
#include <chorus/server.h>

#include <iostream>

namespace chorus
{
    Server::Server(std::uint16_t port)
        :port(port)
    {

    }

    Server::~Server()
    {

    }

    void Server::run()
    {
        try
        {
            asio::io_context io_context;
            connection_acceptor = std::make_unique<asio::ip::tcp::acceptor>(io_context, asio::ip::tcp::endpoint(asio::ip::tcp::v4(), port));
            accept();

            io_context.run();
        }
        catch (std::exception & e)
        {
            std::cerr << "Exception: " << e.what() << std::endl;
        }
    }
    void Server::accept()
    {
        if (connection_acceptor)
        {
            connection_acceptor->async_accept(
                [this](std::error_code ec, asio::ip::tcp::socket socket)
                {
                    if (!ec)
                    {
                        std::make_shared<Session>(std::move(socket))->start();
                    }

                    this->accept();
                });
        }
    }
}
