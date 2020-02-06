#ifndef CHORUS_SERIALIZATION_MANAGER_H_
#define CHORUS_SERIALIZATION_MANAGER_H_

#include <string>
#include <memory>
#include <functional>
#include <unordered_map>

#include <chorus/serialization/serializer.h>

namespace chorus
{
    class Uint8Serializer : public ISerializer
    {
        virtual std::string getName() override
        {
            return "std::uint8_t";
        }

        virtual SObject deepCopier(const SObject& original, ICopyContext& context) override
        {

        }

        virtual void serializer(SObject& untypedInput, ISerializationContext& context) override
        {

        }

        virtual SObject deserializer(IDeserializationContext& context) override
        {

        }
    };

    class SerializationManager
    {
    public:
        void registerSerializer(const std::string& type_name, std::shared_ptr<ISerializer> serializer)
        {
            auto key = std::hash<std::string>{}(type_name);
            if (serializers_.find(key) != serializers_.end()) {
                serializers_[key] = serializer;
            } else {
                serializers_[key] = serializer;
            }
        }
    public:
        void serializeInner();
        void deserializeInner();
        void deepcopyInner();
    private:
        std::unordered_map<std::uint64_t, std::shared_ptr<ISerializer>> serializers_;
    };
}

#endif