
#include "UdpSender.h"

using asio::ip::udp;

UdpSender::UdpSender(asio::io_context& io,
                     const std::string& ip,
                     uint16_t port)
    : socket_(io, udp::v4()),
      target_(asio::ip::make_address(ip), port) {}

void UdpSender::send(const std::string& message) {
    socket_.send_to(asio::buffer(message), target_);
}
