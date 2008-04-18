/*
 *	server/zone/objects/creature/recruiter/RecruiterCreature.cpp generated by engine3 IDL compiler 0.55
 */

#include "../Creature.h"

#include "../../scene/SceneObject.h"

#include "../../player/Player.h"

#include "RecruiterCreature.h"

#include "RecruiterCreatureImplementation.h"

/*
 *	RecruiterCreatureStub
 */

RecruiterCreature::RecruiterCreature() : Creature(NULL) {
}

RecruiterCreature::RecruiterCreature(DistributedObjectServant* obj) : Creature(obj) {
}

RecruiterCreature::RecruiterCreature(RecruiterCreature& ref) : Creature(ref) {
}

RecruiterCreature::~RecruiterCreature() {
}

RecruiterCreature* RecruiterCreature::clone() {
	return new RecruiterCreature(*this);
}


void RecruiterCreature::sendConversationStartTo(SceneObject* obj) {
	if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		DistributedMethod method(this, 6);
		method.addObjectParameter(obj);

		method.executeWithVoidReturn();
	} else
		((RecruiterCreatureImplementation*) _impl)->sendConversationStartTo(obj);
}

void RecruiterCreature::sendFactions(Player* player) {
	if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		DistributedMethod method(this, 7);
		method.addObjectParameter(player);

		method.executeWithVoidReturn();
	} else
		((RecruiterCreatureImplementation*) _impl)->sendFactions(player);
}

void RecruiterCreature::selectConversationOption(int option, SceneObject* obj) {
	if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		DistributedMethod method(this, 8);
		method.addSignedIntParameter(option);
		method.addObjectParameter(obj);

		method.executeWithVoidReturn();
	} else
		((RecruiterCreatureImplementation*) _impl)->selectConversationOption(option, obj);
}

/*
 *	RecruiterCreatureAdapter
 */

RecruiterCreatureAdapter::RecruiterCreatureAdapter(RecruiterCreatureImplementation* obj) : CreatureAdapter(obj) {
}

Packet* RecruiterCreatureAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	Packet* resp = new MethodReturnMessage(0);

	switch (methid) {
	case 6:
		sendConversationStartTo((SceneObject*) inv->getObjectParameter());
		break;
	case 7:
		sendFactions((Player*) inv->getObjectParameter());
		break;
	case 8:
		selectConversationOption(inv->getSignedIntParameter(), (SceneObject*) inv->getObjectParameter());
		break;
	default:
		return NULL;
	}

	return resp;
}

void RecruiterCreatureAdapter::sendConversationStartTo(SceneObject* obj) {
	return ((RecruiterCreatureImplementation*) impl)->sendConversationStartTo(obj);
}

void RecruiterCreatureAdapter::sendFactions(Player* player) {
	return ((RecruiterCreatureImplementation*) impl)->sendFactions(player);
}

void RecruiterCreatureAdapter::selectConversationOption(int option, SceneObject* obj) {
	return ((RecruiterCreatureImplementation*) impl)->selectConversationOption(option, obj);
}

/*
 *	RecruiterCreatureHelper
 */

RecruiterCreatureHelper* RecruiterCreatureHelper::staticInitializer = RecruiterCreatureHelper::instance();

RecruiterCreatureHelper::RecruiterCreatureHelper() {
	className = "RecruiterCreature";

	DistributedObjectBroker::instance()->registerClass(className, this);
}

void RecruiterCreatureHelper::finalizeHelper() {
	RecruiterCreatureHelper::finalize();
}

DistributedObject* RecruiterCreatureHelper::instantiateObject() {
	return new RecruiterCreature();
}

DistributedObjectAdapter* RecruiterCreatureHelper::createAdapter(DistributedObjectServant* obj) {
	DistributedObjectAdapter* adapter = new RecruiterCreatureAdapter((RecruiterCreatureImplementation*) obj);

	DistributedObjectStub* stub = new RecruiterCreature(obj);
	stub->_setClassName(className);
	stub->_setClassHelper(this);

	adapter->setStub(stub);

	obj->_setStub(stub);

	return adapter;
}

/*
 *	RecruiterCreatureServant
 */

RecruiterCreatureServant::RecruiterCreatureServant(unsigned long long oid) : CreatureImplementation(oid) {
	_classHelper = RecruiterCreatureHelper::instance();
}

RecruiterCreatureServant::~RecruiterCreatureServant() {
}

void RecruiterCreatureServant::_setStub(DistributedObjectStub* stub) {
	_this = (RecruiterCreature*) stub;
	CreatureServant::_setStub(stub);
}

DistributedObjectStub* RecruiterCreatureServant::_getStub() {
	return _this;
}

