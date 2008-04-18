/*
 *	server/zone/ZoneClient.h generated by engine3 IDL compiler 0.55
 */

#ifndef ZONECLIENT_H_
#define ZONECLIENT_H_

#include "engine/orb/DistributedObjectBroker.h"

#include "engine/service/proto/BaseMessage.h"

#include "engine/service/proto/StandaloneBaseMessage.h"

class Player;

class ZoneClient : public DistributedObjectStub {
protected:
	ZoneClient();
	ZoneClient(DistributedObjectServant* obj);
	ZoneClient(ZoneClient& ref);

	virtual ~ZoneClient();

public:
	ZoneClient* clone();

	void disconnect(bool doLock = true);

	void closeConnection(bool doLock = true);

	void sendMessage(BaseMessage* msg);

	void sendMessage(StandaloneBaseMessage* msg);

	void resetPacketCheckupTime();

	void balancePacketCheckupTime();

	void info(const string& msg, bool foredLog = false);

	void setPlayer(Player* player);

	Player* getPlayer();

	bool isAvailable();

	string& getAddress();

	unsigned int getSessionKey();

protected:
	string _return_getAddress;


	friend class ZoneClientHelper;
};

class ZoneClientImplementation;

class ZoneClientAdapter : public DistributedObjectAdapter {
public:
	ZoneClientAdapter(ZoneClientImplementation* impl);

	Packet* invokeMethod(sys::uint32 methid, DistributedMethod* method);

	void disconnect(bool doLock);

	void closeConnection(bool doLock);

	void sendMessage(BaseMessage* msg);

	void sendMessage(StandaloneBaseMessage* msg);

	void resetPacketCheckupTime();

	void balancePacketCheckupTime();

	void info(const string& msg, bool foredLog);

	void setPlayer(Player* player);

	Player* getPlayer();

	bool isAvailable();

	string& getAddress();

	unsigned int getSessionKey();

protected:
	string _param0_info__string_bool_;
};

class ZoneClientHelper : public DistributedObjectClassHelper, public Singleton<ZoneClientHelper> {
	static ZoneClientHelper* staticInitializer;

public:
	ZoneClientHelper();

	void finalizeHelper();

	DistributedObject* instantiateObject();

	DistributedObjectAdapter* createAdapter(DistributedObjectServant* obj);

	friend class SingletonWrapper<ZoneClientHelper>;
};

class ZoneClientServant : public DistributedObjectServant {
public:
	ZoneClient* _this;

public:
	ZoneClientServant();
	virtual ~ZoneClientServant();

	void _setStub(DistributedObjectStub* stub);
	DistributedObjectStub* _getStub();

};

#endif /*ZONECLIENT_H_*/
