#pragma once

class ExampleTickEventHandler : public rage::IEventHandler,
	public rage::ITickHandler {
public:
	virtual rage::ITickHandler* GetTickHandler() override { return this; }

	virtual void Tick() override {
		DWORD64 current_tick = GetTickCount64();

		static DWORD64 current_tick_timeout = 0x0;
		static DWORD64 latest_tick_timeout = 0x0;

		if ((current_tick_timeout - latest_tick_timeout) > 10000) {
			rage::Log::Debug("ITickHandler", ">>", "Tick (10000)");

			latest_tick_timeout = current_tick_timeout;
		}
		current_tick_timeout = current_tick;
	}
};