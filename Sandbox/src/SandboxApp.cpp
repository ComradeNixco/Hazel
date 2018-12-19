#include <Hazel/Application.h>
#include <Hazel/EntryPoint.h>


class SandboxApp : public Hazel::Application
{
private:
	using Super = Hazel::Application;

public:
	SandboxApp() = default;
	~SandboxApp() = default;
};

Hazel::Application* Hazel::CreateApplication()
{
	return new SandboxApp();
}