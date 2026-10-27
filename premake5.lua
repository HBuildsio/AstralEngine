include "./vendor/premake/premake_customization/solution_items.lua"
include "Dependencies.lua"

workspace "AstralEngine"
	architecture "x86_64"
	startproject "AstralCore"
	toolset "v145"
	defaultplatform "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

	solution_items
	{
		".editorconfig"
	}

	flags
	{
		"MultiProcessorCompile"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

group "Dependencies"
	include "vendor/premake"
	include "Astral/vendor/Box2D"
	include "Astral/vendor/GLFW"
	include "Astral/vendor/Glad"
	include "Astral/vendor/imgui"
	include "Astral/vendor/yaml-cpp"
group ""

group "Core"
	include "Astral"
	include "Astral-ScriptCore"
group ""

group "Tools"
	include "AstralCore"
group ""

group "Misc"
	include "Sandbox"
group ""
