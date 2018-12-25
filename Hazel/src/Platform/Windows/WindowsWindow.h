#pragma once

#include <GLFW/glfw3.h>

#include "Hazel/Window.h"


namespace Hazel {
	class WindowsWindow : public Window {
	public:
		WindowsWindow(const WindowProps& props);
		virtual ~WindowsWindow();

		void OnUpdate() override;

		inline uint GetWidth() const override { return m_data.width; }
		inline uint GetHeight() const override { return m_data.height; }

		inline void SetEventCallback(const EventCallbackFn& callback) override { m_data.eventCallback = callback; }
		void SetVSync(bool enabled) override;
		bool IsVSync() const override;

	private:
		virtual void Init(const WindowProps& props);
		virtual void Shutdown();

	private:
		struct _WindowData {
			std::string title;
			uint width, height;
			bool vsync;

			EventCallbackFn eventCallback;
		};

		GLFWwindow* m_window;
		_WindowData m_data;
	};

}
