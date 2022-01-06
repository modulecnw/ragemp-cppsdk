#pragma once

class ExampleBlipEventHandler : public rage::IEventHandler,
	public rage::IBlipHandler {
public:
	virtual rage::IBlipHandler* GetBlipHandler() override { return this; }

	virtual void on_player_create_waypoint(rage::IPlayer* entity_ptr, const rage::vec3_t& waypoint_position) override {
		rage::Log::Debug("IBlipHandler", ">>", "Create Waypoint");
	}

	virtual void on_player_reach_waypoint(rage::IPlayer* entity_ptr) override {
		rage::Log::Debug("IBlipHandler", ">>", "Reach");
	}
};