PORTNAME=	partitionmanager
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	sysutils kde kde-applications

MAINTAINER=	er2@dismail.de
COMMENT=	KDE utility for management of disks, partitions and file systems
WWW=		https://apps.kde.org/partitionmanager/

LICENSE=	GPLv3

IGNORE=		not ready yet. If you want to try, comment IGNORE line

LIB_DEPENDS=	libkpmcore.so:sysutils/kpmcore

USES=		cmake compiler:c++11-lang desktop-file-utils gettext kde:5 \
		cpe qt:5 tar:xz xorg
USE_KDE=	config configwidgets coreaddons crash dbusaddons i18n jobwidgets \
		widgetsaddons windowsystem xmlgui
USE_QT=		core dbus gui widgets
USE_XORG=	x11
USE_LDCONFIG=	yes

.include <bsd.port.mk>
