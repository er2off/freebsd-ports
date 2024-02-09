--- src/preload/titlebar.ts.orig	2024-02-09 11:58:24 UTC
+++ src/preload/titlebar.ts
@@ -27,7 +27,8 @@ export function injectTitlebar(): void {
         addStyle(fs.readFileSync(wordmarkcssPath, "utf8"));
         document.body.setAttribute("customTitlebar", "");
 
-        document.body.setAttribute("armcord-platform", os.platform());
+        const platform = os.platform();
+        document.body.setAttribute("armcord-platform", platform == "freebsd" ? "win32" : platform);
 
         const minimize = document.getElementById("minimize");
         const maximize = document.getElementById("maximize");
