#pragma once
#include <cstdint>

namespace rage {
	/*
		.rdata:0000000141A808C8                                                 ; class rage::IColshapeHandler
		.rdata:0000000141A808C8 C8 AB E6 41 01 00 00 00                                         dq offset ??_R4EventHandler@bridge@@6B@_3 ; const bridge::EventHandler::`RTTI Complete Object Locator'
		.rdata:0000000141A808D0                                                 ; const bridge::EventHandler::`vftable'
		.rdata:0000000141A808D0 40 38 21 41 01 00 00 00                         ??_7EventHandler@bridge@@6B@_3 dq offset EnterColshape
		.rdata:0000000141A808D0                                                                                         ; DATA XREF: sub_14120D250+55
		.rdata:0000000141A808D8 40 39 21 41 01 00 00 00                                         dq offset ExitColshape
	*/

	class IColshapeHandler
	{
	public:
		virtual void on_player_enter_colshape(rage::IPlayer* entity_ptr, rage::IColshape* colshape_ptr) = 0;
		virtual void on_player_exit_colshape(rage::IPlayer* entity_ptr, rage::IColshape* colshape_ptr) = 0;
	};
}