#pragma once

#include "Astral/Core/KeyCodes.h"
#include "Astral/Core/MouseCodes.h"

#include <glm/glm.hpp>

namespace Astral {

	class Input
	{
	public:
		static bool IsKeyPressed(KeyCode key);

		static bool IsMouseButtonPressed(MouseCode button);
		static glm::vec2 GetMousePosition();
		static float GetMouseX();
		static float GetMouseY();
	};
}
