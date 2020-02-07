#ifndef CHORUS_TCP_CLIENT_H_
#define CHORUS_TCP_CLIENT_H_

#include <cstdint>
#include <string>
#include <memory>
#include <stdexcept>

#include <asio.hpp>

#include <chorus/net/NetworkStream.h>

namespace chorus
{
    class TcpClient
    {
    public:
        TcpClient()
            :ip_address_(), port_(), socket_(nullptr), endpoint_(nullptr), io_context_(nullptr)
        {
        }
        
        TcpClient(const std::string& ipAddress, std::uint16_t port)
            :ip_address_(ipAddress), port_(port), socket_(nullptr), endpoint_(nullptr), io_context_(nullptr)
        {
            endpoint_ = std::make_unique<asio::ip::tcp::endpoint>(getTcpEndpoint());
        }

        void connect()
        {
            if (endpoint_)
            {
                socket_ = std::make_shared<asio::ip::tcp::socket>(*io_context_);
                asio::connect(*socket_, *endpoint_);
            }
            else
            {
                throw std::runtime_error("Ip and port are not setted.");
            }
        }

        void connect(const std::string& ipAddress, std::uint16_t port)
        {
            socket_ = std::make_shared<asio::ip::tcp::socket>(*io_context_);
            endpoint_ = std::make_unique<asio::ip::tcp::endpoint>(getTcpEndpoint());
            asio::connect(*socket_, *endpoint_);
        }

        NetworkStream getStream()
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
        std::shared_ptr<asio::ip::tcp::socket> socket_;
        std::unique_ptr<asio::ip::tcp::endpoint> endpoint_;
        std::unique_ptr<asio::io_context> io_context_;
    };
}

#endif // CHORUS_TCP_SERVER_H_