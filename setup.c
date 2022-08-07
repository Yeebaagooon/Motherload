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
	/*
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
		int posX = 20;
		trArmyDispatch(""+p+",0","Swordsman", 10, posX,0,10,0,true);
		posX = posX + 10;
	}
	*/
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
	xsEnableRule("load1");
	xsDisableSelf();
}


rule load1
inactive
highFrequency
{
	characterDialog("Loading map.", ""+MapVersion+"", "icons\special e son of osiris icon 64");
	xsEnableRule("load2");
	xsEnableRule("Stats");
	trBlockAllSounds(false);
	xsDisableSelf();
	modifyProtounitAbsolute("Vision Revealer", 0, 2, 2400);
	trArmyDispatch("0,0", "Vision Revealer", 1, 0, 0, 0, 0, false);
	trArmyDispatch("0,0", "Cinematic Block", 1, 0, 0, 0, 0, false);
	for(p = 1; <= cNumberNonGaiaPlayers){
		deployLocHeading(0, p*2, "Victory Marker", p, 180);
	}
}

rule load2
inactive
highFrequency
{
	characterDialog("Loading map..", ""+MapVersion+"", "icons\special e son of osiris icon 64");
	xsEnableRule("load3");
	trSoundPlayFN("Yeebaagooon\Motherload\test sound.mp3", "1", 13, "", "");
	xsDisableSelf();
}

rule load3
inactive
highFrequency
{
	if((trTime()-cActivationTime) >= 1){
		characterDialog("Loading map...", ""+MapVersion+"", "icons\special e son of osiris icon 64");
		for(p = 1; <= cNumberNonGaiaPlayers){
			trPlayerGrantResources(p, "Food", -10000.0);
			trPlayerGrantResources(p, "Wood", -10000.0);
			trPlayerGrantResources(p, "Gold", -10000.0);
			trPlayerGrantResources(p, "Favor", -10000.0);
			trPlayerKillAllGodPowers(p);
		}
		xsDisableSelf();
		xsEnableRule("load4");
	}
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
	PaintAtlantisArea(20,20,80,40,"black");
	trPaintTerrain(21,30,79,30, 0, 50, false);
	trQuestVarSet("StageSelector", trGetNextUnitScenarioNameNumber());
	UnitCreate(1, "Athena", 40, 60, 90);
	if(QuickStart == 1){
		trUnitSelectByQV("StageSelector");
		trUnitMoveToPoint(52,3,50,-1,false);
	}
	trCameraCut(vector(100.463554,153.803818,-59.088593), vector(0.001486,-0.784815,0.619728), vector(0.001882,0.619729,0.784813), vector(0.999997,0.000000,-0.002398));
	trOverlayText("Host, choose a stage", 8.0, 508, 70, 1000);
	for(p = 1; <= 9){
		int next = trGetNextUnitScenarioNameNumber();
		int x = 0;
		if (iModulo(2, p) == 0) { //if is divisble by 2
			x = 20;
		}
		UnitCreate(0, "Outpost", 40+12*p, 50+x, 90);
		xAddDatabaseBlock(dObelisks, true);
		xSetInt(dObelisks, xObeliskName,next);
		xSetInt(dObelisks, xObeliskStage, p);
	}
	
	//EYECANDY PLANET 1
	FloatingUnit("Rock Granite Big", 52, 8, 50, 0, 2,2,2);
	xAddDatabaseBlock(dPlanetEyecandy, true);
	xSetInt(dPlanetEyecandy, xPlanetEyecandyName,1*trQuestVarGet("QVRelic"));
	xSetInt(dPlanetEyecandy, xPlanetEyecandyStage, 1);
	xAddDatabaseBlock(dPlanetEyecandy, true);
	xSetInt(dPlanetEyecandy, xPlanetEyecandyName,1*trQuestVarGet("QVHero"));
	xSetInt(dPlanetEyecandy, xPlanetEyecandyStage, 1);
	FloatingUnit("Fire Hades", 51, 8, 50, 0, 2,2,2);
	xSetInt(dPlanetEyecandy, xPlanetEyecandyName,1*trQuestVarGet("QVRelic"));
	xSetInt(dPlanetEyecandy, xPlanetEyecandyStage, 1);
	xAddDatabaseBlock(dPlanetEyecandy, true);
	xSetInt(dPlanetEyecandy, xPlanetEyecandyName,1*trQuestVarGet("QVHero"));
	xSetInt(dPlanetEyecandy, xPlanetEyecandyStage, 1);
	FloatingUnit("Ice Block", 53, 8, 50, 0, 2,2,2);
	xSetInt(dPlanetEyecandy, xPlanetEyecandyName,1*trQuestVarGet("QVRelic"));
	xSetInt(dPlanetEyecandy, xPlanetEyecandyStage, 1);
	xAddDatabaseBlock(dPlanetEyecandy, true);
	xSetInt(dPlanetEyecandy, xPlanetEyecandyName,1*trQuestVarGet("QVHero"));
	xSetInt(dPlanetEyecandy, xPlanetEyecandyStage, 1);
	//EYECANDY PLANET 2
	FloatingUnit("Rock Sandstone Big", 64, 8, 70, 0, 2,2,2);
	xAddDatabaseBlock(dPlanetEyecandy, true);
	xSetInt(dPlanetEyecandy, xPlanetEyecandyName,1*trQuestVarGet("QVRelic"));
	xSetInt(dPlanetEyecandy, xPlanetEyecandyStage, 2);
	xAddDatabaseBlock(dPlanetEyecandy, true);
	xSetInt(dPlanetEyecandy, xPlanetEyecandyName,1*trQuestVarGet("QVHero"));
	xSetInt(dPlanetEyecandy, xPlanetEyecandyStage, 2);
	//EYECANDY PLANET 3
	FloatingUnitAnimIdle("Earth", 76, 9, 48, 0, 0.2,0.2,0.2);
	xAddDatabaseBlock(dPlanetEyecandy, true);
	xSetInt(dPlanetEyecandy, xPlanetEyecandyName,1*trQuestVarGet("QVRelic"));
	xSetInt(dPlanetEyecandy, xPlanetEyecandyStage, 3);
	xAddDatabaseBlock(dPlanetEyecandy, true);
	xSetInt(dPlanetEyecandy, xPlanetEyecandyName,1*trQuestVarGet("QVHero"));
	xSetInt(dPlanetEyecandy, xPlanetEyecandyStage, 3);
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
	xsDisableSelf();
	xsEnableRule("choose_stage");
}

rule choose_stage
inactive
highFrequency
{
	xDatabaseNext(dObelisks);
	int n = xGetInt(dObelisks, xObeliskName);
	xUnitSelect(dObelisks,xObeliskName);
	if (trCountUnitsInArea(""+n, 1, "Athena",5) == 1) {
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
		trSoundPlayFN("ui\thunder2.wav","1",-1,"","");
		trOverlayText("Planet " + xGetInt(dObelisks, xObeliskStage) + ": " + stageName(Stage), 3.0, 520, 380, 800);
	} else if (trUnitIsSelected()) {
		uiClearSelection();
		if (xGetInt(dObelisks, xObeliskStage) > 0 && xGetInt(dObelisks, xObeliskStage) <= 10) {
			trShowImageDialog(stageIcon(xGetInt(dObelisks, xObeliskStage)), "Planet " + xGetInt(dObelisks, xObeliskStage) + ": " + stageName(xGetInt(dObelisks, xObeliskStage)));
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

