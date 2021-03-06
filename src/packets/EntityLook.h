class EntityLook;

#ifndef _ENTITYLOOK_H
#define _ENTITYLOOK_H

#include "../Packet.h"
#include "../PacketParser.h"

class EntityLook : public Packet
{
public:
	bool readPacket(PacketParser *pParser);
	bool writePacket(PacketWriter *pWriter, int iEntity, char cYaw, char cPitch);
};

REGISTER_PACKET(EntityLook);

#endif
