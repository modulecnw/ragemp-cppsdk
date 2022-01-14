#pragma once
#include <cstdint>

namespace rage {
	/*
		.rdata:0000000141A808E0                                                 ; class rage::ICheckpointHandler
		.rdata:0000000141A808E0 F0 AB E6 41 01 00 00 00                                         dq offset ??_R4EventHandler@bridge@@6B@_4 ; const bridge::EventHandler::`RTTI Complete Object Locator'
		.rdata:0000000141A808E8                                                 ; const bridge::EventHandler::`vftable'
		.rdata:0000000141A808E8 F0 37 21 41 01 00 00 00                         ??_7EventHandler@bridge@@6B@_4 dq offset on_player_enter_checkpoint
		.rdata:0000000141A808E8                                                                                         ; DATA XREF: sub_14120D250+60
		.rdata:0000000141A808F0 F0 38 21 41 01 00 00 00                                         dq offset on_player_exit_checkpoint
	*/

	class ICheckpointHandler
	{
	public:
		virtual void on_player_enter_checkpoint(rage::IPlayer* entity_ptr, rage::ICheckpoint* checkpoint_ptr) = 0;
		virtual void on_player_exit_checkpoint(rage::IPlayer* entity_ptr, rage::ICheckpoint* checkpoint_ptr) = 0;
	};
}