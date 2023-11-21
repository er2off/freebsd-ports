PORTNAME=	prism-launcher
DISTVERSION=	8.0
CATEGORIES=	games java

MAINTAINER=	er2@dismail.de
COMMENT=	Minecraft launcher with the ability to manage multiple instances
WWW=		https://prismlauncher.org

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING.md

RUN_DEPENDS=	lwjgl>=2.9.3:games/lwjgl \
		lwjgl3>=3.0:games/lwjgl3

USES=		cmake compiler:c++17-lang qt:5 kde:5
USE_KDE=	ecm:build
USE_GITHUB=	yes
GH_ACCOUNT=	PrismLauncher
GH_PROJECT=	PrismLauncher
GH_TUPLE=	commonmark:cmark:5ba25ff:cmark/libraries/cmark \
		gulrak:filesystem:8a2edd6:filesystem/libraries/filesystem \
		PrismLauncher:libnbtplusplus:a5e8fd5:libnbtplusplus/libraries/libnbtplusplus \
		stachenov:quazip:6117161:quazip/libraries/quazip \
		marzer:tomlplusplus:7eb2ffc:tomlplusplus/libraries/tomlplusplus
USE_LDCONFIG=	yes
USE_JAVA=	8+
USE_QT=		core concurrent gui network testlib:build widgets xml

post-install:
	@${INSTALL_SCRIPT} ${.CURDIR}/minecraft-runtime ${STAGEDIR}${PREFIX}/bin/minecraft-runtime

.include <bsd.port.mk>
