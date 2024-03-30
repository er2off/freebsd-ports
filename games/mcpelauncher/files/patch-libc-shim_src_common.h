--- libc-shim/src/common.h.orig	2023-07-12 20:51:43 UTC
+++ libc-shim/src/common.h
@@ -127,6 +127,8 @@ namespace shim {
 
 #ifdef __APPLE__
     int fdatasync(int fildes);
+#endif
+#if defined(__APPLE__) || defined(__FreeBSD__)
     int __cmsg_nxthdr();
 #endif
 
