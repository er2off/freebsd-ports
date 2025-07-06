--- lib/logitech_receiver/diversion.py.orig	2025-07-06 08:04:23 UTC
+++ lib/logitech_receiver/diversion.py
@@ -41,7 +41,7 @@ from keysyms import keysymdef
 
 # There is no evdev on macOS or Windows. Diversion will not work without
 # it but other Solaar functionality is available.
-if platform.system() in ("Darwin", "Windows"):
+if platform.system() in ("Darwin", "Windows", "FreeBSD"):
     evdev = None
 else:
     import evdev
