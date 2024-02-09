PORTNAME=	armcord
DISTVERSIONPREFIX=	v
DISTVERSION=	3.2.6
CATEGORIES=	net-im www
DISTFILES=	${PREFETCH_BUILD_FILE}:prefetch \
		${PREFETCH_INSTALL_FILE}:prefetch

MAINTAINER=	er2@dismail.de
COMMENT=	Custom Discord client
WWW=		https://github.com/ArmCord/ArmCord

LICENSE_NAME=	OSL3
#LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept
LICENSE_FILE=	${WRKSRC}/LICENSE

FETCH_DEPENDS=	npm:www/npm${NODEJS_SUFFIX}
BUILD_DEPENDS=	npm:www/npm${NODEJS_SUFFIX} \
		electron25>=25.0.0:devel/electron25
RUN_DEPENDS=	electron25>=25.0.0:devel/electron25

USES=		desktop-file-utils
USE_GITHUB=	yes
GH_ACCOUNT=	ArmCord
GH_PROJECT=	ArmCord

# Taken from security/bitwarden-cli

PREFETCH_BUILD_FILE=	${PORTNAME}-${DISTVERSION}-node-modules-build${EXTRACT_SUFX}
PREFETCH_INSTALL_FILE=	${PORTNAME}-${DISTVERSION}-node-modules-install${EXTRACT_SUFX}
NPM_BUILD_DEPENDS=	copyfiles@2.4.1 typescript@4.9.3 \
			@types/node@18.11.9 @types/ws@8.5.3 electron@28.2.0 \
			ws@8.11.0 cross-fetch@3.1.5 \
			electron-context-menu@github:ArmCord/electron-context-menu \
			@electron/asar@3.2.8
NPM_INSTALL_DEPENDS=	cross-fetch@3.1.5 ws@8.11.0 \
			electron-context-menu@github:ArmCord/electron-context-menu \
			extract-zip@2.0.1 v8-compile-cache@2.3.0

pre-fetch:
	if [ ! -f ${DISTDIR}/${PREFETCH_BUILD_FILE} ]; then \
		${MKDIR} ${WRKDIR}/node-modules-build-cache; \
		cd ${WRKDIR}/node-modules-build-cache && \
		${SETENV} HOME=${WRKDIR} \
			npm i ${NPM_BUILD_DEPENDS} --ignore-scripts --no-progress --no-audit --no-fund; \
		${FIND} ${WRKDIR}/node-modules-build-cache -depth 1 -print | \
			${GREP} -v node_modules | ${XARGS} ${RM} -r; \
		${FIND} ${WRKDIR}/node-modules-build-cache -type d -exec ${CHMOD} 755 {} ';'; \
		cd ${WRKDIR}/node-modules-build-cache && \
		mv node_modules node_modules.build && \
		${MTREE_CMD} -cbnSp node_modules.build | ${MTREE_CMD} -C | ${SED} \
			-e 's:time=[0-9.]*:time=${PREFETCH_TIMESTAMP}.000000000:' \
			-e 's:\([gu]id\)=[0-9]*:\1=0:g' \
			-e 's:flags=.*:flags=none:' \
			-e 's:^\.:./node_modules.build:' > node-modules-build-cache.mtree; \
		${TAR} -cz --options 'gzip:!timestamp' \
			-f ${DISTDIR}/${PREFETCH_BUILD_FILE} \
			@node-modules-build-cache.mtree; \
		${RM} -r ${WRKDIR}; \
	fi
	if [ ! -f ${DISTDIR}/${PREFETCH_INSTALL_FILE} ]; then \
		${MKDIR} ${WRKDIR}/node-modules-install-cache; \
		cd ${WRKDIR}/node-modules-install-cache && \
		${SETENV} HOME=${WRKDIR} \
			npm i ${NPM_INSTALL_DEPENDS} --ignore-scripts --no-progress --no-audit --no-fund; \
		${FIND} ${WRKDIR}/node-modules-install-cache -depth 1 -print | \
			${GREP} -v node_modules | ${XARGS} ${RM} -r; \
		${FIND} ${WRKDIR}/node-modules-install-cache -type d -exec ${CHMOD} 755 {} ';'; \
		cd ${WRKDIR}/node-modules-install-cache && \
		${MTREE_CMD} -cbnSp node_modules | ${MTREE_CMD} -C | ${SED} \
			-e 's:time=[0-9.]*:time=${PREFETCH_TIMESTAMP}.000000000:' \
			-e 's:\([gu]id\)=[0-9]*:\1=0:g' \
			-e 's:flags=.*:flags=none:' \
			-e 's:^\.:./node_modules:' > node-modules-install-cache.mtree; \
		${TAR} -cz --options 'gzip:!timestamp' \
			-f ${DISTDIR}/${PREFETCH_INSTALL_FILE} \
			@node-modules-install-cache.mtree; \
		${RM} -r ${WRKDIR}; \
	fi

# fuck nodejs
post-extract:
	@${MV} ${WRKDIR}/node_modules.build ${WRKSRC}/node_modules

do-build:
	@cd ${WRKSRC} && npm run build

pre-install:
	@${MKDIR} ${WRKSRC}/install
	@${CP} -R ${WRKSRC}/assets/ ${WRKSRC}/install/assets/
	@${CP} -R ${WRKSRC}/ts-out/ ${WRKSRC}/install/ts-out/
	@${CP} -R ${WRKDIR}/node_modules/ ${WRKSRC}/install/node_modules/
	@${CP} -R ${WRKSRC}/src/arrpc/ ${WRKSRC}/install/node_modules/arrpc/
	@${CP} -R ${FILESDIR}/package.json ${WRKSRC}/install/package.json

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/512x512/apps/
	${INSTALL_DATA} ${WRKSRC}/assets/desktop.png ${STAGEDIR}${PREFIX}/share/icons/hicolor/512x512/apps/armcord.png
	${INSTALL_DATA} ${FILESDIR}/armcord.desktop ${STAGEDIR}${DESKTOPDIR}/armcord.desktop
	@cd ${WRKSRC} && npx asar pack install/ ${STAGEDIR}${DATADIR}/app.asar

.include <bsd.port.mk>
