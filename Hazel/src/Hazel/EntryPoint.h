#pragma once

#include "Application.h"
#include "Log.h"


extern Hazel::Application* Hazel::CreateApplication();

#ifdef HZ_PLATFORM_WINDOWS
int main(int argc, char** argv)
{
	Hazel::Log::Init();
	Hazel::Log::GetCoreLogger()->warn("Initialization done!");
	Hazel::Log::GetClientLogger()->info("WoW");
	HZ_CORE_ERROR("An error");
	HZ_TRACE("A trace");
	auto* app = Hazel::CreateApplication();
	app->Run();
	delete app;
}
#endif // HZ_PLATFORM_WINDOWS

