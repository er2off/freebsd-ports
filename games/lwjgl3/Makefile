# Created by: Er2 <er2@dismail.de>

PORTNAME=	lwjgl3
DISTVERSION=	3.3.3
CATEGORIES=	games java
USE_GITHUB=	yes
GH_ACCOUNT=	LWJGL
GH_PROJECT=	lwjgl3
GH_TUPLE=	glfw:glfw:3eaf125:external/glfw

MAINTAINER=	er2@dismail.de
COMMENT=	Lightweight Java Game Library 3

LICENSE=	BSD3CLAUSE

#BUILD_DEPENDS=	${LOCALBASE}/bin/kotlinc:lang/kotlin
BUILD_DEPENDS+=	${LOCALBASE}/bin/ant:devel/apache-ant \
		${LOCALBASE}/openjdk8/bin/java:java/openjdk8
LIB_DEPENDS=	libopenal.so:audio/openal-soft \
		libopus.so:audio/opus \
		libOpenCL.so:devel/ocl-icd

USES=		gl gnome xorg pkgconfig cmake
USE_JAVA=	yes
JAVA_VERSION=	17+
CMAKE_ARGS+=	-DJAVA=${JAVA} -DJAVA8_HOME=${LOCALBASE}/openjdk8
#USE_ANT=	yes
USE_GL=	gl egl glesv2
USE_GNOME=	gtk30 glib20
USE_JAVA=	yes
USE_XORG=	x11

#MAKE_ARGS+=	-Dkotlinc=/usr/local/share/kotlin

LIBSDIR=	${WRKSRC}/bin/libs/native/freebsd/*/org/lwjgl

do-install:
	#@cd ${BUILD_WRKSRC} && ${ANT} release -Dbuild.offline=yes -Djavadoc.skip=yes
	@${MKDIR} ${STAGEDIR}${JAVAJARDIR}/${PORTNAME}
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/${PORTNAME}
.for x in ${WRKSRC}/bin/RELEASE/lwjgl*/*.jar
	${INSTALL_DATA} ${WRKSRC}${x} ${STAGEDIR}${JAVAJARDIR}/${PORTNAME}/
.endfor
.for x in ${WRKSRC}/bin/RELEASE/lwjgl*/*license.txt
	${INSTALL_DATA} ${WRKSRC}${x} ${STAGEDIR}${JAVAJARDIR}/${PORTNAME}/
.endfor
.for x in ${LIBSDIR}/liblwjgl.so ${LIBSDIR}/*/*.so
	${INSTALL_LIB} ${WRKSRC}${x} ${STAGEDIR}${PREFIX}/lib/${PORTNAME}/
.endfor
	${INSTALL_LIB} ${BUILD_WRKSRC}/glfw/src/libglfw.so ${STAGEDIR}${PREFIX}/lib/${PORTNAME}/

.include <bsd.port.mk>
