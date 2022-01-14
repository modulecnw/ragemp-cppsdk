#pragma once
#include <cstdint>

namespace rage {
	/*
	.rdata:0000000141A807F8 C0 34 21 41 01 00 00 00                         ??_7EventHandler@bridge@@6B@_0 dq offset on_entity_created
	.rdata:0000000141A807F8                                                                                         ; DATA XREF: sub_14120D250+2E
	.rdata:0000000141A80800 10 35 21 41 01 00 00 00                                         dq offset on_entity_destroyed 
	.rdata:0000000141A80808 60 35 21 41 01 00 00 00                                         dq offset on_entity_model_change
	*/

	class IEntityHandler
	{
	public:
		virtual void on_entity_created(rage::IEntity* entity_ptr) = 0;
		virtual void on_entity_destroyed(rage::IEntity* entity_ptr) = 0;
		virtual void on_entity_model_change(rage::IEntity* entity_ptr, uint32_t new_model) = 0;
	};
}