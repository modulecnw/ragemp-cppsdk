#pragma once
#include <cstdint>

namespace rage {
	/*
		.text:0000000141213D90								  sub_141213D90   proc near               ; DATA XREF: .rdata:const EventHandler::IServerHandler`
		.text:0000000141213D90 48 FF 25 69 8B 3A 01                          jmp     cs:qword_1425BC900
		.text:0000000141213D90                                sub_141213D90   endp
		.text:0000000141213D90
	*/

	class IServerHandler
	{
	public:
		virtual void Unload() = 0;
	};
}