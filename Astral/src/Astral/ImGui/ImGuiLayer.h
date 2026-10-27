#pragma once

#include "Astral/Core/Layer.h"

#include "Astral/Events/ApplicationEvent.h"
#include "Astral/Events/KeyEvent.h"
#include "Astral/Events/MouseEvent.h"

namespace Astral {

	class ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer() = default;

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnEvent(Event& e) override;

		void Begin();
		void End();

		void BlockEvents(bool block) { m_BlockEvents = block; }
		
		void SetDarkThemeColors();
	private:
		bool m_BlockEvents = true;
	};

}
