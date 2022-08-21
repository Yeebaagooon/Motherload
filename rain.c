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
	xsDisableSelf();
}

void CustomContent(int p = 0){
	xsDisableSelf();
	trQuestVarSet("CustomContent", 1);
	trChatSend(0, "Custom Content enabled!");
}

rule SPCineChoice
inactive
highFrequency
{
	if((trTime()-cActivationTime) >= 1){
		xsDisableSelf();
		trShowChoiceDialog("Play opening cinematic?", "Yes", 15, "No", 16);
	}
}

void SPCineYes(int p = 0){
	trChatSend(0, "Yes cine");
}

void SPCineNo(int p = 0){
	trChatSend(0, "No cine");
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
		for(p = 1; < cNumberNonGaiaPlayers){
			xSetPointer(dPlayerData, p);
			if(xGetInt(dPlayerData, xPlayerActive) == 1){
				trQuestVarSet("P"+p+"Siphon", trGetNextUnitScenarioNameNumber());
				//VECTOR IS 2X+1
				if(Stage <= 2){
					UnitCreate(p, "Hero Greek Atalanta", 75+5*p, 180, 180);
				}
				else{
					UnitCreate(p, "Hero Greek Atalanta", 35+5*p, 168, 180);
				}
				yAddToDatabase("Siphon"+p+"", "P"+p+"Siphon");
				trPlayerSetDiplomacy(0, p, "Enemy");
				trUnitSelectClear();
				trUnitSelectByQV("P"+p+"Siphon");
				trSetSelectedScale(1,0.1,1);
				spyEffect(1*trQuestVarGet("P"+p+"Siphon"), kbGetProtoUnitID("Fire Siphon"), vector(0,0,0), vector(1,1,1));
				/*trUnitSelectByQV("P"+p+"Siphon", false);
				trQuestVarSet("P"+p+"MainSpy", trGetNextUnitScenarioNameNumber());
				trTechInvokeGodPower(0, "spy", vector(0,0,0), vector(0,0,0));*/
				//trDelayedRuleActivation("ChangeMainSpy1");
				trPlayerGrantResources(p, "Gold", 1*trQuestVarGet("p"+p+"goldGrant"));
				xSetFloat(dPlayerData, xFuel, xGetInt(dPlayerData, xFuelTank));
			}
			//trChatSend(0, "P"+p+"gold is " + 1*trQuestVarGet("p"+p+"goldGrant"));
			//trChatSend(0, "p"+p+"Drill level is " + xGetInt(dPlayerData, xDrillLevel));
			//trChatSend(0, "p"+p+"Rad level is " + xGetInt(dPlayerData, xRadiatorLevel));
		}
		xsDisableSelf();
		trDelayedRuleActivation("FadeOut");
		unitTransform("Outpost", "Rocket");
		trSetFogAndBlackmap(true, true);
		//trShowImageDialog(stageIcon(Stage), stageName(Stage));
		/*
		trQuestVarSet("P1EnginePower", 100);
		trQuestVarSet("P1Radiator", 0.1);
		xsEnableRule("TEMPfuel");
		*/
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
	}
	xsEnableRule("FuelEconomy");
	xsEnableRule("StageTimer");
	xsEnableRule("CheckResigns");
}

rule StageTimer
inactive
highFrequency
{
	if((trTime()-cActivationTime) >= 20){ //60
		if(Stage == 1){
			StageTime = 480; //480
			trCounterAddTime("CDSTage", StageTime, 0, "<color={PlayerColor(1)}>Time remaining", -1);
		}
		if(Stage == 2){
			StageTime = 480; //480
			trCounterAddTime("CDSTage", StageTime, 0, "<color={PlayerColor(1)}>Time remaining", -1);
		}
		if(Stage == 3){
			StageTime = 480; //480
			trCounterAddTime("CDSTage", StageTime, 0, "<color={PlayerColor(1)}>Time remaining", -1);
		}
		if(Stage == 4){
			StageTime = 480; //480
			trCounterAddTime("CDSTage", StageTime, 0, "<color={PlayerColor(1)}>Time remaining", -1);
		}
		if(Stage == 5){
			StageTime = 480; //480
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
						xSetFloat(dPlayerData, xFuel, xGetInt(dPlayerData, xFuelTank));
						xSetInt(dPlayerData, xFuelCountdown, 0);
						spyEffect(1*trQuestVarGet("P"+p+"Siphon"), kbGetProtoUnitID("Mountain Giant"), vector(0,0,0), vector(0,0,0), 18);
					}
					else if(Stage != 1){
						xSetFloat(dPlayerData, xFuel, xGetFloat(dPlayerData, xFuel)+1000*GetFuelPump(trVectorQuestVarGetX("P"+p+"Pos"),trVectorQuestVarGetZ("P"+p+"Pos")));
						xSetInt(dPlayerData, xFuelCountdown, 0);
						trPlayerGrantResources(p, "Gold", -1*FuelCost*GetFuelPump(trVectorQuestVarGetX("P"+p+"Pos"),trVectorQuestVarGetZ("P"+p+"Pos")));
						ColouredChatToPlayer(p, "0,1,0", "Refuel complete.");
						spyEffect(1*trQuestVarGet("P"+p+"Siphon"), kbGetProtoUnitID("Mountain Giant"), vector(0,0,0), vector(0,0,0), 18);
						if(xGetFloat(dPlayerData, xFuel) > xGetInt(dPlayerData,xFuelTank)){
							xSetFloat(dPlayerData, xFuel, xGetInt(dPlayerData, xFuelTank));
						}
						
					}
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
			if((trVectorQuestVarGetZ("P"+p+"Pos") > 190) && (trVectorQuestVarGetZ("P"+p+"Pos") < 196)){
				if((trVectorQuestVarGetX("P"+p+"Pos") > Shop1XMin*2) && (trVectorQuestVarGetX("P"+p+"Pos") < Shop1XMax*2)){
					if (trPlayerResourceCount(p, "Gold") >= Shop1Cost) {
						ColouredChatToPlayer(p, "1,0.5,0", "Emergency fuel tank purchased (<u>R</u>).");
						grantGodPowerNoRechargeNextPosition(p, "Ragnorok", 1);
						trPlayerGrantResources(p, "Gold", -1*Shop1Cost);
					}
					else{
						ColouredChatToPlayer(p, "1,0,0", "You do not have enough gold to buy this item!");
					}
				}
				if((trVectorQuestVarGetX("P"+p+"Pos") > Shop2XMin*2) && (trVectorQuestVarGetX("P"+p+"Pos") < Shop2XMax*2)){
					if (trPlayerResourceCount(p, "Gold") >= Shop2Cost) {
						ColouredChatToPlayer(p, "1,0.5,0", "Dynamite purchased (<u>W</u>).");
						grantGodPowerNoRechargeNextPosition(p, "Audrey", 1);
						trPlayerGrantResources(p, "Gold", -1*Shop2Cost);
					}
					else{
						ColouredChatToPlayer(p, "1,0,0", "You do not have enough gold to buy this item!");
					}
				}
				if((trVectorQuestVarGetX("P"+p+"Pos") > Shop3XMin*2) && (trVectorQuestVarGetX("P"+p+"Pos") < Shop3XMax*2)){
					if (trPlayerResourceCount(p, "Gold") >= Shop3Cost) {
						ColouredChatToPlayer(p, "1,0.5,0", "Emergency teleport purchased (<u>E</u>).");
						grantGodPowerNoRechargeNextPosition(p, "Rain", 1);
						trPlayerGrantResources(p, "Gold", -1*Shop3Cost);
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
							trPlayerGrantResources(p, "Gold", -1*Shop4Cost);
							trUnitSelectClear();
							trUnitSelectByQV("P"+p+"Siphon");
							trDamageUnit(-250);
						}
						else{
							ColouredChatToPlayer(p, "1,0,0", "You are at full health.");
						}
					}
					else{
						ColouredChatToPlayer(p, "1,0,0", "You do not have enough gold to buy this item!");
					}
				}
			}
			trQuestVarSet("ShopTimer", trTime()+1);
		}
	}
}


rule FuelEconomy
inactive
highFrequency
//CHANGE condition to distance not time
{
	for(p = 1; <= cNumberNonGaiaPlayers){
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
					xSetInt(dPlayerData, xDepth, (MaxRows*8-1*trVectorQuestVarGetZ("P"+p+"Pos"))*10-10);
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
				else if(xGetFloat(dPlayerData, xFuel) < 151){
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
			trChatSendToPlayer(0, p, "OUT OF FUEL DEATH");
			trUnitSelectByQV("P"+p+"Siphon");
			trUnitDestroy();
			xSetInt(dPlayerData, xPlayerActive, 0);
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
