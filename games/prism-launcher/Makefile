PORTNAME=	prism-launcher
DISTVERSION=	8.2
CATEGORIES=	games java

MAINTAINER=	er2@dismail.de
COMMENT=	Minecraft launcher with the ability to manage multiple instances
WWW=		https://prismlauncher.org

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING.md

RUN_DEPENDS=	lwjgl>=2.9.3:games/lwjgl \
		lwjgl3>=3.0:games/lwjgl3

USES=		cmake compiler:c++17-lang qt:6 kde:5
USE_KDE=	ecm:build
USE_GITHUB=	yes
GH_ACCOUNT=	PrismLauncher
GH_PROJECT=	PrismLauncher
GH_TUPLE=	commonmark:cmark:8fbf029:cmark/libraries/cmark \
		gulrak:filesystem:2fc4b46:filesystem/libraries/filesystem \
		PrismLauncher:libnbtplusplus:23b9551:libnbtplusplus/libraries/libnbtplusplus \
		stachenov:quazip:9d3aa3e:quazip/libraries/quazip \
		marzer:tomlplusplus:7eb2ffc:tomlplusplus/libraries/tomlplusplus
USE_LDCONFIG=	yes
USE_JAVA=	8+
USE_QT=		5compat base

CMAKE_ARGS=	-DLauncher_BUILD_PLATFORM=FreeBSD

.include <bsd.port.mk>
