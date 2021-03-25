#include <gtest/gtest.h>

#include <GaiaUDP/GaiaUDP.hpp>

using namespace Gaia;

int main()
{
	ByteUtility::BytesBuilder builder;
	builder.AddValue(3);
	builder.AddValue(4);
	builder.AddValue(5);

	UDP::Sender::Send(
			UDP::MakeEndpoint("127.0.0.1", 8000),
			ByteUtility::ToBytesAddress(builder.BytesData));

	return 0;
}
