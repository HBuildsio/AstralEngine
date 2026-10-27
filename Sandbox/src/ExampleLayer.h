#pragma once

#include "Astral.h"

class ExampleLayer : public Astral::Layer
{
public:
	ExampleLayer();
	virtual ~ExampleLayer() = default;

	virtual void OnAttach() override;
	virtual void OnDetach() override;

	void OnUpdate(Astral::Timestep ts) override;
	virtual void OnImGuiRender() override;
	void OnEvent(Astral::Event& e) override;
private:
	Astral::ShaderLibrary m_ShaderLibrary;
	Astral::Ref<Astral::Shader> m_Shader;
	Astral::Ref<Astral::VertexArray> m_VertexArray;

	Astral::Ref<Astral::Shader> m_FlatColorShader;
	Astral::Ref<Astral::VertexArray> m_SquareVA;

	Astral::Ref<Astral::Texture2D> m_Texture, m_ChernoLogoTexture;

	Astral::OrthographicCameraController m_CameraController;
	glm::vec3 m_SquareColor = { 0.2f, 0.3f, 0.8f };
};

