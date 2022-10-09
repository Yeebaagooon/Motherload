rule TimesUp
inactive
highFrequency
{
	xsDisableRule("CheckResigns");
	xsDisableRule("FuelEconomy");
	trCounterAbort("CDFuel");
	trCounterAbort("CDDepth");
	trFadeOutMusic(4);
	trFadeOutAllSounds(4);
	trOverlayTextColour(255,125,0);
	trSetFogAndBlackmap(false, false);
	trLetterBox(true);
	playSoundCustom("vortexstart.wav", "\Yeebaagooon\Motherload\Beam Up.mp3");
	int temp = 0;
	for (x=xGetDatabaseCount(dHeldRelics); > 0) {
		xDatabaseNext(dHeldRelics);
		for(p=1; < cNumberNonGaiaPlayers) {
			if (trUnitIsOwnedBy(p)) {
				xUnitSelect(dHeldRelics, xRelicName);
				trQuestVarSet("P"+p+"Leftover", 1*trQuestVarGet("P"+p+"Leftover")+relicCost(xGetInt(dHeldRelics, xRelicValue)));
			}
		}
	}
	for (x=xGetDatabaseCount(dHiddenRelics); > 0) {
		xDatabaseNext(dHiddenRelics);
		for(p=1; < cNumberNonGaiaPlayers) {
			if (xGetInt(dHiddenRelics, xOwner) == p) {
				xUnitSelect(dHiddenRelics, xRelicName);
				trQuestVarSet("P"+p+"Leftover", 1*trQuestVarGet("P"+p+"Leftover")+relicCost(xGetInt(dHiddenRelics, xRelicValue)));
			}
		}
	}
	for(p = 1; < cNumberNonGaiaPlayers){
		temp = trGetNextUnitScenarioNameNumber();
		trArmyDispatch("0,0", "Dwarf", 1, trVectorQuestVarGetX("P"+p+"Pos"), 0, trVectorQuestVarGetZ("P"+p+"Pos"), 0, false);
		trUnitSelect(""+temp);
		trUnitTeleport(trVectorQuestVarGetX("P"+p+"Pos"), 0, trVectorQuestVarGetZ("P"+p+"Pos"));
		trUnitSelectClear();
		trUnitSelect(""+temp);
		trMutateSelected(kbGetProtoUnitID("Deconstruct Unit"));
		trUnitSelectClear();
		trUnitSelect(""+temp);
		trUnitOverrideAnimation(18,0,false,false,-1);
		trUnitSelectByQV("P"+p+"Siphon");
		trUnitChangeProtoUnit("Hero Death");
		trUIFadeToColor(0,0,0,2000,1,true);
		xSetPointer(dPlayerData, p);
		if (xGetInt(dPlayerData, xBonus+8) == 2){
			xSetInt(dPlayerData, xGold, xGetInt(dPlayerData, xGold)+1*trQuestVarGet("P"+p+"Leftover"));
			if(trCurrentPlayer() == p){
				characterDialog("Left over gold added to your total!", ""+1*trQuestVarGet("P"+p+"Leftover")+"", "icons\special e son of osiris icon 64");
			}
		}
		
	}
	xsEnableRule("EndDialog1");
	xsDisableSelf();
}

rule EndDialog1
inactive
highFrequency
{
	if((trTime()-cActivationTime) >= 1){
		int p = trCurrentPlayer();
		xSetPointer(dPlayerData, p);
		trQuestVarSet("Profit", xGetInt(dPlayerData, xGold)-xGetInt(dPlayerData, xGoldStart));
		characterDialog(stageName(Stage) + " complete!", "You have made " +1*trQuestVarGet("Profit") + " gold profit here.", "icons\special e son of osiris icon 64");
		if(Stage == 9){
			characterDialog("Mr Natas", "I TOLD YOU THIS PLANET IS FORBIDDEN!", "icons\scenario g gargarensis icon 64");
		}
		xsDisableSelf();
		xsEnableRule("EndDialog2");
	}
	
}

rule EndDialog2
inactive
highFrequency
{
	if((trTime()-cActivationTime) >= 3){
		if(OverrideSP == true){
			pause(0);
		}
		int p = trCurrentPlayer();
		xSetPointer(dPlayerData, p);
		if (xGetInt(dPlayerData, xStageUnlocked) == Stage-1) {
			//Can unlock next planet
			if(Stage == 1){
				if(xGetInt(dPlayerData, xGold)-xGetInt(dPlayerData, xGoldStart) < 10){
					characterDialog("You did not meet the requirements to progress.", "You needed to make 10 gold profit.", "icons\special e son of osiris icon 64");
				}
				else{
					xSetInt(dPlayerData, xStageUnlocked, xGetInt(dPlayerData, xStageUnlocked) + 1);
					trShowImageDialog(stageIcon(Stage+1), "Next planet unlocked - " + stageName(Stage+1));
					xSetInt(dPlayerData, xStageStatus, 0);
				}
			}
			//Upgrade requirements for Stage 2
			//128 characters combined max!!!
			if(Stage == 2){
				if((xGetInt(dPlayerData, xStageStatus) == 0) || (xGetInt(dPlayerData, xDrillLevel) == 1)){
					if((xGetInt(dPlayerData, xStageStatus) == 0) && (xGetInt(dPlayerData, xDrillLevel) == 1)){
						characterDialog("You did not meet the requirements to progress.", "You needed to sell a gold mineral and upgrade your drill to level 2.", "icons\special e son of osiris icon 64");
					}
					if((xGetInt(dPlayerData, xStageStatus) == 0) && (xGetInt(dPlayerData, xDrillLevel) > 1)){
						characterDialog("You did not meet the requirements to progress.", "You needed to sell a gold mineral.", "icons\special e son of osiris icon 64");
					}
					if((xGetInt(dPlayerData, xStageStatus) == 1) && (xGetInt(dPlayerData, xDrillLevel) == 1)){
						characterDialog("You do not meet the requirements to progress.", "You need to upgrade your drill to level 2 (in singleplayer).", "icons\special e son of osiris icon 64");
					}
				}
				else{
					xSetInt(dPlayerData, xStageUnlocked, xGetInt(dPlayerData, xStageUnlocked) + 1);
					xSetInt(dPlayerData, xStageStatus, 0);
					trShowImageDialog(stageIcon(Stage+1), "Next planet unlocked - " + stageName(Stage+1));
				}
			}
			if(Stage == 3){
				if(xGetInt(dPlayerData, xGold)-xGetInt(dPlayerData, xGoldStart) < 25){
					characterDialog("You did not meet the requirements to progress.", "You needed to make 25 gold profit.", "icons\special e son of osiris icon 64");
				}
				else{
					if(xGetInt(dPlayerData, xHullLevel) < 3){
						characterDialog("You do not meet the requirements to progress.", "You need level 3 hull.", "icons\special e son of osiris icon 64");
						xSetInt(dPlayerData, xStageStatus, 1);
					}
					else{
						xSetInt(dPlayerData, xStageUnlocked, xGetInt(dPlayerData, xStageUnlocked) + 1);
						trShowImageDialog(stageIcon(Stage+1), "Next planet unlocked - " + stageName(Stage+1));
						xSetInt(dPlayerData, xStageStatus, 0);
					}
				}
			}
			if(Stage == 4){
				if((xGetInt(dPlayerData, xDrillLevel) < 3) || (xGetInt(dPlayerData, xHullLevel) < 3) || (xGetInt(dPlayerData, xFuelLevel) < 3) || (xGetInt(dPlayerData, xEngineLevel) < 3) || (xGetInt(dPlayerData, xCargoLevel) < 3) || (xGetInt(dPlayerData, xRadiatorLevel) < 3)){
					characterDialog("You do not meet the requirements to progress.", "All ship attributes must be at least level 3.", "icons\special e son of osiris icon 64");
					xSetInt(dPlayerData, xStageStatus, 1);
				}
				else{
					xSetInt(dPlayerData, xStageUnlocked, xGetInt(dPlayerData, xStageUnlocked) + 1);
					trShowImageDialog(stageIcon(Stage+1), "Next planet unlocked - " + stageName(Stage+1));
					xSetInt(dPlayerData, xStageStatus, 0);
				}
			}
			if(Stage == 5){
				if(xGetInt(dPlayerData, xGold)-xGetInt(dPlayerData, xGoldStart) < 50){
					characterDialog("You did not meet the requirements to progress.", "You needed to make 50 gold profit.", "icons\special e son of osiris icon 64");
				}
				else{
					if(xGetInt(dPlayerData, xStageStatus) == 0){
						characterDialog("You did not meet the requirements to progress.", "You needed to reach 2km depth.", "icons\special e son of osiris icon 64");
					}
					else{
						xSetInt(dPlayerData, xStageUnlocked, xGetInt(dPlayerData, xStageUnlocked) + 1);
						trShowImageDialog(stageIcon(Stage+1), "Next planet unlocked - " + stageName(Stage+1));
						xSetInt(dPlayerData, xStageStatus, 0);
					}
				}
			}
			if(Stage == 6){
				if(xGetInt(dPlayerData, xGold)-xGetInt(dPlayerData, xGoldStart) < 200){
					characterDialog("You did not meet the requirements to progress.", "You needed to make 200 gold profit.", "icons\special e son of osiris icon 64");
				}
				else{
					if((xGetInt(dPlayerData, xStageStatus) == 0) || (xGetInt(dPlayerData, xDrillLevel) < 5)){
						if((xGetInt(dPlayerData, xStageStatus) == 0) && (xGetInt(dPlayerData, xDrillLevel) < 5)){
							characterDialog("You did not meet the requirements to progress.", "You needed to sell a diamond and upgrade your drill to level 5.", "icons\special e son of osiris icon 64");
						}
						if((xGetInt(dPlayerData, xStageStatus) == 0) && (xGetInt(dPlayerData, xDrillLevel) >= 5)){
							characterDialog("You did not meet the requirements to progress.", "You needed to sell a diamond mineral.", "icons\special e son of osiris icon 64");
						}
						if((xGetInt(dPlayerData, xStageStatus) == 1) && (xGetInt(dPlayerData, xDrillLevel) < 5)){
							characterDialog("You do not meet the requirements to progress.", "You need to upgrade your drill to level 5 (in singleplayer).", "icons\special e son of osiris icon 64");
						}
					}
					else{
						xSetInt(dPlayerData, xStageUnlocked, xGetInt(dPlayerData, xStageUnlocked) + 1);
						trShowImageDialog(stageIcon(Stage+1), "Next planet unlocked - " + stageName(Stage+1));
						xSetInt(dPlayerData, xStageStatus, 0);
					}
				}
			}
			if(Stage == 7){
				if(xGetInt(dPlayerData, xGold)-xGetInt(dPlayerData, xGoldStart) < 150){
					characterDialog("You did not meet the requirements to progress.", "You needed to make 150 gold profit.", "icons\special e son of osiris icon 64");
				}
				else{
					if(xGetInt(dPlayerData, xStageStatus) == 0){
						characterDialog("You did not meet the requirements to progress.", "You need to sell obsidian.", "icons\special e son of osiris icon 64");
					}
					else{
						xSetInt(dPlayerData, xStageUnlocked, xGetInt(dPlayerData, xStageUnlocked) + 1);
						trShowImageDialog(stageIcon(Stage+1), "Next planet unlocked - " + stageName(Stage+1));
						xSetInt(dPlayerData, xStageStatus, 0);
					}
				}
			}
			if(Stage == 8){
				if(xGetInt(dPlayerData, xGold)-xGetInt(dPlayerData, xGoldStart) < 350){
					characterDialog("You did not meet the requirements to progress.", "You needed to make 350 gold profit.", "icons\special e son of osiris icon 64");
				}
				else{
					xSetInt(dPlayerData, xStageUnlocked, xGetInt(dPlayerData, xStageUnlocked) + 1);
					trShowImageDialog(stageIcon(Stage+1), "Next planet unlocked - " + stageName(Stage+1));
					xSetInt(dPlayerData, xStageStatus, 0);
				}
			}
		} else if (xGetInt(dPlayerData, xStageUnlocked) < Stage-1) {
			trShowImageDialog(stageIcon(Stage+1), "You must beat previous planets to unlock this one.");
			trSoundPlayFN("cantdothat.wav","1",-1,"","");
		} else {
			trShowImageDialog(stageIcon(Stage+1), "You have already unlocked the next planet.");
		}
		if(Stage == 9){
			characterDialog("Mr Natas", "NEVER COME BACK HERE, MINE OTHER PLANETS ONLY!", "icons\scenario g gargarensis icon 64");
		}
		gadgetUnreal("ShowImageBox-BordersTop");
		gadgetUnreal("ShowImageBox-BordersBottom");
		gadgetUnreal("ShowImageBox-BordersLeft");
		gadgetUnreal("ShowImageBox-BordersRight");
		gadgetUnreal("ShowImageBox-BordersLeftTop");
		gadgetUnreal("ShowImageBox-BordersLeftBottom");
		gadgetUnreal("ShowImageBox-BordersRightBottom");
		gadgetUnreal("ShowImageBox-BordersRightTop");
		gadgetUnreal("ShowImageBox-CloseButton");
		pause(0);
		xsDisableSelf();
		if(NewPlayers == 0){
			xsEnableRule("End1");
		}
		else{
			xsEnableRule("End0");
		}
	}
	
}

rule ProfitChat
inactive
highFrequency
{
	for(p = 1; < cNumberNonGaiaPlayers){
		xSetPointer(dPlayerData, p);
		trQuestVarSet("P"+p+"Profit",xGetInt(dPlayerData, xGold)-xGetInt(dPlayerData, xGoldStart));
		trQuestVarSet("P"+p+"Place",1);
	}
	for(p = 1; < cNumberNonGaiaPlayers){
		for(x = 1; < cNumberNonGaiaPlayers){
			if(1*trQuestVarGet("P"+p+"Profit") < 1*trQuestVarGet("P"+x+"Profit")){
				trQuestVarModify("P"+p+"Place", "+", 1);
			}
		}
	}
	trChatSend(0, "<color=1,0.5,0><u>Mr Natas' " + stageName(Stage) + " Report:</u></color>");
	for(p = 1; < cNumberNonGaiaPlayers){
		for(x = 1; < cNumberNonGaiaPlayers){
			if(1*trQuestVarGet("P"+p+"Place") == x){
				if(x == 1){
					trChatSend(0, "<color={PlayerColor("+p+")}><icon=(20)(icons/star)> {Playername("+p+")} - "+1*trQuestVarGet("P"+p+"Profit")+"");
				}
				else{
					trChatSend(0, "<color={PlayerColor("+p+")}>{Playername("+p+")} - "+1*trQuestVarGet("P"+p+"Profit")+"");
				}
			}
		}
	}
	xsDisableSelf();
}

rule End0
inactive
highFrequency
{
	if((trTime()-cActivationTime) >= 4){
		gadgetUnreal("ShowImageBox");
		gadgetReal("ShowImageBox-BordersTop");
		gadgetReal("ShowImageBox-BordersBottom");
		gadgetReal("ShowImageBox-BordersLeft");
		gadgetReal("ShowImageBox-BordersRight");
		gadgetReal("ShowImageBox-BordersLeftTop");
		gadgetReal("ShowImageBox-BordersLeftBottom");
		gadgetReal("ShowImageBox-BordersRightBottom");
		gadgetReal("ShowImageBox-BordersRightTop");
		gadgetReal("ShowImageBox-CloseButton");
		xsEnableRule("End1");
		characterDialog("Launch this map in singleplayer to upgrade your ship.", "Singleplayer > Random Map > Motherload", "icons\special e son of osiris icon 64");
		xsDisableSelf();
	}
	
}

rule End1
inactive
highFrequency
{
	if((trTime()-cActivationTime) >= 4){
		gadgetUnreal("ShowImageBox");
		gadgetReal("ShowImageBox-BordersTop");
		gadgetReal("ShowImageBox-BordersBottom");
		gadgetReal("ShowImageBox-BordersLeft");
		gadgetReal("ShowImageBox-BordersRight");
		gadgetReal("ShowImageBox-BordersLeftTop");
		gadgetReal("ShowImageBox-BordersLeftBottom");
		gadgetReal("ShowImageBox-BordersRightBottom");
		gadgetReal("ShowImageBox-BordersRightTop");
		gadgetReal("ShowImageBox-CloseButton");
		if(Stage != 9){
			trLetterBox(false);
			trUIFadeToColor(0,0,0,1500,1,false);
		}
		xsEnableRule("End2");
		if(Stage != 10){
			xsEnableRule("ProfitChat");
		}
		//BONUS CHECK AND UNLOCK
		for(p=1; < cNumberNonGaiaPlayers) {
			xSetPointer(dPlayerData, p);
			if ((xGetInt(dPlayerData, xBonus+8) == 0) && (1*trQuestVarGet("P"+p+"Leftover") >= 100)){
				xSetInt(dPlayerData, xBonus+8, 1);
				ColouredIconChat("1,0.5,0", "icons\special e son of osiris icon 64","Bonus unlocked! (8)");
				if(trCurrentPlayer() == p){
					playSoundCustom("cinematics\10_in\clearedcity.wav", "\Yeebaagooon\Motherload\UnlockBonus.mp3");
				}
			}
		}
		xsDisableSelf();
	}
	
}

rule End2
inactive
highFrequency
{
	if((trTime()-cActivationTime) >= 2){
		for(p = 1; < cNumberNonGaiaPlayers){
			trSetPlayerWon(p);
		}
		saveAllData();
		xsDisableSelf();
		trEndGame();
	}
	
}

rule SednaWin
inactive
highFrequency
{
	trCounterAbort("CDSTage");
	StageTime = StageTime+100;
	xsDisableSelf();
	xsDisableRule("CheckResigns");
	xsDisableRule("FuelEconomy");
	trCounterAbort("CDFuel");
	trCounterAbort("CDDepth");
	trFadeOutMusic(1);
	trFadeOutAllSounds(1);
	trSetFogAndBlackmap(false, false);
	//trLetterBox(true);
	unitTransform("Invisible Wall", "Rocket");
	unitTransform("Bolder Rolling", "Rocket");
	unitTransform("Flag Numbered", "Rocket");
	unitTransform("Dwarven Forge", "Rocket");
	trPaintTerrain(70,0,100,30,5,4,true);
	trCameraCut(vector(183.582794,86.963791,-54.754787), vector(0.001486,-0.784815,0.619728), vector(0.001882,0.619729,0.784813), vector(0.999997,0.000000,-0.002398));
	int z = trGetNextUnitScenarioNameNumber();
	trArmyDispatch("0,0","Dwarf",1,198,0,2,0,true);
	trUnitSelectClear();
	trUnitSelect(""+z, true);
	trUnitChangeProtoUnit("Spy Eye");
	trUnitSelectClear();
	trUnitSelect(""+z, true);
	trMutateSelected(kbGetProtoUnitID("Tartarian Gate"));
	trSetSelectedScale(0,0,0);
	trUnitOverrideAnimation(15,0,true,false,-1);
	xsEnableRule("Sedna_C01");
	trQuestVarSet("ShowSpaceship", 1);
	for(x=xGetDatabaseCount(dFreeRelics); >0) {
		xDatabaseNext(dFreeRelics);
		xUnitSelect(dFreeRelics,xRelicName);
		trUnitDestroy();
		xFreeDatabaseBlock(dFreeRelics);
	}
	aiPlanDestroy(dFreeRelics);
	for(x=xGetDatabaseCount(dHeldRelics); >0) {
		xDatabaseNext(dHeldRelics);
		xUnitSelect(dHeldRelics,xRelicName);
		trUnitDestroy();
		xFreeDatabaseBlock(dHeldRelics);
	}
	aiPlanDestroy(dHeldRelics);
	for(x=xGetDatabaseCount(dHiddenRelics); >0) {
		xDatabaseNext(dHiddenRelics);
		xUnitSelect(dHiddenRelics,xRelicName);
		trUnitDestroy();
		xFreeDatabaseBlock(dHeldRelics);
	}
	aiPlanDestroy(dHiddenRelics);
	for(x=xGetDatabaseCount(dSelectables); >0) {
		xDatabaseNext(dSelectables);
		xUnitSelect(dSelectables,xSelectablesName);
		trUnitDestroy();
		xFreeDatabaseBlock(dSelectables);
	}
	for(p=1 ; < cNumberNonGaiaPlayers){
		xSetPointer(dPlayerData, p);
		if(xGetInt(dPlayerData, xStageUnlocked) == 8){
			xSetInt(dPlayerData, xStageUnlocked, xGetInt(dPlayerData, xStageUnlocked) + 1);
			xSetInt(dPlayerData, xStageStatus, 0);
		}
	}
}

rule Sedna_C01
inactive
highFrequency
{
	if((trTime()-cActivationTime) >= 2){
		trSetLighting("default", 0.1);
		xsDisableSelf();
		trPaintTerrain(0,0,100,100,5,4,true);
		PaintPlanets(20,20, 1);
		createCameraTrack(6000);
		trCameraCut(vector(135.184204,18.803818,67.302444), vector(0.525215,-0.390706,-0.755976), vector(0.222924,0.920516,-0.320868), vector(-0.821253,0.000000,-0.570566));
		addCameraTrackWaypoint();
		trCameraCut(vector(114.885735,32.723816,92.523201), vector(0.687415,-0.390706,-0.612217), vector(0.291768,0.920516,-0.259850), vector(-0.665080,0.000001,-0.746772));
		addCameraTrackWaypoint();
		trCameraCut(vector(72.329529,32.723816,85.053596), vector(0.948432,-0.165631,-0.270265), vector(0.159291,0.986188,-0.045390), vector(-0.274050,0.000001,-0.961716));
		addCameraTrackWaypoint();
		trCameraCut(vector(90.976700,37.763817,-31.971802), vector(0.634111,-0.165631,0.755295), vector(0.106500,0.986188,0.126852), vector(0.765873,-0.000001,-0.642992));
		addCameraTrackWaypoint();
		playCameraTrack();
		for(p=1 ; < cNumberNonGaiaPlayers){
			xSetPointer(dPlayerData, p);
			if(xGetInt(dPlayerData, xStageUnlocked) == 9){
				trOverlayText(stageName(10) + " unlocked!", 8.0, 489, 300, 1000);
			}
			else if(xGetInt(dPlayerData, xStageUnlocked) >= 10){
				trOverlayText(stageName(10) + "!", 8.0, 489, 300, 1000);
			}
			else{
				trOverlayText("You need to beat all other planets to unlock this stage", 8.0, 409, 300, 1000);
			}
		}
		xsEnableRule("End1");
		trChatHistoryClear();
	}
}
