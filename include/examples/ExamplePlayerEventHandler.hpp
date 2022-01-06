#pragma once

class ExamplePlayerEventHandler : public rage::IEventHandler,
	public rage::IPlayerHandler {
public:
	virtual rage::IPlayerHandler* GetPlayerHandler() override { return this; }

	virtual void on_player_connect(rage::IPlayer* player) override {
		rage::Log::Debug("IPlayerHandler", ">>", "Connect");
	}

	virtual void on_player_ready(rage::IPlayer* player) override {
		rage::Log::Debug("IPlayerHandler", ">>", "Ready", player->get_id());
	}

	virtual void on_player_disconnect(rage::IPlayer* player, unsigned __int8 disconnect_type, __int64 reason) override {
		// disconnect_type -> broken?

		rage::Log::Debug("IPlayerHandler", ">>", "Disconnect", (int)disconnect_type, reason);
	}

	virtual void on_player_command(rage::IPlayer* player, const std::u16string& command)  override {
		std::string string_command(command.begin(), command.end());

		rage::Log::Debug("IPlayerHandler", ">>", "Command", string_command);
	}

	virtual void on_player_chat(rage::IPlayer* player, const std::u16string& message) override {
		std::string string_message(message.begin(), message.end());

		rage::Log::Debug("IPlayerHandler", ">>", "Chat", string_message);
	}

	virtual void on_player_death(rage::IPlayer* player, uint32_t death_reason, rage::IPlayer* killer_ptr) override {
		rage::Log::Debug("IPlayerHandler", ">>", "Death", death_reason, killer_ptr);
	}

	virtual void on_player_spawn(rage::IPlayer* player) override {
		rage::Log::Debug("IPlayerHandler", ">>", "Spawn");
	}

	virtual void on_player_damage(rage::IPlayer* player, float health_loss, float armor_loss) override {
		rage::Log::Debug("IPlayerHandler", ">>", "Damage", health_loss, armor_loss);
	}

	virtual void on_player_weapon_switch(rage::IPlayer* player, uint32_t old_weapon, uint32_t new_weapon) override {
		rage::Log::Debug("IPlayerHandler", ">>", "WeaponSwitch", old_weapon, new_weapon);
	}

	virtual void on_player_remote_event(rage::IPlayer* player, uint64_t event_name_hash, const rage::args_t& args) override {
		rage::Log::Debug("IPlayerHandler", ">>", "RemoteEvent", event_name_hash, args.Length());
	}

	virtual void on_player_start_enter_vehicle(rage::IPlayer* player, rage::IVehicle* vehicle_ptr, unsigned __int8 seat_id)	override { }

	virtual void on_player_enter_vehicle(rage::IPlayer* player, rage::IVehicle* vehicle_ptr, unsigned __int8 seat_id) override {
		rage::Log::Debug("IPlayerHandler", ">>", "EnterVehicle", vehicle_ptr, (int)seat_id);
	}

	virtual void on_player_start_exit_vehicle(rage::IPlayer* player) override { }

	virtual void on_player_exit_vehicle(rage::IPlayer* player) override {
		rage::Log::Debug("IPlayerHandler", ">>", "ExitVehicle");
	}
};