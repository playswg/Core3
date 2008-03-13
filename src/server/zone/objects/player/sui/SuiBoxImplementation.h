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

#ifndef SUIBOXIMPLEMENTATION_H_
#define SUIBOXIMPLEMENTATION_H_

#include "SuiBox.h"
#include "engine/engine.h"

#include "SuiBoxImplementation.h"

class Player;

class SuiBoxImplementation : public SuiBoxServant {
protected:
	Player* player;
	
	uint32 boxID;
	
	uint64 usingObjectID;
	
	bool cancelButton;
	
	string promptTitle;
	string promptText;
	
	int boxType;
	
public:
	const static int INPUTBOX = 0;
	const static int LISTBOX = 1;
	const static int MESSAGEBOX = 2;
	const static int TRANSFERBOX = 3;
	const static int COLORPICKER = 4;
	const static int BANKTRANSFERBOX = 5;
	
public:
	SuiBoxImplementation(Player* play, uint32 typeID, uint32 boxtype);
	~SuiBoxImplementation();
	
	SuiBox* deploy();
	
	virtual BaseMessage* generateMessage() = 0;
	
	int compareTo(SuiBox* obj) {
		uint32 id = obj->getBoxID();

		if (boxID < id)
			return 1;
		else if (boxID > id)
			return -1;
		else
			return 0;
	}
	
	inline void setPromptTitle(const string name) {
		promptTitle = name;
	}
	
	inline void setPromptText(const string name) {
		promptText = name;
	}
	
	inline void setUsingObjectID(uint64 oid) {
		usingObjectID = oid;
	}

	inline bool isInputBox() {
		return boxType == INPUTBOX;
	}
	
	inline bool isListBox() {
		return boxType == LISTBOX;
	}
	
	inline bool isMessageBox() {
		return boxType == MESSAGEBOX;
	}
	
	inline bool isTransferBox() {
		return boxType == TRANSFERBOX;
	}
	
	inline bool isBankTransferBox() {
		return boxType == BANKTRANSFERBOX;
	}
	
	inline bool isColorPicker() {
		return boxType == COLORPICKER;
	}
	
	inline void setCancelButton(bool value) {
		cancelButton = value;
	}

	inline uint64 getUsingObjectID() {
		return usingObjectID;
	}
	
	inline Player* getPlayer() {
		return player;
	}
	
	inline uint32 getBoxID() {
		return boxID;
	}
	
};

#endif /*SuiBoxIMPLEMENTATON_H_*/
