/*
 *	server/zone/objects/player/sui/banktransferbox/SuiBankTransferBox.cpp generated by engine3 IDL compiler 0.55
 */

#include "../SuiBox.h"

#include "../../Player.h"

#include "SuiBankTransferBox.h"

#include "SuiBankTransferBoxImplementation.h"

/*
 *	SuiBankTransferBoxStub
 */

SuiBankTransferBox::SuiBankTransferBox() : SuiBox(NULL) {
}

SuiBankTransferBox::SuiBankTransferBox(DistributedObjectServant* obj) : SuiBox(obj) {
}

SuiBankTransferBox::SuiBankTransferBox(SuiBankTransferBox& ref) : SuiBox(ref) {
}

SuiBankTransferBox::~SuiBankTransferBox() {
}

SuiBankTransferBox* SuiBankTransferBox::clone() {
	return new SuiBankTransferBox(*this);
}


BaseMessage* SuiBankTransferBox::generateMessage() {
	if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		DistributedMethod method(this, 6);

		return (BaseMessage*) method.executeWithObjectReturn();
	} else
		return ((SuiBankTransferBoxImplementation*) _impl)->generateMessage();
}

BaseMessage* SuiBankTransferBox::getMessage() {
	if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		DistributedMethod method(this, 7);

		return (BaseMessage*) method.executeWithObjectReturn();
	} else
		return ((SuiBankTransferBoxImplementation*) _impl)->getMessage();
}

void SuiBankTransferBox::addOption(const string& itemText, const string& lblType, const string& itemType) {
	if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		DistributedMethod method(this, 8);
		method.addAsciiParameter(itemText);
		method.addAsciiParameter(lblType);
		method.addAsciiParameter(itemType);

		method.executeWithVoidReturn();
	} else
		((SuiBankTransferBoxImplementation*) _impl)->addOption(itemText, lblType, itemType);
}

/*
 *	SuiBankTransferBoxAdapter
 */

SuiBankTransferBoxAdapter::SuiBankTransferBoxAdapter(SuiBankTransferBoxImplementation* obj) : SuiBoxAdapter(obj) {
}

Packet* SuiBankTransferBoxAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	Packet* resp = new MethodReturnMessage(0);

	switch (methid) {
	case 6:
		resp->insertLong(generateMessage()->_getObjectID());
		break;
	case 7:
		resp->insertLong(getMessage()->_getObjectID());
		break;
	case 8:
		addOption(inv->getAsciiParameter(_param0_addOption__string_string_string_), inv->getAsciiParameter(_param1_addOption__string_string_string_), inv->getAsciiParameter(_param2_addOption__string_string_string_));
		break;
	default:
		return NULL;
	}

	return resp;
}

BaseMessage* SuiBankTransferBoxAdapter::generateMessage() {
	return ((SuiBankTransferBoxImplementation*) impl)->generateMessage();
}

BaseMessage* SuiBankTransferBoxAdapter::getMessage() {
	return ((SuiBankTransferBoxImplementation*) impl)->getMessage();
}

void SuiBankTransferBoxAdapter::addOption(const string& itemText, const string& lblType, const string& itemType) {
	return ((SuiBankTransferBoxImplementation*) impl)->addOption(itemText, lblType, itemType);
}

/*
 *	SuiBankTransferBoxHelper
 */

SuiBankTransferBoxHelper* SuiBankTransferBoxHelper::staticInitializer = SuiBankTransferBoxHelper::instance();

SuiBankTransferBoxHelper::SuiBankTransferBoxHelper() {
	className = "SuiBankTransferBox";

	DistributedObjectBroker::instance()->registerClass(className, this);
}

void SuiBankTransferBoxHelper::finalizeHelper() {
	SuiBankTransferBoxHelper::finalize();
}

DistributedObject* SuiBankTransferBoxHelper::instantiateObject() {
	return new SuiBankTransferBox();
}

DistributedObjectAdapter* SuiBankTransferBoxHelper::createAdapter(DistributedObjectServant* obj) {
	DistributedObjectAdapter* adapter = new SuiBankTransferBoxAdapter((SuiBankTransferBoxImplementation*) obj);

	DistributedObjectStub* stub = new SuiBankTransferBox(obj);
	stub->_setClassName(className);
	stub->_setClassHelper(this);

	adapter->setStub(stub);

	obj->_setStub(stub);

	return adapter;
}

/*
 *	SuiBankTransferBoxServant
 */

SuiBankTransferBoxServant::SuiBankTransferBoxServant(Player* play, unsigned int typeID, unsigned int boxtype) : SuiBoxImplementation(play, typeID, boxtype) {
	_classHelper = SuiBankTransferBoxHelper::instance();
}

SuiBankTransferBoxServant::~SuiBankTransferBoxServant() {
}

void SuiBankTransferBoxServant::_setStub(DistributedObjectStub* stub) {
	_this = (SuiBankTransferBox*) stub;
	SuiBoxServant::_setStub(stub);
}

DistributedObjectStub* SuiBankTransferBoxServant::_getStub() {
	return _this;
}

