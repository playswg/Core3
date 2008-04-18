/*
 *	server/zone/objects/tangible/terminal/vendor/VendorTerminal.h generated by engine3 IDL compiler 0.55
 */

#ifndef VENDORTERMINAL_H_
#define VENDORTERMINAL_H_

#include "engine/orb/DistributedObjectBroker.h"

class Terminal;

class Player;

#include "../Terminal.h"

class VendorTerminal : public Terminal {
protected:
	VendorTerminal();
	VendorTerminal(DistributedObjectServant* obj);
	VendorTerminal(VendorTerminal& ref);

	virtual ~VendorTerminal();

public:
	VendorTerminal* clone();

	int useObject(Player* player);

protected:
	friend class VendorTerminalHelper;
};

class VendorTerminalImplementation;

class VendorTerminalAdapter : public TerminalAdapter {
public:
	VendorTerminalAdapter(VendorTerminalImplementation* impl);

	Packet* invokeMethod(sys::uint32 methid, DistributedMethod* method);

	int useObject(Player* player);

};

class VendorTerminalHelper : public DistributedObjectClassHelper, public Singleton<VendorTerminalHelper> {
	static VendorTerminalHelper* staticInitializer;

public:
	VendorTerminalHelper();

	void finalizeHelper();

	DistributedObject* instantiateObject();

	DistributedObjectAdapter* createAdapter(DistributedObjectServant* obj);

	friend class SingletonWrapper<VendorTerminalHelper>;
};

#include "../TerminalImplementation.h"

class VendorTerminalServant : public TerminalImplementation {
public:
	VendorTerminal* _this;

public:
	VendorTerminalServant(unsigned int objCRC, unsigned long long objid, const unicode& n, const string& tempn, float x, float z, float y, int TerminalType);
	virtual ~VendorTerminalServant();

	void _setStub(DistributedObjectStub* stub);
	DistributedObjectStub* _getStub();

};

#endif /*VENDORTERMINAL_H_*/
