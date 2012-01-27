class IncrementStatistic;

#ifndef _INCREMENTSTATISTIC_H
#define _INCREMENTSTATISTIC_H

#include "../Packet.h"
#include "../PacketParser.h"

class IncrementStatistic : public Packet
{
public:
	bool readPacket(PacketParser *pParser);
	bool writePacket();
};

REGISTER_PACKET(IncrementStatistic);

#endif
