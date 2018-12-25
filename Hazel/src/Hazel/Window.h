#pragma once

#include "hzpch.h"

#include "Hazel/Core.h"
#include "Hazel/Events/Event.h"


namespace Hazel {
	struct WindowProps {
		std::string title;
		uint width, height;

		WindowProps(const std::string& title = "Hazel Engine",
					uint width = 1280,
					uint height = 720)
			: title(title), width(width), height(height)
		{
		}
	};

	class HAZEL_API Window {
	public:
		using EventCallbackFn = std::function<void(Event&)>;

		virtual ~Window() = default;

		virtual void OnUpdate() = 0;

		virtual uint GetWidth() const = 0;
		virtual uint GetHeight() const = 0;

		// Window attributes
		virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
		virtual void SetVSync(bool enabled) = 0;
		virtual bool IsVSync() const = 0;

		static Window* Create(const WindowProps& = WindowProps());
	};
}
