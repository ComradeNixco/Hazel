#include "hzpch.h"
#include "Application.h"

#include <GLFW/glfw3.h>

#include "Hazel/Log.h"
#include "Hazel/Events/ApplicationEvent.h"
#include "Hazel/Events/MouseEvent.h"


namespace Hazel {
	Application::~Application() = default;

	Application::Application() {
		m_window = std::unique_ptr<Window>(Window::Create());
	}

	void Application::Run() {
		while (m_isRunning) {
			glClearColor(1, 1, 0, 1);
			glClear(GL_COLOR_BUFFER_BIT);
			m_window->OnUpdate();
		}
	}
}
