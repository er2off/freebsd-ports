--- cmake/Modules/Findqrcodegencpp.cmake.orig	2023-11-28 12:53:41 UTC
+++ cmake/Modules/Findqrcodegencpp.cmake
@@ -97,7 +97,7 @@ find_path(
   qrcodegencpp_INCLUDE_DIR
   NAMES qrcodegen.hpp
   HINTS ${PC_qrcodegencpp_INCLUDE_DIRS}
-  PATHS /usr/include /usr/local/include
+  PATHS /usr/include /usr/local/include /usr/local/include/qrcodegen
   PATH_SUFFIXES qrcodegencpp qrcodegen
   DOC "qrcodegencpp include directory")
 
