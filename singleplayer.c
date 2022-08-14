void LoadDataSP(int p = -1){
	xsSetContextPlayer(0);
	//SLOT 0, STAGE
	xSetPointer(dPlayerData, 1);
	int loaddatasp = 0;
	loaddatasp = trGetScenarioUserData(0);
	trQuestVarSet("p1stage", loaddatasp);
	//SLOT 1, GOLD
	xSetPointer(dPlayerData, 1);
	loaddatasp = 0;
	loaddatasp = trGetScenarioUserData(1);
	trPlayerGrantResources(1, "Gold", loaddatasp);
	loaddatasp = 0;
	//SLOT 2, DRILL LEVEL
	loaddatasp = trGetScenarioUserData(2);
	if(loaddatasp <= 0){
		loaddatasp = 1;
	}
	xSetPointer(dPlayerData, 1);
	xSetInt(dPlayerData, xDrillLevel, loaddatasp);
	//trChatSend(0, ""+loaddatasp + " SP loaded as drill level");
	trQuestVarSet("CurrentDrillL", loaddatasp);
	xSetInt(dPlayerData, xDrillLevel ,1*trQuestVarGet("CurrentDrillL"));
	xSetFloat(dPlayerData, xDrillPower ,1*trQuestVarGet("DrillPowerL"+xGetInt(dPlayerData, xDrillLevel)+""));
	
	//SLOT 3, HULL LEVEL
	loaddatasp = trGetScenarioUserData(3);
	if(loaddatasp <= 0){
		loaddatasp = 1;
	}
	xSetPointer(dPlayerData, 1);
	xSetInt(dPlayerData, xHullLevel, loaddatasp);
	//trChatSend(0, ""+loaddatasp + " SP loaded as hull level");
	trQuestVarSet("CurrentHullL", loaddatasp);
	xSetInt(dPlayerData, xHullLevel ,1*trQuestVarGet("CurrentHullL"));
	xSetInt(dPlayerData, xHullHP ,1*trQuestVarGet("HullHPL"+xGetInt(dPlayerData, xHullLevel)+""));
	
	//SLOT 4, FUEL LEVEL
	loaddatasp = trGetScenarioUserData(4);
	if(loaddatasp <= 0){
		loaddatasp = 1;
	}
	
	
	xSetPointer(dPlayerData, 1);
	xSetInt(dPlayerData, xFuelLevel, loaddatasp);
	//trChatSend(0, ""+loaddatasp + " SP loaded as fuel tank level");
	trQuestVarSet("CurrentFuelL", loaddatasp);
	xSetInt(dPlayerData, xFuelLevel ,1*trQuestVarGet("CurrentFuelL"));
	xSetInt(dPlayerData, xFuelTank ,1*trQuestVarGet("FuelCL"+xGetInt(dPlayerData, xFuelLevel)+""));
	
	//SLOT 5, Cargo LEVEL
	loaddatasp = trGetScenarioUserData(5);
	if(loaddatasp <= 0){
		loaddatasp = 1;
	}
	
	
	xSetPointer(dPlayerData, 1);
	xSetInt(dPlayerData, xCargoLevel, loaddatasp);
	//trChatSend(0, ""+loaddatasp + " SP loaded as cargo level");
	trQuestVarSet("CurrentCargoL", loaddatasp);
	xSetInt(dPlayerData, xCargoLevel ,1*trQuestVarGet("CurrentCargoL"));
	xSetInt(dPlayerData, xCargoHold ,1*trQuestVarGet("CargoCL"+xGetInt(dPlayerData, xCargoLevel)+""));
	
	//SLOT 6, Engine LEVEL
	loaddatasp = trGetScenarioUserData(6);
	if(loaddatasp <= 0){
		loaddatasp = 1;
	}
	
	
	xSetPointer(dPlayerData, 1);
	xSetInt(dPlayerData, xEngineLevel, loaddatasp);
	//trChatSend(0, ""+loaddatasp + " SP loaded as engine level");
	trQuestVarSet("CurrentEngineL", loaddatasp);
	xSetInt(dPlayerData, xEngineLevel ,1*trQuestVarGet("CurrentEngineL"));
	xSetInt(dPlayerData, xEnginePower ,1*trQuestVarGet("EngineCL"+xGetInt(dPlayerData, xEngineLevel)+""));
	
	//SLOT 7, Engine LEVEL
	loaddatasp = trGetScenarioUserData(7);
	if(loaddatasp <= 0){
		loaddatasp = 1;
	}
	
	
	xSetPointer(dPlayerData, 1);
	xSetInt(dPlayerData, xRadiatorLevel, loaddatasp);
	//trChatSend(0, ""+loaddatasp + " SP loaded as radiator level");
	trQuestVarSet("CurrentRadiatorL", loaddatasp);
	xSetInt(dPlayerData, xRadiatorLevel ,1*trQuestVarGet("CurrentRadiatorL"));
	xSetInt(dPlayerData, xRadiator ,1*trQuestVarGet("RadiatorCL"+xGetInt(dPlayerData, xRadiatorLevel)+""));
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
	xAddDatabaseBlock(dSelectables, true);
	xSetInt(dSelectables, xSelectablesName, UnitObelisk2);
	xSetInt(dSelectables, xSelectablesPrompt, 201);
	xAddDatabaseBlock(dSelectables, true);
	xSetInt(dSelectables, xSelectablesName, UnitObelisk3);
	xSetInt(dSelectables, xSelectablesPrompt, 301);
	xAddDatabaseBlock(dSelectables, true);
	xSetInt(dSelectables, xSelectablesName, UnitObelisk4);
	xSetInt(dSelectables, xSelectablesPrompt, 401);
	xAddDatabaseBlock(dSelectables, true);
	xSetInt(dSelectables, xSelectablesName, UnitObelisk5);
	xSetInt(dSelectables, xSelectablesPrompt, 501);
	xAddDatabaseBlock(dSelectables, true);
	xSetInt(dSelectables, xSelectablesName, UnitObelisk6);
	xSetInt(dSelectables, xSelectablesPrompt, 601);
	
	trUnblockAllSounds();
	LoadDataSP();
	trUnitSetVariation(UnitFlag1,1*trQuestVarGet("CurrentDrillL")-1);
	trUnitSetVariation(UnitFlag2,1*trQuestVarGet("CurrentHullL")-1);
	trUnitSetVariation(UnitFlag3,1*trQuestVarGet("CurrentFuelL")-1);
	trUnitSetVariation(UnitFlag4,1*trQuestVarGet("CurrentCargoL")-1);
	trUnitSetVariation(UnitFlag5,1*trQuestVarGet("CurrentEngineL")-1);
	trUnitSetVariation(UnitFlag6,1*trQuestVarGet("CurrentRadiatorL")-1);
	
	trLetterBox(false);
	trUIFadeToColor(0,0,0,1500,0,false);
	uiZoomToProto("Pharaoh of Osiris XP");
	uiClearSelection();
	
	PaintPlanets(8,35);
	xsEnableRule("choose_stage");
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
	trChatHistoryClear();
	trChatSend(0, "<u><color=1,1,1>Drill Upgraded:</color></u>");
	trChatSend(0, trStringQuestVarGet("DrillL"+1*trQuestVarGet("CurrentDrillL")+"") + " "+1*xGetFloat(dPlayerData, xDrillPower)+" m/s");
}

void UpgradeHull(int p = -1){
	xsSetContextPlayer(0);
	trPlayerGrantResources(1, "Gold", -1*trQuestVarGet("goldCost"));
	xSetPointer(dPlayerData, 1);
	int HullLevelDummy = xGetInt(dPlayerData, xHullLevel);
	xSetInt(dPlayerData, xHullLevel, HullLevelDummy+1);
	xSetInt(dPlayerData, xHullHP, trQuestVarGet("HullHPL"+xGetInt(dPlayerData, xHullLevel)+""));
	trUnitSetVariation(1*trQuestVarGet("UnitFlag2"),HullLevelDummy);
	trQuestVarSet("CurrentHullL", xGetInt(dPlayerData, xHullLevel));
	trQuestVarSet("NextHullL", 1*trQuestVarGet("CurrentHullL")+1);
	trQuestVarSet("goldCost", 1*trQuestVarGet("HullCostL"+1*trQuestVarGet("NextHullL")+""));
	trSoundPlayFN("ui\thunder2.wav","1",-1,"","");
	trChatHistoryClear();
	trChatSend(0, "<u><color=1,1,1>Hull Upgraded:</color></u>");
	trChatSend(0, trStringQuestVarGet("HullL"+1*trQuestVarGet("CurrentHullL")+"") + " "+1*xGetInt(dPlayerData, xHullHP)+" hp");
}

void UpgradeFuel(int p = -1){
	xsSetContextPlayer(0);
	trPlayerGrantResources(1, "Gold", -1*trQuestVarGet("goldCost"));
	xSetPointer(dPlayerData, 1);
	int FuelLevelDummy = xGetInt(dPlayerData, xFuelLevel);
	xSetInt(dPlayerData, xFuelLevel, FuelLevelDummy+1);
	xSetInt(dPlayerData, xFuelTank, trQuestVarGet("FuelCL"+xGetInt(dPlayerData, xFuelLevel)+""));
	trUnitSetVariation(1*trQuestVarGet("UnitFlag3"),FuelLevelDummy);
	trQuestVarSet("CurrentFuelL", xGetInt(dPlayerData, xFuelLevel));
	trQuestVarSet("NextFuelL", 1*trQuestVarGet("CurrentFuelL")+1);
	trQuestVarSet("goldCost", 1*trQuestVarGet("FuelCostL"+1*trQuestVarGet("NextFuelL")+""));
	trSoundPlayFN("ui\thunder2.wav","1",-1,"","");
	trChatHistoryClear();
	trChatSend(0, "<u><color=1,1,1>Fuel Upgraded:</color></u>");
	trChatSend(0, trStringQuestVarGet("FuelL"+1*trQuestVarGet("CurrentFuelL")+"") + " "+1*xGetInt(dPlayerData, xFuelTank)+" L");
}

void UpgradeCargo(int p = -1){
	xsSetContextPlayer(0);
	trPlayerGrantResources(1, "Gold", -1*trQuestVarGet("goldCost"));
	xSetPointer(dPlayerData, 1);
	int CargoLevelDummy = xGetInt(dPlayerData, xCargoLevel);
	xSetInt(dPlayerData, xCargoLevel, CargoLevelDummy+1);
	xSetInt(dPlayerData, xCargoHold, trQuestVarGet("CargoCL"+xGetInt(dPlayerData, xCargoLevel)+""));
	trUnitSetVariation(1*trQuestVarGet("UnitFlag4"),CargoLevelDummy);
	trQuestVarSet("CurrentCargoL", xGetInt(dPlayerData, xCargoLevel));
	trQuestVarSet("NextCargoL", 1*trQuestVarGet("CurrentCargoL")+1);
	trQuestVarSet("goldCost", 1*trQuestVarGet("CargoCostL"+1*trQuestVarGet("NextCargoL")+""));
	trSoundPlayFN("ui\thunder2.wav","1",-1,"","");
	trChatHistoryClear();
	trChatSend(0, "<u><color=1,1,1>Cargo Upgraded:</color></u>");
	trChatSend(0, trStringQuestVarGet("CargoL"+1*trQuestVarGet("CurrentCargoL")+"") + " "+1*xGetInt(dPlayerData, xCargoHold)+" minerals");
}

void UpgradeEngine(int p = -1){
	xsSetContextPlayer(0);
	trPlayerGrantResources(1, "Gold", -1*trQuestVarGet("goldCost"));
	xSetPointer(dPlayerData, 1);
	int EngineLevelDummy = xGetInt(dPlayerData, xEngineLevel);
	xSetInt(dPlayerData, xEngineLevel, EngineLevelDummy+1);
	xSetInt(dPlayerData, xEnginePower, trQuestVarGet("EngineCL"+xGetInt(dPlayerData, xEngineLevel)+""));
	trUnitSetVariation(1*trQuestVarGet("UnitFlag5"),EngineLevelDummy);
	trQuestVarSet("CurrentEngineL", xGetInt(dPlayerData, xEngineLevel));
	trQuestVarSet("NextEngineL", 1*trQuestVarGet("CurrentEngineL")+1);
	trQuestVarSet("goldCost", 1*trQuestVarGet("EngineCostL"+1*trQuestVarGet("NextEngineL")+""));
	trSoundPlayFN("ui\thunder2.wav","1",-1,"","");
	trChatHistoryClear();
	trChatSend(0, "<u><color=1,1,1>Engine Upgraded:</color></u>");
	trChatSend(0, trStringQuestVarGet("EngineL"+1*trQuestVarGet("CurrentEngineL")+"") + " "+1*xGetInt(dPlayerData, xEnginePower)+" kW");
}

void UpgradeRadiator(int p = -1){
	xsSetContextPlayer(0);
	trPlayerGrantResources(1, "Gold", -1*trQuestVarGet("goldCost"));
	xSetPointer(dPlayerData, 1);
	int RadiatorLevelDummy = xGetInt(dPlayerData, xRadiatorLevel);
	xSetInt(dPlayerData, xRadiatorLevel, RadiatorLevelDummy+1);
	xSetInt(dPlayerData, xRadiator, trQuestVarGet("RadiatorCL"+xGetInt(dPlayerData, xRadiatorLevel)+""));
	trUnitSetVariation(1*trQuestVarGet("UnitFlag6"),RadiatorLevelDummy);
	trQuestVarSet("CurrentRadiatorL", xGetInt(dPlayerData, xRadiatorLevel));
	trQuestVarSet("NextRadiatorL", 1*trQuestVarGet("CurrentRadiatorL")+1);
	trQuestVarSet("goldCost", 1*trQuestVarGet("RadiatorCostL"+1*trQuestVarGet("NextRadiatorL")+""));
	trSoundPlayFN("ui\thunder2.wav","1",-1,"","");
	trChatHistoryClear();
	trChatSend(0, "<u><color=1,1,1>Radiator Upgraded:</color></u>");
	trChatSend(0, trStringQuestVarGet("RadiatorL"+1*trQuestVarGet("CurrentRadiatorL")+"") + " "+1*xGetInt(dPlayerData, xRadiator)+" percent efficient");
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
		saveAllData();
		xsEnableRule("SPExit");
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
