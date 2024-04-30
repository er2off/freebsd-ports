PORTNAME=	msa
DISTVERSIONPREFIX=	v
DISTVERSION=	0.9.0
CATEGORIES=	games
PKGNAMEPREFIX=	mcpelauncher-

MAINTAINER=	er2@dismail.de
COMMENT=	Microsoft Account login daemon
WWW=		https://mcpelauncher.readthedocs.io/

LICENSE=	GPLv3

USES=		cmake compiler:c++17-lang gl pkgconfig qt:6
USE_GL=		gl egl glesv2
USE_QT=		base
USE_GITHUB=	yes
GH_ACCOUNT=	minecraft-linux
GH_PROJECT=	msa-manifest
GH_TUPLE=	MCMrARM:axml-parser:e5d2610:axmlparser/axml-parser \
		minecraft-linux:file-util:ce7d0d6:fileutil/file-util \
		minecraft-linux:Google-Play-API:7940ada:googleplayapi/google-play-api \
		minecraft-linux:mcpelauncher-apkinfo:04dd54b:mcpelauncherapkinfo/mcpelauncher-apkinfo \
		minecraft-linux:mcpelauncher-common:277c84a:mcpelaunchercommon/mcpelauncher-common \
		minecraft-linux:mcpelauncher-extract:82a841a:mcpelauncherextract/mcpelauncher-extract \
		minecraft-linux:mcpelauncher-ui-qt:ca0e99d:mcpelauncheruiqt/mcpelauncher-ui-qt \
		minecraft-linux:playdl-signin-ui-qt:02a89aa:playdlsigninuiqt/playdl-signin-ui-qt

GH_TUPLE=	minecraft-linux:arg-parser:888bc2f:argparser/arg-parser \
		minecraft-linux:base64:1a11a45:base64/base64 \
		minecraft-linux:daemon-utils:f75fc4a:daemonutils/daemon-utils \
		minecraft-linux:file-util:ce7d0d6:fileutil/file-util \
		minecraft-linux:logger:a559598:logger/logger \
		minecraft-linux:msa:fb69b65:msa/msa \
		minecraft-linux:msa-daemon:d5922ba:msadaemon/msa-daemon \
		minecraft-linux:msa-daemon-client:2f2130d:msadaemonclient/msa-daemon-client \
		minecraft-linux:msa-ui-qt:1193b63:msauiqt/msa-ui-qt \
		minecraft-linux:rapidxml:8a5078a:rapidxml/rapidxml \
		MCMrARM:simple-ipc:e71fdbd:simpleipc/simple-ipc \
		nlohmann:json:v3.7.3:json/nlohmann-json
#		minecraft-linux:msa-ui-gtk:65e4761:msauigtk/msa-ui-gtk

CMAKE_ON=	ENABLE_MSA_QT_UI FREEBSD
CMAKE_OFF=	MSA_UI_PATH_DEV
CMAKE_ARGS=	-DFETCHCONTENT_SOURCE_DIR_NLOHMANN_JSON_EXT=${WRKSRC}/nlohmann-json \
		-DQT_VERSION=6

.include <bsd.port.mk>
