--- mcpelauncher-linker/core/liblog/logger_write.cpp.orig	2020-09-04 05:56:10 UTC
+++ mcpelauncher-linker/core/liblog/logger_write.cpp
@@ -48,6 +48,8 @@
 #include <pthread.h>
 #elif defined(__linux__) && !defined(__ANDROID__)
 #include <syscall.h>
+#elif defined(__FreeBSD__)
+#include <sys/syscall.h>
 #elif defined(_WIN32)
 #include <windows.h>
 #endif
@@ -236,6 +238,8 @@ static uint64_t GetThreadId() {
   return tid;
 #elif defined(__linux__)
   return syscall(__NR_gettid);
+#elif defined(__FreeBSD__)
+  return syscall(SYS_thr_self);
 #elif defined(_WIN32)
   return GetCurrentThreadId();
 #endif