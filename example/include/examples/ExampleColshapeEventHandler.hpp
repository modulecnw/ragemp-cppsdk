#pragma once

class ExampleColshapeEventHandler : public rage::IEventHandler,
	public rage::IColshapeHandler {
public:
	virtual rage::IColshapeHandler* GetColshapeHandler() override { return this; }

	virtual void on_player_enter_colshape(rage::IPlayer* entity_ptr, rage::IColshape* colshape_ptr) override {
		rage::Log::Debug("IColshapeHandler", ">>", "Enter", colshape_ptr);
	}

	virtual void on_player_exit_colshape(rage::IPlayer* entity_ptr, rage::IColshape* colshape_ptr) override {
		rage::Log::Debug("IColshapeHandler", ">>", "Exit", colshape_ptr);
	}
};