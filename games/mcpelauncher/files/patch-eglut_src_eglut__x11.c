--- eglut/src/eglut_x11.c.orig	2022-12-27 16:42:47 UTC
+++ eglut/src/eglut_x11.c
@@ -475,7 +475,7 @@ next_event(struct eglut_window *win)
         }
         case ClientMessage:
         {
-            if ((ulong) event.xclient.data.l[0] == XInternAtom(_eglut->native_dpy, "WM_DELETE_WINDOW", False)) {
+            if ((unsigned long) event.xclient.data.l[0] == XInternAtom(_eglut->native_dpy, "WM_DELETE_WINDOW", False)) {
                 if (win->close_cb) {
                     win->close_cb();
                 } else {
