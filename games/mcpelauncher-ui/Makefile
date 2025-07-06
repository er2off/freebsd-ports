PORTNAME=	ui
DISTVERSIONPREFIX=	v
DISTVERSION=	1.4.1
DISTVERSIONSUFFIX=	-qt6
CATEGORIES=	games
PKGNAMEPREFIX=	mcpelauncher-

MAINTAINER=	er2@dismail.de
COMMENT=	Minecraft Bedrock Edition UI launcher
WWW=		https://mcpelauncher.readthedocs.io/

LICENSE=	GPLv3

USES=		cmake compiler:c++17-lang gl pkgconfig qt:6
USE_GL=		gl egl glesv2
USE_QT=		base webengine
USE_GITHUB=	yes
GH_ACCOUNT=	minecraft-linux
GH_PROJECT=	mcpelauncher-ui-manifest
GH_TUPLE=	MCMrARM:axml-parser:e5d2610:axmlparser/axml-parser \
		minecraft-linux:file-util:3e7be1e:fileutil/file-util \
		minecraft-linux:Google-Play-API:c8d2452:googleplayapi/google-play-api \
		minecraft-linux:mcpelauncher-apkinfo:ebd853b:mcpelauncherapkinfo/mcpelauncher-apkinfo \
		minecraft-linux:mcpelauncher-common:277c84a:mcpelaunchercommon/mcpelauncher-common \
		minecraft-linux:mcpelauncher-extract:1d447c0:mcpelauncherextract/mcpelauncher-extract \
		minecraft-linux:mcpelauncher-ui-qt:f976c6c:mcpelauncheruiqt/mcpelauncher-ui-qt \
		minecraft-linux:playdl-signin-ui-qt:1f080c9:playdlsigninuiqt/playdl-signin-ui-qt

CMAKE_OFF=	LAUNCHER_ENABLE_GLFW
# Allow piracy?
CMAKE_OFF+=	LAUNCHER_ENABLE_GOOGLE_PLAY_LICENCE_CHECK

.include <bsd.port.mk>
