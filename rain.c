/* lure ability */
int MaxRows = 20;
int MaxCols = 25;

rule EventSetHandler
active
highFrequency
{
	trEventSetHandler(1, "UngarrisonDrill");
	trEventSetHandler(2, "UngarrisonDrill");
	trEventSetHandler(3, "UngarrisonDrill");
	trEventSetHandler(4, "UngarrisonDrill");
	trEventSetHandler(5, "UngarrisonDrill");
	trEventSetHandler(6, "UngarrisonDrill");
	trEventSetHandler(7, "UngarrisonDrill");
	trEventSetHandler(8, "UngarrisonDrill");
	trEventSetHandler(9, "UngarrisonDrill");
	trEventSetHandler(10, "UngarrisonDrill");
	trEventSetHandler(11, "UngarrisonDrill");
	trEventSetHandler(12, "UngarrisonDrill");
	xsDisableSelf();
}

rule lure
active
highFrequency
{
	for(p = 1; <= cNumberNonGaiaPlayers){
		if (trPlayerUnitCountSpecific(p, "Animal Attractor") == 1) {
			yFindLatestReverse("p"+p+"LureObject", "Animal Attractor", p);
			trVectorSetUnitPos("TargetVector"+p+"", "p"+p+"LureObject", true);
			trMutateSelected(kbGetProtoUnitID("Osiris SFX"));
			trVectorSnapToGrid("TargetVector"+p+"");
			trVectorSetUnitPos("SiphonPos", "P"+p+"Siphon");
			trVectorSnapToGrid("SiphonPos");
			int startXPos = (trVectorQuestVarGetX("SiphonPos") ) / 8 +1;
			int startZPos = (trVectorQuestVarGetZ("SiphonPos") ) / 8 +1;
			/*
			trArmyDispatch(""+p+",0", "Ajax", 1, trVectorQuestVarGetX("TargetVector"+p+""), trVectorQuestVarGetY("TargetVector"+p+""),
				trVectorQuestVarGetZ("TargetVector"+p+""), 0, true);
			*/
			trVectorQuestVarEcho("TargetVector"+p+"");
			int xPos = (trVectorQuestVarGetX("TargetVector"+p+"") ) / 8 +1;
			int zPos = (trVectorQuestVarGetZ("TargetVector"+p+"") ) / 8 +1;
			/*
			trQuestVarEcho("p"+p+"lureObject");
			trChatSend(0, "TARGET "+xPos+" is COL");
			trChatSend(0, "TARGET "+zPos+" is ROW");
			trChatSend(0, "START "+startXPos+" is COL");
			trChatSend(0, "START "+startZPos+" is ROW");
			*/
			// DISTANCE <92 IS OK TO DRILL
			if(zPos > MaxRows){
				trChatSendToPlayer(0, p, "<color=1,0,0>You can't drill above ground!</color>");
				if(trCurrentPlayer() == p){
					trSoundPlayFN("cantdothat.wav","1",-1,"","");
				}
				trTechGodPower(p, "Animal Magnetism", 1);
			}
			else if(trDistanceToVectorSquared("P1Siphon", "TargetVector"+p+"") > 92){
				trChatSendToPlayer(0, p,
					"<color=1,0,0>Drill request too far!</color>  "+trDistanceToVectorSquared("P"+p+"Siphon", "TargetVector"+p+"")+"");
				if(trCurrentPlayer() == p){
					trSoundPlayFN("cantdothat.wav","1",-1,"","");
				}
				trTechGodPower(p, "Animal Magnetism", 1);
			}
			//Stop diagonal drills
			else if((startXPos != xPos) && (startZPos != zPos)){
				trChatSendToPlayer(0, p, "<color=1,0,0>Diagonal drilling not allowed!</color>");
				if(trCurrentPlayer() == p){
					trSoundPlayFN("cantdothat.wav","1",-1,"","");
				}
				trTechGodPower(p, "Animal Magnetism", 1);
			}
			else if((startXPos == xPos) || (startZPos == zPos)){
				trChatSend(0, "DIST "+trDistanceToVectorSquared("P"+p+"Siphon", "TargetVector"+p+"")+" OK");
				trUnitSelectClear();
				trUnitSelectByQV("P"+p+"MainSpy", true);
				trMutateSelected(kbGetProtoUnitID("Heka Shockwave SFX"));
				trArmyDispatch(""+p+",0", "Revealer", 1, trVectorQuestVarGetX("SiphonPos"), trVectorQuestVarGetY("SiphonPos"),
					trVectorQuestVarGetZ("SiphonPos"), 180, true);
				trQuestVarSet("DrillAttach"+p+"", trGetNextUnitScenarioNameNumber());
				trArmyDispatch(""+p+",0", "Victory Marker", 1, trVectorQuestVarGetX("SiphonPos"), trVectorQuestVarGetY("SiphonPos"),
					trVectorQuestVarGetZ("SiphonPos"), 180, true);
				trUnitSelectClear();
				trUnitSelectByQV("P"+p+"Siphon", false);
				trUnitChangeProtoUnit("Wadjet Spit");
				trUnitSelectClear();
				trUnitSelectByQV("P"+p+"Siphon", false);
				trMutateSelected(kbGetProtoUnitID("relic"));
				trUnitSelectClear();
				trUnitSelectByQV("DrillAttach"+p+"", true);
				trMutateSelected(kbGetProtoUnitID("Ajax"));
				trUnitSelectClear();
				trUnitSelectByQV("P"+p+"Siphon", false);
				trBlockAllSounds(true);
				trImmediateUnitGarrison(""+1*trQuestVarGet("DrillAttach"+p+"")+"");
				trUnblockAllSounds();
				trUnitSelectClear();
				trUnitSelectByQV("P"+p+"Siphon", false);
				trMutateSelected(kbGetProtoUnitID("Fire Siphon"));
				trUnitOverrideAnimation(1, 0, true, false, -1, 0);
				trUnitSelectClear();
				trUnitSelectByQV("DrillAttach"+p+"", true);
				trMutateSelected(kbGetProtoUnitID("Wadjet Spit"));
				modifyProtounitAbsolute("Wadjet Spit", p, 1, 3);
				trUnitSelectClear();
				trUnitSelectByQV("DrillAttach"+p+"", true);
				trUnitMoveToVectorEvent("TargetVector"+p+"", false, 1);
			}
		}
		else {
			trQuestVarSet("p"+p+"LureObject", trGetNextUnitScenarioNameNumber() - 1);
		}
	}
}

void UngarrisonDrill(int p = 1){
	trUnitSelectClear();
	trUnitSelectByQV("DrillAttach"+p+"", true);
	trUnitDestroy();
	trUnitSelectClear();
	trUnitSelectByQV("P"+p+"Siphon", false);
	//trUnitEjectContained();
	//trUnitChangeProtoUnit("Hero Greek Atalanta");
	trMutateSelected(kbGetProtoUnitID("Hero Greek Atalanta"));
	//garrison relics
	trTechGodPower(p, "Animal Magnetism", 1);
	trVectorSetUnitPos("SiphonPos", "P"+p+"Siphon");
	trVectorSnapToGrid("SiphonPos");
	trArmyDispatch(""+p+",0", "Revealer", 1, trVectorQuestVarGetX("SiphonPos"), trVectorQuestVarGetY("SiphonPos"),
		trVectorQuestVarGetZ("SiphonPos"), 180, true);
	trUnitSelectClear();
	trUnitSelectByQV("P"+p+"MainSpy", true);
	trMutateSelected(kbGetProtoUnitID("Fire Siphon"));
	//FEATURE ** - needs some sort of snap to grid tp for the atalanta
	xsDisableSelf();
}

void ChangeMainSpy(int p = 1){
	trUnitSelectClear();
	trUnitSelectByQV("P"+p+"MainSpy", true);
	trMutateSelected(kbGetProtoUnitID("Curse SFX"));
	trChatSend(0, ""+p+"");
}

rule squarespaint
active
highFrequency
{
	if(trChatHistoryContains("1", 1)){
		//trPaintTerrain(0,0,4*col+4,4*row+4,2,13,false);
		trPaintTerrain(0,0,4*MaxCols,4*MaxRows,2,13,false);
		for(col = 1; <= MaxCols){
			for(row = 1; <= MaxRows){
				trPaintTerrain(4*col-1,4*row-1,4*col-3,4*row-3,0,73,false);
				trQuestVarSet("R"+row+"C"+col+"CentreY", row*4-2);
				trQuestVarSet("R"+row+"C"+col+"CentreX", col*4-2);
				//trVectorQuestVarSet("R"+row+"C"+col+"", xsVectorSet(col*8-3, 3, row*8-3));
				//trQuestVarSet("R"+row+"C"+col+"Drilled", 0);
				//trQuestVarSet("R"+row+"C"+col+"HP", 0);
			}
		}
		trQuestVarEcho("R4C3CentreX");
		trQuestVarEcho("R4C3CentreY");
		trVectorQuestVarEcho("R4C3");
		trPaintTerrain(1*trQuestVarGet("R4C3CentreX"),
			1*trQuestVarGet("R4C3CentreY"),1*trQuestVarGet("R4C3CentreX"),
			1*trQuestVarGet("R4C3CentreY"),2,2,false);
		xsDisableSelf();
		trQuestVarSet("P1Siphon", trGetNextUnitScenarioNameNumber());
		//VECTOR IS 2X+1
		UnitCreate(1, "Hero Greek Atalanta", 12, 180, 180);
		yAddToDatabase("Siphon1", "P1Siphon");
		trQuestVarSet("P1MainSpy", trGetNextUnitScenarioNameNumber());
		trPlayerSetDiplomacy(0, 1, "Enemy");
		trUnitSelectClear();
		trUnitSelectByQV("P1Siphon", false);
		trTechInvokeGodPower(0, "spy", vector(0,0,0), vector(0,0,0));
		trDelayedRuleActivation("ChangeMainSpy1");
	}
}

rule fuckssake
active
highFrequency
{
	if(trChatHistoryContains("DEBUG", 1)){
		trChatHistoryClear();
		trVectorQuestVarSet("TargetVector1", vector(1,1,1));
		trVectorQuestVarEcho("TargetVector1");
	}
}
