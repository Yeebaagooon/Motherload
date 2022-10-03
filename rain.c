/* lure ability */

rule EventSetHandler
active
highFrequency
//THESE ONLY WORK IF FIRES FUNCTION, SO USE VOID!
{
	for(p = 1; <= cNumberNonGaiaPlayers){
		trEventSetHandler(p, "UngarrisonDrill");
		//trEventSetHandler(13+p, "SellMinerals");
	}
	trEventSetHandler(13, "CustomContent");
	trEventSetHandler(14, "StageEnd");
	trEventSetHandler(15, "SPCineYes");
	trEventSetHandler(16, "SPCineNo");
	trEventSetHandler(17, "UpgradeDrill");
	trEventSetHandler(18, "UpgradeHull");
	trEventSetHandler(19, "UpgradeFuel");
	trEventSetHandler(20, "UpgradeCargo");
	trEventSetHandler(21, "UpgradeEngine");
	trEventSetHandler(22, "UpgradeRadiator");
	for(x = 1; <= 21){
		trEventSetHandler(22+x, "Select_Bonus");
	}
	//RESERVED TO 43
	xsDisableSelf();
}

void CustomContent(int p = 0){
	xsDisableSelf();
	trQuestVarSet("CustomContent", 1);
	ColouredIconChat("1,0.5,0", "icons\special e son of osiris icon 64","Custom Content enabled!");
}

rule SPCineChoice
inactive
highFrequency
{
	if((trTime()-cActivationTime) >= 2){
		xsDisableSelf();
		trShowChoiceDialog("Play opening cinematic?", "Yes", 15, "No", 16);
	}
}

void SPCineYes(int p = 0){
	xsSetContextPlayer(0);
	trChatSend(0, "Yes cine");
	xsEnableRule("CineSetup");
	xsDisableSelf();
}

void SPCineNo(int p = 0){
	xsSetContextPlayer(0);
	if(1*trQuestVarGet("CineStatus") == 0){
		trChatSend(0, "The introduction cinematic explains gameplay essentials.");
		trChatSend(0, "Watching at a later time is strongly recommended.");
		/*	if(CinematicObelisk == 0){
			SPCineOption();
		}*/
	}
	xsDisableSelf();
}

rule Selectables
inactive
highFrequency
{
	if(xGetDatabaseCount(dSelectables) != 0){
		xDatabaseNext(dSelectables);
		int n = xGetInt(dSelectables, xSelectablesName);
		xUnitSelect(dSelectables,xSelectablesName);
		if (trUnitIsSelected()) {
			uiClearSelection();
			startNPCDialog(xGetInt(dSelectables, xSelectablesPrompt));
			trUnitHighlight(1, true);
		}
	}
}

rule DeployPlayers
inactive
highFrequency
{
	if((trTime()-cActivationTime) >= 1){
		trCameraCut(vector(97.212753,163.322815,-63.585068), vector(0.001486,-0.784815,0.619728), vector(0.001882,0.619730,0.784813), vector(0.999997,-0.000000,-0.002398));
		for(x=xGetDatabaseCount(dPlanetEyecandy); >0) {
			xDatabaseNext(dPlanetEyecandy);
			xUnitSelect(dPlanetEyecandy,xPlanetEyecandyName);
			trUnitDestroy();
		}
		aiPlanDestroy(dPlanetEyecandy);
		for(p = 1; < cNumberNonGaiaPlayers){
			xSetPointer(dPlayerData, p);
			//trQuestVarSet("P"+p+"RadiationResist", 1.00);
			//trQuestVarModify("P"+p+"RadiationResist", "-", 0.05*xGetInt(dPlayerData, xRadiatorLevel));
			if(xGetInt(dPlayerData, xPlayerActive) == 1){
				trQuestVarSet("P"+p+"Siphon", trGetNextUnitScenarioNameNumber());
				//VECTOR IS 2X+1
				if(Stage <= 2){
					UnitCreate(p, "Hero Greek Atalanta", 75+5*p, 180, 180);
				}
				else if(Stage == 10){
					UnitCreate(p, "Hero Greek Atalanta", 132, 10, 180);
				}
				else{
					UnitCreate(p, "Hero Greek Atalanta", 35+5*p, 168, 180);
				}
				yAddToDatabase("Siphon"+p+"", "P"+p+"Siphon");
				trPlayerSetDiplomacy(0, p, "Enemy");
				trUnitSelectClear();
				trUnitSelectByQV("P"+p+"Siphon");
				trSetSelectedScale(1,0.1,0);
				spyEffect(1*trQuestVarGet("P"+p+"Siphon"), kbGetProtoUnitID("Fire Siphon"), xsVectorSet(dPlayerData,xSpySiphonID,p), vector(1,1,1));
				/*trUnitSelectByQV("P"+p+"Siphon", false);
				trQuestVarSet("P"+p+"MainSpy", trGetNextUnitScenarioNameNumber());
				trTechInvokeGodPower(0, "spy", vector(0,0,0), vector(0,0,0));*/
				//trDelayedRuleActivation("ChangeMainSpy1");
				xSetInt(dPlayerData, xGoldStart, xGetInt(dPlayerData, xGold));
				xSetFloat(dPlayerData, xDrillPower ,1*trQuestVarGet("DrillPowerL"+xGetInt(dPlayerData, xDrillLevel)+""));
				xSetInt(dPlayerData, xHullHP ,1*trQuestVarGet("HullHPL"+xGetInt(dPlayerData, xHullLevel)+""));
				xSetInt(dPlayerData, xFuelTank ,1*trQuestVarGet("FuelCL"+xGetInt(dPlayerData, xFuelLevel)+""));
				xSetInt(dPlayerData, xCargoHold ,1*trQuestVarGet("CargoCL"+xGetInt(dPlayerData, xCargoLevel)+""));
				xSetInt(dPlayerData, xEnginePower ,1*trQuestVarGet("EngineCL"+xGetInt(dPlayerData, xEngineLevel)+""));
				xSetInt(dPlayerData, xRadiator ,1*trQuestVarGet("RadiatorCL"+xGetInt(dPlayerData, xRadiatorLevel)+""));
				xSetFloat(dPlayerData, xFuel, xGetInt(dPlayerData, xFuelTank));
			}
		}
		xsDisableSelf();
		trDelayedRuleActivation("FadeOut");
		unitTransform("Outpost", "Rocket");
		trSetFogAndBlackmap(true, true);
		xsEnableRule("BonusGo");
		xsEnableRule("ChatHelpers");
		/*spawnFuelRelic(vector(10,3,190), 1250);
		spawnFuelRelic(vector(10,3,185), 125);
		spawnHullRelic(vector(70,3,190), 250);
		spawnHullRelic(vector(70,3,185), 500);*/
		if(Stage != 10){
			trDelayedRuleActivation("FuelEconomy");
		}
		else{
			trDelayedRuleActivation("FuelEconomyNatas");
		}
		trMusicPlay();
		trPlayNextMusicTrack();
		for(x=xGetDatabaseCount(dSpace); >0) {
			xDatabaseNext(dSpace);
			xUnitSelect(dSpace,xSpaceName);
			trUnitDestroy();
		}
	}
}

rule FadeOut
inactive
highFrequency
{
	for(p = 1; <= cNumberNonGaiaPlayers){
		trTechGodPower(p, "Animal Magnetism", 1);
	}
	trSetFogAndBlackmap(true, true);
	trUIFadeToColor(0,0,0,1000,500,false);
	uiZoomToProto("Hero Greek Atalanta");
	xsDisableSelf();
	//REVEALERS LOS - CHange LOS and more w/e
	trModifyProtounit("Revealer", 0, 2, 14);
	for(x = 1; <= 19){
		trArmyDispatch("0,8", "Revealer", 1, 200-x*10, 1, 190, 0, true);
		if(Stage == 10){
			trArmyDispatch("0,8", "Revealer", 1, 200-x*10, 1, 175, 0, true);
		}
	}
	trPlayerResetBlackMapForAllPlayers();
	//Tutorial dialog
	if(QuickStart == 0){
		if(Stage == 1){
			startNPCDialog(2);
		}
		if(Stage == 2){
			startNPCDialog(6);
		}
		if(Stage == 3){
			startNPCDialog(10);
		}
		if(Stage == 4){
			startNPCDialog(12);
		}
		if(Stage == 5){
			startNPCDialog(14);
		}
		if(Stage == 6){
			startNPCDialog(16);
		}
		if(Stage == 7){
			startNPCDialog(19);
		}
		if(Stage == 8){
			startNPCDialog(20);
		}
		if(Stage == 9){
			startNPCDialog(22);
		}
		if(Stage == 10){
			startNPCDialog(23);
		}
	}
	//xSetPointer(dPlayerData, 1);
	//trChatSend(0, ""+xGetInt(dPlayerData, xDrillLevel));
	xsEnableRule("StageTimer");
	xsEnableRule("CheckResigns");
	xsEnableRule("PlayerStats");
}

rule StageTimer
inactive
highFrequency
{
	if((trTime()-cActivationTime) >= 20){ //60
		if(Stage == 1){
			StageTime = StageTime+480; //480
			trCounterAddTime("CDSTage", StageTime, 0, "<color={PlayerColor(1)}>Time remaining", -1);
		}
		if(Stage == 2){
			StageTime = StageTime+480; //480
			trCounterAddTime("CDSTage", StageTime, 0, "<color={PlayerColor(1)}>Time remaining", -1);
		}
		if(Stage == 3){
			StageTime = StageTime+480; //480
			trCounterAddTime("CDSTage", StageTime, 0, "<color={PlayerColor(1)}>Time remaining", -1);
			//spawnRelicSpecific(vector(180,0,100), 10);
		}
		if(Stage == 4){
			StageTime = StageTime+480; //480
			trCounterAddTime("CDSTage", StageTime, 0, "<color={PlayerColor(1)}>Time remaining", -1);
		}
		if(Stage == 5){
			StageTime = StageTime+480; //480
			trCounterAddTime("CDSTage", StageTime, 0, "<color={PlayerColor(1)}>Time remaining", -1);
		}
		if(Stage == 6){
			StageTime = StageTime+420; //420
			trCounterAddTime("CDSTage", StageTime, 0, "<color={PlayerColor(1)}>Time remaining", -1);
		}
		if(Stage == 7){
			StageTime = StageTime+480; //480
			trCounterAddTime("CDSTage", StageTime, 0, "<color={PlayerColor(1)}>Time remaining", -1);
		}
		if(Stage == 8){
			StageTime = StageTime+540; //540
			trCounterAddTime("CDSTage", StageTime, 0, "<color={PlayerColor(1)}>Time remaining", -1);
		}
		if(Stage == 9){
			StageTime = StageTime+1000; //600
			trCounterAddTime("CDSTage", StageTime, 0, "<color={PlayerColor(1)}>Time remaining", -1);
		}
		if(Stage == 10){
			StageTime = StageTime+1200; //1200
			trCounterAddTime("CDSTage", StageTime, 0, "<color={PlayerColor(1)}>Time remaining", -1);
		}
		xsDisableSelf();
		xsEnableRule("StageEnd");
	}
}

rule StageEnd
inactive
highFrequency
{
	if((trTime()-cActivationTime) >= StageTime){
		xsDisableSelf();
		xsEnableRule("TimesUp");
	}
}

rule CheckResigns
inactive
highFrequency
{
	if((trTime()-cActivationTime) >= CheckTime){
		CheckTime = CheckTime+1;
		for(p = 1; < cNumberNonGaiaPlayers){
			xSetPointer(dPlayerData, p);
			if(kbIsPlayerHuman(p) == false){
				trPlayerKillAllUnits(p);
				trPlayerKillAllBuildings(p);
				trSetPlayerDefeated(p);
				xSetInt(dPlayerData, xPlayerActive, 0);
				trPlayerKillAllGodPowers(p);
				trVectorQuestVarSet("P"+p+"Pos", xsVectorSet(0,0,0));
			}
			if(xGetInt(dPlayerData, xPlayerActive) == 1){
				if(kbIsPlayerResigned(p) == true){
					trPlayerKillAllUnits(p);
					trPlayerKillAllBuildings(p);
					trSetPlayerDefeated(p);
					xSetInt(dPlayerData, xPlayerActive, 0);
					trPlayerKillAllGodPowers(p);
					trVectorQuestVarSet("P"+p+"Pos", xsVectorSet(0,0,0));
				}
			}
			if(xGetInt(dPlayerData, xPlayerActive) == 1){
				trUnitSelectClear();
				trUnitSelectByQV("P"+p+"Siphon");
				if(trUnitDead()==true){
					trPlayerKillAllUnits(p);
					trPlayerKillAllBuildings(p);
					//trSetPlayerDefeated(p);
					//So can chat
					xSetInt(dPlayerData, xPlayerActive, 0);
					trPlayerKillAllGodPowers(p);
					if(trCurrentPlayer() == p){
						trShowWinLose("You have been destroyed!", "xlose.wav");
					}
					trVectorQuestVarSet("P"+p+"Pos", xsVectorSet(0,0,0));
					trArmyDispatch(""+p+",0","Victory Marker", 1, 0,0,0,0);
					if (xGetInt(dPlayerData, xBonus+9) == 0){
						xSetInt(dPlayerData, xBonus+9, 1);
						if(trCurrentPlayer() == p){
							ColouredIconChat("1,0.5,0", "icons\special e son of osiris icon 64","Bonus unlocked (9)!");
							saveAllData();
							playSoundCustom("cinematics\10_in\clearedcity.wav", "\Yeebaagooon\Motherload\UnlockBonus.mp3");
						}
					}
				}
			}
		}
		trQuestVarSet("LossCondition" ,0);
		for(p = 1; < cNumberNonGaiaPlayers){
			xSetPointer(dPlayerData, p);
			if(xGetInt(dPlayerData, xPlayerActive) == 0){
				trQuestVarModify("LossCondition", "+", 1);
			}
		}
		//	trChatHistoryClear();
		//trChatSend(0, ""+1*trQuestVarGet("LossCondition")+"/"+(cNumberNonGaiaPlayers-1)+"");
		if(1*trQuestVarGet("LossCondition") == cNumberNonGaiaPlayers-1){
			for(p = 1; < cNumberNonGaiaPlayers){
				trSetPlayerDefeated(p);
			}
			trEndGame();
		}
		if(1*trQuestVarGet("LossCondition")+1*trQuestVarGet("TotalNatasWinners") == cNumberNonGaiaPlayers-1){
			trChatSend(0, "Final cinematic");
			xsDisableSelf();
		}
	}
	
}

int GetFuelPump(float x = 0, float z = 0){
	if((x > FSOneXMin) && (x < FSOneXMax)){
		if((z > FSOneZMin) && (z < FSOneZMax)){
			return(1);
		}return(0);
	}
	else if((x > FSTwoXMin) && (x < FSTwoXMax)){
		if((z > FSTwoZMin) && (z < FSTwoZMax)){
			return(2);
		}return(0);
	}
	else if((x > FSThreeXMin) && (x < FSThreeXMax)){
		if((z > FSThreeZMin) && (z < FSThreeZMax)){
			return(3);
		}return(0);
	}
	else{
		return(0);
	}
}

int GetHullShop(float x = 0){
	if(Stage < 7){
		if((x > Hull1XMin*2) && (x < Hull1XMax*2)){
			return(1);
		}
		else if((x > Hull2XMin*2) && (x < Hull2XMax*2)){
			return(2);
		}
		else if((x > Hull3XMin*2) && (x < Hull3XMax*2)){
			return(3);
		}
		else if((x > Hull4XMin*2) && (x < Hull4XMax*2)){
			return(4);
		}
	}
	if(Stage == 7){
		if((x > Hull1XMin*2) && (x < Hull1XMax*2)){
			return(1);
		}
		else if((x > Hull2XMin*2) && (x < Hull2XMax*2)){
			return(2);
		}
		else if((x > Hull3XMin*2) && (x < Hull3XMax*2)){
			return(4);
		}
		else if((x > Hull4XMin*2) && (x < Hull4XMax*2)){
			return(8);
		}
	}
	if(Stage >= 8){
		if((x > Hull1XMin*2) && (x < Hull1XMax*2)){
			return(2);
		}
		else if((x > Hull2XMin*2) && (x < Hull2XMax*2)){
			return(4);
		}
		else if((x > Hull3XMin*2) && (x < Hull3XMax*2)){
			return(8);
		}
		else if((x > Hull4XMin*2) && (x < Hull4XMax*2)){
			return(10);
		}
	}
	else{
		return(0);
	}
}

void FuelBuy(int p = 0){
	if(trTime() > 1*xGetInt(dPlayerData, xFuelCountdownTime)){
		if(xGetFloat(dPlayerData, xFuel) < xGetInt(dPlayerData, xFuelTank)){
			if(GetFuelPump(trVectorQuestVarGetX("P"+p+"Pos"),trVectorQuestVarGetZ("P"+p+"Pos")) != 0){
				if(xGetInt(dPlayerData, xFuelCountdown) == 0){
					if (trPlayerResourceCount(p, "Gold") >= FuelCost) {
						ColouredChatToPlayer(p, "1,1,0", "Refilling fuel tank if you remain stationary...");
						xSetInt(dPlayerData, xFuelCountdown, 4);
					}
					else{
						ColouredChatToPlayer(p, "1,0,0", "You do not have enough gold to buy fuel!");
					}
				}
				
				if(xGetInt(dPlayerData, xFuelCountdown) > 1){
					xSetInt(dPlayerData, xFuelCountdown, xGetInt(dPlayerData, xFuelCountdown)-1);
					ColouredChatToPlayer(p, "1,1,0", ""+xGetInt(dPlayerData, xFuelCountdown)+"...");
				}
				else if (xGetInt(dPlayerData, xFuelCountdown) == 1){
					if(Stage == 1){
						ColouredChatToPlayer(p, "0,1,0", "Refuel complete.");
						if(trCurrentPlayer() == p){
							playSoundCustom("suckup1.wav", "\Yeebaagooon\Motherload\Refuel.mp3");
						}
						xSetFloat(dPlayerData, xFuel, xGetInt(dPlayerData, xFuelTank));
						xSetInt(dPlayerData, xFuelCountdown, 0);
						spyEffect(1*trQuestVarGet("P"+p+"Siphon"), kbGetProtoUnitID("Mountain Giant"), vector(0,0,0), vector(0,0,0), 18);
					}
					else if(Stage != 1){
						xSetFloat(dPlayerData, xFuel, xGetFloat(dPlayerData, xFuel)+1000*GetFuelPump(trVectorQuestVarGetX("P"+p+"Pos"),trVectorQuestVarGetZ("P"+p+"Pos")));
						xSetInt(dPlayerData, xFuelCountdown, 0);
						xSetInt(dPlayerData, xGold, xGetInt(dPlayerData, xGold)-1*FuelCost*GetFuelPump(trVectorQuestVarGetX("P"+p+"Pos"),trVectorQuestVarGetZ("P"+p+"Pos")));
						if(xGetInt(dPlayerData, xFuelSpend) < 4700){
							xSetInt(dPlayerData, xFuelSpend, xGetInt(dPlayerData, xFuelSpend)+1*FuelCost*GetFuelPump(trVectorQuestVarGetX("P"+p+"Pos"),trVectorQuestVarGetZ("P"+p+"Pos")));
							if ((xGetInt(dPlayerData, xBonus+16) == 0) && (xGetInt(dPlayerData, xFuelSpend) >= FuelSpendForBonus)){
								xSetInt(dPlayerData, xBonus+16, 1);
								if(trCurrentPlayer() == p){
									saveAllData();
									ColouredIconChat("1,0.5,0", "icons\special e son of osiris icon 64","Bonus unlocked (16)!");
									playSoundCustom("cinematics\10_in\clearedcity.wav", "\Yeebaagooon\Motherload\UnlockBonus.mp3");
								}
							}
						}
						ColouredChatToPlayer(p, "0,1,0", "Refuel complete.");
						if(trCurrentPlayer() == p){
							playSoundCustom("suckup1.wav", "\Yeebaagooon\Motherload\Refuel.mp3");
						}
						spyEffect(1*trQuestVarGet("P"+p+"Siphon"), kbGetProtoUnitID("Mountain Giant"), vector(0,0,0), vector(0,0,0), 18);
						if(xGetFloat(dPlayerData, xFuel) > xGetInt(dPlayerData,xFuelTank)){
							xSetFloat(dPlayerData, xFuel, xGetInt(dPlayerData, xFuelTank));
						}
						
					}
					trQuestVarSet("P"+p+"FuelWarning", 0);
				}
			}
			xSetInt(dPlayerData, xFuelCountdownTime, trTime()+1);
		}
	}
}

rule ExtraShop
inactive
highFrequency
{
	if(trTime() > 1*trQuestVarGet("ShopTimer")){
		for(p = 1; <= cNumberNonGaiaPlayers){
			int count = 0;
			xSetPointer(dPlayerData, p);
			if(xGetInt(dPlayerData, xPlayerActive) == 1){
				if((trVectorQuestVarGetZ("P"+p+"Pos") > 190) && (trVectorQuestVarGetZ("P"+p+"Pos") < 196)){
					if((trVectorQuestVarGetX("P"+p+"Pos") > Shop1XMin*2) && (trVectorQuestVarGetX("P"+p+"Pos") < Shop1XMax*2)){
						if (trPlayerResourceCount(p, "Gold") >= Shop1Cost) {
							
							grantGodPowerNoRechargeNextPosition(p, "Ragnorok", 1);
							xSetInt(dPlayerData, xGold, xGetInt(dPlayerData, xGold)-1*Shop1Cost);
							count = 0;
							for(x=0; < 4) {
								if(trGetGPData(1,0,x) == 234){
									count = count + trGetGPData(1,1,x);
								}
							}
							ColouredChatToPlayer(p, "1,0.5,0", "Emergency fuel tank purchased (<u>R</u>) <color=1,1,1>["+count+"]");
						}
						else{
							ColouredChatToPlayer(p, "1,0,0", "You do not have enough gold to buy this item!");
							if(trCurrentPlayer() == p){
								playSoundCustom("cantdothat.wav", "cantdothat.wav");
							}
						}
					}
					if((trVectorQuestVarGetX("P"+p+"Pos") > Shop2XMin*2) && (trVectorQuestVarGetX("P"+p+"Pos") < Shop2XMax*2)){
						if (trPlayerResourceCount(p, "Gold") >= Shop2Cost) {
							grantGodPowerNoRechargeNextPosition(p, "Audrey", 1);
							xSetInt(dPlayerData, xGold, xGetInt(dPlayerData, xGold)-1*Shop2Cost);
							count = 0;
							for(x=0; < 4) {
								if(trGetGPData(1,0,x) == 407){
									count = count + trGetGPData(1,1,x);
								}
							}
							if(count == 0){
								count = 1;
							}
							if(Stage < 6){
								ColouredChatToPlayer(p, "1,0.5,0", "Dynamite purchased (<u>W</u>) <color=1,1,1>["+count+"]");
							}
							else if((Stage >= 6) && (Stage <= 7)){
								ColouredChatToPlayer(p, "1,0.5,0", "Plastic explosive purchased (<u>W</u>) <color=1,1,1>["+count+"]");
							}
							else if(Stage >= 8){
								ColouredChatToPlayer(p, "1,0.5,0", "Nuclear explosive purchased (<u>W</u>) <color=1,1,1>["+count+"]");
							}
						}
						else{
							ColouredChatToPlayer(p, "1,0,0", "You do not have enough gold to buy this item!");
							if(trCurrentPlayer() == p){
								playSoundCustom("cantdothat.wav", "cantdothat.wav");
							}
						}
					}
					if((trVectorQuestVarGetX("P"+p+"Pos") > Shop3XMin*2) && (trVectorQuestVarGetX("P"+p+"Pos") < Shop3XMax*2)){
						if (trPlayerResourceCount(p, "Gold") >= Shop3Cost) {
							grantGodPowerNoRechargeNextPosition(p, "Rain", 1);
							xSetInt(dPlayerData, xGold, xGetInt(dPlayerData, xGold)-1*Shop3Cost);
							count = 0;
							for(x=0; < 4) {
								if(trGetGPData(1,0,x) == 156){
									count = count + trGetGPData(1,1,x);
								}
							}
							ColouredChatToPlayer(p, "1,0.5,0", "Emergency teleport purchased (<u>E</u>) <color=1,1,1>["+count+"]");
						}
						else{
							ColouredChatToPlayer(p, "1,0,0", "You do not have enough gold to buy this item!");
						}
					}
					if((trVectorQuestVarGetX("P"+p+"Pos") > Shop4XMin*2) && (trVectorQuestVarGetX("P"+p+"Pos") < Shop4XMax*2)){
						if (trPlayerResourceCount(p, "Gold") >= Shop4Cost) {
							trUnitSelectClear();
							trUnitSelectByQV("P"+p+"Siphon");
							if(trUnitPercentDamaged() != 0){
								ColouredChatToPlayer(p, "1,0.5,0", "250hp hull repaired.");
								if(trCurrentPlayer() == p){
									playSoundCustom("roll.wav", "\Yeebaagooon\Motherload\Repair.mp3");
								}
								spyEffect(1*trQuestVarGet("P"+p+"Siphon"), kbGetProtoUnitID("White Tiger"), vector(0,0,0), vector(0,0,0), 18);
								xSetInt(dPlayerData, xGold, xGetInt(dPlayerData, xGold)-1*Shop4Cost);
								if(xGetInt(dPlayerData, xHullSpend) < 4700){
									xSetInt(dPlayerData, xHullSpend, xGetInt(dPlayerData, xHullSpend)+1*Shop4Cost);
									if ((xGetInt(dPlayerData, xBonus+20) == 0) && (xGetInt(dPlayerData, xHullSpend) >= HullSpendForBonus)){
										xSetInt(dPlayerData, xBonus+20, 1);
										if(trCurrentPlayer() == p){
											saveAllData();
											ColouredIconChat("1,0.5,0", "icons\special e son of osiris icon 64","Bonus unlocked (20)!");
											playSoundCustom("cinematics\10_in\clearedcity.wav", "\Yeebaagooon\Motherload\UnlockBonus.mp3");
										}
									}
								}
								trUnitSelectClear();
								trUnitSelectByQV("P"+p+"Siphon");
								trDamageUnit(-250);
							}
							else{
								ColouredChatToPlayer(p, "1,0,0", "You are at full health.");
								if(trCurrentPlayer() == p){
									playSoundCustom("cantdothat.wav", "cantdothat.wav");
								}
							}
						}
						else{
							ColouredChatToPlayer(p, "1,0,0", "You do not have enough gold to buy this item!");
							if(trCurrentPlayer() == p){
								playSoundCustom("cantdothat.wav", "cantdothat.wav");
							}
						}
					}
					if((trVectorQuestVarGetX("P"+p+"Pos") > Hull1XMin*2) && (trVectorQuestVarGetX("P"+p+"Pos") < 200)){
						if(GetHullShop(trVectorQuestVarGetX("P"+p+"Pos")) != 0){
							if (trPlayerResourceCount(p, "Gold") >= HullCost*GetHullShop(trVectorQuestVarGetX("P"+p+"Pos"))) {
								trUnitSelectClear();
								trUnitSelectByQV("P"+p+"Siphon");
								if(trUnitPercentDamaged() != 0){
									ColouredChatToPlayer(p, "1,0.5,0", ""+250*GetHullShop(trVectorQuestVarGetX("P"+p+"Pos"))+"" + " hp hull repaired.");
									if(trCurrentPlayer() == p){
										playSoundCustom("roll.wav", "\Yeebaagooon\Motherload\Repair.mp3");
									}
									spyEffect(1*trQuestVarGet("P"+p+"Siphon"), kbGetProtoUnitID("White Tiger"), vector(0,0,0), vector(0,0,0), 18);
									xSetInt(dPlayerData, xGold, xGetInt(dPlayerData, xGold)-1*HullCost*GetHullShop(trVectorQuestVarGetX("P"+p+"Pos")));
									if(xGetInt(dPlayerData, xHullSpend) < 4700){
										xSetInt(dPlayerData, xHullSpend, xGetInt(dPlayerData, xHullSpend)+1*HullCost*GetHullShop(trVectorQuestVarGetX("P"+p+"Pos")));
										if ((xGetInt(dPlayerData, xBonus+20) == 0) && (xGetInt(dPlayerData, xHullSpend) >= HullSpendForBonus)){
											xSetInt(dPlayerData, xBonus+20, 1);
											if(trCurrentPlayer() == p){
												saveAllData();
												ColouredIconChat("1,0.5,0", "icons\special e son of osiris icon 64","Bonus unlocked (20)!");
												playSoundCustom("cinematics\10_in\clearedcity.wav", "\Yeebaagooon\Motherload\UnlockBonus.mp3");
											}
										}
									}
									trUnitSelectClear();
									trUnitSelectByQV("P"+p+"Siphon");
									trDamageUnit(-250*GetHullShop(trVectorQuestVarGetX("P"+p+"Pos")));
								}
								else{
									ColouredChatToPlayer(p, "1,0,0", "You are at full health.");
									if(trCurrentPlayer() == p){
										playSoundCustom("cantdothat.wav", "cantdothat.wav");
									}
								}
							}
							else{
								ColouredChatToPlayer(p, "1,0,0", "You do not have enough gold to buy this item!");
							}
						}
					}
				}
				trQuestVarSet("ShopTimer", trTime()+1);
			}
		}
	}
}



rule FuelEconomy
inactive
highFrequency
//CHANGE condition to distance not time
{
	for(p = 1; < cNumberNonGaiaPlayers){
		xSetPointer(dPlayerData, p);
		if(xGetInt(dPlayerData, xPlayerActive) == 1){
			if(trDistanceToVectorSquared("P"+p+"Siphon", "P"+p+"Pos") > 0){
				trVectorSetUnitPos("P"+p+"Pos", "P"+p+"Siphon");
				if(xGetInt(dPlayerData, xFuelCountdown) != 0){
					xSetInt(dPlayerData, xFuelCountdown, 0);
				}
				if((trVectorQuestVarGetZ("P"+p+"Pos")) > MaxRows*8){
					xSetInt(dPlayerData, xDepth, 0);
					trQuestVarSet("P"+p+"Depth", 0);
				}
				else{
					FuelLoss(p);
					if(Stage < 5){
						xSetInt(dPlayerData, xDepth, (MaxRows*8-1*trVectorQuestVarGetZ("P"+p+"Pos"))*10-10);
					}
					else if((Stage >= 5) && (Stage < 7)){
						xSetInt(dPlayerData, xDepth, (MaxRows*8-1*trVectorQuestVarGetZ("P"+p+"Pos"))*15-15);
					}
					else if(Stage == 7){
						xSetInt(dPlayerData, xDepth, (MaxRows*8-1*trVectorQuestVarGetZ("P"+p+"Pos"))*20-20);
					}
					else if(Stage == 8){
						xSetInt(dPlayerData, xDepth, (MaxRows*8-1*trVectorQuestVarGetZ("P"+p+"Pos"))*25-25);
					}
					else if(Stage == 9){
						xSetInt(dPlayerData, xDepth, (MaxRows*8-1*trVectorQuestVarGetZ("P"+p+"Pos"))*50-50);
					}
				}
			}
			else{
				if((trVectorQuestVarGetZ("P"+p+"Pos")) > MaxRows*8){
					FuelBuy(p);
				}
			}
		}
		if(trCurrentPlayer() == p){
			trCounterAbort("CDFuel");
			trCounterAbort("CDDepth");
			if(cNumberNonGaiaPlayers > 2){
				//coloured fuel function
				if(xGetFloat(dPlayerData, xFuel) > xGetInt(dPlayerData, xFuelTank)*0.75){
					trCounterAddTime("CDFuel", -40, -30, "<color={PlayerColor(3)}>Fuel:" + 1*xGetFloat(dPlayerData, xFuel) + " L", -1);
					trCounterAddTime("CDDepth", -30, -20, "</color>Depth: " + 1*xGetInt(dPlayerData, xDepth) + " metres", -1);
				}
				else if(xGetFloat(dPlayerData, xFuel) < 201){
					trCounterAddTime("CDFuel", -40, -30, "<color={PlayerColor(2)}>Fuel:" + 1*xGetFloat(dPlayerData, xFuel) + " L", -1);
					trCounterAddTime("CDDepth", -30, -20, "</color>Depth: " + 1*xGetInt(dPlayerData, xDepth) + " metres", -1);
				}
				else{
					trCounterAddTime("CDFuel", -40, -30, "</color>Fuel:" + 1*xGetFloat(dPlayerData, xFuel) + " L", -1);
					trCounterAddTime("CDDepth", -30, -20, "</color>Depth: " + 1*xGetInt(dPlayerData, xDepth) + " metres", -1);
				}
			}
			else if(cNumberNonGaiaPlayers <= 2){
				trCounterAddTime("CDFuel", -40, -30, "</color>Fuel:" + 1*xGetFloat(dPlayerData, xFuel) + " L", -1);
				trCounterAddTime("CDDepth", -30, -20, "</color>Depth: " + 1*xGetInt(dPlayerData, xDepth) + " metres", -1);
			}
		}
		if((xGetFloat(dPlayerData, xFuel) <= 0) && (xGetInt(dPlayerData, xPlayerActive) == 1)){
			if(trCurrentPlayer() == p){
				trOverlayText("OUT OF FUEL!", 8.0, 508, 350, 1000);
			}
			trUnitSelectByQV("P"+p+"Siphon");
			trUnitDestroy();
			xSetInt(dPlayerData, xPlayerActive, 0);
			trSetPlayerDefeated(p);
			if (xGetInt(dPlayerData, xBonus+7) == 0){
				xSetInt(dPlayerData, xBonus+7, 1);
				if(trCurrentPlayer() == p){
					saveAllData();
					ColouredIconChat("1,0.5,0", "icons\special e son of osiris icon 64","Bonus unlocked (7)!");
					playSoundCustom("cinematics\10_in\clearedcity.wav", "\Yeebaagooon\Motherload\UnlockBonus.mp3");
				}
			}
		}
		
		if((xGetFloat(dPlayerData, xFuel) <= 200) && (1*trQuestVarGet("P"+p+"FuelWarning") == 0)){
			if(trCurrentPlayer() == p){
				trOverlayTextColour(200,0,0);
				trOverlayText("LOW FUEL WARNING! REFUEL AT THE SURFACE!", 8.0, 508, 350, 400);
				playSound("attackwarning.wav");
			}
			if (xGetInt(dPlayerData, xBonus+7) == 2){
				trChatSendToPlayer(0, p, "<color=1,0.5,0>Consider using ragnorok (R) - your emergency fuel tank!</color>");
			}
			trQuestVarSet("P"+p+"FuelWarning", 1);
		}
		if((xGetFloat(dPlayerData, xFuel) <= 150) && (1*trQuestVarGet("P"+p+"FuelWarning") == 1)){
			if(trCurrentPlayer() == p){
				trOverlayTextColour(200,0,0);
				trOverlayText("LOW FUEL WARNING!", 8.0, 508, 350, 1000);
				playSound("attackwarning.wav");
			}
			if (xGetInt(dPlayerData, xBonus+7) == 2){
				trChatSendToPlayer(0, p, "<color=1,0.5,0>Consider using ragnorok (R) - your emergency fuel tank!</color>");
			}
			trQuestVarSet("P"+p+"FuelWarning", 2);
		}
		if((xGetFloat(dPlayerData, xFuel) <= 100) && (1*trQuestVarGet("P"+p+"FuelWarning") == 2)){
			if(trCurrentPlayer() == p){
				trOverlayTextColour(200,0,0);
				trOverlayText("LOW FUEL WARNING! REFUEL AT THE SURFACE!", 8.0, 508, 350, 400);
				playSound("attackwarning.wav");
			}
			trQuestVarSet("P"+p+"FuelWarning", 3);
		}
		if((xGetInt(dPlayerData, xStageUnlocked) == 4) && (xGetInt(dPlayerData, xStageStatus) == 0) && (xGetInt(dPlayerData, xDepth) >= 2000)){
			xSetInt(dPlayerData, xStageStatus, 1);
			if (trCurrentPlayer() == p) {
				ColouredIconChat("1,0.5,0", "icons/star", "Progression goal achieved.");
			}
		}
		
		if((xGetInt(dPlayerData, xBonus+4) == 0) && (xGetInt(dPlayerData, xDepth) >= 750)){
			xSetInt(dPlayerData, xBonus+4, 1);
			if(trCurrentPlayer() == p){
				ColouredIconChat("1,0.5,0", "icons\special e son of osiris icon 64","Bonus unlocked (4)!");
				saveAllData();
				playSoundCustom("cinematics\10_in\clearedcity.wav", "\Yeebaagooon\Motherload\UnlockBonus.mp3");
			}
		}
		if((xGetInt(dPlayerData, xBonus+5) == 0) && (xGetInt(dPlayerData, xDepth) >= 1500)){
			xSetInt(dPlayerData, xBonus+5, 1);
			if(trCurrentPlayer() == p){
				ColouredIconChat("1,0.5,0", "icons\special e son of osiris icon 64","Bonus unlocked (5)!");
				saveAllData();
				playSoundCustom("cinematics\10_in\clearedcity.wav", "\Yeebaagooon\Motherload\UnlockBonus.mp3");
			}
		}
		if((Stage == 9) && (xGetInt(dPlayerData, xDepth) >= 7900)){
			xsEnableRule("SednaWin");
			xsDisableSelf();
		}
	}
}

rule FuelEconomyNatas
inactive
highFrequency
//CHANGE condition to distance not time
{
	for(p = 1; < cNumberNonGaiaPlayers){
		xSetPointer(dPlayerData, p);
		if(xGetInt(dPlayerData, xPlayerActive) == 1){
			if(trDistanceToVectorSquared("P"+p+"Siphon", "P"+p+"Pos") > 0){
				trVectorSetUnitPos("P"+p+"Pos", "P"+p+"Siphon");
				if(xGetInt(dPlayerData, xFuelCountdown) != 0){
					xSetInt(dPlayerData, xFuelCountdown, 0);
				}
				if((trVectorQuestVarGetZ("P"+p+"Pos")) > MaxRows*8){
					xSetInt(dPlayerData, xDepth, 0);
					trQuestVarSet("P"+p+"Depth", 0);
				}
				else{
					FuelLossNatas(p);
				}
			}
		}
		if(trCurrentPlayer() == p){
			trCounterAbort("CDFuel");
			if(cNumberNonGaiaPlayers > 2){
				//coloured fuel function
				if(xGetFloat(dPlayerData, xFuel) > xGetInt(dPlayerData, xFuelTank)*0.75){
					trCounterAddTime("CDFuel", -40, -30, "<color={PlayerColor(3)}>Fuel:" + 1*xGetFloat(dPlayerData, xFuel) + " L", -1);
				}
				else if(xGetFloat(dPlayerData, xFuel) < 151){
					trCounterAddTime("CDFuel", -40, -30, "<color={PlayerColor(2)}>Fuel:" + 1*xGetFloat(dPlayerData, xFuel) + " L", -1);
				}
				else{
					trCounterAddTime("CDFuel", -40, -30, "</color>Fuel:" + 1*xGetFloat(dPlayerData, xFuel) + " L", -1);
				}
			}
			else if(cNumberNonGaiaPlayers <= 2){
				trCounterAddTime("CDFuel", -40, -30, "</color>Fuel:" + 1*xGetFloat(dPlayerData, xFuel) + " L", -1);
			}
		}
		if((xGetFloat(dPlayerData, xFuel) <= 0) && (xGetInt(dPlayerData, xPlayerActive) == 1)){
			if(trCurrentPlayer() == p){
				trOverlayText("OUT OF FUEL!", 8.0, 508, 350, 1000);
			}
			trUnitSelectByQV("P"+p+"Siphon");
			trUnitDestroy();
			xSetInt(dPlayerData, xPlayerActive, 0);
			trSetPlayerDefeated(p);
		}
		
		if((xGetFloat(dPlayerData, xFuel) <= 200) && (1*trQuestVarGet("P"+p+"FuelWarning") == 0)){
			if(trCurrentPlayer() == p){
				trOverlayTextColour(200,0,0);
				trOverlayText("LOW FUEL WARNING!", 8.0, 508, 350, 1000);
				playSound("attackwarning.wav");
			}
			if (xGetInt(dPlayerData, xBonus+7) == 2){
				trChatSendToPlayer(0, p, "<color=1,0.5,0>Consider using ragnorok (R) - your emergency fuel tank!</color>");
			}
			trQuestVarSet("P"+p+"FuelWarning", 1);
		}
	}
}


/*
rule fuckssake
active
highFrequency
{
	if(trChatHistoryContains("DEBUG", 1)){
		trVectorSetUnitPos("Drone1V", "Drone1", true);
		int z = trGetNextUnitScenarioNameNumber();
		trArmyDispatch(""+cNumberNonGaiaPlayers+",0", "Dwarf", 1,trVectorQuestVarGetX("Drone1V"),0,trVectorQuestVarGetZ("Drone1V"),0,true);
		trUnitSelectClear();
		
		trUnitSelect(""+z);
		trUnitTeleport(trVectorQuestVarGetX("Drone1V"),0,trVectorQuestVarGetZ("Drone1V"));
		
		trUnitSelectClear();
		trUnitSelect(""+z);
		trUnitChangeProtoUnit("Hero Birth");
		z = trGetNextUnitScenarioNameNumber();
		trArmyDispatch(""+cNumberNonGaiaPlayers+",0", "Dwarf", 1,trVectorQuestVarGetX("Drone1V"),0,trVectorQuestVarGetZ("Drone1V"),0,true);
		trUnitSelectClear();
		
		trUnitSelect(""+z);
		trUnitTeleport(trVectorQuestVarGetX("Drone1V"),0,trVectorQuestVarGetZ("Drone1V"));
		
		trUnitSelectClear();
		trUnitSelect(""+z);
		trUnitChangeProtoUnit("Ball of Fire Impact");
		trChatHistoryClear();
		//xsDisableSelf();
		
	}
}*/


//HELP - trigtemp a chat contains
rule ChatHelpers
inactive
minInterval 2
{
	int count = 0;
	for(p=1; < cNumberNonGaiaPlayers) {
		xSetPointer(dPlayerData, p);
		if(trCurrentPlayer() == p){
			if((trChatHistoryContains("level", p) == true) || (trChatHistoryContains("drill", p) == true) || (trChatHistoryContains("mine", p) == true) || (trChatHistoryContains("help", p) == true) || (trChatHistoryContains("upgrade", p) == true)){
				if(xGetInt(dPlayerData, xStageUnlocked) < 3){
					trChatHistoryClear();
					if(aiIsMultiplayer() == true){
						ColouredChat("1,0.5,0", "To mine the ground, place your cursor over an area of land.");
						ColouredChat("1,0.5,0", "This must also be next to your fire siphon (no diagonals).");
						ColouredChat("1,0.5,0", "Then press 'Q' to drill that square.");
						ColouredChat("1,0.5,0", "Gather minerals and return them to the surface to sell them.");
						ColouredChat("1,0.5,0", "You can carry "+xGetInt(dPlayerData, xCargoHold)+" minerals at once.");
						ColouredChat("1,0.5,0", "Use your profit to upgrade your stats in singleplayer.");
						ColouredChat("1,0.5,0", "(Singleplayer - Random map - Motherload)");
					}
					else{
						ColouredChat("1,0.5,0", "Click an obelisk and you will be asked if you wish to upgrade.");
						ColouredChat("1,0.5,0", "Remember to garrison in the underworld passage to save.");
						if(1*trQuestVarGet("CineStatus") == 0){
							trChatHistoryClear();
							xsEnableRule("CineSetup");
						}
					}
				}
			}
			if((trChatHistoryContains("control", p) == true) || (trChatHistoryContains("hotkey", p) == true) || (trChatHistoryContains("inventory", p) == true) || (trChatHistoryContains("power", p) == true) || (trChatHistoryContains("inventenory", p) == true)){
				trChatHistoryClear();
				ColouredChat("1,0.5,0", "Q - Drill to cursor");
				count = 0;
				for(x=0; < 4) {
					if(trGetGPData(1,0,x) == 407){
						count = count + trGetGPData(1,1,x);
					}
				}
				if(count != 0){
					if(Stage < 6){
						ColouredChatToPlayer(p, "1,0.5,0", "W - Dynamite ("+count+")");
					}
					else if((Stage >= 6) && (Stage <= 7)){
						ColouredChatToPlayer(p, "1,0.5,0", "W - Plastic explosive ("+count+")");
					}
					else if(Stage >= 8){
						ColouredChatToPlayer(p, "1,0.5,0", "W - Nuclear explosive ("+count+")");
					}
				}
				count = 0;
				for(x=0; < 4) {
					if(trGetGPData(1,0,x) == 156){
						count = count + trGetGPData(1,1,x);
					}
				}
				if(count != 0){
					ColouredChat("1,0.5,0", "E - Emergency surface teleport ("+count+")");
				}
				count = 0;
				for(x=0; < 4) {
					if(trGetGPData(1,0,x) == 234){
						count = count + trGetGPData(1,1,x);
					}
				}
				if(count != 0){
					ColouredChat("1,0.5,0", "R - Use backup fuel tank ("+count+")");
				}
				count = 0;
				for(x=0; < 4) {
					if(trGetGPData(1,0,x) == 220){
						count = count + trGetGPData(1,1,x);
					}
				}
				if(count != 0){
					ColouredChat("1,0.5,0", "A - Activates antimatter bomb");
				}
				count = 0;
				for(x=0; < 4) {
					if(trGetGPData(1,0,x) == 557){
						count = count + trGetGPData(1,1,x);
					}
				}
				if(count != 0){
					ColouredChat("1,0.5,0", "L - Activates mining laser (cursor)");
				}
			}
			
			if((trChatHistoryContains("heal", p) == true) || (trChatHistoryContains("repair", p) == true) || (trChatHistoryContains("hitpoint", p) == true)){
				if(xGetInt(dPlayerData, xStageUnlocked) < 6){
					trChatHistoryClear();
					ColouredChat("1,0.5,0", "Go to the hull shop in the top right corner of the map to repair your ship.");
				}
			}
			if((trChatHistoryContains("fuel", p) == true) || (trChatHistoryContains("petrol", p) == true)){
				if(xGetInt(dPlayerData, xStageUnlocked) < 4){
					trChatHistoryClear();
					ColouredChat("1,0.5,0", "To refuel, go to the fuel shop in the top right corner of the map.");
					
				}
			}
			if((trChatHistoryContains("progress", p) == true) || (trChatHistoryContains("goal", p) == true) || (trChatHistoryContains("objective", p) == true) || (trChatHistoryContains("unlock", p) == true)){
				if(xGetInt(dPlayerData, xStageUnlocked) > Stage-1){
					trChatHistoryClear();
					ColouredChat("1,0.5,0", "You have already unlocked the next stage.");
				}
				if(xGetInt(dPlayerData, xStageUnlocked) < Stage-1){
					trChatHistoryClear();
					ColouredChat("1,0.5,0", "You need to beat earlier stages to unlock this planet.");
				}
				if(xGetInt(dPlayerData, xStageUnlocked) == Stage-1){
					trChatHistoryClear();
					if(Stage == 1){
						ColouredChat("1,0.5,0", "<u>To win this planet:</u>");
						if(xGetInt(dPlayerData, xGold)-xGetInt(dPlayerData, xGoldStart) < 10){
							ColouredIconChat("1,0,0", "cursors\cursor_no", "Make 10 profit ["+(xGetInt(dPlayerData, xGold)-xGetInt(dPlayerData, xGoldStart))+"]");
						}
						if(xGetInt(dPlayerData, xGold)-xGetInt(dPlayerData, xGoldStart) >= 10){
							ColouredIconChat("0,1,0", "icons\star", "Make 10 profit ["+(xGetInt(dPlayerData, xGold)-xGetInt(dPlayerData, xGoldStart))+"]");
						}
					}
					if(Stage == 2){
						ColouredChat("1,0.5,0", "<u>To win this planet:</u>");
						if(xGetInt(dPlayerData, xDrillLevel) < 2){
							ColouredIconChat("1,0,0", "cursors\cursor_no", "Upgrade drill to level 2 (in singleplayer)");
						}
						if(xGetInt(dPlayerData, xDrillLevel) >= 2){
							ColouredIconChat("0,1,0", "icons\star", "Upgrade drill to level 2");
						}
						if(xGetInt(dPlayerData, xStageStatus) != 1){
							ColouredIconChat("1,0,0", "cursors\cursor_no", "Sell gold on this stage");
						}
						if(xGetInt(dPlayerData, xStageStatus) == 1){
							ColouredIconChat("0,1,0", "icons\star", "Sell gold on this stage");
						}
						if((xGetInt(dPlayerData, xStageStatus) == 1) && (xGetInt(dPlayerData, xDrillLevel) < 2)){
							trChatSend(0, "Once this game has ended you can unlock the next planet directly in singleplayer!");
						}
					}
					if(Stage == 3){
						ColouredChat("1,0.5,0", "<u>To win this planet:</u>");
						if(xGetInt(dPlayerData, xGold)-xGetInt(dPlayerData, xGoldStart) < 25){
							ColouredIconChat("1,0,0", "cursors\cursor_no", "Make 25 profit ["+(xGetInt(dPlayerData, xGold)-xGetInt(dPlayerData, xGoldStart))+"]");
						}
						if(xGetInt(dPlayerData, xGold)-xGetInt(dPlayerData, xGoldStart) >= 25){
							ColouredIconChat("0,1,0", "icons\star", "Make 25 profit ["+(xGetInt(dPlayerData, xGold)-xGetInt(dPlayerData, xGoldStart))+"]");
						}
						if(xGetInt(dPlayerData, xHullLevel) < 3){
							ColouredIconChat("1,0,0", "cursors\cursor_no", "Upgrade hull to level 3 (in singleplayer)");
						}
						if(xGetInt(dPlayerData, xHullLevel) >= 3){
							ColouredIconChat("0,1,0", "icons\star", "Upgrade hull to level 3");
						}
						if((xGetInt(dPlayerData, xGold)-xGetInt(dPlayerData, xGoldStart) >= 25) && (xGetInt(dPlayerData, xDrillLevel) < 3)){
							trChatSend(0, "Once this game has ended you can unlock the next planet directly in singleplayer!");
						}
					}
					if(Stage == 4){
						ColouredChat("1,0.5,0", "<u>To win this planet:</u>");
						if(xGetInt(dPlayerData, xDrillLevel) < 3){
							ColouredIconChat("1,0,0", "cursors\cursor_no", "Upgrade drill to level 3 <color=1,1,1>["+xGetInt(dPlayerData, xDrillLevel)+"]");
						}
						if(xGetInt(dPlayerData, xDrillLevel) >= 3){
							ColouredIconChat("0,1,0", "icons\star", "Upgrade drill to level 3");
						}
						if(xGetInt(dPlayerData, xHullLevel) < 3){
							ColouredIconChat("1,0,0", "cursors\cursor_no", "Upgrade hull to level 3 <color=1,1,1>["+xGetInt(dPlayerData, xHullLevel)+"]");
						}
						if(xGetInt(dPlayerData, xHullLevel) >= 3){
							ColouredIconChat("0,1,0", "icons\star", "Upgrade hull to level 3");
						}
						if(xGetInt(dPlayerData, xFuelLevel) < 3){
							ColouredIconChat("1,0,0", "cursors\cursor_no", "Upgrade fuel tank to level 3 <color=1,1,1>["+xGetInt(dPlayerData, xFuelLevel)+"]");
						}
						if(xGetInt(dPlayerData, xFuelLevel) >= 3){
							ColouredIconChat("0,1,0", "icons\star", "Upgrade fuel tank to level 3");
						}
						if(xGetInt(dPlayerData, xCargoLevel) < 3){
							ColouredIconChat("1,0,0", "cursors\cursor_no", "Upgrade cargo hold to level 3 <color=1,1,1>["+xGetInt(dPlayerData, xCargoLevel)+"]");
						}
						if(xGetInt(dPlayerData, xCargoLevel) >= 3){
							ColouredIconChat("0,1,0", "icons\star", "Upgrade cargo hold to level 3");
						}
						if(xGetInt(dPlayerData, xEngineLevel) < 3){
							ColouredIconChat("1,0,0", "cursors\cursor_no", "Upgrade engine to level 3 <color=1,1,1>["+xGetInt(dPlayerData, xEngineLevel)+"]");
						}
						if(xGetInt(dPlayerData, xEngineLevel) >= 3){
							ColouredIconChat("0,1,0", "icons\star", "Upgrade engine to level 3");
						}
						if(xGetInt(dPlayerData, xRadiatorLevel) < 3){
							ColouredIconChat("1,0,0", "cursors\cursor_no", "Upgrade radiator to level 3 <color=1,1,1>["+xGetInt(dPlayerData, xRadiatorLevel)+"]");
						}
						if(xGetInt(dPlayerData, xRadiatorLevel) >= 3){
							ColouredIconChat("0,1,0", "icons\star", "Upgrade radiator to level 3");
						}
					}
					if(Stage == 5){
						ColouredChat("1,0.5,0", "<u>To win this planet:</u>");
						if(xGetInt(dPlayerData, xGold)-xGetInt(dPlayerData, xGoldStart) < 50){
							ColouredIconChat("1,0,0", "cursors\cursor_no", "Make 50 profit ["+(xGetInt(dPlayerData, xGold)-xGetInt(dPlayerData, xGoldStart))+"]");
						}
						if(xGetInt(dPlayerData, xGold)-xGetInt(dPlayerData, xGoldStart) >= 50){
							ColouredIconChat("0,1,0", "icons\star", "Make 50 profit ["+(xGetInt(dPlayerData, xGold)-xGetInt(dPlayerData, xGoldStart))+"]");
						}
						if(xGetInt(dPlayerData, xStageStatus) == 0){
							ColouredIconChat("1,0,0", "cursors\cursor_no", "Reach 2km depth");
						}
						if(xGetInt(dPlayerData, xStageStatus) == 1){
							ColouredIconChat("0,1,0", "icons\star", "Reach 2km depth");
						}
					}
					if(Stage == 6){
						ColouredChat("1,0.5,0", "<u>To win this planet:</u>");
						if(xGetInt(dPlayerData, xGold)-xGetInt(dPlayerData, xGoldStart) < 200){
							ColouredIconChat("1,0,0", "cursors\cursor_no", "Make 200 profit ["+(xGetInt(dPlayerData, xGold)-xGetInt(dPlayerData, xGoldStart))+"]");
						}
						if(xGetInt(dPlayerData, xGold)-xGetInt(dPlayerData, xGoldStart) >= 200){
							ColouredIconChat("0,1,0", "icons\star", "Make 200 profit ["+(xGetInt(dPlayerData, xGold)-xGetInt(dPlayerData, xGoldStart))+"]");
						}
						if(xGetInt(dPlayerData, xStageStatus) == 0){
							ColouredIconChat("1,0,0", "cursors\cursor_no", "Sell a diamond");
						}
						if(xGetInt(dPlayerData, xStageStatus) == 1){
							ColouredIconChat("0,1,0", "icons\star", "Sell a diamond");
						}
						if(xGetInt(dPlayerData, xDrillLevel) < 5){
							ColouredIconChat("1,0,0", "cursors\cursor_no", "Upgrade drill to level 5 <color=1,1,1>["+xGetInt(dPlayerData, xDrillLevel)+"]");
						}
						if(xGetInt(dPlayerData, xDrillLevel) >= 5){
							ColouredIconChat("0,1,0", "icons\star", "Upgrade drill to level 5");
						}
					}
					if(Stage == 7){
						ColouredChat("1,0.5,0", "<u>To win this planet:</u>");
						if(xGetInt(dPlayerData, xGold)-xGetInt(dPlayerData, xGoldStart) < 150){
							ColouredIconChat("1,0,0", "cursors\cursor_no", "Make 150 profit ["+(xGetInt(dPlayerData, xGold)-xGetInt(dPlayerData, xGoldStart))+"]");
						}
						if(xGetInt(dPlayerData, xGold)-xGetInt(dPlayerData, xGoldStart) >= 150){
							ColouredIconChat("0,1,0", "icons\star", "Make 150 profit ["+(xGetInt(dPlayerData, xGold)-xGetInt(dPlayerData, xGoldStart))+"]");
						}
						if(xGetInt(dPlayerData, xStageStatus) == 0){
							ColouredIconChat("1,0,0", "cursors\cursor_no", "Sell a lump of obsidian");
						}
						if(xGetInt(dPlayerData, xStageStatus) == 1){
							ColouredIconChat("0,1,0", "icons\star", "Sell a lump of obsidian");
						}
					}
					if(Stage == 8){
						ColouredChat("1,0.5,0", "<u>To win this planet:</u>");
						if(xGetInt(dPlayerData, xGold)-xGetInt(dPlayerData, xGoldStart) < 350){
							ColouredIconChat("1,0,0", "cursors\cursor_no", "Make 350 profit ["+(xGetInt(dPlayerData, xGold)-xGetInt(dPlayerData, xGoldStart))+"]");
						}
						if(xGetInt(dPlayerData, xGold)-xGetInt(dPlayerData, xGoldStart) >= 350){
							ColouredIconChat("0,1,0", "icons\star", "Make 350 profit ["+(xGetInt(dPlayerData, xGold)-xGetInt(dPlayerData, xGoldStart))+"]");
						}
					}
					if(Stage == 9){
						ColouredChat("1,0.5,0", "<u>To win this planet:</u>");
						ColouredIconChat("1,0,0", "cursors\cursor_no", "Reach maximum depth");
					}
				}
			}
		}
	}
}
