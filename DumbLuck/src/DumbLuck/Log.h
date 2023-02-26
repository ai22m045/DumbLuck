#pragma once

#include <memory>
#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/fmt/ostr.h"

namespace DumbLuck {

	class DUMBLUCK_API Log
	{
	public:
		static void Init();
		
		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_CoreLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;

	};

}

// Core log macros
#define DL_CORE_ERROR(...)	::DumbLuck::Log::GetCoreLogger()->error(__VA_ARGS__)
#define DL_CORE_WARN(...)	::DumbLuck::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define DL_CORE_INFO(...)	::DumbLuck::Log::GetCoreLogger()->info(__VA_ARGS__)
#define DL_CORE_TRACE(...)	::DumbLuck::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define DL_CORE_FATAL(...)	::DumbLuck::Log::GetCoreLogger()->critical(__VA_ARGS__)

// Client log macros
#define DL_ERROR(...)	::DumbLuck::Log::GetClientLogger()->error(__VA_ARGS__)
#define DL_WARN(...)	::DumbLuck::Log::GetClientLogger()->warn(__VA_ARGS__)
#define DL_INFO(...)	::DumbLuck::Log::GetClientLogger()->info(__VA_ARGS__)
#define DL_TRACE(...)	::DumbLuck::Log::GetClientLogger()->trace(__VA_ARGS__)
#define DL_FATAL(...)	::DumbLuck::Log::GetClientLogger()->critical(__VA_ARGS__)
