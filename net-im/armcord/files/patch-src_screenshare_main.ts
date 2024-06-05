--- src/screenshare/main.ts.orig	2024-05-18 11:00:04 UTC
+++ src/screenshare/main.ts
@@ -29,7 +29,7 @@ function registerCustomHandler(): void {
             types: ["screen", "window"]
         });
         console.log(sources);
-        if (process.platform === "linux" && process.env.XDG_SESSION_TYPE?.toLowerCase() === "wayland") {
+        if (process.platform in ["linux", "freebsd"] && process.env.XDG_SESSION_TYPE?.toLowerCase() === "wayland") {
             console.log("WebRTC Capturer detected, skipping window creation."); //assume webrtc capturer is used
             var options: Electron.Streams = {video: sources[0]};
             if (showAudioDialog() == true) options = {video: sources[0], audio: "loopbackWithMute"};
