/*
Mist is a game engine by Alex Sabourin

Pupose: defines macros based on the compiler this code is being compiled on

Date: 2016/03/01
*/

#ifdef _MSC_VER

#define MIST_VISUAL_STUDIO

#elif defined(__clang__)

#define MIST_CLANG

#elif defined(__GNUC__)

#define MIST_GCC

#elif defined(__INTEL_COMPILER)

#define MIST_INTEL_COMPILER

#elif



#endif