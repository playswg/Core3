/*
 *	server/zone/objects/tangible/instrument/Instrument.cpp generated by engine3 IDL compiler 0.55
 */

#include "../TangibleObject.h"

#include "../../player/Player.h"

#include "Instrument.h"

#include "InstrumentImplementation.h"

/*
 *	InstrumentStub
 */

Instrument::Instrument() : TangibleObject(NULL) {
}

Instrument::Instrument(DistributedObjectServant* obj) : TangibleObject(obj) {
}

Instrument::Instrument(Instrument& ref) : TangibleObject(ref) {
}

Instrument::~Instrument() {
}

Instrument* Instrument::clone() {
	return new Instrument(*this);
}


int Instrument::useObject(Player* player) {
	if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		DistributedMethod method(this, 6);
		method.addObjectParameter(player);

		return method.executeWithSignedIntReturn();
	} else
		return ((InstrumentImplementation*) _impl)->useObject(player);
}

int Instrument::getInstrumentType() {
	if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		DistributedMethod method(this, 7);

		return method.executeWithSignedIntReturn();
	} else
		return ((InstrumentImplementation*) _impl)->getInstrumentType();
}

/*
 *	InstrumentAdapter
 */

InstrumentAdapter::InstrumentAdapter(InstrumentImplementation* obj) : TangibleObjectAdapter(obj) {
}

Packet* InstrumentAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	Packet* resp = new MethodReturnMessage(0);

	switch (methid) {
	case 6:
		resp->insertSignedInt(useObject((Player*) inv->getObjectParameter()));
		break;
	case 7:
		resp->insertSignedInt(getInstrumentType());
		break;
	default:
		return NULL;
	}

	return resp;
}

int InstrumentAdapter::useObject(Player* player) {
	return ((InstrumentImplementation*) impl)->useObject(player);
}

int InstrumentAdapter::getInstrumentType() {
	return ((InstrumentImplementation*) impl)->getInstrumentType();
}

/*
 *	InstrumentHelper
 */

InstrumentHelper* InstrumentHelper::staticInitializer = InstrumentHelper::instance();

InstrumentHelper::InstrumentHelper() {
	className = "Instrument";

	DistributedObjectBroker::instance()->registerClass(className, this);
}

void InstrumentHelper::finalizeHelper() {
	InstrumentHelper::finalize();
}

DistributedObject* InstrumentHelper::instantiateObject() {
	return new Instrument();
}

DistributedObjectAdapter* InstrumentHelper::createAdapter(DistributedObjectServant* obj) {
	DistributedObjectAdapter* adapter = new InstrumentAdapter((InstrumentImplementation*) obj);

	DistributedObjectStub* stub = new Instrument(obj);
	stub->_setClassName(className);
	stub->_setClassHelper(this);

	adapter->setStub(stub);

	obj->_setStub(stub);

	return adapter;
}

/*
 *	InstrumentServant
 */

InstrumentServant::InstrumentServant(unsigned long long oid, int tp) : TangibleObjectImplementation(oid, tp) {
	_classHelper = InstrumentHelper::instance();
}

InstrumentServant::~InstrumentServant() {
}

void InstrumentServant::_setStub(DistributedObjectStub* stub) {
	_this = (Instrument*) stub;
	TangibleObjectServant::_setStub(stub);
}

DistributedObjectStub* InstrumentServant::_getStub() {
	return _this;
}

