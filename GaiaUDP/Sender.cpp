#include "Sender.hpp"

namespace Gaia::UDP
{
	/// Acquire the socket for sending packet.
	boost::asio::ip::udp::socket& Sender::GetSocket()
	{
        static std::unique_ptr<boost::asio::io_context> context_instance;
        static std::unique_ptr<boost::asio::ip::udp::socket> socket_instance;

        if (!socket_instance)
        {
            context_instance = std::make_unique<boost::asio::io_context>();
            socket_instance = std::make_unique<boost::asio::ip::udp::socket>(*context_instance);
            socket_instance->open(boost::asio::ip::udp::v4());
        }

        return *socket_instance;
	}

    /// Static function for sending packet that has been constructed.
    void Sender::Send(const Endpoint& endpoint, const ByteUtility::BytesAddress& data)
    {
        // Send the data of packet to the packet's destination
        GetSocket().send_to(boost::asio::buffer(data.Data, data.Length), endpoint);
    }
}