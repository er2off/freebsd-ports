# Created by: Er2 <er2@dismail.de>

PORTNAME=	lwjgl3
DISTVERSION=	3.3.3
PORTREVISION=	1
CATEGORIES=	games java

MAINTAINER=	er2@dismail.de
COMMENT=	Lightweight Java Game Library 3
WWW=		https://lwjgl.org

LICENSE=	BSD3CLAUSE

USES=		gl gnome pkgconfig xorg
USE_GITHUB=	yes
GH_ACCOUNT=	LWJGL
GH_PROJECT=	lwjgl3

USE_JAVA=	yes
USE_ANT=	yes
JAVA_VERSION=	17+
JAVA_RUN=	yes
USE_GL=		gl egl glesv2
USE_GNOME=	gtk30 glib20
USE_XORG=	x11

# We need 2 javas, yes
BUILD_DEPENDS=	${LOCALBASE}/openjdk8/bin/java:java/openjdk8
BUILD_DEPENDS+=	${LOCALBASE}/bin/kotlinc:lang/kotlin
LIB_DEPENDS=	libopenal.so:audio/openal-soft \
		libopus.so:audio/opus \
		libOpenCL.so:devel/ocl-icd

OPTIONS_DEFINE=		DOCS
OPTIONS_DEFAULT=	DOCS
OPTIONS_SUB=		yes

MAKE_ENV+=	JAVA8_HOME=${LOCALBASE}/openjdk8
MAKE_ARGS+=	-Dkotlinc=${LOCALBASE}/share/kotlin

LIBSDIR=	${WRKSRC}/bin/libs/native/freebsd/*/org/lwjgl

do-install:
	@cd ${BUILD_WRKSRC} && ${SETENV} ${MAKE_ENV} ${ANT} release ${MAKE_ARGS} #-Dbuild.offline=yes -Djavadoc.skip=yes

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
	#${INSTALL_LIB} ${BUILD_WRKSRC}/glfw/src/libglfw.so ${STAGEDIR}${PREFIX}/lib/${PORTNAME}/

.include <bsd.port.mk>
