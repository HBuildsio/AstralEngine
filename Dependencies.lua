
-- Astral Dependencies

VULKAN_SDK = os.getenv("VULKAN_SDK")

IncludeDir = {}
IncludeDir["stb_image"] = "%{wks.location}/Astral/vendor/stb_image"
IncludeDir["yaml_cpp"] = "%{wks.location}/Astral/vendor/yaml-cpp/include"
IncludeDir["Box2D"] = "%{wks.location}/Astral/vendor/Box2D/include"
IncludeDir["GLFW"] = "%{wks.location}/Astral/vendor/GLFW/include"
IncludeDir["Glad"] = "%{wks.location}/Astral/vendor/Glad/include"
IncludeDir["ImGui"] = "%{wks.location}/Astral/vendor/ImGui"
IncludeDir["ImGuizmo"] = "%{wks.location}/Astral/vendor/ImGuizmo"
IncludeDir["glm"] = "%{wks.location}/Astral/vendor/glm"
IncludeDir["entt"] = "%{wks.location}/Astral/vendor/entt/include"
IncludeDir["mono"] = "%{wks.location}/Astral/vendor/mono/include"
IncludeDir["shaderc"] = "%{wks.location}/Astral/vendor/shaderc/include"
IncludeDir["SPIRV_Cross"] = "%{wks.location}/Astral/vendor/SPIRV-Cross"
IncludeDir["VulkanSDK"] = "%{VULKAN_SDK}/Include"

LibraryDir = {}

LibraryDir["VulkanSDK"] = "%{VULKAN_SDK}/Lib"
LibraryDir["mono"] = "%{wks.location}/Astral/vendor/mono/lib/%{cfg.buildcfg}"

Library = {}
Library["mono_Debug"] = "%{wks.location}/Astral/vendor/mono/lib/Debug/libmono-static-sgen.lib"
Library["mono_Release"] = "%{wks.location}/Astral/vendor/mono/lib/Release/libmono-static-sgen.lib"

Library["Vulkan"] = "%{LibraryDir.VulkanSDK}/vulkan-1.lib"
Library["VulkanUtils"] = "%{LibraryDir.VulkanSDK}/VkLayer_utils.lib"

Library["ShaderC_Debug"] = "%{LibraryDir.VulkanSDK}/shaderc_sharedd.lib"
Library["SPIRV_Cross_Debug"] = "%{LibraryDir.VulkanSDK}/spirv-cross-cored.lib"
Library["SPIRV_Cross_GLSL_Debug"] = "%{LibraryDir.VulkanSDK}/spirv-cross-glsld.lib"
Library["SPIRV_Tools_Debug"] = "%{LibraryDir.VulkanSDK}/SPIRV-Toolsd.lib"

Library["ShaderC_Release"] = "%{LibraryDir.VulkanSDK}/shaderc_shared.lib"
Library["SPIRV_Cross_Release"] = "%{LibraryDir.VulkanSDK}/spirv-cross-core.lib"
Library["SPIRV_Cross_GLSL_Release"] = "%{LibraryDir.VulkanSDK}/spirv-cross-glsl.lib"

-- Windows
Library["WinSock"] = "Ws2_32.lib"
Library["WinMM"] = "Winmm.lib"
Library["WinVersion"] = "Version.lib"
Library["BCrypt"] = "Bcrypt.lib"
