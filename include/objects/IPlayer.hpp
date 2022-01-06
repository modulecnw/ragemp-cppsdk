#pragma once

namespace rage {
	class IPlayer : public rage::IEntity {
	public:
		virtual void kick(const char* reason = nullptr) = 0; 
		virtual void kick_silent(const char* reason = nullptr) = 0;
		virtual void ban(const char* reason = nullptr) = 0;

		/*
		 * When I tried this with the local player, my game crashed.
		 */
		virtual void do_something_with_player(rage::IPlayer* player) = 0;

	};
}