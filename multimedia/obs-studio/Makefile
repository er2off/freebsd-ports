PORTNAME=	obs-studio
DISTVERSION=	30.0.0
PORTREVISION=	1
CATEGORIES=	multimedia

MAINTAINER=	er2@dismail.de
COMMENT=	Open source streaming/recording software
WWW=		https://obsproject.com/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN_FreeBSD_12=	fatal error: 'sys/eventfd.h' file not found

BUILD_DEPENDS=	v4l_compat>=0:multimedia/v4l_compat \
		nlohmann-json>=0:devel/nlohmann-json \
		websocketpp>=0:devel/websocketpp \
		asio>=0:net/asio \
		swig:devel/swig
LIB_DEPENDS=	libavcodec.so:multimedia/ffmpeg \
		libcurl.so:ftp/curl \
		libdatachannel.so:www/libdatachannel \
		libdbus-1.so:devel/dbus \
		libfdk-aac.so:audio/fdk-aac \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libjansson.so:devel/jansson \
		libmbedtls.so:security/mbedtls \
		libpci.so:devel/libpci \
		librist.so:multimedia/librist \
		librnnoise.so:audio/rnnoise \
		libspeexdsp.so:audio/speexdsp \
		libsrt.so:www/srt \
		libsysinfo.so:devel/libsysinfo \
		libudev.so:devel/libudev-devd \
		libv4l2.so:multimedia/libv4l \
		libx264.so:multimedia/libx264 \
		libxcb-ewmh.so:x11/xcb-util-wm \
		libxcb-image.so:x11/xcb-util-image \
		libxcb-keysyms.so:x11/xcb-util-keysyms \
		libxcb-render-util.so:x11/xcb-util-renderutil \
		libxcb-util.so:x11/xcb-util \
		libxkbcommon.so:x11/libxkbcommon \
		libuuid.so:misc/e2fsprogs-libuuid \
		libva.so:multimedia/libva

		#libqrcodegen.so:graphics/qr-code-generator

USES=		cmake compiler:c++17-lang desktop-file-utils gl gnome lua luajit \
		pkgconfig python qt:6 xorg
USE_QT=		base svg tools:build
USE_GNOME=	glib20
USE_GL=		gl
USE_XORG=	ice sm x11 xcb xcomposite xext xfixes xinerama xrandr
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	obsproject
GH_TUPLE=	obsproject:obs-browser:e397df5:obsproject_obs_browser/plugins/obs-browser \
		obsproject:obs-websocket:4ff109b:obsproject_obs_websocket/plugins/obs-websocket \
			nayuki:QR-Code-generator:8518684:nayuki_QR_Code_generator/plugins/obs-websocket/deps/qr \
		Mixer:ftl-sdk:d0c8469:Mixer_ftl_sdk/plugins/obs-outputs/ftl-sdk \
			curl:curl:44b9b4d:curl_curl/plugins/obs-outputs/ftl-sdk/libcurl \
			akheron:jansson:bc5741f:akheron_jansson/plugins/obs-outputs/ftl-sdk/libjansson

CMAKE_ON=	UNIX_STRUCTURE OS_FREEBSD
CMAKE_OFF=	ENABLE_AJA
CMAKE_ARGS=	-DOBS_VERSION_OVERRIDE:STRING="${PORTVERSION}" \
		-DQT_VERSION=6 \
		-DPython_EXECUTABLE="${PYTHON_CMD}"

OPTIONS_DEFINE=		BROWSER PIPEWIRE VLC VST WAYLAND
OPTIONS_DEFAULT=	PIPEWIRE VLC VST WAYLAND
OPTIONS_MULTI=		AUDIO
OPTIONS_MULTI_AUDIO=	JACK PULSEAUDIO SNDIO
OPTIONS_DEFAULT+=	${OPTIONS_MULTI_AUDIO}
OPTIONS_SUB=		yes
AUDIO_DESC=		Audio backends

BROWSER_DESC=		Build OSB browser
BROWSER_CMAKE_BOOL=	BUILD_BROWSER
BROWSER_BROKEN=		Needs CEF (Chromium Embedded Framework) which isn't yet ported

JACK_LIB_DEPENDS=	libjack.so:audio/jack
JACK_CMAKE_ON=		-DENABLE_JACK=TRUE
JACK_CMAKE_OFF=		-DDISABLE_JACK=TRUE

PIPEWIRE_DESC=		Screen capture via PipeWire
PIPEWIRE_LIB_DEPENDS=	libpipewire-0.3.so:multimedia/pipewire
PIPEWIRE_CMAKE_BOOL=	ENABLE_PIPEWIRE

PULSEAUDIO_LIB_DEPENDS=	libpulse.so:audio/pulseaudio
PULSEAUDIO_CMAKE_ON=	-DENABLE_PULSEAUDIO=TRUE
PULSEAUDIO_CMAKE_OFF=	-DDISABLE_PULSEAUDIO=TRUE
PULSEAUDIO_BROKEN_OFF=	https://github.com/obsproject/obs-studio/issues/4025

SNDIO_LIB_DEPENDS=	libsndio.so:audio/sndio
SNDIO_CMAKE_ON=		-DENABLE_SNDIO=TRUE
SNDIO_CMAKE_OFF=	-DDISABLE_SNDIO=TRUE

VLC_DESC=		Enable VLC plugin
VLC_CMAKE_BOOL=		ENABLE_VLC
VLC_LIB_DEPENDS=	libvlc.so:multimedia/vlc

VST_DESC=		Build VST submodule
VST_CMAKE_BOOL=		BUILD_VST

WAYLAND_CATEGORIES=	wayland
WAYLAND_LIB_DEPENDS=	libwayland-client.so:graphics/wayland
WAYLAND_CMAKE_BOOL=	ENABLE_WAYLAND

.include <bsd.port.pre.mk>

.if ${ARCH} != amd64 && ${ARCH} != armv7 && ${ARCH} != i386 && ${ARCH} != powerpc && ${ARCH} != powerpc64 && ${ARCH} != powerpc64le
PLIST_SUB+=	LUAJIT="@comment "
.else
PLIST_SUB+=	LUAJIT=""
.endif

post-install:
	# https://github.com/obsproject/obs-studio/issues/2625
	${INSTALL_DATA} ${WRKSRC}/UI/obs-frontend-api/obs-frontend-api.h ${STAGEDIR}${PREFIX}/include/obs
	# https://github.com/obsproject/obs-studio/issues/2647 (only for multimedia/obs-audio-spectralizer, should be removed later)
	${INSTALL_DATA} ${WRKSRC}/cmake/Modules/ObsHelpers.cmake ${STAGEDIR}${PREFIX}/lib/cmake
#	${INSTALL_DATA} ${WRKSRC}/cmake/external/ObsPluginHelpers.cmake ${STAGEDIR}${PREFIX}/lib/cmake

.include <bsd.port.post.mk>
