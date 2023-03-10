workspace "DumbLuck"
	architecture "x64"
	
	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "DumbLuck/vendor/GLFW/include"

include "DumbLuck/vendor/GLFW"


project "DumbLuck"
	location "DumbLuck"
	kind "SharedLib"
	language "C++"
	
	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
	
	pchheader "dlpch.h"
	pchsource "DumbLuck/src/dlpch.cpp"
	
	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}
	
	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}"
	}

	links
	{
		"GLFW",
		"opengl32.lib"
	}
	
	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"
		
		defines
		{
			"DL_PLATFORM_WINDOWS",
			"DL_BUILD_DLL"
		}
		
		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/WhereIsGravity" )
		}
		
	filter "configurations:Debug"
		defines "DL_DEBUG"
		symbols "On"
		
	filter "configurations:Release"
		defines "DL_RELEASE"
		optimize "On"
		
	filter "configurations:Dist"
		defines "DL_DIST"
		optimize "On"		
		
		
		
project "WhereIsGravity"
	location "WhereIsGravity"
	kind "ConsoleApp"
	language "C++"
	
	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
	
	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}
	
	includedirs
	{
		"DumbLuck/vendor/spdlog/include",
		"DumbLuck/src"
	}
	
	links
	{
		"DumbLuck"
	}
	
	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"
		
		defines
		{
			"DL_PLATFORM_WINDOWS"
		}
		
	filter "configurations:Debug"
		defines "DL_DEBUG"
		symbols "On"
		
	filter "configurations:Release"
		defines "DL_RELEASE"
		optimize "On"
		
	filter "configurations:Dist"
		defines "DL_DIST"
		optimize "On"		
	