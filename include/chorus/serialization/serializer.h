#ifndef CHORUS_SERIALIZER_H_
#define CHORUS_SERIALIZER_H_

#include <cstdint>

#include <chorus/serialization/copy_context.h>
#include <chorus/serialization/serialization_context.h>
#include <chorus/serialization/deserialization_context.h>
#include <chorus/serialization/sobject.h>

namespace chorus
{
    class Serializer
    {
        virtual SObject deepCopier(const SObject& original, ICopyContext context)=0;

        virtual void serializer(SObject& untypedInput, ISerializationContext context)=0;

        virtual SObject deserializer(IDeserializationContext context)=0;
    };

    class Uint8Serializer : public Serializer
    {
        virtual SObject deepCopier(const SObject& original, ICopyContext context)=0;

        virtual void serializer(SObject& untypedInput, ISerializationContext context)=0;

        virtual SObject deserializer(IDeserializationContext context)=0;
    };
}

#endif