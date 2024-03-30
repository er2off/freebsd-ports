--- mcpelauncher-core/src/minecraft_utils.cpp.orig	2023-05-22 18:38:27 UTC
+++ mcpelauncher-core/src/minecraft_utils.cpp
@@ -35,6 +35,8 @@ void* MinecraftUtils::loadLibM() {
 void* MinecraftUtils::loadLibM() {
 #ifdef __APPLE__
     void* libmLib = HybrisUtils::loadLibraryOS("libm.so", "libm.dylib", libm_symbols, std::unordered_map<std::string, void*>{ {std::string("sincos"), (void*)__sincos }, {std::string("sincosf"), (void*)__sincosf } });
+#elif defined(__FreeBSD__)
+    void* libmLib = HybrisUtils::loadLibraryOS("libm.so", "libm.so", libm_symbols);
 #else
     void* libmLib = HybrisUtils::loadLibraryOS("libm.so", "libm.so.6", libm_symbols);
 #endif
@@ -78,6 +80,8 @@ void MinecraftUtils::setupHybris() {
     HybrisUtils::loadLibraryOS("libz.so", 
 #ifdef __APPLE__
     "libz.dylib"
+#elif defined(__FreeBSD__)
+    "libz.so"
 #else
     "libz.so.1"
 #endif
