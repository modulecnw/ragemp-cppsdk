#pragma once
#include <cstdint>

namespace rage {
	/*
		.rdata:0000000141A808F8                                                 ; class rage::IBlipHandler
		.rdata:0000000141A808F8 18 AC E6 41 01 00 00 00                                         dq offset ??_R4EventHandler@bridge@@6B@_5 ; const bridge::EventHandler::`RTTI Complete Object Locator'
		.rdata:0000000141A80900                                                 ; const bridge::EventHandler::`vftable'
		.rdata:0000000141A80900 C0 02 01 40 01 00 00 00                         ??_7EventHandler@bridge@@6B@_5 dq offset on_player_create_waypoint
		.rdata:0000000141A80900                                                                                         ; DATA XREF: sub_14120D250+6B
		.rdata:0000000141A80908 C0 02 01 40 01 00 00 00                                         dq offset on_player_reach_waypoint
	*/

	class IBlipHandler
	{
	public:
		// NOT WORKING - NOT SYNCED
		virtual void on_player_create_waypoint(__int64* entity_ptr, const rage::vec3_t& waypoint_position) = 0;
		virtual void on_player_reach_waypoint(__int64* entity_ptr) = 0;
	};
}