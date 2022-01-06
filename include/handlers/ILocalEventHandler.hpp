#pragma once
#include <cstdint>

namespace rage {
	/*
		.rdata:0000000141A80930                                                 ; class rage::ILocalEventHandler
		.rdata:0000000141A80930 90 AC E6 41 01 00 00 00                                         dq offset ??_R4EventHandler@bridge@@6B@_8 ; const bridge::EventHandler::`RTTI Complete Object Locator'
		.rdata:0000000141A80938                                                 ; const bridge::EventHandler::`vftable'
		.rdata:0000000141A80938 30 36 21 41 01 00 00 00                         ??_7EventHandler@bridge@@6B@_8 dq offset on_local_event
	*/

	class ILocalEventHandler
	{
	public:
		// not tested
		virtual void on_local_event(uint64_t event_name_hash, const rage::args_t& args, __int64* return_value) = 0;
	};
}