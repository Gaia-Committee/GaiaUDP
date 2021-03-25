#include "Receiver.hpp"

namespace Gaia::UDP
{
	/// Default constructor without binding port or address
	Receiver::Receiver(): Socket(Context)

	{}
	/// Construct with binding address
	Receiver::Receiver(const boost::asio::ip::udp::endpoint& address): Socket(Context, address), Bound(true)
	{}

	/// Construct with binding port. Default ip is localhost
	Receiver::Receiver(unsigned short port):
			Socket(Context, boost::asio::ip::udp::endpoint(boost::asio::ip::udp::v4(), port)), Bound(true)
	{}

	/// Bind to a specific address.
	void Receiver:: Bind(const boost::asio::ip::udp::endpoint& address)
	{
		Socket.bind(address);
		Bound = true;
	}

	/// Bind to a port on local host.
	void Receiver::Bind(unsigned short port)
	{
		Socket.bind(boost::asio::ip::udp::endpoint(boost::asio::ip::udp::v4(), port));
		Bound = true;
	}

	/// Start to receive data.
	std::tuple<Endpoint, ByteUtility::BytesBuffer> Receiver::Receive()
	{
		ByteUtility::BytesBuffer buffer;
		Endpoint address;
		buffer.resize(DefaultBufferSize);
		auto length = Socket.receive_from(boost::asio::buffer(buffer.data(), buffer.size()), address);
		buffer.resize(length);
		return std::tuple(address, buffer);
	}

	/// Start to receive a specific amount of data.
	std::tuple<Endpoint, ByteUtility::BytesBuffer> Receiver::Receive(std::size_t length)
	{
		ByteUtility::BytesBuffer buffer;
		Endpoint address;

		buffer.resize(length);

		std::size_t received_size = 0;

		while (received_size < length)
		{
			received_size += Socket.receive_from(
					boost::asio::buffer(buffer.data() + received_size,length - received_size),
					address);
		}

		return std::tuple(address, buffer);
	}
}