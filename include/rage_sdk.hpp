#pragma once

#include <cstdint>
#include <cstring>
#include <string>
#include <vector>
#include <map>

#include <functional>

#include <locale>
#include <codecvt>

#include "types.hpp"

#include "handlers/IEntityHandler.hpp"
#include "handlers/IPlayerHandler.hpp"
#include "handlers/IVehicleHandler.hpp"
#include "handlers/IColshapeHandler.hpp"
#include "handlers/ICheckpointHandler.hpp"
#include "handlers/IBlipHandler.hpp"
#include "handlers/ITickHandler.hpp"
#include "handlers/ILocalEventHandler.hpp"
#include "handlers/IConnectionHandler.hpp"

#ifdef _WIN32
#define EXTERN extern "C" __declspec(dllexport) 
#else
#define EXTERN extern "C"
#endif

namespace rage
{
	//rage::IEntityHandler, rage::IPlayerHandler, rage::IVehicleHandler, rage::IColshapeHandler, rage::ICheckpointHandler, rage::IBlipHandler,
	// rage::ITickHandler, rage::IServerHandler, rage::ILocalEventHandler, rage::IConnectionHandler, rage::IRpcHandler;
	class IEventHandler
	{
	public:
		virtual IEntityHandler* GetEntityHandler() { return nullptr; } // 0x0
		virtual IPlayerHandler* GetPlayerHandler() { return nullptr; } // 0x8
		virtual IVehicleHandler* GetVehicleHandler() { return nullptr; } // 0x10
		virtual IColshapeHandler* GetColshapeHandler() { return nullptr; } // 0x18
		virtual ICheckpointHandler* GetCheckpointHandler() { return nullptr; } // 0x20
		virtual IBlipHandler* GetBlipHandler() { return nullptr; } // 0x28
		virtual __int64* padding_01() { return nullptr; } // 0x30
		virtual ITickHandler* GetTickHandler() { return nullptr; } // 0x38
		virtual ILocalEventHandler* GetLocalEventHandler() { return nullptr; } // 0x40
		virtual IConnectionHandler* GetConnectionHandler() { return nullptr; } // 0x48
		virtual __int64* GetDebugHandler() { return nullptr; } // 0x50 
		virtual __int64* GetServerHandler() { return nullptr; } // 0x58

		virtual __int64 GetRPCHandler() { return 1; } // 0x60
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