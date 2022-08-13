rule lure
inactive
highFrequency
{
	for(p = 1; <= cNumberNonGaiaPlayers){
		if (trPlayerUnitCountSpecific(p, "Animal Attractor") == 1) {
			yFindLatestReverse("p"+p+"LureObject", "Animal Attractor", p);
			trVectorSetUnitPos("TargetVector"+p+"", "p"+p+"LureObject", true);
			trMutateSelected(kbGetProtoUnitID("Rocket"));
			trVectorSnapToGrid("TargetVector"+p+"");
			trVectorSetUnitPos("SiphonPos"+p+"", "P"+p+"Siphon");
			trVectorSnapToGrid("SiphonPos"+p+"");
			int startXPos = (trVectorQuestVarGetX("SiphonPos"+p+"") ) / 8 +1;
			int startZPos = (trVectorQuestVarGetZ("SiphonPos"+p+"") ) / 8 +1;
			/*
			trArmyDispatch(""+p+",0", "Ajax", 1, trVectorQuestVarGetX("TargetVector"+p+""), trVectorQuestVarGetY("TargetVector"+p+""),
				trVectorQuestVarGetZ("TargetVector"+p+""), 0, true);
			*/
			//trVectorQuestVarEcho("TargetVector"+p+"");
			int xPos = (trVectorQuestVarGetX("TargetVector"+p+"") ) / 8 +1;
			int zPos = (trVectorQuestVarGetZ("TargetVector"+p+"") ) / 8 +1;
			trQuestVarSet("P"+p+"DrillTargetX", xPos*8+1);
			trQuestVarSet("P"+p+"DrillTargetZ", zPos*8+1);
			/*
			trQuestVarEcho("p"+p+"lureObject");
			trChatSend(0, "TARGET "+xPos+" is COL");
			trChatSend(0, "TARGET "+zPos+" is ROW");
			trChatSend(0, "START "+startXPos+" is COL");
			trChatSend(0, "START "+startZPos+" is ROW");
			*/
			
			//SET APPROACH DIRECTION
			if(zPos > startZPos){
				trQuestVarSet("P"+p+"Approach", 1);
				//drill up
			}
			else if(zPos < startZPos){
				trQuestVarSet("P"+p+"Approach", 2);
				//drill down
			}
			if(xPos < startXPos){
				trQuestVarSet("P"+p+"Approach", 3);
				//drill left
			}
			else if(xPos > startXPos){
				trQuestVarSet("P"+p+"Approach", 4);
				//right
			}
			
			// DISTANCE <111 IS OK TO DRILL
			
			//Terrain check fails
			if(Stage == 1){
				if((trGetTerrainSubType(1*trQuestVarGet("P"+p+"DrillTargetX")/2-1,
							1*trQuestVarGet("P"+p+"DrillTargetZ")/2-1) == 2) && (trGetTerrainType(1*trQuestVarGet("P"+p+"DrillTargetX")/2-1,
							1*trQuestVarGet("P"+p+"DrillTargetZ")/2-1) == 5)){
					trChatSendToPlayer(0, p, "<color=1,0,0>The ice is too hard for you to drill!</color>");
					if(trCurrentPlayer() == p){
						trSoundPlayFN("cantdothat.wav","1",-1,"","");
					}
					trTechGodPower(p, "Animal Magnetism", 1);
					break;
				}
				if((trGetTerrainSubType(1*trQuestVarGet("P"+p+"DrillTargetX")/2-1,
							1*trQuestVarGet("P"+p+"DrillTargetZ")/2-1) == 10) && (trGetTerrainType(1*trQuestVarGet("P"+p+"DrillTargetX")/2-1,
							1*trQuestVarGet("P"+p+"DrillTargetZ")/2-1) == 2)){
					trChatSendToPlayer(0, p, "<color=1,0,0>Bad idea to drill into the lava...</color>");
					if(trCurrentPlayer() == p){
						trSoundPlayFN("cantdothat.wav","1",-1,"","");
					}
					trTechGodPower(p, "Animal Magnetism", 1);
					break;
				}
			}
			if((trGetTerrainSubType(1*trQuestVarGet("P"+p+"DrillTargetX")/2-1,
						1*trQuestVarGet("P"+p+"DrillTargetZ")/2-1) == 3) && (trGetTerrainType(1*trQuestVarGet("P"+p+"DrillTargetX")/2-1,
						1*trQuestVarGet("P"+p+"DrillTargetZ")/2-1) == 5)){
				trChatSendToPlayer(0, p, "<color=1,0,0>This spot has already been drilled!</color>");
				if(trCurrentPlayer() == p){
					trSoundPlayFN("cantdothat.wav","1",-1,"","");
				}
				trTechGodPower(p, "Animal Magnetism", 1);
				break;
			}
			else if(zPos > MaxRows){
				trChatSendToPlayer(0, p, "<color=1,0,0>You can't drill above ground!</color>");
				if(trCurrentPlayer() == p){
					trSoundPlayFN("cantdothat.wav","1",-1,"","");
				}
				trTechGodPower(p, "Animal Magnetism", 1);
				break;
			}
			else if(trDistanceToVectorSquared("P"+p+"Siphon", "TargetVector"+p+"") > 111){
				trChatSendToPlayer(0, p,
					"<color=1,0,0>Drill request too far!</color>  "+trDistanceToVectorSquared("P"+p+"Siphon", "TargetVector"+p+"")+"");
				if(trCurrentPlayer() == p){
					trSoundPlayFN("cantdothat.wav","1",-1,"","");
				}
				trTechGodPower(p, "Animal Magnetism", 1);
				break;
			}
			//Stop diagonal drills
			else if((startXPos != xPos) && (startZPos != zPos)){
				trChatSendToPlayer(0, p, "<color=1,0,0>Diagonal drilling not allowed!</color>");
				if(trCurrentPlayer() == p){
					trSoundPlayFN("cantdothat.wav","1",-1,"","");
				}
				trTechGodPower(p, "Animal Magnetism", 1);
				break;
			}
			else if((startXPos == xPos) || (startZPos == zPos)){
				//SUCCEESSFUL DRILL
				if(zPos > startZPos){
					trQuestVarSet("P"+p+"Approach", 1);
					/*trUnitSelectClear();
					trUnitSelectByQV("R"+startZPos+"C"+xPos+"WallX");
					trUnitDestroy();*/
					//	trQuestVarEcho("R"+startZPos+"C"+xPos+"WallX");
					if (zPos == 20){
						trUnitSelectClear();
						trUnitSelectByQV("R"+zPos+"C"+xPos+"WallX");
						trUnitDestroy();
						//destroy top wall
					}
					//drill up
				}
				else if(zPos < startZPos){
					trQuestVarSet("P"+p+"Approach", 2);
					/*trUnitSelectClear();
					trUnitSelectByQV("R"+zPos+"C"+xPos+"WallX");
					trUnitDestroy();*/
					//trQuestVarEcho("R"+zPos+"C"+xPos+"WallX");
					//drill down
					if (zPos == 20){
						trUnitSelectClear();
						trUnitSelectByQV("R"+zPos+"C"+xPos+"WallX");
						trUnitDestroy();
						//destroy top wall
					}
				}
				if(xPos < startXPos){
					trQuestVarSet("P"+p+"Approach", 3);
					/*trUnitSelectClear();
					trUnitSelectByQV("R"+zPos+"C"+xPos+"WallY");
					trUnitDestroy();*/
					//trQuestVarEcho("R"+zPos+"C"+xPos+"WallY");
					//drill left
				}
				else if(xPos > startXPos){
					trQuestVarSet("P"+p+"Approach", 4);
					/*trUnitSelectClear();
					trUnitSelectByQV("R"+zPos+"C"+startXPos+"WallY");
					trUnitDestroy();*/
					//trQuestVarEcho("R"+zPos+"C"+startXPos+"WallY");
					//right
				}
				//trChatSend(0, "DIST "+trDistanceToVectorSquared("P"+p+"Siphon", "TargetVector"+p+"")+" OK");
				//trQuestVarEcho("P"+p+"MainSpy");
				HideRelics(p);
				//trUnitSelectClear();
				//trUnitSelectByQV("P"+p+"MainSpy", true);
				//trMutateSelected(kbGetProtoUnitID("Heka Shockwave SFX"));
				trArmyDispatch(""+p+",0", "Revealer", 1, trVectorQuestVarGetX("SiphonPos"+p+""), trVectorQuestVarGetY("SiphonPos"+p+""),
					trVectorQuestVarGetZ("SiphonPos"+p+""), 180, true);
				trUnitSelectClear();
				trUnitSelectByQV("P"+p+"Siphon", false);
				trUnitTeleport(startXPos, 3, startZPos);
				trQuestVarSet("DrillAttach"+p+"", trGetNextUnitScenarioNameNumber());
				trArmyDispatch(""+p+",0", "Victory Marker", 1, trVectorQuestVarGetX("SiphonPos"+p+""), trVectorQuestVarGetY("SiphonPos"+p+""),
					trVectorQuestVarGetZ("SiphonPos"+p+""), 180, true);
				trUnitSelectClear();
				trUnitSelectByQV("P"+p+"Siphon", false);
				trMutateSelected(kbGetProtoUnitID("Relic"));
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
				trMutateSelected(kbGetProtoUnitID("Heka Shockwave SFX"));
				trUnitOverrideAnimation(1, 0, true, false, -1, 0);
				trUnitSelectClear();
				trUnitSelectByQV("DrillAttach"+p+"", true);
				trMutateSelected(kbGetProtoUnitID("Wadjet Spit"));
				//DRILL SPEED
				xSetPointer(dPlayerData, p);
				SetDrillSpeed(p, 1*trQuestVarGet("P"+p+"DrillTargetX")/2-1, 1*trQuestVarGet("P"+p+"DrillTargetZ")/2-1);
				trUnitSelectClear();
				trUnitSelectByQV("DrillAttach"+p+"", true);
				trUnitMoveToVectorEvent("TargetVector"+p+"", false, p);
				trQuestVarSet("P"+p+"Drilling", 19);
				//10 seems to be lowest value here
			}
		}
		else {
			trQuestVarSet("p"+p+"LureObject", trGetNextUnitScenarioNameNumber() - 1);
		}
	}
}

void UngarrisonDrill(int p = 1){
	int zPos = 0;
	int xPos = 0;
	trUnitSelectByQV("P"+p+"Siphon", false);
	//trUnitEjectContained();
	trUnitChangeProtoUnit("Hero Greek Atalanta");
	trUnitSelectClear();
	trUnitSelectByQV("DrillAttach"+p+"", true);
	trUnitDestroy();
	trUnitSelectClear();
	//trMutateSelected(kbGetProtoUnitID("Hero Greek Atalanta"));
	//garrison relics
	trTechGodPower(p, "Animal Magnetism", 1);
	trVectorSetUnitPos("SiphonPos"+p+"", "P"+p+"Siphon");
	trVectorSnapToGrid("SiphonPos"+p+"");
	trArmyDispatch(""+p+",0", "Revealer", 1, 1*trQuestVarGet("P"+p+"DrillTargetX"), 1,
		1*trQuestVarGet("P"+p+"DrillTargetZ"), 180, true);
	//trUnitSelectClear();
	//trUnitSelectByQV("P"+p+"MainSpy", true);
	//trMutateSelected(kbGetProtoUnitID("Fire Siphon"));
	//BUG** If terrain updates the vectors don't update for position and the unit dies on 2nd attempt
	//RESOLVED** unit must have valid ungarrison position but change fixes this anyway
	trPaintTerrain(1*trQuestVarGet("P"+p+"DrillTargetX")/2-3,1*trQuestVarGet("P"+p+"DrillTargetZ")/2-3,
		1*trQuestVarGet("P"+p+"DrillTargetX")/2-1,1*trQuestVarGet("P"+p+"DrillTargetZ")/2-1,5,3,false);
	//This paints the black area around the square depending on entry point
	/*
	if(1*trQuestVarGet("P"+p+"Approach") == 1){
		trPaintTerrain(1*trQuestVarGet("P"+p+"DrillTargetX")/2-3,1*trQuestVarGet("P"+p+"DrillTargetZ")/2-4,
			1*trQuestVarGet("P"+p+"DrillTargetX")/2-1,1*trQuestVarGet("P"+p+"DrillTargetZ")/2-1,5,3,false);
	}
	else if(1*trQuestVarGet("P"+p+"Approach") == 2){
		trPaintTerrain(1*trQuestVarGet("P"+p+"DrillTargetX")/2-3,1*trQuestVarGet("P"+p+"DrillTargetZ")/2-3,
			1*trQuestVarGet("P"+p+"DrillTargetX")/2-1,1*trQuestVarGet("P"+p+"DrillTargetZ")/2,5,3,false);
	}
	else if(1*trQuestVarGet("P"+p+"Approach") == 3){
		trPaintTerrain(1*trQuestVarGet("P"+p+"DrillTargetX")/2-3,1*trQuestVarGet("P"+p+"DrillTargetZ")/2-3,
			1*trQuestVarGet("P"+p+"DrillTargetX")/2,1*trQuestVarGet("P"+p+"DrillTargetZ")/2-1,5,3,false);
	}
	else if(1*trQuestVarGet("P"+p+"Approach") == 4){
		trPaintTerrain(1*trQuestVarGet("P"+p+"DrillTargetX")/2-4,1*trQuestVarGet("P"+p+"DrillTargetZ")/2-3,
			1*trQuestVarGet("P"+p+"DrillTargetX")/2-1,1*trQuestVarGet("P"+p+"DrillTargetZ")/2-1,5,3,false);
	}
	*/
	//IMPROVED - this checked and removes any connecting walls after a drill
	//upwards
	//paint from up
	if((trGetTerrainSubType(1*trQuestVarGet("P"+p+"DrillTargetX")/2-1,
				1*trQuestVarGet("P"+p+"DrillTargetZ")/2+3) == 3) && (trGetTerrainType(1*trQuestVarGet("P"+p+"DrillTargetX")/2-1,
				1*trQuestVarGet("P"+p+"DrillTargetZ")/2+3) == 5)){
		trPaintTerrain(1*trQuestVarGet("P"+p+"DrillTargetX")/2-3,1*trQuestVarGet("P"+p+"DrillTargetZ")/2+1,
			1*trQuestVarGet("P"+p+"DrillTargetX")/2-1,1*trQuestVarGet("P"+p+"DrillTargetZ")/2,5,3,false);
		if((trGetTerrainSubType(1*trQuestVarGet("P"+p+"DrillTargetX")/2-1,
					1*trQuestVarGet("P"+p+"DrillTargetZ")/2-5) == 3) && (trGetTerrainType(1*trQuestVarGet("P"+p+"DrillTargetX")/2-1,
					1*trQuestVarGet("P"+p+"DrillTargetZ")/2-5) == 5)){
		}
	}
	if((trGetTerrainSubType(1*trQuestVarGet("P"+p+"DrillTargetX")/2-1,
				1*trQuestVarGet("P"+p+"DrillTargetZ")/2-5) == 3) && (trGetTerrainType(1*trQuestVarGet("P"+p+"DrillTargetX")/2-1,
				1*trQuestVarGet("P"+p+"DrillTargetZ")/2-5) == 5)){
		trPaintTerrain(1*trQuestVarGet("P"+p+"DrillTargetX")/2-3,1*trQuestVarGet("P"+p+"DrillTargetZ")/2-4,
			1*trQuestVarGet("P"+p+"DrillTargetX")/2-1,1*trQuestVarGet("P"+p+"DrillTargetZ")/2-1,5,3,false);
	}
	
	//paint from left
	if((trGetTerrainSubType(1*trQuestVarGet("P"+p+"DrillTargetX")/2-5,
				1*trQuestVarGet("P"+p+"DrillTargetZ")/2-1) == 3) && (trGetTerrainType(1*trQuestVarGet("P"+p+"DrillTargetX")/2-5,
				1*trQuestVarGet("P"+p+"DrillTargetZ")/2-1) == 5)){
		trPaintTerrain(1*trQuestVarGet("P"+p+"DrillTargetX")/2-4,1*trQuestVarGet("P"+p+"DrillTargetZ")/2-3,
			1*trQuestVarGet("P"+p+"DrillTargetX")/2-1,1*trQuestVarGet("P"+p+"DrillTargetZ")/2-1,5,3,false);
	}
	//paint from right
	if((trGetTerrainSubType(1*trQuestVarGet("P"+p+"DrillTargetX")/2+3,
				1*trQuestVarGet("P"+p+"DrillTargetZ")/2-1) == 3) && (trGetTerrainType(1*trQuestVarGet("P"+p+"DrillTargetX")/2+3,
				1*trQuestVarGet("P"+p+"DrillTargetZ")/2-1) == 5)){
		trPaintTerrain(1*trQuestVarGet("P"+p+"DrillTargetX")/2-3,1*trQuestVarGet("P"+p+"DrillTargetZ")/2-3,
			1*trQuestVarGet("P"+p+"DrillTargetX")/2,1*trQuestVarGet("P"+p+"DrillTargetZ")/2-1,5,3,false);
	}
	//wall destruction post drilling
	zPos = 1*((trQuestVarGet("P"+p+"DrillTargetZ")-1)/8);
	xPos = 1*((trQuestVarGet("P"+p+"DrillTargetX")-1)/8);
	//trPaintTerrain((xPos)*4-2,(zPos)*4-2,(xPos)*4-2,(zPos)*4-2,2,2, false);
	if((trGetTerrainSubType((xPos)*4-2,(zPos)*4+2) == 3) && (trGetTerrainType((xPos)*4-2,
				(zPos)*4+2) == 5)){
		//trChatSend(0, "X = "+xPos+" Z = "+zPos+"");
		trUnitSelectByQV("R"+zPos+"C"+xPos+"WallX");
		trUnitChangeProtoUnit("Heka Shockwave SFX");
	}
	if((trGetTerrainSubType((xPos)*4-2,(zPos)*4+2) == OVERTERRAIN_SUBTYPE) && (trGetTerrainType((xPos)*4-2,
				(zPos)*4+2) == OVERTERRAIN_TYPE)){
		//trChatSend(0, "X = "+xPos+" Z = "+zPos+"");
		trUnitSelectByQV("R"+zPos+"C"+xPos+"WallX");
		trUnitChangeProtoUnit("Heka Shockwave SFX");
	}
	//*ADD*DESTROY TOP WALL WHEN TUNNELING UNDER *** THIS NEEDS TO DETECT BASE PLANET TERRAIN
	if((trGetTerrainSubType((xPos)*4-2,(zPos)*4+2) == 1) && (trGetTerrainType((xPos)*4-2,
				(zPos)*4+2) == 0)){
		//trChatSend(0, "X = "+xPos+" Z = "+zPos+"");
		trUnitSelectByQV("R"+zPos+"C"+xPos+"WallX");
		trUnitChangeProtoUnit("Heka Shockwave SFX");
	}
	if((trGetTerrainSubType((xPos)*4-2,(zPos)*4-6) == 3) && (trGetTerrainType((xPos)*4-2,
				(zPos)*4-6) == 5)){
		trUnitSelectByQV("R"+(zPos-1)+"C"+xPos+"WallX");
		trUnitChangeProtoUnit("Heka Shockwave SFX");
	}
	
	if((trGetTerrainSubType((xPos)*4+2,(zPos)*4-2) == 3) && (trGetTerrainType((xPos)*4+2,
				(zPos)*4-2) == 5)){
		trUnitSelectByQV("R"+zPos+"C"+xPos+"WallY");
		trUnitChangeProtoUnit("Heka Shockwave SFX");
	}
	if((trGetTerrainSubType((xPos)*4-6,(zPos)*4-2) == 3) && (trGetTerrainType((xPos)*4-6,
				(zPos)*4-2) == 5)){
		trUnitSelectByQV("R"+zPos+"C"+(xPos-1)+"WallY");
		trUnitChangeProtoUnit("Heka Shockwave SFX");
	}
	
	//trPaintTerrain(0,0,0,0,0,0, true);
	trQuestVarSet("P"+p+"Approach", 0);
	trQuestVarSet("P"+p+"Drilling", 1);
	xsDisableSelf();
	//snap
	trUnitSelectByQV("P"+p+"Siphon", false);
	trUnitTeleport(xPos*8-3,3,zPos*8-3);
	trUnitSelectByQV("P"+p+"Siphon", false);
	trUnitSetAnimation("Idle");
	ReturnRelics(p);
	xSetPointer(dPlayerData, p);
	trUnitSelectClear();
	trUnitSelectByQV("P"+p+"Siphon");
	if(trUnitGetContained() < xGetInt(dPlayerData, xCargoHold)){
		for(x=xGetDatabaseCount(dFreeRelics); >0) {
			xDatabaseNext(dFreeRelics);
			//VECTOR FROM TARGET NOT DESTINATION
			if(unitDistanceToQVVector(xGetInt(dFreeRelics, xRelicName), "P"+p+"Pos", true) < 10){
				xUnitSelect(dFreeRelics,xRelicName);
				trImmediateUnitGarrison(""+(1*trQuestVarGet("P"+p+"Siphon"))+"");
				break;
			}
		}
	}
	//var x = trQuestVarGet("p"+p+"drillTargetX") / 2 //VAR MAKES IT TRANSFER BETWEEN EFFECTS
}
