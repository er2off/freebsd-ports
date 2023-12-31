# Created by: Er2 <er2@dismail.de>

PORTNAME=	lwjgl3
DISTVERSION=	3.3.4
PORTREVISION=	snapshot+2
CATEGORIES=	games java

MAINTAINER=	er2@dismail.de
COMMENT=	Lightweight Java Game Library 3
WWW=		https://lwjgl.org

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.md

ONLY_FOR_ARCHS=       amd64
ONLY_FOR_ARCHS_REASON=        Some artifacts are not built by LWJGL CI infrastructure. Comment and try -Dbuild.offline=yes in MAKE_ARGS

# We need 2 javas, yes
BUILD_DEPENDS=	${LOCALBASE}/openjdk8/bin/java:java/openjdk8
LIB_DEPENDS=	libopenal.so:audio/openal-soft \
		libopus.so:audio/opus \
		libOpenCL.so:devel/ocl-icd

USES=		gl gnome pkgconfig xorg
USE_GITHUB=	yes
GH_ACCOUNT=	LWJGL
GH_PROJECT=	lwjgl3
GH_TAGNAME=	b428b2f

USE_JAVA=	yes
USE_ANT=	yes
JAVA_VERSION=	17+
JAVA_RUN=	yes
USE_GL=		gl egl glesv2
USE_GNOME=	gtk30 glib20
USE_XORG=	x11

OPTIONS_DEFINE=		DOCS
OPTIONS_DEFAULT=	DOCS
OPTIONS_SUB=		yes

# FIXME: Add automatic %%DOCS%% prefix
#PLIST_SUB=		DOCS_regex=^.\*-javadoc.jar$

MAKE_ENV+=	JAVA8_HOME=${LOCALBASE}/openjdk8

DOCS_MAKE_ARGS_OFF=	-Djavadoc.skip=true

LIBSDIR=	${WRKSRC}/bin/libs/native/freebsd/*/org/lwjgl

do-install:
	@cd ${BUILD_WRKSRC} && ${SETENV} ${MAKE_ENV} ${ANT} release ${MAKE_ARGS} -Dbuild.offline=yes

	@${MKDIR} ${STAGEDIR}${JAVAJARDIR}/${PORTNAME}
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/${PORTNAME}
.for x in ${WRKSRC}/bin/RELEASE/lwjgl*/*.jar
	${INSTALL_DATA} ${WRKSRC}${x} ${STAGEDIR}${JAVAJARDIR}/${PORTNAME}/
.endfor
# FIXME: Use native FreeBSD ports license installation?
.for x in ${WRKSRC}/bin/RELEASE/lwjgl*/*license.txt
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/licenses/${PKGNAME}/
	${INSTALL_DATA} ${WRKSRC}${x} ${STAGEDIR}${PREFIX}/share/licenses/${PKGNAME}/
.endfor
.for x in ${LIBSDIR}/liblwjgl.so ${LIBSDIR}/*/*.so
	${INSTALL_LIB} ${WRKSRC}${x} ${STAGEDIR}${PREFIX}/lib/${PORTNAME}/
.endfor

.include <bsd.port.mk>
