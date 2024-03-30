--- mcpelauncher-linker/bionic/linker/linker.cpp.orig	2023-05-15 16:04:44 UTC
+++ mcpelauncher-linker/bionic/linker/linker.cpp
@@ -400,7 +400,11 @@ static bool realpath_fd(int fd, std::string* realpath)
   }
   auto length = PATH_MAX;
 #else
+#ifdef __FreeBSD__
+  async_safe_format_buffer(proc_self_fd, sizeof(proc_self_fd), "/dev/fd/%d", fd);
+#else
   async_safe_format_buffer(proc_self_fd, sizeof(proc_self_fd), "/proc/self/fd/%d", fd);
+#endif
   auto length = readlink(proc_self_fd, buf, sizeof(buf));
   if (length == -1) {
     if (!is_first_stage_init()) {
