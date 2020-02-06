#ifndef CHORUS_TCP_CLIENT_H_
#define CHORUS_TCP_CLIENT_H_

#include <cstdint>
#include <string>

#include <chorus/network/TcpStream.h>

namespace chorus
{
    class TcpClient
    {
    public:
        TcpClient()
            :ip_address_(), port_()
        {
        }
        
        TcpClient(const std::string& ipAddress, std::uint16_t port)
            :ip_address_(ipAddress), port_(port)
        {
        }

        void connect()
        {

        }

        void connect(const std::string& ipAddress, std::uint16_t port)
        {

        }

        NetworkStream getStream()
        {

        }

    private:
        std::string ip_address_;
        std::uint16_t port_;
    };
}

#endif // CHORUS_TCP_SERVER_H_