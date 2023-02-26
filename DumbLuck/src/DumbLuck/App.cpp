#include "dlpch.h"
#include "App.h"

#include "DumbLuck/Log.h"

namespace DumbLuck {

#define BIND_EVENT_FN(x) std::bind(&x, this, std::placeholders::_1)

	App::App()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(BIND_EVENT_FN(App::OnEvent));
	}


	App::~App()
	{

	}

	void App::OnEvent(Event& e) 
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(App::OnWindowClose));

		DL_CORE_TRACE(e.ToString());
	}

	void App::Run()
	{
		while (m_Running) 
		{
			m_Window->OnUpdate();
		}
	}

	bool App::OnWindowClose(WindowCloseEvent& e)
	{
		m_Running = false;
		return true;
	}

}