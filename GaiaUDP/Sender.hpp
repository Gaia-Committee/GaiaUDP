#pragma once

#include "Endpoint.hpp"
#include <GaiaByteUtility/GaiaByteUtility.hpp>
#include <boost/asio.hpp>

namespace Gaia::UDP
{
	/**
     * @brief Static class for sending bytes to a remote UDP socket.
     */
	class Sender
	{
	private:
		/**
		 * @brief Acquire the static instance of the socket used for sending packet.
		 * @return Reference of the static instance of socket.
		 */
		static boost::asio::ip::udp::socket& GetSocket();

	public:
		/**
		 * @brief Send a packet to the address marked in it.
		 * @param endpoint Address of the socket which will receive the sent data.
		 * @param data Bytes to send, bytes of amount of BytesAddress.Length will be sent.
		 *             BytesAddress.Length can be changed before this function call to send partial data.
		 */
		static void Send(const Endpoint& endpoint, const ByteUtility::BytesAddress& data);
	};
}