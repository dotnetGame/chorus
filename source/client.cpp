
#include <chorus/client.h>

namespace chorus
{
    Client::Client(const std::string& ip, std::uint16_t port)
        :ip(ip), port(port)
    {

    }
    
    Client::~Client()
    {

    }
}