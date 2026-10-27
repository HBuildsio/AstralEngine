#include "hzpch.h"
#include "Astral/Renderer/RenderCommand.h"

namespace Astral {

	Scope<RendererAPI> RenderCommand::s_RendererAPI = RendererAPI::Create();

}