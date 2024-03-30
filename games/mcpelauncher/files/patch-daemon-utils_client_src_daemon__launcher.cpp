--- daemon-utils/client/src/daemon_launcher.cpp.orig	2020-06-24 18:49:07 UTC
+++ daemon-utils/client/src/daemon_launcher.cpp
@@ -6,7 +6,7 @@
 #include <FileUtil.h>
 #include <log.h>
 
-#ifdef __APPLE__
+#if defined(__APPLE__) || defined(__FreeBSD__)
 #include <chrono>
 #include <sys/types.h>
 #include <sys/event.h>
@@ -59,7 +59,7 @@ void daemon_launcher::open(simpleipc::client::service_
         }
     }
 
-#ifdef __APPLE__
+#if defined(__APPLE__) || defined(__FreeBSD__)
     remove(service_path.c_str());
 
     int kq = kqueue();
