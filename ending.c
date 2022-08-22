rule TimesUp
inactive
highFrequency
{
	xsDisableSelf();
	xsDisableRule("CheckResigns");
	xsDisableRule("FuelEconomy");
	trSetFogAndBlackmap(false, false);
	trLetterBox(true);
	saveAllData();
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
		characterDialog("Your gold has been saved, go to SP to upgrade.", " ", "icons\special e son of osiris icon 64");
		xsDisableSelf();
		xsEnableRule("End1");
	}
	
}

rule End1
inactive
highFrequency
{
	if((trTime()-cActivationTime) >= 3){
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
		xsDisableSelf();
		trEndGame();
	}
	
}
