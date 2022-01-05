#pragma once
#include <cstdint>

namespace rage {
	class ITickHandler
	{
	public:
		virtual void Tick() = 0;
	};
}