/*
 *	server/zone/objects/draftschematic/DraftSchematic.cpp generated by engine3 IDL compiler 0.55
 */

#include "DraftSchematic.h"

#include "DraftSchematicImplementation.h"

#include "../scene/SceneObject.h"

#include "../player/Player.h"

#include "DraftSchematicIngredient.h"

#include "DraftSchematicAttribute.h"

#include "DraftSchematicValues.h"

#include "DraftSchematicExpPropGroup.h"

#include "../../packets/object/ObjectControllerMessage.h"

/*
 *	DraftSchematicStub
 */

DraftSchematic::DraftSchematic(unsigned int schematicID, const String& objName, const String& StringName, unsigned int objCRC, const String& groupName, unsigned int complexity, unsigned int schematicSize, int craftingToolTab) : ManagedObject(DummyConstructorParameter::instance()) {
	_impl = new DraftSchematicImplementation(schematicID, objName, StringName, objCRC, groupName, complexity, schematicSize, craftingToolTab);
	_impl->_setStub(this);
}

DraftSchematic::DraftSchematic(DraftSchematic* draftSchematic) : ManagedObject(DummyConstructorParameter::instance()) {
	_impl = new DraftSchematicImplementation(draftSchematic);
	_impl->_setStub(this);
}

DraftSchematic::DraftSchematic(DummyConstructorParameter* param) : ManagedObject(param) {
}

DraftSchematic::~DraftSchematic() {
}

DraftSchematic* DraftSchematic::dsClone(DraftSchematic* draftSchematic) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 6);
		method.addObjectParameter(draftSchematic);

		return (DraftSchematic*) method.executeWithObjectReturn();
	} else
		return ((DraftSchematicImplementation*) _impl)->dsClone(draftSchematic);
}

void DraftSchematic::destroy(Player* player) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 7);
		method.addObjectParameter(player);

		method.executeWithVoidReturn();
	} else
		((DraftSchematicImplementation*) _impl)->destroy(player);
}

void DraftSchematic::sendTo(Player* player) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 8);
		method.addObjectParameter(player);

		method.executeWithVoidReturn();
	} else
		((DraftSchematicImplementation*) _impl)->sendTo(player);
}

void DraftSchematic::addExperimentalProperty(unsigned int groupNumber, const String& experimentalProperty, unsigned int weight, String& subtitle) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 9);
		method.addUnsignedIntParameter(groupNumber);
		method.addAsciiParameter(experimentalProperty);
		method.addUnsignedIntParameter(weight);
		method.addAsciiParameter(subtitle);

		method.executeWithVoidReturn();
	} else
		((DraftSchematicImplementation*) _impl)->addExperimentalProperty(groupNumber, experimentalProperty, weight, subtitle);
}

void DraftSchematic::sendExperimentalPropertiesToPlayer(Player* player) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 10);
		method.addObjectParameter(player);

		method.executeWithVoidReturn();
	} else
		((DraftSchematicImplementation*) _impl)->sendExperimentalPropertiesToPlayer(player);
}

void DraftSchematic::increaseComplexity() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 11);

		method.executeWithVoidReturn();
	} else
		((DraftSchematicImplementation*) _impl)->increaseComplexity();
}

void DraftSchematic::increaseExpCounter() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 12);

		method.executeWithVoidReturn();
	} else
		((DraftSchematicImplementation*) _impl)->increaseExpCounter();
}

void DraftSchematic::sendIngredientsToPlayer(Player* player) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 13);
		method.addObjectParameter(player);

		method.executeWithVoidReturn();
	} else
		((DraftSchematicImplementation*) _impl)->sendIngredientsToPlayer(player);
}

void DraftSchematic::helperSendIngredientsToPlayer(ObjectControllerMessage* objMsg) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 14);
		method.addObjectParameter(objMsg);

		method.executeWithVoidReturn();
	} else
		((DraftSchematicImplementation*) _impl)->helperSendIngredientsToPlayer(objMsg);
}

void DraftSchematic::addIngredient(const String& ingredientTemplateName, const String& ingredientTitleName, const int optional, const String& resourceType, unsigned int resourceQuantity, unsigned int combineType, unsigned int contribution) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 15);
		method.addAsciiParameter(ingredientTemplateName);
		method.addAsciiParameter(ingredientTitleName);
		method.addSignedIntParameter(optional);
		method.addAsciiParameter(resourceType);
		method.addUnsignedIntParameter(resourceQuantity);
		method.addUnsignedIntParameter(combineType);
		method.addUnsignedIntParameter(contribution);

		method.executeWithVoidReturn();
	} else
		((DraftSchematicImplementation*) _impl)->addIngredient(ingredientTemplateName, ingredientTitleName, optional, resourceType, resourceQuantity, combineType, contribution);
}

DraftSchematicIngredient* DraftSchematic::getIngredient(int index) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 16);
		method.addSignedIntParameter(index);

		return (DraftSchematicIngredient*) method.executeWithObjectReturn();
	} else
		return ((DraftSchematicImplementation*) _impl)->getIngredient(index);
}

int DraftSchematic::getIngredientListSize() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 17);

		return method.executeWithSignedIntReturn();
	} else
		return ((DraftSchematicImplementation*) _impl)->getIngredientListSize();
}

int DraftSchematic::getRequiredIngredientCount() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 18);

		return method.executeWithSignedIntReturn();
	} else
		return ((DraftSchematicImplementation*) _impl)->getRequiredIngredientCount();
}

void DraftSchematic::setPersistent(bool status) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 19);
		method.addBooleanParameter(status);

		method.executeWithVoidReturn();
	} else
		((DraftSchematicImplementation*) _impl)->setPersistent(status);
}

void DraftSchematic::setObjectID(unsigned long long objID) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 20);
		method.addUnsignedLongParameter(objID);

		method.executeWithVoidReturn();
	} else
		((DraftSchematicImplementation*) _impl)->setObjectID(objID);
}

void DraftSchematic::setTanoAttributes(String& attributes) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 21);
		method.addAsciiParameter(attributes);

		method.executeWithVoidReturn();
	} else
		((DraftSchematicImplementation*) _impl)->setTanoAttributes(attributes);
}

void DraftSchematic::setContainer(SceneObject* container) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 22);
		method.addObjectParameter(container);

		method.executeWithVoidReturn();
	} else
		((DraftSchematicImplementation*) _impl)->setContainer(container);
}

void DraftSchematic::setXpType(String& type) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 23);
		method.addAsciiParameter(type);

		method.executeWithVoidReturn();
	} else
		((DraftSchematicImplementation*) _impl)->setXpType(type);
}

void DraftSchematic::setXp(int x) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 24);
		method.addSignedIntParameter(x);

		method.executeWithVoidReturn();
	} else
		((DraftSchematicImplementation*) _impl)->setXp(x);
}

void DraftSchematic::setExpCounter() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 25);

		method.executeWithVoidReturn();
	} else
		((DraftSchematicImplementation*) _impl)->setExpCounter();
}

void DraftSchematic::setExpPoints(int points) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 26);
		method.addSignedIntParameter(points);

		method.executeWithVoidReturn();
	} else
		((DraftSchematicImplementation*) _impl)->setExpPoints(points);
}

void DraftSchematic::setExpFailure(float rate) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 27);
		method.addFloatParameter(rate);

		method.executeWithVoidReturn();
	} else
		((DraftSchematicImplementation*) _impl)->setExpFailure(rate);
}

void DraftSchematic::setExperimentingSkill(const String& exp) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 28);
		method.addAsciiParameter(exp);

		method.executeWithVoidReturn();
	} else
		((DraftSchematicImplementation*) _impl)->setExperimentingSkill(exp);
}

void DraftSchematic::setCustomizationSkill(const String& cust) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 29);
		method.addAsciiParameter(cust);

		method.executeWithVoidReturn();
	} else
		((DraftSchematicImplementation*) _impl)->setCustomizationSkill(cust);
}

void DraftSchematic::addCustomizationOption(const String& cust, const int value) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 30);
		method.addAsciiParameter(cust);
		method.addSignedIntParameter(value);

		method.executeWithVoidReturn();
	} else
		((DraftSchematicImplementation*) _impl)->addCustomizationOption(cust, value);
}

void DraftSchematic::setAssemblySkill(const String& ass) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 31);
		method.addAsciiParameter(ass);

		method.executeWithVoidReturn();
	} else
		((DraftSchematicImplementation*) _impl)->setAssemblySkill(ass);
}

void DraftSchematic::setFinished() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 32);

		method.executeWithVoidReturn();
	} else
		((DraftSchematicImplementation*) _impl)->setFinished();
}

void DraftSchematic::setCrafter(Player* crafter) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 33);
		method.addObjectParameter(crafter);

		method.executeWithVoidReturn();
	} else
		((DraftSchematicImplementation*) _impl)->setCrafter(crafter);
}

int DraftSchematic::getAttributesToSetListSize() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 34);

		return method.executeWithSignedIntReturn();
	} else
		return ((DraftSchematicImplementation*) _impl)->getAttributesToSetListSize();
}

DraftSchematicAttribute* DraftSchematic::getAttributeToSet(const int i) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 35);
		method.addSignedIntParameter(i);

		return (DraftSchematicAttribute*) method.executeWithObjectReturn();
	} else
		return ((DraftSchematicImplementation*) _impl)->getAttributeToSet(i);
}

DraftSchematicAttribute* DraftSchematic::getAttributeToSet(const String& name) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 36);
		method.addAsciiParameter(name);

		return (DraftSchematicAttribute*) method.executeWithObjectReturn();
	} else
		return ((DraftSchematicImplementation*) _impl)->getAttributeToSet(name);
}

void DraftSchematic::addAttributeToSet(const String& attribute, float minVal, float maxVal, const String& attributeExpProp, const int precision) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 37);
		method.addAsciiParameter(attribute);
		method.addFloatParameter(minVal);
		method.addFloatParameter(maxVal);
		method.addAsciiParameter(attributeExpProp);
		method.addSignedIntParameter(precision);

		method.executeWithVoidReturn();
	} else
		((DraftSchematicImplementation*) _impl)->addAttributeToSet(attribute, minVal, maxVal, attributeExpProp, precision);
}

int DraftSchematic::getExpPropGroupListSize() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 38);

		return method.executeWithSignedIntReturn();
	} else
		return ((DraftSchematicImplementation*) _impl)->getExpPropGroupListSize();
}

DraftSchematicExpPropGroup* DraftSchematic::getExpPropGroup(int index) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 39);
		method.addSignedIntParameter(index);

		return (DraftSchematicExpPropGroup*) method.executeWithObjectReturn();
	} else
		return ((DraftSchematicImplementation*) _impl)->getExpPropGroup(index);
}

unsigned int DraftSchematic::getSchematicID() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 40);

		return method.executeWithUnsignedIntReturn();
	} else
		return ((DraftSchematicImplementation*) _impl)->getSchematicID();
}

unsigned int DraftSchematic::getSchematicCRC() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 41);

		return method.executeWithUnsignedIntReturn();
	} else
		return ((DraftSchematicImplementation*) _impl)->getSchematicCRC();
}

String& DraftSchematic::getName() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 42);

		method.executeWithAsciiReturn(_return_getName);
		return _return_getName;
	} else
		return ((DraftSchematicImplementation*) _impl)->getName();
}

String& DraftSchematic::getStringName() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 43);

		method.executeWithAsciiReturn(_return_getStringName);
		return _return_getStringName;
	} else
		return ((DraftSchematicImplementation*) _impl)->getStringName();
}

String& DraftSchematic::getGroupName() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 44);

		method.executeWithAsciiReturn(_return_getGroupName);
		return _return_getGroupName;
	} else
		return ((DraftSchematicImplementation*) _impl)->getGroupName();
}

unsigned int DraftSchematic::getComplexity() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 45);

		return method.executeWithUnsignedIntReturn();
	} else
		return ((DraftSchematicImplementation*) _impl)->getComplexity();
}

unsigned int DraftSchematic::getSchematicSize() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 46);

		return method.executeWithUnsignedIntReturn();
	} else
		return ((DraftSchematicImplementation*) _impl)->getSchematicSize();
}

unsigned int DraftSchematic::getObjectID() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 47);

		return method.executeWithUnsignedIntReturn();
	} else
		return ((DraftSchematicImplementation*) _impl)->getObjectID();
}

String& DraftSchematic::getTanoAttributes() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 48);

		method.executeWithAsciiReturn(_return_getTanoAttributes);
		return _return_getTanoAttributes;
	} else
		return ((DraftSchematicImplementation*) _impl)->getTanoAttributes();
}

int DraftSchematic::getCraftingToolTab() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 49);

		return method.executeWithSignedIntReturn();
	} else
		return ((DraftSchematicImplementation*) _impl)->getCraftingToolTab();
}

SceneObject* DraftSchematic::getContainer() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 50);

		return (SceneObject*) method.executeWithObjectReturn();
	} else
		return ((DraftSchematicImplementation*) _impl)->getContainer();
}

String& DraftSchematic::getXpType() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 51);

		method.executeWithAsciiReturn(_return_getXpType);
		return _return_getXpType;
	} else
		return ((DraftSchematicImplementation*) _impl)->getXpType();
}

int DraftSchematic::getXp() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 52);

		return method.executeWithSignedIntReturn();
	} else
		return ((DraftSchematicImplementation*) _impl)->getXp();
}

String& DraftSchematic::getExperimentingSkill() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 53);

		method.executeWithAsciiReturn(_return_getExperimentingSkill);
		return _return_getExperimentingSkill;
	} else
		return ((DraftSchematicImplementation*) _impl)->getExperimentingSkill();
}

String& DraftSchematic::getCustomizationSkill() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 54);

		method.executeWithAsciiReturn(_return_getCustomizationSkill);
		return _return_getCustomizationSkill;
	} else
		return ((DraftSchematicImplementation*) _impl)->getCustomizationSkill();
}

String& DraftSchematic::getCustomizationOption(const int i) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 55);
		method.addSignedIntParameter(i);

		method.executeWithAsciiReturn(_return_getCustomizationOption);
		return _return_getCustomizationOption;
	} else
		return ((DraftSchematicImplementation*) _impl)->getCustomizationOption(i);
}

int DraftSchematic::getCustomizationDefaultValue(const int i) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 56);
		method.addSignedIntParameter(i);

		return method.executeWithSignedIntReturn();
	} else
		return ((DraftSchematicImplementation*) _impl)->getCustomizationDefaultValue(i);
}

int DraftSchematic::getCustomizationOptionCount() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 57);

		return method.executeWithSignedIntReturn();
	} else
		return ((DraftSchematicImplementation*) _impl)->getCustomizationOptionCount();
}

String& DraftSchematic::getAssemblySkill() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 58);

		method.executeWithAsciiReturn(_return_getAssemblySkill);
		return _return_getAssemblySkill;
	} else
		return ((DraftSchematicImplementation*) _impl)->getAssemblySkill();
}

int DraftSchematic::getExpPoints() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 59);

		return method.executeWithSignedIntReturn();
	} else
		return ((DraftSchematicImplementation*) _impl)->getExpPoints();
}

int DraftSchematic::getExpCounter() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 60);

		return method.executeWithSignedIntReturn();
	} else
		return ((DraftSchematicImplementation*) _impl)->getExpCounter();
}

float DraftSchematic::getExpFailure() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 61);

		return method.executeWithFloatReturn();
	} else
		return ((DraftSchematicImplementation*) _impl)->getExpFailure();
}

Player* DraftSchematic::getCrafter() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 62);

		return (Player*) method.executeWithObjectReturn();
	} else
		return ((DraftSchematicImplementation*) _impl)->getCrafter();
}

DraftSchematicValues* DraftSchematic::getCraftingValues() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 63);

		return (DraftSchematicValues*) method.executeWithObjectReturn();
	} else
		return ((DraftSchematicImplementation*) _impl)->getCraftingValues();
}

bool DraftSchematic::isFinished() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 64);

		return method.executeWithBooleanReturn();
	} else
		return ((DraftSchematicImplementation*) _impl)->isFinished();
}

void DraftSchematic::toString() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 65);

		method.executeWithVoidReturn();
	} else
		((DraftSchematicImplementation*) _impl)->toString();
}

/*
 *	DraftSchematicAdapter
 */

DraftSchematicAdapter::DraftSchematicAdapter(DraftSchematicImplementation* obj) : ManagedObjectAdapter(obj) {
}

Packet* DraftSchematicAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	Packet* resp = new MethodReturnMessage(0);

	switch (methid) {
	case 6:
		resp->insertLong(dsClone((DraftSchematic*) inv->getObjectParameter())->_getObjectID());
		break;
	case 7:
		destroy((Player*) inv->getObjectParameter());
		break;
	case 8:
		sendTo((Player*) inv->getObjectParameter());
		break;
	case 9:
		addExperimentalProperty(inv->getUnsignedIntParameter(), inv->getAsciiParameter(_param1_addExperimentalProperty__int_String_int_String_), inv->getUnsignedIntParameter(), inv->getAsciiParameter(_param3_addExperimentalProperty__int_String_int_String_));
		break;
	case 10:
		sendExperimentalPropertiesToPlayer((Player*) inv->getObjectParameter());
		break;
	case 11:
		increaseComplexity();
		break;
	case 12:
		increaseExpCounter();
		break;
	case 13:
		sendIngredientsToPlayer((Player*) inv->getObjectParameter());
		break;
	case 14:
		helperSendIngredientsToPlayer((ObjectControllerMessage*) inv->getObjectParameter());
		break;
	case 15:
		addIngredient(inv->getAsciiParameter(_param0_addIngredient__String_String_int_String_int_int_int_), inv->getAsciiParameter(_param1_addIngredient__String_String_int_String_int_int_int_), inv->getSignedIntParameter(), inv->getAsciiParameter(_param3_addIngredient__String_String_int_String_int_int_int_), inv->getUnsignedIntParameter(), inv->getUnsignedIntParameter(), inv->getUnsignedIntParameter());
		break;
	case 16:
		resp->insertLong(getIngredient(inv->getSignedIntParameter())->_getObjectID());
		break;
	case 17:
		resp->insertSignedInt(getIngredientListSize());
		break;
	case 18:
		resp->insertSignedInt(getRequiredIngredientCount());
		break;
	case 19:
		setPersistent(inv->getBooleanParameter());
		break;
	case 20:
		setObjectID(inv->getUnsignedLongParameter());
		break;
	case 21:
		setTanoAttributes(inv->getAsciiParameter(_param0_setTanoAttributes__String_));
		break;
	case 22:
		setContainer((SceneObject*) inv->getObjectParameter());
		break;
	case 23:
		setXpType(inv->getAsciiParameter(_param0_setXpType__String_));
		break;
	case 24:
		setXp(inv->getSignedIntParameter());
		break;
	case 25:
		setExpCounter();
		break;
	case 26:
		setExpPoints(inv->getSignedIntParameter());
		break;
	case 27:
		setExpFailure(inv->getFloatParameter());
		break;
	case 28:
		setExperimentingSkill(inv->getAsciiParameter(_param0_setExperimentingSkill__String_));
		break;
	case 29:
		setCustomizationSkill(inv->getAsciiParameter(_param0_setCustomizationSkill__String_));
		break;
	case 30:
		addCustomizationOption(inv->getAsciiParameter(_param0_addCustomizationOption__String_int_), inv->getSignedIntParameter());
		break;
	case 31:
		setAssemblySkill(inv->getAsciiParameter(_param0_setAssemblySkill__String_));
		break;
	case 32:
		setFinished();
		break;
	case 33:
		setCrafter((Player*) inv->getObjectParameter());
		break;
	case 34:
		resp->insertSignedInt(getAttributesToSetListSize());
		break;
	case 35:
		resp->insertLong(getAttributeToSet(inv->getSignedIntParameter())->_getObjectID());
		break;
	case 36:
		resp->insertLong(getAttributeToSet(inv->getAsciiParameter(_param0_getAttributeToSet__String_))->_getObjectID());
		break;
	case 37:
		addAttributeToSet(inv->getAsciiParameter(_param0_addAttributeToSet__String_float_float_String_int_), inv->getFloatParameter(), inv->getFloatParameter(), inv->getAsciiParameter(_param3_addAttributeToSet__String_float_float_String_int_), inv->getSignedIntParameter());
		break;
	case 38:
		resp->insertSignedInt(getExpPropGroupListSize());
		break;
	case 39:
		resp->insertLong(getExpPropGroup(inv->getSignedIntParameter())->_getObjectID());
		break;
	case 40:
		resp->insertInt(getSchematicID());
		break;
	case 41:
		resp->insertInt(getSchematicCRC());
		break;
	case 42:
		resp->insertAscii(getName());
		break;
	case 43:
		resp->insertAscii(getStringName());
		break;
	case 44:
		resp->insertAscii(getGroupName());
		break;
	case 45:
		resp->insertInt(getComplexity());
		break;
	case 46:
		resp->insertInt(getSchematicSize());
		break;
	case 47:
		resp->insertInt(getObjectID());
		break;
	case 48:
		resp->insertAscii(getTanoAttributes());
		break;
	case 49:
		resp->insertSignedInt(getCraftingToolTab());
		break;
	case 50:
		resp->insertLong(getContainer()->_getObjectID());
		break;
	case 51:
		resp->insertAscii(getXpType());
		break;
	case 52:
		resp->insertSignedInt(getXp());
		break;
	case 53:
		resp->insertAscii(getExperimentingSkill());
		break;
	case 54:
		resp->insertAscii(getCustomizationSkill());
		break;
	case 55:
		resp->insertAscii(getCustomizationOption(inv->getSignedIntParameter()));
		break;
	case 56:
		resp->insertSignedInt(getCustomizationDefaultValue(inv->getSignedIntParameter()));
		break;
	case 57:
		resp->insertSignedInt(getCustomizationOptionCount());
		break;
	case 58:
		resp->insertAscii(getAssemblySkill());
		break;
	case 59:
		resp->insertSignedInt(getExpPoints());
		break;
	case 60:
		resp->insertSignedInt(getExpCounter());
		break;
	case 61:
		resp->insertFloat(getExpFailure());
		break;
	case 62:
		resp->insertLong(getCrafter()->_getObjectID());
		break;
	case 63:
		resp->insertLong(getCraftingValues()->_getObjectID());
		break;
	case 64:
		resp->insertBoolean(isFinished());
		break;
	case 65:
		toString();
		break;
	default:
		return NULL;
	}

	return resp;
}

DraftSchematic* DraftSchematicAdapter::dsClone(DraftSchematic* draftSchematic) {
	return ((DraftSchematicImplementation*) impl)->dsClone(draftSchematic);
}

void DraftSchematicAdapter::destroy(Player* player) {
	return ((DraftSchematicImplementation*) impl)->destroy(player);
}

void DraftSchematicAdapter::sendTo(Player* player) {
	return ((DraftSchematicImplementation*) impl)->sendTo(player);
}

void DraftSchematicAdapter::addExperimentalProperty(unsigned int groupNumber, const String& experimentalProperty, unsigned int weight, String& subtitle) {
	return ((DraftSchematicImplementation*) impl)->addExperimentalProperty(groupNumber, experimentalProperty, weight, subtitle);
}

void DraftSchematicAdapter::sendExperimentalPropertiesToPlayer(Player* player) {
	return ((DraftSchematicImplementation*) impl)->sendExperimentalPropertiesToPlayer(player);
}

void DraftSchematicAdapter::increaseComplexity() {
	return ((DraftSchematicImplementation*) impl)->increaseComplexity();
}

void DraftSchematicAdapter::increaseExpCounter() {
	return ((DraftSchematicImplementation*) impl)->increaseExpCounter();
}

void DraftSchematicAdapter::sendIngredientsToPlayer(Player* player) {
	return ((DraftSchematicImplementation*) impl)->sendIngredientsToPlayer(player);
}

void DraftSchematicAdapter::helperSendIngredientsToPlayer(ObjectControllerMessage* objMsg) {
	return ((DraftSchematicImplementation*) impl)->helperSendIngredientsToPlayer(objMsg);
}

void DraftSchematicAdapter::addIngredient(const String& ingredientTemplateName, const String& ingredientTitleName, const int optional, const String& resourceType, unsigned int resourceQuantity, unsigned int combineType, unsigned int contribution) {
	return ((DraftSchematicImplementation*) impl)->addIngredient(ingredientTemplateName, ingredientTitleName, optional, resourceType, resourceQuantity, combineType, contribution);
}

DraftSchematicIngredient* DraftSchematicAdapter::getIngredient(int index) {
	return ((DraftSchematicImplementation*) impl)->getIngredient(index);
}

int DraftSchematicAdapter::getIngredientListSize() {
	return ((DraftSchematicImplementation*) impl)->getIngredientListSize();
}

int DraftSchematicAdapter::getRequiredIngredientCount() {
	return ((DraftSchematicImplementation*) impl)->getRequiredIngredientCount();
}

void DraftSchematicAdapter::setPersistent(bool status) {
	return ((DraftSchematicImplementation*) impl)->setPersistent(status);
}

void DraftSchematicAdapter::setObjectID(unsigned long long objID) {
	return ((DraftSchematicImplementation*) impl)->setObjectID(objID);
}

void DraftSchematicAdapter::setTanoAttributes(String& attributes) {
	return ((DraftSchematicImplementation*) impl)->setTanoAttributes(attributes);
}

void DraftSchematicAdapter::setContainer(SceneObject* container) {
	return ((DraftSchematicImplementation*) impl)->setContainer(container);
}

void DraftSchematicAdapter::setXpType(String& type) {
	return ((DraftSchematicImplementation*) impl)->setXpType(type);
}

void DraftSchematicAdapter::setXp(int x) {
	return ((DraftSchematicImplementation*) impl)->setXp(x);
}

void DraftSchematicAdapter::setExpCounter() {
	return ((DraftSchematicImplementation*) impl)->setExpCounter();
}

void DraftSchematicAdapter::setExpPoints(int points) {
	return ((DraftSchematicImplementation*) impl)->setExpPoints(points);
}

void DraftSchematicAdapter::setExpFailure(float rate) {
	return ((DraftSchematicImplementation*) impl)->setExpFailure(rate);
}

void DraftSchematicAdapter::setExperimentingSkill(const String& exp) {
	return ((DraftSchematicImplementation*) impl)->setExperimentingSkill(exp);
}

void DraftSchematicAdapter::setCustomizationSkill(const String& cust) {
	return ((DraftSchematicImplementation*) impl)->setCustomizationSkill(cust);
}

void DraftSchematicAdapter::addCustomizationOption(const String& cust, const int value) {
	return ((DraftSchematicImplementation*) impl)->addCustomizationOption(cust, value);
}

void DraftSchematicAdapter::setAssemblySkill(const String& ass) {
	return ((DraftSchematicImplementation*) impl)->setAssemblySkill(ass);
}

void DraftSchematicAdapter::setFinished() {
	return ((DraftSchematicImplementation*) impl)->setFinished();
}

void DraftSchematicAdapter::setCrafter(Player* crafter) {
	return ((DraftSchematicImplementation*) impl)->setCrafter(crafter);
}

int DraftSchematicAdapter::getAttributesToSetListSize() {
	return ((DraftSchematicImplementation*) impl)->getAttributesToSetListSize();
}

DraftSchematicAttribute* DraftSchematicAdapter::getAttributeToSet(const int i) {
	return ((DraftSchematicImplementation*) impl)->getAttributeToSet(i);
}

DraftSchematicAttribute* DraftSchematicAdapter::getAttributeToSet(const String& name) {
	return ((DraftSchematicImplementation*) impl)->getAttributeToSet(name);
}

void DraftSchematicAdapter::addAttributeToSet(const String& attribute, float minVal, float maxVal, const String& attributeExpProp, const int precision) {
	return ((DraftSchematicImplementation*) impl)->addAttributeToSet(attribute, minVal, maxVal, attributeExpProp, precision);
}

int DraftSchematicAdapter::getExpPropGroupListSize() {
	return ((DraftSchematicImplementation*) impl)->getExpPropGroupListSize();
}

DraftSchematicExpPropGroup* DraftSchematicAdapter::getExpPropGroup(int index) {
	return ((DraftSchematicImplementation*) impl)->getExpPropGroup(index);
}

unsigned int DraftSchematicAdapter::getSchematicID() {
	return ((DraftSchematicImplementation*) impl)->getSchematicID();
}

unsigned int DraftSchematicAdapter::getSchematicCRC() {
	return ((DraftSchematicImplementation*) impl)->getSchematicCRC();
}

String& DraftSchematicAdapter::getName() {
	return ((DraftSchematicImplementation*) impl)->getName();
}

String& DraftSchematicAdapter::getStringName() {
	return ((DraftSchematicImplementation*) impl)->getStringName();
}

String& DraftSchematicAdapter::getGroupName() {
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

String& DraftSchematicAdapter::getTanoAttributes() {
	return ((DraftSchematicImplementation*) impl)->getTanoAttributes();
}

int DraftSchematicAdapter::getCraftingToolTab() {
	return ((DraftSchematicImplementation*) impl)->getCraftingToolTab();
}

SceneObject* DraftSchematicAdapter::getContainer() {
	return ((DraftSchematicImplementation*) impl)->getContainer();
}

String& DraftSchematicAdapter::getXpType() {
	return ((DraftSchematicImplementation*) impl)->getXpType();
}

int DraftSchematicAdapter::getXp() {
	return ((DraftSchematicImplementation*) impl)->getXp();
}

String& DraftSchematicAdapter::getExperimentingSkill() {
	return ((DraftSchematicImplementation*) impl)->getExperimentingSkill();
}

String& DraftSchematicAdapter::getCustomizationSkill() {
	return ((DraftSchematicImplementation*) impl)->getCustomizationSkill();
}

String& DraftSchematicAdapter::getCustomizationOption(const int i) {
	return ((DraftSchematicImplementation*) impl)->getCustomizationOption(i);
}

int DraftSchematicAdapter::getCustomizationDefaultValue(const int i) {
	return ((DraftSchematicImplementation*) impl)->getCustomizationDefaultValue(i);
}

int DraftSchematicAdapter::getCustomizationOptionCount() {
	return ((DraftSchematicImplementation*) impl)->getCustomizationOptionCount();
}

String& DraftSchematicAdapter::getAssemblySkill() {
	return ((DraftSchematicImplementation*) impl)->getAssemblySkill();
}

int DraftSchematicAdapter::getExpPoints() {
	return ((DraftSchematicImplementation*) impl)->getExpPoints();
}

int DraftSchematicAdapter::getExpCounter() {
	return ((DraftSchematicImplementation*) impl)->getExpCounter();
}

float DraftSchematicAdapter::getExpFailure() {
	return ((DraftSchematicImplementation*) impl)->getExpFailure();
}

Player* DraftSchematicAdapter::getCrafter() {
	return ((DraftSchematicImplementation*) impl)->getCrafter();
}

DraftSchematicValues* DraftSchematicAdapter::getCraftingValues() {
	return ((DraftSchematicImplementation*) impl)->getCraftingValues();
}

bool DraftSchematicAdapter::isFinished() {
	return ((DraftSchematicImplementation*) impl)->isFinished();
}

void DraftSchematicAdapter::toString() {
	return ((DraftSchematicImplementation*) impl)->toString();
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
	return new DraftSchematic(DummyConstructorParameter::instance());
}

DistributedObjectAdapter* DraftSchematicHelper::createAdapter(DistributedObjectStub* obj) {
	DistributedObjectAdapter* adapter = new DraftSchematicAdapter((DraftSchematicImplementation*) obj->_getImplementation());

	obj->_setClassName(className);
	obj->_setClassHelper(this);

	adapter->setStub(obj);

	return adapter;
}

/*
 *	DraftSchematicServant
 */

DraftSchematicServant::DraftSchematicServant() : ManagedObjectImplementation() {
	_classHelper = DraftSchematicHelper::instance();
}

DraftSchematicServant::~DraftSchematicServant() {
}

void DraftSchematicServant::_setStub(DistributedObjectStub* stub) {
	_this = (DraftSchematic*) stub;
	ManagedObjectServant::_setStub(stub);
}

DistributedObjectStub* DraftSchematicServant::_getStub() {
	return _this;
}

