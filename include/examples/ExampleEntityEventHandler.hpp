#pragma once

class ExampleEntityEventHandler : public rage::IEventHandler,
	public rage::IEntityHandler {
public:
	virtual rage::IEntityHandler* GetEntityHandler() override { return this; }

	virtual void on_entity_created(rage::IEntity *entity_ptr) override {
		rage::Log::Debug("IEntityHandler", ">>", "Created", (int)entity_ptr->get_id(), (int)entity_ptr->get_entity_type());
	}

	virtual void on_entity_destroyed(rage::IEntity* entity_ptr) override {
		rage::Log::Debug("IEntityHandler", ">>", "Destroyed");
	}

	virtual void on_entity_model_change(rage::IEntity* entity_ptr, uint32_t new_model) override {
		rage::Log::Debug("IEntityHandler", ">>", "Model-Change", new_model);
	}
};