#include "StdInc.h"
#include "PacketParser.h"
#include "Endian.h"
#include "Packets.h"

PacketParser::PacketParser(ePacketSource packetSource)
	: m_packetSource(packetSource), m_iLastCompletePacket(-1)
{
	m_pPacketHandlerHelper = new PacketHandlerHelper(this);
}

PacketParser::~PacketParser()
{
	delete m_pPacketHandlerHelper;
}

ePacketSource PacketParser::getPacketSource()
{
	return m_packetSource;
}

void PacketParser::registerPacketHandler(IPacketHandler *pHandler)
{
	for (std::list<IPacketHandler *>::iterator i = m_lstPacketHandlers.begin(); i != m_lstPacketHandlers.end(); ++i)
	{
		if (*i == pHandler)
		{
			return;
		}
	}

	m_lstPacketHandlers.push_back(pHandler);
}

bool PacketParser::unregisterPacketHandler(IPacketHandler *pHandler)
{
	for (std::list<IPacketHandler *>::iterator i = m_lstPacketHandlers.begin(); i != m_lstPacketHandlers.end(); ++i)
	{
		if (*i == pHandler)
		{
			i = m_lstPacketHandlers.erase(i);
			return true;
		}
	}

	return false;
}

IPacketHandler *PacketParser::getPacketHandlerHelper()
{
	return m_pPacketHandlerHelper;
}

void PacketParser::parseInput(const char *pData, size_t iSize)
{
	m_strBuffer.append(pData, iSize);

	std::string::iterator strip = m_strBuffer.begin();

	for (std::string::iterator i = m_strBuffer.begin(); i != m_strBuffer.end();)
	{
		unsigned char p = (unsigned char) *i;
		if (m_packetSource == CLIENT && p != 0x0A)
			printf("client packet %02X\n", p);
		++i; // skip packet id

		Packet *pack = Packets::createPacket((int) p);
		if (pack != NULL)
		{
			m_itCurrentIterator = i;
			try
			{
				for (std::list<IPacketHandler *>::iterator x = m_lstPacketHandlers.begin(); x != m_lstPacketHandlers.end(); ++x)
				{
					(*x)->m_packetSource = m_packetSource;
				}

				if (pack->readPacket(this))
				{
					strip = i = m_itCurrentIterator;
					m_iLastCompletePacket = (int) p;
				}
				else
				{
					printf("WARNING: Failed to handle packet 0x%02X as %s packet\n", p, m_packetSource == SERVER ? "server" : "client");
				}
				
				for (std::list<IPacketHandler *>::iterator x = m_lstPacketHandlers.begin(); x != m_lstPacketHandlers.end(); ++x)
				{
					(*x)->m_packetSource = UNKNOWN;
				}
			}
			catch (PacketIncompleteNotification)
			{
				// This packet is incomplete, we'll do it next time.
				delete pack;
				break;
			}

			delete pack;
		}
		else
		{
			Exception ex;
			ex.m_iPacketId = p;
			ex.m_iLastCompletePacket = m_iLastCompletePacket;
			throw ex;
		}

		if (i == m_strBuffer.end())
			break;
	}

	if (strip != m_strBuffer.begin())
	{
		m_strBuffer.erase(m_strBuffer.begin(), strip);
	}
}

void PacketParser::getBytes(unsigned char *dest, size_t num)
{
	size_t c = 0;
	for (; c < num && m_itCurrentIterator != m_strBuffer.end(); ++m_itCurrentIterator)
	{
		dest[c++] = *m_itCurrentIterator;
	}

	if (num - c != 0)
	{
		PacketIncompleteNotification e;
		e.m_iMinMissingBytes = num - c;
		throw e;
	}
}

unsigned char PacketParser::getByte()
{
	unsigned char ucByte;
	getBytes(&ucByte, 1);
	return ucByte;
}

short PacketParser::getShort()
{
	short iShort;
	getBytes((unsigned char *)&iShort, 2);
	return ntohs(iShort);
}

int PacketParser::getInt()
{
	int iInt;
	getBytes((unsigned char *)&iInt, 4);
	return ntohl(iInt);
}

__int64 PacketParser::getLong()
{
	__int64 iLong;
	getBytes((unsigned char *)&iLong, 8);
	return ntohll(iLong);
}

std::wstring PacketParser::getString()
{
	short iLength;
	getBytes((unsigned char *)&iLength, 2);
	iLength = ntohs(iLength);

	std::wstring wstrString;
	wstrString.resize(iLength);
	getBytes((unsigned char *)wstrString.c_str(), iLength * 2);

	for (std::wstring::iterator i = wstrString.begin(); i != wstrString.end(); ++i)
	{
		*i = ntohs(*i);
	}
	return wstrString;
}

float PacketParser::getFloat()
{
	float fFloat;
	getBytes((unsigned char *)&fFloat, 4);
	return Endian::bigFloat(fFloat);
}

double PacketParser::getDouble()
{
	double dDouble;
	getBytes((unsigned char *)&dDouble, 8);
	return Endian::bigDouble(dDouble);
}

bool PacketParser::getBool()
{
	unsigned char ucByte;
	getBytes(&ucByte, 1);
	return ucByte != 0;
}

void PacketParser::getMetadata()
{
	unsigned char p = getByte();
	while (p != 0x7F)
	{
		switch (p >> 5)
		{
		case 0:
			getByte();
			break;
		case 1:
			getShort();
			break;
		case 2:
			getInt();
			break;
		case 3:
			getFloat();
			break;
		case 4:
			getString();
			break;
		case 5:
			getShort();
			getByte();
			getShort();
			break;
		case 6:
			getInt();
			getInt();
			getInt();
			break;
		default:
			printf("UNHANDLED metadata type %d\n", p >> 5);
			break;
		}
		p = getByte();
	}
}