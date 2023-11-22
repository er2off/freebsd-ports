--- UI/cmake/legacy.cmake.orig	2023-11-22 13:42:31 UTC
+++ UI/cmake/legacy.cmake
@@ -479,6 +479,7 @@ elseif(OS_POSIX)
 
   if(OS_FREEBSD)
     target_link_libraries(obs PRIVATE procstat)
+    target_compile_options(obs PRIVATE -Wno-unqualified-std-cast-call)
   endif()
 
   if(OS_LINUX AND ENABLE_WHATSNEW)
