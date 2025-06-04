PORTNAME=	groaac
PORTVERSION=	1.0
DISTVERSIONPREFIX=	v.
PORTREVISION=	1
CATEGORIES=	audio python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	er2@dismail.de
COMMENT=	Extract MP3s from MP4 files
WWW=		https://github.com/GMDProjectL/groaac

LICENSE=	WTFPL

RUN_DEPENDS=	ffmpeg:multimedia/ffmpeg \
		${PYTHON_PKGNAMEPREFIX}dbus>=0:devel/py-dbus@${PY_FLAVOR}

USES=		python
USE_GITHUB=	yes
GH_ACCOUNT=	GMDProjectL
USE_WX=		3.2+
WX_COMPS=	python:run wx

NO_ARCH=	yes
NO_BUILD=	yes

do-patch:
	@${REINPLACE_CMD} -e 's|/opt/groaac|${DATADIR}|; s|python3|${PYTHON_CMD}|' \
		${WRKSRC}/groaac.desktop

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/*.py ${WRKSRC}/groaac.png \
		${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/groaac.desktop \
		${STAGEDIR}${DESKTOPDIR}/groaac.desktop

.include <bsd.port.mk>
