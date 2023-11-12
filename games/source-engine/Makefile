PORTNAME=	source-engine
DISTVERSION=	1.17
PORTREVISION=	1
CATEGORIES=	games

MAINTAINER=	er2@dismail.de
COMMENT=	Valve's Source Engine based on leaked code
WWW=		https://github.com/nillerusr/source-engine/

LICENSE=	SOURCE
LICENSE_NAME=	Source 1 SDK License
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_PERMS=	dist-mirror no-dist-sell pkg-mirror no-pkg-sell #auto-accept

USES=		waf iconv pkgconfig
USE_SDL=	sdl2
USE_GITHUB=	yes
GH_ACCOUNT=	nillerusr
GH_TAGNAME=	23204fc
GH_TUPLE=	nillerusr:source-physics:4098acb:ivp/ivp \
		nillerusr:source-thirdparty:c5b901e:thirdparty/thirdparty

32BITS=		armv7 i386
64BITS=		amd64 aarch64
ONLY_FOR_ARCHS=	${32BITS} ${64BITS}
ONLY_FOR_ARCHS_REASON=	Need to port your architecture

.ifdef WITH_CCACHE_BUILD
CONFIGURE_ARGS+=	--use-ccache
.endif
.ifdef WITH_DEBUG
CONFIGURE_ARGS+=	-T debug
.else
CONFIGURE_ARGS+=	-T release
.endif
.if ${32BITS:M${ARCH}}
CONFIGURE_ARGS+=	--32bits
.endif

OPTIONS_SUB=		yes
OPTIONS_DEFAULT=	TOGLES LAUNCHER HL2

#OPTIONS_MULTI=	EXETYPE
#OPTIONS_MULTI_EXETYPE=	LAUNCHER DEDICATED

OPTIONS_SINGLE=	EXETYPE BACKEND GAME
OPTIONS_SINGLE_EXETYPE=	LAUNCHER DEDICATED
OPTIONS_SINGLE_BACKEND=	TOGL TOGLES

GAMES_LIST=	hl2 hl2mp hl1 episodic portal hl1mp cstrike dod
.for game in ${GAMES_LIST}
OPTIONS_SINGLE_GAME+=		${game:tu}
${game:tu}_CONFIGURE_ON=	--build-games=${game}
${game:tu}_PLIST_SUB=		GAME=${game}
.endfor

BACKEND_DESC=	Graphical backend (any for DEDICATED)
TOGL_DESC=	OpenGL (ToGL)
TOGLES_DESC=	OpenGL ES (ToGLES) (more stable on amd, not tested on nvidia)
EXETYPE_DESC=	Executable type
LAUNCHER_DESC=	Client launcher
DEDICATED_DESC=	Dedicated server
GAME_DESC=	Game to compile
ALL_DESC=	Every game below
HL2_DESC=	Half-Life 2
HL2MP_DESC=	Half-Life 2 Multiplayer
HL1_DESC=	Half-Life: Source
EPISODIC_DESC=	Half-Life: Episode
PORTAL_DESC=	Portal
HL1MP_DESC=	Half-Life Multiplayer: Source
CSTRIKE_DESC=	Counter-Strike
DOD_DESC=	Day of defeat

LAUNCHER_USES=		sdl openal jpeg gl
LAUNCHER_LIB_DEPENDS=	libcurl.so:ftp/curl \
			libfreetype.so:print/freetype2 \
			libfontconfig.so:x11-fonts/fontconfig \
			libpng.so:graphics/png
#LAUNCHER_CONFIGURE_ON=	--launcher
DEDICATED_CONFIGURE_ON=	--dedicated
DEDICATED_PLIST_SUB=	TOGL="@comment " TOGLES="@comment "
DEDICATED_USES=		libedit
TOGL_USE=		GL=opengl
TOGLES_USE=		GL=egl
TOGLES_CONFIGURE_ON=	--togles

post-install:
.ifndef WITH_DEBUG
	${FIND} ${STAGEDIR}${PREFIX}/bin -type f -exec ${STRIP_CMD} {} \;
	${FIND} ${STAGEDIR}${PREFIX}/lib -name '*.so' -type f -exec ${STRIP_CMD} {} \;
.endif

.include <bsd.port.mk>
