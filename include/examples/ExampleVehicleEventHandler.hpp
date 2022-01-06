#pragma once

class ExampleVehicleEventHandler : public rage::IEventHandler,
	public rage::IVehicleHandler {
public:
	virtual rage::IVehicleHandler* GetVehicleHandler() override { return this; }

	virtual void on_vehicle_death(rage::IVehicle* vehicle_ptr) override {
		rage::Log::Debug("IVehicleHandler", ">>", "Death");
	}

	virtual void on_vehicle_siren_toggle(rage::IVehicle* vehicle_ptr, bool state) override {
		rage::Log::Debug("IVehicleHandler", ">>", "Siren", state);
	}

	virtual void on_vehicle_horn_toggle(rage::IVehicle* vehicle_ptr, bool state)  override {
		rage::Log::Debug("IVehicleHandler", ">>", "Horen", state);
	}

	virtual void on_trailer_attached(rage::IVehicle* vehicle_ptr, rage::IVehicle* trailer_ptr) override {
		rage::Log::Debug("IVehicleHandler", ">>", "Trailer attached");
	}

	virtual void on_vehicle_damage(rage::IVehicle* vehicle_ptr, float body_health_loss, float engine_health_loss)  override {
		rage::Log::Debug("IVehicleHandler", ">>", "Damage", body_health_loss, engine_health_loss);
	}
};