#ifndef MIST_PLATFORM_DEFINES_H
#define MIST_PLATFORM_DEFINES_H

/*
 Mist is a game engine by Alex Sabourin

 Pupose: This header will define Mist platform specific precompiler macros

 Date: 2016/03/01
*/

#if defined(_WIN32)

#define MIST_WINDOWS

    #ifdef _WIN64

    #define MIST_WINDOWS_64

    #else

    #define MIST_WINDOWS_32

    #endif

#elif defined(__APPLE__)

#define MIST_APPLE

    #ifdef TARGET_OS_IPHONE

    #define MIST_APPLE_IOS

	#elif defined(TARGET_OS_MAC)

    #define __MIST_APPLE_MAC

    #endif


#elif defined(__linux__)

#define MIST_LINUX

#elif defined(__unix__)

#define MIST_UNIX

#else

#define  MIST_UNKNOWN_COMPILER

#endif

#endif //PLATFORM_DEFINES_H