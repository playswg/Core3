/*
 *	server/zone/objects/waypoint/WaypointObject.cpp generated by engine3 IDL compiler 0.55
 */

#include "../scene/SceneObject.h"

#include "WaypointObject.h"

#include "WaypointObjectImplementation.h"

/*
 *	WaypointObjectStub
 */

WaypointObject::WaypointObject() : SceneObject(NULL) {
}

WaypointObject::WaypointObject(DistributedObjectServant* obj) : SceneObject(obj) {
}

WaypointObject::WaypointObject(WaypointObject& ref) : SceneObject(ref) {
}

WaypointObject::~WaypointObject() {
}

WaypointObject* WaypointObject::clone() {
	return new WaypointObject(*this);
}


void WaypointObject::changeStatus(bool status) {
	if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		DistributedMethod method(this, 6);
		method.addBooleanParameter(status);

		method.executeWithVoidReturn();
	} else
		((WaypointObjectImplementation*) _impl)->changeStatus(status);
}

void WaypointObject::setName(const string& Name) {
	if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		DistributedMethod method(this, 7);
		method.addAsciiParameter(Name);

		method.executeWithVoidReturn();
	} else
		((WaypointObjectImplementation*) _impl)->setName(Name);
}

void WaypointObject::setPlanetName(const string& planet) {
	if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		DistributedMethod method(this, 8);
		method.addAsciiParameter(planet);

		method.executeWithVoidReturn();
	} else
		((WaypointObjectImplementation*) _impl)->setPlanetName(planet);
}

void WaypointObject::switchStatus() {
	if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		DistributedMethod method(this, 9);

		method.executeWithVoidReturn();
	} else
		((WaypointObjectImplementation*) _impl)->switchStatus();
}

unsigned int WaypointObject::getPlanetCRC() {
	if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		DistributedMethod method(this, 10);

		return method.executeWithUnsignedIntReturn();
	} else
		return ((WaypointObjectImplementation*) _impl)->getPlanetCRC();
}

bool WaypointObject::getStatus() {
	if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		DistributedMethod method(this, 11);

		return method.executeWithBooleanReturn();
	} else
		return ((WaypointObjectImplementation*) _impl)->getStatus();
}

string& WaypointObject::getName() {
	if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		DistributedMethod method(this, 12);

		method.executeWithAsciiReturn(_return_getName);
		return _return_getName;
	} else
		return ((WaypointObjectImplementation*) _impl)->getName();
}

string& WaypointObject::getPlanetName() {
	if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		DistributedMethod method(this, 13);

		method.executeWithAsciiReturn(_return_getPlanetName);
		return _return_getPlanetName;
	} else
		return ((WaypointObjectImplementation*) _impl)->getPlanetName();
}

/*
 *	WaypointObjectAdapter
 */

WaypointObjectAdapter::WaypointObjectAdapter(WaypointObjectImplementation* obj) : SceneObjectAdapter(obj) {
}

Packet* WaypointObjectAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	Packet* resp = new MethodReturnMessage(0);

	switch (methid) {
	case 6:
		changeStatus(inv->getBooleanParameter());
		break;
	case 7:
		setName(inv->getAsciiParameter(_param0_setName__string_));
		break;
	case 8:
		setPlanetName(inv->getAsciiParameter(_param0_setPlanetName__string_));
		break;
	case 9:
		switchStatus();
		break;
	case 10:
		resp->insertInt(getPlanetCRC());
		break;
	case 11:
		resp->insertBoolean(getStatus());
		break;
	case 12:
		resp->insertAscii(getName());
		break;
	case 13:
		resp->insertAscii(getPlanetName());
		break;
	default:
		return NULL;
	}

	return resp;
}

void WaypointObjectAdapter::changeStatus(bool status) {
	return ((WaypointObjectImplementation*) impl)->changeStatus(status);
}

void WaypointObjectAdapter::setName(const string& Name) {
	return ((WaypointObjectImplementation*) impl)->setName(Name);
}

void WaypointObjectAdapter::setPlanetName(const string& planet) {
	return ((WaypointObjectImplementation*) impl)->setPlanetName(planet);
}

void WaypointObjectAdapter::switchStatus() {
	return ((WaypointObjectImplementation*) impl)->switchStatus();
}

unsigned int WaypointObjectAdapter::getPlanetCRC() {
	return ((WaypointObjectImplementation*) impl)->getPlanetCRC();
}

bool WaypointObjectAdapter::getStatus() {
	return ((WaypointObjectImplementation*) impl)->getStatus();
}

string& WaypointObjectAdapter::getName() {
	return ((WaypointObjectImplementation*) impl)->getName();
}

string& WaypointObjectAdapter::getPlanetName() {
	return ((WaypointObjectImplementation*) impl)->getPlanetName();
}

/*
 *	WaypointObjectHelper
 */

WaypointObjectHelper* WaypointObjectHelper::staticInitializer = WaypointObjectHelper::instance();

WaypointObjectHelper::WaypointObjectHelper() {
	className = "WaypointObject";

	DistributedObjectBroker::instance()->registerClass(className, this);
}

void WaypointObjectHelper::finalizeHelper() {
	WaypointObjectHelper::finalize();
}

DistributedObject* WaypointObjectHelper::instantiateObject() {
	return new WaypointObject();
}

DistributedObjectAdapter* WaypointObjectHelper::createAdapter(DistributedObjectServant* obj) {
	DistributedObjectAdapter* adapter = new WaypointObjectAdapter((WaypointObjectImplementation*) obj);

	DistributedObjectStub* stub = new WaypointObject(obj);
	stub->_setClassName(className);
	stub->_setClassHelper(this);

	adapter->setStub(stub);

	obj->_setStub(stub);

	return adapter;
}

/*
 *	WaypointObjectServant
 */

WaypointObjectServant::WaypointObjectServant(unsigned long long oid) : SceneObjectImplementation(oid) {
	_classHelper = WaypointObjectHelper::instance();
}

WaypointObjectServant::~WaypointObjectServant() {
}

void WaypointObjectServant::_setStub(DistributedObjectStub* stub) {
	_this = (WaypointObject*) stub;
	SceneObjectServant::_setStub(stub);
}

DistributedObjectStub* WaypointObjectServant::_getStub() {
	return _this;
}

