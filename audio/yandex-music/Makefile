PORTNAME=	yandex-music
DISTVERSIONPREFIX=	v
DISTVERSION=	5.53.1
CATEGORIES=	audio www
MASTER_SITES=	https://music-desktop-application.s3.yandex.net/stable/:7z
DISTFILES=	${PREFETCH_BUILD_FILE}:prefetch \
		Yandex_Music_x64_${DISTVERSION}.exe:7z

MAINTAINER=	er2@dismail.de
COMMENT=	Official Yandex Music client (patched for FreeBSD)
WWW=		https://music.yandex.ru

LICENSE=	EULA
LICENSE_NAME=	Terms of Use of Yandex.Music
# Actually wrong, this should be grab from https://yandex.ru/legal/music_termsofuse
LICENSE_FILE=	${WRKSRC}/LICENSE.md
LICENSE_PERMS=	dist-mirror pkg-mirror auto-accept

FETCH_DEPENDS=	npm:www/npm${NODEJS_SUFFIX}
BUILD_DEPENDS=	npm:www/npm${NODEJS_SUFFIX} \
		bash:shells/bash \
		gsed:textproc/gsed \
		electron${ELECTRON_VER_MAJOR}:devel/electron${ELECTRON_VER_MAJOR}
RUN_DEPENDS=	electron${ELECTRON_VER_MAJOR}:devel/electron${ELECTRON_VER_MAJOR}

USES=		7z:7-zip,partial desktop-file-utils shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	cucumber-sp
GH_PROJECT=	yandex-music-linux

ELECTRON_VER_MAJOR= 34

SHEBANG_FILES=	templates/yandex-music.sh

OPTIONS_DEFINE=		PLUS
OPTIONS_DEFAULT=

PLUS_DESC=	Activates Yandex plus bypass (For personal use only, violates EULA)

.include <bsd.port.options.mk>

# Taken from security/bitwarden-cli

PREFETCH_BUILD_FILE=	${PORTNAME}-${DISTVERSION}-node-modules-build${EXTRACT_SUFX}
NPM_BUILD_DEPENDS=	@electron/asar@3.2.8

pre-fetch:
	if [ ! -f ${DISTDIR}/${PREFETCH_BUILD_FILE} ]; then \
		${MKDIR} ${WRKDIR}/node-modules-cache; \
		cd ${WRKDIR}/node-modules-cache && \
		${SETENV} HOME=${WRKDIR} \
			npm i ${NPM_BUILD_DEPENDS} --ignore-scripts --no-progress --no-audit --no-fund; \
		${FIND} ${WRKDIR}/node-modules-cache -depth 1 -print | \
			${GREP} -v node_modules | ${XARGS} ${RM} -r; \
		${FIND} ${WRKDIR}/node-modules-cache -type d -exec ${CHMOD} 755 {} ';'; \
		cd ${WRKDIR}/node-modules-cache && \
		${MTREE_CMD} -cbnSp node_modules | ${MTREE_CMD} -C | ${SED} \
			-e 's:time=[0-9.]*:time=${PREFETCH_TIMESTAMP}.000000000:' \
			-e 's:\([gu]id\)=[0-9]*:\1=0:g' \
			-e 's:flags=.*:flags=none:' \
			-e 's:^\.:./node_modules:' > node-modules-cache.mtree; \
		${TAR} -cz --options 'gzip:!timestamp' \
			-f ${DISTDIR}/${PREFETCH_BUILD_FILE} \
			@node-modules-cache.mtree; \
		${RM} -r ${WRKDIR}; \
	fi

post-extract:
	@${MV} ${WRKDIR}/node_modules ${WRKSRC}/node_modules
	@${CP} ${FILESDIR}/0008-freebsd-fixes.patch ${WRKSRC}/patches/
# Prepare sources
	@${MKDIR} "${WRKSRC}/Extracted" "${WRKSRC}/app"
	7z x "${WRKDIR}/\$$PLUGINSDIR/app-64.7z" -o"${WRKSRC}/Extracted"
	cd ${WRKSRC} && npx asar extract "${WRKSRC}/Extracted/resources/app.asar" "${WRKSRC}/app/app"
.if ${PORT_OPTIONS:MPLUS} # Plus activated
	@${CP} ${FILESDIR}/0009-hack-activate.patch ${WRKSRC}/patches/
	@${CP} ${FILESDIR}/plus-hack.js ${WRKSRC}/app/app/main/
.endif

do-build:
	@cd ${WRKSRC} && bash ./repack.sh

# Partially copy of build-tarball.sh
do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	${CP} ${WRKSRC}/app/yandex-music.asar ${STAGEDIR}${DATADIR}/yandex-music.asar
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/48x48/apps/
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/512x512/apps/
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps/
	${INSTALL_DATA} ${WRKSRC}/app/favicon.png ${STAGEDIR}${PREFIX}/share/pixmaps/yandex-music.png
	${INSTALL_DATA} ${WRKSRC}/app/favicon.png ${STAGEDIR}${PREFIX}/share/icons/hicolor/48x48/apps/yandex-music.png
	${INSTALL_DATA} ${WRKSRC}/app/favicon-512x512.png ${STAGEDIR}${PREFIX}/share/icons/hicolor/512x512/apps/yandex-music.png
	${INSTALL_DATA} ${WRKSRC}/app/favicon.svg ${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps/yandex-music.svg

	${INSTALL_DATA} ${WRKSRC}/templates/desktop ${STAGEDIR}${DESKTOPDIR}/yandex-music.desktop
	${INSTALL_DATA} ${WRKSRC}/templates/default.conf ${STAGEDIR}${DATADIR}/default.conf
	${INSTALL_SCRIPT} ${WRKSRC}/templates/yandex-music.sh ${WRKSRC}/app/yandex-music
	@${REINPLACE_CMD} -e 's|/usr/lib/yandex-music|${DATADIR}|; s|%asar_path%|${DATADIR}/yandex-music.asar|; s|%electron_path%|${PREFIX}/bin/electron${ELECTRON_VER_MAJOR}|' \
		${WRKSRC}/app/yandex-music
	${INSTALL_SCRIPT} ${WRKSRC}/app/yandex-music ${STAGEDIR}${PREFIX}/bin/yandex-music

.include <bsd.port.mk>
