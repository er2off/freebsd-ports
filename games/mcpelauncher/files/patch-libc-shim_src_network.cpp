--- libc-shim/src/network.cpp.orig	2023-07-12 20:51:43 UTC
+++ libc-shim/src/network.cpp
@@ -1,7 +1,13 @@
 #include "network.h"
 #include "errno.h"
 
+#ifdef __FreeBSD__
+#define _KERNEL
+#endif
 #include <netinet/in.h>
+#ifdef __FreeBSD__
+#undef _KERNEL
+#endif
 #include <net/if.h>
 #include <arpa/inet.h>
 #include <cstring>
@@ -515,4 +521,4 @@ void shim::add_network_shimmed_symbols(std::vector<shi
         {"if_nameindex", if_nameindex},
         {"if_freenameindex", if_freenameindex},
     });
-}
\ No newline at end of file
+}
