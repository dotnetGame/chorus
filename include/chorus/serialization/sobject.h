#ifndef CHORUS_SOBJECT_H_
#define CHORUS_SOBJECT_H_

#include <cstdint>
#include <variant>
#include <string>
#include <vector>
#include <memory>

namespace chorus
{
    class IObject
    {

    };

    class SObject
    {
    public:
        using SUnionType = std::variant<
            std::uint8_t,
            std::uint16_t,
            std::uint32_t,
            std::uint64_t,
            std::int8_t,
            std::int16_t,
            std::int32_t,
            std::int64_t,
            float,
            double,
            std::string,
            std::vector<SObject>,
            std::unique_ptr<IObject>
        >;

    public:
        SObject()
            :inner_{}
        {
        }

        template<typename T>
        SObject(T&&rhs)
            :inner_{rhs}
        {
        }

        SObject(const SObject& other) = delete;

        SObject(SObject&& other) noexcept = delete;

        ~SObject()
        {
        }

        bool is_uint8() { return inner_.index() == 0; }
        bool is_uint16() { return inner_.index() == 1; }
        bool is_uint32() { return inner_.index() == 2; }
        bool is_uint64() { return inner_.index() == 3; }
        bool is_int8() { return inner_.index() == 4; }
        bool is_int16() { return inner_.index() == 5; }
        bool is_int32() { return inner_.index() == 6; }
        bool is_int64() { return inner_.index() == 7; }
        bool is_float() { return inner_.index() == 8; }
        bool is_double() { return inner_.index() == 9; }
        bool is_string() { return inner_.index() == 10; }
        bool is_array() { return inner_.index() == 11; }
        bool is_object() { return inner_.index() == 12; }

        std::uint8_t* get_uint8_ptr() { return std::get_if<std::uint8_t>(&inner_); }
        std::uint16_t* get_uint16_ptr() { return std::get_if<std::uint16_t>(&inner_); }
        std::uint32_t* get_uint32_ptr() { return std::get_if<std::uint32_t>(&inner_); }
        std::uint64_t* get_uint64_ptr() { return std::get_if<std::uint64_t>(&inner_); }
        std::int8_t* get_int8_ptr() { return std::get_if<std::int8_t>(&inner_); }
        std::int16_t* get_int16_ptr() { return std::get_if<std::int16_t>(&inner_); }
        std::int32_t* get_int32_ptr() { return std::get_if<std::int32_t>(&inner_); }
        std::int64_t* get_int64_ptr() { return std::get_if<std::int64_t>(&inner_); }
        float* get_float_ptr() { return std::get_if<float>(&inner_); }
        double* get_double_ptr() { return std::get_if<double>(&inner_); }
        std::string* get_string_ptr() { return std::get_if<std::string>(&inner_); }
        std::vector<SObject>* get_array_ptr() { return std::get_if<std::vector<SObject>>(&inner_); }
        std::unique_ptr<IObject>* get_object_ptr() { return std::get_if<std::unique_ptr<IObject>>(&inner_); }

        std::uint8_t& get_uint8() { return std::get<std::uint8_t>(inner_); }
        std::uint16_t& get_uint16() { return std::get<std::uint16_t>(inner_); }
        std::uint32_t& get_uint32() { return std::get<std::uint32_t>(inner_); }
        std::uint64_t& get_uint64() { return std::get<std::uint64_t>(inner_); }
        std::int8_t& get_int8() { return std::get<std::int8_t>(inner_); }
        std::int16_t& get_int16() { return std::get<std::int16_t>(inner_); }
        std::int32_t& get_int32() { return std::get<std::int32_t>(inner_); }
        std::int64_t& get_int64() { return std::get<std::int64_t>(inner_); }
        float& get_float() { return std::get<float>(inner_); }
        double& get_double() { return std::get<double>(inner_); }
        std::string& get_string() { return std::get<std::string>(inner_); }
        std::vector<SObject>& get_array() { return std::get<std::vector<SObject>>(inner_); }
        std::unique_ptr<IObject>& get_object() { return std::get<std::unique_ptr<IObject>>(inner_); }

        template<typename T>
        SObject& operator=( T&& rhs )
        {
            inner_ = rhs;
            return *this;
        }
    private:
        SUnionType inner_;
    };
}

#endif