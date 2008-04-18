/*
 *	server/zone/objects/tangible/weapons/melee/UnarmedMeleeWeapon.h generated by engine3 IDL compiler 0.55
 */

#ifndef UNARMEDMELEEWEAPON_H_
#define UNARMEDMELEEWEAPON_H_

#include "engine/orb/DistributedObjectBroker.h"

class CreatureObject;

class MeleeWeapon;

#include "../MeleeWeapon.h"

class UnarmedMeleeWeapon : public MeleeWeapon {
protected:
	UnarmedMeleeWeapon();
	UnarmedMeleeWeapon(DistributedObjectServant* obj);
	UnarmedMeleeWeapon(UnarmedMeleeWeapon& ref);

	virtual ~UnarmedMeleeWeapon();

public:
	UnarmedMeleeWeapon* clone();

	friend class UnarmedMeleeWeaponHelper;
};

class UnarmedMeleeWeaponImplementation;

class UnarmedMeleeWeaponAdapter : public MeleeWeaponAdapter {
public:
	UnarmedMeleeWeaponAdapter(UnarmedMeleeWeaponImplementation* impl);

	Packet* invokeMethod(sys::uint32 methid, DistributedMethod* method);

};

class UnarmedMeleeWeaponHelper : public DistributedObjectClassHelper, public Singleton<UnarmedMeleeWeaponHelper> {
	static UnarmedMeleeWeaponHelper* staticInitializer;

public:
	UnarmedMeleeWeaponHelper();

	void finalizeHelper();

	DistributedObject* instantiateObject();

	DistributedObjectAdapter* createAdapter(DistributedObjectServant* obj);

	friend class SingletonWrapper<UnarmedMeleeWeaponHelper>;
};

#include "../MeleeWeaponImplementation.h"

class UnarmedMeleeWeaponServant : public MeleeWeaponImplementation {
public:
	UnarmedMeleeWeapon* _this;

public:
	UnarmedMeleeWeaponServant(unsigned long long objid, unsigned int tempcrc, const unicode& n, const string& tempn, int tp, bool eqp);
	UnarmedMeleeWeaponServant(CreatureObject* creature, const string& temp, const unicode& n, const string& tempn, int tp, bool eqp);
	virtual ~UnarmedMeleeWeaponServant();

	void _setStub(DistributedObjectStub* stub);
	DistributedObjectStub* _getStub();

};

#endif /*UNARMEDMELEEWEAPON_H_*/
