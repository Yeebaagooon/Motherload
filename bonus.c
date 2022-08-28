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
		Deselect_Bonus(bonus);
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
