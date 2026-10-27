#include "hzpch.h"
#include "Platform/OpenGL/OpenGLRendererAPI.h"

#include <glad/glad.h>

namespace Astral {
	
	void OpenGLMessageCallback(
		unsigned source,
		unsigned type,
		unsigned id,
		unsigned severity,
		int length,
		const char* message,
		const void* userParam)
	{
		switch (severity)
		{
			case GL_DEBUG_SEVERITY_HIGH:         HZ_CORE_CRITICAL(message); return;
			case GL_DEBUG_SEVERITY_MEDIUM:       HZ_CORE_ERROR(message); return;
			case GL_DEBUG_SEVERITY_LOW:          HZ_CORE_WARN(message); return;
			case GL_DEBUG_SEVERITY_NOTIFICATION: HZ_CORE_TRACE(message); return;
		}
		
		HZ_CORE_ASSERT(false, "Unknown severity level!");
	}

	void OpenGLRendererAPI::Init()
	{
		HZ_PROFILE_FUNCTION();

	#ifdef HZ_DEBUG
		glEnable(GL_DEBUG_OUTPUT);
		glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);
		glDebugMessageCallback(OpenGLMessageCallback, nullptr);
		
		glDebugMessageControl(GL_DONT_CARE, GL_DONT_CARE, GL_DEBUG_SEVERITY_NOTIFICATION, 0, NULL, GL_FALSE);
	#endif

		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

		glEnable(GL_DEPTH_TEST);
		glEnable(GL_LINE_SMOOTH);
	}

	void OpenGLRendererAPI::SetViewport(uint32_t x, uint32_t y, uint32_t width, uint32_t height)
	{
		glViewport(x, y, width, height);
	}

	void OpenGLRendererAPI::SetClearColor(const glm::vec4& color)
	{
		glClearColor(color.r, color.g, color.b, color.a);
	}

	void OpenGLRendererAPI::Clear()
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

	void OpenGLRendererAPI::DrawIndexed(
		const Ref<VertexArray>& vertexArray,
		uint32_t indexCount)
	{
		if (!vertexArray)
		{
			std::cerr << "[DrawIndexed] Null VertexArray\n";
			return;
		}

		const auto& indexBuffer = vertexArray->GetIndexBuffer();
		if (!indexBuffer)
		{
			std::cerr << "[DrawIndexed] Null IndexBuffer\n";
			return;
		}

		const uint32_t bufferCount = indexBuffer->GetCount();
		const uint32_t count = indexCount ? indexCount : bufferCount;

		if (count == 0)
			return;

		if (count > bufferCount)
		{
			std::cerr << "[DrawIndexed] Index count exceeds buffer count: "
				<< count << " > " << bufferCount << '\n';
			return;
		}

		vertexArray->Bind();

		GLint boundVAO = 0;
		GLint boundEBO = 0;

		glGetIntegerv(GL_VERTEX_ARRAY_BINDING, &boundVAO);
		glGetIntegerv(GL_ELEMENT_ARRAY_BUFFER_BINDING, &boundEBO);

		std::cerr << "[DrawIndexed] VAO=" << boundVAO
			<< ", EBO=" << boundEBO
			<< ", count=" << count << '\n';

		while (glGetError() != GL_NO_ERROR) {}

		glDrawElements(GL_TRIANGLES, count, GL_UNSIGNED_INT, nullptr);

		GLenum error = glGetError();
		if (error != GL_NO_ERROR)
		{
			std::cerr << "[DrawIndexed] OpenGL error: 0x"
				<< std::hex << error << std::dec << '\n';
		}
	}

	void OpenGLRendererAPI::DrawLines(
		const Ref<VertexArray>& vertexArray,
		uint32_t vertexCount)
	{
		if (!vertexArray || vertexCount == 0)
			return;

		vertexArray->Bind();

		GLint vao = 0;
		GLint vbo = 0;

		glGetIntegerv(GL_VERTEX_ARRAY_BINDING, &vao);
		glGetIntegerv(GL_ARRAY_BUFFER_BINDING, &vbo);

		std::cout << "DrawLines: VAO=" << vao
			<< ", GL_ARRAY_BUFFER=" << vbo
			<< ", vertexCount=" << vertexCount << '\n';

		glDrawArrays(GL_LINES, 0, static_cast<GLsizei>(vertexCount));
	}

	void OpenGLRendererAPI::SetLineWidth(float width)
	{
		glLineWidth(width);
	}

}
