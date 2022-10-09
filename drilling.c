rule Rain
inactive
highFrequency
{
	for(p = 1; <= cNumberNonGaiaPlayers){
		int count = 0;
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
					playSoundCustom("vortexstart.wav");
				}
				count = 0;
				for(x=0; < 4) {
					if(trGetGPData(1,0,x) == 156){
						count = count + trGetGPData(1,1,x);
					}
				}
				ColouredChatToPlayer(p, "1,0.5,0", "Emergency teleports remaining - <color=1,1,1>"+count+"");
			}
		}
	}
}

rule Ragnorok
inactive
highFrequency
{
	for(p = 1; <= cNumberNonGaiaPlayers){
		int count = 0;
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
				count = 0;
				for(x=0; < 4) {
					if(trGetGPData(1,0,x) == 234){
						count = count + trGetGPData(1,1,x);
					}
				}
				ColouredChatToPlayer(p, "1,0.5,0", "Backup fuel tanks remaining - <color=1,1,1>"+count+"");
			}
		}
	}
}

rule Audrey
inactive
highFrequency
{
	for(p = 1; <= cNumberNonGaiaPlayers){
		int count = 0;
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
					if(trCurrentPlayer() == p){
						playSoundCustom("earthdragonbirth.wav", "earthdragonbirth.wav");
					}
					count = 0;
					for(x=0; < 4) {
						if(trGetGPData(p,0,x) == 407){
							count = count + trGetGPData(p,1,x);
						}
					}
					if(count == 0){
						trChatSendToPlayer(0, p, "<color=1,0,0>You have no dynamite remaining.</color>");
					}
					else{
						ColouredChatToPlayer(p, "1,0.5,0", "Dynamite remaining - <color=1,1,1>"+count+"");
					}
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

rule EarthDragon
inactive
highFrequency
{
	for(p = 1; <= cNumberNonGaiaPlayers){
		if (trPlayerUnitCountSpecific(p, "Earth Dragon") == 1) {
			yFindLatestReverse("p"+p+"DragonObject", "Earth Dragon", p);
			trVectorSetUnitPos("BombVector"+p+"", "p"+p+"DragonObject", true);
			trMutateSelected(kbGetProtoUnitID("Rocket"));
			trVectorSnapToGrid("BombVector"+p+"");
			int Col = (trVectorQuestVarGetX("BombVector"+p+"") ) / 8 +1;
			int Row = (trVectorQuestVarGetZ("BombVector"+p+"") ) / 8 +1;
			//trChatSend(0, "TRow" + Row);
			//trChatSend(0, "TCol" + Col);
			trVectorSetUnitPos("SiphonPos"+p+"", "P"+p+"Siphon");
			trVectorSnapToGrid("SiphonPos"+p+"");
			int startCol = (trVectorQuestVarGetX("SiphonPos"+p+"") ) / 8 +1;
			int startRow = (trVectorQuestVarGetZ("SiphonPos"+p+"") ) / 8 +1;
			unitTransform("Earth Dragon Hole", "Rocket");
			//trChatSend(0, "SRow" + startRow);
			//trChatSend(0, "SCol" + startCol);
			//VALIDITY CHECKS
			if(Row > MaxRows){
				trChatSendToPlayer(0, p, "<color=1,0,0>Cannot use laser here!</color>");
				if(trCurrentPlayer() == p){
					trSoundPlayFN("cantdothat.wav","1",-1,"","");
				}
				grantGodPowerNoRechargeNextPosition(p, "Earth Dragon", 1);
				break;
			}
			if((Row == startRow) && (Col == startCol)){
				trChatSendToPlayer(0, p, "<color=1,0,0>Laser error - no direction. Use adjacent to your ship.</color>");
				if(trCurrentPlayer() == p){
					trSoundPlayFN("cantdothat.wav","1",-1,"","");
				}
				grantGodPowerNoRechargeNextPosition(p, "Earth Dragon", 1);
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
						for(d=2 ; <= 10){
							MineSquare(Row, Col+d);
							RemoveBlack(Row, Col+d);
						}
					}
					if((Col-startCol) == -1){
						MineSquare(Row, Col);
						MineSquare(Row, Col-1);
						RemoveBlack(Row, Col);
						RemoveBlack(Row, Col-1);
						RemoveBlack(Row, Col+1);
						for(d=2 ; <= 10){
							MineSquare(Row, Col-d);
							RemoveBlack(Row, Col-d);
						}
					}
				}
				else if(Col-startCol == 0){
					if((Row-startRow) == 1){
						MineSquare(Row, Col);
						MineSquare(Row+1, Col);
						RemoveBlack(Row, Col);
						RemoveBlack(Row+1, Col);
						RemoveBlack(Row-1, Col);
						for(d=2 ; <= 10){
							MineSquare(Row+d, Col);
							RemoveBlack(Row+d, Col);
						}
					}
					if((Row-startRow) == -1){
						MineSquare(Row, Col);
						MineSquare(Row+1, Col);
						RemoveBlack(Row, Col);
						RemoveBlack(Row-1, Col);
						RemoveBlack(Row+1, Col);
						for(d=2 ; <= 10){
							MineSquare(Row-d, Col);
							RemoveBlack(Row-d, Col);
						}
					}
				}
				if(trCurrentPlayer() == p){
					playSoundCustom("cinematics\32_out\doorseal.wav", "\Yeebaagooon\Motherload\Laser.mp3");
					playSoundCustom("cinematics\32_out\explosion.wav", "");
					playSoundCustom("cinematics\32_out\bigfire.wav", "");
					playSoundCustom("cinematics\32_out\hammerglow.wav", "");
				}
				int a = trGetNextUnitScenarioNameNumber();
				if((Row-startRow) != 0){
					trArmyDispatch("0,0","Dwarf",1,1,0,1,0,true);
				}
				if((Col-startCol) != 0){
					trArmyDispatch("0,0","Dwarf",1,1,0,1,90,true);
				}
				trUnitSelectClear();
				trUnitSelect(""+a);
				trUnitTeleport(trVectorQuestVarGetX("P"+p+"Pos"),4,trVectorQuestVarGetZ("P"+p+"Pos"));
				trUnitSelectClear();
				trUnitSelect(""+a);
				trUnitChangeProtoUnit("Petosuchus Projectile");
				trUnitSelectClear();
				trUnitSelect(""+a);
				if((Row-startRow) == -1){
					trSetSelectedScale(40,4,100);
				}
				if((Row-startRow) == 1){
					trSetSelectedScale(40,4,-100);
				}
				if((Col-startCol) == -1){
					trSetSelectedScale(40,4,100);
					//L
				}
				if((Col-startCol) == 1){
					trSetSelectedScale(40,4,-100);
					//R
				}
				trUnitSelectClear();
				trUnitSelect(""+a);
				trUnitHighlight(5.0, false);
				xAddDatabaseBlock(dDestroyMe, true);
				xSetInt(dDestroyMe, xDestroyName, a);
				xSetInt(dDestroyMe, xDestroyTime, trTimeMS()+1500);
				a = trGetNextUnitScenarioNameNumber();
				trArmyDispatch("0,0","Dwarf",1,1,0,1,0,true);
				trUnitSelectClear();
				trUnitSelect(""+a);
				
				if((Row-startRow) == -1){
					trUnitTeleport(trVectorQuestVarGetX("P"+p+"Pos"),4,1*trVectorQuestVarGetZ("P"+p+"Pos")+8);
				}
				if((Row-startRow) == 1){
					trUnitTeleport(trVectorQuestVarGetX("P"+p+"Pos"),4,1*trVectorQuestVarGetZ("P"+p+"Pos")-8);
				}
				if((Col-startCol) == -1){
					trUnitTeleport(1*trVectorQuestVarGetX("P"+p+"Pos")+8,4,1*trVectorQuestVarGetZ("P"+p+"Pos"));
					//L
				}
				if((Col-startCol) == 1){
					trUnitTeleport(1*trVectorQuestVarGetX("P"+p+"Pos")-8,4,1*trVectorQuestVarGetZ("P"+p+"Pos"));
					//R
				}
				//trUnitTeleport(1*trVectorQuestVarGetX("P"+p+"Pos"),4,1*trVectorQuestVarGetZ("P"+p+"Pos"));
				trUnitSelectClear();
				trUnitSelect(""+a);
				trUnitChangeProtoUnit("Meteorite");
				trUnitSelectClear();
				trUnitSelect(""+a);
				trUnitOverrideAnimation(6,0,false,false,-1,-1);
				trUnitSelectClear();
				trUnitSelect(""+a);
				trSetSelectedScale(0,0,0);
				trUnitSelectClear();
				trUnitSelect(""+a);
				if((Row-startRow) == -1){
					trSetSelectedUpVector(0,0,-15);
				}
				if((Row-startRow) == 1){
					trSetSelectedUpVector(0,0,15);
				}
				if((Col-startCol) == -1){
					trSetSelectedUpVector(-15,0,0);
					//L
				}
				if((Col-startCol) == 1){
					trSetSelectedUpVector(15,0,0);
					//R
				}
				trUnitSelectClear();
				trUnitSelect(""+a);
				trUnitHighlight(5.0, false);
				xSetPointer(dPlayerData, p);
				trUnitSelectClear();
				xUnitSelect(dPlayerData, xSpyObject);
				trUnitChangeProtoUnit("Olympus Temple SFX");
				//effect
				/*
				it's very simple
				just toss them in a database
				with a variable that keeps track of their timeout
				like trTimeMS() + 1000
				and then set their scale to be a fraction of that
				(timeout - current time) / lifespan
				well, more like
				0.001 * (timeout - current time)
				since you want it to be a float
				*/
				break;
			}
			else{
				trChatSendToPlayer(0, p, "<color=1,0,0>Laser error - target too far. Use adjacent to your ship.</color>");
				if(trCurrentPlayer() == p){
					trSoundPlayFN("cantdothat.wav","1",-1,"","");
				}
				grantGodPowerNoRechargeNextPosition(p, "Earth Dragon", 1);
			}
		}
	}
}

rule Vision
inactive
highFrequency
{
	for(p = 1; <= cNumberNonGaiaPlayers){
		if (trPlayerGetPopulation(p) >= 10000) {
			unitTransform("Vision Revealer", "Rocket");
			trVectorSetUnitPos("SiphonPos"+p+"", "P"+p+"Siphon");
			trVectorSnapToGrid("SiphonPos"+p+"");
			int Col = (trVectorQuestVarGetX("SiphonPos"+p+"") ) / 8 +1;
			int Row = (trVectorQuestVarGetZ("SiphonPos"+p+"") ) / 8 +1;
			for(a=0 ; < 5){
				for(b=0 ; < 5){
					MineSquare(Row+a-2, Col+b-2);
					RemoveBlack(Row+a-2, Col+b-2);
				}
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
			trArmyDispatch("0,0","Dwarf",25,trVectorQuestVarGetX("P"+p+"Pos"),0,trVectorQuestVarGetZ("P"+p+"Pos"),0,true);
			trUnitSelectClear();
			trArmySelect("0,0");
			trUnitChangeProtoUnit("Vision SFX");
			trArmyDispatch("0,1","Cyclops",25,trVectorQuestVarGetX("P"+p+"Pos"),0,trVectorQuestVarGetZ("P"+p+"Pos"),0,true);
			trUnitSelectClear();
			trArmySelect("0,1");
			trUnitChangeProtoUnit("Dust Large");
			trCameraShake(3, 0.25);
			xSetPointer(dPlayerData, p);
			trUnitSelectClear();
			xUnitSelect(dPlayerData, xSpyObject);
			trUnitChangeProtoUnit("Olympus Temple SFX");
		}
	}
}

rule Nidhogg
inactive
highFrequency
{
	for(p = 1; <= cNumberNonGaiaPlayers){
		if (trPlayerUnitCountSpecific(p, "Nidhogg") >= 1) {
			unitTransform("Nidhogg", "Rocket");
			int temp = trGetNextUnitScenarioNameNumber();
			//trUnitSelect(""+temp, true);
			//trChatSend(0, ""+xGetDatabaseCount(dDestroyMe));
			//trChatSend(0, "<color=0,1,0>"+xGetInt(dDestroyMe, xDestroyName));
			xSetPointer(dPlayerData, p);
			trUnitSelectClear();
			xUnitSelect(dPlayerData, xSpyObject);
			trMutateSelected(kbGetProtoUnitID("Monument"));
			trUnitSelectClear();
			xUnitSelect(dPlayerData, xSpyObject);
			trSetSelectedScale(1,1,1);
			trUnitSelectClear();
			trUnitOverrideAnimation(4,0,false,false,-1);
			xAddDatabaseBlock(dDestroyMe, true);
			xSetInt(dDestroyMe, xDestroyName, xGetInt(dPlayerData, xSpyObject));
			xSetInt(dDestroyMe, xDestroyTime, trTimeMS()+30000);
			trQuestVarSet("P"+p+"DrillBonusOn", 1);
			if(trCurrentPlayer() == p){
				trCounterAddTime("CDDrill", 30, 0, "<color={PlayerColor("+p+")}>Reality drill", -1);
			}
			trQuestVarSet("StopB22T"+p+"", trTime()+30);
			trEventFire(44+p);
			spyEffect(1*trQuestVarGet("P"+p+"Siphon"), kbGetProtoUnitID("Implode Sphere Effect"), xsVectorSet(dPlayerData,xSpyObject,p), vector(0,0,0), 6);
			spyEffect(1*trQuestVarGet("P"+p+"Siphon"), kbGetProtoUnitID("Imperial Examination"), vector(0,0,0), vector(1,1,1));
		}
	}
}

void DrillBonusOff(int p = 0){
	xsSetContextPlayer(0);
	p = p-44;
	if(trTime() > 1*trQuestVarGet("StopB22T"+p+"")){
		trQuestVarSet("P"+p+"DrillBonusOn", 0);
		if(trCurrentPlayer() == p){
			playSound("godpowerfailed.wav");
		}
		xSetPointer(dPlayerData, p);
		xAddDatabaseBlock(dDestroyMe, true);
		xSetInt(dDestroyMe, xDestroyName, xGetInt(dPlayerData, xSpyObject));
		xSetInt(dDestroyMe, xDestroyTime, trTimeMS()+1);
		unitTransform("Imperial Examination", "Rocket");
		xsDisableSelf();
	}
}

rule AudreyL2
inactive
highFrequency
{
	for(p = 1; <= cNumberNonGaiaPlayers){
		int count = 0;
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
				if(Stage >= 8){
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
				count = 0;
				for(x=0; < 4) {
					if(trGetGPData(p,0,x) == 407){
						count = count + trGetGPData(p,1,x);
					}
				}
				if(count == 0){
					trChatSendToPlayer(0, p, "<color=1,0,0>You have no more heavy explosives left.</color>");
				}
				else{
					if(Stage <= 7){
						ColouredChatToPlayer(p, "1,0.5,0", "Remaining plastic explosives <color=1,1,1>["+count+"]");
					}
					else{
						ColouredChatToPlayer(p, "1,0.5,0", "Remaining nuclear explosives<color=1,1,1>["+count+"]");
					}
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
				xSetPointer(dPlayerData, p);
				if(xGetInt(dPlayerData, xDrillLevel) < 6){
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
				//Lava 3
				if((trGetTerrainSubType(1*trQuestVarGet("P"+p+"DrillTargetX")/2-1,
							1*trQuestVarGet("P"+p+"DrillTargetZ")/2-1) == 10) && (trGetTerrainType(1*trQuestVarGet("P"+p+"DrillTargetX")/2-1,
							1*trQuestVarGet("P"+p+"DrillTargetZ")/2-1) == 2)){
					trQuestVarSet("StatusEffectP"+p+"", 3);
					//BONUS 17
				}
				//HARD ICE - UnderwaterIceC/Hades9/HadesCliff
				if((trGetTerrainSubType(1*trQuestVarGet("P"+p+"DrillTargetX")/2-1,
							1*trQuestVarGet("P"+p+"DrillTargetZ")/2-1) == 8) && (trGetTerrainType(1*trQuestVarGet("P"+p+"DrillTargetX")/2-1,
							1*trQuestVarGet("P"+p+"DrillTargetZ")/2-1) == 3)){
					trQuestVarSet("StatusEffectP"+p+"", 4);
					//BONUS 19
				}
				if((trGetTerrainSubType(1*trQuestVarGet("P"+p+"DrillTargetX")/2-1,
							1*trQuestVarGet("P"+p+"DrillTargetZ")/2-1) == 9) && (trGetTerrainType(1*trQuestVarGet("P"+p+"DrillTargetX")/2-1,
							1*trQuestVarGet("P"+p+"DrillTargetZ")/2-1) == 5)){
					trQuestVarSet("StatusEffectP"+p+"", 4);
					//BONUS 19
				}
				if((trGetTerrainSubType(1*trQuestVarGet("P"+p+"DrillTargetX")/2-1,
							1*trQuestVarGet("P"+p+"DrillTargetZ")/2-1) == 11) && (trGetTerrainType(1*trQuestVarGet("P"+p+"DrillTargetX")/2-1,
							1*trQuestVarGet("P"+p+"DrillTargetZ")/2-1) == 2)){
					trQuestVarSet("StatusEffectP"+p+"", 4);
					//BONUS 19
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
				if(1*trQuestVarGet("P"+p+"Approach") == 4){
					trArmyDispatch(""+p+",0", "Victory Marker", 1, trVectorQuestVarGetX("SiphonPos"+p+""), trVectorQuestVarGetY("SiphonPos"+p+""),
						trVectorQuestVarGetZ("SiphonPos"+p+""), 90, true);
				}
				if(1*trQuestVarGet("P"+p+"Approach") == 3){
					trArmyDispatch(""+p+",0", "Victory Marker", 1, trVectorQuestVarGetX("SiphonPos"+p+""), trVectorQuestVarGetY("SiphonPos"+p+""),
						trVectorQuestVarGetZ("SiphonPos"+p+""), 270, true);
				}
				if(1*trQuestVarGet("P"+p+"Approach") == 2){
					trArmyDispatch(""+p+",0", "Victory Marker", 1, trVectorQuestVarGetX("SiphonPos"+p+""), trVectorQuestVarGetY("SiphonPos"+p+""),
						trVectorQuestVarGetZ("SiphonPos"+p+""), 180, true);
				}
				if(1*trQuestVarGet("P"+p+"Approach") == 1){
					trArmyDispatch(""+p+",0", "Victory Marker", 1, trVectorQuestVarGetX("SiphonPos"+p+""), trVectorQuestVarGetY("SiphonPos"+p+""),
						trVectorQuestVarGetZ("SiphonPos"+p+""), 0, true);
				}
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
				trVectorQuestVarSet("TargetVector"+p+"", xsVectorSet(1*trQuestVarGet("P"+p+"DrillTargetX")-4,3,1*trQuestVarGet("P"+p+"DrillTargetZ")-4));
				trUnitMoveToVectorEvent("TargetVector"+p+"", false, p);
				if(trCurrentPlayer() == p){
					if(1*trQuestVarGet("P"+p+"DrillBonusOn") == 0){
						playSoundCustom("earthquakeexist.wav", "earthquakeexist.wav");
					}
					else{
						playSoundCustom("timeshift.wav");
					}
				}
				if(Stage <= 2){
					trQuestVarSet("P"+p+"Drilling", 19);
				}
				else if((Stage <= 4) && (Stage >= 3)){
					trQuestVarSet("P"+p+"Drilling", 19+xGetInt(dPlayerData, xDrillLevel));
				}
				else if(Stage >= 5){
					trQuestVarSet("P"+p+"Drilling", 19+xGetInt(dPlayerData, xDrillLevel)*2-xGetInt(dPlayerData, xRadiatorLevel));
				}
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
		if(trQuestVarGet("P"+p+"B17") == 1){
			trDamageUnit(-100);
		}
	}
	//Lava 2
	if(1*trQuestVarGet("StatusEffectP"+p+"") == 2){
		trUnitSelectByQV("P"+p+"Siphon", false);
		trDamageUnit(350-xGetInt(dPlayerData, xRadiator));
		trDamageUnit(10*xGetInt(dPlayerData, xDepth)/xGetInt(dPlayerData, xRadiator));
		trQuestVarSet("StatusEffectP"+p+"", 0);
		if(trQuestVarGet("P"+p+"B17") == 1){
			trDamageUnit(-100);
		}
	}
	//Lava 3
	if(1*trQuestVarGet("StatusEffectP"+p+"") == 3){
		trUnitSelectByQV("P"+p+"Siphon", false);
		trDamageUnit(500-xGetInt(dPlayerData, xRadiator));
		trQuestVarSet("StatusEffectP"+p+"", 0);
		if(trQuestVarGet("P"+p+"B17") == 1){
			trDamageUnit(-100);
		}
		if(Stage == 1){
			trQuestVarModify("P"+p+"LavaBonus", "+", 1);
			if(trQuestVarGet("P"+p+"LavaBonus") >= 10){
				xSetPointer(dPlayerData, p);
				if (xGetInt(dPlayerData, xBonus+17) == 0){
					xSetInt(dPlayerData, xBonus+17, 1);
					if(trCurrentPlayer() == p){
						ColouredIconChat("1,0.5,0", "icons\special e son of osiris icon 64","Bonus unlocked (17)!");
						playSoundCustom("cinematics\10_in\clearedcity.wav", "\Yeebaagooon\Motherload\UnlockBonus.mp3");
						saveAllData();
					}
				}
			}
		}
	}
	//Hard Ice
	if(1*trQuestVarGet("StatusEffectP"+p+"") == 4){
		trQuestVarSet("StatusEffectP"+p+"", 0);
		xSetPointer(dPlayerData, p);
		if (xGetInt(dPlayerData, xBonus+19) == 0){
			xSetInt(dPlayerData, xIceDrill, 1*xGetInt(dPlayerData, xIceDrill)+1);
			if (xGetInt(dPlayerData, xIceDrill) >= 1*SeaIceDrill){
				xSetInt(dPlayerData, xBonus+19, 1);
				if(trCurrentPlayer() == p){
					ColouredIconChat("1,0.5,0", "icons\special e son of osiris icon 64","Bonus unlocked (19)!");
					playSoundCustom("cinematics\10_in\clearedcity.wav", "\Yeebaagooon\Motherload\UnlockBonus.mp3");
					saveAllData();
				}
			}
		}
	}
	//Hull destroy
	if(Stage == 10){
		trUnitSelectClear();
		int row = zPos;
		int col = xPos;
		trUnitSelectByQV("HullR"+row+"C"+col+"");
		trUnitChangeProtoUnit("Meteor Impact Ground");
		trUnitDestroy();
	}
	if((trPlayerUnitCountSpecific(cNumberNonGaiaPlayers, "Invisible Wall") <= 20) && (Stage != 10)){
		for(a = 1; < cNumberNonGaiaPlayers){
			xSetPointer(dPlayerData, a);
			if (xGetInt(dPlayerData, xBonus+15) == 0){
				xSetInt(dPlayerData, xBonus+15, 1);
				if(trCurrentPlayer() == a){
					ColouredIconChat("1,0.5,0", "icons\special e son of osiris icon 64","Bonus unlocked (15)!");
				}
			}
		}
		saveAllData();
		trOverlayText("Entire planet drilled!", 4.0, 579, 350, 1000);
		playSoundCustom("cinematics\10_in\clearedcity.wav", "\Yeebaagooon\Motherload\UnlockBonus.mp3");
		trCounterAbort("CDSTage");
		StageTime = 30+trTime();
		if(cNumberNonGaiaPlayers >= 3){
			trCounterAddTime("CDSTage", 30, 0, "<color={PlayerColor(3)}>Time remaining", -1);
		}
		else{
			trCounterAddTime("CDSTage", 30, 0, "<color={PlayerColor(0)}>Time remaining", -1);
		}
	}
}
