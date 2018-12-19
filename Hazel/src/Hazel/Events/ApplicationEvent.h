#pragma once

#include "Event.h"
#include "Hazel/Core.h"


namespace Hazel {
	class HAZEL_API WindowResizeEvent : public Event {
	public:
		WindowResizeEvent(uint width, uint height)
			: m_width(width), m_height(height) {}

		inline uint GetWidth() const { return m_width; }
		inline uint GetHeight() const { return m_height; }

		std::string ToString() const override {
			std::stringstream ss;
			ss << "WindowResizeEvent: " << m_width << ", " << m_height;
			return ss.str();
		}

		EVENT_CLASS_TYPE(WindowResize)
		EVENT_CLASS_CATEGORY(EC_APPLICATION)
	private:
		uint m_width, m_height;
	};

	class HAZEL_API WindowCloseEvent : public Event {
		WindowCloseEvent() = default;

		EVENT_CLASS_TYPE(WindowClose)
		EVENT_CLASS_CATEGORY(EC_APPLICATION)
	};

	class HAZEL_API AppTickEvent : public Event {
	public:
		AppTickEvent() {}

		EVENT_CLASS_TYPE(AppTick)
		EVENT_CLASS_CATEGORY(EC_APPLICATION)
	};

	class HAZEL_API AppUpdateEvent : public Event {
	public:
		AppUpdateEvent() {}

		EVENT_CLASS_TYPE(AppUpdate)
		EVENT_CLASS_CATEGORY(EC_APPLICATION)
	};

	class HAZEL_API AppRenderEvent : public Event {
	public:
		AppRenderEvent() {}

		EVENT_CLASS_TYPE(AppRender)
		EVENT_CLASS_CATEGORY(EC_APPLICATION)
	};
}