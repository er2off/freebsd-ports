--- libc-shim/src/stat.h.orig	2023-07-12 20:51:43 UTC
+++ libc-shim/src/stat.h
@@ -68,10 +68,10 @@ namespace shim {
         };
 #endif
 
-#ifndef __APPLE__
-        void from_host(struct ::stat64 const &info, stat &result);
-#else
+#if defined(__APPLE__) || defined(__FreeBSD__)
         void from_host(struct ::stat const &info, stat &result);
+#else
+        void from_host(struct ::stat64 const &info, stat &result);
 #endif
 
     }
