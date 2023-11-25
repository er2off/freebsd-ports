PORTNAME=	kpmcore
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	sysutils kde-applications

MAINTAINER=	er2@dismail.de
COMMENT=	KDE Partition Manager core library
WWW=		https://invent.kde.org/system/kpmcore

LICENSE=	GPLv3

IGNORE=		not ready yet. If you want to try, comment IGNORE line

LIB_DEPENDS=	libpolkit-qt5-core-1.so:sysutils/polkit-qt

USES=		cmake compiler:c++17-lang gettext kde:5 qt:5 tar:xz
USE_KDE=	auth coreaddons i18n widgetsaddons \
		ecm:build
USE_QT=		concurrent core dbus declarative \
		gui widgets \
		buildtools:build qmake:build
USE_GITHUB=	yes
GH_ACCOUNT=	er2off
GH_PROJECT=	kpmcore
GH_TAGNAME=	freebsd

.include <bsd.port.mk>
