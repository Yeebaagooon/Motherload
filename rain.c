/* lure ability */

rule EventSetHandler
active
highFrequency
{
	for(p = 1; <= cNumberNonGaiaPlayers){
		trEventSetHandler(p, "UngarrisonDrill");
		trEventSetHandler(13+p, "SellMinerals");
	}
	trEventSetHandler(13, "CustomContent");
	//reserved to 24
	xsDisableSelf();
}

void CustomContent(int p = 0){
	xsDisableSelf();
	trQuestVarSet("CustomContent", 1);
	trChatSend(0, "Custom Content enabled!");
}

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
				trMutateSelected(kbGetProtoUnitID("Fire Siphon"));
				trUnitOverrideAnimation(1, 0, true, false, -1, 0);
				trUnitSelectClear();
				trUnitSelectByQV("DrillAttach"+p+"", true);
				trMutateSelected(kbGetProtoUnitID("Wadjet Spit"));
				//DRILL SPEED
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
	//var x = trQuestVarGet("p"+p+"drillTargetX") / 2 //VAR MAKES IT TRANSFER BETWEEN EFFECTS
}

rule squarespaint
inactive
highFrequency
{
	if((trTime()-cActivationTime) >= 1){
		//trPaintTerrain(0,0,4*col+4,4*row+4,2,13,false);
		trPaintTerrain(0,0,4*MaxCols,4*MaxRows,2,13,false);
		GroundType(Stage);
		trPaintTerrain(0,4*MaxRows+1,200,200,OVERTERRAIN_TYPE,OVERTERRAIN_SUBTYPE,false); //paints the land above the dig area
		for(col = 1; <= MaxCols){
			for(row = 1; <= MaxRows){
				trQuestVarSet("R"+row+"C"+col+"WallX", 1*trGetNextUnitScenarioNameNumber());
				UnitCreate(cNumberNonGaiaPlayers, "Victory Marker", 8*col-4, 8*row, 0);
				trQuestVarSet("R"+row+"C"+col+"WallY", 1*trGetNextUnitScenarioNameNumber());
				UnitCreate(cNumberNonGaiaPlayers, "Victory Marker", 8*col, 8*row-4, 90);
				if(Stage == 1){
					if((col > 5) && (col < 20)){
						if(row > 18){
							RockType(1);
						}
						else if((row > 15) && (row <= 18 )){
							trQuestVarSetFromRand("Temp",1,2,true);
							RockType(1*trQuestVarGet("Temp"));
						}
						else if((row > 13) && (row <= 15 )){
							trQuestVarSetFromRand("Temp",1,3,true);
							if(trQuestVarGet("Temp") == 3){
								trQuestVarModify("Temp", "-", 1);
							}
							RockType(1*trQuestVarGet("Temp"));
						}
						else if((row > 10) && (row <= 13 )){
							trQuestVarSetFromRand("Temp",2,4,true);
							if(trQuestVarGet("Temp") == 4){
								trQuestVarModify("Temp", "-", 1);
							}
							RockType(1*trQuestVarGet("Temp"));
						}
						else if((row > 7) && (row <= 10 )){
							trQuestVarSetFromRand("Temp",2,4,true);
							if(trQuestVarGet("Temp") == 2){
								trQuestVarModify("Temp", "+", 1);
							}
							RockType(1*trQuestVarGet("Temp"));
						}
						else if((row > 5) && (row <= 7 )){
							trQuestVarSetFromRand("Temp",3,4,true);
							RockType(1*trQuestVarGet("Temp"));
						}
						else if((row > 2) && (row <= 5 )){
							trQuestVarSetFromRand("Temp",4,7,true);
							if(trQuestVarGet("Temp") != 4){
								trQuestVarSet("Temp", 5);
							}
							RockType(1*trQuestVarGet("Temp"));
						}
						else if(row <= 2 ){
							RockType(5);
						}
					}
					if(col >= 20){
						RockType(8);
					}
					if(col <= 5){
						RockType(9);
					}
				}
				trPaintTerrain(4*col-1,4*row-1,4*col-3,4*row-3,TERRAIN_TYPE,TERRAIN_SUBTYPE,false);
				trQuestVarSet("R"+row+"C"+col+"CentreY", row*4-2);
				trQuestVarSet("R"+row+"C"+col+"CentreX", col*4-2);
				//trVectorQuestVarSet("R"+row+"C"+col+"", xsVectorSet(col*8-3, 3, row*8-3));
				//trQuestVarSet("R"+row+"C"+col+"Drilled", 0);
				//trQuestVarSet("R"+row+"C"+col+"HP", 0);
			}
		}
		/*
		trQuestVarEcho("R4C3CentreX");
		trQuestVarEcho("R4C3CentreY");
		trVectorQuestVarEcho("R4C3");
		trPaintTerrain(1*trQuestVarGet("R4C3CentreX"),
			1*trQuestVarGet("R4C3CentreY"),1*trQuestVarGet("R4C3CentreX"),
			1*trQuestVarGet("R4C3CentreY"),2,2,false);
		*/
		xsDisableSelf();
		trPaintTerrain(0,80,100,80,5,3,false);
		xsEnableRule("PaintLoot");
		xsEnableRule("PainSmeltShop");
		//UnitCreate(0, "Hoplite", 20, 180, 180);
	}
}

rule PainSmeltShop
inactive
highFrequency
{
	PaintSmelter(20,180);
	PainSellTerrain(15,89);
	GVectorSellPos = vector(38,3,176);
	xsDisableSelf();
}

rule PaintLoot
inactive
highFrequency
{
	xsDisableSelf();
	for(col = 1; <= MaxCols){
		for(row = 1; <= MaxRows){
			vector v = xsVectorSet(col*8-4,0,row*8-4);
			if(Stage == 1){
				if((col > 5) && (col < 20)){
					if(row > 16){
						trQuestVarSetFromRand("Temp",1,15);
						if(1*trQuestVarGet("Temp") <= cNumberNonGaiaPlayers){
							spawnRelicSpecific(v,1);
						}
					}
					else if((row > 10) && (row <= 16)){
						trQuestVarSetFromRand("Temp",1,15);
						trQuestVarSetFromRand("Temp2",1,2);
						if(1*trQuestVarGet("Temp") <= cNumberNonGaiaPlayers){
							spawnRelicSpecific(v,1*trQuestVarGet("Temp2"));
						}
					}
					else if((row > 6) && (row <= 10)){
						trQuestVarSetFromRand("Temp",1,15);
						trQuestVarSetFromRand("Temp2",1,3);
						if(1*trQuestVarGet("Temp") <= cNumberNonGaiaPlayers){
							spawnRelicSpecific(v,1*trQuestVarGet("Temp2"));
						}
					}
					else if((row > 3) && (row <= 6)){
						trQuestVarSetFromRand("Temp",1,15);
						trQuestVarSetFromRand("Temp2",2,3);
						if(1*trQuestVarGet("Temp") <= cNumberNonGaiaPlayers){
							spawnRelicSpecific(v,1*trQuestVarGet("Temp2"));
						}
					}
					else if(row <= 3){
						trQuestVarSetFromRand("Temp",1,15);
						trQuestVarSetFromRand("Temp2",2,4);
						if(1*trQuestVarGet("Temp") <= cNumberNonGaiaPlayers){
							spawnRelicSpecific(v,1*trQuestVarGet("Temp2"));
						}
					}
				}
			}
		}
	}
	xsEnableRule("WallUp");
}

rule WallUp
inactive
highFrequency
{
	for(col = 1; <= MaxCols){
		for(row = 1; <= MaxRows){
			trUnitSelectByQV("R"+row+"C"+col+"WallX");
			trUnitChangeProtoUnit("Invisible Wall");
			trUnitSelectByQV("R"+row+"C"+col+"WallY");
			trUnitChangeProtoUnit("Invisible Wall");
		}
	}
	xsDisableSelf();
}

rule TEMPdeployP1
inactive
highFrequency
{
	if((trTime()-cActivationTime) >= 2){
		for(p = 1; < cNumberNonGaiaPlayers){
			trQuestVarSet("P"+p+"Siphon", trGetNextUnitScenarioNameNumber());
			//VECTOR IS 2X+1
			UnitCreate(p, "Hero Greek Atalanta", 75+5*p, 180, 180);
			yAddToDatabase("Siphon"+p+"", "P"+p+"Siphon");
			trPlayerSetDiplomacy(0, p, "Enemy");
			trUnitSelectClear();
			trUnitSelectByQV("P"+p+"Siphon", false);
			trQuestVarSet("P"+p+"MainSpy", trGetNextUnitScenarioNameNumber());
			trTechInvokeGodPower(0, "spy", vector(0,0,0), vector(0,0,0));
			//trDelayedRuleActivation("ChangeMainSpy1");
			//trPaintTerrain(0,0,0,0,0,0, true);
		}
		xsDisableSelf();
		trShowImageDialog(stageIcon(Stage), stageName(Stage));
		/*
		trQuestVarSet("P1EnginePower", 100);
		trQuestVarSet("P1Radiator", 0.1);
		xsEnableRule("TEMPfuel");
		*/
	}
}


rule TEMPfuel
inactive
highFrequency
//CHANGE condition to distance not time
{
	for(p = 1; <= cNumberNonGaiaPlayers){
		if(trDistanceToVectorSquared("P"+p+"Siphon", "P"+p+"Pos") > 0){
			trVectorSetUnitPos("P"+p+"Pos", "P"+p+"Siphon");
			//Disable surface penalty
			if((trVectorQuestVarGetZ("P"+p+"Pos")) > MaxRows*8){
				trPlayerGrantResources(p, "Gold", 0);
				trQuestVarSet("P"+p+"Depth", 0);
			}
			else{
				FuelLoss(p);
				trQuestVarSet("P"+p+"Depth", (MaxRows*8-1*trVectorQuestVarGetZ("P"+p+"Pos"))*10);
			}
		}
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
