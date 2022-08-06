rule Initialise
active
highFrequency
runImmediately
{
	characterDialog("Waiting for everyone to connect.", " ", "icons\special e son of osiris icon 64");
	trUIFadeToColor(0, 0, 0, 0, 10000, false);
	trFadeOutAllSounds(0.1);
	trFadeOutMusic(0.1);
	if(QuickStart == 0){
	}
	trBlockAllSounds(true);
	trArmyDispatch("0,0", "Cinematic Block", 1, 0, 0, 0, 0, false);
	for(p = 1; <= cNumberNonGaiaPlayers){
		deployLocHeading(0, p*2, "Victory Marker", p, 180);
	}
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
		modifyProtounitAbsolute("Vision Revealer", p, 2, 24);
		modifyProtounitAbsolute("Vision Revealer", p, 8, 999999);
	}
	//start fade to black
	//trUIFadeToColor(1,0,0,0,0,true);
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
	if((trTime()-cActivationTime) >= 1){
		//fade out when loaded
		trUnblockAllSounds();
		trLetterBox(false);
		trUIFadeToColor(0,0,0,1000,1,false);
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
				trDelayedRuleActivation("PaintStageSelect");
			}
		}
		else if(aiIsMultiplayer() == true){
			trDelayedRuleActivation("PaintStageSelect");
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
	}
}

rule LoadSP
inactive
highFrequency
{
	trSetFogAndBlackmap(false, false);
	xsDisableSelf();
	xsEnableRule("SPCineChoice");
	PaintAtlantisArea(0,0,68,31,"NorseRoadA");
	PaintAtlantisArea(32,12,36,16,"BlackRock"); // main sq
	PaintAtlantisArea(32,23,36,27,"black"); // boon sq
	PaintAtlantisArea(32,1,36,5,"black"); // exit sq
	UnitCreate(0, "Fire Siphon", 68, 28, 180); //main siphon
	UnitCreate(1, "Pharaoh of Osiris XP", 68, 20, 180); //Player Unit
	UnitCreate(1, "Tunnel", 68, 7, 180); //exit unit
	UnitCreate(0, "Outpost", 68, 51, 180); //boon unit
	//TERRAIN initial 6 legs
	//LEFT LEGS
	trPaintTerrain(34,7,34,10,0,74,false); //vertical strip main to exit
	trPaintTerrain(34,11,34,11,0,76,false); //cap+
	trPaintTerrain(34,6,34,6,0,78,false); //cap-
	trPaintTerrain(34,18,34,21,0,74,false); //vertical strip main to boon
	trPaintTerrain(34,22,34,22,0,76,false); //cap+
	trPaintTerrain(34,17,34,17,0,78,false); //cap-
	trPaintTerrain(31,13,31,15,0,77,false);  //L frills
	//trPaintTerrain(30,13,30,15,0,75,false);  //L frillcaps
	trPaintTerrain(37,13,37,15,0,79,false);  //R frills
	
	trPaintTerrain(26,14,30,14,0,75,false);  //LMid hullroute
	trPaintTerrain(25,14,25,14,0,79,false);  //LMid hullroute cap
	PaintAtlantisArea(22,13,24,15,"black"); // hull square
	//drill terrain
	trPaintTerrain(30,15,30,15,0,82,false);  //drillcorner1
	trPaintTerrain(30,16,30,18,0,74,false);  //drilltrail
	trPaintTerrain(30,19,30,19,0,80,false);  //drillcorner2
	trPaintTerrain(26,19,29,19,0,75,false);  //LTop drillroute
	trPaintTerrain(25,19,25,19,0,79,false);  //LTop drillroute cap
	PaintAtlantisArea(22,18,24,20, "black"); // drill square
	//fuelterrain
	trPaintTerrain(30,13,30,13,0,83,false);  //fuelcorner1
	trPaintTerrain(30,10,30,12,0,74,false);  //fueltrail
	trPaintTerrain(30,9,30,9,0,81,false);  //fuelcorner2
	trPaintTerrain(26,9,29,9,0,75,false);  //LBot fuelroute
	trPaintTerrain(25,9,25,9,0,79,false);  //LBot fuelroute cap
	PaintAtlantisArea(22,8,24,10, "black"); // fuel square
	
	//RIGHT LEGS
	//engine mid
	trPaintTerrain(38,14,42,14,0,75,false);  //RMid engineroute
	trPaintTerrain(43,14,43,14,0,77,false);  //RMid engineroute cap
	PaintAtlantisArea(44,13,46,15,"black"); // engine square
	
	//cargo terrain
	trPaintTerrain(38,15,38,15,0,81,false);  //fuelcorner1
	trPaintTerrain(38,16,38,18,0,74,false);  //fueltrail
	trPaintTerrain(38,19,38,19,0,83,false);  //fuelcorner2
	trPaintTerrain(39,19,42,19,0,75,false);  //RTop drillroute
	trPaintTerrain(43,19,43,19,0,77,false);  //RTop fuelroute cap
	PaintAtlantisArea(44,18,46,20, "black"); // fuel square
	
	//radiatorterrain
	trPaintTerrain(38,13,38,13,0,80,false);  //radcorner1
	trPaintTerrain(38,10,38,12,0,74,false);  //radtrail
	trPaintTerrain(38,9,38,9,0,82,false);  //radcorner2
	trPaintTerrain(39,9,42,9,0,75,false);  //RBot radroute
	trPaintTerrain(43,9,43,9,0,77,false);  //RBot radroute cap
	PaintAtlantisArea(44,8,46,10, "black"); // rad square
	
	//UNITS for the 6 boxes and flags
	int UnitBox1 = trGetNextUnitScenarioNameNumber();
	UnitCreate(0, "Victory Marker", 46, 38, 90); //drill unit
	trUnitSelectClear();
	trUnitSelect(""+UnitBox1);
	trUnitChangeProtoUnit("Ramming Ship Greek");
	int UnitFlag1 = trGetNextUnitScenarioNameNumber();
	UnitCreate(0, "Victory Marker", 46, 41, 180); //drill flag
	trUnitSelectClear();
	trUnitSelect(""+UnitFlag1);
	trUnitChangeProtoUnit("Flag Numbered");
	trUnitSetVariation(UnitFlag1,0);
	trUnitSelect(""+UnitFlag1);
	trSetSelectedScale(2,2,2);
	
	int UnitBox2 = trGetNextUnitScenarioNameNumber();
	UnitCreate(0, "Wall Connector", 46, 28, 180); //hull unit
	int UnitFlag2 = trGetNextUnitScenarioNameNumber();
	UnitCreate(0, "Victory Marker", 46, 31, 180); //hull flag
	trUnitSelectClear();
	trUnitSelect(""+UnitFlag2);
	trUnitChangeProtoUnit("Flag Numbered");
	trUnitSetVariation(UnitFlag2,0);
	trUnitSelect(""+UnitFlag2);
	trSetSelectedScale(2,2,2);
	
	int UnitFlag3 = trGetNextUnitScenarioNameNumber();
	UnitCreate(0, "Victory Marker", 46, 21, 180); //fuel tank flag
	int UnitBox3 = trGetNextUnitScenarioNameNumber();
	UnitCreate(0, "Victory Marker", 46, 18, 180); //fuel tank unit
	trUnitSelectClear();
	trUnitSelect(""+UnitBox3);
	trUnitChangeProtoUnit("Well of Urd");
	trUnitSelectClear();
	trUnitSelect(""+UnitBox3);
	trSetSelectedScale(0.4,0.4,0.4);
	trUnitSelectClear();
	trUnitSelect(""+UnitFlag3);
	trUnitChangeProtoUnit("Flag Numbered");
	trUnitSetVariation(UnitFlag3,0);
	trUnitSelect(""+UnitFlag3);
	trSetSelectedScale(2,2,2);
	
	int UnitFlag4 = trGetNextUnitScenarioNameNumber();
	UnitCreate(0, "Victory Marker", 90,41,180); //cargo hold flag
	int UnitBox4 = trGetNextUnitScenarioNameNumber();
	UnitCreate(0, "Victory Marker", 90,38,180); //cargo hold unit
	trUnitSelectClear();
	trUnitSelect(""+UnitBox4);
	trUnitChangeProtoUnit("Sky Passage");
	trUnitSelectClear();
	trUnitSelect(""+UnitBox4);
	trSetSelectedScale(0.5,0.5,0.5);
	trUnitSelectClear();
	trUnitSelect(""+UnitFlag4);
	trUnitChangeProtoUnit("Flag Numbered");
	trUnitSetVariation(UnitFlag4,0);
	trUnitSelect(""+UnitFlag4);
	trSetSelectedScale(2,2,2);
	
	int UnitFlag5 = trGetNextUnitScenarioNameNumber();
	UnitCreate(0, "Victory Marker", 90,31,180); //fuel tank flag
	int UnitBox5 = trGetNextUnitScenarioNameNumber();
	UnitCreate(0, "Victory Marker", 90,28,180); //fuel tank unit
	trUnitSelectClear();
	trUnitSelect(""+UnitBox5);
	trUnitChangeProtoUnit("Dwarven Forge");
	trUnitSetVariation(UnitBox5,1);
	trUnitSelectClear();
	trUnitSelect(""+UnitBox5);
	trSetSelectedScale(0.6,0.6,0.6);
	trUnitSelectClear();
	trUnitSelect(""+UnitFlag5);
	trUnitChangeProtoUnit("Flag Numbered");
	trUnitSetVariation(UnitFlag5,0);
	trUnitSelect(""+UnitFlag5);
	trSetSelectedScale(2,2,2);
	
	int UnitFlag6 = trGetNextUnitScenarioNameNumber();
	UnitCreate(0, "Victory Marker", 90,21,180); //rad flag
	int UnitBox6 = trGetNextUnitScenarioNameNumber();
	UnitCreate(0, "Dwarf", 90,18,180); //rad unit
	int RadEC1 = trGetNextUnitScenarioNameNumber();
	UnitCreate(0, "Victory Marker", 88,18,90); //rad ec object
	int RadEC2 = trGetNextUnitScenarioNameNumber();
	UnitCreate(0, "Victory Marker", 90,18,90); //rad ec object
	int RadEC3 = trGetNextUnitScenarioNameNumber();
	UnitCreate(0, "Victory Marker", 92,18,90); //rad ec object
	trUnitSelectClear();
	trUnitSelect(""+UnitBox6);
	trUnitChangeProtoUnit("Tent");
	trUnitSetVariation(UnitBox6,1);
	trUnitSelectClear();
	trUnitSelect(""+RadEC1);
	trUnitChangeProtoUnit("Taproot Small");
	trUnitSetVariation(RadEC1,1);
	trUnitSelectClear();
	trUnitSelect(""+RadEC2);
	trUnitChangeProtoUnit("Taproot Small");
	trUnitSetVariation(RadEC2,1);
	trUnitSelectClear();
	trUnitSelect(""+RadEC3);
	trUnitChangeProtoUnit("Taproot Small");
	trUnitSetVariation(RadEC3,1);
	trUnitSelectClear();
	trUnitSelect(""+UnitFlag6);
	trUnitChangeProtoUnit("Flag Numbered");
	trUnitSetVariation(UnitFlag6,0);
	trUnitSelectClear();
	trUnitSelect(""+UnitFlag6);
	trSetSelectedScale(2,2,2);
	trUnitSelectClear();
	trUnitSelect(""+UnitBox6);
	trSetSelectedScale(1.2,1.2,1.2);
	
}

rule PaintStageSelect
inactive
highFrequency
{
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
	}
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

