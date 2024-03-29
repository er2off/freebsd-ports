PORTNAME=	cutter
PORTVERSION=	2.3.4
DISTVERSIONPREFIX=v
PORTREVISION=	1
CATEGORIES=	lang devel
PKGNAMEPREFIX=	rizin-

MAINTAINER=	er2@dismail.de
COMMENT=	Free and Open Source Reverse Engineering Platform
WWW=		https://cutter.re/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	librz_main.so:lang/rizin

BUILD_DEPENDS=	meson:devel/meson \
		ninja:devel/ninja \
		${PYTHON_PKGNAMEPREFIX}pyaml>=23.5.9:textproc/py-pyaml@${PY_FLAVOR}

USES=		cmake compiler:c++11-lib desktop-file-utils pkgconfig python
USE_GITHUB=	yes
GH_ACCOUNT=	rizinorg
GH_TUPLE=	rizinorg:cutter-translations:8358f17:translations/src/translations
USE_QT=		base

OPTIONS_DEFINE=		QT6
OPTIONS_DEFAULT=	QT6

QT6_DESC=		Use Qt6 instead of Qt5
QT6_USE=		qt:6
QT6_USE_OFF=		qt:5
QT6_CMAKE_BOOL=		CUTTER_QT6

CMAKE_ARGS=		-DCUTTER_USE_BUNDLED_RIZIN=OFF

.include <bsd.port.mk>
