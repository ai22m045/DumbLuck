#pragma once

#include "Core.h"
#include "Events/Event.h"
#include "DumbLuck/Events/ApplicationEvent.h"
#include "Window.h"

namespace DumbLuck 
{
	class DUMBLUCK_API App
	{
	public:
		App();
		virtual ~App();

		void Run();

		void OnEvent(Event& e);
	private:
		bool OnWindowClose(WindowCloseEvent& e);
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
	};

	//To be defined in CLIENT
	App* CreateApp();
}

