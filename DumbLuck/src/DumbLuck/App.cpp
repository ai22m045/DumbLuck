#include "App.h"

#include "DumbLuck/Events/ApplicationEvent.h"
#include "DumbLuck/Log.h"

namespace DumbLuck {

	App::App()
	{

	}


	App::~App()
	{

	}

	void App::Run()
	{
		WindowResizeEvent e(1200, 720);
		if (e.IsInCategory(EventCategoryApplication)) {
			DL_TRACE(e.ToString());
		}
		if (e.IsInCategory(EventCategoryInput)) {
			DL_TRACE(e.ToString());
		}
		while (true);
	}
}