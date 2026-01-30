#pragma once
#include <asio.hpp>
#include <string>

class UdpSender {
public:
    UdpSender(asio::io_context& io,
              const std::string& ip,
              uint16_t port);

    void send(const std::string& message);

private:
    asio::ip::udp::socket socket_;
    asio::ip::udp::endpoint target_;
};
