PORTNAME=	ghidra
PORTVERSION=	0.7.0
DISTVERSIONPREFIX=v
PORTREVISION=	1
CATEGORIES=	lang devel
PKGNAMEPREFIX=	rizin-

MAINTAINER=	er2@dismail.de
COMMENT=	Deep ghidra decompiler and sleigh disassembler integration for rizin
WWW=		https://github.com/rizinorg/rz-ghidra/

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	librz_main.so:lang/rizin

USES=		cmake compiler:c++11-lib desktop-file-utils pkgconfig python
USE_GITHUB=	yes
GH_ACCOUNT=	rizinorg
GH_PROJECT=	rz-ghidra
GH_TUPLE=	rizinorg:ghidra:b82c65a:ghidra/ghidra/ghidra \
		zeux:pugixml:fdf0295:pugixml/third-party/pugixml

CMAKE_ARGS=	-DBUILD_CUTTER_PLUGIN=ON -DBUILD_SLEIGH_PLUGIN=ON -DCUTTER_USER_PLUGDIR="${STAGEDIR}${PREFIX}/lib/rizin/plugins"

.include <bsd.port.mk>
