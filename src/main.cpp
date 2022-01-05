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
	public rage::IPlayerHandler {
public:
	virtual rage::IPlayerHandler* GetPlayerHandler() override { return this; }

	virtual void on_player_connect(__int64* entity_ptr) override {
		rage::Log::Debug("IPlayerHandler", ">>", "Connect");
	}

	virtual void on_player_ready(__int64* entity_ptr) override {
		rage::Log::Debug("IPlayerHandler", ">>", "Ready");
	}

	virtual void on_player_disconnect(__int64* entity_ptr, unsigned __int8 disconnect_type, __int64 reason) override {
		// disconnect_type -> broken?

		rage::Log::Debug("IPlayerHandler", ">>", "Disconnect", (int)disconnect_type, reason);
	}

	virtual void on_player_command(__int64* entity_ptr, const std::u16string& command)  override {
		std::string string_command(command.begin(), command.end());

		rage::Log::Debug("IPlayerHandler", ">>", "Command", string_command);
	}

	virtual void on_player_chat(__int64* entity_ptr, const std::u16string& message) override {
		std::string string_message(message.begin(), message.end());

		rage::Log::Debug("IPlayerHandler", ">>", "Chat", string_message);
	}

	virtual void on_player_death(__int64* entity_ptr, uint32_t death_reason, __int64* killer_ptr) override {
		rage::Log::Debug("IPlayerHandler", ">>", "Death", death_reason, killer_ptr);
	}

	virtual void on_player_spawn(__int64* entity_ptr) override {
		rage::Log::Debug("IPlayerHandler", ">>", "Spawn");
	}

	virtual void on_player_damage(__int64* entity_ptr, float health_loss, float armor_loss) override {
		rage::Log::Debug("IPlayerHandler", ">>", "Damage", health_loss, armor_loss);
	}

	virtual void on_player_weapon_switch(__int64* entity_ptr, uint32_t old_weapon, uint32_t new_weapon) override {
		rage::Log::Debug("IPlayerHandler", ">>", "WeaponSwitch", old_weapon, new_weapon);
	}

	virtual void on_player_remote_event(__int64* entity_ptr, uint64_t event_name_hash, const rage::args_t& args) override {
		rage::Log::Debug("IPlayerHandler", ">>", "RemoteEvent", event_name_hash, args.Length());
	}

	virtual void on_player_start_enter_vehicle(__int64* entity_ptr, __int64* vehicle_ptr, unsigned __int8 seat_id)	override { }

	virtual void on_player_enter_vehicle(__int64* entity_ptr, __int64* vehicle_ptr, unsigned __int8 seat_id) override {
		rage::Log::Debug("IPlayerHandler", ">>", "EnterVehicle", vehicle_ptr, (int)seat_id);
	}

	virtual void on_player_start_exit_vehicle(__int64* entity_ptr) override { }

	virtual void on_player_exit_vehicle(__int64* entity_ptr) override {
		rage::Log::Debug("IPlayerHandler", ">>", "ExitVehicle");
	}
};

EXTERN void InitializePlugin(rage::IMultiplayer* _mp)
{
	rage::IMultiplayer::SetInstance(_mp);
	rage::Log::Push(new rage::Log::ConsoleStream);

	rage::Log::Done("Initialized plugin.", ">>", GetPluginName());

	rage::IMultiplayer::Instance().SetEventHandler(new ExampleEventHandler);
}