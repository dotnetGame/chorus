#ifndef CHORUS_IO_STREAM_H_
#define CHORUS_IO_STREAM_H_

#include <string>
#include <future>
#include <cstdint>

namespace chorus
{
    enum class SeekOrigin
    {
        Begin,
        Current,
        End
    };

    class Stream
    {
    public:
        virtual bool canRead() = 0;
        virtual bool canSeek() = 0;
        virtual bool canTimeout() = 0;
        virtual bool canWrite() = 0;
        virtual std::int64_t length() = 0;
        virtual std::int64_t& position() = 0;

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
    };
}

#endif // CHORUS_IO_STREAM_H_