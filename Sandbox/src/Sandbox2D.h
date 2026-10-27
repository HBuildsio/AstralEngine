#pragma once

#include "Astral.h"

class Sandbox2D : public Astral::Layer
{
public:
	Sandbox2D();
	virtual ~Sandbox2D() = default;

	virtual void OnAttach() override;
	virtual void OnDetach() override;

	void OnUpdate(Astral::Timestep ts) override;
	virtual void OnImGuiRender() override;
	void OnEvent(Astral::Event& e) override;
private:
	Astral::OrthographicCameraController m_CameraController;
	
	// Temp
	Astral::Ref<Astral::VertexArray> m_SquareVA;
	Astral::Ref<Astral::Shader> m_FlatColorShader;

	Astral::Ref<Astral::Texture2D> m_CheckerboardTexture;

	glm::vec4 m_SquareColor = { 0.2f, 0.3f, 0.8f, 1.0f };
};
