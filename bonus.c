rule Bonus_Display
inactive
highFrequency
{
	if((trTime()-cActivationTime) >= 2){
		xSetPointer(dPlayerData, 1);
		if((xGetInt(dPlayerData, xStageUnlocked) == 10) && (1*trQuestVarGet("CineStatus") == 1)){
			trQuestVarSet("CineStatus", 2);
			startNPCDialog(30);
			playSoundCustom("cinematics\10_in\clearedcity.wav", "\Yeebaagooon\Motherload\UnlockBonus.mp3");
		}
		if(xGetInt(dPlayerData, xBonus+1) != 0){
			trUnitSelectByQV("Bonus1");
			trUnitChangeProtoUnit("Statue of Major God");
			xAddDatabaseBlock(dSelectables, true);
			xSetInt(dSelectables, xSelectablesName, 1*trQuestVarGet("Bonus1"));
			xSetInt(dSelectables, xSelectablesPrompt, 701);
			if(xGetInt(dPlayerData, xBonus+1) == 2){
				trUnitSelectByQV("BonusEffect1");
				trUnitChangeProtoUnit("Gaia Forest effect");
				trUnitSelectByQV("BonusUnit");
				trUnitChangeProtoUnit("Statue of Major God");
			}
		}
		else if(xGetInt(dPlayerData, xBonus+1) == 0){
			if(1*trQuestVarGet("CustomContent") == 1){
				trUnitSelectByQV("Bonus1");
				trUnitChangeProtoUnit("Statue of Major God");
				trUnitSelectByQV("Bonus1");
				trUnitHighlight(5,true);
				xSetInt(dPlayerData, xBonus+1, 1);
				xAddDatabaseBlock(dSelectables, true);
				xSetInt(dSelectables, xSelectablesName, 1*trQuestVarGet("Bonus1"));
				xSetInt(dSelectables, xSelectablesPrompt, 701);
			}
			if(1*trQuestVarGet("CustomContent") == 0){
				trUnitSelectByQV("Bonus1");
				trUnitChangeProtoUnit("Outpost");
				trUnitSelectByQV("Bonus1");
				trSetSelectedScale(0.5,0.1,0.5);
				xAddDatabaseBlock(dSelectables, true);
				xSetInt(dSelectables, xSelectablesName, 1*trQuestVarGet("Bonus1"));
				xSetInt(dSelectables, xSelectablesPrompt, 731);
			}
		}
		//Already unlcoked
		if(xGetInt(dPlayerData, xBonus+2) != 0){
			trUnitSelectByQV("Bonus2");
			trUnitChangeProtoUnit("Well of Urd");
			trUnitSelectByQV("Bonus2");
			trSetSelectedScale(0.5,0.5,0.5);
			xAddDatabaseBlock(dSelectables, true);
			xSetInt(dSelectables, xSelectablesName, 1*trQuestVarGet("Bonus2"));
			xSetInt(dSelectables, xSelectablesPrompt, 702);
			if(xGetInt(dPlayerData, xBonus+2) == 2){
				trUnitSelectByQV("BonusEffect2");
				trUnitChangeProtoUnit("Gaia Forest effect");
				trUnitSelectByQV("BonusUnit");
				trUnitChangeProtoUnit("Well of Urd");
				trUnitSelectByQV("BonusUnit");
				trSetSelectedScale(0.5,0.5,0.5);
			}
		}
		//Actively unlock in SP
		else if(xGetInt(dPlayerData, xBonus+2) == 0){
			if(1*trQuestVarGet("CineStatus") != 0){
				trUnitSelectByQV("Bonus2");
				trUnitChangeProtoUnit("Well of Urd");
				trUnitSelectByQV("Bonus2");
				trSetSelectedScale(0.5,0.5,0.5);
				trUnitSelectByQV("Bonus2");
				trUnitHighlight(5,true);
				xSetInt(dPlayerData, xBonus+2, 1);
				xAddDatabaseBlock(dSelectables, true);
				xSetInt(dSelectables, xSelectablesName, 1*trQuestVarGet("Bonus2"));
				xSetInt(dSelectables, xSelectablesPrompt, 702);
			}
			if(1*trQuestVarGet("CineStatus") == 0){
				trUnitSelectByQV("Bonus2");
				trUnitChangeProtoUnit("Outpost");
				trUnitSelectByQV("Bonus2");
				trSetSelectedScale(0.5,0.1,0.5);
				xAddDatabaseBlock(dSelectables, true);
				xSetInt(dSelectables, xSelectablesName, 1*trQuestVarGet("Bonus2"));
				xSetInt(dSelectables, xSelectablesPrompt, 732);
			}
		}
		if(xGetInt(dPlayerData, xBonus+3) != 0){
			trUnitSelectByQV("Bonus3");
			trUnitChangeProtoUnit("Ramming Ship Greek");
			trUnitSelectByQV("Bonus3");
			trSetSelectedScale(0.5,0.5,0.5);
			xAddDatabaseBlock(dSelectables, true);
			xSetInt(dSelectables, xSelectablesName, 1*trQuestVarGet("Bonus3"));
			xSetInt(dSelectables, xSelectablesPrompt, 703);
			if(xGetInt(dPlayerData, xBonus+3) == 2){
				trUnitSelectByQV("BonusEffect3");
				trUnitChangeProtoUnit("Gaia Forest effect");
				trUnitSelectByQV("BonusUnit");
				trUnitChangeProtoUnit("Ramming Ship Greek");
			}
		}
		if(xGetInt(dPlayerData, xBonus+3) == 0){
			trUnitSelectByQV("Bonus3");
			trUnitChangeProtoUnit("Outpost");
			trUnitSelectByQV("Bonus3");
			trSetSelectedScale(0.5,0.1,0.5);
			xAddDatabaseBlock(dSelectables, true);
			xSetInt(dSelectables, xSelectablesName, 1*trQuestVarGet("Bonus3"));
			xSetInt(dSelectables, xSelectablesPrompt, 733);
		}
		if(xGetInt(dPlayerData, xBonus+4) != 0){
			trUnitSelectByQV("Bonus4");
			trUnitChangeProtoUnit("Tent");
			xAddDatabaseBlock(dSelectables, true);
			xSetInt(dSelectables, xSelectablesName, 1*trQuestVarGet("Bonus4"));
			xSetInt(dSelectables, xSelectablesPrompt, 704);
			if(xGetInt(dPlayerData, xBonus+4) == 2){
				trUnitSelectByQV("BonusEffect4");
				trUnitChangeProtoUnit("Gaia Forest effect");
				trUnitSelectByQV("BonusUnit");
				trUnitChangeProtoUnit("Tent");
			}
		}
		if(xGetInt(dPlayerData, xBonus+4) == 0){
			trUnitSelectByQV("Bonus4");
			trUnitChangeProtoUnit("Outpost");
			trUnitSelectByQV("Bonus4");
			trSetSelectedScale(0.5,0.1,0.5);
			xAddDatabaseBlock(dSelectables, true);
			xSetInt(dSelectables, xSelectablesName, 1*trQuestVarGet("Bonus4"));
			xSetInt(dSelectables, xSelectablesPrompt, 734);
		}
		if(xGetInt(dPlayerData, xBonus+5) != 0){
			trUnitSelectByQV("Bonus5");
			trUnitChangeProtoUnit("Dwarven Forge");
			trUnitSelectByQV("Bonus5");
			trUnitSetVariation(1*trQuestVarGet("Bonus5"), 1);
			trSetSelectedScale(0.5,0.5,0.5);
			xAddDatabaseBlock(dSelectables, true);
			xSetInt(dSelectables, xSelectablesName, 1*trQuestVarGet("Bonus5"));
			xSetInt(dSelectables, xSelectablesPrompt, 705);
			if(xGetInt(dPlayerData, xBonus+5) == 2){
				trUnitSelectByQV("BonusEffect5");
				trUnitChangeProtoUnit("Gaia Forest effect");
				trUnitSelectByQV("BonusUnit");
				trUnitChangeProtoUnit("Dwarven Forge");
				trUnitSetVariation(1*trQuestVarGet("BonusUnit"), 1);
			}
		}
		if(xGetInt(dPlayerData, xBonus+5) == 0){
			trUnitSelectByQV("Bonus5");
			trUnitChangeProtoUnit("Outpost");
			trUnitSelectByQV("Bonus5");
			trSetSelectedScale(0.5,0.1,0.5);
			xAddDatabaseBlock(dSelectables, true);
			xSetInt(dSelectables, xSelectablesName, 1*trQuestVarGet("Bonus5"));
			xSetInt(dSelectables, xSelectablesPrompt, 735);
		}
		if(xGetInt(dPlayerData, xBonus+6) != 0){
			trUnitSelectByQV("Bonus6");
			trUnitChangeProtoUnit("Wall Connector");
			xAddDatabaseBlock(dSelectables, true);
			xSetInt(dSelectables, xSelectablesName, 1*trQuestVarGet("Bonus6"));
			xSetInt(dSelectables, xSelectablesPrompt, 706);
			if(xGetInt(dPlayerData, xBonus+6) == 2){
				trUnitSelectByQV("BonusEffect6");
				trUnitChangeProtoUnit("Gaia Forest effect");
				trUnitSelectByQV("BonusUnit");
				trUnitChangeProtoUnit("Wall Connector");
			}
		}
		if(xGetInt(dPlayerData, xBonus+6) == 0){
			trUnitSelectByQV("Bonus6");
			trUnitChangeProtoUnit("Outpost");
			trUnitSelectByQV("Bonus6");
			trSetSelectedScale(0.5,0.1,0.5);
			xAddDatabaseBlock(dSelectables, true);
			xSetInt(dSelectables, xSelectablesName, 1*trQuestVarGet("Bonus6"));
			xSetInt(dSelectables, xSelectablesPrompt, 736);
		}
		if(xGetInt(dPlayerData, xBonus+7) != 0){
			trUnitSelectByQV("Bonus7");
			trUnitChangeProtoUnit("Hero Ragnorok");
			xAddDatabaseBlock(dSelectables, true);
			xSetInt(dSelectables, xSelectablesName, 1*trQuestVarGet("Bonus7"));
			xSetInt(dSelectables, xSelectablesPrompt, 707);
			if(xGetInt(dPlayerData, xBonus+7) == 2){
				trUnitSelectByQV("BonusEffect7");
				trUnitChangeProtoUnit("Gaia Forest effect");
				trUnitSelectByQV("BonusUnit");
				trUnitChangeProtoUnit("Hero Ragnorok");
			}
		}
		if(xGetInt(dPlayerData, xBonus+7) == 0){
			trUnitSelectByQV("Bonus7");
			trUnitChangeProtoUnit("Outpost");
			trUnitSelectByQV("Bonus7");
			trSetSelectedScale(0.5,0.1,0.5);
			if((xGetInt(dPlayerData, xFuelLevel) < 3) && (1*trQuestVarGet("CineStatus") != 2)){
				trUnitSelectByQV("Bonus7");
				trUnitSetAnimationPath("0,1,0,0,0");
				xAddDatabaseBlock(dSelectables, true);
				xSetInt(dSelectables, xSelectablesName, 1*trQuestVarGet("Bonus7"));
				xSetInt(dSelectables, xSelectablesPrompt, 730);
			}
			else{
				xAddDatabaseBlock(dSelectables, true);
				xSetInt(dSelectables, xSelectablesName, 1*trQuestVarGet("Bonus7"));
				xSetInt(dSelectables, xSelectablesPrompt, 737);
			}
		}
		if(xGetInt(dPlayerData, xBonus+8) != 0){
			trUnitSelectByQV("Bonus8");
			trUnitChangeProtoUnit("Great Box");
			trUnitSelectByQV("Bonus8");
			trSetSelectedScale(0.5,0.5,0.5);
			xAddDatabaseBlock(dSelectables, true);
			xSetInt(dSelectables, xSelectablesName, 1*trQuestVarGet("Bonus8"));
			xSetInt(dSelectables, xSelectablesPrompt, 708);
			if(xGetInt(dPlayerData, xBonus+8) == 2){
				trUnitSelectByQV("BonusEffect8");
				trUnitChangeProtoUnit("Gaia Forest effect");
				trUnitSelectByQV("BonusUnit");
				trUnitChangeProtoUnit("Great Box");
				trUnitSelectByQV("BonusUnit");
				trSetSelectedScale(0.5,0.5,0.5);
			}
		}
		if(xGetInt(dPlayerData, xBonus+8) == 0){
			trUnitSelectByQV("Bonus8");
			trUnitChangeProtoUnit("Outpost");
			trUnitSelectByQV("Bonus8");
			trSetSelectedScale(0.5,0.1,0.5);
			if((xGetInt(dPlayerData, xStageUnlocked) < 6) && (1*trQuestVarGet("CineStatus") != 2)){
				trUnitSelectByQV("Bonus8");
				trUnitSetAnimationPath("0,1,0,0,0");
				xAddDatabaseBlock(dSelectables, true);
				xSetInt(dSelectables, xSelectablesName, 1*trQuestVarGet("Bonus8"));
				xSetInt(dSelectables, xSelectablesPrompt, 730);
			}
			else{
				xAddDatabaseBlock(dSelectables, true);
				xSetInt(dSelectables, xSelectablesName, 1*trQuestVarGet("Bonus8"));
				xSetInt(dSelectables, xSelectablesPrompt, 738);
			}
		}
		if(xGetInt(dPlayerData, xBonus+9) != 0){
			trUnitSelectByQV("Bonus9");
			trUnitChangeProtoUnit("Pharaoh");
			xAddDatabaseBlock(dSelectables, true);
			xSetInt(dSelectables, xSelectablesName, 1*trQuestVarGet("Bonus9"));
			xSetInt(dSelectables, xSelectablesPrompt, 709);
			if(xGetInt(dPlayerData, xBonus+9) == 2){
				trUnitSelectByQV("BonusEffect9");
				trUnitChangeProtoUnit("Gaia Forest effect");
				trUnitSelectByQV("BonusUnit");
				trUnitChangeProtoUnit("Pharaoh");
			}
		}
		if(xGetInt(dPlayerData, xBonus+9) == 0){
			trUnitSelectByQV("Bonus9");
			trUnitChangeProtoUnit("Outpost");
			trUnitSelectByQV("Bonus9");
			trSetSelectedScale(0.5,0.1,0.5);
			if((xGetInt(dPlayerData, xStageUnlocked) < 5) && (1*trQuestVarGet("CineStatus") != 2)){
				trUnitSelectByQV("Bonus9");
				trUnitSetAnimationPath("0,1,0,0,0");
				xAddDatabaseBlock(dSelectables, true);
				xSetInt(dSelectables, xSelectablesName, 1*trQuestVarGet("Bonus9"));
				xSetInt(dSelectables, xSelectablesPrompt, 730);
			}
			else{
				xAddDatabaseBlock(dSelectables, true);
				xSetInt(dSelectables, xSelectablesName, 1*trQuestVarGet("Bonus9"));
				xSetInt(dSelectables, xSelectablesPrompt, 739);
			}
		}
		if(xGetInt(dPlayerData, xBonus+10) != 0){
			trUnitSelectByQV("Bonus10");
			trUnitChangeProtoUnit("Fire Giant");
			xAddDatabaseBlock(dSelectables, true);
			xSetInt(dSelectables, xSelectablesName, 1*trQuestVarGet("Bonus10"));
			xSetInt(dSelectables, xSelectablesPrompt, 710);
			if(xGetInt(dPlayerData, xBonus+10) == 2){
				trUnitSelectByQV("BonusEffect10");
				trUnitChangeProtoUnit("Gaia Forest effect");
				trUnitSelectByQV("BonusUnit");
				trUnitChangeProtoUnit("Fire Giant");
			}
		}
		if(xGetInt(dPlayerData, xBonus+10) == 0){
			trUnitSelectByQV("Bonus10");
			trUnitChangeProtoUnit("Outpost");
			trUnitSelectByQV("Bonus10");
			trSetSelectedScale(0.5,0.1,0.5);
			if((xGetInt(dPlayerData, xStageUnlocked) < 5) && (1*trQuestVarGet("CineStatus") != 2)){
				trUnitSelectByQV("Bonus10");
				trUnitSetAnimationPath("0,1,0,0,0");
				xAddDatabaseBlock(dSelectables, true);
				xSetInt(dSelectables, xSelectablesName, 1*trQuestVarGet("Bonus10"));
				xSetInt(dSelectables, xSelectablesPrompt, 730);
			}
			else{
				xAddDatabaseBlock(dSelectables, true);
				xSetInt(dSelectables, xSelectablesName, 1*trQuestVarGet("Bonus10"));
				xSetInt(dSelectables, xSelectablesPrompt, 740);
			}
		}
		//Already unlocked
		if(xGetInt(dPlayerData, xBonus+11) != 0){
			trUnitSelectByQV("Bonus11");
			trBlockAllSounds();
			trUnitChangeProtoUnit("Wonder SPC");
			trUnblockAllSounds();
			trChatHistoryClear();
			trUnitSelectByQV("Bonus11");
			trSetSelectedScale(0.3,0.3,0.3);
			trUnitSelectByQV("Bonus11");
			trUnitSetAnimationPath("3,0,0,1,0");
			xAddDatabaseBlock(dSelectables, true);
			xSetInt(dSelectables, xSelectablesName, 1*trQuestVarGet("Bonus11"));
			xSetInt(dSelectables, xSelectablesPrompt, 711);
			if(xGetInt(dPlayerData, xBonus+11) == 2){
				trUnitSelectByQV("BonusEffect11");
				trUnitChangeProtoUnit("Gaia Forest effect");
				trUnitSelectByQV("BonusUnit");
				trUnitChangeProtoUnit("Prisoner");
				trUnitSelectByQV("BonusUnit");
				trBlockAllSounds();
				trUnitChangeProtoUnit("Wonder SPC");
				trChatHistoryClear();
				trUnblockAllSounds();
				trUnitSelectByQV("BonusUnit");
				trSetSelectedScale(0.3,0.3,0.3);
				trUnitSelectByQV("BonusUnit");
				trUnitSetAnimationPath("3,0,0,1,0");
			}
		}
		//Actively unlock in SP
		else if(xGetInt(dPlayerData, xBonus+11) == 0){
			if((xGetInt(dPlayerData, xDrillLevel) >= 3) || (xGetInt(dPlayerData, xHullLevel) >= 3) || (xGetInt(dPlayerData, xFuelLevel) >= 3) || (xGetInt(dPlayerData, xEngineLevel) >= 3) || (xGetInt(dPlayerData, xCargoLevel) >= 3) || (xGetInt(dPlayerData, xRadiatorLevel) >= 3)){
				trUnitSelectByQV("Bonus11");
				trUnitChangeProtoUnit("Prisoner");
				trUnitSelectByQV("Bonus11");
				trBlockAllSounds();
				trUnitChangeProtoUnit("Wonder SPC");
				trUnblockAllSounds();
				trUnitSelectByQV("Bonus11");
				trSetSelectedScale(0.3,0.3,0.3);
				trUnitSelectByQV("Bonus11");
				trUnitHighlight(5,true);
				xSetInt(dPlayerData, xBonus+11, 1);
				xAddDatabaseBlock(dSelectables, true);
				xSetInt(dSelectables, xSelectablesName, 1*trQuestVarGet("Bonus11"));
				xSetInt(dSelectables, xSelectablesPrompt, 711);
				trUnitSelectByQV("Bonus11");
				trUnitSetAnimationPath("3,0,0,1,0");
				ColouredIconChat("1,0.5,0", "icons\special e son of osiris icon 64","Bonus unlocked (11)!");
				playSoundCustom("cinematics\10_in\clearedcity.wav", "\Yeebaagooon\Motherload\UnlockBonus.mp3");
			}
			else{trUnitSelectByQV("Bonus11");
				trUnitChangeProtoUnit("Outpost");
				trUnitSelectByQV("Bonus11");
				trSetSelectedScale(0.5,0.1,0.5);
				if((xGetInt(dPlayerData, xDrillLevel) < 2) && (1*trQuestVarGet("CineStatus") != 2)){
					trUnitSelectByQV("Bonus11");
					trUnitSetAnimationPath("0,1,0,0,0");
					xAddDatabaseBlock(dSelectables, true);
					xSetInt(dSelectables, xSelectablesName, 1*trQuestVarGet("Bonus11"));
					xSetInt(dSelectables, xSelectablesPrompt, 730);
				}
				else{
					xAddDatabaseBlock(dSelectables, true);
					xSetInt(dSelectables, xSelectablesName, 1*trQuestVarGet("Bonus11"));
					xSetInt(dSelectables, xSelectablesPrompt, 741);
				}
			}
		}
		if(xGetInt(dPlayerData, xBonus+12) != 0){
			trUnitSelectByQV("Bonus12");
			trUnitChangeProtoUnit("Alfred");
			xAddDatabaseBlock(dSelectables, true);
			xSetInt(dSelectables, xSelectablesName, 1*trQuestVarGet("Bonus12"));
			xSetInt(dSelectables, xSelectablesPrompt, 712);
			if(xGetInt(dPlayerData, xBonus+12) == 2){
				trUnitSelectByQV("BonusEffect12");
				trUnitChangeProtoUnit("Gaia Forest effect");
				trUnitSelectByQV("BonusUnit");
				trUnitChangeProtoUnit("Alfred");
			}
		}
		if(xGetInt(dPlayerData, xBonus+12) == 0){
			trUnitSelectByQV("Bonus12");
			trUnitChangeProtoUnit("Outpost");
			trUnitSelectByQV("Bonus12");
			trSetSelectedScale(0.5,0.1,0.5);
			if((xGetInt(dPlayerData, xGold) < 999) && (1*trQuestVarGet("CineStatus") != 2)){
				trUnitSelectByQV("Bonus12");
				trUnitSetAnimationPath("0,1,0,0,0");
				xAddDatabaseBlock(dSelectables, true);
				xSetInt(dSelectables, xSelectablesName, 1*trQuestVarGet("Bonus12"));
				xSetInt(dSelectables, xSelectablesPrompt, 730);
			}
			else{
				xAddDatabaseBlock(dSelectables, true);
				xSetInt(dSelectables, xSelectablesName, 1*trQuestVarGet("Bonus12"));
				xSetInt(dSelectables, xSelectablesPrompt, 742);
			}
		}
		if(xGetInt(dPlayerData, xBonus+13) != 0){
			trUnitSelectByQV("Bonus13");
			trUnitChangeProtoUnit("Chariot Archer");
			xAddDatabaseBlock(dSelectables, true);
			xSetInt(dSelectables, xSelectablesName, 1*trQuestVarGet("Bonus13"));
			xSetInt(dSelectables, xSelectablesPrompt, 713);
			if(xGetInt(dPlayerData, xBonus+13) == 2){
				trUnitSelectByQV("BonusEffect13");
				trUnitChangeProtoUnit("Gaia Forest effect");
				trUnitSelectByQV("BonusUnit");
				trUnitChangeProtoUnit("Chariot Archer");
			}
		}
		if(xGetInt(dPlayerData, xBonus+13) == 0){
			trUnitSelectByQV("Bonus13");
			trUnitChangeProtoUnit("Outpost");
			trUnitSelectByQV("Bonus13");
			trSetSelectedScale(0.5,0.1,0.5);
			if((xGetInt(dPlayerData, xStageUnlocked) <= 3) && (1*trQuestVarGet("CineStatus") != 2)){
				trUnitSelectByQV("Bonus13");
				trUnitSetAnimationPath("0,1,0,0,0");
				xAddDatabaseBlock(dSelectables, true);
				xSetInt(dSelectables, xSelectablesName, 1*trQuestVarGet("Bonus13"));
				xSetInt(dSelectables, xSelectablesPrompt, 730);
			}
			else{
				xAddDatabaseBlock(dSelectables, true);
				xSetInt(dSelectables, xSelectablesName, 1*trQuestVarGet("Bonus13"));
				xSetInt(dSelectables, xSelectablesPrompt, 743);
			}
		}
		//Already unlocked
		if(xGetInt(dPlayerData, xBonus+14) != 0){
			trUnitSelectByQV("Bonus14");
			trBlockAllSounds();
			trUnitChangeProtoUnit("Tower Mirror");
			trUnblockAllSounds();
			trChatHistoryClear();
			trUnitSelectByQV("Bonus14");
			trSetSelectedScale(0.3,0.5,0.3);
			xAddDatabaseBlock(dSelectables, true);
			xSetInt(dSelectables, xSelectablesName, 1*trQuestVarGet("Bonus14"));
			xSetInt(dSelectables, xSelectablesPrompt, 714);
			if(xGetInt(dPlayerData, xBonus+14) == 2){
				trUnitSelectByQV("BonusEffect14");
				trUnitChangeProtoUnit("Gaia Forest effect");
				trUnitSelectByQV("BonusUnit");
				trUnitChangeProtoUnit("Prisoner");
				trUnitSelectByQV("BonusUnit");
				trBlockAllSounds();
				trUnitChangeProtoUnit("Tower Mirror");
				trChatHistoryClear();
				trUnblockAllSounds();
				trUnitSelectByQV("BonusUnit");
				trSetSelectedScale(0.3,0.5,0.3);
			}
		}
		//Actively unlock in SP
		else if(xGetInt(dPlayerData, xBonus+14) == 0){
			if((xGetInt(dPlayerData, xDrillLevel) >= 8) || (xGetInt(dPlayerData, xHullLevel) >= 8) || (xGetInt(dPlayerData, xFuelLevel) >= 8) || (xGetInt(dPlayerData, xEngineLevel) >= 8) || (xGetInt(dPlayerData, xCargoLevel) >= 8) || (xGetInt(dPlayerData, xRadiatorLevel) >= 8)){
				trUnitSelectByQV("Bonus14");
				trUnitChangeProtoUnit("Prisoner");
				trUnitSelectByQV("Bonus14");
				trUnitChangeProtoUnit("Tower Mirror");
				trUnitSelectByQV("Bonus14");
				trSetSelectedScale(0.3,0.5,0.3);
				trUnitSelectByQV("Bonus14");
				trUnitHighlight(5,true);
				xSetInt(dPlayerData, xBonus+14, 1);
				xAddDatabaseBlock(dSelectables, true);
				xSetInt(dSelectables, xSelectablesName, 1*trQuestVarGet("Bonus14"));
				xSetInt(dSelectables, xSelectablesPrompt, 714);
				ColouredIconChat("1,0.5,0", "icons\special e son of osiris icon 64","Bonus unlocked (14)!");
				playSoundCustom("cinematics\10_in\clearedcity.wav", "\Yeebaagooon\Motherload\UnlockBonus.mp3");
			}
			else{trUnitSelectByQV("Bonus14");
				trUnitChangeProtoUnit("Outpost");
				trUnitSelectByQV("Bonus14");
				trSetSelectedScale(0.5,0.1,0.5);
				if((xGetInt(dPlayerData, xDrillLevel) <= 5) && (1*trQuestVarGet("CineStatus") != 2)){
					trUnitSelectByQV("Bonus14");
					trUnitSetAnimationPath("0,1,0,0,0");
					xAddDatabaseBlock(dSelectables, true);
					xSetInt(dSelectables, xSelectablesName, 1*trQuestVarGet("Bonus14"));
					xSetInt(dSelectables, xSelectablesPrompt, 730);
				}
				else{
					xAddDatabaseBlock(dSelectables, true);
					xSetInt(dSelectables, xSelectablesName, 1*trQuestVarGet("Bonus14"));
					xSetInt(dSelectables, xSelectablesPrompt, 744);
				}
			}
		}
		if(xGetInt(dPlayerData, xBonus+15) != 0){
			trUnitSelectByQV("Bonus15");
			trUnitChangeProtoUnit("Roc Tent");
			trUnitSelectByQV("Bonus15");
			trSetSelectedScale(0.5,0.5,0.5);
			xAddDatabaseBlock(dSelectables, true);
			xSetInt(dSelectables, xSelectablesName, 1*trQuestVarGet("Bonus15"));
			xSetInt(dSelectables, xSelectablesPrompt, 715);
			if(xGetInt(dPlayerData, xBonus+15) == 2){
				trUnitSelectByQV("BonusEffect15");
				trUnitChangeProtoUnit("Gaia Forest effect");
				trUnitSelectByQV("BonusUnit");
				trUnitChangeProtoUnit("Roc Tent");
				trUnitSelectByQV("BonusUnit");
				trSetSelectedScale(0.5,0.5,0.5);
			}
		}
		if(xGetInt(dPlayerData, xBonus+15) == 0){
			trUnitSelectByQV("Bonus15");
			trUnitChangeProtoUnit("Outpost");
			trUnitSelectByQV("Bonus15");
			trSetSelectedScale(0.5,0.1,0.5);
			if((xGetInt(dPlayerData, xStageUnlocked) < 8) && (1*trQuestVarGet("CineStatus") != 2)){
				trUnitSelectByQV("Bonus15");
				trUnitSetAnimationPath("0,1,0,0,0");
				xAddDatabaseBlock(dSelectables, true);
				xSetInt(dSelectables, xSelectablesName, 1*trQuestVarGet("Bonus15"));
				xSetInt(dSelectables, xSelectablesPrompt, 730);
			}
			else{
				xAddDatabaseBlock(dSelectables, true);
				xSetInt(dSelectables, xSelectablesName, 1*trQuestVarGet("Bonus15"));
				xSetInt(dSelectables, xSelectablesPrompt, 745);
			}
		}
		if(xGetInt(dPlayerData, xBonus+16) != 0){
			trUnitSelectByQV("Bonus16");
			trUnitChangeProtoUnit("Well of Urd");
			trUnitSelectByQV("Bonus16");
			trSetSelectedScale(0.5,0.5,0.5);
			xAddDatabaseBlock(dSelectables, true);
			xSetInt(dSelectables, xSelectablesName, 1*trQuestVarGet("Bonus16"));
			xSetInt(dSelectables, xSelectablesPrompt, 716);
			if(xGetInt(dPlayerData, xBonus+16) == 2){
				trUnitSelectByQV("BonusEffect16");
				trUnitChangeProtoUnit("Gaia Forest effect");
				trUnitSelectByQV("BonusUnit");
				trUnitChangeProtoUnit("Well of Urd");
				trUnitSelectByQV("BonusUnit");
				trSetSelectedScale(0.5,0.5,0.5);
			}
		}
		if(xGetInt(dPlayerData, xBonus+16) == 0){
			trUnitSelectByQV("Bonus16");
			trUnitChangeProtoUnit("Outpost");
			trUnitSelectByQV("Bonus16");
			trSetSelectedScale(0.5,0.1,0.5);
			if((xGetInt(dPlayerData, xFuelSpend) < 1000) && (1*trQuestVarGet("CineStatus") != 2)){
				trUnitSelectByQV("Bonus16");
				trUnitSetAnimationPath("0,1,0,0,0");
				xAddDatabaseBlock(dSelectables, true);
				xSetInt(dSelectables, xSelectablesName, 1*trQuestVarGet("Bonus16"));
				xSetInt(dSelectables, xSelectablesPrompt, 730);
			}
			else{
				xAddDatabaseBlock(dSelectables, true);
				xSetInt(dSelectables, xSelectablesName, 1*trQuestVarGet("Bonus16"));
				xSetInt(dSelectables, xSelectablesPrompt, 746);
			}
		}
		if(xGetInt(dPlayerData, xBonus+17) != 0){
			trUnitSelectByQV("Bonus17");
			trUnitChangeProtoUnit("Tartarian Gate");
			trUnitSelectByQV("Bonus17");
			trSetSelectedScale(0.4,-0.4,0.4);
			trUnitSelectByQV("Bonus17");
			trUnitOverrideAnimation(2,0,true,true,-1,-1);
			trUnitSelectByQV("Bonus17");
			trUnitSetAnimationPath("0,0,1,1,0,0");
			xAddDatabaseBlock(dSelectables, true);
			xSetInt(dSelectables, xSelectablesName, 1*trQuestVarGet("Bonus17"));
			xSetInt(dSelectables, xSelectablesPrompt, 717);
			if(xGetInt(dPlayerData, xBonus+17) == 2){
				trUnitSelectByQV("BonusEffect17");
				trUnitChangeProtoUnit("Gaia Forest effect");
				trUnitSelectByQV("BonusUnit");
				trUnitChangeProtoUnit("Tartarian Gate");
				trUnitSelectByQV("BonusUnit");
				trSetSelectedScale(0.4,-0.4,0.4);
				trUnitSelectByQV("BonusUnit");
				trUnitOverrideAnimation(2,0,true,true,-1,-1);
				trUnitSelectByQV("BonusUnit");
				trUnitSetAnimationPath("0,0,1,1,0,0");
			}
		}
		if(xGetInt(dPlayerData, xBonus+17) == 0){
			trUnitSelectByQV("Bonus17");
			trUnitChangeProtoUnit("Outpost");
			trUnitSelectByQV("Bonus17");
			trSetSelectedScale(0.5,0.1,0.5);
			if(xGetInt(dPlayerData, xStageUnlocked) < 9){
				trUnitSelectByQV("Bonus17");
				trUnitSetAnimationPath("0,1,0,0,0");
				xAddDatabaseBlock(dSelectables, true);
				xSetInt(dSelectables, xSelectablesName, 1*trQuestVarGet("Bonus17"));
				xSetInt(dSelectables, xSelectablesPrompt, 730);
			}
			else{
				xAddDatabaseBlock(dSelectables, true);
				xSetInt(dSelectables, xSelectablesName, 1*trQuestVarGet("Bonus17"));
				xSetInt(dSelectables, xSelectablesPrompt, 747);
			}
		}
		if(xGetInt(dPlayerData, xBonus+18) != 0){
			trUnitSelectByQV("Bonus18");
			trUnitChangeProtoUnit("Hero Chinese Monk");
			xAddDatabaseBlock(dSelectables, true);
			xSetInt(dSelectables, xSelectablesName, 1*trQuestVarGet("Bonus18"));
			xSetInt(dSelectables, xSelectablesPrompt, 718);
			if(xGetInt(dPlayerData, xBonus+18) == 2){
				trUnitSelectByQV("BonusEffect18");
				trUnitChangeProtoUnit("Gaia Forest effect");
				trUnitSelectByQV("BonusUnit");
				trUnitChangeProtoUnit("Hero Chinese Monk");
			}
		}
		if(xGetInt(dPlayerData, xBonus+18) == 0){
			trUnitSelectByQV("Bonus18");
			trUnitChangeProtoUnit("Outpost");
			trUnitSelectByQV("Bonus18");
			trSetSelectedScale(0.5,0.1,0.5);
			if((xGetInt(dPlayerData, xRadioactivesSold) < RadiationBonus/4) && (1*trQuestVarGet("CineStatus") != 2)){
				trUnitSelectByQV("Bonus18");
				trUnitSetAnimationPath("0,1,0,0,0");
				xAddDatabaseBlock(dSelectables, true);
				xSetInt(dSelectables, xSelectablesName, 1*trQuestVarGet("Bonus18"));
				xSetInt(dSelectables, xSelectablesPrompt, 730);
			}
			else{
				xAddDatabaseBlock(dSelectables, true);
				xSetInt(dSelectables, xSelectablesName, 1*trQuestVarGet("Bonus18"));
				xSetInt(dSelectables, xSelectablesPrompt, 748);
			}
		}
		if(xGetInt(dPlayerData, xBonus+19) != 0){
			trUnitSelectByQV("Bonus19");
			trUnitChangeProtoUnit("Gate Ram");
			trUnitSelectByQV("Bonus19");
			trSetSelectedScale(0.4,0.4,0.4);
			trUnitSelectByQV("Bonus19");
			trUnitSetHeading(90);
			xAddDatabaseBlock(dSelectables, true);
			xSetInt(dSelectables, xSelectablesName, 1*trQuestVarGet("Bonus19"));
			xSetInt(dSelectables, xSelectablesPrompt, 719);
			if(xGetInt(dPlayerData, xBonus+19) == 2){
				trUnitSelectByQV("BonusEffect19");
				trUnitChangeProtoUnit("Gaia Forest effect");
				trUnitSelectByQV("BonusUnit");
				trUnitChangeProtoUnit("Gate Ram");
				trUnitSelectByQV("BonusUnit");
				trSetSelectedScale(0.4,0.4,0.4);
			}
		}
		if(xGetInt(dPlayerData, xBonus+19) == 0){
			trUnitSelectByQV("Bonus19");
			trUnitChangeProtoUnit("Outpost");
			trUnitSelectByQV("Bonus19");
			trSetSelectedScale(0.5,0.1,0.5);
			if((xGetInt(dPlayerData, xIceDrill) < 5) && (1*trQuestVarGet("CineStatus") != 2)){
				trUnitSelectByQV("Bonus19");
				trUnitSetAnimationPath("0,1,0,0,0");
				xAddDatabaseBlock(dSelectables, true);
				xSetInt(dSelectables, xSelectablesName, 1*trQuestVarGet("Bonus19"));
				xSetInt(dSelectables, xSelectablesPrompt, 730);
			}
			else{
				xAddDatabaseBlock(dSelectables, true);
				xSetInt(dSelectables, xSelectablesName, 1*trQuestVarGet("Bonus19"));
				xSetInt(dSelectables, xSelectablesPrompt, 749);
			}
		}
		if(xGetInt(dPlayerData, xBonus+20) != 0){
			trUnitSelectByQV("Bonus20");
			trUnitChangeProtoUnit("Troy Wall Connector");
			trUnitSelectByQV("Bonus20");
			trSetSelectedScale(0.2,0.2,0.2);
			xAddDatabaseBlock(dSelectables, true);
			xSetInt(dSelectables, xSelectablesName, 1*trQuestVarGet("Bonus20"));
			xSetInt(dSelectables, xSelectablesPrompt, 720);
			if(xGetInt(dPlayerData, xBonus+20) == 2){
				trUnitSelectByQV("BonusEffect20");
				trUnitChangeProtoUnit("Gaia Forest effect");
				trUnitSelectByQV("BonusUnit");
				trUnitChangeProtoUnit("Troy Wall Connector");
				trUnitSelectByQV("BonusUnit");
				trSetSelectedScale(0.2,0.2,0.2);
			}
		}
		if(xGetInt(dPlayerData, xBonus+20) == 0){
			trUnitSelectByQV("Bonus20");
			trUnitChangeProtoUnit("Outpost");
			trUnitSelectByQV("Bonus20");
			trSetSelectedScale(0.5,0.1,0.5);
			if((xGetInt(dPlayerData, xHullSpend) < 1000) && (1*trQuestVarGet("CineStatus") != 2)){
				trUnitSelectByQV("Bonus20");
				trUnitSetAnimationPath("0,1,0,0,0");
				xAddDatabaseBlock(dSelectables, true);
				xSetInt(dSelectables, xSelectablesName, 1*trQuestVarGet("Bonus20"));
				xSetInt(dSelectables, xSelectablesPrompt, 730);
			}
			else{
				xAddDatabaseBlock(dSelectables, true);
				xSetInt(dSelectables, xSelectablesName, 1*trQuestVarGet("Bonus20"));
				xSetInt(dSelectables, xSelectablesPrompt, 750);
			}
		}
		if(xGetInt(dPlayerData, xBonus+21) != 0){
			trUnitSelectByQV("Bonus21");
			trUnitChangeProtoUnit("Monument");
			xAddDatabaseBlock(dSelectables, true);
			xSetInt(dSelectables, xSelectablesName, 1*trQuestVarGet("Bonus21"));
			xSetInt(dSelectables, xSelectablesPrompt, 721);
			if(xGetInt(dPlayerData, xBonus+21) == 2){
				trUnitSelectByQV("BonusEffect21");
				trUnitChangeProtoUnit("Gaia Forest effect");
				trUnitSelectByQV("BonusUnit");
				trUnitChangeProtoUnit("Monument");
			}
		}
		if(xGetInt(dPlayerData, xBonus+21) == 0){
			trUnitSelectByQV("Bonus21");
			trUnitChangeProtoUnit("Outpost");
			trUnitSelectByQV("Bonus21");
			trSetSelectedScale(0.5,0.1,0.5);
			if(xGetInt(dPlayerData, xStageUnlocked) != 10){
				trUnitSelectByQV("Bonus21");
				trUnitSetAnimationPath("0,1,0,0,0");
				xAddDatabaseBlock(dSelectables, true);
				xSetInt(dSelectables, xSelectablesName, 1*trQuestVarGet("Bonus21"));
				xSetInt(dSelectables, xSelectablesPrompt, 730);
			}
			else{
				xAddDatabaseBlock(dSelectables, true);
				xSetInt(dSelectables, xSelectablesName, 1*trQuestVarGet("Bonus21"));
				xSetInt(dSelectables, xSelectablesPrompt, 751);
			}
		}
		xsDisableSelf();
	}
}

void Deselect_Bonus(int p = 0){
	xsSetContextPlayer(0);
	for(x = 1; <= 21){
		if(x != p){
			trUnitSelectByQV("BonusEffect"+x);
			trUnitChangeProtoUnit("Cinematic Block");
			if(xGetInt(dPlayerData, xBonus+x) == 2){
				xSetInt(dPlayerData, xBonus+x, 1);
			}
		}
	}
}

void Select_Bonus(int bonus = 0){
	xsSetContextPlayer(0);
	bonus = bonus-22;
	xSetPointer(dPlayerData, 1);
	if(xGetInt(dPlayerData, xBonus+bonus) == 2){
		ColouredChat("1,0,0", "This bonus is already equipped!");
	}
	if(xGetInt(dPlayerData, xBonus+bonus) == 0){
		ColouredChat("1,0,0", "WTF ERROR!");
	}
	if(xGetInt(dPlayerData, xBonus+bonus) == 1){
		xSetInt(dPlayerData, xBonus+bonus, 2);
		trUnitSelectByQV("BonusEffect"+bonus);
		trUnitChangeProtoUnit("Gaia Forest effect");
		trUnitSelectByQV("BonusUnit");
		if(bonus == 1){
			trUnitChangeProtoUnit("Statue of Major God");
			ColouredChat("1,0.5,0", "+1 mineral capacity equipped");
		}
		if(bonus == 2){
			trUnitChangeProtoUnit("Well of Urd");
			trUnitSelectByQV("BonusUnit");
			trSetSelectedScale(0.5,0.5,0.5);
			ColouredChat("1,0.5,0", "+100L fuel capacity equipped");
		}
		if(bonus == 3){
			trUnitChangeProtoUnit("Ramming Ship Greek");
			ColouredChat("1,0.5,0", "+10 drill power equipped");
		}
		if(bonus == 4){
			trUnitChangeProtoUnit("Tent");
			ColouredChat("1,0.5,0", "+4 percent radiator efficiency equipped");
		}
		if(bonus == 5){
			trUnitChangeProtoUnit("Dwarven Forge");
			trUnitSelectByQV("BonusUnit");
			trSetSelectedScale(0.5,0.5,0.5);
			ColouredChat("1,0.5,0", "+15 engine power equipped");
			trUnitSetVariation(1*trQuestVarGet("BonusUnit"), 1);
		}
		if(bonus == 6){
			trUnitChangeProtoUnit("Wall Connector");
			ColouredChat("1,0.5,0", "+250hp hull equipped");
		}
		if(bonus == 7){
			trUnitChangeProtoUnit("Hero Ragnorok");
			ColouredChat("1,0.5,0", "Free emergency fuel tank equipped");
		}
		if(bonus == 8){
			trUnitChangeProtoUnit("Great Box");
			trUnitSelectByQV("BonusUnit");
			trSetSelectedScale(0.5,0.5,0.5);
			ColouredChat("1,0.5,0", "Sell all held minerals at game end equipped");
		}
		if(bonus == 9){
			trUnitChangeProtoUnit("Pharaoh");
			ColouredChat("1,0.5,0", "Nullified first two instances of damage equipped");
		}
		if(bonus == 10){
			trUnitChangeProtoUnit("Fire Giant");
			ColouredChat("1,0.5,0", "Gas pocket detection equipped");
		}
		if(bonus == 11){
			trUnitChangeProtoUnit("Prisoner");
			trUnitSelectByQV("BonusUnit");
			trBlockAllSounds();
			trUnitChangeProtoUnit("Wonder SPC");
			trUnblockAllSounds();
			trUnitSelectByQV("BonusUnit");
			trSetSelectedScale(0.3,0.3,0.3);
			trChatHistoryClear();
			ColouredChat("1,0.5,0", "+30s extra stage time equipped");
			trUnitSelectByQV("BonusUnit");
			trUnitSetAnimationPath("3,0,0,1,0");
		}
		if(bonus == 12){
			trUnitChangeProtoUnit("Alfred");
			ColouredChat("1,0.5,0", "Extra 25 percent profit on first sale equipped");
		}
		if(bonus == 13){
			trUnitChangeProtoUnit("Chariot Archer");
			ColouredChat("1,0.5,0", "Extra 5 ship speed equipped");
		}
		if(bonus == 14){
			trUnitChangeProtoUnit("Prisoner");
			trUnitSelectByQV("BonusUnit");
			trBlockAllSounds();
			trUnitChangeProtoUnit("Tower Mirror");
			trUnblockAllSounds();
			trUnitSelectByQV("BonusUnit");
			trSetSelectedScale(0.3,0.5,0.3);
			trChatHistoryClear();
			ColouredChat("1,0.5,0", "Mining laser equipped");
		}
		if(bonus == 15){
			trUnitChangeProtoUnit("Roc Tent");
			trUnitSelectByQV("BonusUnit");
			trSetSelectedScale(0.5,0.5,0.5);
			trChatHistoryClear();
			ColouredChat("1,0.5,0", "Antimatter bomb equipped");
		}
		if(bonus == 16){
			trUnitChangeProtoUnit("Well of Urd");
			trUnitSelectByQV("BonusUnit");
			trSetSelectedScale(0.5,0.5,0.5);
			ColouredChat("1,0.5,0", "+1000L fuel capacity equipped");
		}
		if(bonus == 17){
			trUnitChangeProtoUnit("Tartarian Gate");
			trUnitSelectByQV("BonusUnit");
			trSetSelectedScale(0.4,-0.4,0.4);
			trUnitSelectByQV("BonusUnit");
			trUnitOverrideAnimation(2,0,true,true,-1,-1);
			trUnitSelectByQV("BonusUnit");
			trUnitSetAnimationPath("0,0,1,1,0,0");
			trChatHistoryClear();
			ColouredChat("1,0.5,0", "Lava resist equipped");
		}
		if(bonus == 18){
			trUnitChangeProtoUnit("Hero Chinese Monk");
			trChatHistoryClear();
			ColouredChat("1,0.5,0", "Radiation resist equipped");
		}
		if(bonus == 19){
			trUnitChangeProtoUnit("Gate Ram");
			trUnitSelectByQV("BonusUnit");
			trSetSelectedScale(0.4,0.4,0.4);
			trChatHistoryClear();
			ColouredChat("1,0.5,0", "+100 drill power equipped");
		}
		if(bonus == 20){
			trUnitChangeProtoUnit("Troy Wall Connector");
			trUnitSelectByQV("BonusUnit");
			trSetSelectedScale(0.2,0.2,0.2);
			ColouredChat("1,0.5,0", "+1500 hull hp equipped");
		}
		if(bonus == 21){
			trUnitChangeProtoUnit("Monument");
			ColouredChat("1,0.5,0", "Reality Drill equipped");
		}
		Deselect_Bonus(bonus);
		playSoundCustom("ageadvance.wav", "\Yeebaagooon\Motherload\SelectBonus.mp3");
	}
	xsDisableSelf();
}

void Apply_Bonus(int s = -1){
	xsSetContextPlayer(0);
	for(p = 1; < cNumberNonGaiaPlayers){
		xSetPointer(dPlayerData, p);
		if(xGetInt(dPlayerData, xBonus+1) == 2){
			xSetInt(dPlayerData, xCargoHold, xGetInt(dPlayerData, xCargoHold)+1);
		}
		if(xGetInt(dPlayerData, xBonus+2) == 2){
			xSetInt(dPlayerData, xFuelTank, xGetInt(dPlayerData, xFuelTank)+100);
			xSetFloat(dPlayerData, xFuel, xGetFloat(dPlayerData, xFuel)+100);
		}
		if(xGetInt(dPlayerData, xBonus+3) == 2){
			xSetFloat(dPlayerData, xDrillPower, xGetFloat(dPlayerData, xDrillPower)+10);
		}
		if(xGetInt(dPlayerData, xBonus+4) == 2){
			xSetInt(dPlayerData, xRadiator, xGetInt(dPlayerData, xRadiator)+4);
		}
		if(xGetInt(dPlayerData, xBonus+5) == 2){
			xSetInt(dPlayerData, xEnginePower, xGetInt(dPlayerData, xEnginePower)+15);
		}
		if(xGetInt(dPlayerData, xBonus+6) == 2){
			xSetInt(dPlayerData, xHullHP, xGetInt(dPlayerData, xHullHP)+250);
		}
		if(xGetInt(dPlayerData, xBonus+7) == 2){
			grantGodPowerNoRechargeNextPosition(p, "Ragnorok", 1);
		}
		if(xGetInt(dPlayerData, xBonus+9) == 2){
			trQuestVarSet("P"+p+"B9", 2);
		}
		if(xGetInt(dPlayerData, xBonus+11) == 2){
			StageTime = StageTime+30;
		}
		if(xGetInt(dPlayerData, xBonus+12) == 2){
			trQuestVarSet("P"+p+"B12", 1);
		}
		if(xGetInt(dPlayerData, xBonus+13) == 2){
			trModifyProtounit("Hero Greek Atalanta", p, 1, 5);
		}
		if(xGetInt(dPlayerData, xBonus+14) == 2){
			if(Stage != 10){
				grantGodPowerNoRechargeNextPosition(p, "Earth Dragon", 1);
				ColouredChatToPlayer(p, "1,0.5,0", "Mining laser equipped (L key to use)");
				ColouredChatToPlayer(p, "1,0.5,0", "DIRECTIONAL - mines 10 tiles in the target direction");
				ColouredChatToPlayer(p, "1,0.5,0", "Use like dynamite - have the cursor next to your ship");
				spyEffect(1*trQuestVarGet("P"+p+"Siphon"), kbGetProtoUnitID("Tower Mirror"), xsVectorSet(dPlayerData,xSpyObject,p), vector(0.3,0.5,0.3));
				xsEnableRule("EarthDragon");
			}
			else{
				ColouredChatToPlayer(p, "1,0.5,0", "Super weapons are not permitted on this stage.");
			}
		}
		if(xGetInt(dPlayerData, xBonus+15) == 2){
			if(Stage != 10){
				grantGodPowerNoRechargeNextPosition(p, "Vision", 1);
				ColouredChatToPlayer(p, "1,0.5,0", "Antimatter bomb equipped (A key to use)");
				ColouredChatToPlayer(p, "1,0.5,0", "Blasts 5x5 squares around you when used.");
				spyEffect(1*trQuestVarGet("P"+p+"Siphon"), kbGetProtoUnitID("Roc Tent"), xsVectorSet(dPlayerData,xSpyObject,p), vector(1,1,1));
				xsEnableRule("Vision");
			}
			else{
				ColouredChatToPlayer(p, "1,0.5,0", "Super weapons are not permitted on this stage.");
			}
		}
		if(xGetInt(dPlayerData, xBonus+16) == 2){
			xSetInt(dPlayerData, xFuelTank, xGetInt(dPlayerData, xFuelTank)+1000);
			xSetFloat(dPlayerData, xFuel, xGetFloat(dPlayerData, xFuel)+1000);
		}
		if(xGetInt(dPlayerData, xBonus+17) == 2){
			trQuestVarSet("P"+p+"B17", 1);
		}
		if(xGetInt(dPlayerData, xBonus+18) == 2){
			trQuestVarSet("P"+p+"B18", 1);
		}
		if(xGetInt(dPlayerData, xBonus+19) == 2){
			xSetFloat(dPlayerData, xDrillPower, xGetFloat(dPlayerData, xDrillPower)+100);
		}
		if(xGetInt(dPlayerData, xBonus+20) == 2){
			xSetInt(dPlayerData, xHullHP, xGetInt(dPlayerData, xHullHP)+1500);
		}
		if(xGetInt(dPlayerData, xBonus+21) == 2){
			if(Stage != 10){
				grantGodPowerNoRechargeNextPosition(p, "Nidhogg", 1);
				ColouredChatToPlayer(p, "1,0.5,0", "Reality drill equipped (D key to use)");
				ColouredChatToPlayer(p, "1,0.5,0", "Cuts through tiles at max speed for 30 seconds.");
				spyEffect(1*trQuestVarGet("P"+p+"Siphon"), kbGetProtoUnitID("Monument"), xsVectorSet(dPlayerData,xSpyObject,p), vector(1,1,1));
				xsEnableRule("Nidhogg");
			}
			else{
				ColouredChatToPlayer(p, "1,0.5,0", "Super weapons are not permitted on this stage.");
			}
		}
	}
	xsDisableSelf();
}

rule BonusGo
inactive
highFrequency
{
	xsDisableSelf();
	Apply_Bonus();
	//Check status effects code
	/*
	xSetPointer(dPlayerData, 1);
	trChatSend(0, "Drill power:" + xGetFloat(dPlayerData, xDrillPower));
	*/
}

/*
for (x= xGetDatabaseCount(dDestroyMe); > 0) {
	xDatabaseNext(dDestroyMe);
	if(xGetInt(dDestroyMe, 1)){
		trUnitDestroy();
		xFreeDatabaseBlock(dDestroyMe);
		
		
		trUnitSelectClear();
		xUnitSelect(dDestroyMe, 1)
		trUnitChangeProtoUnit("Cinematic Block");
	}
}




so just add a new variable to that one
xMirrorTowerObject
something like that
and in the spy effect
the destination is (dPlayerData, xMirrorTowerObject, p)
and then the unit name of the spy eye will be stored in the xGetInt(dPlayerData, xMirrorTowerObject) at index p, which is the player


9
and then
xUnitSelect(dPlayerData, xSpyObject)
after setting the pointer

*/
