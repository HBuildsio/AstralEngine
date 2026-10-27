#pragma once
#include "Astral/Core/Base.h"
#include "Astral/Core/Application.h"

#ifdef HZ_PLATFORM_WINDOWS

extern Astral::Application* Astral::CreateApplication(ApplicationCommandLineArgs args);

int main(int argc, char** argv)
{
	Astral::Log::Init();

	HZ_PROFILE_BEGIN_SESSION("Startup", "AstralProfile-Startup.json");
	auto app = Astral::CreateApplication({ argc, argv });
	HZ_PROFILE_END_SESSION();

	HZ_PROFILE_BEGIN_SESSION("Runtime", "AstralProfile-Runtime.json");
	app->Run();
	HZ_PROFILE_END_SESSION();

	HZ_PROFILE_BEGIN_SESSION("Shutdown", "AstralProfile-Shutdown.json");
	delete app;
	HZ_PROFILE_END_SESSION();
}

#endif
