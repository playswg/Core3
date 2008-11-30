/*
 *	server/zone/objects/tangible/powerup/Powerup.cpp generated by engine3 IDL compiler 0.55
 */

#include "Powerup.h"

#include "PowerupImplementation.h"

#include "../../creature/CreatureObject.h"

#include "../../player/Player.h"

#include "../TangibleObject.h"

#include "../weapons/Weapon.h"

/*
 *	PowerupStub
 */

Powerup::Powerup(unsigned long long oid) : TangibleObject(DummyConstructorParameter::instance()) {
	_impl = new PowerupImplementation(oid);
	_impl->_setStub(this);
}

Powerup::Powerup(unsigned long long oid, unsigned int tempCRC, const UnicodeString& n, const String& tempn) : TangibleObject(DummyConstructorParameter::instance()) {
	_impl = new PowerupImplementation(oid, tempCRC, n, tempn);
	_impl->_setStub(this);
}

Powerup::Powerup(DummyConstructorParameter* param) : TangibleObject(param) {
}

Powerup::~Powerup() {
}

void Powerup::apply(Weapon* weapon) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 6);
		method.addObjectParameter(weapon);

		method.executeWithVoidReturn();
	} else
		((PowerupImplementation*) _impl)->apply(weapon);
}

void Powerup::remove(Player* player) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 7);
		method.addObjectParameter(player);

		method.executeWithVoidReturn();
	} else
		((PowerupImplementation*) _impl)->remove(player);
}

int Powerup::getPowerup0Type() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 8);

		return method.executeWithSignedIntReturn();
	} else
		return ((PowerupImplementation*) _impl)->getPowerup0Type();
}

int Powerup::getPowerup1Type() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 9);

		return method.executeWithSignedIntReturn();
	} else
		return ((PowerupImplementation*) _impl)->getPowerup1Type();
}

int Powerup::getPowerup2Type() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 10);

		return method.executeWithSignedIntReturn();
	} else
		return ((PowerupImplementation*) _impl)->getPowerup2Type();
}

float Powerup::getPowerup0Value() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 11);

		return method.executeWithFloatReturn();
	} else
		return ((PowerupImplementation*) _impl)->getPowerup0Value();
}

float Powerup::getPowerup1Value() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 12);

		return method.executeWithFloatReturn();
	} else
		return ((PowerupImplementation*) _impl)->getPowerup1Value();
}

float Powerup::getPowerup2Value() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 13);

		return method.executeWithFloatReturn();
	} else
		return ((PowerupImplementation*) _impl)->getPowerup2Value();
}

int Powerup::getPowerupUses() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 14);

		return method.executeWithSignedIntReturn();
	} else
		return ((PowerupImplementation*) _impl)->getPowerupUses();
}

int Powerup::getPowerupType() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 15);

		return method.executeWithSignedIntReturn();
	} else
		return ((PowerupImplementation*) _impl)->getPowerupType();
}

int Powerup::getPowerupSubType() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 16);

		return method.executeWithSignedIntReturn();
	} else
		return ((PowerupImplementation*) _impl)->getPowerupSubType();
}

void Powerup::setPowerupStats(int modifier) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 17);
		method.addSignedIntParameter(modifier);

		method.executeWithVoidReturn();
	} else
		((PowerupImplementation*) _impl)->setPowerupStats(modifier);
}

void Powerup::setPowerup0Type(int value) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 18);
		method.addSignedIntParameter(value);

		method.executeWithVoidReturn();
	} else
		((PowerupImplementation*) _impl)->setPowerup0Type(value);
}

void Powerup::setPowerup1Type(int value) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 19);
		method.addSignedIntParameter(value);

		method.executeWithVoidReturn();
	} else
		((PowerupImplementation*) _impl)->setPowerup1Type(value);
}

void Powerup::setPowerup2Type(int value) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 20);
		method.addSignedIntParameter(value);

		method.executeWithVoidReturn();
	} else
		((PowerupImplementation*) _impl)->setPowerup2Type(value);
}

void Powerup::setPowerup0Value(float value) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 21);
		method.addFloatParameter(value);

		method.executeWithVoidReturn();
	} else
		((PowerupImplementation*) _impl)->setPowerup0Value(value);
}

void Powerup::setPowerup1Value(float value) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 22);
		method.addFloatParameter(value);

		method.executeWithVoidReturn();
	} else
		((PowerupImplementation*) _impl)->setPowerup1Value(value);
}

void Powerup::setPowerup2Value(float value) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 23);
		method.addFloatParameter(value);

		method.executeWithVoidReturn();
	} else
		((PowerupImplementation*) _impl)->setPowerup2Value(value);
}

void Powerup::setPowerupUses(int value) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 24);
		method.addSignedIntParameter(value);

		method.executeWithVoidReturn();
	} else
		((PowerupImplementation*) _impl)->setPowerupUses(value);
}

void Powerup::setPowerupType(int value) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 25);
		method.addSignedIntParameter(value);

		method.executeWithVoidReturn();
	} else
		((PowerupImplementation*) _impl)->setPowerupType(value);
}

void Powerup::setPowerupSubType(int value) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 26);
		method.addSignedIntParameter(value);

		method.executeWithVoidReturn();
	} else
		((PowerupImplementation*) _impl)->setPowerupSubType(value);
}

/*
 *	PowerupAdapter
 */

PowerupAdapter::PowerupAdapter(PowerupImplementation* obj) : TangibleObjectAdapter(obj) {
}

Packet* PowerupAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	Packet* resp = new MethodReturnMessage(0);

	switch (methid) {
	case 6:
		apply((Weapon*) inv->getObjectParameter());
		break;
	case 7:
		remove((Player*) inv->getObjectParameter());
		break;
	case 8:
		resp->insertSignedInt(getPowerup0Type());
		break;
	case 9:
		resp->insertSignedInt(getPowerup1Type());
		break;
	case 10:
		resp->insertSignedInt(getPowerup2Type());
		break;
	case 11:
		resp->insertFloat(getPowerup0Value());
		break;
	case 12:
		resp->insertFloat(getPowerup1Value());
		break;
	case 13:
		resp->insertFloat(getPowerup2Value());
		break;
	case 14:
		resp->insertSignedInt(getPowerupUses());
		break;
	case 15:
		resp->insertSignedInt(getPowerupType());
		break;
	case 16:
		resp->insertSignedInt(getPowerupSubType());
		break;
	case 17:
		setPowerupStats(inv->getSignedIntParameter());
		break;
	case 18:
		setPowerup0Type(inv->getSignedIntParameter());
		break;
	case 19:
		setPowerup1Type(inv->getSignedIntParameter());
		break;
	case 20:
		setPowerup2Type(inv->getSignedIntParameter());
		break;
	case 21:
		setPowerup0Value(inv->getFloatParameter());
		break;
	case 22:
		setPowerup1Value(inv->getFloatParameter());
		break;
	case 23:
		setPowerup2Value(inv->getFloatParameter());
		break;
	case 24:
		setPowerupUses(inv->getSignedIntParameter());
		break;
	case 25:
		setPowerupType(inv->getSignedIntParameter());
		break;
	case 26:
		setPowerupSubType(inv->getSignedIntParameter());
		break;
	default:
		return NULL;
	}

	return resp;
}

void PowerupAdapter::apply(Weapon* weapon) {
	return ((PowerupImplementation*) impl)->apply(weapon);
}

void PowerupAdapter::remove(Player* player) {
	return ((PowerupImplementation*) impl)->remove(player);
}

int PowerupAdapter::getPowerup0Type() {
	return ((PowerupImplementation*) impl)->getPowerup0Type();
}

int PowerupAdapter::getPowerup1Type() {
	return ((PowerupImplementation*) impl)->getPowerup1Type();
}

int PowerupAdapter::getPowerup2Type() {
	return ((PowerupImplementation*) impl)->getPowerup2Type();
}

float PowerupAdapter::getPowerup0Value() {
	return ((PowerupImplementation*) impl)->getPowerup0Value();
}

float PowerupAdapter::getPowerup1Value() {
	return ((PowerupImplementation*) impl)->getPowerup1Value();
}

float PowerupAdapter::getPowerup2Value() {
	return ((PowerupImplementation*) impl)->getPowerup2Value();
}

int PowerupAdapter::getPowerupUses() {
	return ((PowerupImplementation*) impl)->getPowerupUses();
}

int PowerupAdapter::getPowerupType() {
	return ((PowerupImplementation*) impl)->getPowerupType();
}

int PowerupAdapter::getPowerupSubType() {
	return ((PowerupImplementation*) impl)->getPowerupSubType();
}

void PowerupAdapter::setPowerupStats(int modifier) {
	return ((PowerupImplementation*) impl)->setPowerupStats(modifier);
}

void PowerupAdapter::setPowerup0Type(int value) {
	return ((PowerupImplementation*) impl)->setPowerup0Type(value);
}

void PowerupAdapter::setPowerup1Type(int value) {
	return ((PowerupImplementation*) impl)->setPowerup1Type(value);
}

void PowerupAdapter::setPowerup2Type(int value) {
	return ((PowerupImplementation*) impl)->setPowerup2Type(value);
}

void PowerupAdapter::setPowerup0Value(float value) {
	return ((PowerupImplementation*) impl)->setPowerup0Value(value);
}

void PowerupAdapter::setPowerup1Value(float value) {
	return ((PowerupImplementation*) impl)->setPowerup1Value(value);
}

void PowerupAdapter::setPowerup2Value(float value) {
	return ((PowerupImplementation*) impl)->setPowerup2Value(value);
}

void PowerupAdapter::setPowerupUses(int value) {
	return ((PowerupImplementation*) impl)->setPowerupUses(value);
}

void PowerupAdapter::setPowerupType(int value) {
	return ((PowerupImplementation*) impl)->setPowerupType(value);
}

void PowerupAdapter::setPowerupSubType(int value) {
	return ((PowerupImplementation*) impl)->setPowerupSubType(value);
}

/*
 *	PowerupHelper
 */

PowerupHelper* PowerupHelper::staticInitializer = PowerupHelper::instance();

PowerupHelper::PowerupHelper() {
	className = "Powerup";

	DistributedObjectBroker::instance()->registerClass(className, this);
}

void PowerupHelper::finalizeHelper() {
	PowerupHelper::finalize();
}

DistributedObject* PowerupHelper::instantiateObject() {
	return new Powerup(DummyConstructorParameter::instance());
}

DistributedObjectAdapter* PowerupHelper::createAdapter(DistributedObjectStub* obj) {
	DistributedObjectAdapter* adapter = new PowerupAdapter((PowerupImplementation*) obj->_getImplementation());

	obj->_setClassName(className);
	obj->_setClassHelper(this);

	adapter->setStub(obj);

	return adapter;
}

/*
 *	PowerupServant
 */

PowerupServant::PowerupServant(unsigned long long oid, int type) : TangibleObjectImplementation(oid, type) {
	_classHelper = PowerupHelper::instance();
}

PowerupServant::~PowerupServant() {
}

void PowerupServant::_setStub(DistributedObjectStub* stub) {
	_this = (Powerup*) stub;
	TangibleObjectServant::_setStub(stub);
}

DistributedObjectStub* PowerupServant::_getStub() {
	return _this;
}

