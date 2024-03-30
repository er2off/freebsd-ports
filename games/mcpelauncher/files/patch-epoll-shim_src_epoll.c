--- epoll-shim/src/epoll.c.orig	2020-04-22 11:28:38 UTC
+++ epoll-shim/src/epoll.c
@@ -328,6 +328,7 @@ epoll_wait(int fd, struct epoll_event *ev, int cnt, in
 
 	for (int i = 0; i < ret; ++i) {
 		int events = 0;
+#ifndef __FreeBSD__
 		if (evlist[i].flags & EV_OOBAND) {
                     uint16_t flags = 0;
                     kqueue_load_state(fd, evlist[i].ident, &flags);
@@ -335,6 +336,7 @@ epoll_wait(int fd, struct epoll_event *ev, int cnt, in
 		    if (flags & KQUEUE_STATE_EPOLLPRI)
                         events |= EPOLLPRI;
 		}
+#endif
 		if (evlist[i].filter == EVFILT_READ) {
 			events |= EPOLLIN;
 		} else if (evlist[i].filter == EVFILT_WRITE) {
