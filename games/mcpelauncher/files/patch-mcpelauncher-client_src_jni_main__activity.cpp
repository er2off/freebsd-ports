--- mcpelauncher-client/src/jni/main_activity.cpp.orig	2024-03-16 10:28:41 UTC
+++ mcpelauncher-client/src/jni/main_activity.cpp
@@ -2,11 +2,15 @@
 #include "../settings.h"
 
 #include <unistd.h>
-#ifndef __APPLE__
-#include <sys/sysinfo.h>
-#else
+#ifdef __FreeBSD__
 #include <sys/sysctl.h>
+#include <sys/user.h>
+#include <sys/vmmeter.h>
+#elif defined(__APPLE__)
+#include <sys/sysctl.h>
 #include <mach/mach.h>
+#else
+#include <sys/sysinfo.h>
 #endif
 #include <file_picker_factory.h>
 #include <game_window_manager.h>
@@ -36,6 +40,14 @@ FakeJni::JLong MainActivity::getUsedMemory() {
 
     double page_K = page_size / (double)1024;
     return (stat.active_count + stat.wire_count) * page_K * 1000;
+#elif defined(__FreeBSD__)
+    int mib[4] = {CTL_VM, KERN_PROC, KERN_PROC_PID, getpid()};
+    struct kinfo_proc info = {};
+    size_t size = sizeof(info);
+    if(sysctl(mib, 4, &info, &size, NULL, 0) != 0)
+        return 0L;
+    // from usr.bin/top/machine.c macro PROCSIZE
+    return info.ki_size / 1024;
 #else
     FILE* file = fopen("/proc/self/statm", "r");
     if(file == nullptr)
@@ -60,6 +72,19 @@ FakeJni::JLong MainActivity::getFreeMemory() {
 
     double page_K = page_size / (double)1024;
     return stat.free_count * page_K * 1000;
+#elif defined(__FreeBSD__)
+    uint64_t page_size;
+    size_t len = sizeof(page_size);
+    sysctlbyname("hw.pagesize", &page_size, &len, NULL, 0);
+
+    int mib[2] = {CTL_VM, VM_TOTAL};
+    struct vmtotal info = {};
+    size_t size = sizeof(info);
+    if(sysctl(mib, 2, &info, &size, NULL, 0) != 0)
+        return 0L;
+
+    double page_K = page_size / (double)1024;
+    return info.t_free * page_K * 1000;
 #else
     struct sysinfo memInfo;
     sysinfo(&memInfo);
@@ -75,6 +100,19 @@ FakeJni::JLong MainActivity::getTotalMemory() {
     size_t len = sizeof(memsize);
     sysctlbyname("hw.memsize", &memsize, &len, NULL, 0);
     return memsize;
+#elif defined(__FreeBSD__)
+    uint64_t page_size;
+    size_t len = sizeof(page_size);
+    sysctlbyname("hw.pagesize", &page_size, &len, NULL, 0);
+
+    int mib[2] = {CTL_VM, VM_TOTAL};
+    struct vmtotal info = {};
+    size_t size = sizeof(info);
+    if(sysctl(mib, 2, &info, &size, NULL, 0) != 0)
+        return 0L;
+
+    double page_K = page_size / (double)1024;
+    return info.t_vm * page_K * 1000;
 #else
     struct sysinfo memInfo;
     sysinfo(&memInfo);
