rule TimesUp
inactive
highFrequency
{
	trChatSend(0, "data save");
	for(p=1; < cNumberNonGaiaPlayers) {
		int savedatasp = 0;
		savedatasp = trPlayerResourceCount(1, "Gold");
		int loaddatasp = trGetScenarioUserData(1);
		if(loaddatasp > 10000){
			savedatasp = trPlayerResourceCount(1, "Gold") - 10000 + loaddatasp;
		}
		trSetCurrentScenarioUserData(1, savedatasp);
		trChatSend(0, ""+savedatasp + " saved as gold");
	}
	xsDisableSelf();
	xsEnableRule("SPExit");
}
