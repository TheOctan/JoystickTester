#pragma once

#ifndef XXX_CONFIG_HPP
#define XXX_CONFIG_HPP

////////////////////////////////////////////////////////////
// Define the XXX version
////////////////////////////////////////////////////////////
#define XXX_VERSION_MAJOR 1
#define XXX_VERSION_MINOR 0
#define XXX_VERSION_PATCH 0

// Windows compilers need specific (and different) keywords for export and import
#define XXX_API_EXPORT __declspec(dllexport)
#define XXX_API_IMPORT __declspec(dllimport)

#if !defined(SFML_STATIC)

	#ifdef _DEBUG

		#define SFML_SYSTEM		"sfml-system-d"
		#define SFML_WINDOW		"sfml-window-d"
		#define SFML_GRAPHICS	"sfml-graphics-d"
		#define SFML_AUDIO		"sfml-audio-d"
		#define SFML_NETWORK	"sfml-network-d"
		#define SFML_MAIN		"sfml-main-d"

	#else

		#define NDEBUG

		#define SFML_SYSTEM		"sfml-system"
		#define SFML_WINDOW		"sfml-window"
		#define SFML_GRAPHICS	"sfml-graphics"
		#define SFML_AUDIO		"sfml-audio"
		#define SFML_NETWORK	"sfml-network"
		#define SFML_MAIN		"sfml-main"
		#define SFML_MAIN		"sfml-main"

	#endif // _DEBUG

#else

	#pragma comment (lib, "opengl32.lib")
	#pragma comment (lib, "winmm.lib")
	#pragma comment (lib, "gdi32.lib")
	#pragma comment (lib, "freetype.lib")
	#pragma comment (lib, "jpeg.lib")

	#pragma comment (lib, "flac.lib")
	#pragma comment (lib, "vorbisenc.lib")
	#pragma comment (lib, "vorbisfile.lib")
	#pragma comment (lib, "vorbis.lib")
	#pragma comment (lib, "ogg.lib")

	#pragma comment (lib, "ws2_32.lib")

	#ifdef _DEBUG

		#define SFML_SYSTEM		"sfml-system-s-d"
		#define SFML_WINDOW		"sfml-window-s-d"
		#define SFML_GRAPHICS	"sfml-graphics-s-d"
		#define SFML_AUDIO		"sfml-audio-s-d"
		#define SFML_NETWORK	"sfml-network-s-d"
		#define SFML_MAIN		"sfml-main-d"

	#else

		#define SFML_SYSTEM		"sfml-system-s"
		#define SFML_WINDOW		"sfml-window-s"
		#define SFML_GRAPHICS	"sfml-graphics-s"
		#define SFML_AUDIO		"sfml-audio-s"
		#define SFML_NETWORK	"sfml-network-s"
		#define SFML_MAIN		"sfml-main"

	#endif // _DEBUG

#endif

#pragma comment (lib, SFML_SYSTEM)
#pragma comment (lib, SFML_WINDOW)
#pragma comment (lib, SFML_GRAPHICS)
#pragma comment (lib, SFML_AUDIO)
#pragma comment (lib, SFML_NETWORK)
#pragma comment (lib, SFML_MAIN)


#endif // !XXX_CONFIG_HPP
