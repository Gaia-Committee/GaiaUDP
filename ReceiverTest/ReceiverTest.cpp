#include <gtest/gtest.h>
#include <GaiaUDP/GaiaUDP.hpp>
#include <iostream>

using namespace Gaia;

int main()
{
	UDP::Receiver receiver {8000};
	const auto& [address, data] = receiver.Receive();

	const auto& data_string = ByteUtility::BytesPrinter::PrintToString(ByteUtility::ToBytesAddress(data));

	std::cout << data_string << std::endl;

	ByteUtility::BytesAccessor accessor;
	accessor.SourceBytes = ByteUtility::ToBytesAddress(data);
	std::cout << "Number1: " << accessor.Access<int>(0);
	std::cout << "Number2: " << accessor.Access<int>(4);
	std::cout << "Number3: " << accessor.Access<int>(8);

	return 0;
}