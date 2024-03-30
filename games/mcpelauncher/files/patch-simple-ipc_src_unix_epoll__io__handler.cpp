--- simple-ipc/src/unix/epoll_io_handler.cpp.orig	2023-03-25 17:39:55 UTC
+++ simple-ipc/src/unix/epoll_io_handler.cpp
@@ -90,4 +90,4 @@ io_handler& io_handler::get_instance() {
 io_handler& io_handler::get_instance() {
     static epoll_io_handler instance;
     return instance;
-}
\ No newline at end of file
+}
