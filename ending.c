rule TimesUp
inactive
highFrequency
{
	saveAllData();
	xsDisableSelf();
	xsEnableRule("SPExit");
}
