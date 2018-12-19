#pragma once

#include "Event.h"


namespace Hazel {
	class HAZEL_API KeyEvent : public Event {
	public:
		inline int GetKeyCode() const { return m_keyCode; }

		EVENT_CLASS_CATEGORY(EC_KEYBOARD | EC_INPUT)
		
	protected:
		KeyEvent(int keyCode)
			: m_keyCode(keyCode) {}

		int m_keyCode;
	};

	class HAZEL_API KeyPressedEvent : public KeyEvent {
	public:
		KeyPressedEvent(int keyCode, int repeatCount)
			: KeyEvent(keyCode), m_repeatCount(repeatCount) {}

		inline int GetRepeatCount() const { return m_repeatCount; }

		std::string ToString() const override {
			std::stringstream ss;
			ss << "KeyPressedEvent: " << m_keyCode << " (" << m_repeatCount << " repeats)";
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyPressed)

	private:
		int m_repeatCount;
	};

	class HAZEL_API KeyReleasedEvent : public KeyEvent {
	public:
		KeyReleasedEvent(int keyCode)
			: KeyEvent(keyCode) {}

		std::string ToString() {
			std::stringstream ss;
			ss << "KeyReleasedEvent: " << m_keyCode;
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyReleased)
	};
}
