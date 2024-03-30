PORTNAME=	mcpelauncher
DISTVERSIONPREFIX=	v
DISTVERSIONSUFFIX=	-qt6
DISTVERSION=	0.14.1
CATEGORIES=	games
#MASTER_SITES=	https://github.com/nlohmann/json/releases/download/v3.7.3/include.zip

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
		minecraft-linux:cll-telemetry:b31d77d:clltelemetry/cll-telemetry \
		minecraft-linux:daemon-utils:f380f5b:daemonutils/daemon-utils \
		minecraft-linux:eglut:7007a34:eglut/eglut \
		minecraft-linux:epoll-shim:c007a00:epollshim/epoll-shim \
		minecraft-linux:file-picker:f5cbac6:filepicker/file-picker \
		minecraft-linux:file-util:ce7d0d6:fileutil/file-util \
		minecraft-linux:game-window:ddf11ba:gamewindow/game-window \
		minecraft-linux:libc-shim:736b89d:libcshim/libc-shim \
		ocornut:imgui:278cf1a:imgui/imgui \
		ChristopherHX:libjnivm:8c9db81:libjnivm/libjnivm \
		MCMrARM:linux-gamepad:68d75a7:linuxgamepad/linux-gamepad \
		minecraft-linux:logger:a559598:logger/logger \
		minecraft-linux:mcpelauncher-client:271f8a9:mcpelauncherclient/mcpelauncher-client \
		minecraft-linux:mcpelauncher-common:277c84a:mcpelaunchercommon/mcpelauncher-common \
		minecraft-linux:mcpelauncher-core:f5670f1:mcpelaunchercore/mcpelauncher-core \
		minecraft-linux:mcpelauncher-errorwindow:dd34ad1:mcpelaunchererrorwindow/mcpelauncher-errorwindow \
		minecraft-linux:mcpelauncher-linker:678a33e:mcpelauncherlinker/mcpelauncher-linker \
		minecraft-linux:android_bionic:59dbc15:android_bionic/mcpelauncher-linker_bionic \
		aosp-mirror:platform_system_core:d26f8c9:core/mcpelauncher-linker_core \
		minecraft-linux:mcpelauncher-linux-bin:1e84fde:mcpelauncherlinuxbin/mcpelauncher-linux-bin \
		minecraft-linux:mcpelauncher-webview:9eb9487:mcpelauncherwebview/mcpelauncher-webview \
		minecraft-linux:minecraft-imported-symbols:17d9b14:minecraftimportedsymbols/minecraft-imported-symbols \
		minecraft-linux:msa-daemon-client:a5bb100:msadaemonclient/msa-daemon-client \
		minecraft-linux:properties-parser:79f5360:propertiesparser/properties-parser \
		MCMrARM:simple-ipc:fb5734e:simpleipc/simple-ipc \
		nlohmann:json:v3.7.3:json/nlohmann-json
#		libsdl-org:SDL:c00b6a8:sdl3/sdl3

#    file(DOWNLOAD "https://raw.githubusercontent.com/gabomdq/SDL_GameControllerDB/master/gamecontrollerdb.txt"
#            ${GAMECONTROLLERDB_DIR}/gamecontrollerdb.txt)
#    file(DOWNLOAD "https://raw.githubusercontent.com/gabomdq/SDL_GameControllerDB/master/LICENSE"
#            ${GAMECONTROLLERDB_DIR}/LICENSE)

#CMAKE_ARGS=	-DLauncher_BUILD_PLATFORM=FreeBSD
CMAKE_OFF=	USE_OWN_CURL ENABLE_DEV_PATHS

post-extract:
	@rm -r ${WRKSRC}/mcpelauncher-linker/bionic ${WRKSRC}/mcpelauncher-linker/core
	@mv ${WRKSRC}/mcpelauncher-linker_bionic ${WRKSRC}/mcpelauncher-linker/bionic
	@mv ${WRKSRC}/mcpelauncher-linker_core ${WRKSRC}/mcpelauncher-linker/core

.include <bsd.port.mk>
