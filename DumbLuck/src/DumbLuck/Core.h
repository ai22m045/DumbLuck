#pragma once

#ifdef DL_PLATFORM_WINDOWS
	#ifdef DL_BUILD_DLL
		#define DUMBLUCK_API __declspec(dllexport)
	#else
		#define DUMBLUCK_API __declspec(dllimport)
	#endif // HZ_BUILD_DLL

#else
	#error DumbLuck only supports Windows!
#endif // HZ_PLATFORM_WINDOWS

#ifdef DL_ENABLE_ASSERTS
	#define DL_ASSERT(x, ...) { if(!(x)) { DL_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak();}}
	#define DL_CORE_ASSERT(x, ...) {if(!(x)) { DL_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak();}}
#else
	#define DL_ASSERT(x, ...)
	#define DL_CORE_ASSERT(x, ...)
#endif



#define BIT(x) (1 << x)