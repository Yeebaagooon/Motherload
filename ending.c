rule TimesUp
inactive
highFrequency
{
	xsDisableSelf();
	xsDisableRule("CheckResigns");
	xsDisableRule("FuelEconomy");
	trCounterAbort("CDFuel");
	trCounterAbort("CDDepth");
	trSetFogAndBlackmap(false, false);
	trLetterBox(true);
	for(p = 1; < cNumberNonGaiaPlayers){
		trUnitSelectByQV("P"+p+"Siphon");
		trUnitChangeProtoUnit("Hero Death");
		trUIFadeToColor(0,0,0,2000,1,true);
		xsEnableRule("EndDialog1");
	}
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
				}
			}
		} else if (xGetInt(dPlayerData, xStageUnlocked) < Stage-1) {
			trShowImageDialog(stageIcon(Stage+1), "You must beat previous planets to unlock this one.");
			trSoundPlayFN("cantdothat.wav","1",-1,"","");
		} else {
			trShowImageDialog(stageIcon(Stage+1), "You already have unlocked the next planet.");
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
	if((trTime()-cActivationTime) >= 3){
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
		xsDisableSelf();
		xsEnableRule("End2");
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
