#pragma once
#include <cstdint>

namespace rage {
	/*
		.rdata:0000000141A80940                                                 ; class rage::IConnectionHandler
		.rdata:0000000141A80940 B8 AC E6 41 01 00 00 00                                         dq offset ??_R4EventHandler@bridge@@6B@_9 ; const bridge::EventHandler::`RTTI Complete Object Locator'
		.rdata:0000000141A80948                                                 ; const bridge::EventHandler::`vftable'
		.rdata:0000000141A80948 C0 35 21 41 01 00 00 00                         ??_7EventHandler@bridge@@6B@_9 dq offset on_incoming_connection
	*/

	class IConnectionHandler
	{
	public:
		virtual void on_incoming_connection(const char* ip, const std::string& serial, const char* rgsc_name, unsigned long rgsc_id, rage::game_type_t game_type) = 0;
	};
}