#pragma once
#include <xkeycheck.h>

class ExampleConnectionEventHandler : public rage::IEventHandler,
	public rage::IConnectionHandler {
public:
	virtual rage::IConnectionHandler* GetConnectionHandler() override { return this; }

	virtual void on_incoming_connection(const char* ip, const std::string& serial, const char* rgsc_name, unsigned long rgsc_id, rage::game_type_t game_type) override {
		rage::Log::Debug(">>>>>>>>>>>>>>>>>", "IConnectionHandler - Connection Start", ">>>>>>>>>>>>>>>>>");
		rage::Log::Debug("IP:", ip);
		rage::Log::Debug("Serial:", serial);
		rage::Log::Debug("RGSC-Name:", rgsc_name);
		rage::Log::Debug("RGSC-ID:", rgsc_id);
		rage::Log::Debug("Game-Type:", (int)game_type);
		rage::Log::Debug(">>>>>>>>>>>>>>>>>", "IConnectionHandler - Connection End", ">>>>>>>>>>>>>>>>>");
	}
};