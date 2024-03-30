--- mcpelauncher-linker/core/base/threads.cpp.orig	2020-09-04 05:56:10 UTC
+++ mcpelauncher-linker/core/base/threads.cpp
@@ -23,6 +23,8 @@
 #include <pthread.h>
 #elif defined(__linux__) && !defined(__ANDROID__)
 #include <syscall.h>
+#elif defined(__FreeBSD__)
+#include <sys/syscall.h>
 #elif defined(_WIN32)
 #include <windows.h>
 #endif
@@ -39,6 +41,8 @@ uint64_t GetThreadId() {
   return tid;
 #elif defined(__linux__)
   return syscall(__NR_gettid);
+#elif defined(__FreeBSD__)
+  return syscall(SYS_thr_self);
 #elif defined(_WIN32)
   return GetCurrentThreadId();
 #endif
