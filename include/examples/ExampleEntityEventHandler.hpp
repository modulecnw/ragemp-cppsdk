#pragma once

class ExampleEntityEventHandler : public rage::IEventHandler,
	public rage::IEntityHandler {
public:
	virtual rage::IEntityHandler* GetEntityHandler() override { return this; }

	virtual void on_entity_created(__int64* entity_ptr) override {
		rage::Log::Debug("IEntityHandler", ">>", "Created");
	}

	virtual void on_entity_destroyed(__int64* entity_ptr) override {
		rage::Log::Debug("IEntityHandler", ">>", "Destroyed");
	}

	virtual void on_entity_model_change(__int64* entity_ptr, uint32_t new_model) override {
		rage::Log::Debug("IEntityHandler", ">>", "Model-Change", new_model);
	}
};