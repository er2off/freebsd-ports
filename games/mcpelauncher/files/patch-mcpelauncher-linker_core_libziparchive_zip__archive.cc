--- mcpelauncher-linker/core/libziparchive/zip_archive.cc.orig	2020-09-04 05:56:10 UTC
+++ mcpelauncher-linker/core/libziparchive/zip_archive.cc
@@ -34,7 +34,7 @@
 #include <memory>
 #include <vector>
 
-#if defined(__APPLE__)
+#if defined(__APPLE__) || defined(__FreeBSD__)
 #define lseek64 lseek
 #endif
 
