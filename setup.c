int QuickStart = 0;
string MapVersion = "Test Version";
string MapName = "Motherload.xs";

rule Initialise
active
highFrequency
runImmediately
{
	characterDialog("Waiting for everyone to connect.", " ", "icons\special e son of osiris icon 64");
	trUIFadeToColor(0, 0, 0, 0, 10000, false);
	trFadeOutAllSounds(0.1);
	trFadeOutMusic(0.1);
	xsEnableRule("WorldBuild");
	if(QuickStart == 0){
	}
	trBlockAllSounds(true);
	trArmyDispatch("0,0", "Cinematic Block", 1, 0, 0, 0, 0, false);
	for(p = 1; <= cNumberNonGaiaPlayers){
		deployLocHeading(0, p*2, "Victory Marker", p, 180);
	}
	trSetFogAndBlackmap(false, false);
	%
	for(p=1; <= cNumberNonGaiaPlayers) {
		code("trStringQuestVarSet(\"p"+p+"name\", \""+rmGetPlayerName(p)+"\");");
	}
	%
	xsDisableSelf();
}

rule START
active
highFrequency
{
	aiSet("NoAI", 0);
	trPlayerKillAllGodPowers(0);
	for(p = 1; <= cNumberNonGaiaPlayers){
		trSetCivAndCulture(p, 3, 1);
		trPlayerGrantResources(p, "Food", -10000.0);
		trPlayerGrantResources(p, "Wood", -10000.0);
		trPlayerGrantResources(p, "Gold", -10000.0);
		trPlayerGrantResources(p, "Favor", -10000.0);
		trPlayerKillAllGodPowers(p);
		modifyProtounitAbsolute("Vision Revealer", p, 2, 24);
		modifyProtounitAbsolute("Vision Revealer", p, 8, 999999);
	}
	//start fade to black
	//trUIFadeToColor(1,0,0,0,0,true);
	trShowImageDialog("icons\improvement wealth of erebus icon 64", MapName + " by Yeebaagooon");
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
	characterDialog("Initialising map", " ", "icons\special e son of osiris icon 64");
	xsEnableRule("load1");
	xsDisableSelf();
}

rule load1
inactive
highFrequency
{
	characterDialog("Loading map.", ""+MapVersion+"", "icons\special e son of osiris icon 64");
	xsEnableRule("load2");
	trBlockAllSounds(false);
	xsDisableSelf();
}

rule load2
inactive
highFrequency
{
	characterDialog("Loading map..", ""+MapVersion+"", "icons\special e son of osiris icon 64");
	xsEnableRule("load3");
	xsDisableSelf();
}

rule load3
inactive
highFrequency
{
	if((trTime()-cActivationTime) >= 1){
		characterDialog("Loading map...", ""+MapVersion+"", "icons\special e son of osiris icon 64");
		aiSet("NoAI", 0);
		for(p = 1; <= cNumberNonGaiaPlayers){
			trPlayerGrantResources(p, "Food", -10000.0);
			trPlayerGrantResources(p, "Wood", -10000.0);
			trPlayerGrantResources(p, "Gold", -10000.0);
			trPlayerGrantResources(p, "Favor", -10000.0);
			trPlayerKillAllGodPowers(p);
			//this does custom content
			//	trSoundPlayFN("Yeebaagooon\test sound.mp3", "1", 3, "","");
		}
		xsEnableRule("load4");
		xsDisableSelf();
	}
}

rule load4
inactive
highFrequency
{
	if((trTime()-cActivationTime) >= 1){
		//fade out when loaded
		trUnblockAllSounds();
		trLetterBox(false);
		trUIFadeToColor(0,0,0,1000,1,false);
		trOverlayTextColour(255, 125, 0);
		gadgetUnreal("ShowImageBox");
		trOverlayText(MapName, 8.0, 566, 35, 1000);
		trSetUnitIdleProcessing(true);
		xsDisableSelf();
		paintShopSquare(3,3, "Black");
		UnitCreate(0, "Hoplite", 6, 6, 180);
		gadgetReal("ShowImageBox-BordersTop");
		gadgetReal("ShowImageBox-BordersBottom");
		gadgetReal("ShowImageBox-BordersLeft");
		gadgetReal("ShowImageBox-BordersRight");
		gadgetReal("ShowImageBox-BordersLeftTop");
		gadgetReal("ShowImageBox-BordersLeftBottom");
		gadgetReal("ShowImageBox-BordersRightBottom");
		gadgetReal("ShowImageBox-BordersRightTop");
		gadgetReal("ShowImageBox-CloseButton");
		//startNPCDialog(1);
		trTechGodPower(1, "Animal Magnetism", 1);
		trTechGodPower(1, "Nidhogg", 1);
		while(cNumberNonGaiaPlayers>=trQuestVarGet("PlayerID")) {
			trQuestVarSet("PlayerID2", 0);
			while(cNumberNonGaiaPlayers>=trQuestVarGet("PlayerID2")) {
				trPlayerSetDiplomacy(trQuestVarGet("PlayerID"), trQuestVarGet("PlayerID2"), "Enemy");
				trPlayerSetDiplomacy(trQuestVarGet("PlayerID2"), trQuestVarGet("PlayerID"), "Enemy");
			trQuestVarSet("PlayerID2", trQuestVarGet("PlayerID2")+1);}
		trQuestVarSet("PlayerID", trQuestVarGet("PlayerID")+1);}
	}
}

rule customcontent
inactive
highFrequency
{
	xsDisableSelf();
	trQuestVarSet("CustomContent", 1);
}
