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
	public rage::ITickHandler
{
public:
	virtual rage::ITickHandler* GetTickHandler() override { return this; }

	virtual void Tick() override {
		rage::Log::Debug("ITickHandler", ">>", "Tick");
	}
};

EXTERN void InitializePlugin(rage::IMultiplayer* _mp)
{
	rage::IMultiplayer::SetInstance(_mp);
	rage::Log::Push(new rage::Log::ConsoleStream);

	rage::Log::Done("Initialized plugin.", ">>", GetPluginName());

	rage::IMultiplayer::Instance().SetEventHandler(new ExampleEventHandler);
}