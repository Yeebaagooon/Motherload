void LoadDataSP(int p = -1){
	xsSetContextPlayer(0);
	int loaddata = 0;
	loaddata = trGetScenarioUserData(1);
	trPlayerGrantResources(1, "Gold", loaddata);
}

void SaveDataSP(int p = -1){
	xsSetContextPlayer(0);
	//DATA SAVE SP
	//SLOT 1, GOLD
	int savedata = 0;
	savedata = trPlayerResourceCount(1, "Gold");
	trSetCurrentScenarioUserData(1, savedata);
	trDelayedRuleActivation("SPExit");
	trChatSend(0, ""+savedata + " saved as gold");
}

rule LoadSP
inactive
highFrequency
{
	trBlockAllSounds();
	trSetFogAndBlackmap(false, false);
	xsDisableSelf();
	//xsEnableRule("SPCineChoice");
	PaintAtlantisArea(0,0,68,31,"NorseRoadA");
	PaintAtlantisArea(32,12,36,16,"BlackRock"); // main sq
	PaintAtlantisArea(32,23,36,27,"black"); // boon sq
	PaintAtlantisArea(32,1,36,5,"black"); // exit sq
	UnitCreate(0, "Fire Siphon", 68, 28, 180); //main siphon
	UnitCreate(1, "Pharaoh of Osiris XP", 68, 20, 180); //Player Unit
	trQuestVarSet("ExitTunnel", trGetNextUnitScenarioNameNumber());
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
	
	//frills to obelisk select
	for(y=1 ; <= 3){
		trPaintTerrain(21,y*5+4,21,y*5+4,0,77,false);  //3x frill to obelisk L
		trPaintTerrain(20,y*5+4,20,y*5+4,0,75,false);
		trPaintTerrain(19,y*5+4,19,y*5+4,0,79,false);
		PaintAtlantisArea(5,y*5+3,17,y*5+5, "GrassA"); // square
		
		trPaintTerrain(47,y*5+4,47,y*5+4,0,79,false); //3x frill to obelisk R
		trPaintTerrain(48,y*5+4,48,y*5+4,0,75,false);
		trPaintTerrain(49,y*5+4,49,y*5+4,0,77,false);
		PaintAtlantisArea(51,y*5+3,63,y*5+5, "GrassA"); // square
	}
	
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
	
	int UnitObelisk1 = trGetNextUnitScenarioNameNumber();
	UnitCreate(1, "Victory Marker", 38, 38, 90);
	int UnitObelisk2 = trGetNextUnitScenarioNameNumber();
	UnitCreate(1, "Victory Marker", 38, 28, 90);
	int UnitObelisk3 = trGetNextUnitScenarioNameNumber();
	UnitCreate(1, "Victory Marker", 38, 18, 90);
	int UnitObelisk4 = trGetNextUnitScenarioNameNumber();
	UnitCreate(1, "Victory Marker", 98, 38, 90);
	int UnitObelisk5 = trGetNextUnitScenarioNameNumber();
	UnitCreate(1, "Victory Marker", 98, 28, 90);
	int UnitObelisk6 = trGetNextUnitScenarioNameNumber();
	UnitCreate(1, "Victory Marker", 98, 18, 90);
	trUnitSelectClear();
	trUnitSelect(""+UnitObelisk1);
	trUnitChangeProtoUnit("Outpost");
	trUnitSelectClear();
	trUnitSelect(""+UnitObelisk2);
	trUnitChangeProtoUnit("Outpost");
	trUnitSelectClear();
	trUnitSelect(""+UnitObelisk3);
	trUnitChangeProtoUnit("Outpost");
	trUnitSelectClear();
	trUnitSelect(""+UnitObelisk4);
	trUnitChangeProtoUnit("Outpost");
	trUnitSelectClear();
	trUnitSelect(""+UnitObelisk5);
	trUnitChangeProtoUnit("Outpost");
	trUnitSelectClear();
	trUnitSelect(""+UnitObelisk6);
	trUnitChangeProtoUnit("Outpost");
	
	//SET units selectable for info
	xAddDatabaseBlock(dSelectables, true);
	xSetInt(dSelectables, xSelectablesName, UnitBox1);
	xSetInt(dSelectables, xSelectablesPrompt, 100);
	xAddDatabaseBlock(dSelectables, true);
	xSetInt(dSelectables, xSelectablesName, UnitBox2);
	xSetInt(dSelectables, xSelectablesPrompt, 200);
	xAddDatabaseBlock(dSelectables, true);
	xSetInt(dSelectables, xSelectablesName, UnitBox3);
	xSetInt(dSelectables, xSelectablesPrompt, 300);
	xAddDatabaseBlock(dSelectables, true);
	xSetInt(dSelectables, xSelectablesName, UnitBox4);
	xSetInt(dSelectables, xSelectablesPrompt, 400);
	xAddDatabaseBlock(dSelectables, true);
	xSetInt(dSelectables, xSelectablesName, UnitBox5);
	xSetInt(dSelectables, xSelectablesPrompt, 500);
	xAddDatabaseBlock(dSelectables, true);
	xSetInt(dSelectables, xSelectablesName, UnitBox6);
	xSetInt(dSelectables, xSelectablesPrompt, 600);
	xsEnableRule("Selectables");
	xsEnableRule("SPLoops");
	
	//SET Flags names
	trQuestVarSet("UnitFlag1", UnitFlag1);
	trQuestVarSet("UnitFlag2", UnitFlag2);
	trQuestVarSet("UnitFlag3", UnitFlag3);
	trQuestVarSet("UnitFlag4", UnitFlag4);
	trQuestVarSet("UnitFlag5", UnitFlag5);
	trQuestVarSet("UnitFlag6", UnitFlag6);
	
	//SET upgrade obelisk selectable
	xAddDatabaseBlock(dSelectables, true);
	xSetInt(dSelectables, xSelectablesName, UnitObelisk1);
	xSetInt(dSelectables, xSelectablesPrompt, 101);
	
	//Loadout chat
	/*
	xSetPointer(dPlayerData, 1);
	trQuestVarSet("CurrentDrillL", xGetInt(dPlayerData, xDrillLevel));
	trChatHistoryClear();
	trChatSend(0, "<u><color=1,1,1>Current Drill:</color></u>");
	trChatSend(0, trStringQuestVarGet("DrillL"+1*trQuestVarGet("CurrentDrillL")+"") + " "+1*xGetFloat(dPlayerData, xDrillPower)+" m/s");
	*/
	trUnblockAllSounds();
	//LoadDataSP();
}

void UpgradeDrill(int p = -1){
	xsSetContextPlayer(0);
	trPlayerGrantResources(1, "Gold", -1*trQuestVarGet("goldCost"));
	xSetPointer(dPlayerData, 1);
	int DrillLevelDummy = xGetInt(dPlayerData, xDrillLevel);
	xSetInt(dPlayerData, xDrillLevel, DrillLevelDummy+1);
	xSetFloat(dPlayerData, xDrillPower, trQuestVarGet("DrillPowerL"+xGetInt(dPlayerData, xDrillLevel)+""));
	trUnitSetVariation(1*trQuestVarGet("UnitFlag1"),DrillLevelDummy);
	trQuestVarSet("CurrentDrillL", xGetInt(dPlayerData, xDrillLevel));
	trQuestVarSet("NextDrillL", 1*trQuestVarGet("CurrentDrillL")+1);
	trQuestVarSet("goldCost", 1*trQuestVarGet("DrillCostL"+1*trQuestVarGet("NextDrillL")+""));
	trSoundPlayFN("ui\thunder2.wav","1",-1,"","");
}

rule SPLoops
inactive
highFrequency
{
	trUnitSelectClear();
	trUnitSelectByQV("ExitTunnel", true);
	if (trUnitGetContained() == 1) {
		xsSetContextPlayer(0);
		xsDisableSelf();
		SaveDataSP();
	} else if (trUnitIsSelected()) {
		uiClearSelection();
		uiMessageBox("Garrison in me to save your progress!");
	}
}

rule SPExit
inactive
highFrequency
{
	if((trTime()-cActivationTime) >= 1){
		xsDisableSelf();
		trEndGame();
		trModeEnter("Pregame");
	}
}
