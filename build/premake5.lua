local ROOT = "../"

workspace "Raytracer"
	configurations {"Debug", "Release"}
	platforms {"x32", "x64"}
	
	local project_action = "UNDEFINED"
	if _ACTION ~= nill then project_action = _ACTION end
	
	flags "FatalWarnings"
	
	output = "%{cfg.platform}/%{cfg.buildcfg}"

	targetdir (ROOT .. "bin/" .. output .. "/%{prj.name}")
	objdir (ROOT .. "bin/int/" .. output .. "/%{prj.name}")
	
	location (ROOT)
	
	filter "configurations:Debug"    defines { "DEBUG" }  symbols  "On"
	filter "configurations:Release"  defines { "NDEBUG" } optimize "On"
	
	
	filter { "system:windows", "action:vs*"}
		flags         { "MultiProcessorCompile", "NoMinimalRebuild" }
		linkoptions   { "/ignore:4099" }
		
	filter { "system:macosx", "action:gmake"}
		toolset "clang"
	
	filter {}
	
	project "Raytracer"
		kind "ConsoleApp"
		
		language "C++"
		cppdialect "C++17"
		
		SourceDir = ROOT .. "src/"
		IncludeDir = ROOT .. "include/"
		
		files
		{
			SourceDir .. "**.c", SourceDir .. "**.cpp",
			IncludeDir .. "**.h", IncludeDir .. "**.hpp"
		}
		
		vpaths 
		{
			["Header Files/*"] = { IncludeDir .. "**.h", IncludeDir .. "**.hpp" },
			["Source Files/*"] = { SourceDir .. "**.c", SourceDir .. "**.cpp" },
		}
		
		includedirs
		{
			IncludeDir
		}