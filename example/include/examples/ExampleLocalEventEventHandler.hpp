#pragma once

class ExampleLocalEventEventHandler : public rage::IEventHandler,
	public rage::ILocalEventHandler {
public:
	virtual rage::ILocalEventHandler* GetLocalEventHandler() override { return this; }

	virtual void on_local_event(uint64_t event_name_hash, const rage::args_t& args, __int64* return_value) override {
		rage::Log::Debug("ILocalEventHandler", ">>", event_name_hash, args.Length(), return_value);
	}
};