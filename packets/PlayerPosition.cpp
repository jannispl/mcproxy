#include "StdInc.h"
#include "PlayerPosition.h"

bool PlayerPosition::readPacket(PacketParser *pParser)
{
	double dX = pParser->getDouble();
	double dY = pParser->getDouble();
	double dStance = pParser->getDouble();
	double dZ = pParser->getDouble();
	bool bGround = pParser->getBool();
	
	pParser->getPacketHandlerHelper()->onPlayerPosition(dX, dY, dStance, dZ, bGround);
	return true;
}

bool PlayerPosition::writePacket()
{
	return false;
}
