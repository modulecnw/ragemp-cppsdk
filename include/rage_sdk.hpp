#pragma once

#include <cstdint>
#include <cstring>
#include <string>
#include <vector>
#include <map>

#include <functional>

#include <locale>
#include <codecvt>

#include "handlers/IEntityHandler.hpp"
#include "handlers/IPlayerHandler.hpp"
#include "handlers/ITickHandler.hpp"

#ifdef _WIN32
#define EXTERN extern "C" __declspec(dllexport) 
#else
#define EXTERN extern "C"
#endif

namespace rage
{
	class ICustomHandler
	{
	public:

	};

	class IRPCHandler
	{
	public:

	};

	//rage::IEntityHandler, rage::IPlayerHandler, rage::IVehicleHandler, rage::IColshapeHandler, rage::ICheckpointHandler, rage::IBlipHandler,
	// rage::ITickHandler, rage::IServerHandler, rage::ILocalEventHandler, rage::IConnectionHandler, rage::IRpcHandler;
	class IEventHandler
	{
	public:
		virtual IEntityHandler* GetEntityHandler() { return nullptr; } // 0x0
		virtual ICustomHandler* GetPlayerHandler() { return nullptr; } // 0x8
		virtual ICustomHandler* GetVehicleHandler() { return nullptr; } // 0x10
		virtual ICustomHandler* GetColshapeHandler() { return nullptr; } // 0x18
		virtual ICustomHandler* GetCheckpointHandler() { return nullptr; } // 0x20
		virtual ICustomHandler* GetBlipHandler() { return nullptr; } // 0x28
		virtual ICustomHandler* padding_01() { return nullptr; } // 0x30
		virtual ITickHandler* GetTickHandler() { return nullptr; } // 0x38
		virtual ICustomHandler* GetLocalEventHandler() { return nullptr; } // 0x40
		virtual ICustomHandler* GetConnectionHandler() { return nullptr; } // 0x48
		virtual ICustomHandler* GetDebugHandler() { return nullptr; } // 0x50 
		virtual ICustomHandler* GetServerHandler() { return nullptr; } // 0x58
		virtual IRPCHandler* GetRPCHandler() { return new IRPCHandler; } // 0x60 <- must not be nullptr
	};

	class IMultiplayer
	{
	public:
		static constexpr uint32_t SDK_VERSION = 6;

		virtual void SetEventHandler(IEventHandler* event_handler) = 0;

		static IMultiplayer& Instance()
		{
			return *_instance();
		}
		static void SetInstance(IMultiplayer* server) { _instance() = server; }

	protected:
		virtual ~IMultiplayer() = default;

	private:
		static IMultiplayer*& _instance()
		{
			static IMultiplayer* instance = nullptr;
			return instance;
		}
	};
}