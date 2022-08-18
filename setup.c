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
const int TOTAL_LOAD = 13;

void showLoadProgress() {
	trSoundPlayFN("default","1",-1,"Loading Data:"+100 * loadProgress / TOTAL_LOAD,"icons\god power reverse time icons 64");
}


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
	
	//SWRODSMEN DEPLOY
	int DeployXX = 20;
	if(aiIsMultiplayer() == false){
		if(OverrideSP == false){
			trDelayedRuleActivation("load1");
		}
		else if(OverrideSP == true){
			for(p=1; < cNumberNonGaiaPlayers) {
				trModifyProtounit("Swordsman Hero", p, 6, -100);
				trModifyProtounit("Swordsman Hero", p, 16, 9999999999999999999.0);
				trModifyProtounit("Swordsman Hero", p, 17, 9999999999999999999.0);
				trModifyProtounit("Swordsman Hero", p, 18, 9999999999999999999.0);
				trModifyProtounit("Swordsman Hero", p, 19, 9999999999999999999.0);
				trModifyProtounit("Swordsman Hero", p, 16, -9999999999999999999.0);
				trModifyProtounit("Swordsman Hero", p, 17, -9999999999999999999.0);
				trModifyProtounit("Swordsman Hero", p, 18, -9999999999999999999.0);
				trModifyProtounit("Swordsman Hero", p, 19, -9999999999999999999.0);
				trArmyDispatch(""+p+",0","Swordsman", 10, DeployXX,0,10,0,true);
				DeployXX = DeployXX + 20;
			}
			xsEnableRule("data_load_01_ready");
		}
	}
	else if(aiIsMultiplayer() == true){
		for(p=1; < cNumberNonGaiaPlayers) {
			trModifyProtounit("Swordsman Hero", p, 6, -100);
			trModifyProtounit("Swordsman Hero", p, 16, 9999999999999999999.0);
			trModifyProtounit("Swordsman Hero", p, 17, 9999999999999999999.0);
			trModifyProtounit("Swordsman Hero", p, 18, 9999999999999999999.0);
			trModifyProtounit("Swordsman Hero", p, 19, 9999999999999999999.0);
			trModifyProtounit("Swordsman Hero", p, 16, -9999999999999999999.0);
			trModifyProtounit("Swordsman Hero", p, 17, -9999999999999999999.0);
			trModifyProtounit("Swordsman Hero", p, 18, -9999999999999999999.0);
			trModifyProtounit("Swordsman Hero", p, 19, -9999999999999999999.0);
			trArmyDispatch(""+p+",0","Swordsman", 10, DeployXX,0,10,0,true);
			DeployXX = DeployXX + 20;
		}
		xsEnableRule("data_load_01_ready");
	}
	
	
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
	characterDialog("Initialising map", " ", "icons\special e son of osiris icon 64");
	xsDisableSelf();
}

rule data_load_01_ready
highFrequency
inactive
{
	int swordsmen = 0;
	int total = 10 * (cNumberNonGaiaPlayers - 1);
	for(p=1; < cNumberNonGaiaPlayers) {
		swordsmen = swordsmen + trPlayerUnitCountSpecific(p, "Swordsman");
	}
	if (swordsmen == total) {
		savedata = trGetScenarioUserData(0);
		if (savedata < 0) {
			savedata = 0;
		}
		currentdata = iModulo(10, savedata);
		savedata = savedata / 10;
		
		xsEnableRule("data_load_01_load_data");
		xsEnableRule("data_load_02_detect_data");
		//	xsEnableRule("data_load_emergency_exit");
		xsDisableSelf();
	}
}

/*
ASYNC
*/
rule data_load_01_load_data
highFrequency
inactive
{
	trLetterBox(false);
	trBlockAllSounds(true);
	if (currentdata >= 10) {
		trSoundPlayFN("cantdothat.wav","1",-1,"Invalid code at " + loadProgress + "!","");
	}
	trUnitSelectClear();
	trUnitSelectByID(currentdata + 10 * (trCurrentPlayer() - 1));
	for(i=10; >0) {
		if (trUnitIsSelected() == false) {
			uiFindType("Swordsman");
		} else {
			break;
		}
	}
	uiTransformSelectedUnit("Swordsman Hero");
	trForceNonCinematicModels(true);
	
	//trLetterBox(true);
	
	showLoadProgress();
	xsDisableSelf();
}

/*
SYNC
*/
rule data_load_02_detect_data
highFrequency
inactive
{
	int swordsmen = 0;
	for(p=1; < cNumberNonGaiaPlayers) {
		swordsmen = swordsmen + trPlayerUnitCountSpecific(p, "Swordsman Hero");
	}
	if (swordsmen == cNumberNonGaiaPlayers - 1) { //why was this 2
		for(p=1; < cNumberNonGaiaPlayers) {
			if (xSetPointer(dPlayerData, p) == false) {
				debugLog("Cannot set pointer for " + aiPlanGetName(dPlayerData) + " to: " + p);
				//debugLog("database size is " + aiPlanGetNumberUserVariableValues(dPlayerData,xDirtyBit));
				debugLog("Progress: " + loadProgress + " context: " + xsGetContextPlayer());
			}
			swordsmen = 10 * (p - 1);
			// Check which swordsman is a hero and use his ID to figure out the number
			for(x=0; < 10) {
				if (kbGetUnitBaseTypeID(x + swordsmen) == kbGetProtoUnitID("Swordsman Hero")) {
					/* read the data */
					if (loadProgress == 0) {
						trQuestVarSet("p"+p+"stage", x);
						if(OverrideStage == true){
							trQuestVarSet("p1stage", 9);
						}
					} else if (loadProgress < 7) {
						// Gold
						trQuestVarSet("p"+p+"goldGrant", trQuestVarGet("p"+p+"goldGrant") + x * xsPow(10, loadProgress - 1));
					} else if (loadProgress == 7) {
						xSetInt(dPlayerData, xDrillLevel, 1*xsMax(1, x));
						xSetFloat(dPlayerData, xDrillPower, 1*trQuestVarGet("DrillPowerL"+xGetInt(dPlayerData, xDrillLevel)+""));
					} else if (loadProgress == 8) {
						xSetInt(dPlayerData, xHullLevel, 1*xsMax(1, x));
						xSetInt(dPlayerData, xHullHP, 1*trQuestVarGet("HullHPL"+xGetInt(dPlayerData, xHullLevel)+""));
					} else if (loadProgress == 9) {
						xSetInt(dPlayerData, xFuelLevel, 1*xsMax(1, x));
						xSetInt(dPlayerData, xFuelTank, 1*trQuestVarGet("FuelCL"+xGetInt(dPlayerData, xFuelLevel)+""));
					} else if (loadProgress == 10) {
						xSetInt(dPlayerData, xCargoLevel, 1*xsMax(1, x));
						xSetInt(dPlayerData, xCargoHold, 1*trQuestVarGet("CargoCL"+xGetInt(dPlayerData, xCargoLevel)+""));
					} else if (loadProgress == 11) {
						xSetInt(dPlayerData, xEngineLevel, 1*xsMax(1, x));
						xSetInt(dPlayerData, xEnginePower, 1*trQuestVarGet("EngineCL"+xGetInt(dPlayerData, xEngineLevel)+""));
					} else if (loadProgress == 12) {
						xSetInt(dPlayerData, xRadiatorLevel, 1*xsMax(1, x));
						xSetInt(dPlayerData, xRadiator, 1*trQuestVarGet("RadiatorCL"+xGetInt(dPlayerData, xRadiatorLevel)+""));
					}
					if (p  == 1) {
						//debugLog("digit is " + x);
					}
					
					trUnitSelectClear();
					trUnitSelectByID(x + swordsmen);
					trMutateSelected(kbGetProtoUnitID("Swordsman"));
					break;
				}
			}
		}
		
		
		loadProgress = loadProgress + 1;
		showLoadProgress();
		
		
		if (loadProgress == TOTAL_LOAD) {
			xsDisableSelf();
			xsEnableRule("data_load_03_done");
		} else {
			/* prepare the next data */
			xsEnableRule("data_load_01_load_data");
			switch(loadProgress)
			{
				case 1: // done reading slot 0.
				{
					savedata = trGetScenarioUserData(1);
				}
				case 7: // done reading slot 1.
				{
					savedata = trGetScenarioUserData(2);
				}
				case 8: // done reading slot 2.
				{
					savedata = trGetScenarioUserData(3);
				}
				case 9: // done reading slot 3.
				{
					savedata = trGetScenarioUserData(4);
				}
				case 10: // done reading slot 4.
				{
					savedata = trGetScenarioUserData(5);
				}
				case 11: // done reading slot 5.
				{
					savedata = trGetScenarioUserData(6);
				}
				case 12: // done reading slot 6.
				{
					savedata = trGetScenarioUserData(7);
				}
			}
			if (savedata < 0) {
				savedata = 0;
			}
			
			currentdata = iModulo(10, savedata);
			savedata = savedata / 10;
		}
	}
}


rule data_load_03_done
highFrequency
inactive
{
	/*
	Destroy swordsmen
	*/
	for(x=0; < trQuestVarGet("temp")) {
		trUnitSelectClear();
		trUnitSelectByID(x);
		trUnitDestroy();
	}
	/*
	Deploy victory markers to avoid defeats
	modify class hold capacity
	*/
	for(p=1; < cNumberNonGaiaPlayers) {
		
		trForbidProtounit(p, "Swordsman Hero");
		trArmyDispatch(""+p+",0","Victory Marker",1,1,0,1,0,true);
		trUnblockAllSounds();
		trSoundPlayFN("favordump.wav","1",-1,"Done!","icons\god power reverse time icons 64");
		xsDisableSelf();
		xsEnableRule("load1");
		unitTransform("Swordsman", "Rocket");
		unitTransform("Swordsman Hero", "Rocket");
	}
}

rule data_load_emergency_exit
highFrequency
inactive
{
	if (trTime() > cActivationTime + 5) {
		xsDisableSelf();
		if (loadProgress == 0) {
			int x = 0;
			for(p=1; < cNumberNonGaiaPlayers) {
				x = x + trPlayerUnitCountSpecific(p, "Swordsman Hero");
			}
			if (x <= 1) {
				trSoundPlayFN("default","1",-1,
					"Zenophobia: Hmm, looks like AoM has sent everyone into singleplayer. Returning you to main menu now.",
					"icons\infantry g hoplite icon 64");
				if (trCurrentPlayer() == 1) {
					xsEnableRule("data_load_emergency_exit_01");
				} else {
					xsEnableRule("data_load_emergency_exit_02");
				}
			}
		}
	}
}

rule data_load_emergency_exit_01
highFrequency
inactive
{
	if (trTime() > cActivationTime + 5) {
		xsDisableSelf();
		xsEnableRule("data_load_emergency_exit_02");
		trSoundPlayFN("default","1",-1,
			"Zenophobia:Host, make sure all spots are filled with humans and the last player is a CPU.",
			"icons\infantry g hoplite icon 64");
	}
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
	characterDialog("Loading map.", ""+MapVersion+"", "icons\special e son of osiris icon 64");
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
	trLetterBox(false);
	//trUIFadeToColor(0,0,0,1000,1,false);
	trOverlayTextColour(255, 125, 0);
	gadgetUnreal("ShowImageBox");
	trOverlayText(MapName, 8.0, 579, 35, 1000);
	trSetUnitIdleProcessing(true);
	xsDisableSelf();
	if(aiIsMultiplayer() == false){
		if(OverrideSP == false){
			trDelayedRuleActivation("LoadSP");
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
}

void PaintPlanets(int x = 0, int z = 0, int offsetearth = 0){
	PaintAtlantisArea(x,z,x+60,z+20,"black");
	trPaintTerrain(x+1,z+10,x+59,z+10, 0, 50, false);
	for(p = 1; <= 9){
		int next = trGetNextUnitScenarioNameNumber();
		int offset = 0;
		if (iModulo(2, p) == 0) { //if is divisble by 2
			offset = 20;
		}
		if(1*trQuestVarGet("p1stage") > xGetInt(dObelisks, xObeliskStage)-1){
			UnitCreate(0, "Outpost", x*2+12*p, z*2+10+offset, 90);
		}
		else{
			UnitCreate(0, "Victory Marker", x*2+12*p, z*2+10+offset, 90);
		}
		xAddDatabaseBlock(dObelisks, true);
		xSetInt(dObelisks, xObeliskName,next);
		xSetInt(dObelisks, xObeliskStage, p);
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
	if(offsetearth == 0){
		FloatingUnitAnimIdle("Earth", x*2+48, 9, z*2+29, 0, 0.2,0.2,0.2);
	}
	if(offsetearth == 1){
		FloatingUnitAnimIdle("Earth", x*2+28, 9, z*2+18, 0, 0.2,0.2,0.2);
	}
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
	//END
}

rule LoadMP
inactive
highFrequency
{
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
	PaintPlanets(20,20, 1);
	trQuestVarSet("StageSelector", trGetNextUnitScenarioNameNumber());
	UnitCreate(1, "Athena", 40, 60, 90);
	if(QuickStart == 1){
		trUnitSelectByQV("StageSelector");
		trUnitMoveToPoint(52,3,50,-1,false);
	}
	trCameraCut(vector(100.463554,153.803818,-59.088593), vector(0.001486,-0.784815,0.619728), vector(0.001882,0.619729,0.784813), vector(0.999997,0.000000,-0.002398));
	trOverlayText("Host, choose a stage", 8.0, 508, 70, 1000);
	trLetterBox(false);
	trUIFadeToColor(0,0,0,1500,0,false);
	xsDisableSelf();
	xsEnableRule("choose_stage");
	uiZoomToProto("Athena");
}

rule choose_stage
inactive
highFrequency
{
	xDatabaseNext(dObelisks);
	int n = xGetInt(dObelisks, xObeliskName);
	xUnitSelect(dObelisks,xObeliskName);
	if (trCountUnitsInArea(""+n, 1, "Athena",5) == 1){
		//and is an obleisk
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
		trSoundPlayFN("ageadvance.wav","1",-1,"","");
		trOverlayText("Planet " + xGetInt(dObelisks, xObeliskStage) + ": " + stageName(Stage), 3.0, 520, 380, 800);
	} else if (trUnitIsSelected()) {
		uiClearSelection();
		if (xGetInt(dObelisks, xObeliskStage) > 0 && xGetInt(dObelisks, xObeliskStage) <= 10) {
			int p = trCurrentPlayer();
			if(1*trQuestVarGet("p"+p+"stage") >= xGetInt(dObelisks, xObeliskStage)-1){
				trShowImageDialog(stageIcon(xGetInt(dObelisks, xObeliskStage)), "Planet " + xGetInt(dObelisks, xObeliskStage) + ": " + stageName(xGetInt(dObelisks, xObeliskStage)));
			}
			else{
				trShowImageDialog(stageIcon(xGetInt(dObelisks, xObeliskStage)), "LOCKED");
			}
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

void saveAllData() {
	xsSetContextPlayer(0);
	int p = trCurrentPlayer();
	if (p != cNumberNonGaiaPlayers) {
		xSetPointer(dPlayerData, p);
		//DATA SAVE SP
		//SLOT 0, STAGE
		int savedatasp = 0;
		savedatasp = xsMax(1*trQuestVarGet("p"+p+"stage"), Stage);
		trSetCurrentScenarioUserData(0, savedatasp);
		trChatSend(0, ""+savedatasp + " saved as stage");
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
}
