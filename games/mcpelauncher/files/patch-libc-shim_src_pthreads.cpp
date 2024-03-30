--- libc-shim/src/pthreads.cpp.orig	2023-07-12 20:51:43 UTC
+++ libc-shim/src/pthreads.cpp
@@ -5,6 +5,9 @@
 #include <signal.h>
 #include "pthreads.h"
 #include "errno.h"
+#ifdef __FreeBSD__
+#include <pthread_np.h>
+#endif
 
 using namespace shim;
 
@@ -167,7 +170,11 @@ int shim::pthread_getattr_np(pthread_t th, pthread_att
     attr->stack_size = stacksize;
 #else
     ::pthread_attr_t hostattr;
+#ifdef __FreeBSD__
+    int ret = ::pthread_attr_get_np(th, &hostattr);
+#else
     int ret = ::pthread_getattr_np(th, &hostattr);
+#endif
     if (ret != 0)
         return bionic::translate_errno_from_host(ret);
     pthread_attr_init(attr);
@@ -413,6 +420,9 @@ pid_t shim::pthread_gettid_np(pthread_t thread) {
 pid_t shim::pthread_gettid_np(pthread_t thread) {
 #ifdef __linux__
     pid_t ret = thread;
+#elif defined(__FreeBSD__)
+    /* in lib/libthr/thread/thr_private.h tid field is first */
+    pid_t ret = (long)thread;
 #else
     pid_t ret = thread->__sig;
 #endif
