--- mcpelauncher-linker/core/base/file.cpp.orig	2020-09-04 05:56:10 UTC
+++ mcpelauncher-linker/core/base/file.cpp
@@ -35,6 +35,9 @@
 #if defined(__APPLE__)
 #include <mach-o/dyld.h>
 #endif
+#if defined(__FreeBSD__)
+#include <sys/sysctl.h>
+#endif
 #if defined(_WIN32)
 #include <direct.h>
 #include <windows.h>
@@ -451,6 +454,14 @@ std::string GetExecutablePath() {
     std::unique_ptr<char> path_buf(new char[path_len]);
     _NSGetExecutablePath(path_buf.get(), &path_len);
     return path_buf.get();
+  }
+  return path;
+#elif defined(__FreeBSD__)
+  char path[PATH_MAX + 1];
+  int mib[4] = {CTL_KERN, KERN_PROC, KERN_PROC_PATHNAME, getpid()};
+  size_t path_len = sizeof(path);
+  if (sysctl(mib, 4, path, &path_len, NULL, 0) != 0) {
+    return NULL;
   }
   return path;
 #elif defined(_WIN32)
