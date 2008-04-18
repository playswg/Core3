/*
 *	server/zone/objects/tangible/inventory/CreatureInventory.cpp generated by engine3 IDL compiler 0.55
 */

#include "../Container.h"

#include "CreatureInventory.h"

#include "CreatureInventoryImplementation.h"

/*
 *	CreatureInventoryStub
 */

CreatureInventory::CreatureInventory() : Container(NULL) {
}

CreatureInventory::CreatureInventory(DistributedObjectServant* obj) : Container(obj) {
}

CreatureInventory::CreatureInventory(CreatureInventory& ref) : Container(ref) {
}

CreatureInventory::~CreatureInventory() {
}

CreatureInventory* CreatureInventory::clone() {
	return new CreatureInventory(*this);
}


/*
 *	CreatureInventoryAdapter
 */

CreatureInventoryAdapter::CreatureInventoryAdapter(CreatureInventoryImplementation* obj) : ContainerAdapter(obj) {
}

Packet* CreatureInventoryAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	Packet* resp = new MethodReturnMessage(0);

	switch (methid) {
	default:
		return NULL;
	}

	return resp;
}

/*
 *	CreatureInventoryHelper
 */

CreatureInventoryHelper* CreatureInventoryHelper::staticInitializer = CreatureInventoryHelper::instance();

CreatureInventoryHelper::CreatureInventoryHelper() {
	className = "CreatureInventory";

	DistributedObjectBroker::instance()->registerClass(className, this);
}

void CreatureInventoryHelper::finalizeHelper() {
	CreatureInventoryHelper::finalize();
}

DistributedObject* CreatureInventoryHelper::instantiateObject() {
	return new CreatureInventory();
}

DistributedObjectAdapter* CreatureInventoryHelper::createAdapter(DistributedObjectServant* obj) {
	DistributedObjectAdapter* adapter = new CreatureInventoryAdapter((CreatureInventoryImplementation*) obj);

	DistributedObjectStub* stub = new CreatureInventory(obj);
	stub->_setClassName(className);
	stub->_setClassHelper(this);

	adapter->setStub(stub);

	obj->_setStub(stub);

	return adapter;
}

/*
 *	CreatureInventoryServant
 */

CreatureInventoryServant::CreatureInventoryServant(unsigned long long oid) : ContainerImplementation(oid) {
	_classHelper = CreatureInventoryHelper::instance();
}

CreatureInventoryServant::~CreatureInventoryServant() {
}

void CreatureInventoryServant::_setStub(DistributedObjectStub* stub) {
	_this = (CreatureInventory*) stub;
	ContainerServant::_setStub(stub);
}

DistributedObjectStub* CreatureInventoryServant::_getStub() {
	return _this;
}

