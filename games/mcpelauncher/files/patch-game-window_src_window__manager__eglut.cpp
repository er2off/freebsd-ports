--- game-window/src/window_manager_eglut.cpp.orig	2023-07-13 19:14:09 UTC
+++ game-window/src/window_manager_eglut.cpp
@@ -5,7 +5,9 @@
 #include <eglut.h>
 #include <eglut_x11.h>
 #include <unistd.h>
+#ifndef __FreeBSD__
 #include <linux/limits.h>
+#endif
 #include <libgen.h>
 #include <cstring>
 
