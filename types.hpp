#pragma once
#include <sstream>

namespace rage {
	enum class game_type_t : uint8_t {
		rgsc,
		steam,
		egs
	};

	struct vec3_t {
		float x, y, z;
	};

	enum class entity_type_t : uint8_t
	{
		PLAYER,
		VEHICLE,
		OBJECT,
		PICKUP,
		BLIP,
		CHECKPOINT,
		MARKER,
		COLSHAPE,
		TEXTLABEL,
		DUMMYENTITY
	};

#pragma pack(push, 1)
	struct arg_t
	{
	public:
		enum class val_t : uint8_t
		{
			Int,
			Float,
			String,
			Boolean,
			Vector3,
			Object,
			Null,

			Entity
		};

		arg_t() : type(val_t::Null), v{} { }
		arg_t(bool b) : type(val_t::Boolean), v{ b } { }
		arg_t(int i) : type(val_t::Int), v{ i } { }
		arg_t(float f) : type(val_t::Float), v{ f } { }
		arg_t(const std::string& str) : type(val_t::String), v{ new char[str.length() + 1] } { memcpy(v.str, str.c_str(), str.length()); v.str[str.length()] = 0; }
		arg_t(entity_type_t entityType, uint16_t id, __int64* entity) : type(val_t::Entity), v{ entityType, id, entity } { }
		arg_t(const arg_t& r) : type(val_t::Null) { *this = r; }

		void SetNull() { DeleteString(); type = val_t::Null; }
		void SetBoolean(bool b) { DeleteString(); type = val_t::Boolean; v.b = b; }
		void SetInteger(int i) { DeleteString(); type = val_t::Int; v.i = i; }
		void SetFloat(float f) { DeleteString(); type = val_t::Float; v.f = f; }
		void SetString(const std::string& str) { DeleteString(); type = val_t::String; v.str = new char[str.length() + 1]; memcpy(v.str, str.c_str(), str.length()); v.str[str.length()] = 0; }
		void SetJson(const std::string& str) { DeleteString(); type = val_t::Object; v.str = new char[str.length() + 1]; memcpy(v.str, str.c_str(), str.length()); v.str[str.length()] = 0; }
		void SetEntity(entity_type_t entityType, uint16_t id, __int64* entity) { DeleteString(); type = val_t::Entity; v.entity = { entityType, id, entity }; }
		void SetVector3(const vec3_t& vec) { DeleteString(); type = val_t::Vector3; v.vector = vec; }

		val_t GetType() const { return type; }
		bool IsNull() const { return type == val_t::Null; }
		bool IsBoolean() const { return type == val_t::Boolean; }
		bool IsInt() const { return type == val_t::Int; }
		bool IsFloat() const { return type == val_t::Float; }
		bool IsString() const { return type == val_t::String; }
		bool IsEntity() const { return type == val_t::Entity; }

		bool Boolean() const { return (type == val_t::Boolean) ? v.b : false; }
		int Int() const { return (type == val_t::Int) ? v.i : 0; }
		float Float() const { return (type == val_t::Float) ? v.f : 0.0f; }
		const char* String() const { return (type == val_t::String && v.str) ? v.str : ""; }
		const char* Object() const { return (type == val_t::Object && v.str) ? v.str : ""; }
		const vec3_t& Vector3() const { if (type == val_t::Vector3) { return v.vector; } else { static vec3_t ret; return ret; } }

		__int64* Entity() const { return (type == val_t::Entity) ? v.entity.ptr : nullptr; }
		uint16_t EntityId() const { return (type == val_t::Entity) ? v.entity.id : 0xFFFF; }
		entity_type_t EntityType() const { return (type == val_t::Entity) ? v.entity.type : static_cast<entity_type_t>(-1); }

		arg_t& operator=(const arg_t& r) { DeleteString(); if (r.GetType() != val_t::String) { this->v.entity = r.v.entity; type = r.GetType(); } else { this->SetString(r.String()); } return *this; }
		arg_t& operator=(arg_t&& r) { DeleteString(); this->v.str = r.v.str; type = r.GetType(); r.type = val_t::Null; r.v.str = nullptr; return *this; }

		~arg_t() { DeleteString(); }

	private:
		bool OwnsAString() { return (type == val_t::Object || type == val_t::String); }
		void DeleteString() { if (this->OwnsAString() && v.str) { delete[] v.str; v.str = nullptr; } }

		union _Value
		{
			bool b;
			int i;
			float f;
			char* str;

			vec3_t vector;

			struct _EntityData
			{
				entity_type_t type;
				uint16_t id;

				__int64* ptr;
			} entity;

			_Value() { memset(this, 0, sizeof(_Value)); }
			_Value(bool _b) : b{ _b } { }
			_Value(int _i) : i{ _i } { }
			_Value(float _f) : f{ _f } { }
			_Value(char* _str) : str{ _str } { }
			_Value(const vec3_t& _vec) : vector{ _vec } { }
			_Value(entity_type_t entityType, uint16_t id, __int64* ptr) : entity{ entityType, id, ptr } { }
		} v;

		val_t type;
	};
#pragma pack(pop)

	struct args_t
	{
	public:
		args_t(arg_t* data, size_t len)
			: m_data(data), m_len(len) { }

		size_t Length() const { return this->m_len; }
		const arg_t& operator[](size_t id) const { if (id >= this->m_len) { static arg_t ar{}; return ar; } return this->m_data[id]; }

		auto begin() const { return m_data; }
		auto end() const { return &m_data[this->m_len]; }

	private:
		size_t m_len;
		arg_t* m_data;
	};
}