//	if((trGetTerrainSubType(col*4-2,row*4-2) != 13) && (trGetTerrainType(col*4-2,row*4-2) != 2)){
//Doesnt stop black rock from being blown up ... wtf

void MineSquare(int row = 0, int col = 0){
	trPaintTerrain(col*4-3,row*4-3,col*4-1,row*4-1,MineT, MineST,false);
	trArmyDispatch("0,0", "Revealer", 1, col*8-4, 1, row*8-4, 180, true);
	//Blow up gas pocket
	for (x= xGetDatabaseCount(dGasPocket); > 0) {
		xDatabaseNext(dGasPocket);
		if((xGetInt(dGasPocket, xGasCol) == col) && (xGetInt(dGasPocket, xGasRow) == row)){
			trVectorQuestVarSet("TempGas", xsVectorSet(8*xGetInt(dGasPocket, xGasCol)-4,3,8*xGetInt(dGasPocket, xGasRow)-4));
			int temp = trGetNextUnitScenarioNameNumber();
			trArmyDispatch("0,0", "Dwarf", 1, 1,1,1, 0, true);
			trUnitSelectClear();
			trUnitSelect(""+temp);
			trUnitSelectClear();
			trUnitSelect(""+temp);
			trUnitTeleport(trVectorQuestVarGetX("TempGas"),trVectorQuestVarGetY("TempGas"),trVectorQuestVarGetZ("TempGas"));
			trMutateSelected(kbGetProtoUnitID("Harpy"));
			trUnitSelectClear();
			trUnitSelect(""+temp);
			trSetSelectedHeight(-10.0);
			trUnitSelectClear();
			trUnitSelect(""+temp);
			trSetSelectedScale(0,0,0);
			trUnitSelectClear();
			trUnitSelect(""+temp);
			trUnitOverrideAnimation(1,0,false,true,-1,-1);
			xFreeDatabaseBlock(dGasPocket);
			trUnitSelectClear();
			trUnitSelect(""+temp);
			xAddDatabaseBlock(dDestroyMe, true);
			xSetInt(dDestroyMe, xDestroyName, temp);
			xSetInt(dDestroyMe, xDestroyTime, trTimeMS()+1500);
		}
	}
}

void RemoveBlack(int row = 0, int col = 0){
	int rowmid = row*4-2;
	int colmid = col*4-2;
	//Wall above
	if(row <= MaxRows){
		if((trGetTerrainSubType((colmid),(rowmid)+4) == MineST) && (trGetTerrainType((colmid),(rowmid)+4) == MineT)){
			trUnitSelectClear();
			trPaintTerrain(col*4-3,row*4-3,col*4-1,row*4,MineT, MineST,false);
			trUnitSelectByQV("R"+row+"C"+col+"WallX");
			trUnitChangeProtoUnit("Meteor Impact Ground");
			trUnitSelectClear();
			trUnitSelectByQV("R"+row+"C"+col+"WallX");
			trUnitDestroy();
			//correct wall but not top layer because terrain above isnt overworld
		}
		if((trGetTerrainSubType((colmid),(rowmid)+4) == OVERTERRAIN_SUBTYPE) && (trGetTerrainType((colmid),(rowmid)+4) == OVERTERRAIN_TYPE)){
			trUnitSelectClear();
			trUnitSelectByQV("R"+row+"C"+col+"WallX");
			trUnitChangeProtoUnit("Meteor Impact Ground");
			trUnitSelectClear();
			trUnitSelectByQV("R"+row+"C"+col+"WallX");
			trUnitDestroy();
		}
		//Wall below
		if((trGetTerrainSubType((colmid),(rowmid)-4) == MineST) && (trGetTerrainType((colmid),(rowmid)-4) == MineT)){
			trPaintTerrain(col*4-3,row*4-4,col*4-1,row*4-1,MineT, MineST,false);
			trUnitSelectClear();
			trUnitSelectByQV("R"+(row-1)+"C"+col+"WallX");
			trUnitChangeProtoUnit("Meteor Impact Ground");
			trUnitSelectClear();
			trUnitSelectByQV("R"+(row-1)+"C"+col+"WallX");
			trUnitDestroy();
			//correct wall but not top layer because terrain above isnt overworld
		}
		if((trGetTerrainSubType((colmid)+4,(rowmid)) == MineST) && (trGetTerrainType((colmid)+4,(rowmid)) == MineT)){
			trPaintTerrain(col*4-3,row*4-3,col*4,row*4-1,MineT, MineST,false);
			trUnitSelectClear();
			trUnitSelectByQV("R"+row+"C"+col+"WallY");
			trUnitChangeProtoUnit("Meteor Impact Ground");
			trUnitSelectClear();
			trUnitSelectByQV("R"+row+"C"+col+"WallY");
			trUnitDestroy();
		}
		if((trGetTerrainSubType((colmid)-4,(rowmid)) == MineST) && (trGetTerrainType((colmid)-4,(rowmid)) == MineT)){
			trPaintTerrain(col*4-4,row*4-3,col*4-1,row*4-1,MineT, MineST,false);
			trUnitSelectClear();
			trUnitSelectByQV("R"+row+"C"+(col-1)+"WallY");
			trUnitChangeProtoUnit("Meteor Impact Ground");
			trUnitSelectClear();
			trUnitSelectByQV("R"+row+"C"+(col-1)+"WallY");
			trUnitDestroy();
		}
	}
	trPaintTerrain(0,4*MaxRows+1,200,4*MaxRows+5,OVERTERRAIN_TYPE,OVERTERRAIN_SUBTYPE,false);
}

rule Rain
inactive
highFrequency
{
	for(p = 1; <= cNumberNonGaiaPlayers){
		if(trCheckGPActive("Rain", p)){
			if(trTime() > 1*trQuestVarGet("P"+p+"RainTime")){
				trUnitSelectClear();
				trUnitSelectByQV("P"+p+"Siphon");
				trMutateSelected(kbGetUnitBaseTypeID(kbGetBlockID(""+1*trQuestVarGet("P"+p+"Siphon"))));
				trUnitTeleport(150,0,190);
				trQuestVarSet("P"+p+"RainTime", trTime()+2);
				if(trCurrentPlayer() == p){
					trOverlayText("Emergency surface teleport!", 4, -1,-1,-1);
					uiZoomToProto("Hero Greek Atalanta");
					trCameraCut(vector(107.841461,153.803818,55.919525), vector(0.001486,-0.784815,0.619728), vector(0.001882,0.619729,0.784813), vector(0.999997,0.000000,-0.002398));
				}
			}
		}
	}
}

rule Ragnorok
inactive
highFrequency
{
	for(p = 1; <= cNumberNonGaiaPlayers){
		if(trCheckGPActive("Ragnorok", p)){
			if(trTime() > 1*trQuestVarGet("P"+p+"RagnorokTime")){
				xSetPointer(dPlayerData, p);
				spyEffect(1*trQuestVarGet("P"+p+"Siphon"), kbGetProtoUnitID("Mountain Giant"), vector(0,0,0), vector(0,0,0), 18);
				xSetFloat(dPlayerData, xFuel, xGetFloat(dPlayerData, xFuel)+200);
				trQuestVarSet("P"+p+"RagnorokTime", trTime()+2);
				if(xGetFloat(dPlayerData, xFuel) > xGetInt(dPlayerData,xFuelTank)){
					xSetFloat(dPlayerData, xFuel, xGetInt(dPlayerData, xFuelTank));
				}
				if(trCurrentPlayer() == p){
					trOverlayText("Backup fuel tank used!", 4, -1,-1,-1);
				}
			}
		}
	}
}

rule Audrey
inactive
highFrequency
{
	for(p = 1; <= cNumberNonGaiaPlayers){
		if (trPlayerUnitCountSpecific(p, "Audrey") == 1) {
			yFindLatestReverse("p"+p+"DragonObject", "Audrey", p);
			trVectorSetUnitPos("BombVector"+p+"", "p"+p+"DragonObject", true);
			trMutateSelected(kbGetProtoUnitID("Rocket"));
			yFindLatestReverse("p"+p+"Effect", "Audrey Base", p);
			trVectorSnapToGrid("BombVector"+p+"");
			int Col = (trVectorQuestVarGetX("BombVector"+p+"") ) / 8 +1;
			int Row = (trVectorQuestVarGetZ("BombVector"+p+"") ) / 8 +1;
			//trChatSend(0, "TRow" + Row);
			//trChatSend(0, "TCol" + Col);
			trVectorSetUnitPos("SiphonPos"+p+"", "P"+p+"Siphon");
			trVectorSnapToGrid("SiphonPos"+p+"");
			int startCol = (trVectorQuestVarGetX("SiphonPos"+p+"") ) / 8 +1;
			int startRow = (trVectorQuestVarGetZ("SiphonPos"+p+"") ) / 8 +1;
			//trChatSend(0, "SRow" + startRow);
			//trChatSend(0, "SCol" + startCol);
			//VALIDITY CHECKS
			if(Row > MaxRows){
				trChatSendToPlayer(0, p, "<color=1,0,0>Cannot use dynamite here!</color>");
				if(trCurrentPlayer() == p){
					trSoundPlayFN("cantdothat.wav","1",-1,"","");
				}
				grantGodPowerNoRechargeNextPosition(p, "Audrey", 1);
				unitTransform("Audrey Base", "Rocket");
				break;
			}
			if((Row == startRow) && (Col == startCol)){
				trChatSendToPlayer(0, p, "<color=1,0,0>Dynamite error - no direction. Use adjacent to your ship.</color>");
				if(trCurrentPlayer() == p){
					trSoundPlayFN("cantdothat.wav","1",-1,"","");
				}
				grantGodPowerNoRechargeNextPosition(p, "Audrey", 1);
				unitTransform("Audrey Base", "Rocket");
				break;
			}
			//Direction calculate
			if(((xsMax(Row,startRow)-xsMin(Row,startRow) == 0) && (xsMax(Col,startCol)-xsMin(Col,startCol) == 1)) || ((xsMax(Row,startRow)-xsMin(Row,startRow) == 1) && (xsMax(Col,startCol)-xsMin(Col,startCol) == 0))){
				if(Row-startRow == 0){
					if((Col-startCol) == 1){
						MineSquare(Row, Col);
						MineSquare(Row, Col+1);
						RemoveBlack(Row, Col);
						RemoveBlack(Row, Col+1);
						RemoveBlack(Row, Col-1);
						trUnitSelectClear();
						trUnitSelectByQV("p"+p+"Effect");
						trUnitChangeProtoUnit("Meteorite");
						//trMutateSelected(kbGetProtoUnitID("Meteorite"));
						trUnitSelectClear();
						trUnitSelectByQV("p"+p+"Effect");
						trUnitOverrideAnimation(6,0,false,false,-1,-1);
						trUnitSelectClear();
						trUnitSelectByQV("p"+p+"Effect");
						trSetSelectedScale(0,0,0);
						trUnitSelectClear();
						trUnitSelectByQV("p"+p+"Effect");
						trSetSelectedUpVector(3,0,0);
					}
					if((Col-startCol) == -1){
						MineSquare(Row, Col);
						MineSquare(Row, Col-1);
						RemoveBlack(Row, Col);
						RemoveBlack(Row, Col-1);
						RemoveBlack(Row, Col+1);
						trUnitSelectClear();
						trUnitSelectByQV("p"+p+"Effect");
						trUnitChangeProtoUnit("Meteorite");
						//trMutateSelected(kbGetProtoUnitID("Meteorite"));
						trUnitSelectClear();
						trUnitSelectByQV("p"+p+"Effect");
						trUnitOverrideAnimation(6,0,false,false,-1,-1);
						trUnitSelectClear();
						trUnitSelectByQV("p"+p+"Effect");
						trSetSelectedScale(0,0,0);
						trUnitSelectClear();
						trUnitSelectByQV("p"+p+"Effect");
						trSetSelectedUpVector(-3,0,0);
					}
				}
				else if(Col-startCol == 0){
					if((Row-startRow) == 1){
						MineSquare(Row, Col);
						MineSquare(Row+1, Col);
						RemoveBlack(Row, Col);
						RemoveBlack(Row+1, Col);
						RemoveBlack(Row-1, Col);
						trUnitSelectClear();
						trUnitSelectByQV("p"+p+"Effect");
						trUnitChangeProtoUnit("Meteorite");
						//trMutateSelected(kbGetProtoUnitID("Meteorite"));
						trUnitSelectClear();
						trUnitSelectByQV("p"+p+"Effect");
						trUnitOverrideAnimation(6,0,false,false,-1,-1);
						trUnitSelectClear();
						trUnitSelectByQV("p"+p+"Effect");
						trSetSelectedScale(0,0,0);
						trUnitSelectClear();
						trUnitSelectByQV("p"+p+"Effect");
						trSetSelectedUpVector(0,0,3);
					}
					if((Row-startRow) == -1){
						MineSquare(Row, Col);
						MineSquare(Row+1, Col);
						RemoveBlack(Row, Col);
						RemoveBlack(Row-1, Col);
						RemoveBlack(Row+1, Col);
						trUnitSelectClear();
						trUnitSelectByQV("p"+p+"Effect");
						trUnitChangeProtoUnit("Meteorite");
						//trMutateSelected(kbGetProtoUnitID("Meteorite"));
						trUnitSelectClear();
						trUnitSelectByQV("p"+p+"Effect");
						trUnitOverrideAnimation(6,0,false,false,-1,-1);
						trUnitSelectClear();
						trUnitSelectByQV("p"+p+"Effect");
						trSetSelectedScale(0,0,0);
						trUnitSelectClear();
						trUnitSelectByQV("p"+p+"Effect");
						trSetSelectedUpVector(0,0,-3);
					}
				}
				break;
			}
			else{
				trChatSendToPlayer(0, p, "<color=1,0,0>Dynamite error - target too far. Use adjacent to your ship.</color>");
				if(trCurrentPlayer() == p){
					trSoundPlayFN("cantdothat.wav","1",-1,"","");
				}
				grantGodPowerNoRechargeNextPosition(p, "Audrey", 1);
				unitTransform("Audrey Base", "Rocket");
			}
		}
	}
}

rule AudreyL2
inactive
highFrequency
{
	for(p = 1; <= cNumberNonGaiaPlayers){
		if (trPlayerUnitCountSpecific(p, "Audrey") == 1) {
			yFindLatestReverse("p"+p+"DragonObject", "Audrey", p);
			trVectorSetUnitPos("BombVector"+p+"", "p"+p+"DragonObject", true);
			trMutateSelected(kbGetProtoUnitID("Rocket"));
			unitTransform("Audrey Base", "Rocket");
			trVectorSetUnitPos("SiphonPos"+p+"", "P"+p+"Siphon");
			trVectorSnapToGrid("SiphonPos"+p+"");
			int Col = (trVectorQuestVarGetX("SiphonPos"+p+"") ) / 8 +1;
			int Row = (trVectorQuestVarGetZ("SiphonPos"+p+"") ) / 8 +1;
			if(Row <= MaxRows){
				if(Row < MaxRows){
					MineSquare(Row+1, Col+1);
					MineSquare(Row+1, Col);
					MineSquare(Row+1, Col-1);
				}
				MineSquare(Row, Col+1);
				MineSquare(Row, Col-1);
				MineSquare(Row-1, Col+1);
				MineSquare(Row-1, Col);
				MineSquare(Row-1, Col-1);
				if(Row < MaxRows){RemoveBlack(Row+1, Col+1);
					RemoveBlack(Row+1, Col);
					RemoveBlack(Row+1, Col-1);
				}
				RemoveBlack(Row, Col+1);
				RemoveBlack(Row, Col-1);
				RemoveBlack(Row-1, Col+1);
				RemoveBlack(Row-1, Col);
				RemoveBlack(Row-1, Col-1);
				if(Stage == 8){
					if(Row < MaxRows-1){
						MineSquare(Row+2, Col+2);
						MineSquare(Row+2, Col+1);
						MineSquare(Row+2, Col);
						MineSquare(Row+2, Col-1);
						MineSquare(Row+2, Col-2);
					}
					MineSquare(Row+1, Col+2);
					MineSquare(Row+1, Col-2);
					MineSquare(Row, Col+2);
					MineSquare(Row, Col-2);
					MineSquare(Row-1, Col+2);
					MineSquare(Row-1, Col-2);
					MineSquare(Row-2, Col+2);
					MineSquare(Row-2, Col+1);
					MineSquare(Row-2, Col);
					MineSquare(Row-2, Col-1);
					MineSquare(Row-2, Col-2);
					RemoveBlack(Row+2, Col+2);
					RemoveBlack(Row+2, Col+1);
					RemoveBlack(Row+2, Col);
					RemoveBlack(Row+2, Col-1);
					RemoveBlack(Row+2, Col-2);
					RemoveBlack(Row+1, Col+2);
					RemoveBlack(Row+1, Col-2);
					RemoveBlack(Row, Col+2);
					RemoveBlack(Row, Col-2);
					RemoveBlack(Row-1, Col+2);
					RemoveBlack(Row-1, Col-2);
					RemoveBlack(Row-2, Col+2);
					RemoveBlack(Row-2, Col+1);
					RemoveBlack(Row-2, Col);
					RemoveBlack(Row-2, Col-1);
					RemoveBlack(Row-2, Col-2);
				}
				int temp = trGetNextUnitScenarioNameNumber();
				trArmyDispatch("0,0","Dwarf",1,trVectorQuestVarGetX("P"+p+"Pos"),0,trVectorQuestVarGetZ("P"+p+"Pos"),0,true);
				trArmySelect("0,0");
				trUnitChangeProtoUnit("Spy Eye");
				trUnitSelectClear();
				trUnitSelect(""+temp, true);
				trMutateSelected(kbGetProtoUnitID("Hades Door"));
				trSetSelectedScale(0,0,0);
				trUnitOverrideAnimation(25,0,false,false,-1);
				trUnitSetAnimationPath("3,0,0,0,0,0,0");
				trSetUnitOrientation(vector(0,1,0),vector(1,0,0),true);
				trUnitSelectClear();
				//trUnitSelect(""+temp, true);
				xAddDatabaseBlock(dDestroyMe, true);
				xSetInt(dDestroyMe, xDestroyName, temp);
				xSetInt(dDestroyMe, xDestroyTime, trTimeMS()+1500);
				//trChatSend(0, ""+xGetDatabaseCount(dDestroyMe));
				//trChatSend(0, "<color=0,1,0>"+xGetInt(dDestroyMe, xDestroyName));
			}
			else{
				trChatSendToPlayer(0, p, "<color=1,0,0>Plastic explosive error - can't use on the surface.</color>");
				if(trCurrentPlayer() == p){
					trSoundPlayFN("cantdothat.wav","1",-1,"","");
				}
				grantGodPowerNoRechargeNextPosition(p, "Audrey", 1);
			}
		}
	}
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
						1*trQuestVarGet("P"+p+"DrillTargetZ")/2-1) == MineST) && (trGetTerrainType(1*trQuestVarGet("P"+p+"DrillTargetX")/2-1,
						1*trQuestVarGet("P"+p+"DrillTargetZ")/2-1) == MineT)){
				trChatSendToPlayer(0, p, "<color=1,0,0>This spot has already been drilled!</color>");
				if(trCurrentPlayer() == p){
					trSoundPlayFN("cantdothat.wav","1",-1,"","");
				}
				trTechGodPower(p, "Animal Magnetism", 1);
				break;
			}
			if((trGetTerrainSubType(1*trQuestVarGet("P"+p+"DrillTargetX")/2-1,
						1*trQuestVarGet("P"+p+"DrillTargetZ")/2-1) == 13) && (trGetTerrainType(1*trQuestVarGet("P"+p+"DrillTargetX")/2-1,
						1*trQuestVarGet("P"+p+"DrillTargetZ")/2-1) == 2)){
				trChatSendToPlayer(0, p, "<color=1,0,0>You cannot drill here!</color>");
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
				
				//STATUS EFFECTS
				//Lava 1
				if((trGetTerrainSubType(1*trQuestVarGet("P"+p+"DrillTargetX")/2-1,
							1*trQuestVarGet("P"+p+"DrillTargetZ")/2-1) == 7) && (trGetTerrainType(1*trQuestVarGet("P"+p+"DrillTargetX")/2-1,
							1*trQuestVarGet("P"+p+"DrillTargetZ")/2-1) == 5)){
					trQuestVarSet("StatusEffectP"+p+"", 1);
				}
				//Lava 2
				if((trGetTerrainSubType(1*trQuestVarGet("P"+p+"DrillTargetX")/2-1,
							1*trQuestVarGet("P"+p+"DrillTargetZ")/2-1) == 8) && (trGetTerrainType(1*trQuestVarGet("P"+p+"DrillTargetX")/2-1,
							1*trQuestVarGet("P"+p+"DrillTargetZ")/2-1) == 2)){
					trQuestVarSet("StatusEffectP"+p+"", 2);
				}
				//Drill egyptian cliff to unlock bonus 3
				if((trGetTerrainSubType(1*trQuestVarGet("P"+p+"DrillTargetX")/2-1,
							1*trQuestVarGet("P"+p+"DrillTargetZ")/2-1) == 2) && (trGetTerrainType(1*trQuestVarGet("P"+p+"DrillTargetX")/2-1,
							1*trQuestVarGet("P"+p+"DrillTargetZ")/2-1) == 2)){
					xSetPointer(dPlayerData, p);
					if (xGetInt(dPlayerData, xBonus+3) == 0){
						xSetInt(dPlayerData, xBonus+3, 1);
						ColouredIconChat("1,0.5,0", "icons\special e son of osiris icon 64","Bonus unlocked (3)!");
						if(trCurrentPlayer() == p){
							saveAllData();
							playSoundCustom("cinematics\10_in\clearedcity.wav", "\Yeebaagooon\Motherload\UnlockBonus.mp3");
						}
					}
				}
				//DRILLING
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
				trQuestVarSet("P"+p+"Drilling", 19+xGetInt(dPlayerData, xDrillLevel));
				//Maybe double drill level and - engine level? - Bit harsh on stage 1
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
		1*trQuestVarGet("P"+p+"DrillTargetX")/2-1,1*trQuestVarGet("P"+p+"DrillTargetZ")/2-1,MineT, MineST,false);
	//This paints the black area around the square depending on entry point
	/*
	if(1*trQuestVarGet("P"+p+"Approach") == 1){
		trPaintTerrain(1*trQuestVarGet("P"+p+"DrillTargetX")/2-3,1*trQuestVarGet("P"+p+"DrillTargetZ")/2-4,
			1*trQuestVarGet("P"+p+"DrillTargetX")/2-1,1*trQuestVarGet("P"+p+"DrillTargetZ")/2-1,MineT, MineST,false);
	}
	else if(1*trQuestVarGet("P"+p+"Approach") == 2){
		trPaintTerrain(1*trQuestVarGet("P"+p+"DrillTargetX")/2-3,1*trQuestVarGet("P"+p+"DrillTargetZ")/2-3,
			1*trQuestVarGet("P"+p+"DrillTargetX")/2-1,1*trQuestVarGet("P"+p+"DrillTargetZ")/2,MineT, MineST,false);
	}
	else if(1*trQuestVarGet("P"+p+"Approach") == 3){
		trPaintTerrain(1*trQuestVarGet("P"+p+"DrillTargetX")/2-3,1*trQuestVarGet("P"+p+"DrillTargetZ")/2-3,
			1*trQuestVarGet("P"+p+"DrillTargetX")/2,1*trQuestVarGet("P"+p+"DrillTargetZ")/2-1,MineT, MineST,false);
	}
	else if(1*trQuestVarGet("P"+p+"Approach") == 4){
		trPaintTerrain(1*trQuestVarGet("P"+p+"DrillTargetX")/2-4,1*trQuestVarGet("P"+p+"DrillTargetZ")/2-3,
			1*trQuestVarGet("P"+p+"DrillTargetX")/2-1,1*trQuestVarGet("P"+p+"DrillTargetZ")/2-1,MineT, MineST,false);
	}
	*/
	//IMPROVED - this checked and removes any connecting walls after a drill
	//upwards
	//paint from up
	if((trGetTerrainSubType(1*trQuestVarGet("P"+p+"DrillTargetX")/2-1,
				1*trQuestVarGet("P"+p+"DrillTargetZ")/2+3) == MineST) && (trGetTerrainType(1*trQuestVarGet("P"+p+"DrillTargetX")/2-1,
				1*trQuestVarGet("P"+p+"DrillTargetZ")/2+3) == MineT)){
		trPaintTerrain(1*trQuestVarGet("P"+p+"DrillTargetX")/2-3,1*trQuestVarGet("P"+p+"DrillTargetZ")/2+1,
			1*trQuestVarGet("P"+p+"DrillTargetX")/2-1,1*trQuestVarGet("P"+p+"DrillTargetZ")/2,MineT, MineST,false);
		if((trGetTerrainSubType(1*trQuestVarGet("P"+p+"DrillTargetX")/2-1,
					1*trQuestVarGet("P"+p+"DrillTargetZ")/2-5) == MineST) && (trGetTerrainType(1*trQuestVarGet("P"+p+"DrillTargetX")/2-1,
					1*trQuestVarGet("P"+p+"DrillTargetZ")/2-5) == MineT)){
		}
	}
	if((trGetTerrainSubType(1*trQuestVarGet("P"+p+"DrillTargetX")/2-1,
				1*trQuestVarGet("P"+p+"DrillTargetZ")/2-5) == MineST) && (trGetTerrainType(1*trQuestVarGet("P"+p+"DrillTargetX")/2-1,
				1*trQuestVarGet("P"+p+"DrillTargetZ")/2-5) == MineT)){
		trPaintTerrain(1*trQuestVarGet("P"+p+"DrillTargetX")/2-3,1*trQuestVarGet("P"+p+"DrillTargetZ")/2-4,
			1*trQuestVarGet("P"+p+"DrillTargetX")/2-1,1*trQuestVarGet("P"+p+"DrillTargetZ")/2-1,MineT, MineST,false);
	}
	
	//paint from left
	if((trGetTerrainSubType(1*trQuestVarGet("P"+p+"DrillTargetX")/2-5,
				1*trQuestVarGet("P"+p+"DrillTargetZ")/2-1) == MineST) && (trGetTerrainType(1*trQuestVarGet("P"+p+"DrillTargetX")/2-5,
				1*trQuestVarGet("P"+p+"DrillTargetZ")/2-1) == MineT)){
		trPaintTerrain(1*trQuestVarGet("P"+p+"DrillTargetX")/2-4,1*trQuestVarGet("P"+p+"DrillTargetZ")/2-3,
			1*trQuestVarGet("P"+p+"DrillTargetX")/2-1,1*trQuestVarGet("P"+p+"DrillTargetZ")/2-1,MineT, MineST,false);
	}
	//paint from right
	if((trGetTerrainSubType(1*trQuestVarGet("P"+p+"DrillTargetX")/2+3,
				1*trQuestVarGet("P"+p+"DrillTargetZ")/2-1) == MineST) && (trGetTerrainType(1*trQuestVarGet("P"+p+"DrillTargetX")/2+3,
				1*trQuestVarGet("P"+p+"DrillTargetZ")/2-1) == MineT)){
		trPaintTerrain(1*trQuestVarGet("P"+p+"DrillTargetX")/2-3,1*trQuestVarGet("P"+p+"DrillTargetZ")/2-3,
			1*trQuestVarGet("P"+p+"DrillTargetX")/2,1*trQuestVarGet("P"+p+"DrillTargetZ")/2-1,MineT, MineST,false);
	}
	//wall destruction post drilling
	zPos = 1*((trQuestVarGet("P"+p+"DrillTargetZ")-1)/8);
	xPos = 1*((trQuestVarGet("P"+p+"DrillTargetX")-1)/8);
	//trPaintTerrain((xPos)*4-2,(zPos)*4-2,(xPos)*4-2,(zPos)*4-2,2,2, false);
	if((trGetTerrainSubType((xPos)*4-2,(zPos)*4+2) == MineST) && (trGetTerrainType((xPos)*4-2,
				(zPos)*4+2) == MineT)){
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
	if((trGetTerrainSubType((xPos)*4-2,(zPos)*4-6) == MineST) && (trGetTerrainType((xPos)*4-2,
				(zPos)*4-6) == MineT)){
		trUnitSelectByQV("R"+(zPos-1)+"C"+xPos+"WallX");
		trUnitChangeProtoUnit("Heka Shockwave SFX");
	}
	
	if((trGetTerrainSubType((xPos)*4+2,(zPos)*4-2) == MineST) && (trGetTerrainType((xPos)*4+2,
				(zPos)*4-2) == MineT)){
		trUnitSelectByQV("R"+zPos+"C"+xPos+"WallY");
		trUnitChangeProtoUnit("Heka Shockwave SFX");
	}
	if((trGetTerrainSubType((xPos)*4-6,(zPos)*4-2) == MineST) && (trGetTerrainType((xPos)*4-6,
				(zPos)*4-2) == MineT)){
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
			}
		}
	}
	//STATUS EFFECTS
	//Lava 1
	if(1*trQuestVarGet("StatusEffectP"+p+"") == 1){
		trUnitSelectByQV("P"+p+"Siphon", false);
		trDamageUnit(200-xGetInt(dPlayerData, xRadiator));
		trDamageUnit(10*xGetInt(dPlayerData, xDepth)/xGetInt(dPlayerData, xRadiator));
		trQuestVarSet("StatusEffectP"+p+"", 0);
	}
	//Lava 2
	if(1*trQuestVarGet("StatusEffectP"+p+"") == 2){
		trUnitSelectByQV("P"+p+"Siphon", false);
		trDamageUnit(350-xGetInt(dPlayerData, xRadiator));
		trDamageUnit(10*xGetInt(dPlayerData, xDepth)/xGetInt(dPlayerData, xRadiator));
		trQuestVarSet("StatusEffectP"+p+"", 0);
	}
}
