#include <prismarine/connection_hub.h>

#include <memory>

namespace prismarine
{
	ConnectionHub::ConnectionHub()
        : addr()
	{
	}

	ConnectionHub::~ConnectionHub()
	{

	}

    int ConnectionHub::listen(const char* ip, int port)
    {
        uv_loop_t* loop = uv_default_loop();
        uv_tcp_t server;
        uv_tcp_init(loop, &server);

        uv_ip4_addr(ip, port, &addr);

        uv_tcp_bind(&server, (const struct sockaddr*) & addr, 0);
        int r = uv_listen((uv_stream_t*)&server, 128, ConnectionHub::on_new_connection);
        if (r) {
            fprintf(stderr, "Listen error %s\n", uv_strerror(r));
            return 1;
        }
        return uv_run(loop, UV_RUN_DEFAULT);
    }

    void ConnectionHub::on_new_connection(uv_stream_t* server, int status)
    {
        uv_loop_t* loop = uv_default_loop();
        if (status < 0) {
            fprintf(stderr, "New connection error %s\n", uv_strerror(status));
            // error!
            return;
        }

        std::unique_ptr<uv_tcp_t> client = std::make_unique<uv_tcp_t>();
        uv_tcp_init(loop, client.get());
        if (uv_accept(server, (uv_stream_t*)client.get()) == 0)
        {
            uv_read_start((uv_stream_t*)client.get(), ConnectionHub::alloc_buffer, ConnectionHub::echo_read);
        }
        else
        {
            uv_close((uv_handle_t*)client.get(), ConnectionHub::on_close);
        }
    }

    void ConnectionHub::alloc_buffer(uv_handle_t* handle, size_t suggested_size, uv_buf_t* buf)
    {
        buf->base = (char*)malloc(suggested_size);
        buf->len = suggested_size;
    }

    void ConnectionHub::echo_read(uv_stream_t* client, ssize_t nread, const uv_buf_t* buf)
    {

    }

    void ConnectionHub::on_close(uv_handle_t* handle)
    {

    }
}