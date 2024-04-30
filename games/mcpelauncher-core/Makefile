PORTNAME=	core
DISTVERSIONPREFIX=	v
DISTVERSION=	0.14.3
DISTVERSIONSUFFIX=	-qt6
CATEGORIES=	games
PKGNAMEPREFIX=	mcpelauncher-

MAINTAINER=	er2@dismail.de
COMMENT=	Minecraft Bedrock Edition launcher
WWW=		https://mcpelauncher.readthedocs.io/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${LOCALBASE}/include/pulse/pulseaudio.h:audio/pulseaudio
LIB_DEPENDS=	libpng.so:graphics/png

USES=		cmake compiler:c++17-lang gl pkgconfig qt:6
USE_GL=		gl egl glesv2
USE_QT=		base webengine
USE_GITHUB=	yes
GH_ACCOUNT=	minecraft-linux
GH_PROJECT=	mcpelauncher-manifest
GH_TUPLE=	minecraft-linux:android-support-headers:bd60029:androidsupportheaders/android-support-headers \
		minecraft-linux:arg-parser:888bc2f:argparser/arg-parser \
		minecraft-linux:base64:1a11a45:base64/base64 \
		minecraft-linux:cll-telemetry:5410472:clltelemetry/cll-telemetry \
		minecraft-linux:daemon-utils:f75fc4a:daemonutils/daemon-utils \
		minecraft-linux:epoll-shim:a53248d:epollshim/epoll-shim \
		minecraft-linux:file-picker:f5cbac6:filepicker/file-picker \
		minecraft-linux:file-util:ce7d0d6:fileutil/file-util \
		minecraft-linux:game-window:2b92aa8:gamewindow/game-window \
		ocornut:imgui:278cf1a:imgui/imgui \
		minecraft-linux:libc-shim:e6fb756:libcshim/libc-shim \
		ChristopherHX:libjnivm:8c9db81:libjnivm/libjnivm \
		minecraft-linux:logger:a559598:logger/logger \
		minecraft-linux:mcpelauncher-client:935a409:mcpelauncherclient/mcpelauncher-client \
		minecraft-linux:mcpelauncher-common:277c84a:mcpelaunchercommon/mcpelauncher-common \
		minecraft-linux:mcpelauncher-core:97c39f3:mcpelaunchercore/mcpelauncher-core \
		minecraft-linux:mcpelauncher-errorwindow:ee3a95d:mcpelaunchererrorwindow/mcpelauncher-errorwindow \
		minecraft-linux:mcpelauncher-linker:0538aee:mcpelauncherlinker/mcpelauncher-linker \
		minecraft-linux:android_bionic:116d910:android_bionic/mcpelauncher-linker_bionic \
		minecraft-linux:android_core:0235714:core/mcpelauncher-linker_core \
		minecraft-linux:mcpelauncher-linux-bin:1e84fde:mcpelauncherlinuxbin/mcpelauncher-linux-bin \
		minecraft-linux:mcpelauncher-webview:cbd635c:mcpelauncherwebview/mcpelauncher-webview \
		minecraft-linux:minecraft-imported-symbols:17d9b14:minecraftimportedsymbols/minecraft-imported-symbols \
		minecraft-linux:msa-daemon-client:a5bb100:msadaemonclient/msa-daemon-client \
		minecraft-linux:properties-parser:79f5360:propertiesparser/properties-parser \
		MCMrARM:simple-ipc:e71fdbd:simpleipc/simple-ipc \
		nlohmann:json:v3.7.3:json/nlohmann-json \
		mdqinc:SDL_GameControllerDB:aa9cc41:controllerdb/gamecontrollerdb \
		libsdl-org:SDL:c00b6a8:sdl3/sdl3

CMAKE_OFF=	USE_OWN_CURL ENABLE_DEV_PATHS
CMAKE_ARGS=	-DGAMEWINDOW_SYSTEM=SDL3 \
		-DFETCHCONTENT_SOURCE_DIR_NLOHMANN_JSON_EXT=${WRKSRC}/nlohmann-json

post-extract:
	@${RM} -r ${WRKSRC}/mcpelauncher-linker/bionic ${WRKSRC}/mcpelauncher-linker/core
	@${MV} ${WRKSRC}/mcpelauncher-linker_bionic ${WRKSRC}/mcpelauncher-linker/bionic
	@${MV} ${WRKSRC}/mcpelauncher-linker_core ${WRKSRC}/mcpelauncher-linker/core

.include <bsd.port.mk>
