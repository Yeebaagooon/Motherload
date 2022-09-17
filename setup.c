/*	int loaddata = 0;
loaddata = trGetScenarioUserData(1);
trQuestVarSet("Gold", loaddata);
trQuestVarEcho("Gold");
if(trQuestVarGet("Gold") == -1){
	trQuestVarSet("Gold", 0);
	loaddata = 0;
}
for(x = 1; <= 9){
	trQuestVarSet("GoldDigit"+x+"", iModulo(10, loaddata));
	loaddata = loaddata / 10;
}

*/

rule Initialise
active
highFrequency
runImmediately
{
	characterDialog("Waiting for everyone to connect.", " ", "icons\special e son of osiris icon 64");
	//trUIFadeToColor(0, 0, 0, 0, 10000, false);
	trFadeOutAllSounds(0.1);
	trFadeOutMusic(0.1);
	trUIFadeToColor(1,0,0,0,0,true);
	trBlockAllSounds(true);
	xsDisableRule("BasicVC1");
	xsDisableRule("BasicVC2");
	
	//trSetFogAndBlackmap(false, false);
	%
	for(p=1; < cNumberNonGaiaPlayers) {
		code("trStringQuestVarSet(\"p"+p+"name\", \""+rmGetPlayerName(p)+"\");");
	}
	%
	xsDisableSelf();
	xsSetContextPlayer(0);
	map("q", "game", "uiSetSpecialPower(227) uiSpecialPowerAtPointer");
	map("w", "game", "uiSetSpecialPower(407) uiSpecialPowerAtPointer");
	map("e", "game", "uiSetSpecialPower(156) uiSpecialPowerAtPointer");
	map("r", "game", "uiSetSpecialPower(234) uiSpecialPowerAtPointer");
	//special powers
	map("l", "game", "uiSetSpecialPower(133) uiSpecialPowerAtPointer");
	map("a", "game", "uiSetSpecialPower(220) uiSpecialPowerAtPointer");
}

rule START
active
highFrequency
{
	trPlayerKillAllGodPowers(0);
	for(p = 1; <= cNumberNonGaiaPlayers){
		trSetCivAndCulture(p, 3, 1);
		trPlayerGrantResources(p, "Food", -10000.0);
		trPlayerGrantResources(p, "Wood", -10000.0);
		trPlayerGrantResources(p, "Gold", -10000.0);
		trPlayerGrantResources(p, "Favor", -10000.0);
		trPlayerKillAllGodPowers(p);
		trLetterBox(true);
		if(trCurrentPlayer() == p){
			trSoundPlayFN("\Yeebaagooon\Motherload\Test sound.mp3", "1", 13, "","");
		}
	}
	
	while(cNumberNonGaiaPlayers>=trQuestVarGet("PlayerID")) {
		trQuestVarSet("PlayerID2", 0);
		while(cNumberNonGaiaPlayers>=trQuestVarGet("PlayerID2")) {
			trPlayerSetDiplomacy(trQuestVarGet("PlayerID"), trQuestVarGet("PlayerID2"), "Ally");
			trPlayerSetDiplomacy(trQuestVarGet("PlayerID2"), trQuestVarGet("PlayerID"), "Ally");
			trPlayerSetDiplomacy(trQuestVarGet("PlayerID2"), 0, "Ally");
			trPlayerSetDiplomacy(0, trQuestVarGet("PlayerID2"), "Enemy");
			trPlayerSetDiplomacy(trQuestVarGet("PlayerID2"), cNumberNonGaiaPlayers, "Enemy");
			trPlayerSetDiplomacy(cNumberNonGaiaPlayers, trQuestVarGet("PlayerID2"), "Enemy");
		trQuestVarSet("PlayerID2", trQuestVarGet("PlayerID2")+1);}
	trQuestVarSet("PlayerID", trQuestVarGet("PlayerID")+1);}
	
	
	//start fade to black
	//trUIFadeToColor(1,0,0,0,0,true);
	
	/*
	trShowImageDialog("icons\improvement wealth of erebus icon 64", MapName + " by Yeebaagooon");
	gadgetUnreal("ShowImageBox-BordersTop");
	gadgetUnreal("ShowImageBox-BordersBottom");
	gadgetUnreal("ShowImageBox-BordersLeft");
	gadgetUnreal("ShowImageBox-BordersRight");
	gadgetUnreal("ShowImageBox-BordersLeftTop");
	gadgetUnreal("ShowImageBox-BordersLeftBottom");
	gadgetUnreal("ShowImageBox-BordersRightBottom");
	gadgetUnreal("ShowImageBox-BordersRightTop");
	gadgetUnreal("ShowImageBox-CloseButton");
	pause(0);
	*/
	xsEnableRule("setup_data");
	characterDialog("Initialising map", " ", "icons\special e son of osiris icon 64");
	xsDisableSelf();
}

/*
README

A slot can hold an integer value up to 1 billion. Make sure you're not using up all this space.
To calculate how much space you are using in a slot, multiply together all the various sizes of
data that are stored in that slot.

In Age of Mythology, we have 16 slots to work with, numbered 0-15.

Make sure that there are no units at the start of the map. If you want to do any
map initialization suff, make sure it is done in or after the NEXT_TRIGGER_NAME trigger.
This is to ensure that the unit names are contiguous and starting from 0, which is
important for the data load algorithm.

Also make sure that the bottom corner of the map is passable terrain at the very start. (It can be changed after data loading is done)

Also, using this will modify the cost of swordsman hero to 0 and also make swordsmen flying units.
Be wary of this side effect. You can modify it back to what you want later.

There are two functions you can use to add data:

////////////////////
// addSavedDataDB //
////////////////////
Use this when you want to save the data in a database containing player info. This data
will be synced with other players at the start of the map.

NOTE: The database must be large enough to have an entry for each player. When data is
loaded, it will be stored at the database <destDB> at the variable <destVar> at the index <p>,
where p is the player. Also, the database must be declared BEFORE this function is ever
called. You can do so by initializing the database in a highFrequency trigger that is
active at the very start before this trigger is run.

addSavedDataDB(<DB name>, <Var name>, <slot number>, <data range>);

Example: addSavedDataDB(dPlayerData, xPlayerHealth, 3, 10);
This will tell the game to keep track of the xPlayerHealth value for each player in the dPlayerData database.
Its value ranges from 0-9 and it is stored in slot 3.

////////////////////
// addLocalDataQV //
////////////////////
Use this when you want to save the data in a quest var but LOCAL. This is important because
this data is NOT transferred to other players whatsoever, and is completely local to the player.

addLocalDataQV(<QV name>, <slot number>, <data range>);

Example: addLocalDataQV("cow", 0, 10);
This will tell the game to keep track of the QV "cow". Its value is limited to the range 0-9 and it is stored in slot 0.



///////////////
// IMPORTANT //
///////////////
DO NOT MIX LOCAL AND SAVE DATA! This is very important! Each slot must contain either local data or data that is transferred
to other players, but never both!
*/

rule setup_data
inactive
highFrequency
{
	NEXT_TRIGGER_NAME = "load1"; // the next trigger to run after data load is complete
	/*
	Add data to slots here
	
	EXAMPLE
	name | slot | maximum value
	addSavedDataQV("cow", 1, 10);
	addSavedDataDB(dPlayerData, xPlayerGold, 0, 1000);
	*/
	
	/*
	Slot 0
	Total size: 1
	*/
	addSavedDataDB(dPlayerData, xStageUnlocked , 0, 10);
	addSavedDataDB(dPlayerData, xStageStatus , 0, 4);
	//addLocalDataQV("example", 0, 1000); // the QV "example" can have an integer value from 0-999. It is stored in the first slot
	
	/*
	Slot 1
	Total size: 1000
	*/
	addSavedDataDB(dPlayerData, xGold, 1, 100000);
	/*
	Slot 2
	Total size: 1,000,000
	*/
	addSavedDataDB(dPlayerData, xDrillLevel, 2, 9);
	
	/*
	Slot 3
	Total size: 1000
	*/
	addSavedDataDB(dPlayerData, xHullLevel, 3, 9);
	
	/*
	Slot 4
	Total size: 0
	*/
	addSavedDataDB(dPlayerData, xFuelLevel, 4, 9);
	
	/*
	Slot 5
	Total size: 0
	*/
	addSavedDataDB(dPlayerData, xCargoLevel, 5, 9);
	
	/*
	Slot 6
	Total size: 0
	*/
	addSavedDataDB(dPlayerData, xEngineLevel, 6, 9);
	
	/*
	Slot 7
	Total size: 0
	*/
	addSavedDataDB(dPlayerData, xRadiatorLevel, 7, 9);
	
	/*
	Slot 8
	Total size: 0
	*/
	addLocalDataQV("CineStatus", 8, 10);
	
	/*
	Slot 9
	Total size: 0
	*/
	for(x=0; <= 18) {
		addSavedDataDB(dPlayerData, xBonus+x, 9, 3);
	}
	
	/*
	Slot 10
	Total size: 0
	*/
	for(x=19; <= 21) {
		addSavedDataDB(dPlayerData, xBonus+x, 10, 3);
	}
	for(x=1; <= 15) {
		addSavedDataDB(dPlayerData, xRelicCollected+x, 10, 2);
	}
	
	/*
	Slot 11
	Total size: 0
	*/
	for(x=16; <= 21) {
		addSavedDataDB(dPlayerData, xRelicCollected+x, 11, 2);
	}
	
	/*
	Slot 12
	Total size: 0
	*/
	addSavedDataDB(dPlayerData, xFuelSpend, 12, 5000);
	addSavedDataDB(dPlayerData, xHullSpend, 12, 5000);
	
	/*
	Slot 13
	Total size: 0
	*/
	
	/*
	Slot 14
	Total size: 0
	*/
	
	/*
	Slot 15
	Total size: 0
	*/
	xsDisableSelf();
}

rule data_load_emergency_exit_02
highFrequency
inactive
{
	if (trTime() > cActivationTime + 7) {
		xsDisableSelf();
		trLetterBox(false);
		subModeEnter("Simulation","Editor");
		uiMessageBox("","leaveGame()");
		uiCycleCurrentActivate();
		uiCycleCurrentActivate();
		subModeLeave("Simulation","Editor");
		modeEnter("pregame");
		modeEnter("Simulation");
	}
}



rule load1
inactive
highFrequency
{
	characterDialog("Loading map", ""+MapVersion+"", "icons\special e son of osiris icon 64");
	xsEnableRule("load4");
	xsEnableRule("Stats");
	trBlockAllSounds(false);
	modifyProtounitAbsolute("Vision Revealer", 0, 2, 2400);
	trArmyDispatch("0,0", "Vision Revealer", 1, 0, 0, 0, 0, false);
	trArmyDispatch("0,0", "Cinematic Block", 1, 0, 0, 0, 0, false);
	for(p = 1; <= cNumberNonGaiaPlayers){
		deployLocHeading(0, p*2, "Victory Marker", p, 180);
	}
	for(p = 1; <= cNumberNonGaiaPlayers){
		trPlayerGrantResources(p, "Food", -10000.0);
		trPlayerGrantResources(p, "Wood", -10000.0);
		trPlayerGrantResources(p, "Gold", -10000.0);
		trPlayerGrantResources(p, "Favor", -10000.0);
		trPlayerKillAllGodPowers(p);
	}
	xsDisableSelf();
}

rule load4
inactive
highFrequency
{
	//fade out when loaded
	trUnblockAllSounds();
	//trUIFadeToColor(0,0,0,1000,1,false);
	trOverlayTextColour(255, 125, 0);
	gadgetUnreal("ShowImageBox");
	trOverlayText(MapName, 8.0, 579, 35, 1000);
	trSetUnitIdleProcessing(true);
	xsDisableSelf();
	if(aiIsMultiplayer() == false){
		if(OverrideSP == false){
			trDelayedRuleActivation("LoadSP");
			trLetterBox(false);
		}
		else if(OverrideSP == true){
			trDelayedRuleActivation("LoadMP");
		}
	}
	else if(aiIsMultiplayer() == true){
		trDelayedRuleActivation("LoadMP");
	}
	trSetFogAndBlackmap(false, false);
	gadgetReal("ShowImageBox-BordersTop");
	gadgetReal("ShowImageBox-BordersBottom");
	gadgetReal("ShowImageBox-BordersLeft");
	gadgetReal("ShowImageBox-BordersRight");
	gadgetReal("ShowImageBox-BordersLeftTop");
	gadgetReal("ShowImageBox-BordersLeftBottom");
	gadgetReal("ShowImageBox-BordersRightBottom");
	gadgetReal("ShowImageBox-BordersRightTop");
	gadgetReal("ShowImageBox-CloseButton");
	//startNPCDialog(1);
	for(p = 1; <= cNumberNonGaiaPlayers){
		xSetPointer(dPlayerData, p);
		if(xGetInt(dPlayerData, xDrillLevel) == 0){
			xSetInt(dPlayerData, xDrillLevel, 1);
		}
		if(xGetInt(dPlayerData, xHullLevel) == 0){
			xSetInt(dPlayerData, xHullLevel, 1);
		}
		if(xGetInt(dPlayerData, xFuelLevel) == 0){
			xSetInt(dPlayerData, xFuelLevel, 1);
		}
		if(xGetInt(dPlayerData, xCargoLevel) == 0){
			xSetInt(dPlayerData, xCargoLevel, 1);
		}
		if(xGetInt(dPlayerData, xEngineLevel) == 0){
			xSetInt(dPlayerData, xEngineLevel, 1);
		}
		if(xGetInt(dPlayerData, xRadiatorLevel) == 0){
			xSetInt(dPlayerData, xRadiatorLevel, 1);
		}
	}
}

void PaintPlanets(int x = 0, int z = 0, int offsetearth = 0){
	PaintAtlantisArea(x,z,x+60,z+20,"black");
	trPaintTerrain(x+1,z+10,x+59,z+10, 0, 50, false);
	//EYECANDY PLANET 7
	trBlockAllSounds();
	int temp = trGetNextUnitScenarioNameNumber();
	trArmyDispatch("0,0","Dwarf",1,x*2+84,0,z*2+10,90,true);
	trArmySelect("0,0");
	trUnitChangeProtoUnit("Spy Eye");
	trUnitSelectClear();
	trUnitSelect(""+temp, true);
	trMutateSelected(kbGetProtoUnitID("Hades Door"));
	trSetSelectedScale(0,0,0);
	trUnitOverrideAnimation(25,0,false,false,-1);
	trUnitSetAnimationPath("3,0,0,0,0,0,0");
	trSetUnitOrientation(vector(-1,-1,-1),vector(0,0,0),true);
	xAddDatabaseBlock(dPlanetEyecandy, true);
	xSetInt(dPlanetEyecandy, xPlanetEyecandyName,temp);
	xSetInt(dPlanetEyecandy, xPlanetEyecandyStage, 7);
	temp = trGetNextUnitScenarioNameNumber();
	trArmyDispatch("0,0","Dwarf",1,x*2+84,0,z*2+10,180,true);
	trArmySelect("0,0");
	trUnitChangeProtoUnit("Spy Eye");
	trUnitSelectClear();
	trUnitSelect(""+temp, true);
	trMutateSelected(kbGetProtoUnitID("Hades Door"));
	trSetSelectedScale(0,0,0);
	trUnitOverrideAnimation(25,0,false,false,-1);
	trUnitSetAnimationPath("3,0,0,0,0,0,0");
	trSetUnitOrientation(vector(-1,-1,-1),vector(0,0,0),true);
	xAddDatabaseBlock(dPlanetEyecandy, true);
	xSetInt(dPlanetEyecandy, xPlanetEyecandyName,temp);
	xSetInt(dPlanetEyecandy, xPlanetEyecandyStage, 7);
	temp = trGetNextUnitScenarioNameNumber();
	trArmyDispatch("0,0","Dwarf",1,x*2+84,0,z*2+10,270,true);
	trArmySelect("0,0");
	trUnitChangeProtoUnit("Spy Eye");
	trUnitSelectClear();
	trUnitSelect(""+temp, true);
	trMutateSelected(kbGetProtoUnitID("Hades Door"));
	trSetSelectedScale(0,0,0);
	trUnitOverrideAnimation(25,0,false,false,-1);
	trUnitSetAnimationPath("3,0,0,0,0,0,0");
	trSetUnitOrientation(vector(-1,-1,-1),vector(0,0,0),true);
	xAddDatabaseBlock(dPlanetEyecandy, true);
	xSetInt(dPlanetEyecandy, xPlanetEyecandyName,temp);
	xSetInt(dPlanetEyecandy, xPlanetEyecandyStage, 7);
	FloatingUnit("Cypress", x*2+84, 8, z*2+10, 0, 4,0.5,4);
	xAddDatabaseBlock(dPlanetEyecandy, true);
	xSetInt(dPlanetEyecandy, xPlanetEyecandyName,1*trQuestVarGet("QVRelic"));
	xSetInt(dPlanetEyecandy, xPlanetEyecandyStage, 7);
	trUnitSetVariation(trQuestVarGet("QVRelic"), 0);
	FloatingUnit("Cypress", x*2+84, 8.5, z*2+10, 0, 4,-0.5,4);
	xAddDatabaseBlock(dPlanetEyecandy, true);
	xSetInt(dPlanetEyecandy, xPlanetEyecandyName,1*trQuestVarGet("QVRelic"));
	xSetInt(dPlanetEyecandy, xPlanetEyecandyStage, 7);
	trUnitSetVariation(trQuestVarGet("QVRelic"), 0);
	trUnblockAllSounds();
	//monument
	temp = trGetNextUnitScenarioNameNumber();
	trArmyDispatch("0,0","Dwarf",1,x*2+12*8, 3, z*2+30,90,true);
	trArmySelect("0,0");
	trUnitChangeProtoUnit("Spy Eye");
	trUnitSelectClear();
	trUnitSelect(""+temp, true);
	trMutateSelected(kbGetProtoUnitID("Monument 5"));
	trSetSelectedScale(0,0,0);
	trUnitOverrideAnimation(4,0,false,false,-1);
	xAddDatabaseBlock(dPlanetEyecandy, true);
	xSetInt(dPlanetEyecandy, xPlanetEyecandyName,temp);
	xSetInt(dPlanetEyecandy, xPlanetEyecandyStage, 8);
	for(p = 1; <= 10){
		int next = trGetNextUnitScenarioNameNumber();
		int offset = 0;
		if (iModulo(2, p) == 0) { //if is divisble by 2
			offset = 20;
		}
		if (iModulo(10, p) == 0) { //if is divisble by 2
			offset = 10;
		}
		xSetPointer(dPlayerData, 1);
		if(aiIsMultiplayer() == true){
			if(xGetInt(dPlayerData, xStageUnlocked) > xGetInt(dObelisks, xObeliskStage)-1){
				UnitCreate(0, "Outpost", x*2+12*p, z*2+10+offset, 90);
				xAddDatabaseBlock(dObelisks, true);
				xSetInt(dObelisks, xObeliskName,next);
				xSetInt(dObelisks, xObeliskStage, p);
			}
			else{
				UnitCreate(0, "Victory Marker", x*2+12*p, z*2+10+offset, 90);
			}
		}
		else if(aiIsMultiplayer() == false){
			UnitCreate(0, "Outpost", x*2+12*p, z*2+10+offset, 90);
			xAddDatabaseBlock(dObelisks, true);
			xSetInt(dObelisks, xObeliskName,next);
			xSetInt(dObelisks, xObeliskStage, p);
		}
		if(p == 10){
			xSetPointer(dPlayerData, 1);
			if(xGetInt(dPlayerData, xStageUnlocked) != 9){
				trUnitSelectClear();
				trUnitSelect(""+next, true);
				trUnitChangeProtoUnit("Cinematic Block");
			}
		}
	}
	//EYECANDY PLANET 1
	FloatingUnit("Rock Granite Big", x*2+12, 8, z*2+10, 0, 2,2,2);
	xAddDatabaseBlock(dPlanetEyecandy, true);
	xSetInt(dPlanetEyecandy, xPlanetEyecandyName,1*trQuestVarGet("QVRelic"));
	xSetInt(dPlanetEyecandy, xPlanetEyecandyStage, 1);
	xAddDatabaseBlock(dPlanetEyecandy, true);
	xSetInt(dPlanetEyecandy, xPlanetEyecandyName,1*trQuestVarGet("QVHero"));
	xSetInt(dPlanetEyecandy, xPlanetEyecandyStage, 1);
	trUnitSetVariation(1*trQuestVarGet("QVRelic"), 1);
	FloatingUnit("Fire Hades", x*2+11, 8, z*2+10, 0, 2,2,2);
	xSetInt(dPlanetEyecandy, xPlanetEyecandyName,1*trQuestVarGet("QVRelic"));
	xSetInt(dPlanetEyecandy, xPlanetEyecandyStage, 1);
	xAddDatabaseBlock(dPlanetEyecandy, true);
	xSetInt(dPlanetEyecandy, xPlanetEyecandyName,1*trQuestVarGet("QVHero"));
	xSetInt(dPlanetEyecandy, xPlanetEyecandyStage, 1);
	FloatingUnit("Ice Block", x*2+13, 8, z*2+10, 0, 2,2,2);
	xSetInt(dPlanetEyecandy, xPlanetEyecandyName,1*trQuestVarGet("QVRelic"));
	xSetInt(dPlanetEyecandy, xPlanetEyecandyStage, 1);
	xAddDatabaseBlock(dPlanetEyecandy, true);
	xSetInt(dPlanetEyecandy, xPlanetEyecandyName,1*trQuestVarGet("QVHero"));
	xSetInt(dPlanetEyecandy, xPlanetEyecandyStage, 1);
	//EYECANDY PLANET 2
	FloatingUnit("Rock Dirt Big", x*2+24, 8.5, z*2+31, 0, 1,2,2);
	xAddDatabaseBlock(dPlanetEyecandy, true);
	xSetInt(dPlanetEyecandy, xPlanetEyecandyName,1*trQuestVarGet("QVRelic"));
	xSetInt(dPlanetEyecandy, xPlanetEyecandyStage, 2);
	trUnitSetVariation(1*trQuestVarGet("QVRelic"), 1);
	xAddDatabaseBlock(dPlanetEyecandy, true);
	xSetInt(dPlanetEyecandy, xPlanetEyecandyName,1*trQuestVarGet("QVHero"));
	xSetInt(dPlanetEyecandy, xPlanetEyecandyStage, 2);
	//EYECANDY PLANET 3
	FloatingUnit("Rock Overgrown Big", x*2+36, 8, z*2+10, 0, 2,2,2);
	xAddDatabaseBlock(dPlanetEyecandy, true);
	xSetInt(dPlanetEyecandy, xPlanetEyecandyName,1*trQuestVarGet("QVRelic"));
	xSetInt(dPlanetEyecandy, xPlanetEyecandyStage, 1);
	xAddDatabaseBlock(dPlanetEyecandy, true);
	xSetInt(dPlanetEyecandy, xPlanetEyecandyName,1*trQuestVarGet("QVHero"));
	xSetInt(dPlanetEyecandy, xPlanetEyecandyStage, 1);
	trUnitSetVariation(1*trQuestVarGet("QVRelic"), 1);
	//EYECANDY PLANET 4
	FloatingUnitAnimIdle("Earth", x*2+48, 9, z*2+29, 0, 0.2,0.2,0.2);
	xAddDatabaseBlock(dPlanetEyecandy, true);
	xSetInt(dPlanetEyecandy, xPlanetEyecandyName,1*trQuestVarGet("QVRelic"));
	xSetInt(dPlanetEyecandy, xPlanetEyecandyStage, 4);
	xAddDatabaseBlock(dPlanetEyecandy, true);
	xSetInt(dPlanetEyecandy, xPlanetEyecandyName,1*trQuestVarGet("QVHero"));
	xSetInt(dPlanetEyecandy, xPlanetEyecandyStage, 4);
	trQuestVarSet("tempH", 3.141593 * 180.0 / 180.0);
	trQuestVarSet("tempT", 3.141593 * 90.0 / 180.0);
	trQuestVarSet("tempSinH", xsSin(trQuestVarGet("tempH")));
	trQuestVarSet("tempCosH", xsCos(trQuestVarGet("tempH")));
	trQuestVarSet("tempSinT", xsSin(trQuestVarGet("tempT")));
	trQuestVarSet("tempCosT", xsCos(trQuestVarGet("tempT")));
	trUnitSelectClear();
	trUnitSelectByQV("QVHero");
	trSetUnitOrientation(xsVectorSet(trQuestVarGet("tempCosH"),0,trQuestVarGet("tempSinH")),xsVectorSet(trQuestVarGet("tempSinT")*trQuestVarGet("tempSinH"),
			trQuestVarGet("tempCosT"),0.0-trQuestVarGet("tempSinT")*trQuestVarGet("tempCosH")),true);
	//EYECANDY PLANET 5
	FloatingUnitAnimIdle("Implode Sphere", x*2+60, 10, z*2+10, 0, 3,3,3);
	//FloatingUnit("Implode Sphere", x*2+60, 8, z*2+10, 0, 2,2,2);
	xAddDatabaseBlock(dPlanetEyecandy, true);
	xSetInt(dPlanetEyecandy, xPlanetEyecandyName,1*trQuestVarGet("QVRelic"));
	xSetInt(dPlanetEyecandy, xPlanetEyecandyStage, 5);
	xAddDatabaseBlock(dPlanetEyecandy, true);
	xSetInt(dPlanetEyecandy, xPlanetEyecandyName,1*trQuestVarGet("QVHero"));
	xSetInt(dPlanetEyecandy, xPlanetEyecandyStage, 5);
	FloatingUnitAnimIdle("Gaia Forest effect", x*2+60, 9, z*2+10, 0, 1,1,1);
	//FloatingUnit("Gaia Forest effect", x*2+60, 8, z*2+10, 0, 1,1,1);
	xAddDatabaseBlock(dPlanetEyecandy, true);
	xSetInt(dPlanetEyecandy, xPlanetEyecandyName,1*trQuestVarGet("QVRelic"));
	xSetInt(dPlanetEyecandy, xPlanetEyecandyStage, 5);
	xAddDatabaseBlock(dPlanetEyecandy, true);
	xSetInt(dPlanetEyecandy, xPlanetEyecandyName,1*trQuestVarGet("QVHero"));
	xSetInt(dPlanetEyecandy, xPlanetEyecandyStage, 5);
	FloatingUnitAnimIdle("Valkyrie", x*2+60, 10, z*2+10, 0, 0,0,0);
	//FloatingUnit("Gaia Forest effect", x*2+60, 8, z*2+10, 0, 1,1,1);
	xAddDatabaseBlock(dPlanetEyecandy, true);
	xSetInt(dPlanetEyecandy, xPlanetEyecandyName,1*trQuestVarGet("QVRelic"));
	xSetInt(dPlanetEyecandy, xPlanetEyecandyStage, 5);
	xAddDatabaseBlock(dPlanetEyecandy, true);
	xSetInt(dPlanetEyecandy, xPlanetEyecandyName,1*trQuestVarGet("QVHero"));
	xSetInt(dPlanetEyecandy, xPlanetEyecandyStage, 5);
	//EYECANDY PLANET 6
	FloatingUnit("Guardian Sleeping XP", x*2+72, 9, z*2+30, 0, 0,0,0);
	xAddDatabaseBlock(dPlanetEyecandy, true);
	xSetInt(dPlanetEyecandy, xPlanetEyecandyName,1*trQuestVarGet("QVRelic"));
	xSetInt(dPlanetEyecandy, xPlanetEyecandyStage, 6);
	xAddDatabaseBlock(dPlanetEyecandy, true);
	xSetInt(dPlanetEyecandy, xPlanetEyecandyName,1*trQuestVarGet("QVHero"));
	xSetInt(dPlanetEyecandy, xPlanetEyecandyStage, 6);
	FloatingUnit("Guardian Sleeping XP", x*2+72, 9, z*2+30, 0, 0,0,0);
	xAddDatabaseBlock(dPlanetEyecandy, true);
	xSetInt(dPlanetEyecandy, xPlanetEyecandyName,1*trQuestVarGet("QVRelic"));
	xSetInt(dPlanetEyecandy, xPlanetEyecandyStage, 6);
	xAddDatabaseBlock(dPlanetEyecandy, true);
	xSetInt(dPlanetEyecandy, xPlanetEyecandyName,1*trQuestVarGet("QVHero"));
	xSetInt(dPlanetEyecandy, xPlanetEyecandyStage, 6);
	FloatingUnit("Guardian Sleeping XP", x*2+72, 9, z*2+30, 0, 0,0,0);
	xAddDatabaseBlock(dPlanetEyecandy, true);
	xSetInt(dPlanetEyecandy, xPlanetEyecandyName,1*trQuestVarGet("QVRelic"));
	xSetInt(dPlanetEyecandy, xPlanetEyecandyStage, 6);
	xAddDatabaseBlock(dPlanetEyecandy, true);
	xSetInt(dPlanetEyecandy, xPlanetEyecandyName,1*trQuestVarGet("QVHero"));
	xSetInt(dPlanetEyecandy, xPlanetEyecandyStage, 6);
	FloatingUnit("Guardian Sleeping XP", x*2+72, 9, z*2+30, 0, 0,0,0);
	xAddDatabaseBlock(dPlanetEyecandy, true);
	xSetInt(dPlanetEyecandy, xPlanetEyecandyName,1*trQuestVarGet("QVRelic"));
	xSetInt(dPlanetEyecandy, xPlanetEyecandyStage, 6);
	xAddDatabaseBlock(dPlanetEyecandy, true);
	xSetInt(dPlanetEyecandy, xPlanetEyecandyName,1*trQuestVarGet("QVHero"));
	xSetInt(dPlanetEyecandy, xPlanetEyecandyStage, 6);
	//EYECANDY PLANET 8
	FloatingUnit("Ice Block", x*2+96, 9, z*2+30, 0, 4,4,4);
	xAddDatabaseBlock(dPlanetEyecandy, true);
	xSetInt(dPlanetEyecandy, xPlanetEyecandyName,1*trQuestVarGet("QVRelic"));
	xSetInt(dPlanetEyecandy, xPlanetEyecandyStage, 8);
	xAddDatabaseBlock(dPlanetEyecandy, true);
	xSetInt(dPlanetEyecandy, xPlanetEyecandyName,1*trQuestVarGet("QVHero"));
	xSetInt(dPlanetEyecandy, xPlanetEyecandyStage, 8);
	trUnitSetVariation(1*trQuestVarGet("QVRelic"), 0);
	FloatingUnit("Ice Block", x*2+96, 10, z*2+30, 0, 4,-4,4);
	xAddDatabaseBlock(dPlanetEyecandy, true);
	xSetInt(dPlanetEyecandy, xPlanetEyecandyName,1*trQuestVarGet("QVRelic"));
	xSetInt(dPlanetEyecandy, xPlanetEyecandyStage, 8);
	xAddDatabaseBlock(dPlanetEyecandy, true);
	xSetInt(dPlanetEyecandy, xPlanetEyecandyName,1*trQuestVarGet("QVHero"));
	xSetInt(dPlanetEyecandy, xPlanetEyecandyStage, 8);
	trUnitSetVariation(1*trQuestVarGet("QVRelic"), 0);
	FloatingUnit("Ice Block", x*2+96, 9, z*2+30, 0, 3,3,3);
	xAddDatabaseBlock(dPlanetEyecandy, true);
	xSetInt(dPlanetEyecandy, xPlanetEyecandyName,1*trQuestVarGet("QVRelic"));
	xSetInt(dPlanetEyecandy, xPlanetEyecandyStage, 8);
	xAddDatabaseBlock(dPlanetEyecandy, true);
	xSetInt(dPlanetEyecandy, xPlanetEyecandyName,1*trQuestVarGet("QVHero"));
	xSetInt(dPlanetEyecandy, xPlanetEyecandyStage, 8);
	trUnitSetVariation(1*trQuestVarGet("QVRelic"), 0);
	FloatingUnit("Ice Block", x*2+96, 10, z*2+30, 0, 3,-3,3);
	xAddDatabaseBlock(dPlanetEyecandy, true);
	xSetInt(dPlanetEyecandy, xPlanetEyecandyName,1*trQuestVarGet("QVRelic"));
	xSetInt(dPlanetEyecandy, xPlanetEyecandyStage, 8);
	xAddDatabaseBlock(dPlanetEyecandy, true);
	xSetInt(dPlanetEyecandy, xPlanetEyecandyName,1*trQuestVarGet("QVHero"));
	xSetInt(dPlanetEyecandy, xPlanetEyecandyStage, 8);
	trUnitSetVariation(1*trQuestVarGet("QVRelic"), 0);
	FloatingUnit("Frost Giant", x*2+96, 9, z*2+30, 0, 0,0,0);
	xAddDatabaseBlock(dPlanetEyecandy, true);
	xSetInt(dPlanetEyecandy, xPlanetEyecandyName,1*trQuestVarGet("QVRelic"));
	xSetInt(dPlanetEyecandy, xPlanetEyecandyStage, 8);
	xAddDatabaseBlock(dPlanetEyecandy, true);
	xSetInt(dPlanetEyecandy, xPlanetEyecandyName,1*trQuestVarGet("QVHero"));
	xSetInt(dPlanetEyecandy, xPlanetEyecandyStage, 8);
	//PLANET 9
	FloatingUnitAnimIdle("Hades Door", x*2+108, 9, z*2+10.5, 0, 0.05,0.05,0.1);
	xAddDatabaseBlock(dPlanetEyecandy, true);
	xSetInt(dPlanetEyecandy, xPlanetEyecandyName,1*trQuestVarGet("QVRelic"));
	xSetInt(dPlanetEyecandy, xPlanetEyecandyStage, 9);
	xAddDatabaseBlock(dPlanetEyecandy, true);
	xSetInt(dPlanetEyecandy, xPlanetEyecandyName,1*trQuestVarGet("QVHero"));
	xSetInt(dPlanetEyecandy, xPlanetEyecandyStage, 9);
	FloatingUnitAnimIdle("Hades Door", x*2+108, 9, z*2+9.5, 180, 0.05,0.05,0.1);
	xAddDatabaseBlock(dPlanetEyecandy, true);
	xSetInt(dPlanetEyecandy, xPlanetEyecandyName,1*trQuestVarGet("QVRelic"));
	xSetInt(dPlanetEyecandy, xPlanetEyecandyStage, 9);
	xAddDatabaseBlock(dPlanetEyecandy, true);
	xSetInt(dPlanetEyecandy, xPlanetEyecandyName,1*trQuestVarGet("QVHero"));
	xSetInt(dPlanetEyecandy, xPlanetEyecandyStage, 9);
	FloatingUnitAnimIdle("Titan Kronos", x*2+108, 9, z*2+10, 0, 0,0,0);
	xAddDatabaseBlock(dPlanetEyecandy, true);
	xSetInt(dPlanetEyecandy, xPlanetEyecandyName,1*trQuestVarGet("QVRelic"));
	xSetInt(dPlanetEyecandy, xPlanetEyecandyStage, 9);
	xAddDatabaseBlock(dPlanetEyecandy, true);
	xSetInt(dPlanetEyecandy, xPlanetEyecandyName,1*trQuestVarGet("QVHero"));
	xSetInt(dPlanetEyecandy, xPlanetEyecandyStage, 9);
	//NATAS
	if((Stage != 9) && (xGetInt(dPlayerData, xStageUnlocked) >= 9)){
		int a = trGetNextUnitScenarioNameNumber();
		trArmyDispatch(""+cNumberNonGaiaPlayers+",0","Dwarf",1,160,0,60,270,true);
		trUnitSelectClear();
		trUnitSelect(""+a, true);
		//Mr Natas Spaceship
		trUnitChangeProtoUnit("Phoenix");
		spyEffect(a, kbGetProtoUnitID("Sky Passage"), vector(0,0,0), vector(1,1,1));
		spyEffect(a, kbGetProtoUnitID("Fire Ship Atlantean"), vector(0,0,0), vector(2,2,2));
		spyEffect(a, kbGetProtoUnitID("Helepolis"), vector(0,0,0), vector(2,1,2));
		spyEffect(a, kbGetProtoUnitID("Migdol Stronghold"), vector(0,0,0), vector(1,-0.4,1));
		spyEffect(a, kbGetProtoUnitID("Outpost"), vector(0,0,0), vector(1,1.5,1));
		xAddDatabaseBlock(dPlanetEyecandy, true);
		xSetInt(dPlanetEyecandy, xPlanetEyecandyName,a);
		xSetInt(dPlanetEyecandy, xPlanetEyecandyStage, 10);
	}
	//END
}

rule LoadMP
inactive
highFrequency
{
	trCameraCut(vector(100.057152,219.744125,92.986107), vector(0.000006,-0.999997,0.002399), vector(0.002398,0.002398,0.999994), vector(0.999997,0.000000,-0.002398));
	xsEnableRule("LoadMP2");
	xsEnableRule("LoadMP3");
	trUIFadeToColor(0,0,0,1500,0,false);
	trOverlayText("Yeebaagooon presents", 4.0, 518, 100, 1000);
	sunColor(0,0,0);
	ambientColor(0,0,0);
	terrainAmbient(0,0,0);
	trSoundPlayDialog("default", "1", -1, false, " : ", "");
	xsDisableSelf();
}

rule LoadMP3
inactive
highFrequency
{
	if((trTime()-cActivationTime) >= 1){
		MainTitle(38,85);
		trSoundPlayDialog("default", "1", -1, false, " : ", "");
		xsDisableSelf();
		trSetLighting("Erebus", 1.0);
	}
}

rule LoadMP2
inactive
highFrequency
{
	if((trTime()-cActivationTime) >= 4){
		trLetterBox(false);
		//FEATURE - Kick inactives on planet screen
		/*
		for(p = 2; < cNumberNonGaiaPlayers){
			xSetPointer(dPlayerData, p);
			if(xGetInt(dPlayerData, xPlayerActive) == 1){
				if(kbIsPlayerHuman(p) == false){
					trPlayerKillAllUnits(p);
					trPlayerKillAllBuildings(p);
					trSetPlayerDefeated(p);
					xSetInt(dPlayerData, xPlayerActive, 0);
				}
				if(xGetInt(dPlayerData, xPlayerActive) == 1){
					if(kbIsPlayerResigned(p) == true){
						trPlayerKillAllUnits(p);
						trPlayerKillAllBuildings(p);
						trSetPlayerDefeated(p);
						xSetInt(dPlayerData, xPlayerActive, 0);
					}
				}
			}
		}*/
		trSetLighting("default", 5.0);
		PaintPlanets(20,20, 1);
		trQuestVarSet("StageSelector", trGetNextUnitScenarioNameNumber());
		UnitCreate(1, "Athena", 40, 60, 90);
		if(QuickStart == 1){
			trUnitSelectByQV("StageSelector");
			trUnitTeleport(50+10*QuickStage,3,60);
		}
		trOverlayText("Host, choose a stage", 8.0, 508, 70, 1000);
		trLetterBox(false);
		xsDisableSelf();
		xsEnableRule("choose_stage");
		trCameraCut(vector(97.212753,163.322815,-63.585068), vector(0.001486,-0.784815,0.619728), vector(0.001882,0.619730,0.784813), vector(0.999997,-0.000000,-0.002398));
		if(trCurrentPlayer() == 1){
			trCameraCut(vector(100.463554,153.803818,-59.088593), vector(0.001486,-0.784815,0.619728), vector(0.001882,0.619729,0.784813), vector(0.999997,0.000000,-0.002398));
			uiZoomToProto("Athena");
		}
		/*
		//CREATE CAMERA TRACK
		createCameraTrack(10000);
		trCameraCut(vector(100.463554,153.803818,-59.088593), vector(0.001486,-0.784815,0.619728), vector(0.001882,0.619729,0.784813), vector(0.999997,0.000000,-0.002398));
		addCameraTrackWaypoint();
		trCameraCut(vector(100.463554,103.803818,-59.088593), vector(0.001486,-0.784815,0.619728), vector(0.001882,0.619729,0.784813), vector(0.999997,0.000000,-0.002398));
		addCameraTrackWaypoint();
		trCameraCut(vector(100.463554,103.803818,-9.088593), vector(0.001486,-0.784815,0.619728), vector(0.001882,0.619729,0.784813), vector(0.999997,0.000000,-0.002398));
		addCameraTrackWaypoint();
		playCameraTrack();
		*/
	}
}

rule choose_stage
inactive
highFrequency
{
	xDatabaseNext(dObelisks);
	int n = xGetInt(dObelisks, xObeliskName);
	xUnitSelect(dObelisks,xObeliskName);
	if (trCountUnitsInArea(""+n, 1, "Athena",5) == 1){
		trQuestVarSet("Stage", xGetInt(dObelisks,xObeliskStage));
		Stage = 1*trQuestVarGet("Stage");
		//fire event build stage
		trUnitSelectClear();
		trUnitSelectByQV("StageSelector", true);
		trUnitChangeProtoUnit("Rocket");
		for(x=xGetDatabaseCount(dObelisks); >0) {
			xDatabaseNext(dObelisks);
			xUnitSelect(dObelisks,xObeliskName);
			trUnitDestroy();
		}
		aiPlanDestroy(dObelisks);
		xsDisableSelf();
		xsEnableRule("stage_chosen");
		//trForceNonCinematicModels(true);
		//trLetterBox(true);
		trUIFadeToColor(0,0,0,1000,0,true);
		playSound("ageadvance.wav");
		if(xGetInt(dObelisks,xObeliskStage) <= 9){
			trOverlayText("Planet " + xGetInt(dObelisks, xObeliskStage) + ": " + stageName(Stage), 3.0, 520, 380, 800);
		}
		else{
			trOverlayText(stageName(Stage), 3.0, 520, 380, 800);
		}
	} else if (trUnitIsSelected()) {
		uiClearSelection();
		xSetPointer(dPlayerData, trCurrentPlayer());
		if(xGetInt(dPlayerData, xStageUnlocked) >= xGetInt(dObelisks, xObeliskStage)-1){
			if(xGetInt(dObelisks,xObeliskStage) <= 9){
				trShowImageDialog(stageIcon(xGetInt(dObelisks, xObeliskStage)), "Planet " + xGetInt(dObelisks, xObeliskStage) + ": " + stageName(xGetInt(dObelisks, xObeliskStage)));
			}
			if(xGetInt(dObelisks,xObeliskStage) == 10){
				trShowImageDialog(stageIcon(xGetInt(dObelisks, xObeliskStage)), stageName(xGetInt(dObelisks, xObeliskStage)));
			}
		}
		else{
			trShowImageDialog(stageIcon(xGetInt(dObelisks, xObeliskStage)), "LOCKED");
		}
	}
}

rule stage_chosen
inactive
highFrequency
{
	if((trTime()-cActivationTime) >= 1){
		xsDisableSelf();
		for(x=xGetDatabaseCount(dPlanetEyecandy); >0) {
			xDatabaseNext(dPlanetEyecandy);
			xUnitSelect(dPlanetEyecandy,xPlanetEyecandyName);
			trUnitDestroy();
			xsEnableRule("BasicVC1");
			xsEnableRule("BasicVC2");
		}
		aiPlanDestroy(dPlanetEyecandy);
		/*int limit = trGetNextUnitScenarioNameNumber()-1;
		for(x = cNumberNonGaiaPlayers+1; < limit){
			trUnitSelectClear();
			trUnitSelect("+x+");
			trUnitDestroy();
		}*/
		xsEnableRule("lure");
		xsEnableRule("DeployPlayers");
		xsEnableRule("squarespaint");
		trUnitSelectClear();
		trUnitSelect("0");
		trUnitChangeInArea(0, 0, "Outpost", "Rocket", 999.0);
	}
}

/*RULES DISABLED IN THE RAIN DOC THAT STARTS GAMES
rule TEMPdeployP1
rule squarespaint
rule lure
xsEnableRule("lure");
xsEnableRule("TEMPdeployP1");
xsEnableRule("squarespaint");
*/

/*void saveAllDataOLD() {
	xsSetContextPlayer(0);
	int p = trCurrentPlayer();
	if (p != cNumberNonGaiaPlayers) {
		xSetPointer(dPlayerData, p);
		//DATA SAVE SP
		//SLOT 0, STAGE
		int savedatasp = 0;
		savedatasp = xsMax(1*trQuestVarGet("p"+p+"stage"), Stage);
		trSetCurrentScenarioUserData(0, savedatasp);
		//trChatSend(0, ""+savedatasp + " saved as stage");
		//SLOT 1, GOLD
		savedatasp = 0;
		savedatasp = trPlayerResourceCount(p, "Gold");
		trSetCurrentScenarioUserData(1, savedatasp);
		//trChatSend(0, ""+savedatasp + " saved as gold");
		//SLOT 2, DRILL LEVEL
		savedatasp = 1*xGetInt(dPlayerData, xDrillLevel);
		trSetCurrentScenarioUserData(2, savedatasp); //drill level save
		//trChatSend(0, ""+savedatasp + " saved as drill level");
		//SLOT 3, HULL LEVEL
		savedatasp = 1*xGetInt(dPlayerData, xHullLevel);
		trSetCurrentScenarioUserData(3, savedatasp); //drill level save
		//trChatSend(0, ""+savedatasp + " saved as hull level");
		//SLOT 4, HULL LEVEL
		savedatasp = 1*xGetInt(dPlayerData, xFuelLevel);
		trSetCurrentScenarioUserData(4, savedatasp); //drill level save
		//trChatSend(0, ""+savedatasp + " saved as fuel level");
		//SLOT 5, CARGO LEVEL
		savedatasp = 1*xGetInt(dPlayerData, xCargoLevel);
		trSetCurrentScenarioUserData(5, savedatasp); //drill level save
		//trChatSend(0, ""+savedatasp + " saved as cargo level");
		//SLOT 6, ENGINE LEVEL
		savedatasp = 1*xGetInt(dPlayerData, xEngineLevel);
		trSetCurrentScenarioUserData(6, savedatasp); //drill level save
		//trChatSend(0, ""+savedatasp + " saved as engine level");
		//SLOT 7, RADIATOR LEVEL
		savedatasp = 1*xGetInt(dPlayerData, xRadiatorLevel);
		trSetCurrentScenarioUserData(7, savedatasp); //drill level save
		//trChatSend(0, ""+savedatasp + " saved as rad level");
	}
}*/
