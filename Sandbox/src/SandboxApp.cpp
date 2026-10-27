#include <Astral.h>
#include <Astral/Core/EntryPoint.h>

#include "Sandbox2D.h"
#include "ExampleLayer.h"

class Sandbox : public Astral::Application
{
public:
	Sandbox(const Astral::ApplicationSpecification& specification)
		: Astral::Application(specification)
	{
		// PushLayer(new ExampleLayer());
		PushLayer(new Sandbox2D());
	}

	~Sandbox()
	{
	}
};

Astral::Application* Astral::CreateApplication(Astral::ApplicationCommandLineArgs args)
{
	ApplicationSpecification spec;
	spec.Name = "Sandbox";
	spec.WorkingDirectory = "../AstralCore";
	spec.CommandLineArgs = args;

	return new Sandbox(spec);
}
