#pragma once

class ExampleCheckpointEventHandler : public rage::IEventHandler,
	public rage::ICheckpointHandler {
public:
	virtual rage::ICheckpointHandler* GetCheckpointHandler() override { return this; }

	virtual void on_player_enter_checkpoint(rage::IPlayer* entity_ptr, rage::ICheckpoint* checkpoint_ptr) override {
		rage::Log::Debug("ICheckpointHandler", ">>", "Enter", checkpoint_ptr);
	}

	virtual void on_player_exit_checkpoint(rage::IPlayer* entity_ptr, rage::ICheckpoint* checkpoint_ptr) override {
		rage::Log::Debug("ICheckpointHandler", ">>", "Exit", checkpoint_ptr);
	}
};