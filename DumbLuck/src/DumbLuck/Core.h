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


#define BIT(x) (1 << x)