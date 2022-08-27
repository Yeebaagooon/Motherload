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
	}
	xsDisableSelf();
}

rule BonusGo
inactive
highFrequency
{
	xsDisableSelf();
	Apply_Bonus();
}
