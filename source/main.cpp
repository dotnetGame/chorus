#include <iostream>
#include <spdlog/spdlog.h>
#include <spdlog/sinks/basic_file_sink.h>
#include <uv.h>

#include <prismarine/connection_hub.h>

int main(void)
{
    // Set the default logger to file logger
    auto file_logger = spdlog::basic_logger_mt("basic_logger", "logs.txt");
    spdlog::set_default_logger(file_logger);

    spdlog::debug("server start");

    prismarine::ConnectionHub hub;
    hub.listen("0.0.0.0", 7000);


    spdlog::debug("server stop");
}