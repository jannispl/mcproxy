class ExperienceOrb;

#ifndef _EXPERIENCEORB_H
#define _EXPERIENCEORB_H

#include "../Packet.h"
#include "../PacketParser.h"

class ExperienceOrb : public Packet
{
public:
	bool readPacket(PacketParser *pParser);
	bool writePacket();
};

REGISTER_PACKET(ExperienceOrb);

#endif
