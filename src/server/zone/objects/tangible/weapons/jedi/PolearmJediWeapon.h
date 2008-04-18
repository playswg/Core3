/*
 *	server/zone/objects/tangible/weapons/jedi/PolearmJediWeapon.h generated by engine3 IDL compiler 0.55
 */

#ifndef POLEARMJEDIWEAPON_H_
#define POLEARMJEDIWEAPON_H_

#include "engine/orb/DistributedObjectBroker.h"

class CreatureObject;

class JediWeapon;

#include "../JediWeapon.h"

class PolearmJediWeapon : public JediWeapon {
protected:
	PolearmJediWeapon();
	PolearmJediWeapon(DistributedObjectServant* obj);
	PolearmJediWeapon(PolearmJediWeapon& ref);

	virtual ~PolearmJediWeapon();

public:
	PolearmJediWeapon* clone();

	friend class PolearmJediWeaponHelper;
};

class PolearmJediWeaponImplementation;

class PolearmJediWeaponAdapter : public JediWeaponAdapter {
public:
	PolearmJediWeaponAdapter(PolearmJediWeaponImplementation* impl);

	Packet* invokeMethod(sys::uint32 methid, DistributedMethod* method);

};

class PolearmJediWeaponHelper : public DistributedObjectClassHelper, public Singleton<PolearmJediWeaponHelper> {
	static PolearmJediWeaponHelper* staticInitializer;

public:
	PolearmJediWeaponHelper();

	void finalizeHelper();

	DistributedObject* instantiateObject();

	DistributedObjectAdapter* createAdapter(DistributedObjectServant* obj);

	friend class SingletonWrapper<PolearmJediWeaponHelper>;
};

#include "../JediWeaponImplementation.h"

class PolearmJediWeaponServant : public JediWeaponImplementation {
public:
	PolearmJediWeapon* _this;

public:
	PolearmJediWeaponServant(unsigned long long objid, unsigned int tempcrc, const unicode& n, const string& tempn, int tp, bool eqp);
	PolearmJediWeaponServant(CreatureObject* creature, const string& temp, const unicode& n, const string& tempn, int tp, bool eqp);
	virtual ~PolearmJediWeaponServant();

	void _setStub(DistributedObjectStub* stub);
	DistributedObjectStub* _getStub();

};

#endif /*POLEARMJEDIWEAPON_H_*/
