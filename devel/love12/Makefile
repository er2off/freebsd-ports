PORTNAME=	love
PORTVERSION=	12.0
PORTREVISION=	1
CATEGORIES=	devel games
PKGNAMESUFFIX=	12

MAINTAINER=	er2@dismail.de
COMMENT=	Open-source 2D game engine (pre-release version 12.0)
WWW=		https://www.love2d.org/

LICENSE=	ZLIB
LICENSE_FILE=	${WRKSRC}/license.txt

LIB_DEPENDS=	libmodplug.so:audio/libmodplug \
		libfreetype.so:print/freetype2 \
		libharfbuzz.so:print/harfbuzz \
		libogg.so:audio/libogg \
		libvorbisfile.so:audio/libvorbis \
		libtheora.so:multimedia/libtheora

USES=		cmake compiler:c++11-lib desktop-file-utils gl openal \
		pkgconfig sdl shared-mime-info
USE_GITHUB=	yes
GH_ACCOUNT=	love2d
GH_TAGNAME=	876625d
USE_SDL=	sdl2
USE_GL=		gl glu

OPTIONS_DEFINE=		LUAJIT
OPTIONS_DEFAULT=	LUAJIT

LUAJIT_DESC=		Use luajit
LUAJIT_LIB_DEPENDS=	libluajit-5.1.so:lang/luajit-devel
LUAJIT_LIB_DEPENDS_OFF=	liblua-5.1.so:lang/lua51
LUAJIT_CMAKE_BOOL=	LOVE_JIT

CMAKE_ARGS=	-DLOVE_EXE_NAME=love${PKGNAMESUFFIX} \
		-DLOVE_LIB_NAME=liblove${PKGNAMESUFFIX} \
		-DCMAKE_INSTALL_MANDIR=${PREFIX}/share/man

post-patch:
	@${REINPLACE_CMD} -Ee \
		'/(Exec|Icon|MimeType)/ s|love|&${PKGNAMESUFFIX}|; s|LÖVE|& ${PKGNAMESUFFIX}|; /^Comment/ s|$$| (pre-release version 12.0)|; /^NoDisplay/ s|true|false|' \
		${WRKSRC}/platform/unix/love.desktop.in
	@${REINPLACE_CMD} -e 's|x-love-game|x-love${PKGNAMESUFFIX}-game|; s|LÖVE|& ${PKGNAMESUFFIX}|' \
		${WRKSRC}/platform/unix/love.xml

post-install:
	@${MV} ${STAGEDIR}${PREFIX}/share/applications/love.desktop \
		${STAGEDIR}${PREFIX}/share/applications/love${PKGNAMESUFFIX}.desktop
	@${MV} ${STAGEDIR}${PREFIX}/share/pixmaps/love.svg \
		${STAGEDIR}${PREFIX}/share/pixmaps/love${PKGNAMESUFFIX}.svg
	@${MV} ${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/mimetypes/application-x-love-game.svg \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/mimetypes/application-x-love${PKGNAMESUFFIX}-game.svg
	@${MV} ${STAGEDIR}${PREFIX}/share/mime/packages/love.xml \
		${STAGEDIR}${PREFIX}/share/mime/packages/love${PKGNAMESUFFIX}.xml

.include <bsd.port.mk>
