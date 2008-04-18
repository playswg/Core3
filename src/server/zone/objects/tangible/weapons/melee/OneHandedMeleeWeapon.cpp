/*
 *	server/zone/objects/tangible/weapons/melee/OneHandedMeleeWeapon.cpp generated by engine3 IDL compiler 0.55
 */

#include "../../../creature/CreatureObject.h"

#include "../MeleeWeapon.h"

#include "OneHandedMeleeWeapon.h"

#include "OneHandedMeleeWeaponImplementation.h"

/*
 *	OneHandedMeleeWeaponStub
 */

OneHandedMeleeWeapon::OneHandedMeleeWeapon() : MeleeWeapon(NULL) {
}

OneHandedMeleeWeapon::OneHandedMeleeWeapon(DistributedObjectServant* obj) : MeleeWeapon(obj) {
}

OneHandedMeleeWeapon::OneHandedMeleeWeapon(OneHandedMeleeWeapon& ref) : MeleeWeapon(ref) {
}

OneHandedMeleeWeapon::~OneHandedMeleeWeapon() {
}

OneHandedMeleeWeapon* OneHandedMeleeWeapon::clone() {
	return new OneHandedMeleeWeapon(*this);
}


/*
 *	OneHandedMeleeWeaponAdapter
 */

OneHandedMeleeWeaponAdapter::OneHandedMeleeWeaponAdapter(OneHandedMeleeWeaponImplementation* obj) : MeleeWeaponAdapter(obj) {
}

Packet* OneHandedMeleeWeaponAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	Packet* resp = new MethodReturnMessage(0);

	switch (methid) {
	default:
		return NULL;
	}

	return resp;
}

/*
 *	OneHandedMeleeWeaponHelper
 */

OneHandedMeleeWeaponHelper* OneHandedMeleeWeaponHelper::staticInitializer = OneHandedMeleeWeaponHelper::instance();

OneHandedMeleeWeaponHelper::OneHandedMeleeWeaponHelper() {
	className = "OneHandedMeleeWeapon";

	DistributedObjectBroker::instance()->registerClass(className, this);
}

void OneHandedMeleeWeaponHelper::finalizeHelper() {
	OneHandedMeleeWeaponHelper::finalize();
}

DistributedObject* OneHandedMeleeWeaponHelper::instantiateObject() {
	return new OneHandedMeleeWeapon();
}

DistributedObjectAdapter* OneHandedMeleeWeaponHelper::createAdapter(DistributedObjectServant* obj) {
	DistributedObjectAdapter* adapter = new OneHandedMeleeWeaponAdapter((OneHandedMeleeWeaponImplementation*) obj);

	DistributedObjectStub* stub = new OneHandedMeleeWeapon(obj);
	stub->_setClassName(className);
	stub->_setClassHelper(this);

	adapter->setStub(stub);

	obj->_setStub(stub);

	return adapter;
}

/*
 *	OneHandedMeleeWeaponServant
 */

OneHandedMeleeWeaponServant::OneHandedMeleeWeaponServant(unsigned long long objid, unsigned int tempcrc, const unicode& n, const string& tempn, int tp, bool eqp) : MeleeWeaponImplementation(objid, tempcrc, n, tempn, tp, eqp) {
	_classHelper = OneHandedMeleeWeaponHelper::instance();
}

OneHandedMeleeWeaponServant::OneHandedMeleeWeaponServant(CreatureObject* creature, const string& temp, const unicode& n, const string& tempn, int tp, bool eqp) : MeleeWeaponImplementation(creature, temp, n, tempn, tp, eqp) {
	_classHelper = OneHandedMeleeWeaponHelper::instance();
}

OneHandedMeleeWeaponServant::~OneHandedMeleeWeaponServant() {
}

void OneHandedMeleeWeaponServant::_setStub(DistributedObjectStub* stub) {
	_this = (OneHandedMeleeWeapon*) stub;
	MeleeWeaponServant::_setStub(stub);
}

DistributedObjectStub* OneHandedMeleeWeaponServant::_getStub() {
	return _this;
}

