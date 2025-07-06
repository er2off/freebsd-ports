--- lib/hidapi/hidapi_impl.py.orig	2025-07-06 08:03:04 UTC
+++ lib/hidapi/hidapi_impl.py
@@ -60,6 +60,7 @@ _library_paths = (
     "libhidapi-libusb.so.0",
     "libhidapi-iohidmanager.so",
     "libhidapi-iohidmanager.so.0",
+    "libhidapi.so",
     "libhidapi.dylib",
     "hidapi.dll",
     "libhidapi-0.dll",
