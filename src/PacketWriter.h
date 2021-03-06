class PacketWriter;

#ifndef _PACKETWRITER_H
#define _PACKETWRITER_H

#include <string>
#include "TcpClient.h"

#ifdef WIN32
#include "winiconv/iconv.h"
#else
#include <iconv.h>
#endif

class PacketWriter
{
public:
	PacketWriter();
	PacketWriter(size_t iAllocSize);
	~PacketWriter();

	void addBytes(const char *pData, size_t iSize);

	void addByte(uint8_t ucByte);
	void addShort(int16_t iNum);
	void addInt(int32_t iNum);
	void addLong(int64_t iNum);
	void addString(std::string strString);
	void addFloat(float fNum);
	void addDouble(double dNum);
	void addBool(bool bBool);

	void send(TcpClient *pSocket);

private:
	std::string m_strBuffer;

	iconv_t m_iconv;
};

#endif
