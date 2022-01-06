#pragma once

class ExampleServerEventHandler : public rage::IEventHandler,
	public rage::IServerHandler {
public:
	virtual rage::IServerHandler* GetServerHandler() override { return this; }

	virtual void Unload() override {
		rage::Log::Debug("IServerHandler", ">>", "Unload");
		Sleep(2000);
	}
};