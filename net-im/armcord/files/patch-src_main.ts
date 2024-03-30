--- src/main.ts.orig	2024-02-12 15:00:57 UTC
+++ src/main.ts
@@ -66,7 +66,7 @@ if (!app.requestSingleInstanceLock() && getConfigSync(
     // Your data now belongs to CCP
     crashReporter.start({uploadToServer: false});
     // enable webrtc capturer for wayland
-    if (process.platform === "linux" && process.env.XDG_SESSION_TYPE?.toLowerCase() === "wayland") {
+    if (process.platform in ["linux", "freebsd"] && process.env.XDG_SESSION_TYPE?.toLowerCase() === "wayland") {
         app.commandLine.appendSwitch("enable-features=WebRTCPipeWireCapturer");
         console.log("Wayland detected, using PipeWire for video capture.");
     }
