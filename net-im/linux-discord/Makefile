PORTNAME=	discord
DISTVERSION=	0.0.35
CATEGORIES=	net-im www linux
MASTER_SITES=	https://dl.discordapp.net/apps/linux/${DISTVERSION}/
PKGNAMEPREFIX=	linux-
#DISTNAME=	discord-${DISTVERSION}

MAINTAINER=	er2@dismail.de
COMMENT=	Discord Client (Linux version)
WWW=		https://discord.com

ONLY_FOR_ARCHS=	amd64

RUN_DEPENDS=	${LOCALBASE}/steam-utils/lib64/fakeudev:games/linux-steam-utils \
		${LOCALBASE}/steam-utils/lib64/webfix/webfix.so:games/linux-steam-utils

USES=		desktop-file-utils linux shared-mime-info

LICENSE_NAME=	EULA
LICENSE_PERMS=	dist-mirror pkg-mirror auto-accept

NO_BUILD=	YES
PATCH_WRKSRC=	${WRKDIR}
WRKSRC=		${WRKDIR}/Discord
#USE_LINUX_PREFIX=	YES

post-patch:
	@${REINPLACE_CMD} -Ee \
		'/Name/ s|Discord|Discord (Linux)|; /^Exec/ s|/usr/share/discord/Discord|/usr/local/bin/linux-discord|; /^Path/ s|/usr/bin|/usr/local/bin|' \
		${WRKSRC}/discord.desktop

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/linux-discord ${STAGEDIR}${PREFIX}/bin/
	@${MKDIR} ${STAGEDIR}${LINUXBASE}/bin
	@${MKDIR} ${STAGEDIR}${LINUXBASE}/share/discord
	@${CP} ${WRKSRC}/discord.desktop \
		${STAGEDIR}${PREFIX}/share/applications/
	@${CP} ${WRKSRC}/discord.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/
	${INSTALL_SCRIPT} ${WRKDIR}/discord ${STAGEDIR}${LINUXBASE}/bin/
	@${CP} -r ${WRKDIR}/Discord/* ${STAGEDIR}${LINUXBASE}/share/discord

.include <bsd.port.mk>
