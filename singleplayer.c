void PaintSP(){
	xsSetContextPlayer(0);
	xSetPointer(dPlayerData, 1);
	PaintAtlantisArea(0,0,68,31,"NorseRoadA");
	PaintAtlantisArea(32,12,36,16,"BlackRock"); // main sq
	PaintAtlantisArea(32,23,36,27,"black"); // boon sq
	PaintAtlantisArea(32,1,36,5,"black"); // exit sq
	
	PaintAtlantisArea(33,28,35,30,"black"); //bonus central
	PaintAtlantisArea(70,0,72,44,"black"); //relic warehouse
	for(z=1 ; <= 21){
		trQuestVarSet("RelicEffect"+z, trGetNextUnitScenarioNameNumber());
		trArmyDispatch("0,0", "Victory Marker", 1, 142,3,4*z, 90, true);
		if((z >= 20) || (z == RELIC_TOPAZ)){
			trQuestVarSet("RelicEffectA"+z, trGetNextUnitScenarioNameNumber());
			trArmyDispatch("0,0", "Victory Marker", 1, 142,3,4*z, 90, true);
		}
		if(xGetInt(dPlayerData, xRelicCollected+z) == 1){
			spawnRelicSpecific(xsVectorSet(142,3,4*z), z);
			trUnitSelectByQV("RelicEffect"+z);
			trUnitChangeProtoUnit("Spy Eye");
			trUnitSelectByQV("RelicEffect"+z);
			if(z == RELIC_IRON){
				trMutateSelected(kbGetProtoUnitID("Rock Limestone Sprite"));
				trUnitSelectByQV("RelicEffect"+z);
				trSetSelectedScale(2,2,2);
			}
			if(z == RELIC_BRONZE){
				trMutateSelected(kbGetProtoUnitID("Rock Dirt Sprite"));
				trUnitSelectByQV("RelicEffect"+z);
				trSetSelectedScale(2,2,2);
			}
			if(z == RELIC_SILVER){
				trMutateSelected(kbGetProtoUnitID("Rock Granite Sprite"));
				trUnitSelectByQV("RelicEffect"+z);
				trSetSelectedScale(2,2,2);
			}
			if(z == RELIC_GOLD){
				trMutateSelected(kbGetProtoUnitID("Rock Sandstone Sprite"));
				trUnitSelectByQV("RelicEffect"+z);
				trSetSelectedScale(2,2,2);
			}
			if(z == RELIC_PLATINUM){
				trMutateSelected(kbGetProtoUnitID("Ragnorok SFX"));
			}
			if(z == RELIC_URANIUM){
				trMutateSelected(kbGetProtoUnitID("Medusa"));
				trUnitSelectByQV("RelicEffect"+z);
				trBlockAllSounds();
				trUnitOverrideAnimation(40,0,true,true,-1,0);
				trUnblockAllSounds();
				trUnitSelectByQV("RelicEffect"+z);
				trSetSelectedScale(0.001,0.5,0);
			}
			if(z == RELIC_RUBY){
				trMutateSelected(kbGetProtoUnitID("Einheriar Boost SFX"));
			}
			if(z == RELIC_SAPPHIRE){
				trMutateSelected(kbGetProtoUnitID("Vortex Start Linked"));
			}
			if(z == RELIC_DIAMOND){
				trMutateSelected(kbGetProtoUnitID("Healing SFX"));
				trUnitSelectByQV("RelicEffect"+z);
				trUnitOverrideAnimation(18,0,true,false,-1,0);
				//trUnitSelectByQV("RelicEffect"+z);
				//trSetSelectedScale(0.001,0.5,0);
			}
			if(z == RELIC_PROMETHIUM){
				trMutateSelected(kbGetProtoUnitID("Poison SFX"));
			}
			if(z == RELIC_EINSTEINIUM){
				trMutateSelected(kbGetProtoUnitID("Fire Giant"));
				trSetSelectedScale(0,0,0);
			}
			if(z == RELIC_OBSIDIAN){
				trMutateSelected(kbGetProtoUnitID("Smoke"));
			}
			if(z == RELIC_TOPAZ){
				trMutateSelected(kbGetProtoUnitID("Hero Norse"));
				trSetSelectedScale(0,0,0);
				trUnitSelectClear();
				trUnitSelectByQV("RelicEffectA"+z);
				trUnitChangeProtoUnit("Spy Eye");
				trUnitSelectByQV("RelicEffectA"+z);
				trMutateSelected(kbGetProtoUnitID("Hero Norse"));
				trSetSelectedScale(0,0,0);
				trUnitSelectClear();
			}
			if(z == RELIC_QUARTZ){
				trMutateSelected(kbGetProtoUnitID("Arkantosman"));
				trSetSelectedScale(0,0,0);
			}
			if(z == RELIC_OPAL){
				trMutateSelected(kbGetProtoUnitID("Flying Purple Hippo"));
				trSetSelectedScale(0,0,0);
				trUnitSelectByQV("RelicEffect"+z);
				trUnitOverrideAnimation(15,0,true,false,-1,0);
			}
			if(z == RELIC_AMETHYST){
				trMutateSelected(kbGetProtoUnitID("Pharaoh of Osiris XP"));
				trSetSelectedScale(0.01,0.5,0);
				trUnitSelectByQV("RelicEffect"+z);
				trUnitOverrideAnimation(50,0,true,false,-1,0);
			}
			if(z == RELIC_EMERALD){
				trMutateSelected(kbGetProtoUnitID("Acid Pool"));
				trSetSelectedScale(0,0,0);
			}
			if(z == RELIC_ICE){
				trMutateSelected(kbGetProtoUnitID("Frost Giant"));
				trUnitSelectByQV("RelicEffect"+z);
				trSetSelectedScale(0,0,0);
			}
			if(z == RELIC_HYDROGEN){
				trMutateSelected(kbGetProtoUnitID("Lighthouse"));
				trUnitSelectByQV("RelicEffect"+z);
				trSetSelectedScale(0,0,0);
			}
			if(z == RELIC_ANTIMATTER){
				trMutateSelected(kbGetProtoUnitID("Tower Mirror"));
				trUnitSelectByQV("RelicEffect"+z);
				trSetSelectedScale(0,0,0);
				trUnitSelectClear();
				trUnitSelectByQV("RelicEffectA"+z);
				trUnitChangeProtoUnit("Spy Eye");
				trUnitSelectByQV("RelicEffectA"+z);
				trMutateSelected(kbGetProtoUnitID("Tower Mirror"));
				trSetSelectedScale(0,0,0);
				trUnitSelectClear();
			}
			if(z == RELIC_YEEBIUM){
				trMutateSelected(kbGetProtoUnitID("Valkyrie"));
				trUnitSelectByQV("RelicEffect"+z);
				trSetSelectedScale(0,0,0);
				trUnitSelectClear();
				trUnitSelectByQV("RelicEffectA"+z);
				trUnitChangeProtoUnit("Spy Eye");
				trUnitSelectByQV("RelicEffectA"+z);
				trMutateSelected(kbGetProtoUnitID("Valkyrie"));
				trSetSelectedScale(0,0,0);
				trUnitSelectClear();
				trTechSetStatus(0, 91, 4);
			}
		}
	}
	for(x=1 ; <= 10){
		PaintAtlantisArea(33-x*3,28,35-x*3,30,"black");
	}
	for(x=1 ; <= 10){
		PaintAtlantisArea(33+x*3,28,35+x*3,30,"black");
	}
	
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
}

void UpgradeEffect(int u = 0){
	xsSetContextPlayer(0);
	if((u == 2) || (u == 5)){
		trQuestVarSet("Path"+u+"", 12);
	}
	else {
		trQuestVarSet("Path"+u+"", 15);
	}
	//SP Obelisk anim light cost
	if(xGetInt(dPlayerData, xGold) < 1*trQuestVarGet("DrillCostL"+(1*xGetInt(dPlayerData, xDrillLevel)+1)+"")){
		trUnitSelectClear();
		trUnitSelect(""+UnitObelisk1);
		trUnitSetAnimationPath("0,1,0,0,0");
	}
	if(xGetInt(dPlayerData, xGold) < 1*trQuestVarGet("HullCostL"+(1*xGetInt(dPlayerData, xHullLevel)+1)+"")){
		trUnitSelectClear();
		trUnitSelect(""+UnitObelisk2);
		trUnitSetAnimationPath("0,1,0,0,0");
	}
	if(xGetInt(dPlayerData, xGold) < 1*trQuestVarGet("FuelCostL"+(1*xGetInt(dPlayerData, xFuelLevel)+1)+"")){
		trUnitSelectClear();
		trUnitSelect(""+UnitObelisk3);
		trUnitSetAnimationPath("0,1,0,0,0");
	}
	if(xGetInt(dPlayerData, xGold) < 1*trQuestVarGet("CargoCostL"+(1*xGetInt(dPlayerData, xCargoLevel)+1)+"")){
		trUnitSelectClear();
		trUnitSelect(""+UnitObelisk4);
		trUnitSetAnimationPath("0,1,0,0,0");
	}
	if(xGetInt(dPlayerData, xGold) < 1*trQuestVarGet("EngineCostL"+(1*xGetInt(dPlayerData, xEngineLevel)+1)+"")){
		trUnitSelectClear();
		trUnitSelect(""+UnitObelisk5);
		trUnitSetAnimationPath("0,1,0,0,0");
	}
	if(xGetInt(dPlayerData, xGold) < 1*trQuestVarGet("RadiatorCostL"+(1*xGetInt(dPlayerData, xRadiatorLevel)+1)+"")){
		trUnitSelectClear();
		trUnitSelect(""+UnitObelisk6);
		trUnitSetAnimationPath("0,1,0,0,0");
	}
	trUnitSelectClear();
}

rule UpgradeSFX
inactive
highFrequency
{
	if(trTimeMS() > 1*trQuestVarGet("100MS")){
		trQuestVarModify("100MS", "+", 100);
		int a = 0;
		if(1*trQuestVarGet("Path1") == 15){
			trQuestVarSet("1X",47);
			trQuestVarSet("1Z",39);
		}
		if(1*trQuestVarGet("Path1") >= 1){
			a = trGetNextUnitScenarioNameNumber();
			trArmyDispatch("0,0", "Dwarf", 1, 1,1,1, 0, true);
			trUnitSelectClear();
			trUnitSelect(""+a);
			trUnitTeleport(1*trQuestVarGet("1X"),3,1*trQuestVarGet("1Z"));
			trUnitSelectClear();
			trUnitSelect(""+a);
			trUnitChangeProtoUnit("Lampades Bolt");
			if(1*trQuestVarGet("Path1") >= 9){
				trQuestVarModify("1X", "+", 2);
			}
			else if((1*trQuestVarGet("Path1") >= 5) && (1*trQuestVarGet("Path1") < 9)){
				trQuestVarModify("1Z", "-", 2);
			}
			else if((1*trQuestVarGet("Path1") >= 3) && (1*trQuestVarGet("Path1") < 5)){
				trQuestVarModify("1X", "+", 2);
			}
			else if(1*trQuestVarGet("Path1") <= 2){
				trQuestVarModify("1X", "+", 2);
				trQuestVarModify("1Z", "-", 2);
			}
			trQuestVarModify("Path1", "-", 1);
			if(1*trQuestVarGet("Path1") == 0){
				trUnitSelectByQV("MainSiphon");
				trUnitHighlight(1.0, false);
			}
		}
		if(1*trQuestVarGet("Path2") == 12){
			trQuestVarSet("2X",47);
			trQuestVarSet("2Z",29);
		}
		if(1*trQuestVarGet("Path2") >= 1){
			a = trGetNextUnitScenarioNameNumber();
			trArmyDispatch("0,0", "Dwarf", 1, 1,1,1, 0, true);
			trUnitSelectClear();
			trUnitSelect(""+a);
			trUnitTeleport(1*trQuestVarGet("2X"),3,1*trQuestVarGet("2Z"));
			trUnitSelectClear();
			trUnitSelect(""+a);
			trUnitChangeProtoUnit("Lampades Bolt");
			trQuestVarModify("2X", "+", 2);
			trQuestVarModify("Path2", "-", 1);
			if(1*trQuestVarGet("Path2") == 0){
				trUnitSelectByQV("MainSiphon");
				trUnitHighlight(1.0, false);
			}
		}
		if(1*trQuestVarGet("Path3") == 15){
			trQuestVarSet("3X",47);
			trQuestVarSet("3Z",19);
		}
		if(1*trQuestVarGet("Path3") >= 1){
			a = trGetNextUnitScenarioNameNumber();
			trArmyDispatch("0,0", "Dwarf", 1, 1,1,1, 0, true);
			trUnitSelectClear();
			trUnitSelect(""+a);
			trUnitTeleport(1*trQuestVarGet("3X"),3,1*trQuestVarGet("3Z"));
			trUnitSelectClear();
			trUnitSelect(""+a);
			trUnitChangeProtoUnit("Lampades Bolt");
			if(1*trQuestVarGet("Path3") >= 9){
				trQuestVarModify("3X", "+", 2);
			}
			else if((1*trQuestVarGet("Path3") >= 5) && (1*trQuestVarGet("Path3") < 9)){
				trQuestVarModify("3Z", "+", 2);
			}
			else if((1*trQuestVarGet("Path3") >= 3) && (1*trQuestVarGet("Path3") < 5)){
				trQuestVarModify("3X", "+", 2);
			}
			else if(1*trQuestVarGet("Path3") <= 2){
				trQuestVarModify("3X", "+", 2);
				trQuestVarModify("3Z", "+", 2);
			}
			trQuestVarModify("Path3", "-", 1);
			if(1*trQuestVarGet("Path3") == 0){
				trUnitSelectByQV("MainSiphon");
				trUnitHighlight(1.0, false);
			}
		}
		if(1*trQuestVarGet("Path4") == 15){
			trQuestVarSet("4X",91);
			trQuestVarSet("4Z",39);
		}
		if(1*trQuestVarGet("Path4") >= 1){
			a = trGetNextUnitScenarioNameNumber();
			trArmyDispatch("0,0", "Dwarf", 1, 1,1,1, 0, true);
			trUnitSelectClear();
			trUnitSelect(""+a);
			trUnitTeleport(1*trQuestVarGet("4X"),3,1*trQuestVarGet("4Z"));
			trUnitSelectClear();
			trUnitSelect(""+a);
			trUnitChangeProtoUnit("Lampades Bolt");
			if(1*trQuestVarGet("Path4") >= 9){
				trQuestVarModify("4X", "-", 2);
			}
			else if((1*trQuestVarGet("Path4") >= 5) && (1*trQuestVarGet("Path4") < 9)){
				trQuestVarModify("4Z", "-", 2);
			}
			else if((1*trQuestVarGet("Path4") >= 3) && (1*trQuestVarGet("Path4") < 5)){
				trQuestVarModify("4X", "-", 2);
			}
			else if(1*trQuestVarGet("Path4") <= 2){
				trQuestVarModify("4X", "-", 2);
				trQuestVarModify("4Z", "-", 2);
			}
			trQuestVarModify("Path4", "-", 1);
			if(1*trQuestVarGet("Path4") == 0){
				trUnitSelectByQV("MainSiphon");
				trUnitHighlight(1.0, false);
			}
		}
		if(1*trQuestVarGet("Path5") == 12){
			trQuestVarSet("5X",91);
			trQuestVarSet("5Z",29);
		}
		if(1*trQuestVarGet("Path5") >= 1){
			a = trGetNextUnitScenarioNameNumber();
			trArmyDispatch("0,0", "Dwarf", 1, 1,1,1, 0, true);
			trUnitSelectClear();
			trUnitSelect(""+a);
			trUnitTeleport(1*trQuestVarGet("5X"),3,1*trQuestVarGet("5Z"));
			trUnitSelectClear();
			trUnitSelect(""+a);
			trUnitChangeProtoUnit("Lampades Bolt");
			trQuestVarModify("5X", "-", 2);
			trQuestVarModify("Path5", "-", 1);
			if(1*trQuestVarGet("Path5") == 0){
				trUnitSelectByQV("MainSiphon");
				trUnitHighlight(1.0, false);
			}
		}
		if(1*trQuestVarGet("Path6") == 15){
			trQuestVarSet("6X",91);
			trQuestVarSet("6Z",19);
		}
		if(1*trQuestVarGet("Path6") >= 1){
			a = trGetNextUnitScenarioNameNumber();
			trArmyDispatch("0,0", "Dwarf", 1, 1,1,1, 0, true);
			trUnitSelectClear();
			trUnitSelect(""+a);
			trUnitTeleport(1*trQuestVarGet("6X"),3,1*trQuestVarGet("6Z"));
			trUnitSelectClear();
			trUnitSelect(""+a);
			trUnitChangeProtoUnit("Lampades Bolt");
			if(1*trQuestVarGet("Path6") >= 9){
				trQuestVarModify("6X", "-", 2);
			}
			else if((1*trQuestVarGet("Path6") >= 5) && (1*trQuestVarGet("Path6") < 9)){
				trQuestVarModify("6Z", "+", 2);
			}
			else if((1*trQuestVarGet("Path6") >= 3) && (1*trQuestVarGet("Path6") < 5)){
				trQuestVarModify("6X", "-", 2);
			}
			else if(1*trQuestVarGet("Path6") <= 2){
				trQuestVarModify("6X", "-", 2);
				trQuestVarModify("6Z", "+", 2);
			}
			trQuestVarModify("Path6", "-", 1);
			if(1*trQuestVarGet("Path6") == 0){
				trUnitSelectByQV("MainSiphon");
				trUnitHighlight(1.0, false);
			}
		}
	}
}

rule LoadSP
inactive
highFrequency
{
	trBlockAllSounds();
	trSetFogAndBlackmap(false, false);
	xsDisableSelf();
	//xsEnableRule("SPCineChoice");
	xsEnableRule("UpgradeSFX");
	PaintSP();
	trQuestVarSet("MainSiphon", trGetNextUnitScenarioNameNumber());
	UnitCreate(0, "Fire Siphon", 68, 28, 180); //main siphon
	trQuestVarSet("ExitYeeb", trGetNextUnitScenarioNameNumber());
	UnitCreate(1, "Pharaoh of Osiris XP", 68, 20, 180); //Player Unit
	trQuestVarSet("ExitTunnel", trGetNextUnitScenarioNameNumber());
	UnitCreate(1, "Tunnel", 68, 7, 180); //exit unit
	trQuestVarSet("BonusUnit", trGetNextUnitScenarioNameNumber());
	UnitCreate(0, "Outpost", 68, 51, 180); //boon unit
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
	
	UnitObelisk1 = trGetNextUnitScenarioNameNumber();
	UnitCreate(1, "Victory Marker", 38, 38, 90);
	UnitObelisk2 = trGetNextUnitScenarioNameNumber();
	UnitCreate(1, "Victory Marker", 38, 28, 90);
	UnitObelisk3 = trGetNextUnitScenarioNameNumber();
	UnitCreate(1, "Victory Marker", 38, 18, 90);
	UnitObelisk4 = trGetNextUnitScenarioNameNumber();
	UnitCreate(1, "Victory Marker", 98, 38, 90);
	UnitObelisk5 = trGetNextUnitScenarioNameNumber();
	UnitCreate(1, "Victory Marker", 98, 28, 90);
	UnitObelisk6 = trGetNextUnitScenarioNameNumber();
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
	
	//SP Obelisk anim light cost
	if(xGetInt(dPlayerData, xGold) < 1*trQuestVarGet("DrillCostL"+(1*xGetInt(dPlayerData, xDrillLevel)+1)+"")){
		trUnitSelect(""+UnitObelisk1);
		trUnitSetAnimationPath("0,1,0,0,0");
	}
	if(xGetInt(dPlayerData, xGold) < 1*trQuestVarGet("HullCostL"+(1*xGetInt(dPlayerData, xHullLevel)+1)+"")){
		trUnitSelect(""+UnitObelisk2);
		trUnitSetAnimationPath("0,1,0,0,0");
	}
	if(xGetInt(dPlayerData, xGold) < 1*trQuestVarGet("FuelCostL"+(1*xGetInt(dPlayerData, xFuelLevel)+1)+"")){
		trUnitSelect(""+UnitObelisk3);
		trUnitSetAnimationPath("0,1,0,0,0");
	}
	if(xGetInt(dPlayerData, xGold) < 1*trQuestVarGet("CargoCostL"+(1*xGetInt(dPlayerData, xCargoLevel)+1)+"")){
		trUnitSelect(""+UnitObelisk4);
		trUnitSetAnimationPath("0,1,0,0,0");
	}
	if(xGetInt(dPlayerData, xGold) < 1*trQuestVarGet("EngineCostL"+(1*xGetInt(dPlayerData, xEngineLevel)+1)+"")){
		trUnitSelect(""+UnitObelisk5);
		trUnitSetAnimationPath("0,1,0,0,0");
	}
	if(xGetInt(dPlayerData, xGold) < 1*trQuestVarGet("RadiatorCostL"+(1*xGetInt(dPlayerData, xRadiatorLevel)+1)+"")){
		trUnitSelect(""+UnitObelisk6);
		trUnitSetAnimationPath("0,1,0,0,0");
	}
	
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
	//LoadDataSP();
	xsSetContextPlayer(0);
	xSetPointer(dPlayerData, 1);
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
	trQuestVarSet("CurrentDrillL", xGetInt(dPlayerData, xDrillLevel));
	xSetFloat(dPlayerData, xDrillPower ,1*trQuestVarGet("DrillPowerL"+xGetInt(dPlayerData, xDrillLevel)+""));
	trQuestVarSet("CurrentHullL", xGetInt(dPlayerData, xHullLevel));
	xSetInt(dPlayerData, xHullHP ,1*trQuestVarGet("HullHPL"+xGetInt(dPlayerData, xHullLevel)+""));
	trQuestVarSet("CurrentFuelL", xGetInt(dPlayerData, xFuelLevel));
	xSetInt(dPlayerData, xFuelLevel ,1*trQuestVarGet("CurrentFuelL"));
	xSetInt(dPlayerData, xFuelTank ,1*trQuestVarGet("FuelCL"+xGetInt(dPlayerData, xFuelLevel)+""));
	trQuestVarSet("CurrentCargoL", xGetInt(dPlayerData, xCargoLevel));
	xSetInt(dPlayerData, xCargoHold ,1*trQuestVarGet("CargoCL"+xGetInt(dPlayerData, xCargoLevel)+""));
	trQuestVarSet("CurrentEngineL", xGetInt(dPlayerData, xEngineLevel));
	xSetInt(dPlayerData, xEnginePower ,1*trQuestVarGet("EngineCL"+xGetInt(dPlayerData, xEngineLevel)+""));
	trQuestVarSet("CurrentRadiatorL", xGetInt(dPlayerData, xRadiatorLevel));
	xSetInt(dPlayerData, xRadiator ,1*trQuestVarGet("RadiatorCL"+xGetInt(dPlayerData, xRadiatorLevel)+""));
	
	
	trUnitSetVariation(UnitFlag1,1*trQuestVarGet("CurrentDrillL")-1);
	trUnitSetVariation(UnitFlag2,1*trQuestVarGet("CurrentHullL")-1);
	trUnitSetVariation(UnitFlag3,1*trQuestVarGet("CurrentFuelL")-1);
	trUnitSetVariation(UnitFlag4,1*trQuestVarGet("CurrentCargoL")-1);
	trUnitSetVariation(UnitFlag5,1*trQuestVarGet("CurrentEngineL")-1);
	trUnitSetVariation(UnitFlag6,1*trQuestVarGet("CurrentRadiatorL")-1);
	xsEnableRule("eternal_loops");
	trLetterBox(false);
	trUIFadeToColor(0,0,0,1500,0,false);
	uiZoomToProto("Pharaoh of Osiris XP");
	uiClearSelection();
	
	PaintPlanets(8,35);
	MainTitle(14,115);
	//trChatSend(0, "Hull repair spend - " + xGetInt(dPlayerData, xHullSpend));
	//trChatSend(0, "Fuel spend - " + xGetInt(dPlayerData, xFuelSpend));
	xsEnableRule("choose_stage");
	if((xGetInt(dPlayerData, xStageUnlocked) == 1) && (xGetInt(dPlayerData, xStageStatus) == 1)){
		xsEnableRule("SPUnlock3");
	}
	if((xGetInt(dPlayerData, xStageUnlocked) == 2) && (xGetInt(dPlayerData, xStageStatus) == 1)){
		xsEnableRule("SPUnlock4");
	}
	if((xGetInt(dPlayerData, xStageUnlocked) == 3) && (xGetInt(dPlayerData, xStageStatus) == 1)){
		xsEnableRule("SPUnlock5");
	}
	if((xGetInt(dPlayerData, xStageUnlocked) == 4) && (xGetInt(dPlayerData, xStageStatus) == 1)){
		xsEnableRule("SPUnlock6");
	}
	
	if(1*trQuestVarGet("CineStatus") == 0){
		xsEnableRule("SPCineChoice");
	}
	else{
		SPCineOption();
	}
	
	//BONUS
	for(x=1 ; <= 23){
		trQuestVarSet("Bonus"+x, trGetNextUnitScenarioNameNumber());
		trArmyDispatch("0,0", "Victory Marker", 1, x*6+2,3,58, 180, true);
		trQuestVarSet("BonusEffect"+x, trGetNextUnitScenarioNameNumber());
		trArmyDispatch("0,0", "Victory Marker", 1, x*6+2,3,58, 180, true);
		trQuestVarSet("BonusEffects"+x, trGetNextUnitScenarioNameNumber());
		trArmyDispatch("0,0", "Victory Marker", 1, x*6+2,3,58, 180, true);
		/*trUnitSelectClear();
		trUnitSelectByQV("Bonus"+x);
		trUnitChangeProtoUnit("Outpost");*/
	}
	xsEnableRule("Bonus_Display");
	
}

void UpgradeDrill(int p = -1){
	xsSetContextPlayer(0);
	xSetInt(dPlayerData, xGold, xGetInt(dPlayerData, xGold)-1*trQuestVarGet("goldCost"));
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
	playSoundCustom("ageadvance.wav", "\Yeebaagooon\Motherload\Upgrade.mp3");
	UpgradeEffect(1);
}

void UpgradeHull(int p = -1){
	xsSetContextPlayer(0);
	xSetInt(dPlayerData, xGold, xGetInt(dPlayerData, xGold)-1*trQuestVarGet("goldCost"));
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
	playSoundCustom("ageadvance.wav", "\Yeebaagooon\Motherload\Upgrade.mp3");
	UpgradeEffect(2);
}

void UpgradeFuel(int p = -1){
	xsSetContextPlayer(0);
	xSetInt(dPlayerData, xGold, xGetInt(dPlayerData, xGold)-1*trQuestVarGet("goldCost"));
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
	playSoundCustom("ageadvance.wav", "\Yeebaagooon\Motherload\Upgrade.mp3");
	UpgradeEffect(3);
}

void UpgradeCargo(int p = -1){
	xsSetContextPlayer(0);
	xSetInt(dPlayerData, xGold, xGetInt(dPlayerData, xGold)-1*trQuestVarGet("goldCost"));
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
	playSoundCustom("ageadvance.wav", "\Yeebaagooon\Motherload\Upgrade.mp3");
	UpgradeEffect(4);
}

void UpgradeEngine(int p = -1){
	xsSetContextPlayer(0);
	xSetInt(dPlayerData, xGold, xGetInt(dPlayerData, xGold)-1*trQuestVarGet("goldCost"));
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
	playSoundCustom("ageadvance.wav", "\Yeebaagooon\Motherload\Upgrade.mp3");
	UpgradeEffect(5);
}

void UpgradeRadiator(int p = -1){
	xsSetContextPlayer(0);
	xSetInt(dPlayerData, xGold, xGetInt(dPlayerData, xGold)-1*trQuestVarGet("goldCost"));
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
	playSoundCustom("ageadvance.wav", "\Yeebaagooon\Motherload\Upgrade.mp3");
	UpgradeEffect(6);
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
		if(OverrideStage == true){
			xSetPointer(dPlayerData, 1);
			xSetInt(dPlayerData, xGold, 10000);
			saveAllData();
		}
		xsDisableSelf();
		trEndGame();
		trModeEnter("Pregame");
	}
}

rule SPUnlock3
inactive
highFrequency
{
	xSetPointer(dPlayerData, 1);
	if(xGetInt(dPlayerData, xDrillLevel) > 1){
		xSetInt(dPlayerData, xStageUnlocked, xGetInt(dPlayerData, xStageUnlocked) + 1);
		xSetInt(dPlayerData, xStageStatus, 0);
		trShowImageDialog(stageIcon(3), "Next planet unlocked - " + stageName(3));
		xsDisableSelf();
	}
}

rule SPUnlock4
inactive
highFrequency
{
	xSetPointer(dPlayerData, 1);
	if(xGetInt(dPlayerData, xHullLevel) > 2){
		xSetInt(dPlayerData, xStageUnlocked, xGetInt(dPlayerData, xStageUnlocked) + 1);
		xSetInt(dPlayerData, xStageStatus, 0);
		trShowImageDialog(stageIcon(4), "Next planet unlocked - " + stageName(4));
		xsDisableSelf();
	}
}

rule SPUnlock5
inactive
highFrequency
{
	xSetPointer(dPlayerData, 1);
	if((xGetInt(dPlayerData, xDrillLevel) >= 3) && (xGetInt(dPlayerData, xHullLevel) >= 3) && (xGetInt(dPlayerData, xFuelLevel) >= 3) && (xGetInt(dPlayerData, xEngineLevel) >= 3) && (xGetInt(dPlayerData, xCargoLevel) >= 3) && (xGetInt(dPlayerData, xRadiatorLevel) >= 3)){
		xSetInt(dPlayerData, xStageUnlocked, xGetInt(dPlayerData, xStageUnlocked) + 1);
		xSetInt(dPlayerData, xStageStatus, 0);
		trShowImageDialog(stageIcon(5), "Next planet unlocked - " + stageName(5));
		xsDisableSelf();
	}
}

rule SPUnlock6
inactive
highFrequency
{
	xSetPointer(dPlayerData, 1);
	if(xGetInt(dPlayerData, xDrillLevel) >= 5){
		xSetInt(dPlayerData, xStageUnlocked, xGetInt(dPlayerData, xStageUnlocked) + 1);
		xSetInt(dPlayerData, xStageStatus, 0);
		trShowImageDialog(stageIcon(5), "Next planet unlocked - " + stageName(5));
		xsDisableSelf();
	}
}
