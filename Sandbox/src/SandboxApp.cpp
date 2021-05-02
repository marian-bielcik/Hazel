#include <Hazel.h>
#include <Hazel/Core/EntryPoint.h>

#include <imgui/imgui.h>

#include <glm/gtc/matrix_transform.hpp>

#include <glm/gtc/type_ptr.hpp>

#include "Sandbox2D.h"
#include "ExampleLayer.h"

namespace Hazel {
	class Sandbox : public Application
	{
	public:
		Sandbox(ApplicationCommandLineArgs args)
			: Application("Sandbox", args)
		{
			// PushLayer(new ExampleLayer());
			PushLayer(new Sandbox2D());
		}

		~Sandbox()
		{
		}
	};

	Application* CreateApplication(ApplicationCommandLineArgs args)
	{
		return new Sandbox(args);
	}
}
