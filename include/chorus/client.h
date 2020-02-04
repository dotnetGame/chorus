#ifndef CHORUS_CLIENT_H_
#define CHORUS_CLIENT_H_

#include <string>
#include <cstdint>
#include <type_traits>

namespace chorus
{
    class Client
    {
    public:
        Client(const std::string& ip, std::uint16_t port);
        ~Client();
    private:
        std::string ip;
        std::uint16_t port;
    };
}


#endif // CHORUS_CLIENT_H_