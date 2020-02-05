#ifndef CHORUS_SERIALIZATION_MANAGER_H_
#define CHORUS_SERIALIZATION_MANAGER_H_

#include <string>

namespace chorus
{
    class SerializationManager
    {
    public:
        void registerSerializer(const std::string& type_name, );
    public:
        void serializeInner();
        void deserializeInner();
        void deepcopyInner();
    };
}

#endif