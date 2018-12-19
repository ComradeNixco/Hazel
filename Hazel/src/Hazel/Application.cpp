#include "hzpch.h"
#include "Application.h"

#include "Hazel/Log.h"
#include "Hazel/Events/ApplicationEvent.h"
#include "Hazel/Events/MouseEvent.h"


namespace Hazel {
	Application::Application() = default;
	Application::~Application() = default;


	void Application::Run() {
		WindowResizeEvent e(1920, 1080);
		MouseButtonPressedEvent e2(2);

		HZ_TRACE(e);
		HZ_WARNING(e2);
		
		while (true);
	}
}
