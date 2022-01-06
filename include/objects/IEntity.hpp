#pragma once

namespace rage {
	class IEntity {
	public:
		virtual uint16_t get_id() = 0; // 0x38
		virtual entity_type_t get_entity_type() = 0; // 0xB

		virtual void v8_internal_compiler_LoadElimination() = 0; // ????

		virtual void destroy() = 0;

		virtual uint32_t get_dimension() = 0; // 0x3A
		virtual void set_dimension(uint32_t dimension) = 0;

		//virtual void v8_internal_OptimizedCompilationInfo_InlinedFunctionHolder_inlined_functions() = 0;
		virtual const vec3_t& get_position() = 0; // 0x64
		virtual void set_position(const vec3_t& position) = 0;

		virtual const vec3_t& get_rotation() = 0; 
		virtual void set_rotation(const vec3_t& rotation) = 0;

		virtual uint32_t get_model() = 0; // 0x3E
		virtual void set_model(uint32_t model_hash) = 0;

		virtual const vec3_t& get_velocity() = 0; // could be velocity, or something different idk

		virtual uint8_t get_alpha() = 0;
		virtual void set_alpha(uint8_t alpha) = 0;
	};
}