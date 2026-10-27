#pragma once

#include "Astral/Renderer/GraphicsContext.h"

struct GLFWwindow;

namespace Astral {

	class OpenGLContext : public GraphicsContext
	{
	public:
		OpenGLContext(GLFWwindow* windowHandle);

		virtual void Init() override;
		virtual void SwapBuffers() override;
	private:
		GLFWwindow* m_WindowHandle;
	};

}