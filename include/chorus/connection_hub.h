#ifndef CONNECTION_HUB_H_
#define CONNECTION_HUB_H_

#include <uv.h>
#include <stdio.h>
#include <stdlib.h>

#include <functional>

namespace prismarine
{
    class ConnectionHub
    {
    public:
        ConnectionHub();
        ~ConnectionHub();

        int listen(const char* ip, int port);
        static void on_new_connection(uv_stream_t* server, int status);
        static void alloc_buffer(uv_handle_t* handle, size_t suggested_size, uv_buf_t* buf);
        static void echo_read(uv_stream_t* client, ssize_t nread, const uv_buf_t* buf);
        static void on_close(uv_handle_t* handle);
    private:
        struct sockaddr_in addr;
    };
}



#endif