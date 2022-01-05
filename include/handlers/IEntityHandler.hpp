#pragma once
#include <cstdint>

namespace rage {
	class IEntityHandler
	{
	public:
		virtual void on_entity_created(__int64* entity_ptr) = 0;
		virtual void on_entity_destroyed(__int64* entity_ptr) = 0;
	};
}