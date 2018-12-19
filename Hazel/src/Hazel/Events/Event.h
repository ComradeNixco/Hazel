#pragma once

#include "hzpch.h"
#include "Hazel/Core.h"


namespace Hazel {
	enum class EventType {
		None = 0,
		WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
		AppTick, AppUpdate, AppRender,
		KeyPressed, KeyReleased,
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
	};

	enum EventCategory {
		EC_NONE			= 0,
		EC_APPLICATION	= BIT(0),
		EC_INPUT		= BIT(1),
		EC_KEYBOARD		= BIT(2),
		EC_MOUSE		= BIT(3),
		EC_MOUSEBUTTON	= BIT(4)
	};

	#define EVENT_CLASS_TYPE(type) static EventType GetStaticType() { return EventType::##type; }\
								   virtual EventType GetEventType() const override { return GetStaticType(); }\
								   virtual const char* GetName() const override { return #type; }
	#define EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags() const override { return category; }

	class HAZEL_API Event {
		friend class EventDispatcher;

	public:
		virtual EventType GetEventType() const = 0;
		virtual const char* GetName() const = 0;
		virtual int GetCategoryFlags() const = 0;
		virtual std::string ToString() const { return GetName(); }

		inline bool IsInCategory(EventCategory category) { return GetCategoryFlags() & category; }

	protected:
		bool m_handled = false;
	};

	class HAZEL_API EventDispatcher {
		template<typename T, typename = std::enable_if<std::is_base_of<Event, T>::value>>
		using EventFn = std::function<bool(T&)>;

	public:
		EventDispatcher(Event& event)
			: m_event(event) {};

		template<typename T, typename = std::enable_if<std::is_base_of<Event, T>::value>>
		bool Dispatch(EventFn<T> func) {
			if (m_event.GetEventType() == T::GetStaticType()) {
				m_event.m_handled = func(*(T*)&m_event);
				return true;
			}

			return false;
		}

	private:
		Event& m_event;
	};

	inline std::ostream& operator<<(std::ostream& os, const Event& e) {
		return os << e.ToString();
	}
}
