/*
 *	server/zone/managers/bazaar/BazaarAuctionsMap.h generated by engine3 IDL compiler 0.60
 */

#ifndef BAZAARAUCTIONSMAP_H_
#define BAZAARAUCTIONSMAP_H_

#include "engine/orb/DistributedObjectBroker.h"

#include "engine/core/ManagedReference.h"

#include "engine/core/ManagedWeakReference.h"

namespace server {
namespace zone {
namespace objects {
namespace tangible {
namespace terminal {
namespace bazaar {

class AuctionItem;

} // namespace bazaar
} // namespace terminal
} // namespace tangible
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::tangible::terminal::bazaar;

#include "engine/core/ManagedObject.h"

#include "system/util/VectorMap.h"

namespace server {
namespace zone {
namespace managers {
namespace bazaar {

class BazaarAuctionsMap : public ManagedObject {
public:
	BazaarAuctionsMap();

	int getAuctionCount();

	bool containsAuction(unsigned long long objectID);

	void addAuction(unsigned long long objectID, AuctionItem* item);

	int getPlayerAuctionCount(unsigned long long objectID);

	void dropAuction(unsigned long long objectID);

	AuctionItem* getAuction(unsigned long long objectID);

	AuctionItem* getAuction(int index);

	VectorMap<unsigned long long, ManagedReference<AuctionItem > >* getAuctions();

protected:
	BazaarAuctionsMap(DummyConstructorParameter* param);

	virtual ~BazaarAuctionsMap();

	friend class BazaarAuctionsMapHelper;
};

} // namespace bazaar
} // namespace managers
} // namespace zone
} // namespace server

using namespace server::zone::managers::bazaar;

namespace server {
namespace zone {
namespace managers {
namespace bazaar {

class BazaarAuctionsMapImplementation : public ManagedObjectImplementation {
protected:
	VectorMap<unsigned long long, ManagedReference<AuctionItem > > auctions;

	VectorMap<unsigned long long, int> playerAuctionCount;

public:
	BazaarAuctionsMapImplementation();

	BazaarAuctionsMapImplementation(DummyConstructorParameter* param);

	int getAuctionCount();

	bool containsAuction(unsigned long long objectID);

	void addAuction(unsigned long long objectID, AuctionItem* item);

	int getPlayerAuctionCount(unsigned long long objectID);

	void dropAuction(unsigned long long objectID);

	AuctionItem* getAuction(unsigned long long objectID);

	AuctionItem* getAuction(int index);

	VectorMap<unsigned long long, ManagedReference<AuctionItem > >* getAuctions();

	BazaarAuctionsMap* _this;

	operator const BazaarAuctionsMap*();

	DistributedObjectStub* _getStub();
protected:
	virtual ~BazaarAuctionsMapImplementation();

	void finalize();

	void _initializeImplementation();

	void _setStub(DistributedObjectStub* stub);

	void lock(bool doLock = true);

	void lock(ManagedObject* obj);

	void rlock(bool doLock = true);

	void wlock(bool doLock = true);

	void wlock(ManagedObject* obj);

	void unlock(bool doLock = true);

	void runlock(bool doLock = true);

	void _serializationHelperMethod();

	friend class BazaarAuctionsMap;
};

class BazaarAuctionsMapAdapter : public ManagedObjectAdapter {
public:
	BazaarAuctionsMapAdapter(BazaarAuctionsMapImplementation* impl);

	Packet* invokeMethod(sys::uint32 methid, DistributedMethod* method);

	int getAuctionCount();

	bool containsAuction(unsigned long long objectID);

	void addAuction(unsigned long long objectID, AuctionItem* item);

	int getPlayerAuctionCount(unsigned long long objectID);

	void dropAuction(unsigned long long objectID);

	AuctionItem* getAuction(unsigned long long objectID);

	AuctionItem* getAuction(int index);

};

class BazaarAuctionsMapHelper : public DistributedObjectClassHelper, public Singleton<BazaarAuctionsMapHelper> {
	static BazaarAuctionsMapHelper* staticInitializer;

public:
	BazaarAuctionsMapHelper();

	void finalizeHelper();

	DistributedObject* instantiateObject();

	DistributedObjectServant* instantiateServant();

	DistributedObjectAdapter* createAdapter(DistributedObjectStub* obj);

	friend class Singleton<BazaarAuctionsMapHelper>;
};

} // namespace bazaar
} // namespace managers
} // namespace zone
} // namespace server

using namespace server::zone::managers::bazaar;

#endif /*BAZAARAUCTIONSMAP_H_*/
