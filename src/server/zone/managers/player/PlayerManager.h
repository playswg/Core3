/*
 *	server/zone/managers/player/PlayerManager.h generated by engine3 IDL compiler 0.55
 */

#ifndef PLAYERMANAGER_H_
#define PLAYERMANAGER_H_

#include "engine/orb/DistributedObjectBroker.h"

class GuildManager;

class Player;

class TangibleObject;

class ZoneClient;

class PlayerMap;

#include "engine/service/proto/BaseMessage.h"

class PlayerManager : public DistributedObjectStub {
protected:
	PlayerManager();
	PlayerManager(DistributedObjectServant* obj);
	PlayerManager(PlayerManager& ref);

	virtual ~PlayerManager();

public:
	PlayerManager* clone();

	void stop();

	bool create(Player* player, unsigned int sessionkey);

	bool validateName(string& name);

	BaseMessage* attemptPlayerCreation(Player* player, ZoneClient* client);

	Player* load(unsigned long long charid);

	void unload(Player* player);

	void handleAbortTradeMessage(Player* player);

	void handleAddItemMessage(Player* player, unsigned long long itemID);

	void handleGiveMoneyMessage(Player* player, unsigned int value);

	void handleAcceptTransactionMessage(Player* player);

	void handleUnAcceptTransactionMessage(Player* player);

	void handleVerifyTradeMessage(Player* player);

	void moveItem(Player* sender, Player* receiver, TangibleObject* item);

	void doBankTip(Player* sender, Player* receiver, int tipAmount, bool updateTipTo);

	void doCashTip(Player* sender, Player* receiver, int tipAmount, bool updateTipTo);

	bool modifyOfflineBank(Player* sender, string& receiverName, int creditAmount);

	bool modifyRecipientOfflineBank(string& recipient, int creditAmount);

	void updatePlayerCreditsFromDatabase(Player* player);

	void updatePlayerCreditsToDatabase(Player* player);

	void setGuildManager(GuildManager* gmanager);

	Player* putPlayer(Player* player);

	Player* getPlayer(string& name);

	GuildManager* getGuildManager();

	PlayerMap* getPlayerMap();

protected:
	friend class PlayerManagerHelper;
};

class PlayerManagerImplementation;

class PlayerManagerAdapter : public DistributedObjectAdapter {
public:
	PlayerManagerAdapter(PlayerManagerImplementation* impl);

	Packet* invokeMethod(sys::uint32 methid, DistributedMethod* method);

	void stop();

	bool create(Player* player, unsigned int sessionkey);

	bool validateName(string& name);

	BaseMessage* attemptPlayerCreation(Player* player, ZoneClient* client);

	Player* load(unsigned long long charid);

	void unload(Player* player);

	void handleAbortTradeMessage(Player* player);

	void handleAddItemMessage(Player* player, unsigned long long itemID);

	void handleGiveMoneyMessage(Player* player, unsigned int value);

	void handleAcceptTransactionMessage(Player* player);

	void handleUnAcceptTransactionMessage(Player* player);

	void handleVerifyTradeMessage(Player* player);

	void moveItem(Player* sender, Player* receiver, TangibleObject* item);

	void doBankTip(Player* sender, Player* receiver, int tipAmount, bool updateTipTo);

	void doCashTip(Player* sender, Player* receiver, int tipAmount, bool updateTipTo);

	bool modifyOfflineBank(Player* sender, string& receiverName, int creditAmount);

	bool modifyRecipientOfflineBank(string& recipient, int creditAmount);

	void updatePlayerCreditsFromDatabase(Player* player);

	void updatePlayerCreditsToDatabase(Player* player);

	void setGuildManager(GuildManager* gmanager);

	Player* putPlayer(Player* player);

	Player* getPlayer(string& name);

	GuildManager* getGuildManager();

	PlayerMap* getPlayerMap();

protected:
	string _param0_validateName__string_;
	string _param1_modifyOfflineBank__Player_string_int_;
	string _param0_modifyRecipientOfflineBank__string_int_;
	string _param0_getPlayer__string_;
};

class PlayerManagerHelper : public DistributedObjectClassHelper, public Singleton<PlayerManagerHelper> {
	static PlayerManagerHelper* staticInitializer;

public:
	PlayerManagerHelper();

	void finalizeHelper();

	DistributedObject* instantiateObject();

	DistributedObjectAdapter* createAdapter(DistributedObjectServant* obj);

	friend class SingletonWrapper<PlayerManagerHelper>;
};

class PlayerManagerServant : public DistributedObjectServant {
public:
	PlayerManager* _this;

public:
	PlayerManagerServant();
	virtual ~PlayerManagerServant();

	void _setStub(DistributedObjectStub* stub);
	DistributedObjectStub* _getStub();

};

#endif /*PLAYERMANAGER_H_*/
