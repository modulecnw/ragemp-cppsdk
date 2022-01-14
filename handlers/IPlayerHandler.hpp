#pragma once
#include <cstdint>

namespace rage {
	/*
		.rdata:0000000141A80818 C0 02 01 40 01 00 00 00                         ??_7EventHandler@@6B@_1 dq offset PlayerConnect
		.rdata:0000000141A80820 30 3A 21 41 01 00 00 00                                         dq offset PlayerReady_0
		.rdata:0000000141A80828 E0 39 21 41 01 00 00 00                                         dq offset PlayerQuit
		.rdata:0000000141A80830 E0 36 21 41 01 00 00 00                                         dq offset Command
		.rdata:0000000141A80838 90 36 21 41 01 00 00 00                                         dq offset Chat
		.rdata:0000000141A80840 80 37 21 41 01 00 00 00                                         dq offset Death
		.rdata:0000000141A80848 E0 3A 21 41 01 00 00 00                                         dq offset Spawn
		.rdata:0000000141A80850 30 37 21 41 01 00 00 00                                         dq offset Damage
		.rdata:0000000141A80858 C0 3B 21 41 01 00 00 00                                         dq offset WeaponSwitch
		.rdata:0000000141A80860 60 3A 21 41 01 00 00 00                                         dq offset RemoteEvent_0
		.rdata:0000000141A80868 C0 02 01 40 01 00 00 00                                         dq offset uv_cond_destroy
		.rdata:0000000141A80870 C0 02 01 40 01 00 00 00                                         dq offset uv_cond_destroy
		.rdata:0000000141A80878 10 3B 21 41 01 00 00 00                                         dq offset StartEnterVeh
		.rdata:0000000141A80880 90 38 21 41 01 00 00 00                                         dq offset EnterVeh
		.rdata:0000000141A80888 70 3B 21 41 01 00 00 00                                         dq offset StartExit
		.rdata:0000000141A80890 90 39 21 41 01 00 00 00                                         dq offset Exit
	*/

	class IPlayerHandler
	{
	public:
		virtual void on_player_connect(rage::IPlayer* player) = 0;
		virtual void on_player_ready(rage::IPlayer* player) = 0;
		virtual void on_player_disconnect(rage::IPlayer* player, unsigned __int8 disconnect_type, __int64 reason) = 0;

		virtual void on_player_command(rage::IPlayer* player, const std::u16string& command) = 0;
		virtual void on_player_chat(rage::IPlayer* player, const std::u16string& message) = 0;

		virtual void on_player_death(rage::IPlayer* player, uint32_t death_reason, rage::IPlayer* killer) = 0;
		virtual void on_player_spawn(rage::IPlayer* player) = 0;

		virtual void on_player_damage(rage::IPlayer* player, float health_loss, float armor_loss) = 0;
		virtual void on_player_weapon_switch(rage::IPlayer* player, uint32_t old_weapon, uint32_t new_weapon) = 0;

		virtual void on_player_remote_event(rage::IPlayer* player, uint64_t event_name_hash, const rage::args_t& args) = 0;

		virtual void padding_01(rage::IPlayer* player) { }
		virtual void padding_02(rage::IPlayer* player) { }

		virtual void on_player_start_enter_vehicle(rage::IPlayer* player, rage::IVehicle* vehicle_ptr, unsigned __int8 seat_id) = 0;
		virtual void on_player_enter_vehicle(rage::IPlayer* player, rage::IVehicle* vehicle_ptr, unsigned __int8 seat_id) = 0;

		virtual void on_player_start_exit_vehicle(rage::IPlayer* player) = 0;
		virtual void on_player_exit_vehicle(rage::IPlayer* player) = 0;
	};
}