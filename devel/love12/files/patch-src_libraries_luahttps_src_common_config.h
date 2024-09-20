--- src/libraries/luahttps/src/common/config.h.orig	2024-09-20 11:54:15 UTC
+++ src/libraries/luahttps/src/common/config.h
@@ -28,7 +28,7 @@
 #elif defined(__APPLE__)
 	#define HTTPS_BACKEND_NSURL
 	#define HTTPS_LIBRARY_LOADER_UNIX
-#elif defined(linux) || defined(__linux) || defined(__linux__)
+#elif defined(linux) || defined(__linux) || defined(__linux__) || defined(__FreeBSD__)
 	#define HTTPS_LIBRARY_LOADER_UNIX
 
 	#if defined __has_include
