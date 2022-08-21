const int RELIC_NUMBER = 9;
const int RELIC_IRON = 1;
const int RELIC_BRONZE = 2;
const int RELIC_SILVER = 3;
const int RELIC_GOLD = 4;
const int RELIC_PLATINUM = 5;
const int RELIC_URANIUM = 6;
const int RELIC_RUBY = 7;
const int RELIC_SAPPHIRE = 8;
const int RELIC_DIAMOND = 9;

const int URANIUM_DAMAGE = 1;

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
		case RELIC_PLATINUM:
		{
			msg = "Platinum";
		}
		case RELIC_URANIUM:
		{
			msg = "Uranium";
		}
		case RELIC_RUBY:
		{
			msg = "Ruby";
		}
		case RELIC_SAPPHIRE:
		{
			msg = "Sapphire";
		}
		case RELIC_DIAMOND:
		{
			msg = "Diamond";
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
		case RELIC_PLATINUM:
		{
			price = 7;
		}
		case RELIC_URANIUM:
		{
			price = 9;
		}
		case RELIC_RUBY:
		{
			price = 10;
		}
		case RELIC_SAPPHIRE:
		{
			price = 12;
		}
		case RELIC_DIAMOND:
		{
			price = 15;
		}
	}
	return(price);
}

string RelicColour(int relic = 0) {
	string colour = "1,1,1";
	switch(relic)
	{
		case RELIC_IRON:
		{
			colour = "0.22,0.25,0.23";
		}
		case RELIC_BRONZE:
		{
			colour = "0.69,0.55,0.34";
		}
		case RELIC_SILVER:
		{
			colour = "0.66,0.66,0.66";
		}
		case RELIC_GOLD:
		{
			colour = "0.83,0.68,0.21";
		}
		case RELIC_PLATINUM:
		{
			colour = "1,1,1";
		}
		case RELIC_URANIUM:
		{
			colour = "0.08,0.84,0.2";
		}
		case RELIC_RUBY:
		{
			colour = "0.68,0,0.11";
		}
		case RELIC_SAPPHIRE:
		{
			colour = "0,0.44,1";
		}
		case RELIC_DIAMOND:
		{
			colour = "1,1,1";
		}
	}
	return(colour);
}

string relicIcon(int relic = 0) {
	string icon = "icons\infantry g hoplite icon 64";
	switch(relic)
	{
		case RELIC_IRON:
		{
			icon = "icons\scenario thors hammer icon 64";
		}
		case RELIC_BRONZE:
		{
			icon = "icons\special x behemoth icons 64";
		}
		case RELIC_SILVER:
		{
			icon = "icons\special x automaton icons 64";
		}
		case RELIC_GOLD:
		{
			icon = "icons\special n battle boar icon 64";
		}
		case RELIC_PLATINUM:
		{
			icon = "icons\hero g bellerophon icon 64";
		}
		case RELIC_URANIUM:
		{
			icon = "icons\special g medusa icon 64";
		}
		case RELIC_RUBY:
		{
			icon = "icons\special g manticore icon 64";
		}
		case RELIC_SAPPHIRE:
		{
			icon = "icons\special x servant icons 64";
		}
		case RELIC_DIAMOND:
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
			proto = kbGetProtoUnitID("Thor Hammer Head");
		}
		case RELIC_BRONZE:
		{
			proto = kbGetProtoUnitID("Behemoth");
		}
		case RELIC_SILVER:
		{
			proto = kbGetProtoUnitID("Automaton SPC");
		}
		case RELIC_GOLD:
		{
			proto = kbGetProtoUnitID("Battle Boar");
		}
		case RELIC_PLATINUM:
		{
			proto = kbGetProtoUnitID("Hero Greek Bellerophon");
		}
		case RELIC_URANIUM:
		{
			proto = kbGetProtoUnitID("Medusa");
		}
		case RELIC_RUBY:
		{
			proto = kbGetProtoUnitID("Manticore");
		}
		case RELIC_SAPPHIRE:
		{
			proto = kbGetProtoUnitID("Servant");
		}
		case RELIC_DIAMOND:
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

void spawnRelicSpecific(vector v = vector (0,0,0), int val = 1){
	trQuestVarSet("TEMPRELIC", trGetNextUnitScenarioNameNumber());
	trArmyDispatch(""+cNumberNonGaiaPlayers+",0", "Dwarf", 1,xsVectorGetX(v),0,xsVectorGetZ(v),0,true);
	xAddDatabaseBlock(dFreeRelics, true);
	xSetInt(dFreeRelics, xRelicName, 1*trQuestVarGet("TEMPRELIC"));
	xSetInt(dFreeRelics, xRelicValue, val);
	xSetInt(dFreeRelics, xRelicTick, (trTimeMS()+50));
	if(xGetInt(dFreeRelics, xRelicValue) == RELIC_URANIUM){
		xSetInt(dFreeRelics, xRelicDamage, URANIUM_DAMAGE);
	}
	else{
		xSetInt(dFreeRelics, xRelicDamage, 0);
	}
	trUnitSelectClear();
	trUnitSelectByQV("TEMPRELIC");
	trUnitChangeProtoUnit("Relic");
	if(val == 0){
		trChatSend(0, "ERROR AT" + v);
	}
	//trChatSend(0, "Free relics = "+xGetDatabaseCount(dFreeRelics)+"");
}

void reselectMyself() {
	uiClearSelection();
	int p = trCurrentPlayer();
	trackInsert();
	trackAddWaypoint();
	trackAddWaypoint();
	uiFindType(kbGetProtoUnitName(554));
	trackPlay(1,999);
	
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
	//vector pos = vector(0,0,0);
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
						//trChatSend(0, relicName(xGetInt(dFreeRelics, xRelicValue)) + " stored in cargo hold!");
						ColouredChatToPlayer(p, RelicColour(xGetInt(dFreeRelics, xRelicValue)), relicName(xGetInt(dFreeRelics, xRelicValue)) + " stored in cargo hold!");
						trSoundPlayFN("researchcomplete.wav","1",-1,"","");
					}
					/*
					db = getWarehouseDB(p);
					xAddDatabaseBlock(db, true);
					xSetInt(db, xRelicName, xGetInt(dFreeRelics, xRelicName));
					xSetInt(db, xRelicType, xGetInt(dFreeRelics, xRelicType));
					*/
					xAddDatabaseBlock(dHeldRelics, true);
					xSetInt(dHeldRelics, xRelicName, 1*xGetInt(dFreeRelics, xRelicName));
					xSetInt(dHeldRelics, xRelicValue, 1*xGetInt(dFreeRelics, xRelicValue));
					xSetInt(dHeldRelics, xRelicTick, (trTimeMS()+50));
					if(xGetInt(dFreeRelics, xRelicValue) == RELIC_URANIUM){
						xSetInt(dHeldRelics, xRelicDamage, URANIUM_DAMAGE);
					}
					else{
						xSetInt(dHeldRelics, xRelicDamage, 0);
					}
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

void processHeldRelics(int count = 1) {
	float amt = 0;
	int dropper = 0;
	int db = 0;
	float currentDistance = 0;
	for (x=xsMin(count, xGetDatabaseCount(dHeldRelics)); > 0) {
		amt = 0;
		xDatabaseNext(dHeldRelics);
		xUnitSelect(dHeldRelics, xRelicName);
		//If relic is dropped
		currentDistance = unitDistanceToVector(xGetInt(dHeldRelics, xRelicName), GVectorSellPos);
		if (trUnitGetIsContained("Unit") == false) {
			for(p=1; < cNumberNonGaiaPlayers) {
				if (trUnitIsOwnedBy(p)) {
					//trChatSend(0, "Dropped by p"+p+""); //WHO DROPPED THE RELIC
					dropper = p;
				}
			}
			if (currentDistance > 80) {
				trUnitChangeProtoUnit("Relic");
				xUnitSelect(dHeldRelics, xRelicName);
				xAddDatabaseBlock(dFreeRelics, true);
				xSetInt(dFreeRelics, xRelicName, 1*xGetInt(dHeldRelics, xRelicName));
				xSetInt(dFreeRelics, xRelicValue, 1*xGetInt(dHeldRelics, xRelicValue));
				xSetInt(dFreeRelics, xRelicTick, (trTimeMS()+50));
				if(xGetInt(dHeldRelics, xRelicValue) == RELIC_URANIUM){
					xSetInt(dFreeRelics, xRelicDamage, 1);
				}
				else{
					xSetInt(dFreeRelics, xRelicDamage, 0);
				}
				xFreeDatabaseBlock(dHeldRelics);
				//break;
			}
		}
		if (currentDistance < 80) {
			for(p=1; < cNumberNonGaiaPlayers) {
				if (trUnitIsOwnedBy(p)) {
					dropper = p;
					trUnitChangeProtoUnit("Rocket");
					trUnitSelectClear();
					spyEffect(1*trQuestVarGet("P"+dropper+"Siphon"), kbGetProtoUnitID("Automaton"), vector(0,0,0), vector(0,0,0), 18);
					//trMutateSelected(kbGetProtoUnitID("Rocket"));
					xUnitSelect(dHeldRelics, xRelicName);
					trPlayerGrantResources(dropper, "Gold", 1*relicCost(1*xGetInt(dHeldRelics, xRelicValue)));
					if (trCurrentPlayer() == dropper) {
						//trChatSend(0, relicName(xGetInt(dHeldRelics, xRelicValue)) + " sold!");
						trQuestVarModify("P"+dropper+"R"+1*xGetInt(dHeldRelics, xRelicValue)+"", "+", 1);
						trSoundPlayFN("favordump.wav","1",-1,"","");
					}
					GSeller = dropper;
					trQuestVarSet("TEMPValue", 1*xGetInt(dHeldRelics, xRelicValue));
					trQuestVarModify("TEMPNumber", "+", 1);
					xFreeDatabaseBlock(dHeldRelics);
					trDelayedRuleActivation("SellMinerals");
					reselectMyself();
					break;
				}
			}
		}
		if(xGetInt(dHeldRelics, xRelicValue) == RELIC_URANIUM){
			if(trTimeMS() > xGetInt(dHeldRelics, xRelicTick)){
				for(p=1; < cNumberNonGaiaPlayers) {
					trDamageUnitsInArea(p,"All",4, xGetInt(dHeldRelics, xRelicDamage));
					trDamageUnit(-1*xGetInt(dHeldRelics, xRelicDamage));
				}
				xSetInt(dHeldRelics, xRelicTick,(trTimeMS()+50));
			}
		}
	}
}

rule SellMinerals
inactive
highFrequency
{
	//trChatSendToPlayer(0, GSeller, ""+1*trQuestVarGet("TEMPNumber")+"x "+relicName(1*trQuestVarGet("TEMPValue"))+" sold!");
	for(r=RELIC_NUMBER; >= 1) {
		if(trQuestVarGet("P"+GSeller+"R"+r+"") > 0){
			ColouredChatToPlayer(GSeller, RelicColour(r), ""+1*trQuestVarGet("P"+GSeller+"R"+r+"")+"x "+relicName(r)+" sold!");
			trQuestVarSet("P"+GSeller+"R"+r+"", 0);
		}
	}
	xsDisableSelf();
}

//These two are probably wrong anyway, also DB set
void HideRelics(int owner = 1) {
	int db = 0;
	float currentDistance = 0;
	vector pos = vector(1,1,1);
	for (x=xsMin(30, xGetDatabaseCount(dHeldRelics)); > 0) {
		xDatabaseNext(dHeldRelics);
		xUnitSelect(dHeldRelics, xRelicName);
		//If relic is owned
		if (trUnitIsOwnedBy(owner)) {
			trUnitChangeProtoUnit("Cinematic Block");
			xUnitSelect(dHeldRelics, xRelicName);
			xAddDatabaseBlock(dHiddenRelics, true);
			xSetInt(dHiddenRelics, xRelicName, 1*xGetInt(dHeldRelics, xRelicName));
			xSetInt(dHiddenRelics, xRelicValue, 1*xGetInt(dHeldRelics, xRelicValue));
			xSetInt(dHiddenRelics, xRelicTick, 1*xGetInt(dHeldRelics, xRelicTick));
			xSetInt(dHiddenRelics, xRelicDamage, 1*xGetInt(dHeldRelics, xRelicDamage));
			xSetInt(dHiddenRelics, xOwner, owner);
			xFreeDatabaseBlock(dHeldRelics);
			//break;
		}
	}
}

void ReturnRelics(int owner = 1) {
	xsSetContextPlayer(0);
	for (x= xGetDatabaseCount(dHiddenRelics); > 0) {
		xDatabaseNext(dHiddenRelics);
		xUnitSelect(dHiddenRelics, xRelicName);
		if (xGetInt(dHiddenRelics, xOwner) == owner) {
			trUnitChangeProtoUnit("Relic");
			xUnitSelect(dHiddenRelics, xRelicName);
			trBlockAllSounds();
			trImmediateUnitGarrison(""+(1*trQuestVarGet("P"+owner+"Siphon"))+"");
			trUnblockAllSounds();
			trSetSelectedScale(0,0,-1);
			trMutateSelected(relicProto(xGetInt(dHiddenRelics, xRelicValue)));
			trUnitSetAnimationPath("1,0,1,1,0,0,0");
			xAddDatabaseBlock(dHeldRelics, true);
			xSetInt(dHeldRelics, xRelicName, 1*xGetInt(dHiddenRelics, xRelicName));
			xSetInt(dHeldRelics, xRelicValue, 1*xGetInt(dHiddenRelics, xRelicValue));
			xSetInt(dHeldRelics, xRelicTick, 1*xGetInt(dHiddenRelics, xRelicTick));
			xSetInt(dHeldRelics, xRelicDamage, 1*xGetInt(dHiddenRelics, xRelicDamage));
			xFreeDatabaseBlock(dHiddenRelics);
			//break;
		}
	}
}

rule eternal_loops
active
highFrequency
{
	processFreeRelics(10);
	processHeldRelics(10);
	
	if(trTime() > 1*trQuestVarGet("TimeSeconds")){
		trQuestVarModify("TimeSeconds", "+", 1);
		for (x= xGetDatabaseCount(dGasPocket); > 0) {
			xDatabaseNext(dGasPocket);
			trVectorQuestVarSet("TempGas", xsVectorSet(8*xGetInt(dGasPocket, xGasCol)-4,3,8*xGetInt(dGasPocket, xGasRow)-4));
			//trVectorQuestVarEcho("TempGas");
			//trVectorQuestVarEcho("P1Pos");
			for(p = 1; <= cNumberNonGaiaPlayers){
				if(trDistanceBetweenVectorsSquared("TempGas", "P"+p+"Pos") < 30){
					int temp = trGetNextUnitScenarioNameNumber();
					trArmyDispatch("0,0", "Dwarf", 1, 1,1,1, 0, true);
					trUnitSelectClear();
					trUnitSelect(""+temp);
					trUnitSelectClear();
					trUnitSelect(""+temp);
					trUnitTeleport(trVectorQuestVarGetX("TempGas"),trVectorQuestVarGetY("TempGas"),trVectorQuestVarGetZ("TempGas"));
					trMutateSelected(kbGetProtoUnitID("Harpy"));
					trUnitSelectClear();
					trUnitSelect(""+temp);
					trSetSelectedHeight(-10.0);
					trUnitSelectClear();
					trUnitSelect(""+temp);
					trSetSelectedScale(0,0,0);
					trUnitSelectClear();
					trUnitSelect(""+temp);
					trUnitOverrideAnimation(1,0,false,true,-1,-1);
					xFreeDatabaseBlock(dGasPocket);
					trUnitSelectClear();
					trUnitSelectByQV("P"+p+"Siphon");
					trDamageUnit(400);
					trChatSendToPlayer(0, p, "<color=1,0,0>You hit a gas pocket!</color>");
					if(trCurrentPlayer() == p){
						trSoundPlayFN("meteorbighit.wav","1",-1,"","");
						trSoundPlayFN("uprootbirth.wav","1",-1,"","");
					}
				}
			}
		}
		
	}
	
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
