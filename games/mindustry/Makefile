PORTNAME=	mindustry
DISTVERSIONPREFIX=	v
DISTVERSION=	147
CATEGORIES=	games java

MAINTAINER=	er2@dismail.de
COMMENT=	Automation tower defense RTS
WWW=		https://mindustrygame.github.io

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

# ant inside gradle in arc
BUILD_DEPENDS=		gradle761>=7.6.1:devel/gradle761 \
			${LOCALBASE}/bin/ant:devel/apache-ant
EXTRACT_DEPENDS=	${LOCALBASE}/bin/unzip:archivers/unzip \
			stb>=g20211010:devel/stb

DIST_SUBDIR=	Mindustry
USES=		compiler:c++17-lang
USE_JAVA=	17
JAVA_BUILD=	jdk
JAVA_RUN=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	Anuken
GH_PROJECT=	Mindustry
GH_TAGNAME=	f9d39ad31a96e6ff4f2ad2c9d134f098636be0a7
GH_TUPLE=	Anuken:Arc:34775c7:Arc/Arc \
		Anuken:soloud:v0.9:soloud/Arc/arc-core/csrc/soloud \
		freetype:freetype:VER-2-10-4:freetype/Arc/extensions/freetype/jni/freetype-2.10.4
#		nigels-com:glew:glew-2.2.0:glew/Arc/backends/backend-sdl/jni/glew-2.2.0
USE_LDCONFIG=	yes

_GRADLE_ENV=	GRADLE_USER_HOME=${WRKDIR}/gradle-home \
		JAVA_VERSION=${JAVA_VERSION}
_GRADLE_RUN=	${SETENV} ${_GRADLE_ENV} gradle761 --no-daemon -Prelease=yes

ARCDIR=	${WRKSRC}/Arc

# Looks weird, please FIXME

pre-fetch:
	@fetch -apr -o ${_DISTDIR}/glew.zip https://github.com/nigels-com/glew/releases/download/glew-2.2.0/glew-2.2.0.zip

post-extract:
	@${MKDIR} ${ARCDIR}/arc-core/csrc/
	@${MKDIR} ${ARCDIR}/backends/backend-sdl/jni/
	@${CP} ${PREFIX}/include/stb/stb_image.h ${ARCDIR}/arc-core/csrc/
	@${TOUCH} ${ARCDIR}/backends/backend-sdl/jni/glew.zip
	@${TOUCH} ${ARCDIR}/backends/backend-sdl/jni/sdlmingw.tar.gz
	@${UNZIP_CMD} -qq -d ${ARCDIR}/backends/backend-sdl/jni/ ${_DISTDIR}/glew.zip

do-build:
	@cd ${ARCDIR} && ${_GRADLE_RUN} \
		arc-core:jnigenBuild \
		extensions:freetype:jnigenBuild \
		backends:backend-sdl:jnigenBuild
	@cd ${WRKSRC} && ${_GRADLE_RUN} \
		desktop:dist

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/512x512/apps/
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/android/res/mipmap-xxxhdpi/ic_launcher.png ${STAGEDIR}${PREFIX}/share/icons/hicolor/512x512/apps/mindustry.png
	${INSTALL_DATA} ${WRKSRC}/desktop/build/libs/Mindustry.jar ${STAGEDIR}${DATADIR}/Mindustry.jar
	${INSTALL_DATA} ${FILESDIR}/mindustry.desktop ${STAGEDIR}${DESKTOPDIR}/mindustry.desktop
	${INSTALL_SCRIPT} ${FILESDIR}/mindustry ${STAGEDIR}${PREFIX}/bin/mindustry

.include <bsd.port.mk>
