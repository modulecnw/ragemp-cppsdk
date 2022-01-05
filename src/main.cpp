#include <iostream>
#include <Windows.h>

#include "rage_sdk.hpp"
#include "rage_log.hpp"

EXTERN uint32_t GetPluginVersion()
{
	return rage::IMultiplayer::SDK_VERSION;
}

EXTERN const char* GetPluginName()
{
	return "rage:MP SDK";
}

class ExampleEventHandler : public rage::IEventHandler,
	public rage::IEntityHandler {
public:
	virtual rage::IEntityHandler* GetEntityHandler() override { return this; }

	virtual void on_entity_created(__int64* entity_ptr) override { 
		rage::Log::Debug("IEntityHandler", ">>", "Created");
	}

	virtual void on_entity_destroyed(__int64* entity_ptr) override {
		rage::Log::Debug("IEntityHandler", ">>", "Destroyed");
	}
};

EXTERN void InitializePlugin(rage::IMultiplayer* _mp)
{
	rage::IMultiplayer::SetInstance(_mp);
	rage::Log::Push(new rage::Log::ConsoleStream);

	rage::Log::Done("Initialized plugin.", ">>", GetPluginName());

	rage::IMultiplayer::Instance().SetEventHandler(new ExampleEventHandler);
}