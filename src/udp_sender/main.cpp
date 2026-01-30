#include <asio.hpp>
#include <iostream>
#include "UdpSender.h"

int main() {
    asio::io_context io;

    // IP телефону в тій самій Wi-Fi мережі
    UdpSender sender(io, "10.0.2.2", 5000);

    sender.send("Hello Android from C++ 🚀");

    std::cout << "Message sent\n";
    return 0;
}
