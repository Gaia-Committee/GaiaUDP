#include "Endpoint.hpp"

namespace Gaia::UDP
{
	/// Make an endpoint object according the given ip address and port.
	Endpoint MakeEndpoint(const std::string& ip, unsigned int port)
    {
        return boost::asio::ip::udp::endpoint(boost::asio::ip::address::from_string(ip), port);
	}
}