#include <iostream>
#include <Windows.h>

#include "rage_sdk.hpp"
#include "rage_log.hpp"

#include "examples/ExampleEntityEventHandler.hpp"
#include "examples/ExamplePlayerEventHandler.hpp"
#include "examples/ExampleTickEventHandler.hpp"

EXTERN uint32_t GetPluginVersion()
{
	return rage::IMultiplayer::SDK_VERSION;
}

EXTERN const char* GetPluginName()
{
	return "rage:MP SDK";
}

EXTERN void InitializePlugin(rage::IMultiplayer* _mp)
{
	rage::IMultiplayer::SetInstance(_mp);
	rage::Log::Push(new rage::Log::ConsoleStream);

	rage::Log::Done("Initialized plugin.", ">>", GetPluginName());

	rage::IMultiplayer::Instance().SetEventHandler(new ExampleEntityEventHandler);
	rage::IMultiplayer::Instance().SetEventHandler(new ExamplePlayerEventHandler);
	rage::IMultiplayer::Instance().SetEventHandler(new ExampleTickEventHandler);
}