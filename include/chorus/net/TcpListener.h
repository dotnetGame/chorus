#ifndef CHORUS_TCP_LISTENER_H_
#define CHORUS_TCP_LISTENER_H_

#include <cstdint>
#include <string>

#include <asio.hpp>

namespace chorus
{
    class TcpListener
    {
    public:
        TcpListener(const std::string& ipAddress, std::uint16_t port)
            :ip_address_(ipAddress), port_(port)
        {
            
        }

        void start()
        {

        }

        void acceptTcpClient()
        {
            
        }

        void stop()
        {

        }
    private:
        asio::ip::tcp::endpoint getTcpEndpoint() const
        {
            asio::ip::address address;
            address.from_string(ip_address_.c_str());
            asio::ip::tcp::endpoint endpoint(address, port_);
            return endpoint;
        }

    private:
        std::string ip_address_;
        std::uint16_t port_;
    };
}

#endif // CHORUS_TCP_LISTENER_H_