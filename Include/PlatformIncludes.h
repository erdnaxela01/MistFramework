#ifndef MIST_PLATFORM_INCLUDES_H
#define MIST_PLATFORM_INCLUDES_H

/*
Mist is a game engine by Alex Sabourin

Pupose: This header will include platform specific header files

Date: 2016/03/01
*/

#include "PlatformDefines.h"

#if defined(MIST_WINDOWS)

#include <Windows.h>

#elif defined(MIST_LINUX)

#include <unistd.h>
#include <ftw.h>

#endif //MIST_WINDOWS

#endif //PLATFORM_INCLUDES_H