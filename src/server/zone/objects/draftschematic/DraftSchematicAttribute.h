/*
 *	server/zone/objects/draftschematic/DraftSchematicAttribute.h generated by engine3 IDL compiler 0.55
 */

#ifndef DRAFTSCHEMATICATTRIBUTE_H_
#define DRAFTSCHEMATICATTRIBUTE_H_

#include "engine/orb/DistributedObjectBroker.h"

class DraftSchematicAttribute : public DistributedObjectStub {
public:
	DraftSchematicAttribute(const String& attribute, float minVal, float maxVal, const String& attributeExpProp, const int precision);

	DraftSchematicAttribute(DraftSchematicAttribute* attrib);

	void setAttributeName(const String& attribute);

	void setMinValue(float minVal);

	void setMaxValue(float maxVal);

	void setAttributeExperimentalProperty(const String& attributeExpProp);

	String& getAttributeName();

	float getMinValue();

	float getMaxValue();

	float getRange();

	int getPrecision();

	String& getAttributeExperimentalProperty();

protected:
	DraftSchematicAttribute(DummyConstructorParameter* param);

	virtual ~DraftSchematicAttribute();

	String _return_getAttributeExperimentalProperty;
	String _return_getAttributeName;

	friend class DraftSchematicAttributeHelper;
};

class DraftSchematicAttributeImplementation;

class DraftSchematicAttributeAdapter : public DistributedObjectAdapter {
public:
	DraftSchematicAttributeAdapter(DraftSchematicAttributeImplementation* impl);

	Packet* invokeMethod(sys::uint32 methid, DistributedMethod* method);

	void setAttributeName(const String& attribute);

	void setMinValue(float minVal);

	void setMaxValue(float maxVal);

	void setAttributeExperimentalProperty(const String& attributeExpProp);

	String& getAttributeName();

	float getMinValue();

	float getMaxValue();

	float getRange();

	int getPrecision();

	String& getAttributeExperimentalProperty();

protected:
	String _param0_setAttributeName__String_;
	String _param0_setAttributeExperimentalProperty__String_;
};

class DraftSchematicAttributeHelper : public DistributedObjectClassHelper, public Singleton<DraftSchematicAttributeHelper> {
	static DraftSchematicAttributeHelper* staticInitializer;

public:
	DraftSchematicAttributeHelper();

	void finalizeHelper();

	DistributedObject* instantiateObject();

	DistributedObjectAdapter* createAdapter(DistributedObjectStub* obj);

	friend class SingletonWrapper<DraftSchematicAttributeHelper>;
};

class DraftSchematicAttributeServant : public DistributedObjectServant {
public:
	DraftSchematicAttribute* _this;

public:
	DraftSchematicAttributeServant();
	virtual ~DraftSchematicAttributeServant();

	void _setStub(DistributedObjectStub* stub);
	DistributedObjectStub* _getStub();

};

#endif /*DRAFTSCHEMATICATTRIBUTE_H_*/
