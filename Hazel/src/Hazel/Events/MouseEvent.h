#pragma once

#include "Event.h"


namespace Hazel {
	class HAZEL_API MouseMovedEvent : public Event {
	public:
		MouseMovedEvent(float x, float y)
			: m_mouseX(x), m_mouseY(y) {}

		inline float GetX() const { return m_mouseX; }
		inline float GetY() const { return m_mouseY; }

		std::string ToString() const override {
			std::stringstream ss;
			ss << "MouseMovedEvent: " << m_mouseX << ", " << m_mouseY;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseMoved)
		EVENT_CLASS_CATEGORY(EC_MOUSE | EC_INPUT)
	private:
		float m_mouseX, m_mouseY;
	};

	class HAZEL_API MouseScrolledEvent : public Event {
	public:
		MouseScrolledEvent(float xOffset, float yOffset)
			: m_xOffset(xOffset), m_yOffset(yOffset) {}

		inline float GetXOffset() const { return m_xOffset; }
		inline float GetYOffset() const { return m_yOffset; }

		std::string ToString() const override {
			std::stringstream ss;
			ss << "MouseScrolledEvent: " << m_xOffset << ", " << m_yOffset;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseScrolled)
		EVENT_CLASS_CATEGORY(EC_MOUSE | EC_INPUT)
	private:
		float m_xOffset, m_yOffset;
	};

	class HAZEL_API MouseButtonEvent : public Event {
	public:
		inline int GetMouseButton() const { return m_button; }
		std::string ToString() const override {
			std::stringstream ss;
			ss << GetName() << "Event: "<< m_button;
			return ss.str();
		}

		EVENT_CLASS_CATEGORY(EC_MOUSE | EC_INPUT)
	protected:
		MouseButtonEvent(int button)
			: m_button(button) {}

		int m_button;
	};

	class HAZEL_API MouseButtonPressedEvent : public MouseButtonEvent {
	public:
		MouseButtonPressedEvent(int button) 
			: MouseButtonEvent(button) {}

		EVENT_CLASS_TYPE(MouseButtonPressed)
	};

	class HAZEL_API MouseButtonReleasedEvent : public MouseButtonEvent {
	public:
		MouseButtonReleasedEvent(int button)
			: MouseButtonEvent(button) {}
		
		EVENT_CLASS_TYPE(MouseButtonReleased)
	};
}
