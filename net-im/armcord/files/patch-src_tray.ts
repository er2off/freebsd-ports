--- src/tray.ts.orig	2024-02-12 15:02:44 UTC
+++ src/tray.ts
@@ -18,7 +18,7 @@ app.whenReady().then(async () => {
             return trayPath.resize({height: 16});
         } else if (process.platform == "darwin") {
             return trayPath.resize({height: 18});
-        } else if (process.platform == "linux") {
+        } else if (process.platform in ["linux", "freebsd"]) {
             return trayPath.resize({height: 24});
         }
         return undefined;
