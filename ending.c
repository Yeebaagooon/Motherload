rule TimesUp
inactive
highFrequency
{
	xsDisableRule("CheckResigns");
	xsDisableRule("FuelEconomy");
	trCounterAbort("CDFuel");
	trCounterAbort("CDDepth");
	trOverlayTextColour(255,125,0);
	trSetFogAndBlackmap(false, false);
	trLetterBox(true);
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
		} else if (xGetInt(dPlayerData, xStageUnlocked) < Stage-1) {
			trShowImageDialog(stageIcon(Stage+1), "You must beat previous planets to unlock this one.");
			trSoundPlayFN("cantdothat.wav","1",-1,"","");
		} else {
			trShowImageDialog(stageIcon(Stage+1), "You have already unlocked the next planet.");
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
		xsEnableRule("End1");
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
		trLetterBox(false);
		trUIFadeToColor(0,0,0,1500,1,false);
		xsEnableRule("End2");
		//BONUS CHECK AND UNLOCK
		for(p=1; < cNumberNonGaiaPlayers) {
			xSetPointer(dPlayerData, p);
			if ((xGetInt(dPlayerData, xBonus+8) == 0) && (1*trQuestVarGet("P"+p+"Leftover") >= 100)){
				xSetInt(dPlayerData, xBonus+8, 1);
				ColouredIconChat("1,0.5,0", "icons\special e son of osiris icon 64","Bonus unlocked - check out singleplayer!");
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
