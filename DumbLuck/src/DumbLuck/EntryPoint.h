#pragma once

#ifdef DL_PLATFORM_WINDOWS

extern DumbLuck::App* DumbLuck::CreateApp();

int main(int argc, char** argv)
{
	DumbLuck::Log::Init();
	DL_CORE_WARN("Initialized Log!");
	DL_INFO("Initialized Log!");



	auto app = DumbLuck::CreateApp();
	app->Run();
	delete app;
}

#endif // HZ_PLATFORM_WINDOWS