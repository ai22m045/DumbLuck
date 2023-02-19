#pragma once

#ifdef DL_PLATFORM_WINDOWS

extern DumbLuck::App* DumbLuck::CreateApp();

int main(int argc, char** argv)
{
	printf("DumbLuck Engine\n");
	auto app = DumbLuck::CreateApp();
	app->Run();
	delete app;
}

#endif // HZ_PLATFORM_WINDOWS