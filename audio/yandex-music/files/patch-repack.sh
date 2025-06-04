--- repack.sh.orig	2025-05-30 00:51:26 UTC
+++ repack.sh
@@ -38,43 +38,18 @@ fi
 fi
 
 
-if [ -z "$exe_location" ]; then
-    echo "No exe file specified"
-    usage
-    exit 1
-fi
-
-clear() {
-    rm -rf "$TEMPDIR"
-}
-TEMPDIR="$(mktemp -d)"
-trap clear EXIT
-
-
-EXTRACTED="$TEMPDIR/Extracted"
-# unpacking
-7z x "$exe_location" -o"$EXTRACTED"
-mv "$EXTRACTED/\$PLUGINSDIR/app-64.7z" "$TEMPDIR/app-64.7z"
-rm -rf "$EXTRACTED"
-7z x "$TEMPDIR/app-64.7z" -o"$EXTRACTED"
-mv "$EXTRACTED/resources/app.asar" "$TEMPDIR/app.asar"
-rm -rf "$EXTRACTED"
-rm "$TEMPDIR/app-64.7z"
-asar extract "$TEMPDIR/app.asar" "$TEMPDIR/app"
-rm "$TEMPDIR/app.asar"
-
 curdir="$PWD"
-cd "$TEMPDIR/app"
+cd "$dst/app"
 
 
 echo "Patching .js chunks"
 find "./" -type f \( -name "*.js" -o -name "*.js.map" \) -print0 | while IFS= read -r -d $'\0' file; do
     # Use 'sed' to perform the replacement in-place
-    sed -i -E 's/(\w\.)isLinuxApplication/(window.CUSTOM_TITLE_BAR)/g' "$file"
-    sed -i 's/panel:!1,allowOverwriteExperiments:!1/panel:window.IS_DEVTOOLS_ENABLED??!1,allowOverwriteExperiments:window.IS_DEVTOOLS_ENABLED??!1/g' "$file"
-    sed -i -E 's;"MacOS",(\w).LINUX="Linux";"MacOS",\1.LINUX="Windows";g' "$file"
-    sed -i -E 's;LINUX:(\w)="uVNvVMAvdrvjtwN0VlhEt2";LINUX:\1="kzqU4XhfCaY6B6JTHODeq5";g' "$file"
-    sed -i "s/atob(a)/atob(a).replace('nt(25,', \`nt(\${window.VIBE_ANIMATION_MAX_FPS??25},\`)/g" "$file"
+    gsed -i -E 's/(\w\.)isLinuxApplication/(window.CUSTOM_TITLE_BAR)/g' "$file"
+    gsed -i 's/panel:!1,allowOverwriteExperiments:!1/panel:window.IS_DEVTOOLS_ENABLED??!1,allowOverwriteExperiments:window.IS_DEVTOOLS_ENABLED??!1/g' "$file"
+    gsed -i -E 's;"MacOS",(\w).LINUX="Linux";"MacOS",\1.LINUX="Windows";g' "$file"
+    gsed -i -E 's;LINUX:(\w)="uVNvVMAvdrvjtwN0VlhEt2";LINUX:\1="kzqU4XhfCaY6B6JTHODeq5";g' "$file"
+    gsed -i "s/atob(a)/atob(a).replace('nt(25,', \`nt(\${window.VIBE_ANIMATION_MAX_FPS??25},\`)/g" "$file"
 done
 echo ".js chunks patched"
 
@@ -82,12 +57,12 @@ find "./" -type f -name "*.html" -print0 | while IFS= 
 echo "Fixing Title"
 find "./" -type f -name "*.html" -print0 | while IFS= read -r -d $'\0' file; do
     # Use 'sed' to perform the replacement in-place
-    sed -i "s/Яндекс Музыка — собираем музыку для вас/Яндекс Музыка/g" "$file"
+    gsed -i "s/Яндекс Музыка — собираем музыку для вас/Яндекс Музыка/g" "$file"
 done
 echo "Title Fixed"
 
 echo "Replacing Icons"
-cp -drf "$SCRIPT_DIR/icons/." "./app/"
+cp -rf "$SCRIPT_DIR/icons/." "./app/"
 echo "Replaced Icons"
 
 # applying patches
@@ -114,7 +89,7 @@ apply_patch()
         fi
     fi
     echo "Applying patch '$patchfile'"
-    (cd "$TEMPDIR/app" && patch -p1 < "$patchfile")
+    (cd "$dst/app" && patch -p1 -V none < "$patchfile")
 }
 
 if [ "$nopatch" != "1" ]; then
@@ -123,21 +98,16 @@ fi
     done
 fi
 
-mkdir -p "$dst"
+#mkdir -p "$dst"
 
-if [ -n "$extract_only" ]; then
-    eval cp -r "$TEMPDIR/app/*" "$dst"
-    exit 0
-fi
-
 echo "Packing"
 cd "$curdir"
-asar pack "$TEMPDIR/app" "$dst/yandex-music.asar"
+npx asar pack "$dst/app" "$dst/yandex-music.asar"
 for ext in png svg; do
-    mv "$TEMPDIR/app/app/favicon.$ext" "$dst"
+    mv "$dst/app/app/favicon.$ext" "$dst"
 done
-mv "$TEMPDIR/app/app/favicon-512x512.png" "$dst"
-mv "$TEMPDIR/app/app/favicon-dark.png" "$dst"
-mv "$TEMPDIR/app/app/favicon-light.png" "$dst"
+mv "$dst/app/app/favicon-512x512.png" "$dst"
+mv "$dst/app/app/favicon-dark.png" "$dst"
+mv "$dst/app/app/favicon-light.png" "$dst"
 
 echo "Done"
