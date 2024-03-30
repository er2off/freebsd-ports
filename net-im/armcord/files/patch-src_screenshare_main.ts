--- src/screenshare/main.ts.orig	2024-02-12 15:01:34 UTC
+++ src/screenshare/main.ts
@@ -17,7 +17,7 @@ function registerCustomHandler(): void {
             types: ["screen", "window"]
         });
         console.log(sources);
-        if (process.platform === "linux" && process.env.XDG_SESSION_TYPE?.toLowerCase() === "wayland") {
+        if (process.platform in ["linux", "freebsd"] && process.env.XDG_SESSION_TYPE?.toLowerCase() === "wayland") {
             console.log("WebRTC Capturer detected, skipping window creation."); //assume webrtc capturer is used
             console.log({video: {id: sources[0].id, name: sources[0].name}});
             callback({video: {id: sources[0].id, name: sources[0].name}});
