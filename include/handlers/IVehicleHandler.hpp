#pragma once
#include <cstdint>

namespace rage {
	/*
		.rdata:0000000141A808A0 50 3E 21 41 01 00 00 00                         ??_7EventHandler@bridge@@6B@_2 dq offset OnVehicleDeath
		.rdata:0000000141A808A0                                                                                         ; DATA XREF: sub_14120D250+4A
		.rdata:0000000141A808A8 00 3F 21 41 01 00 00 00                                         dq offset OnSirenToggle
		.rdata:0000000141A808B0 C0 3E 21 41 01 00 00 00                                         dq offset OnVehicleHorn
		.rdata:0000000141A808B8 A0 3D 21 41 01 00 00 00                                         dq offset OnTrailerAttach
		.rdata:0000000141A808C0 00 3E 21 41 01 00 00 00                                         dq offset OnVehicleDamage
	*/

	class IVehicleHandler
	{
	public:
		virtual void on_vehicle_death(__int64* vehicle_ptr) = 0;
		virtual void on_vehicle_siren_toggle(__int64* vehicle_ptr, bool state) = 0;
		virtual void on_vehicle_horn_toggle(__int64* vehicle_ptr, bool state) = 0;
		virtual void on_trailer_attached(__int64* vehicle_ptr, __int64* trailer_ptr) = 0;
		virtual void on_vehicle_damage(__int64* vehicle_ptr, float body_health_loss, float engine_health_loss) = 0;
	};
}