/*
 *	server/zone/objects/draftschematic/DraftSchematic.cpp generated by engine3 IDL compiler 0.55
 */

#include "../scene/SceneObject.h"

#include "../player/Player.h"

#include "DraftSchematicIngredient.h"

#include "DraftSchematicExpPropGroup.h"

#include "../../packets/object/ObjectControllerMessage.h"

#include "DraftSchematic.h"

#include "DraftSchematicImplementation.h"

/*
 *	DraftSchematicStub
 */

DraftSchematic::DraftSchematic() : DistributedObjectStub(NULL) {
}

DraftSchematic::DraftSchematic(DistributedObjectServant* obj) : DistributedObjectStub(obj) {
}

DraftSchematic::DraftSchematic(DraftSchematic& ref) : DistributedObjectStub(ref) {
}

DraftSchematic::~DraftSchematic() {
}

DraftSchematic* DraftSchematic::clone() {
	return new DraftSchematic(*this);
}


DraftSchematic* DraftSchematic::dsClone(DraftSchematic* ds) {
	if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		DistributedMethod method(this, 6);
		method.addObjectParameter(ds);

		return (DraftSchematic*) method.executeWithObjectReturn();
	} else
		return ((DraftSchematicImplementation*) _impl)->dsClone(ds);
}

void DraftSchematic::addIngredient(const string& ingredientTemplateName, const string& ingredientTitleName, bool optional, const string& resourceType, unsigned int resourceQuantity) {
	if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		DistributedMethod method(this, 7);
		method.addAsciiParameter(ingredientTemplateName);
		method.addAsciiParameter(ingredientTitleName);
		method.addBooleanParameter(optional);
		method.addAsciiParameter(resourceType);
		method.addUnsignedIntParameter(resourceQuantity);

		method.executeWithVoidReturn();
	} else
		((DraftSchematicImplementation*) _impl)->addIngredient(ingredientTemplateName, ingredientTitleName, optional, resourceType, resourceQuantity);
}

void DraftSchematic::sendIngredientsToPlayer(Player* player) {
	if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		DistributedMethod method(this, 8);
		method.addObjectParameter(player);

		method.executeWithVoidReturn();
	} else
		((DraftSchematicImplementation*) _impl)->sendIngredientsToPlayer(player);
}

void DraftSchematic::helperSendIngredientsToPlayer(ObjectControllerMessage* objMsg) {
	if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		DistributedMethod method(this, 9);
		method.addObjectParameter(objMsg);

		method.executeWithVoidReturn();
	} else
		((DraftSchematicImplementation*) _impl)->helperSendIngredientsToPlayer(objMsg);
}

void DraftSchematic::addExperimentalProperty(unsigned int groupNumber, const string& experimentalProperty, unsigned int weight) {
	if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		DistributedMethod method(this, 10);
		method.addUnsignedIntParameter(groupNumber);
		method.addAsciiParameter(experimentalProperty);
		method.addUnsignedIntParameter(weight);

		method.executeWithVoidReturn();
	} else
		((DraftSchematicImplementation*) _impl)->addExperimentalProperty(groupNumber, experimentalProperty, weight);
}

void DraftSchematic::sendExperimentalPropertiesToPlayer(Player* player) {
	if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		DistributedMethod method(this, 11);
		method.addObjectParameter(player);

		method.executeWithVoidReturn();
	} else
		((DraftSchematicImplementation*) _impl)->sendExperimentalPropertiesToPlayer(player);
}

DraftSchematicIngredient* DraftSchematic::getIngredient(int index) {
	if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		DistributedMethod method(this, 12);
		method.addSignedIntParameter(index);

		return (DraftSchematicIngredient*) method.executeWithObjectReturn();
	} else
		return ((DraftSchematicImplementation*) _impl)->getIngredient(index);
}

int DraftSchematic::getIngredientListSize() {
	if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		DistributedMethod method(this, 13);

		return method.executeWithSignedIntReturn();
	} else
		return ((DraftSchematicImplementation*) _impl)->getIngredientListSize();
}

void DraftSchematic::addExpPropTitle(const string& title) {
	if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		DistributedMethod method(this, 14);
		method.addAsciiParameter(title);

		method.executeWithVoidReturn();
	} else
		((DraftSchematicImplementation*) _impl)->addExpPropTitle(title);
}

int DraftSchematic::getExpPropTitlesListSize() {
	if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		DistributedMethod method(this, 15);

		return method.executeWithSignedIntReturn();
	} else
		return ((DraftSchematicImplementation*) _impl)->getExpPropTitlesListSize();
}

string& DraftSchematic::getExpPropTitle(int index) {
	if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		DistributedMethod method(this, 16);
		method.addSignedIntParameter(index);

		method.executeWithAsciiReturn(_return_getExpPropTitle);
		return _return_getExpPropTitle;
	} else
		return ((DraftSchematicImplementation*) _impl)->getExpPropTitle(index);
}

int DraftSchematic::getExpPropGroupListSize() {
	if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		DistributedMethod method(this, 17);

		return method.executeWithSignedIntReturn();
	} else
		return ((DraftSchematicImplementation*) _impl)->getExpPropGroupListSize();
}

DraftSchematicExpPropGroup* DraftSchematic::getExpPropGroup(int index) {
	if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		DistributedMethod method(this, 18);
		method.addSignedIntParameter(index);

		return (DraftSchematicExpPropGroup*) method.executeWithObjectReturn();
	} else
		return ((DraftSchematicImplementation*) _impl)->getExpPropGroup(index);
}

void DraftSchematic::setPersistent(bool status) {
	if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		DistributedMethod method(this, 19);
		method.addBooleanParameter(status);

		method.executeWithVoidReturn();
	} else
		((DraftSchematicImplementation*) _impl)->setPersistent(status);
}

void DraftSchematic::setObjectID(unsigned long long objID) {
	if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		DistributedMethod method(this, 20);
		method.addUnsignedLongParameter(objID);

		method.executeWithVoidReturn();
	} else
		((DraftSchematicImplementation*) _impl)->setObjectID(objID);
}

void DraftSchematic::setTanoAttributes(string& attributes) {
	if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		DistributedMethod method(this, 21);
		method.addAsciiParameter(attributes);

		method.executeWithVoidReturn();
	} else
		((DraftSchematicImplementation*) _impl)->setTanoAttributes(attributes);
}

unsigned int DraftSchematic::getSchematicID() {
	if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		DistributedMethod method(this, 22);

		return method.executeWithUnsignedIntReturn();
	} else
		return ((DraftSchematicImplementation*) _impl)->getSchematicID();
}

unsigned int DraftSchematic::getSchematicCRC() {
	if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		DistributedMethod method(this, 23);

		return method.executeWithUnsignedIntReturn();
	} else
		return ((DraftSchematicImplementation*) _impl)->getSchematicCRC();
}

string& DraftSchematic::getName() {
	if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		DistributedMethod method(this, 24);

		method.executeWithAsciiReturn(_return_getName);
		return _return_getName;
	} else
		return ((DraftSchematicImplementation*) _impl)->getName();
}

string& DraftSchematic::getGroupName() {
	if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		DistributedMethod method(this, 25);

		method.executeWithAsciiReturn(_return_getGroupName);
		return _return_getGroupName;
	} else
		return ((DraftSchematicImplementation*) _impl)->getGroupName();
}

unsigned int DraftSchematic::getComplexity() {
	if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		DistributedMethod method(this, 26);

		return method.executeWithUnsignedIntReturn();
	} else
		return ((DraftSchematicImplementation*) _impl)->getComplexity();
}

unsigned int DraftSchematic::getSchematicSize() {
	if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		DistributedMethod method(this, 27);

		return method.executeWithUnsignedIntReturn();
	} else
		return ((DraftSchematicImplementation*) _impl)->getSchematicSize();
}

unsigned int DraftSchematic::getObjectID() {
	if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		DistributedMethod method(this, 28);

		return method.executeWithUnsignedIntReturn();
	} else
		return ((DraftSchematicImplementation*) _impl)->getObjectID();
}

string& DraftSchematic::getTanoAttributes() {
	if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		DistributedMethod method(this, 29);

		method.executeWithAsciiReturn(_return_getTanoAttributes);
		return _return_getTanoAttributes;
	} else
		return ((DraftSchematicImplementation*) _impl)->getTanoAttributes();
}

int DraftSchematic::getCraftingToolTab() {
	if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		DistributedMethod method(this, 30);

		return method.executeWithSignedIntReturn();
	} else
		return ((DraftSchematicImplementation*) _impl)->getCraftingToolTab();
}

/*
 *	DraftSchematicAdapter
 */

DraftSchematicAdapter::DraftSchematicAdapter(DraftSchematicImplementation* obj) : DistributedObjectAdapter((DistributedObjectServant*) obj) {
}

Packet* DraftSchematicAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	Packet* resp = new MethodReturnMessage(0);

	switch (methid) {
	case 6:
		resp->insertLong(dsClone((DraftSchematic*) inv->getObjectParameter())->_getObjectID());
		break;
	case 7:
		addIngredient(inv->getAsciiParameter(_param0_addIngredient__string_string_bool_string_int_), inv->getAsciiParameter(_param1_addIngredient__string_string_bool_string_int_), inv->getBooleanParameter(), inv->getAsciiParameter(_param3_addIngredient__string_string_bool_string_int_), inv->getUnsignedIntParameter());
		break;
	case 8:
		sendIngredientsToPlayer((Player*) inv->getObjectParameter());
		break;
	case 9:
		helperSendIngredientsToPlayer((ObjectControllerMessage*) inv->getObjectParameter());
		break;
	case 10:
		addExperimentalProperty(inv->getUnsignedIntParameter(), inv->getAsciiParameter(_param1_addExperimentalProperty__int_string_int_), inv->getUnsignedIntParameter());
		break;
	case 11:
		sendExperimentalPropertiesToPlayer((Player*) inv->getObjectParameter());
		break;
	case 12:
		resp->insertLong(getIngredient(inv->getSignedIntParameter())->_getObjectID());
		break;
	case 13:
		resp->insertSignedInt(getIngredientListSize());
		break;
	case 14:
		addExpPropTitle(inv->getAsciiParameter(_param0_addExpPropTitle__string_));
		break;
	case 15:
		resp->insertSignedInt(getExpPropTitlesListSize());
		break;
	case 16:
		resp->insertAscii(getExpPropTitle(inv->getSignedIntParameter()));
		break;
	case 17:
		resp->insertSignedInt(getExpPropGroupListSize());
		break;
	case 18:
		resp->insertLong(getExpPropGroup(inv->getSignedIntParameter())->_getObjectID());
		break;
	case 19:
		setPersistent(inv->getBooleanParameter());
		break;
	case 20:
		setObjectID(inv->getUnsignedLongParameter());
		break;
	case 21:
		setTanoAttributes(inv->getAsciiParameter(_param0_setTanoAttributes__string_));
		break;
	case 22:
		resp->insertInt(getSchematicID());
		break;
	case 23:
		resp->insertInt(getSchematicCRC());
		break;
	case 24:
		resp->insertAscii(getName());
		break;
	case 25:
		resp->insertAscii(getGroupName());
		break;
	case 26:
		resp->insertInt(getComplexity());
		break;
	case 27:
		resp->insertInt(getSchematicSize());
		break;
	case 28:
		resp->insertInt(getObjectID());
		break;
	case 29:
		resp->insertAscii(getTanoAttributes());
		break;
	case 30:
		resp->insertSignedInt(getCraftingToolTab());
		break;
	default:
		return NULL;
	}

	return resp;
}

DraftSchematic* DraftSchematicAdapter::dsClone(DraftSchematic* ds) {
	return ((DraftSchematicImplementation*) impl)->dsClone(ds);
}

void DraftSchematicAdapter::addIngredient(const string& ingredientTemplateName, const string& ingredientTitleName, bool optional, const string& resourceType, unsigned int resourceQuantity) {
	return ((DraftSchematicImplementation*) impl)->addIngredient(ingredientTemplateName, ingredientTitleName, optional, resourceType, resourceQuantity);
}

void DraftSchematicAdapter::sendIngredientsToPlayer(Player* player) {
	return ((DraftSchematicImplementation*) impl)->sendIngredientsToPlayer(player);
}

void DraftSchematicAdapter::helperSendIngredientsToPlayer(ObjectControllerMessage* objMsg) {
	return ((DraftSchematicImplementation*) impl)->helperSendIngredientsToPlayer(objMsg);
}

void DraftSchematicAdapter::addExperimentalProperty(unsigned int groupNumber, const string& experimentalProperty, unsigned int weight) {
	return ((DraftSchematicImplementation*) impl)->addExperimentalProperty(groupNumber, experimentalProperty, weight);
}

void DraftSchematicAdapter::sendExperimentalPropertiesToPlayer(Player* player) {
	return ((DraftSchematicImplementation*) impl)->sendExperimentalPropertiesToPlayer(player);
}

DraftSchematicIngredient* DraftSchematicAdapter::getIngredient(int index) {
	return ((DraftSchematicImplementation*) impl)->getIngredient(index);
}

int DraftSchematicAdapter::getIngredientListSize() {
	return ((DraftSchematicImplementation*) impl)->getIngredientListSize();
}

void DraftSchematicAdapter::addExpPropTitle(const string& title) {
	return ((DraftSchematicImplementation*) impl)->addExpPropTitle(title);
}

int DraftSchematicAdapter::getExpPropTitlesListSize() {
	return ((DraftSchematicImplementation*) impl)->getExpPropTitlesListSize();
}

string& DraftSchematicAdapter::getExpPropTitle(int index) {
	return ((DraftSchematicImplementation*) impl)->getExpPropTitle(index);
}

int DraftSchematicAdapter::getExpPropGroupListSize() {
	return ((DraftSchematicImplementation*) impl)->getExpPropGroupListSize();
}

DraftSchematicExpPropGroup* DraftSchematicAdapter::getExpPropGroup(int index) {
	return ((DraftSchematicImplementation*) impl)->getExpPropGroup(index);
}

void DraftSchematicAdapter::setPersistent(bool status) {
	return ((DraftSchematicImplementation*) impl)->setPersistent(status);
}

void DraftSchematicAdapter::setObjectID(unsigned long long objID) {
	return ((DraftSchematicImplementation*) impl)->setObjectID(objID);
}

void DraftSchematicAdapter::setTanoAttributes(string& attributes) {
	return ((DraftSchematicImplementation*) impl)->setTanoAttributes(attributes);
}

unsigned int DraftSchematicAdapter::getSchematicID() {
	return ((DraftSchematicImplementation*) impl)->getSchematicID();
}

unsigned int DraftSchematicAdapter::getSchematicCRC() {
	return ((DraftSchematicImplementation*) impl)->getSchematicCRC();
}

string& DraftSchematicAdapter::getName() {
	return ((DraftSchematicImplementation*) impl)->getName();
}

string& DraftSchematicAdapter::getGroupName() {
	return ((DraftSchematicImplementation*) impl)->getGroupName();
}

unsigned int DraftSchematicAdapter::getComplexity() {
	return ((DraftSchematicImplementation*) impl)->getComplexity();
}

unsigned int DraftSchematicAdapter::getSchematicSize() {
	return ((DraftSchematicImplementation*) impl)->getSchematicSize();
}

unsigned int DraftSchematicAdapter::getObjectID() {
	return ((DraftSchematicImplementation*) impl)->getObjectID();
}

string& DraftSchematicAdapter::getTanoAttributes() {
	return ((DraftSchematicImplementation*) impl)->getTanoAttributes();
}

int DraftSchematicAdapter::getCraftingToolTab() {
	return ((DraftSchematicImplementation*) impl)->getCraftingToolTab();
}

/*
 *	DraftSchematicHelper
 */

DraftSchematicHelper* DraftSchematicHelper::staticInitializer = DraftSchematicHelper::instance();

DraftSchematicHelper::DraftSchematicHelper() {
	className = "DraftSchematic";

	DistributedObjectBroker::instance()->registerClass(className, this);
}

void DraftSchematicHelper::finalizeHelper() {
	DraftSchematicHelper::finalize();
}

DistributedObject* DraftSchematicHelper::instantiateObject() {
	return new DraftSchematic();
}

DistributedObjectAdapter* DraftSchematicHelper::createAdapter(DistributedObjectServant* obj) {
	DistributedObjectAdapter* adapter = new DraftSchematicAdapter((DraftSchematicImplementation*) obj);

	DistributedObjectStub* stub = new DraftSchematic(obj);
	stub->_setClassName(className);
	stub->_setClassHelper(this);

	adapter->setStub(stub);

	obj->_setStub(stub);

	return adapter;
}

/*
 *	DraftSchematicServant
 */

DraftSchematicServant::DraftSchematicServant() {
	_classHelper = DraftSchematicHelper::instance();
}

DraftSchematicServant::~DraftSchematicServant() {
}

void DraftSchematicServant::_setStub(DistributedObjectStub* stub) {
	_this = (DraftSchematic*) stub;
}

DistributedObjectStub* DraftSchematicServant::_getStub() {
	return _this;
}

