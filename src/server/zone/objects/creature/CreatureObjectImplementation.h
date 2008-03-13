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

#ifndef CREATUREOBJECTIMPLEMENTATION_H_
#define CREATUREOBJECTIMPLEMENTATION_H_

#include "engine/engine.h"

#include "../scene/SceneObject.h"
#include "../scene/SceneObjectImplementation.h"

#include "../../objects/player/Races.h"
#include "../../objects/tangible/CustomizationVariables.h"

#include "skills/Skill.h"
#include "skillmods/SkillModList.h"

#include "../guild/Guild.h"

class CombatManager;

class Player;
//class Npc;

class Inventory;
class HairObject;
class TangibleObject;
class Weapon;
class Armor;

class GroupObject;
class MountCreature;
class DizzyFallDownEvent;

class MountCreature;
class BuildingObject;
class CreatureObjectServant;

class CreatureObjectImplementation : public CreatureObjectServant {
protected:
	unicode characterName; //character name
	string terrainName;

	CustomizationVariables customization;
	string raceName; //species
	string speciesName; //species

	string hairObject; //hair object iff string
	string hairData; //hair customization string
	
	string stfName;

	uint32 positionCounter;
	uint32 actionCounter;
	
	VectorMap<uint32, Skill*> creatureSkills;
	uint32 creatureSkillsCount;

	//creature objects
	Inventory* inventory;
	Container* lootContainer;
	HairObject* hairObj;
	
	Time lastCombatAction;

	Vector<BaseMessage*> broadcastBuffer;

	// modifiers
	int weaponSpeedModifier;
	
	int centeredBonus;

	//CREO1 operands
	uint32 skillBoxesUpdateCounter;

	uint32 cashCredits;
	uint32 bankCredits;

 	//CREO3 operands
	uint8 postureState;

	uint64 stateBitmask;
	uint64 oldStateBitmask;
	
	uint32 creatureBitmask;
	
	MountCreature* mount;
	int conditionDamage;
	int maxCondition;
	Time mountCooldown;
	
	uint64 creatureLinkID;

	Time knockdownRecoveryTime;

	Time dizzyRecoveryTime;
	Time stunRecoveryTime;
	Time blindRecoveryTime;
	Time intimidateRecoveryTime;
	
	Time fireRecoveryTime;
	Time poisonRecoveryTime;
	Time bleedingRecoveryTime;
	Time diseasedRecoveryTime;

 	//CREO4 operands
	float speed;
	float acceleration;
	float height;
	SkillModList creatureSkillMods;
	SkillModList creatureSkillModBonus;
	
	uint32 skillModsCounter;
	string skillMod;
	
	uint32 skillModBonusCounter;

	//CREO6 operands
	uint32 defenderUpdateCounter;
	uint64 defenderID;
	
	string mood;
	uint8 moodid;
	
	Weapon* weaponObject;
	ManagedReference<SceneObject> targetObject;

	// HAM variables
	uint32 hamUpdateCounter;
	uint32 hamMaxUpdateCounter;

	//CREO1 HAM variables
	uint32 baseHealth;
	uint32 baseStrength;
	uint32 baseConstitution;
	uint32 baseAction;
	uint32 baseQuickness;
	uint32 baseStamina;
	uint32 baseMind;
	uint32 baseFocus;
	uint32 baseWillpower;
	
	uint32 health;
	uint32 strength;
	uint32 constitution;
	uint32 action;
	uint32 quickness;
	uint32 stamina;
	uint32 mind;
	uint32 focus;
	uint32 willpower;

	uint32 healthMax;
	uint32 strengthMax;
	uint32 constitutionMax;
	uint32 actionMax;
	uint32 quicknessMax;
	uint32 staminaMax;
	uint32 mindMax;
	uint32 focusMax;
	uint32 willpowerMax;
	
	uint32 healthEncumbrance;
	uint32 actionEncumbrance;
	uint32 mindEncumbrance;
	
	// Inherent Armor,Resists
	uint32 armor;
	
	float kinetic;
	float energy;
	float electricity;
	float stun;
	float blast;
	float heat;
	float cold;
	float acid;
	float lightSaber;
	
	// WOUND vars
	
	uint32 woundsUpdateCounter;
	uint32 healthWounds;
	uint32 actionWounds;
	uint32 mindWounds;
	
	uint32 shockWounds;

	// misc
	uint32 pvpStatusBitmask;
	uint32 faction;
	int interp_update;
	float oldpositionX;
	//float oldpositionZ;
	float oldpositionY;
	
	float spawnPositionX;
	float spawnPositionY;
	float spawnPositionZ;
	
	// combat
	int fireDotType;
	int fireDotStrength;
	
	int poisonDotType;
	int poisonDotStrength;
	
	int diseaseDotType;
	int diseaseDotStrength;
	
	int bleedingDotType;
	int bleedingDotStrength;
	
	Time nextBleedingTick;
	Time nextFireTick;
	Time nextPoisonTick;
	Time nextDiseaseTick;
	
	Time knockdownRecovery;
	Time postureDownRecovery;
	Time postureUpRecovery;
	
	Time nextAttackDelay;
	Time nextAttackDelayRecovery;
	
	bool meditating;
	
	int accuracy;
	
	Time burstRunCooldown;
	int damageBonus;
	int defenseBonus;
	
	VectorMap<uint32, uint32> queuedStates; // TODO: make SortedVector for basic types
	
	DizzyFallDownEvent* dizzyFallDownEvent;
	
	Vector<ManagedReference<CreatureObject> > defenderList;
	
	VectorMap<CreatureObject*, uint32> damageMap;
	
	// Store buff events so they can be removed on death.
	Vector<Event*> buffEvents;
	
	//group stuff
	uint64 groupId;
	uint64 groupInviteCount;
	uint64 groupInviterID;
	
	GroupObject* group;
	
	// Entertainer stuff
	string performanceName;
	uint32 performanceCounter;
	
	int instrumentID;
	
	bool doDancing;
	bool doPlayingMusic;
	bool doListening;
	bool doWatching;
	
	bool healthBuff;
	bool strengthBuff;
	bool constitutionBuff;
	bool actionBuff;
	bool quicknessBuff;
	bool staminaBuff;
	bool mindBuff;
	bool focusBuff;
	bool willpowerBuff;
	
	uint64 watchID;
	uint64 listenID;
	
	SortedVector<CreatureObject*> listeners;
	SortedVector<CreatureObject*> watchers;
	
	bool sittingOnObject;

	Guild* guild;
	
	uint32 lastMovementUpdateStamp;
	int ignoreMovementTests;
	Time lastServerMovementStamp;
	
	int level;
	
public:
	static const uint8 INVALID_POSTURE = 0xFF;
	static const uint8 UPRIGHT_POSTURE = 0;
	static const uint8 CROUCHED_POSTURE = 1;
	static const uint8 PRONE_POSTURE = 2;
	static const uint8 SNEAKING_POSTURE = 3;
	static const uint8 BLOCKING_POSTURE = 4;
	static const uint8 CLIMBING_POSTURE = 5;
	static const uint8 FLYING_POSTURE = 6;
	static const uint8 LYINGDOWN_POSTURE = 7;
	static const uint8 SITTING_POSTURE = 8;
	static const uint8 SKILLANIMATING_POSTURE = 9;
	static const uint8 DRIVINGVEHICLE_POSTURE = 10;
	static const uint8 RIDINGCREATURE_POSTURE = 11;
	static const uint8 KNOCKEDDOWN_POSTURE = 12;
	static const uint8 INCAPACITATED_POSTURE = 13;
	static const uint8 DEAD_POSTURE = 14;

	static const uint64 INVALID_STATE = 0x00;
	static const uint64 COVER_STATE = 0x01;
	static const uint64 COMBAT_STATE = 0x02;
	static const uint64 PEACE_STATE = 0x04;
	static const uint64 AIMING_STATE = 0x08;
	static const uint64 ALERT_STATE = 0x10;
	static const uint64 BERSERK_STATE = 0x20;
	static const uint64 FEIGNDEATH_STATE = 0x40;
	static const uint64 COMBATATTITUDEEVASIVE_STATE = 0x80;
	static const uint64 COMBATATTITUDENORMAL_STATE = 0x100;
	static const uint64 COMBATATTITUDEAGGRESSIVE_STATE = 0x200;
	static const uint64 TUMBLING_STATE = 0x400;
	static const uint64 RALLIED_STATE = 0x800;
	static const uint64 STUNNED_STATE = 0x1000;
	static const uint64 BLINDED_STATE = 0x2000;
	static const uint64 DIZZY_STATE = 0x4000;
	static const uint64 INTIMIDATED_STATE = 0x8000;
	static const uint64 IMMOBILIZED_STATE = 0x10000;
	static const uint64 FROZEN_STATE = 0x20000;
	static const uint64 SWIMMING_STATE = 0x40000;
	static const uint64 SITTINGONCHAIR_STATE = 0x80000;
	static const uint64 CRAFTING_STATE = 0x100000;
	static const uint64 GLOWINGJEDI_STATE = 0x200000;
	static const uint64 MASKSCENT_STATE = 0x400000;
	static const uint64 POISONED_STATE = 0x800000;
	static const uint64 BLEEDING_STATE = 0x1000000;
	static const uint64 DISEASED_STATE = 0x2000000;
	static const uint64 ONFIRE_STATE = 0x4000000;
	static const uint64 RIDINGMOUNT_STATE = 0x8000000;
	static const uint64 MOUNTEDCREATURE_STATE = 0x10000000;
	static const uint64 PILOTSHIP_STATE = 0x20000000;
	static const uint64 SHIPOPERATIONS_STATE = 0x40000000;
	static const uint64 SHIPGUNNER_STATE = 0x80000000;
	//static const uint64 SHIPINTERIOR_STATE = 0x100000000;
	//static const uint64 PILOTINGPOBSHIP_STATE = 0x200000000;
	
	static const uint32 NULL_FLAG = 0x00;
	static const uint32 ATTACKABLE_FLAG = 0x01;
	static const uint32 AGGRESSIVE_FLAG = 0x02;
	static const uint32 OVERT_FLAG = 0x04;
	static const uint32 TEF_FLAG = 0x08;
	static const uint32 PLAYER_FLAG = 0x10;
	static const uint32 ENEMY_FLAG = 0x20;
	static const uint32 DUEL_FLAG = 0x40;
	
public:
	CreatureObjectImplementation(uint64 oid);
	
	virtual ~CreatureObjectImplementation();

	// opdarand Update methods
	void doCombatAnimation(CreatureObject* defender, uint32 animcrc, uint8 hit = 0);
	void doAnimation(const string& anim);
	void playEffect(const string& file, const string& aux = "");
	void showFlyText(const string& file, const string& aux, uint8 red, uint8 green, uint8 blue);
	void sendCombatSpam(CreatureObject* defender, TangibleObject* item, uint32 damage, const string& skill, bool areaSpam = true);

	void setPosture(uint8 state, bool overrideDizzy = false, bool objectInteraction = false, float objX = 0, float objY = 0, float objZ = 0);
	
	void setDefender(CreatureObject* defender);
	void addDefender(CreatureObject* defender);
	void removeDefender(CreatureObject* defender);
	void removeDefenders();
	bool hasDefender(CreatureObject* defender);
	
	void setCombatState();
	void clearCombatState(bool removeDefenders = true);

	bool setState(uint64 state);
	bool clearState(uint64 state);
	void updateStates();
	void clearStates();
	
	bool changeHAMBars(int32 hp, int32 ap, int32 mp, bool forcedChange = false);
	bool changeHAMWounds(int32 hpwnd, int32 apwnd, int32 mpwnd, bool forcedChange = false);
	void changeMaxHAMBars(int32 hp, int32 ap, int32 mp);
	
	bool changeHealthWoundsBar(int32 wounds, bool forcedChange = false);
	bool changeActionWoundsBar(int32 wounds, bool forcedChange = false);
	bool changeMindWoundsBar(int32 wounds, bool forcedChange = false);
	
	bool changeHealthBar(int32 hp, bool forcedChange = false);
	bool changeStrengthBar(int32 st, bool forcedChange = false);
	bool changeConstitutionBar(int32 cs, bool forcedChange = false);
	
	void changeMaxHealthBar(int32 hp);
	void changeMaxStrengthBar(int32 hp);
	void changeMaxConstitutionBar(int32 hp);
	
	bool changeActionBar(int32 ap, bool forcedChange = false);
	bool changeQuicknessBar(int32 qc, bool forcedChange = false);
	bool changeStaminaBar(int32 st, bool forcedChange = false);
	
	void changeMaxActionBar(int32 hp);
	void changeMaxQuicknessBar(int32 hp);
	void changeMaxStaminaBar(int32 hp);
	
	bool changeMindBar(int32 mp, bool forcedChange = false);
	bool changeFocusBar(int32 fc, bool forcedChange = false);
	bool changeWillpowerBar(int32 wl, bool forcedChange = false);
	
	void changeMaxMindBar(int32 hp);
	void changeMaxFocusBar(int32 hp);
	void changeMaxWillpowerBar(int32 hp);
	
	void changeConditionDamage(int amount);
	
	void changeShockWounds(int bf);
	
	void resetHAMBars();
	
	void setMaxHAMBars(uint32 hp, uint32 ap, uint32 mp);
	void setHAMBars(uint32 hp, uint32 ap, uint32 mp);
	void setHAMWoundsBars(uint32 hpwnds, uint32 acwnds, uint32 mpwnds);
	
	void setHealthWoundsBar(uint32 wnds);
	void setActionWoundsBar(uint32 wnds);
	void setMindWoundsBar(uint32 wnds);
	
	void setHealthBar(uint32 hp);
	void setStrengthBar(uint32 st);
	void setConstitutionBar(uint32 cst);
	
	void setMaxHealthBar(uint32 hp);
	void setMaxStrengthBar(uint32 st);
	void setMaxConstitutionBar(uint32 cst);
	
	void setActionBar(uint32 ap);
	void setQuicknessBar(uint32 qck);
	void setStaminaBar(uint32 sta);
	
	void setMaxActionBar(uint32 ap);
	void setMaxQuicknessBar(uint32 qck);
	void setMaxStaminaBar(uint32 sta);
	
	void setMindBar(uint32 mp);
	void setFocusBar(uint32 fc);
	void setWillpowerBar(uint32 will);
	
	void setMaxMindBar(uint32 mp);
	void setMaxFocusBar(uint32 fc);
	void setMaxWillpowerBar(uint32 will);
	
	void calculateHAMregen();
	float calculateBFRatio();

	void activateBurstRun();
	void deactivateBurstRun();
	
	void activateForceRun1(float sp, float acc);

	void updateTarget(uint64 targ);
	void updateTarget(SceneObject* targ);
	
	void clearTarget();
	
	void setDizziedState();
	void setStunnedState();
	void setBlindedState();
	void setIntimidatedState();
	
	bool setNextAttackDelay(int del);
	
	void setMeditateState();
	
	void addDamage(CreatureObject* creature, uint32 damage);

	bool isLootOwner(CreatureObject* creature);

	virtual bool isAttackable() {
		return !isIncapacitated() && !isDead();
	}

	inline bool isAttackableBy(CreatureObject* attacker) {
		return !(creatureBitmask & 0x100);
	}
	
	bool hasAttackDelay() {
		return !nextAttackDelay.isPast();
	}
	
	void clearAttackDelay() {
		nextAttackDelay.update();
	}

	void setRebel() {
		faction = String::hashCode("rebel");
	}
	
	void setImperial() {
		faction = String::hashCode("imperial");
	}
	
	void setNeutral() {
		faction = 0;
	}
	
	void setFaction(uint32 fac) {
		faction = fac;
	}
	
	void setLastMovementUpdateStamp(uint32 tme) {
		lastMovementUpdateStamp = tme;
	}
	
	void setIgnoreMovementTests(int times) {
		ignoreMovementTests = times;
	}

	void sendFactionStatusTo(Player* player, bool doTwoWay = false);
	
	int getCreatureSkillsSize() {
		return creatureSkills.size();
	}
	
	void addSkill(Skill* skill) {
		creatureSkills.put(skill->getNameCRC(), skill);
	}
	
	Skill* getSkill(const string& name) {
		return creatureSkills.get(String::hashCode(name));
	}
	
	inline string& getSkill(int idx) {
		return creatureSkills.get(idx)->getSkillName();
	}
	
	void removeSkill(Skill* skill) {
		creatureSkills.drop(skill->getNameCRC());
	}
	
	bool hasSkill(uint32 skillCRC) {
		return creatureSkills.contains(skillCRC);
	}
	
	void addSkills(Vector<Skill*>& skills, bool updateClient);
	void removeSkills(Vector<Skill*>& skills, bool updateClient);
	
	inline uint32 getCreatureSkillsCount() {
		return creatureSkillsCount;
	}
	
	inline uint32 getNewCreatureSkillsCount(int cnt) {
		return creatureSkillsCount += cnt;
	}
	
	inline uint32 getDamage(CreatureObject* creature) {
		return damageMap.get(creature);
	}
	
	uint32 getMitigation(const string& mit);
	
	virtual void activateRecovery() = 0;
		
	// dots
	void setPoisonedState(int str, int type, int duration);
	void setBleedingState(int str, int type, int duration);
	void setDiseasedState(int str, int type, int duration);
	void setOnFireState(int str, int type, int duration);
	
	void doPoisonTick();
	void doBleedingTick();
	void doDiseaseTick();
	void doFireTick();

	virtual void doIncapacitate() = 0;

	bool isOnFullHealth() {
		return (health == healthMax - healthWounds) && (action == actionMax - actionWounds) && (mind == mindMax - mindWounds);
	}
	
	void setGroup(GroupObject* Group) {
		group = Group;
	}
	
	void removeGroup() {
		group = NULL;
	}
	
	bool isInAGroup() {
		return group != NULL;
	}
	
	inline uint64 getGroupID() {
		return groupId;
	}
	
	inline void setGroupID(uint64 gid) {
		groupId = gid;
	}

	inline bool isIncapacitated() {
		return postureState == INCAPACITATED_POSTURE;
	}

	inline bool isDead() {
		return postureState == DEAD_POSTURE;
	}

	inline bool isKnockedDown() {
		return postureState == KNOCKEDDOWN_POSTURE;
	}
	
	inline bool isKneeled() {
		return postureState == CROUCHED_POSTURE;
	}
	
	inline bool isProne() {
		return postureState == PRONE_POSTURE;
	}

	inline bool isSitting() {
		return postureState == SITTING_POSTURE;
	}

	inline bool isInCombat() {
		return stateBitmask & COMBAT_STATE;
	}

	inline bool isDizzied() {
		return stateBitmask & DIZZY_STATE;
	}

	inline bool isStunned() {
		return stateBitmask & STUNNED_STATE;
	}

	inline bool isBlinded() {
		return stateBitmask & BLINDED_STATE;
	}
	
	inline bool isIntimidated() {
		return stateBitmask & INTIMIDATED_STATE;
	}
	
	inline bool isDiseased() {
		return stateBitmask & DISEASED_STATE;
	}
	
	inline bool isPoisoned() {
		return stateBitmask & POISONED_STATE;
	}
	
	inline bool isBleeding() {
		return stateBitmask & BLEEDING_STATE;
	}
	
	inline bool isOnFire() {
		return stateBitmask & ONFIRE_STATE;
	}
	
	inline bool isMounted() {
		return stateBitmask & RIDINGMOUNT_STATE;
	}
	
	inline bool isRidingCreature() {
		return stateBitmask & MOUNTEDCREATURE_STATE;
	}
	
	inline bool isPeaced() {
		return stateBitmask & PEACE_STATE;
	}
	
	inline bool isMeditating() {
		return meditating;
	}
	
	// misc methods
	void updateKnockdownRecovery() {
		knockdownRecovery.update();
		knockdownRecovery.addMiliTime(30000);
	}
	
	bool checkKnockdownRecovery() {
		return knockdownRecovery.isPast();
	}
	
	void updatePostureDownRecovery() {
		postureDownRecovery.update();
		postureDownRecovery.addMiliTime(30000);
	}
	
	void updatePostureUpRecovery() {
		postureUpRecovery.update();
		postureUpRecovery.addMiliTime(30000);
	}
	
	bool checkPostureDownRecovery() {
		return postureDownRecovery.isPast();
	}
	
	bool checkPostureUpRecovery() {
		return postureUpRecovery.isPast();
	}

	// item methods
	void equipItem(TangibleObject* item);
	void unequipItem(TangibleObject* item);
	
	void addInventoryItem(TangibleObject* item);

	TangibleObject* getInventoryItem(uint64 oid);
	
	void removeInventoryItem(SceneObject* item);
	void removeInventoryItem(uint64 oid);

	void addLootItem(TangibleObject* item);

	TangibleObject* getLootItem(uint64 oid);
	
	void removeLootItem(SceneObject* item);
	void removeLootItem(uint64 oid);
	
	// Entertainer methods
	void startDancing(const string& anim);
	void startPlayingMusic(const string& anim);

	void stopDancing();
	void stopPlayingMusic();
	
	void startWatch(uint64 entid);
	void startListen(uint64 entid);
	void stopWatch(uint64 entid, bool doSendPackets = true, bool forced = false, bool doLock = true);
	void stopListen(uint64 entid, bool doSendPackets = true, bool forced = false, bool doLock = true);

	// guild methods
	void sendGuildTo();
	
	// mount methods
	void mountCreature(MountCreature* mnt, bool lockMount = true);
	void dismount(bool lockMount = true, bool ignoreCooldown = false);

	// buffing methods
	void applyBuff(const string& type, int value, float duration);
	void removeBuff(const string& type, int value, Event* event);
	
	void removeBuffs(bool doUpdateCreature = true);

	// cash transaction methods
	void addCashCredits(uint32 credits);
	void addBankCredits(uint32 credits);
	void updateCashCredits(uint32 credits);
	void updateBankCredits(uint32 credits);
	void subtractCashCredits(uint32 credits);
	void subtractBankCredits(uint32 credits);

	bool verifyCashCredits(int creditsToRemove);
	bool verifyBankCredits(int creditsToRemove);

	// misc		
	virtual uint64 getNewItemID() = 0;

	// client level methods
	void sendToOwner(Player* player, bool doClose = true);

	void sendTo(Player* player, bool doClose = true);
	
	void sendItemsTo(Player* player);

	void sendDestroyTo(Player* player);

	void broadcastMessage(BaseMessage* msg, int range = 128, bool doLock = true);
	void broadcastMessages(Vector<BaseMessage*>& msgs, int range = 128, bool doLock = true);
	
	void sendSystemMessage(const string& message);
	void sendSystemMessage(const string& file, const string& str, uint64 targetid = 0);
	
	void setSpeed(float Speed, float Acceleration);
	
	void updateGroupId(uint64 id);
	void updateGroupInviterId(uint64 id);
	
	float getDistanceTo(CreatureObject* targetCreature);
	
	void updateMood(const string& md);

	inline void updateServerMovementStamp() {
		lastServerMovementStamp.update();
	}

	inline uint64 getLastServerMovementStamp() {
		return lastServerMovementStamp.miliDifference();
	}
	
protected:
	void sendEntertainingUpdate(uint32 entval, const string& performance, uint32 perfcntr, int instrid);
	void sendEntertainmentUpdate(uint64 entid, const string& mood, bool updateEntVal = false);

public:
	// setters and getters
	void addSkillMod(const string& name, int mod, bool updateClient = false);
	void removeSkillMod(const string& name, bool updateClient = false);

	void addSkillModBonus(const string& name, int mod, bool updateClient = false);
	void removeSkillModBonus(const string& name, bool updateClient = false);
	
	bool hasQueuedState(uint32 skillCRC) {
		return queuedStates.contains(skillCRC);
	}
	
	bool removeQueuedState(uint32 skillCRC) {
		return queuedStates.drop(skillCRC);
	}
	
	bool addQueuedState(uint32 skillCRC) {
		return queuedStates.put(skillCRC, skillCRC);
	}
	
	SkillModList* getSkillModList() {
		return &creatureSkillMods;
	}
	
	SkillModList* getSkillModBonusList() {
		return &creatureSkillModBonus;
	}
		
	void setGroupInviterID(uint64 oid) {
		groupInviterID = oid;
	}
	
	int getSkillMod(const string& name) {
		int bonus = creatureSkillModBonus.get(name);
		if (bonus > 25)
			bonus = 25;
		return creatureSkillMods.get(name) + bonus;
	}
	
	bool hasSkillMod(const string& name) {
		return creatureSkillMods.containsKey(name);
	}
	
	void removeSkillMod(string& name) {
		creatureSkillMods.remove(name);
	}

	int getSkillModBonus(const string& name) {
		int bonus = creatureSkillModBonus.get(name);
		return bonus;
	}
	
	bool hasSkillModBonus(const string& name) {
		return creatureSkillModBonus.containsKey(name);
	}
	
	void removeSkillModBonus(string& name) {
		creatureSkillModBonus.remove(name);
	}
		
	inline int getDamageBonus() {
		return damageBonus;
	}
	
	inline int getDefenseBonus() {
		return defenseBonus;
	}
	
	inline uint64 getGroupInviterID() {
		return groupInviterID;
	}
	
	inline uint64 getNewGroupInviteCounter() {
		return ++groupInviteCount;
	}

	inline uint64 getGroupInviteCounter() {
		return groupInviteCount;
	}
	
	inline int getConditionDamage() {
		return conditionDamage;
	}
	
	inline int getMaxCondition() {
		return maxCondition;
	}
	
	inline int getCondition() {
		return maxCondition - conditionDamage;
	}
	
	inline int getCenteredBonus() {
		return centeredBonus;
	}
	
	inline uint64 getCreatureLinkID() {
		return creatureLinkID;
	}
	
	inline uint32 getLastMovementUpdateStamp() {
		return lastMovementUpdateStamp;
	}
	
	inline int getIgnoreMovementTests() {
		return ignoreMovementTests;
	}
	
	inline void setMount(MountCreature* mnt) {
		mount = mnt;
	}

	inline MountCreature* getMount() {
		return mount;
	}
	
	inline void setDamageBonus(int bonus) {
		damageBonus = bonus;
	}
	
	inline void setDefenseBonus(int bonus) {
		defenseBonus = bonus;
	}
	
	inline void setCreatureLinkID(uint64 creatureID) {
		creatureLinkID = creatureID;
	}
	
	inline void setCharacterName(const string& name) {
		characterName = name;
	}

	inline void setCharacterName(unicode& name) {
		characterName = name;
	}

	inline void setTerrainName(const string& name) {
		terrainName = name;
	}

	inline void setCharacterApperance(string cust) {
		customization = cust;
	}

	inline void setRaceName(const string& name) {
		raceName = name;
	}

	inline void setSpeciesName(const string& name) {
		speciesName = name;
	}
	
	inline void setHeight(float h) {
		height = h;
	}

	inline void setWeapon(Weapon* wep) {
		weaponObject = wep;
	}
	
	inline void setMood(uint8 mdid) {
		moodid = mdid;
		mood = Races::getMood(moodid);
	}
	
	inline void setMood(const string& m) {
		mood = m;
	}
	
	inline void setPvpStatusBitmask(uint32 mask) {
		pvpStatusBitmask = mask;
	}
	
	inline void setBaseHealth(uint32 value) {
		baseHealth = value;
	}

	inline void setBaseStrength(uint32 value) {
		baseStrength = value;
	}

	inline void setBaseConstitution(uint32 value) {
		baseConstitution = value;
	}

	inline void setBaseAction(uint32 value) {
		baseAction = value;
	}

	inline void setBaseQuickness(uint32 value) {
		baseQuickness = value;
	}

	inline void setBaseStamina(uint32 value) {
		baseStamina = value;
	}

	inline void setBaseMind(uint32 value) {
		baseMind = value;
	}
	
	inline void setBaseFocus(uint32 value) {
		baseFocus = value;
	}
	
	inline void setBaseWillpower(uint32 value) {
		baseWillpower = value;
	}

	inline void setHealth(uint32 value) {
		health = value;
	}

	inline void setStrength(uint32 value) {
		strength = value;
	}

	inline void setConstitution(uint32 value) {
		constitution = value;
	}

	inline void setAction(uint32 value) {
		action = value;
	}

	inline void setQuickness(uint32 value) {
		quickness = value;
	}

	inline void setStamina(uint32 value) {
		stamina = value;
	}

	inline void setMind(uint32 value) {
		mind = value;
	}
	
	inline void setFocus(uint32 value) {
		focus = value;
	}
	
	inline void setWillpower(uint32 value) {
		willpower = value;
	}

	inline void setHealthMax(uint32 value) {
		healthMax = value;
	}

	inline void setStrengthMax(uint32 value) {
		strengthMax = value;
	}

	inline void setConstitutionMax(uint32 value) {
		constitutionMax = value;
	}

	inline void setActionMax(uint32 value) {
		actionMax = value;
	}

	inline void setQuicknessMax(uint32 value) {
		quicknessMax = value;
	}

	inline void setStaminaMax(uint32 value) {
		staminaMax = value;
	}

	inline void setMindMax(uint32 value) {
		mindMax = value;
	}
	
	inline void setFocusMax(uint32 value) {
		focusMax = value;
	}
	
	inline void setWillpowerMax(uint32 value) {
		willpowerMax = value;
	}

	inline void setArmor(uint32 ar) {
		armor=ar;
	}

	inline void setKinetic(float kin) {
		kinetic = kin;
	}

	inline void setEnergy(float ene) {
		energy = ene;
	}

	inline void setElectricity(float ele) {
		electricity = ele;
	}

	inline void setStun(float stu) {
		stun = stu;
	}
	
	inline void setBlast(float bla) {
		blast = bla;
	}

	inline void setHeat(float hea) {
		heat = hea;
	}

	inline void setCold(float col) {
		cold = col;
	}
	
	inline void setAcid(float aci) {
		acid = aci;
	}
	
	inline void setLightSaber(float lig) {
		lightSaber = lig;
	}
	
	inline void setHealthWounds(uint32 wounds) {
		healthWounds = wounds;
	}

	inline void setActionWounds(uint32 wounds) {
		actionWounds = wounds;
	}

	inline void setMindWounds(uint32 wounds) {
		mindWounds = wounds;
	}
	
	inline void setShockWounds(uint32 wounds) {
		shockWounds = wounds;
	}
	
	inline void setWoundsUpdateCounter(uint32 count) {
		woundsUpdateCounter = count;
	}
	
	inline void setDefenderID(uint64 did) {
		defenderID = did;
	}
	
	// getters
	inline unicode& getCharacterName() {
		return characterName;
	}
	
	inline string& getTerrainName() {
		return terrainName;
	}

	inline void getCharacterApperance(string& appearance) {
		customization.toString(appearance);
	}
	
	inline string& getRaceName() {
		return raceName;
	}

	inline string& getSpeciesName() {
		return speciesName;
	}

	inline string& getStfName() {
		return stfName;
	}
	
	inline uint32 getPositionCounter() {
		return positionCounter++;
	}
	
	inline uint32 getDefenderListSize() {
		return defenderList.size();
	}
	
	inline CreatureObject* getDefender(int idx) {
		return defenderList.get(idx);
	}

	inline uint32 getBankCredits() {
		return bankCredits;
	}

	inline uint32 getCashCredits() {
		return cashCredits;
	}

	inline SceneObject* getTarget() {
		return targetObject;
	}

	inline Weapon* getWeapon() {
		return weaponObject;
	}
	
	Armor* getArmor(int type);

	// HAM getters
	inline uint32 getBaseHealth() {
		return baseHealth;
	}

	inline uint32 getBaseStrength() {
		return baseStrength;
	}

	inline uint32 getBaseConstitution() {
		return baseConstitution;
	}

	inline uint32 getBaseAction() {
		return baseAction;
	}

	inline uint32 getBaseQuickness() {
		return baseQuickness;
	}

	inline uint32 getBaseStamina() {
		return baseStamina;
	}

	inline uint32 getBaseMind() {
		return baseMind;
	}

	inline uint32 getBaseFocus() {
		return baseFocus;
	}

	inline uint32 getBaseWillpower() {
		return baseWillpower;
	}

	inline uint32 getHealth() {
		return health;
	}

	inline uint32 getStrength() {
		if ((int) strength < 1)
			return 1;
		else 
			return strength;
	}

	inline uint32 getConstitution() {
		if ((int) constitution < 1)
			return 1;
		else 
			return constitution;
	}

	inline uint32 getAction() {
		return action;
	}

	inline uint32 getQuickness() {
		if ((int) quickness < 1)
			return 1;
		else 
			return quickness;
	}

	inline uint32 getStamina() {
		if ((int) stamina < 1)
			return 1;
		else 
			return stamina;
	}

	inline uint32 getMind() {
		return mind;
	}

	inline uint32 getFocus() {
		if ((int) focus < 1)
			return 1;
		else 
			return focus;
	}

	inline uint32 getWillpower() {
		if ((int) willpower < 1)
			return 1;
		else 
			return willpower;
	}

	inline uint32 getHealthMax() {
		return healthMax;
	}

	inline uint32 getStrengthMax() {
		if ((int) strengthMax < 1)
			return 1;
		else 
			return strengthMax;
	}

	inline uint32 getConstitutionMax() {
		if ((int) constitutionMax < 1)
			return 1;
		else 
			return constitutionMax;
	}

	inline uint32 getActionMax() {
		return actionMax;
	}

	inline uint32 getQuicknessMax() {
		if ((int) quicknessMax < 1)
			return 1;
		else 
			return quicknessMax;
	}

	inline uint32 getStaminaMax() {
		if ((int) staminaMax < 1)
			return 1;
		else 
			return staminaMax;
	}

	inline uint32 getMindMax() {
		return mindMax;
	}

	inline uint32 getFocusMax() {
		if ((int) focusMax < 1)
			return 1;
		else 
			return focusMax;
	}

	inline uint32 getWillpowerMax() {
		if ((int) willpowerMax < 1)
			return 1;
		else 
			return willpowerMax;
	}
	
	inline uint32 getArmor() {
		return armor;
	}
	
	inline float getKinetic() {
		return kinetic - (kinetic * calculateBFRatio());
	}

	inline float getEnergy() {
		return energy - (energy  * calculateBFRatio());
	}

	inline float getElectricity() {
		return electricity - (electricity  * calculateBFRatio());
	}

	inline float getStun() {
		return stun - (stun * calculateBFRatio());
	}
	
	inline float getBlast() {
		return blast - (blast * calculateBFRatio());
	}

	inline float getHeat() {
		return heat - (heat * calculateBFRatio());
	}

	inline float getCold() {
		return cold - (cold * calculateBFRatio());
	}
	
	inline float getAcid() {
		return acid - (acid * calculateBFRatio());
	}
	
	inline float getLightSaber() {
		return lightSaber - (lightSaber * calculateBFRatio());
	}
	
	float getArmorResist(int resistType);

	inline uint32 getHealthWounds() {
		return healthWounds;
	}

	inline uint32 getActionWounds() {
		return actionWounds;
	}

	inline uint32 getMindWounds() {
		return mindWounds;
	}

	inline uint32 getShockWounds() {
		return shockWounds;
	}
	
	inline uint32 getHAMUpdateCounter() {
		return hamUpdateCounter;
	}
	
	inline uint32 getNewHAMUpdateCounter(int cnt) {
			return hamUpdateCounter += cnt;
	}

	inline uint32 getHAMMaxUpdateCounter() {
		return hamMaxUpdateCounter;
	}
	
	inline uint32 getNewHAMMaxUpdateCounter(int cnt) {
			return hamMaxUpdateCounter += cnt;
	}

	inline uint32 getWoundsUpdateCounter() {
		return woundsUpdateCounter;
	}
	
	inline uint32 getNewWoundsUpdateCounter(int upd) {
		return woundsUpdateCounter += upd;
	}

	inline uint8 getPosture() {
		return postureState;
	}
	
	inline string& getMood() {
		return mood;
	}
	
	inline uint8 getMoodID() {
		return moodid;
	}
	
	inline uint64 getStateBitmask() {
		return stateBitmask;
	}
	
	inline float getHeight() {
		return height;
	}
	
	inline bool hasStates() {
		return stateBitmask != 0;
	}
	
	inline bool hasWounds() {
		return (healthWounds > 0 || actionWounds > 0 || mindWounds > 0);
	}
	
	inline bool hasShockWounds() {
		return (shockWounds > 0);
	}
	
	inline bool hasState(uint64 state) {
		return stateBitmask & state;
	}
	
	inline int getAccuracy() {
		return accuracy;
	}

	inline float getSpeed() {
		return speed;
	}

	inline float getAcceleration() {
		return acceleration;
	}
	
	inline bool isOvert() {
		return pvpStatusBitmask & OVERT_FLAG;
	}
	
	inline bool isAgressive() {
		return pvpStatusBitmask & AGGRESSIVE_FLAG;
	}
	
	inline bool isTEF() {
		return pvpStatusBitmask & TEF_FLAG;
	}
	
	inline bool isPlayerFlag() {
		return pvpStatusBitmask & PLAYER_FLAG;
	}
	
	inline bool isEnemy() {
		return pvpStatusBitmask & ENEMY_FLAG;
	}
	
	inline uint32 getFaction() {
		return faction;
	}
	
	inline bool isRebel() {
		return faction == String::hashCode("rebel");
	}
	
	inline bool isNeutral() {
		return faction == 0;
	}
	
	inline bool isImperial() {
		return faction == String::hashCode("imperial");
	}
	
	inline uint32 getPvpStatusBitmask() {
		return pvpStatusBitmask;
	}
	
	inline void setCreatureBitmask(uint32 bit) {
		creatureBitmask = bit;
	}
	
	inline uint32 getCreatureBitmask() {
		return creatureBitmask;
	}
	
	uint64 getTargetID();

	uint64 getWeaponID();

	inline uint64 getDefenderID() {
		return defenderID;
	}
	
	inline uint32 getDefenderUpdateCounter() {
		return defenderUpdateCounter;
	}
	
	inline uint32 getNewDefenderUpdateCounter(int cnt) {
		return defenderUpdateCounter += cnt;
	}

	inline uint32 getNewSkillModsCounter(int cnt) {
		return skillModsCounter += cnt;
	}
	
	inline uint32 getSkillModsCounter() {
		return skillModsCounter;
	}
	
	inline uint32 getNewSkillModBonusCounter(int cnt) {
		return skillModBonusCounter += cnt;
	}
	
	inline uint32 getSkillModBonusCounter() {
		return skillModBonusCounter;
	}
	
	inline uint32 getLevel() {
		return level;
	}
	
	inline uint32 getHealthEncumbrance() {
		return healthEncumbrance;
	}
	
	inline uint32 getActionEncumbrance() {
		return actionEncumbrance;
	}
	
	inline uint32 getMindEncumbrance() {
		return mindEncumbrance;
	}

	// modifiers
	inline int getWeaponSpeedModifier() {
		return weaponSpeedModifier;
	}

	inline Inventory* getInventory() {
		return inventory;
	}
	
	inline Container* getLootContainer() {
		return lootContainer;
	}

	// entertainer
	inline void addListener(CreatureObject* creature) {
		listeners.put(creature);
	}
	
	inline void addWatcher(CreatureObject* creature) {
		watchers.put(creature);
	}
	
	inline void removeListener(CreatureObject* creature) {
		if (!listeners.drop(creature)) {
			cout << "SortedVector ERROR: object " << creature << " not found\n";
			
			for (int i = 0; i < listeners.size(); ++i) {
				CreatureObject* obj = listeners.get(i);
				cout << obj << "(0x" << obj->getObjectID() << ") ";
			}
			
			cout << "\n";
		}
	}
	
	inline void removeWatcher(CreatureObject* creature) {
		if (!watchers.drop(creature)) {
			cout << "SortedVector ERROR: object " << creature << " not found\n";
			
			for (int i = 0; i < watchers.size(); ++i) {
				CreatureObject* obj = watchers.get(i);
				cout << obj << "(0x" << obj->getObjectID() << ") ";
			}
			
			cout << "\n";
		}
	}
	
	inline string& getPerformanceName() {
		return performanceName;	
	}

	inline uint32 getPerformanceCounter() {
		return performanceCounter;
	}
	
	inline int getInstrumentID() {
		return instrumentID;
	}
	
	inline uint32 getSkillBoxesUpdateCounter() {
		return skillBoxesUpdateCounter++;
	}
	
	inline void setAccuracy(int acc) {
		accuracy = acc;
	}
	
	inline void setPerformanceName(const string& performancename) {
		performanceName = performancename;
	}
	
	inline void setPerformanceCounter(uint32 performancecounter) {
		performanceCounter = performancecounter;	
	}
	
	inline void setInstrumentID(int value) {
		instrumentID = value;	
	}
	
	inline void setDancing(bool value) {
		doDancing = value;	
	}
	
	inline void setPlayingMusic(bool value) {
		doPlayingMusic = value;	
	}
	
	inline bool isDancing() {
		return doDancing;
	}
	
	inline bool isPlayingMusic() {
		return doPlayingMusic;	
	}

	inline void setWatchID(uint64 oid) {
		watchID = oid;
	}
	
	inline void setListenID(uint64 oid) {
		listenID = oid;	
	}
	
	inline void setWatching(bool value) {
		doWatching = value;
	}
	
	inline void setListening(bool value) {
		doListening = value;
	}
	
	inline bool isWatching() {
		return doWatching;
	}
	
	inline bool isListening() {
		return doListening;
	}
	
	inline uint64 getWatchID() {
		return watchID;	
	}
	
	inline uint64 getListenID() {
		return listenID;
	}
	
	inline bool isSittingOnObject() {
		return sittingOnObject;	
	}
	
	inline void setSittingOnObject(bool value) {
		sittingOnObject = value;
	}
	
	inline void setGuild(Guild* gld) {
		guild = gld;
	}
	
	inline void setActionCounter(uint32 actioncntr) {
		actionCounter = actioncntr;
	}
	
	inline void setLevel(uint32 lvl) {
		level = lvl;
	}
	
	inline Guild* getGuild() {
		return guild;	
	}
	
	inline uint32 getGuildID() {
		if (guild != NULL)
			return guild->getGuildID();
		else 
			return 0;
	}

	inline string& getGuildName() {
		return guild->getGuildName();
	}
		
	inline bool isGuilded() {
		return guild != NULL;
	}
		
	inline void setCashCredits(int credits) {
		cashCredits = credits;
	}
	
	inline void setBankCredits(int credits) {
		bankCredits = credits;
	}

	inline float getTerrainNegotiation() {
		return (float(getSkillMod("slope_move"))/float(100));
	}
	
	friend class CombatManager;
	friend class SkillManager;

	friend class CreatureObjectMessage1;
	//friend class CreatureObjectMessage3;
	friend class CreatureObjectMessage4;
	friend class CreatureObjectMessage6;
	friend class PlayerObjectMessage9;

	friend class CreatureObjectDeltaMessage1;
	friend class CreatureObjectDeltaMessage3;
	friend class CreatureObjectDeltaMessage4;
	friend class CreatureObjectDeltaMessage6;
	friend class PlayerObjectDeltaMessage9;

	friend class ObjectControllerMessage;
	friend class PostureMessage;

	friend class UpdatePVPStatusMessage;

};

#endif /*CREATUREOBJECTIMPLEMENTATION_H_*/
