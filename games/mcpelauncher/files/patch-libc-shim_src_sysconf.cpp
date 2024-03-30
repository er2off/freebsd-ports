--- libc-shim/src/sysconf.cpp.orig	2023-07-12 20:51:43 UTC
+++ libc-shim/src/sysconf.cpp
@@ -25,7 +25,9 @@ int shim::bionic::to_host_sysconf_id(int arg) {
         case 0x0009: return _SC_LINE_MAX;
         case 0x000a: return _SC_NGROUPS_MAX;
         case 0x000b: return _SC_OPEN_MAX;
+#ifndef __FreeBSD__
         case 0x000c: return _SC_PASS_MAX;
+#endif
         case 0x000d: return _SC_2_C_BIND;
         case 0x000e: return _SC_2_C_DEV;
         case 0x0010: return _SC_2_CHAR_TERM;
@@ -102,4 +104,4 @@ int shim::bionic::to_host_sysconf_id(int arg) {
         case 0x0064: return _SC_MONOTONIC_CLOCK;
         default: throw std::runtime_error("Uknown sysconf id");
     }
-}
\ No newline at end of file
+}
