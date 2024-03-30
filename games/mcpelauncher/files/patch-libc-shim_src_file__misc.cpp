--- libc-shim/src/file_misc.cpp.orig	2023-07-12 20:51:43 UTC
+++ libc-shim/src/file_misc.cpp
@@ -1,5 +1,9 @@
 #include "file_misc.h"
 
+#ifdef __FreeBSD__
+// HACKHACK
+#define EPOLL_SHIM_DETAIL_COMMON_H_
+#endif
 #include <sys/ioctl.h>
 #include <net/if.h>
 #include <fcntl.h>
