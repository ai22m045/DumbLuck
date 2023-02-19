#pragma once

#include "Core.h"

namespace DumbLuck 
{
	class DUMBLUCK_API App
	{
	public:
		App();
		virtual ~App();

		void Run();
	};

	//To be defined in CLIENT
	App* CreateApp();
}

