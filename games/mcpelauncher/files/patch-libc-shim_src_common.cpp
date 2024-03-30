--- libc-shim/src/common.cpp.orig	2023-07-12 20:51:43 UTC
+++ libc-shim/src/common.cpp
@@ -44,13 +44,14 @@
 #endif
 #include <sys/uio.h>
 #include <syslog.h>
-#ifndef __APPLE__
+#if !defined(__APPLE__) && !defined(__FreeBSD__)
 #include <sys/prctl.h>
 #include <sys/auxv.h>
 #include <sys/utsname.h>
+#else
+#include <xlocale.h>
 #endif
 #ifdef __APPLE__
-#include <xlocale.h>
 #if __MAC_OS_X_VERSION_MIN_REQUIRED < 101200
 // for macOS 10.10 - 10.11
 #include <mach/clock.h>
@@ -60,7 +61,7 @@
 #include <inttypes.h>
 #ifdef _WIN32
 #include <Processthreadsapi.h>
-#elif defined(__APPLE__) || defined(__linux__)
+#elif defined(__APPLE__) || defined(__linux__) || defined(__FreeBSD__)
 #include <sys/syscall.h>
 #endif
 #ifdef __linux__
@@ -90,7 +91,7 @@ uintptr_t bionic::stack_chk_guard = []() {
 #endif
 
 uintptr_t bionic::stack_chk_guard = []() {
-#ifndef __APPLE__
+#if !defined(__APPLE__) && !defined(__FreeBSD__)
     char* buf = reinterpret_cast<char*>(getauxval(AT_RANDOM));
     uintptr_t res = 0;
     memcpy(&res, buf, sizeof(res));
@@ -125,8 +126,10 @@ int bionic::to_host_mmap_flags(bionic::mmap_flags flag
         ret |= MAP_FILE;
     if ((uint32_t) flags & (uint32_t) mmap_flags::ANON)
         ret |= MAP_ANONYMOUS;
+#ifndef __FreeBSD__
     if ((uint32_t) flags & (uint32_t) mmap_flags::NORESERVE)
         ret |= MAP_NORESERVE;
+#endif
     return ret;
 }
 
@@ -247,7 +250,11 @@ int shim::prctl(bionic::prctl_num opt, unsigned long a
 #else
     switch (opt) {
         case bionic::prctl_num::SET_NAME:
+#ifdef __FreeBSD__
+            return ::pthread_setname_np(::pthread_self(), (const char *) a2);
+#else
             return ::pthread_setname_np((const char *) a2);
+#endif
         default:
             Log::error("Shim/Common", "Unexpected prctl: %i", opt);
             return EINVAL;
@@ -311,6 +318,8 @@ int shim::sendfile(int src, int dst, bionic::off_t *of
     off_t c = offset ? (off_t)offset : 0;
 #ifdef __APPLE__
     auto ret = ::sendfile(src, dst, c, offset ? &c : nullptr, nullptr, 0);
+#elif defined(__FreeBSD__)
+    auto ret = ::sendfile(src, dst, c, count, nullptr, 0, 0);
 #else
     auto ret = ::sendfile(src, dst, offset ? &c : nullptr, count);
 #endif
@@ -342,6 +351,8 @@ int shim::fdatasync(int fildes) {
 int shim::fdatasync(int fildes) {
     return ::fcntl(fildes, F_FULLFSYNC);
 }
+#endif
+#if defined(__APPLE__) || defined(__FreeBSD__)
 int shim::__cmsg_nxthdr() {
     return 0;
 }
@@ -354,8 +365,9 @@ int shim::gettid() {
     return (long&)tid;
 #elif defined(SYS_gettid)
     return syscall(SYS_gettid);
+#elif defined(SYS_thr_self)
+    return syscall(SYS_thr_self);
 #else
-    // Fallback for freebsd
     return pthread_getthreadid_np();
 #endif
 }
@@ -569,7 +581,9 @@ void shim::add_time_shimmed_symbols(std::vector<shim::
         {"ctime_r", ::ctime_r},
         {"tzname", ::tzname},
         {"tzset", ::tzset},
+#ifndef __FreeBSD__
         {"daylight", &::daylight},
+#endif
         {"timezone", &::timezone},
         {"nanosleep", ::nanosleep},
         {"clock_gettime", clock_gettime},
