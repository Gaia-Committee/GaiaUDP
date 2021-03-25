#pragma once

#include <boost/asio.hpp>

namespace Gaia::UDP
{
	/// Represents the information of a socket, contains ip, port and other information.
	using Endpoint = boost::asio::ip::udp::endpoint;

	/**
	 * @brief Make an endpoint object according the given ip address and port.
	 * @param ip Text of IP. Be cautious that hostname such as 'localhost' is not allowed here.
	 * @param port Port number.
	 * @return Endpoint object of the given IP and port.
	 */
	Endpoint MakeEndpoint(const std::string& ip, unsigned int port);
}
