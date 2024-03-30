--- mcpelauncher-linker/include/compat.h.orig	2024-03-12 22:26:21 UTC
+++ mcpelauncher-linker/include/compat.h
@@ -2,7 +2,7 @@
 #include <string.h>
 #define PAGE_SIZE 4096
 #define PAGE_MASK (~(PAGE_SIZE - 1))
-#ifndef __APPLE__
+#if !defined(__APPLE__) && !defined(__FreeBSD__)
 #define DEF_WEAK(a)
 #define __BIONIC_ALIGN(__value, __alignment) (((__value) + (__alignment)-1) & ~((__alignment)-1))
 #define	__predict_true(exp)	__builtin_expect((exp) != 0, 1)
@@ -28,7 +28,8 @@ size_t strlcat(char *dst, const char *src, size_t dsiz
 "C"
 #endif
 size_t strlcat(char *dst, const char *src, size_t dsize);
-#else
+
+#else /* APPLE || FreeBSD */
 #define gettid() 0
 #define __assert __loader_assert
 extern 
@@ -50,10 +51,21 @@ void __loader_assert(const char* file, int line, const
 #  define fopen64 fopen
 #  define mmap64 mmap
 #  define pread64 pread
-#define PTHREAD_RECURSIVE_MUTEX_INITIALIZER_NP PTHREAD_RECURSIVE_MUTEX_INITIALIZER
+#ifdef __FreeBSD__
+#define PTHREAD_RECURSIVE_MUTEX_INITIALIZER_NP PTHREAD_MUTEX_INITIALIZER
+#define MAP_NORESERVE 0
+#define DEF_WEAK(a)
+#else
 #define __LIBC_HIDDEN__
+#define PTHREAD_RECURSIVE_MUTEX_INITIALIZER_NP PTHREAD_RECURSIVE_MUTEX_INITIALIZER
+// macos-14 arm64 VM of GitHub error marks them as non existent
+#define	__predict_true(exp)	__builtin_expect((exp) != 0, 1)
+#define	__predict_false(exp)	__builtin_expect((exp) != 0, 0)
+#endif
 #include <libgen.h>
+#ifndef basename
 #define basename(name) basename((char*)name)
+#endif
 // Returns the address of the page containing address 'x'.
 #define PAGE_START(x) ((x) & PAGE_MASK)
 
@@ -63,8 +75,4 @@ void __loader_assert(const char* file, int line, const
 // Returns the address of the next page after address 'x', unless 'x' is
 // itself at the start of a page.
 #define PAGE_END(x) PAGE_START((x) + (PAGE_SIZE-1))
-
-// macos-14 arm64 VM of GitHub error marks them as non existent
-#define	__predict_true(exp)	__builtin_expect((exp) != 0, 1)
-#define	__predict_false(exp)	__builtin_expect((exp) != 0, 0)
 #endif
