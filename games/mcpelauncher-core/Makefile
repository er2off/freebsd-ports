PORTNAME=	core
DISTVERSIONPREFIX=	v
DISTVERSION=	1.4.1
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
GH_TUPLE=	minecraft-linux:android-support-headers:17b018e:androidsupportheaders/android-support-headers \
		minecraft-linux:arg-parser:888bc2f:argparser/arg-parser \
		minecraft-linux:base64:1a11a45:base64/base64 \
		minecraft-linux:cll-telemetry:5410472:clltelemetry/cll-telemetry \
		minecraft-linux:daemon-utils:f75fc4a:daemonutils/daemon-utils \
		minecraft-linux:epoll-shim:a53248d:epollshim/epoll-shim \
		minecraft-linux:file-picker:8c542e1:filepicker/file-picker \
		minecraft-linux:file-util:3e7be1e:fileutil/file-util \
		minecraft-linux:game-window:eb0ca80:gamewindow/game-window \
		ocornut:imgui:fd75bdc:imgui/imgui \
		er2off:libc-shim:b6ad925:libcshim/libc-shim \
		ChristopherHX:libjnivm:8c9db81:libjnivm/libjnivm \
		minecraft-linux:logger:a559598:logger/logger \
		minecraft-linux:mcpelauncher-client:f7eeae3:mcpelauncherclient/mcpelauncher-client \
		minecraft-linux:mcpelauncher-common:277c84a:mcpelaunchercommon/mcpelauncher-common \
		minecraft-linux:mcpelauncher-core:d08b13b:mcpelaunchercore/mcpelauncher-core \
		minecraft-linux:mcpelauncher-errorwindow:dd34ad1:mcpelaunchererrorwindow/mcpelauncher-errorwindow \
		minecraft-linux:mcpelauncher-linker:2c0675c:mcpelauncherlinker/mcpelauncher-linker \
		minecraft-linux:android_bionic:b10aecb:android_bionic/mcpelauncher-linker_bionic \
		minecraft-linux:android_core:0235714:core/mcpelauncher-linker_core \
		minecraft-linux:mcpelauncher-linux-bin:f1d4f3a:mcpelauncherlinuxbin/mcpelauncher-linux-bin \
		minecraft-linux:mcpelauncher-webview:9eb9487:mcpelauncherwebview/mcpelauncher-webview \
		minecraft-linux:minecraft-imported-symbols:a86fd9d:minecraftimportedsymbols/minecraft-imported-symbols \
		minecraft-linux:msa-daemon-client:a5bb100:msadaemonclient/msa-daemon-client \
		minecraft-linux:properties-parser:7349e4a:propertiesparser/properties-parser \
		MCMrARM:simple-ipc:e71fdbd:simpleipc/simple-ipc \
		nlohmann:json:v3.7.3:json/nlohmann-json \
		mdqinc:SDL_GameControllerDB:7979e7b:controllerdb/gamecontrollerdb \
		libsdl-org:SDL:5ac37a8:sdl3/sdl3

CMAKE_OFF=	USE_OWN_CURL ENABLE_DEV_PATHS
CMAKE_ARGS=	-DGAMEWINDOW_SYSTEM=SDL3 \
		-DFETCHCONTENT_SOURCE_DIR_NLOHMANN_JSON_EXT=${WRKSRC}/nlohmann-json

post-extract:
	@${RM} -r ${WRKSRC}/mcpelauncher-linker/bionic ${WRKSRC}/mcpelauncher-linker/core
	@${MV} ${WRKSRC}/mcpelauncher-linker_bionic ${WRKSRC}/mcpelauncher-linker/bionic
	@${MV} ${WRKSRC}/mcpelauncher-linker_core ${WRKSRC}/mcpelauncher-linker/core

.include <bsd.port.mk>
