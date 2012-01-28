class BotClient;

#ifndef _BOTCLIENT_H
#define _BOTCLIENT_H

#include "VanillaClient.h"
#include "Authentication.h"

class BotClient : public VanillaClient
{
public:
	BotClient(const std::string &strName, ISocketHandler &h);
	~BotClient();

	void setAuthentication(Authentication *pAuth);

protected:
	virtual void onConnected() { }
	void onHandshake(const std::wstring &wstrHash);
	void onKeepAlive(int iRandom);

private:
	void OnConnect();

	std::string m_strName;

	Authentication *m_pAuth;
};

#endif
