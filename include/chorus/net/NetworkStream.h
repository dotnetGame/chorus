#ifndef CHORUS_NETWORK_TCP_STREAM_H_
#define CHORUS_NETWORK_TCP_STREAM_H_


#include <exception>
#include <memory>

#include <asio.hpp>

#include <chorus/io/Stream.h>

namespace chorus
{
    class NetworkStream : public Stream
    {
    public:
        NetworkStream()
            : socket_(nullptr)
        {

        }
        ~NetworkStream() {}

        NetworkStream& operator=(const NetworkStream&) = delete;
        NetworkStream(const NetworkStream&) = delete;

        void setSocket(asio::ip::tcp::socket&& sock)
        {
            socket_ = std::make_unique<asio::ip::tcp::socket>(sock);
        }

    public:
        virtual bool canRead() { return true; }
        virtual bool canSeek() { return false; }
        virtual bool canTimeout() { return true; }
        virtual bool canWrite() { return true; }
        virtual std::int64_t length() { throw std::runtime_error("This property is not currently supported."); }
        virtual std::int64_t& position() { throw std::runtime_error("This property is not currently supported."); }

        virtual void close() = 0;
        virtual void flush() = 0;

        virtual std::int32_t readByte() = 0;
        virtual std::int32_t read(std::byte* buffer, std::int32_t offset, std::int32_t size) = 0;
        virtual std::future<int> readAsync(std::byte* buffer, std::int32_t offset, std::int32_t size) = 0;
        
        virtual std::int64_t seek(std::int64_t offset, SeekOrigin origin) = 0;
        virtual void setLength(std::int64_t value) = 0;
        
        virtual void writeByte(std::byte value) = 0;
        virtual void write(std::byte* buffer, std::int32_t offset, std::int32_t size) = 0;
        virtual std::future<void> writeAsync(std::byte* buffer, std::int32_t offset, std::int32_t size) = 0;
    private:
        std::unique_ptr<asio::ip::tcp::socket> socket_;
    };
}

#endif // CHORUS_NETWORK_TCP_STREAM_H_