--- libc-shim/src/stat.cpp.orig	2023-07-12 20:51:43 UTC
+++ libc-shim/src/stat.cpp
@@ -3,7 +3,7 @@ using namespace shim;
 
 using namespace shim;
 
-#ifndef __APPLE__
+#if !defined(__APPLE__) && !defined(__FreeBSD__)
 
 void bionic::from_host(struct ::stat64 const &info, stat &result) {
     result.st_dev = info.st_dev;
