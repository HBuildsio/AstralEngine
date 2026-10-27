#include <Astral.h>
#include <Astral/Core/EntryPoint.h>

#include "EditorLayer.h"

namespace Astral {

	class AstralCore : public Application
	{
	public:
		AstralCore(const ApplicationSpecification& spec)
			: Application(spec)
		{
			PushLayer(new EditorLayer());
		}
	};

	Application* CreateApplication(ApplicationCommandLineArgs args)
	{
		ApplicationSpecification spec;
		spec.Name = "Astral Engine";
		spec.CommandLineArgs = args;

		if (!std::filesystem::exists("assets/shaders") || !std::filesystem::exists("mono/lib"))
		{
			if (std::filesystem::exists("AstralCore/assets/shaders"))
				spec.WorkingDirectory = "AstralCore";
			else if (std::filesystem::exists("../../../AstralCore/assets/shaders"))
				spec.WorkingDirectory = "../../../AstralCore";
			else if (std::filesystem::exists("../../AstralCore/assets/shaders"))
				spec.WorkingDirectory = "../../AstralCore";
		}

		return new AstralCore(spec);
	}

}
