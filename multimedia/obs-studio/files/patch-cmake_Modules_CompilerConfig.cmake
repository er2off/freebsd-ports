--- cmake/Modules/CompilerConfig.cmake.orig	2023-11-25 17:23:03 UTC
+++ cmake/Modules/CompilerConfig.cmake
@@ -118,6 +118,7 @@ else()
     -Wunused-parameter
     -Wno-unused-function
     -Wno-missing-field-initializers
+    -Wno-deprecated-declarations
     -fno-strict-aliasing
     "$<$<COMPILE_LANGUAGE:C>:-Werror-implicit-function-declaration;-Wno-missing-braces>"
     "$<$<BOOL:${USE_LIBCXX}>:-stdlib=libc++>"
