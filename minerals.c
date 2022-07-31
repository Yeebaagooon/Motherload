/* MINERALS */
const int RELIC_IRON = 1;
const int RELIC_BRONZE = 2;
const int RELIC_SILVER = 3;
const int RELIC_GOLD = 4;

string relicName(int relic = 0) {
	string msg = "WTF That's not a relic!";
	switch(relic)
	{
		case RELIC_IRON:
		{
			msg = "Iron";
		}
		case RELIC_BRONZE:
		{
			msg = "Bronze";
		}
		case RELIC_SILVER:
		{
			msg = "Silver";
		}
		case RELIC_GOLD:
		{
			msg = "Gold";
		}
	}
	return(msg);
}

int relicCost(int relic = 0) {
	int price = 0;
	switch(relic)
	{
		case RELIC_IRON:
		{
			price = 1;
		}
		case RELIC_BRONZE:
		{
			price = 2;
		}
		case RELIC_SILVER:
		{
			price = 3;
		}
		case RELIC_GOLD:
		{
			price = 5;
		}
	}
	return(price);
}

string relicIcon(int relic = 0) {
	string icon = "icons\infantry g hoplite icon 64";
	switch(relic)
	{
		case RELIC_IRON:
		{
			icon = "icons\building armory icon 64";
		}
		case RELIC_BRONZE:
		{
			icon = "icons\icon building wooden fence 64";
		}
		case RELIC_SILVER:
		{
			icon = "icons\building dock icon 64";
		}
		case RELIC_GOLD:
		{
			icon = "icons\building lighthouse icon 64";
		}
	}
	return(icon);
}

int relicProto(int relic = 0) {
	int proto = kbGetProtoUnitID("Hoplite");
	switch(relic)
	{
		case RELIC_IRON:
		{
			proto = kbGetProtoUnitID("Armory");
		}
		case RELIC_BRONZE:
		{
			proto = kbGetProtoUnitID("Fence Iron");
		}
		case RELIC_SILVER:
		{
			proto = kbGetProtoUnitID("Dock");
		}
		case RELIC_GOLD:
		{
			proto = kbGetProtoUnitID("Lighthouse");
		}
	}
	return(proto);
}

void relicDescription(int relic = 0) {
	string icon = relicIcon(relic);
	string msg = relicName(relic);
	string textgap = " - Value = ";
	int price = relicCost(relic);
	string message = msg + textgap + price;
	trShowImageDialog(icon, message);
}

//declare the db first
int dFreeRelics = 0;
int xRelicName = 0;
int xRelicValue = 0;
//int xRelicPrice = 0;

rule setup_databases
active
highFrequency
{
	dFreeRelics = xInitDatabase("FreeRelics"); //db name
	xRelicName = xInitAddInt(dFreeRelics, "name"); //unit name
	xRelicValue = xInitAddInt(dFreeRelics, "value", 1); //value of the relic, default to 1=iron
	xsDisableSelf();
}

void spawnRelicSpecific(vector v = vector (0,0,0), int val = 1){
	trQuestVarSet("TEMP", trGetNextUnitScenarioNameNumber());
	trArmyDispatch("0,0", "Dwarf", 1,xsVectorGetX(v),0,xsVectorGetZ(v),0,true);
	xAddDatabaseBlock(dFreeRelics, true);
	xSetInt(dFreeRelics, xRelicName, 1*trQuestVarGet("TEMP"));
	xSetInt(dFreeRelics, xRelicValue, val);
	trUnitSelectClear();
	trUnitSelectByQV("TEMP");
	trUnitChangeProtoUnit("Relic");
	trChatSend(0, "Free relics = "+xGetDatabaseCount(dFreeRelics)+"");
}

void reselectMyself() {
	uiClearSelection();
	/*
	int p = trCurrentPlayer();
	int class = xGetInt(dPlayerData, xPlayerClass, p);
	trackInsert();
	trackAddWaypoint();
	trackAddWaypoint();
	trBlockAllSounds(false);
	uiFindType(kbGetProtoUnitName(xGetInt(dClass, xClassProto, class)));
	trackPlay(1,999);
	*/
}

/*
void processFreeRelicsOLD(int count = 1) {
	float amt = 0;
	int db = 0;
	vector pos = vector(0,0,0);
	for (x=xsMin(count, xGetDatabaseCount(dFreeRelics)); > 0) {
		amt = 0;
		xDatabaseNext(dFreeRelics);
		xUnitSelect(dFreeRelics, xRelicName);
		//STARRED CODE HERE AND BELOW ELSEIF
		if(trUnitIsSelected()) {
			//trShowImageDialog(relicIcon(xGetInt(dFreeRelics, xRelicValue)), relicName(xGetInt(dFreeRelics, xRelicValue)));
			relicDescription(xGetInt(dFreeRelics, xRelicValue));
			reselectMyself();
		}
	}
}
*/

void processFreeRelics(int count = 1) {
	float amt = 0;
	int db = 0;
	vector pos = vector(0,0,0);
	for (x=xsMin(count, xGetDatabaseCount(dFreeRelics)); > 0) {
		amt = 0;
		xDatabaseNext(dFreeRelics);
		xUnitSelect(dFreeRelics, xRelicName);
		if (trUnitGetIsContained("Unit")) {
			for(p=1; < cNumberNonGaiaPlayers) {
				if (trUnitIsOwnedBy(p)) {
					trSetSelectedScale(0,0,-1);
					trMutateSelected(relicProto(xGetInt(dFreeRelics, xRelicValue)));
					trUnitSetAnimationPath("1,0,1,1,0,0,0");
					if (trCurrentPlayer() == p) {
						trChatSend(0, relicName(xGetInt(dFreeRelics, xRelicValue)) + " stored in cargo hold!");
						trSoundPlayFN("researchcomplete.wav","1",-1,"","");
					}
					/*
					db = getWarehouseDB(p);
					xAddDatabaseBlock(db, true);
					xSetInt(db, xRelicName, xGetInt(dFreeRelics, xRelicName));
					xSetInt(db, xRelicType, xGetInt(dFreeRelics, xRelicType));
					*/
					xFreeDatabaseBlock(dFreeRelics);
					break; //ends the loop
				}
				
			}
		} else if (trUnitIsSelected()) {
			relicDescription(xGetInt(dFreeRelics, xRelicValue));
			reselectMyself();
		}
	}
}

rule eternal_loops
active
highFrequency
{
	processFreeRelics(5);
	//trChatSend(0, "Free relics = "+xGetDatabaseCount(dFreeRelics)+"");
	/* relics dropped */
	/*
	trQuestVarSet("relicPlayer", 1 + trQuestVarGet("relicPlayer"));
	if (trQuestVarGet("relicPlayer") >= cNumberNonGaiaPlayers) {
		trQuestVarSet("relicPlayer", 1);
	}
	p = trQuestVarGet("relicPlayer");
	xSetPointer(dPlayerData, p);
	if (xGetBool(dPlayerData, xPlayerResigned) == false) {
		xUnitSelect(dPlayerData, xPlayerUnit);
		if (trUnitAlive() && xGetInt(dPlayerData, xPlayerDead) <= 0) {
			pos = kbGetBlockPosition(""+xGetInt(dPlayerData,xPlayerUnit), true);
			db = getRelicsDB(p);
			for(x=xGetDatabaseCount(db); >0) {
				xDatabaseNext(db);
				xUnitSelect(db, xUnitName);
				if (trUnitGetIsContained("Unit") == false) {
					if (xGetInt(db, xRelicType) < KEY_RELICS) {
						relicReturned = false;
						if ((xGetInt(db, xRelicType) == RELIC_TRANSPORTER_TICKET) && Multiplayer) {
							trUnitDestroy();
							if (trCurrentPlayer() == p) {
								uiMessageBox("Relic Transporter Ticket unequipped. Return to singleplayer if you want to equip it again.");
							}
						} else if (distanceBetweenVectors(pos, trVectorQuestVarGet("relicTransporterGuyPos")) < 36) {
							relicReturned = true;
							if (trPlayerUnitCountSpecific(p, "Villager Atlantean Hero") == 0) {
								if (trPlayerResourceCount(p, "gold") >= 100) {
									trPlayerGrantResources(p, "gold", -100);
									trQuestVarSet("p"+p+"transporterPurchased", 1);
									spawnPlayerUnit(p, kbGetProtoUnitID("Villager Atlantean Hero"), pos);
									if (trCurrentPlayer() == p) {
										trChatSend(0, "A Relic Transporter has been hired!");
										trSoundPlayFN("favordump.wav","1",-1,"","");
										trSoundPlayFN("villagercreate.wav","1",-1,"","");
									}
								}
							}
							
							
							if (relicReturned == false) {
								id = kbGetBlockID(""+xGetInt(db, xUnitName));
								if (trCurrentPlayer() == p) {
									trSoundPlayFN("backtowork.wav","1",-1,"","");
									trChatSend(0, relicName(xGetInt(db, xRelicType)) + " dropped.");
								}
								if (kbGetUnitBaseTypeID(id) == relicProto(xGetInt(db, xRelicType))) {
									trUnitChangeProtoUnit("Relic");
									xAddDatabaseBlock(dFreeRelics, true);
									xSetInt(dFreeRelics, xUnitName, xGetInt(db, xUnitName));
									xSetInt(dFreeRelics, xRelicType, xGetInt(db, xRelicType));
								}
								xFreeDatabaseBlock(db);
							}
						}
					}
				}
			}
		}
	}*/
}
