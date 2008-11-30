/*
Copyright (C) 2007 <SWGEmu>

This File is part of Core3.

This program is free software; you can redistribute
it and/or modify it under the terms of the GNU Lesser
General Public License as published by the Free Software
Foundation; either version 2 of the License,
or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
See the GNU Lesser General Public License for
more details.

You should have received a copy of the GNU Lesser General
Public License along with this program; if not, write to
the Free Software Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA

Linking Engine3 statically or dynamically with other modules
is making a combined work based on Engine3.
Thus, the terms and conditions of the GNU Lesser General Public License
cover the whole combination.

In addition, as a special exception, the copyright holders of Engine3
give you permission to combine Engine3 program with free software
programs or libraries that are released under the GNU LGPL and with
code included in the standard release of Core3 under the GNU LGPL
license (or modified versions of such code, with unchanged license).
You may copy and distribute such a system following the terms of the
GNU LGPL for Engine3 and the licenses of the other code concerned,
provided that you include the source code of that other code when
and as the GNU LGPL requires distribution of source code.

Note that people who make modified versions of Engine3 are not obligated
to grant this special exception for their modified versions;
it is their choice whether to do so. The GNU Lesser General Public License
gives permission to release a modified version without this exception;
this exception also makes it possible to release a modified version
which carries forward this exception.
*/

#include "../../../../packets.h"

#include "../../../../objects.h"

#include "Component.h"
#include "ComponentImplementation.h"

#include "../../../../ZoneClientSession.h"

ComponentImplementation::ComponentImplementation(uint64 object_id, uint32 tempCRC,
		const UnicodeString& n, const String& tempn) : ComponentServant(object_id, tempCRC, n, tempn,
				COMPONENT) {
	objectCRC = tempCRC;

	templateTypeName = "obj_n";
	templateName = tempn;

	name = n;

	init();
}

ComponentImplementation::ComponentImplementation(CreatureObject* creature, uint32 tempCRC,
		const UnicodeString& n, const String& tempn) : ComponentServant(creature, tempCRC, n, tempn,
				COMPONENT) {
	objectCRC = tempCRC;

	templateTypeName = "obj_n";
	templateName = tempn;

	name = n;

	init();
}

ComponentImplementation::ComponentImplementation(Component* component, uint64 oid) :
	ComponentServant(oid, COMPONENT) {

	component->lock();

	objectCRC = component->getObjectCRC();
	templateTypeName = component->getTemplateTypeName();
	templateName = component->getTemplateName();
	name = component->getName();
	objectCount = component->getObjectCount();

	craftersName = component->getCraftersName();
	String tempattribute = "craftersname";
	itemAttributes->setStringAttribute(tempattribute, craftersName);

	String tempattribute2 = "craftedserial";
	craftedSerial = component->getCraftedSerial();
	itemAttributes->setStringAttribute(tempattribute2, craftedSerial);

	String property;

	for (int i = 0; i < component->getPropertyCount(); ++i) {
		property = component->getProperty(i);

		float value = component->getAttributeValue(property);
		int precision = component->getAttributePrecision(property);
		String title = component->getAttributeTitle(property);

		keyList.add(property);
		attributeMap.put(property, value);
		itemAttributes->setFloatAttribute(property, value);
		precisionMap.put(property, precision);
		titleMap.put(property, title);
	}

	savePrecisionList();
	saveTitleList();

	itemAttributes->getAttributeString(attributeString);

	component->unlock();
}


ComponentImplementation::~ComponentImplementation(){
	attributeMap.removeAll();
	precisionMap.removeAll();
	titleMap.removeAll();
	keyList.removeAll();
}

Component* ComponentImplementation::cloneComponent(Component* component, uint64 oid) {
	if (component != NULL) {
		return new Component(component, oid);
	} else {
		return NULL;
	}
}

void ComponentImplementation::sendRadialResponseTo(Player* player, ObjectMenuResponse* omr) {
	omr->finish();

	player->sendMessage(omr);
}

void ComponentImplementation::init() {
	parseAttributeString();
	parsePrecisionString();
	parseTitleString();
}

int ComponentImplementation::useObject(Player* player) {
	return 0;
}

void ComponentImplementation::generateAttributes(SceneObject* obj) {
	if (!obj->isPlayer())
		return;

	String attribute;

	float value;
	double power;
	int precision;

	String footer;

	Player* player = (Player*) obj;

	AttributeListMessage* alm = new AttributeListMessage(_this);
	alm->insertAttribute("volume", "1");

	if (craftersName != "") {
		alm->insertAttribute("crafter", craftersName);
	}

	if (craftedSerial != "") {
		alm->insertAttribute("serial_number", craftedSerial);
	}

	for (int i = 0; i < keyList.size(); ++i) {
		footer = "";

		attribute = keyList.get(i);
		value = attributeMap.get(attribute);
		precision = precisionMap.get(attribute);

		if (precision >= 0) {
			if (precision >= 10) {
				footer = "%";
				precision -= 10;
			}

			StringBuffer displayvalue;

			displayvalue << getPrecision(value, precision);

			displayvalue << footer;

			alm->insertAttribute(attribute, displayvalue.toString());
		}
	}

	player->sendMessage(alm);
}

void ComponentImplementation::parseItemAttributes(){
	parseAttributeString();
	parsePrecisionString();
	parseTitleString();

	String temp = "craftersname";
	craftersName = itemAttributes->getStringAttribute(temp);

	temp = "craftedserial";
	craftedSerial = itemAttributes->getStringAttribute(temp);

	temp = "looted";
	wasLooted = itemAttributes->getBooleanAttribute(temp);
}

float ComponentImplementation::getAttributeValue(String& attributeName){
	return attributeMap.get(attributeName);
}

int ComponentImplementation::getAttributePrecision(String& attributeName){
	return precisionMap.get(attributeName);
}

String& ComponentImplementation::getAttributeTitle(String& attributeName){
	return titleMap.get(attributeName);
}

void ComponentImplementation::updateCraftingValues(DraftSchematic* draftSchematic){
	DraftSchematicValues* craftingValues = draftSchematic->getCraftingValues();

	String attribute;
	float value;
	int precision;
	String title;

	attributeMap.removeAll();
	precisionMap.removeAll();
	titleMap.removeAll();
	keyList.removeAll();

	for (int i = 0; i < draftSchematic->getAttributesToSetListSize(); ++i) {
		value = craftingValues->getAttributeAndValue(draftSchematic, attribute, i);

		keyList.add(attribute);
	}

	for (int i = 0; i < craftingValues->getExperimentalPropertySubtitleSize(); ++i){
		attribute = craftingValues->getExperimentalPropertySubtitle(i);

		//value = craftingValues->getAttributeAndValue(draftSchematic, attribute, i);
		//precision = craftingValues->getPrecision(draftSchematic, i);
		//title = craftingValues->getExperimentalPropertyTitle(attribute);

		value = craftingValues->getCurrentValue(attribute);
		precision = craftingValues->getPrecision(attribute);
		title = craftingValues->getExperimentalPropertyTitle(attribute);

		if (!hasKey(attribute))
			keyList.add(attribute);

		itemAttributes->setFloatAttribute(attribute, value);

		attributeMap.put(attribute, value);
		precisionMap.put(attribute, precision);
		titleMap.put(attribute, title);

	}

	savePrecisionList();
	saveTitleList();
	setUpdated(true);
}

void ComponentImplementation::savePrecisionList(){
	StringBuffer ss;
	String element;

	for (int i = 0; i < keyList.size(); ++i){
		element = keyList.get(i);

		ss << element << "=" << precisionMap.get(element) << ";";
	}

	String attribute = "precision";
	String value = ss.toString();

	itemAttributes->setStringAttribute(attribute, value);
}

void ComponentImplementation::saveTitleList(){
	StringBuffer ss;
	String element;

	for (int i = 0; i < keyList.size(); ++i){
		element = keyList.get(i);

		ss << element << "=" << titleMap.get(element) << ";";
	}

	String attribute = "title";
	String value = ss.toString();

	itemAttributes->setStringAttribute(attribute, value);
}

void ComponentImplementation::parsePrecisionString() {
	int index1 = 0;
	int index2;
	int index3;

	precisionMap.removeAll();
	keyList.removeAll();

	String attribute = "precision";
	String precisionString = itemAttributes->getStringAttribute(attribute);

	while ((index2 = precisionString.indexOf(";", index1)) != -1) {
		String attrPair = precisionString.subString(index1, index2);

		if ((index3 = attrPair.indexOf("=", 0)) != -1) {
			String key = attrPair.subString(0, index3);
			String value = attrPair.subString(index3 + 1, attrPair.length());

			precisionMap.put(key, Integer::valueOf(value));
			keyList.add(key);
		}

		index1 = index2 + 1;
	}
}

void ComponentImplementation::parseTitleString() {
	int index1 = 0;
	int index2;
	int index3;

	titleMap.removeAll();

	String attribute = "title";
	String titleString = itemAttributes->getStringAttribute(attribute);

	while ((index2 = titleString.indexOf(";", index1)) != -1) {
		String attrPair = titleString.subString(index1, index2);

		if ((index3 = attrPair.indexOf("=", 0)) != -1) {
			String key = attrPair.subString(0, index3);
			String value = attrPair.subString(index3 + 1, attrPair.length());

			titleMap.put(key, value);
		}

		index1 = index2 + 1;
	}
}

void ComponentImplementation::parseAttributeString() {
	int index1 = 0;
	int index2;
	int index3;

	attributeMap.removeAll();
	itemAttributes->getAttributeString(attributeString);

	while ((index2 = attributeString.indexOf(":", index1)) != -1) {
		String attrPair = attributeString.subString(index1, index2);

		if ((index3 = attrPair.indexOf("=", 0)) != -1) {
			String key = attrPair.subString(0, index3);
			String value = attrPair.subString(index3 + 1, attrPair.length());

			attributeMap.put(key, Float::valueOf(value));
		}

		index1 = index2 + 1;
	}
}

