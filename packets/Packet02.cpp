#include "StdInc.h"
#include "Packet02.h"

bool Packet02::readPacket(PacketParser *pParser)
{
	std::wstring wstrHashOrUsername = pParser->getString();

	pParser->getPacketHandlerHelper()->onHandshake(wstrHashOrUsername);
	return true;
}

bool Packet02::writePacket()
{
	return false;
}
