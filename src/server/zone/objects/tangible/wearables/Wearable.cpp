/*
 *	server/zone/objects/tangible/wearables/Wearable.cpp generated by engine3 IDL compiler 0.55
 */

#include "../TangibleObject.h"

#include "Wearable.h"

#include "WearableImplementation.h"

/*
 *	WearableStub
 */

Wearable::Wearable() : TangibleObject(NULL) {
}

Wearable::Wearable(DistributedObjectServant* obj) : TangibleObject(obj) {
}

Wearable::Wearable(Wearable& ref) : TangibleObject(ref) {
}

Wearable::~Wearable() {
}

Wearable* Wearable::clone() {
	return new Wearable(*this);
}


/*
 *	WearableAdapter
 */

WearableAdapter::WearableAdapter(WearableImplementation* obj) : TangibleObjectAdapter(obj) {
}

Packet* WearableAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	Packet* resp = new MethodReturnMessage(0);

	switch (methid) {
	default:
		return NULL;
	}

	return resp;
}

/*
 *	WearableHelper
 */

WearableHelper* WearableHelper::staticInitializer = WearableHelper::instance();

WearableHelper::WearableHelper() {
	className = "Wearable";

	DistributedObjectBroker::instance()->registerClass(className, this);
}

void WearableHelper::finalizeHelper() {
	WearableHelper::finalize();
}

DistributedObject* WearableHelper::instantiateObject() {
	return new Wearable();
}

DistributedObjectAdapter* WearableHelper::createAdapter(DistributedObjectServant* obj) {
	DistributedObjectAdapter* adapter = new WearableAdapter((WearableImplementation*) obj);

	DistributedObjectStub* stub = new Wearable(obj);
	stub->_setClassName(className);
	stub->_setClassHelper(this);

	adapter->setStub(stub);

	obj->_setStub(stub);

	return adapter;
}

/*
 *	WearableServant
 */

WearableServant::WearableServant(unsigned long long oid, int tp) : TangibleObjectImplementation(oid, tp) {
	_classHelper = WearableHelper::instance();
}

WearableServant::~WearableServant() {
}

void WearableServant::_setStub(DistributedObjectStub* stub) {
	_this = (Wearable*) stub;
	TangibleObjectServant::_setStub(stub);
}

DistributedObjectStub* WearableServant::_getStub() {
	return _this;
}

