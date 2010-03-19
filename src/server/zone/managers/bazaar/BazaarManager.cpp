/*
 *	server/zone/managers/bazaar/BazaarManager.cpp generated by engine3 IDL compiler 0.60
 */

#include "BazaarManager.h"

#include "server/zone/ZoneServer.h"

#include "server/zone/managers/object/ObjectManager.h"

#include "server/zone/ZoneServer.h"

#include "server/zone/objects/player/PlayerCreature.h"

#include "server/zone/managers/bazaar/BazaarAuctionsMap.h"

#include "server/zone/objects/tangible/terminal/bazaar/BazaarTerminal.h"

#include "server/zone/objects/tangible/terminal/bazaar/AuctionItem.h"

#include "server/zone/objects/scene/SceneObject.h"

/*
 *	BazaarManagerStub
 */

BazaarManager::BazaarManager(ZoneServer* server) : ManagedObject(DummyConstructorParameter::instance()) {
	_impl = new BazaarManagerImplementation(server);
	_impl->_setStub(this);
}

BazaarManager::BazaarManager(DummyConstructorParameter* param) : ManagedObject(param) {
}

BazaarManager::~BazaarManager() {
}


void BazaarManager::initialize() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 6);

		method.executeWithVoidReturn();
	} else
		((BazaarManagerImplementation*) _impl)->initialize();
}

void BazaarManager::checkAuctions() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 7);

		method.executeWithVoidReturn();
	} else
		((BazaarManagerImplementation*) _impl)->checkAuctions();
}

void BazaarManager::addSaleItem(PlayerCreature* player, unsigned long long objectid, unsigned long long bazaarid, const UnicodeString& description, int price, unsigned int duration, bool auction) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 8);
		method.addObjectParameter(player);
		method.addUnsignedLongParameter(objectid);
		method.addUnsignedLongParameter(bazaarid);
		method.addUnicodeParameter(description);
		method.addSignedIntParameter(price);
		method.addUnsignedIntParameter(duration);
		method.addBooleanParameter(auction);

		method.executeWithVoidReturn();
	} else
		((BazaarManagerImplementation*) _impl)->addSaleItem(player, objectid, bazaarid, description, price, duration, auction);
}

AuctionItem* BazaarManager::createAuctionItem(PlayerCreature* player, SceneObject* objectToSell, BazaarTerminal* terminal, const UnicodeString& description, int price, unsigned int duration, bool auction) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 9);
		method.addObjectParameter(player);
		method.addObjectParameter(objectToSell);
		method.addObjectParameter(terminal);
		method.addUnicodeParameter(description);
		method.addSignedIntParameter(price);
		method.addUnsignedIntParameter(duration);
		method.addBooleanParameter(auction);

		return (AuctionItem*) method.executeWithObjectReturn();
	} else
		return ((BazaarManagerImplementation*) _impl)->createAuctionItem(player, objectToSell, terminal, description, price, duration, auction);
}

int BazaarManager::checkSaleItem(PlayerCreature* player, SceneObject* object, int price) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 10);
		method.addObjectParameter(player);
		method.addObjectParameter(object);
		method.addSignedIntParameter(price);

		return method.executeWithSignedIntReturn();
	} else
		return ((BazaarManagerImplementation*) _impl)->checkSaleItem(player, object, price);
}

void BazaarManager::getItemAttributes(PlayerCreature* player, unsigned long long objectid) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 11);
		method.addObjectParameter(player);
		method.addUnsignedLongParameter(objectid);

		method.executeWithVoidReturn();
	} else
		((BazaarManagerImplementation*) _impl)->getItemAttributes(player, objectid);
}

void BazaarManager::getBazaarData(PlayerCreature* player, int extent, unsigned long long bazaarObjectid, int screen, unsigned int category, int count, int offset) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 12);
		method.addObjectParameter(player);
		method.addSignedIntParameter(extent);
		method.addUnsignedLongParameter(bazaarObjectid);
		method.addSignedIntParameter(screen);
		method.addUnsignedIntParameter(category);
		method.addSignedIntParameter(count);
		method.addSignedIntParameter(offset);

		method.executeWithVoidReturn();
	} else
		((BazaarManagerImplementation*) _impl)->getBazaarData(player, extent, bazaarObjectid, screen, category, count, offset);
}

void BazaarManager::getAllBazaarData(PlayerCreature* player, BazaarTerminal* terminal, int screen, unsigned int category, int count, int offset) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 13);
		method.addObjectParameter(player);
		method.addObjectParameter(terminal);
		method.addSignedIntParameter(screen);
		method.addUnsignedIntParameter(category);
		method.addSignedIntParameter(count);
		method.addSignedIntParameter(offset);

		method.executeWithVoidReturn();
	} else
		((BazaarManagerImplementation*) _impl)->getAllBazaarData(player, terminal, screen, category, count, offset);
}

void BazaarManager::getPlanetBazaarData(PlayerCreature* player, BazaarTerminal* terminal, int screen, unsigned int category, int count, int offset) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 14);
		method.addObjectParameter(player);
		method.addObjectParameter(terminal);
		method.addSignedIntParameter(screen);
		method.addUnsignedIntParameter(category);
		method.addSignedIntParameter(count);
		method.addSignedIntParameter(offset);

		method.executeWithVoidReturn();
	} else
		((BazaarManagerImplementation*) _impl)->getPlanetBazaarData(player, terminal, screen, category, count, offset);
}

void BazaarManager::getRegionBazaarData(PlayerCreature* player, BazaarTerminal* terminal, int screen, unsigned int category, int count, int offset) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 15);
		method.addObjectParameter(player);
		method.addObjectParameter(terminal);
		method.addSignedIntParameter(screen);
		method.addUnsignedIntParameter(category);
		method.addSignedIntParameter(count);
		method.addSignedIntParameter(offset);

		method.executeWithVoidReturn();
	} else
		((BazaarManagerImplementation*) _impl)->getRegionBazaarData(player, terminal, screen, category, count, offset);
}

int BazaarManager::checkRetrieve(PlayerCreature* player, unsigned long long objectIdToRetrieve, BazaarTerminal* terminal) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 16);
		method.addObjectParameter(player);
		method.addUnsignedLongParameter(objectIdToRetrieve);
		method.addObjectParameter(terminal);

		return method.executeWithSignedIntReturn();
	} else
		return ((BazaarManagerImplementation*) _impl)->checkRetrieve(player, objectIdToRetrieve, terminal);
}

void BazaarManager::retrieveItem(PlayerCreature* player, unsigned long long objectid, unsigned long long bazaarid) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 17);
		method.addObjectParameter(player);
		method.addUnsignedLongParameter(objectid);
		method.addUnsignedLongParameter(bazaarid);

		method.executeWithVoidReturn();
	} else
		((BazaarManagerImplementation*) _impl)->retrieveItem(player, objectid, bazaarid);
}

void BazaarManager::buyItem(PlayerCreature* player, unsigned long long objectid, int price1, int price2) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 18);
		method.addObjectParameter(player);
		method.addUnsignedLongParameter(objectid);
		method.addSignedIntParameter(price1);
		method.addSignedIntParameter(price2);

		method.executeWithVoidReturn();
	} else
		((BazaarManagerImplementation*) _impl)->buyItem(player, objectid, price1, price2);
}

void BazaarManager::doAuctionBid(PlayerCreature* player, AuctionItem* item, int price1, int price2) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 19);
		method.addObjectParameter(player);
		method.addObjectParameter(item);
		method.addSignedIntParameter(price1);
		method.addSignedIntParameter(price2);

		method.executeWithVoidReturn();
	} else
		((BazaarManagerImplementation*) _impl)->doAuctionBid(player, item, price1, price2);
}

void BazaarManager::doInstantBuy(PlayerCreature* player, AuctionItem* item, int price1, int price2) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 20);
		method.addObjectParameter(player);
		method.addObjectParameter(item);
		method.addSignedIntParameter(price1);
		method.addSignedIntParameter(price2);

		method.executeWithVoidReturn();
	} else
		((BazaarManagerImplementation*) _impl)->doInstantBuy(player, item, price1, price2);
}

int BazaarManager::checkBidAuction(PlayerCreature* player, AuctionItem* item, int price1, int price2) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 21);
		method.addObjectParameter(player);
		method.addObjectParameter(item);
		method.addSignedIntParameter(price1);
		method.addSignedIntParameter(price2);

		return method.executeWithSignedIntReturn();
	} else
		return ((BazaarManagerImplementation*) _impl)->checkBidAuction(player, item, price1, price2);
}

AuctionQueryHeadersResponseMessage* BazaarManager::fillAuctionQueryHeadersResponseMessage(PlayerCreature* player, VectorMap<unsigned long long, ManagedReference<AuctionItem > >* items, int screen, unsigned int category, int count, int offset) {
	if (_impl == NULL) {
		throw ObjectNotLocalException(this);

	} else
		return ((BazaarManagerImplementation*) _impl)->fillAuctionQueryHeadersResponseMessage(player, items, screen, category, count, offset);
}

/*
 *	BazaarManagerImplementation
 */

BazaarManagerImplementation::BazaarManagerImplementation(DummyConstructorParameter* param) : ManagedObjectImplementation(param) {
	_initializeImplementation();
}

BazaarManagerImplementation::~BazaarManagerImplementation() {
}


void BazaarManagerImplementation::finalize() {
}

void BazaarManagerImplementation::_initializeImplementation() {
	_setClassHelper(BazaarManagerHelper::instance());

	_serializationHelperMethod();
}

void BazaarManagerImplementation::_setStub(DistributedObjectStub* stub) {
	_this = (BazaarManager*) stub;
	ManagedObjectImplementation::_setStub(stub);
}

DistributedObjectStub* BazaarManagerImplementation::_getStub() {
	return _this;
}

BazaarManagerImplementation::operator const BazaarManager*() {
	return _this;
}

void BazaarManagerImplementation::lock(bool doLock) {
	_this->lock(doLock);
}

void BazaarManagerImplementation::lock(ManagedObject* obj) {
	_this->lock(obj);
}

void BazaarManagerImplementation::rlock(bool doLock) {
	_this->rlock(doLock);
}

void BazaarManagerImplementation::wlock(bool doLock) {
	_this->wlock(doLock);
}

void BazaarManagerImplementation::wlock(ManagedObject* obj) {
	_this->wlock(obj);
}

void BazaarManagerImplementation::unlock(bool doLock) {
	_this->unlock(doLock);
}

void BazaarManagerImplementation::runlock(bool doLock) {
	_this->runlock(doLock);
}

void BazaarManagerImplementation::_serializationHelperMethod() {
	ManagedObjectImplementation::_serializationHelperMethod();

	_setClassName("BazaarManager");

	addSerializableVariable("auctionMap", &auctionMap);
	addSerializableVariable("zoneServer", &zoneServer);
}

BazaarManagerImplementation::BazaarManagerImplementation(ZoneServer* server) {
	_initializeImplementation();
	// server/zone/managers/bazaar/BazaarManager.idl(74):  		zoneServer = server;
	zoneServer = server;
	// server/zone/managers/bazaar/BazaarManager.idl(76):  		Logger.setLoggingName("BazaarManager");
	Logger::setLoggingName("BazaarManager");
}

/*
 *	BazaarManagerAdapter
 */

BazaarManagerAdapter::BazaarManagerAdapter(BazaarManagerImplementation* obj) : ManagedObjectAdapter(obj) {
}

Packet* BazaarManagerAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	Packet* resp = new MethodReturnMessage(0);

	switch (methid) {
	case 6:
		initialize();
		break;
	case 7:
		checkAuctions();
		break;
	case 8:
		addSaleItem((PlayerCreature*) inv->getObjectParameter(), inv->getUnsignedLongParameter(), inv->getUnsignedLongParameter(), inv->getUnicodeParameter(_param3_addSaleItem__PlayerCreature_long_long_UnicodeString_int_int_bool_), inv->getSignedIntParameter(), inv->getUnsignedIntParameter(), inv->getBooleanParameter());
		break;
	case 9:
		resp->insertLong(createAuctionItem((PlayerCreature*) inv->getObjectParameter(), (SceneObject*) inv->getObjectParameter(), (BazaarTerminal*) inv->getObjectParameter(), inv->getUnicodeParameter(_param3_createAuctionItem__PlayerCreature_SceneObject_BazaarTerminal_UnicodeString_int_int_bool_), inv->getSignedIntParameter(), inv->getUnsignedIntParameter(), inv->getBooleanParameter())->_getObjectID());
		break;
	case 10:
		resp->insertSignedInt(checkSaleItem((PlayerCreature*) inv->getObjectParameter(), (SceneObject*) inv->getObjectParameter(), inv->getSignedIntParameter()));
		break;
	case 11:
		getItemAttributes((PlayerCreature*) inv->getObjectParameter(), inv->getUnsignedLongParameter());
		break;
	case 12:
		getBazaarData((PlayerCreature*) inv->getObjectParameter(), inv->getSignedIntParameter(), inv->getUnsignedLongParameter(), inv->getSignedIntParameter(), inv->getUnsignedIntParameter(), inv->getSignedIntParameter(), inv->getSignedIntParameter());
		break;
	case 13:
		getAllBazaarData((PlayerCreature*) inv->getObjectParameter(), (BazaarTerminal*) inv->getObjectParameter(), inv->getSignedIntParameter(), inv->getUnsignedIntParameter(), inv->getSignedIntParameter(), inv->getSignedIntParameter());
		break;
	case 14:
		getPlanetBazaarData((PlayerCreature*) inv->getObjectParameter(), (BazaarTerminal*) inv->getObjectParameter(), inv->getSignedIntParameter(), inv->getUnsignedIntParameter(), inv->getSignedIntParameter(), inv->getSignedIntParameter());
		break;
	case 15:
		getRegionBazaarData((PlayerCreature*) inv->getObjectParameter(), (BazaarTerminal*) inv->getObjectParameter(), inv->getSignedIntParameter(), inv->getUnsignedIntParameter(), inv->getSignedIntParameter(), inv->getSignedIntParameter());
		break;
	case 16:
		resp->insertSignedInt(checkRetrieve((PlayerCreature*) inv->getObjectParameter(), inv->getUnsignedLongParameter(), (BazaarTerminal*) inv->getObjectParameter()));
		break;
	case 17:
		retrieveItem((PlayerCreature*) inv->getObjectParameter(), inv->getUnsignedLongParameter(), inv->getUnsignedLongParameter());
		break;
	case 18:
		buyItem((PlayerCreature*) inv->getObjectParameter(), inv->getUnsignedLongParameter(), inv->getSignedIntParameter(), inv->getSignedIntParameter());
		break;
	case 19:
		doAuctionBid((PlayerCreature*) inv->getObjectParameter(), (AuctionItem*) inv->getObjectParameter(), inv->getSignedIntParameter(), inv->getSignedIntParameter());
		break;
	case 20:
		doInstantBuy((PlayerCreature*) inv->getObjectParameter(), (AuctionItem*) inv->getObjectParameter(), inv->getSignedIntParameter(), inv->getSignedIntParameter());
		break;
	case 21:
		resp->insertSignedInt(checkBidAuction((PlayerCreature*) inv->getObjectParameter(), (AuctionItem*) inv->getObjectParameter(), inv->getSignedIntParameter(), inv->getSignedIntParameter()));
		break;
	default:
		return NULL;
	}

	return resp;
}

void BazaarManagerAdapter::initialize() {
	((BazaarManagerImplementation*) impl)->initialize();
}

void BazaarManagerAdapter::checkAuctions() {
	((BazaarManagerImplementation*) impl)->checkAuctions();
}

void BazaarManagerAdapter::addSaleItem(PlayerCreature* player, unsigned long long objectid, unsigned long long bazaarid, const UnicodeString& description, int price, unsigned int duration, bool auction) {
	((BazaarManagerImplementation*) impl)->addSaleItem(player, objectid, bazaarid, description, price, duration, auction);
}

AuctionItem* BazaarManagerAdapter::createAuctionItem(PlayerCreature* player, SceneObject* objectToSell, BazaarTerminal* terminal, const UnicodeString& description, int price, unsigned int duration, bool auction) {
	return ((BazaarManagerImplementation*) impl)->createAuctionItem(player, objectToSell, terminal, description, price, duration, auction);
}

int BazaarManagerAdapter::checkSaleItem(PlayerCreature* player, SceneObject* object, int price) {
	return ((BazaarManagerImplementation*) impl)->checkSaleItem(player, object, price);
}

void BazaarManagerAdapter::getItemAttributes(PlayerCreature* player, unsigned long long objectid) {
	((BazaarManagerImplementation*) impl)->getItemAttributes(player, objectid);
}

void BazaarManagerAdapter::getBazaarData(PlayerCreature* player, int extent, unsigned long long bazaarObjectid, int screen, unsigned int category, int count, int offset) {
	((BazaarManagerImplementation*) impl)->getBazaarData(player, extent, bazaarObjectid, screen, category, count, offset);
}

void BazaarManagerAdapter::getAllBazaarData(PlayerCreature* player, BazaarTerminal* terminal, int screen, unsigned int category, int count, int offset) {
	((BazaarManagerImplementation*) impl)->getAllBazaarData(player, terminal, screen, category, count, offset);
}

void BazaarManagerAdapter::getPlanetBazaarData(PlayerCreature* player, BazaarTerminal* terminal, int screen, unsigned int category, int count, int offset) {
	((BazaarManagerImplementation*) impl)->getPlanetBazaarData(player, terminal, screen, category, count, offset);
}

void BazaarManagerAdapter::getRegionBazaarData(PlayerCreature* player, BazaarTerminal* terminal, int screen, unsigned int category, int count, int offset) {
	((BazaarManagerImplementation*) impl)->getRegionBazaarData(player, terminal, screen, category, count, offset);
}

int BazaarManagerAdapter::checkRetrieve(PlayerCreature* player, unsigned long long objectIdToRetrieve, BazaarTerminal* terminal) {
	return ((BazaarManagerImplementation*) impl)->checkRetrieve(player, objectIdToRetrieve, terminal);
}

void BazaarManagerAdapter::retrieveItem(PlayerCreature* player, unsigned long long objectid, unsigned long long bazaarid) {
	((BazaarManagerImplementation*) impl)->retrieveItem(player, objectid, bazaarid);
}

void BazaarManagerAdapter::buyItem(PlayerCreature* player, unsigned long long objectid, int price1, int price2) {
	((BazaarManagerImplementation*) impl)->buyItem(player, objectid, price1, price2);
}

void BazaarManagerAdapter::doAuctionBid(PlayerCreature* player, AuctionItem* item, int price1, int price2) {
	((BazaarManagerImplementation*) impl)->doAuctionBid(player, item, price1, price2);
}

void BazaarManagerAdapter::doInstantBuy(PlayerCreature* player, AuctionItem* item, int price1, int price2) {
	((BazaarManagerImplementation*) impl)->doInstantBuy(player, item, price1, price2);
}

int BazaarManagerAdapter::checkBidAuction(PlayerCreature* player, AuctionItem* item, int price1, int price2) {
	return ((BazaarManagerImplementation*) impl)->checkBidAuction(player, item, price1, price2);
}

/*
 *	BazaarManagerHelper
 */

BazaarManagerHelper* BazaarManagerHelper::staticInitializer = BazaarManagerHelper::instance();

BazaarManagerHelper::BazaarManagerHelper() {
	className = "BazaarManager";

	DistributedObjectBroker::instance()->registerClass(className, this);
}

void BazaarManagerHelper::finalizeHelper() {
	BazaarManagerHelper::finalize();
}

DistributedObject* BazaarManagerHelper::instantiateObject() {
	return new BazaarManager(DummyConstructorParameter::instance());
}

DistributedObjectServant* BazaarManagerHelper::instantiateServant() {
	return new BazaarManagerImplementation(DummyConstructorParameter::instance());
}

DistributedObjectAdapter* BazaarManagerHelper::createAdapter(DistributedObjectStub* obj) {
	DistributedObjectAdapter* adapter = new BazaarManagerAdapter((BazaarManagerImplementation*) obj->_getImplementation());

	obj->_setClassName(className);
	obj->_setClassHelper(this);

	adapter->setStub(obj);

	return adapter;
}

