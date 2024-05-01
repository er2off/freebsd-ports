--- mcpelauncher-ui-qt/supportedandroidabis.cpp.orig	2024-04-24 17:40:37 UTC
+++ mcpelauncher-ui-qt/supportedandroidabis.cpp
@@ -42,6 +42,10 @@ bool Supports32Bit() {
 
 #ifndef __APPLE__
 bool Supports32Bit() {
+#ifdef __FreeBSD__ // TODO: Currently we're unable to build 32-bit launcher
+    return false;
+#endif
+
     // ToDo really check it
     return true;
 }
