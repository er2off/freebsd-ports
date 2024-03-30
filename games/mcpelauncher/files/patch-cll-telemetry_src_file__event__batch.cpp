--- cll-telemetry/src/file_event_batch.cpp.orig	2020-04-10 18:12:04 UTC
+++ cll-telemetry/src/file_event_batch.cpp
@@ -3,7 +3,7 @@
 #include <log.h>
 #include <fcntl.h>
 
-#ifdef __APPLE__
+#if defined(__APPLE__) || defined(__FreeBSD__)
 #define ftruncate64 ftruncate
 #define lseek64 lseek
 #endif
