PORTNAME=	solaar
DISTVERSION=	1.1.14
CATEGORIES=	sysutils

MAINTAINER=	er2+ports@dismail.de
COMMENT=	Device manager for the Logitech Unifying Receiver
WWW=		https://pwr-solaar.github.io/Solaar/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

# libhidapi.so is only loaded at runtime via ctypes (dlopen)
RUN_DEPENDS=	${LOCALBASE}/lib/libhidapi.so:comms/hidapi \
		${PYTHON_PKGNAMEPREFIX}pyyaml>=0:devel/py-pyyaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-xlib>=0:x11-toolkits/py-python-xlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}psutil>=0:sysutils/py-psutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pygobject>=0:devel/py-pygobject@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>=0:devel/py-typing-extensions@${PY_FLAVOR}

USES=		python
USE_GITHUB=	yes
GH_ACCOUNT=	pwr-Solaar
GH_PROJECT=	Solaar
USE_PYTHON=	autoplist concurrent distutils optsuffix

NO_ARCH=	yes

OPTIONS_DEFINE=	GUI

GUI_USES=	gnome
GUI_USE=	GNOME=pygobject3:run

post-build:
	${AWK} -f ${FILESDIR}/devd-solaar.awk \
		${WRKSRC}/rules.d/42-logitech-unify-permissions.rules \
		> ${WRKDIR}/solaar.conf.sample

post-install:
	${INSTALL_DATA} ${WRKDIR}/solaar.conf.sample \
		${STAGEDIR}${PREFIX}/etc/devd

.include <bsd.port.mk>
