#include "StdInc.h"
#include "WindowItems.h"
#include "../utils/MinecraftUtils.h"
#include <vector>

bool WindowItems::readPacket(PacketParser *pParser)
{
	unsigned char ucWindow = pParser->getByte();
	short iCount = pParser->getShort();

	for (short i = 0; i < iCount; ++i)
	{
		short iItem = pParser->getShort();

		if (iItem != -1)
		{
			unsigned char ucQty = pParser->getByte();
			short iUses = pParser->getShort();

			if (MinecraftUtils::isEnchantable(iItem))
			{
				short iSize = pParser->getShort();
				if (iSize != -1)
				{
					std::vector<unsigned char> vecBytes(iSize);
					pParser->getBytes((unsigned char *)&vecBytes[0], iSize);
				}
			}
		}
		else
		{
			// empty slot
		}
	}
	
	pParser->getPacketHandlerHelper()->onWindowItems(ucWindow, iCount);
	return true;
}

bool WindowItems::writePacket(PacketWriter *pWriter)
{
	return false;
}
