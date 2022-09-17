rule Bonus_Display
inactive
highFrequency
{
	if((trTime()-cActivationTime) >= 2){
		xSetPointer(dPlayerData, 1);
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
				//ColouredIconChat("1,0.5,0", "icons\special e son of osiris icon 64","Bonus unlocked (3)!");
				//	playSoundCustom("cinematics\10_in\clearedcity.wav", "\Yeebaagooon\Motherload\UnlockBonus.mp3");
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
			trUnitChangeProtoUnit("Prisoner");
			trUnitSelectByQV("BonusUnit");
			trBlockAllSounds();
			trUnitChangeProtoUnit("Roc Tent");
			trUnblockAllSounds();
			trUnitSelectByQV("BonusUnit");
			trSetSelectedScale(0.5,0.5,0.5);
			trChatHistoryClear();
			ColouredChat("1,0.5,0", "Antimatter bomb equipped");
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
			grantGodPowerNoRechargeNextPosition(p, "Underworld Passage", 1);
			ColouredChatToPlayer(p, "1,0.5,0", "Mining laser equipped (L key to use)");
			ColouredChatToPlayer(p, "1,0.5,0", "DIRECTIONAL - mines 10 tiles in the target direction");
			ColouredChatToPlayer(p, "1,0.5,0", "Use like dynamite - have the cursor next to your ship");
		}
		if(xGetInt(dPlayerData, xBonus+15) == 2){
			grantGodPowerNoRechargeNextPosition(p, "Vision", 1);
			ColouredChatToPlayer(p, "1,0.5,0", "Antimatter bomb equipped (A key to use)");
			ColouredChatToPlayer(p, "1,0.5,0", "Blasts 5x5 squares around you when used.");
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
