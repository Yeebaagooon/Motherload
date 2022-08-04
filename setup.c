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
	//trSetFogAndBlackmap(false, false);
	%
	for(p=1; < cNumberNonGaiaPlayers) {
		code("trStringQuestVarSet(\"p"+p+"name\", \""+rmGetPlayerName(p)+"\");");
	}
	%
	xsDisableSelf();
	xsSetContextPlayer(0);
	map("q", "game", "uiSetSpecialPower(227) uiSpecialPowerAtPointer");
}

rule START
active
highFrequency
{
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
	xsEnableRule("Stats");
	trBlockAllSounds(false);
	xsDisableSelf();
	modifyProtounitAbsolute("Vision Revealer", 0, 2, 2400);
	trArmyDispatch("0,0", "Vision Revealer", 1, 0, 0, 0, 0, false);
}

rule load2
inactive
highFrequency
{
	characterDialog("Loading map..", ""+MapVersion+"", "icons\special e son of osiris icon 64");
	xsEnableRule("load3");
	trSoundPlayFN("Yeebaagooon\test sound.mp3", "1", 13, "", "");
	xsDisableSelf();
}

rule load3
inactive
highFrequency
{
	if((trTime()-cActivationTime) >= 1){
		characterDialog("Loading map...", ""+MapVersion+"", "icons\special e son of osiris icon 64");
		for(p = 1; <= cNumberNonGaiaPlayers){
			trPlayerGrantResources(p, "Food", -10000.0);
			trPlayerGrantResources(p, "Wood", -10000.0);
			trPlayerGrantResources(p, "Gold", -10000.0);
			trPlayerGrantResources(p, "Favor", -10000.0);
			trPlayerKillAllGodPowers(p);
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
		trDelayedRuleActivation("PaintStageSelect");
		trSetFogAndBlackmap(false, false);
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
		for(p = 1; <= cNumberNonGaiaPlayers){
			trTechGodPower(p, "Animal Magnetism", 1);
		}
		while(cNumberNonGaiaPlayers>=trQuestVarGet("PlayerID")) {
			trQuestVarSet("PlayerID2", 0);
			while(cNumberNonGaiaPlayers>=trQuestVarGet("PlayerID2")) {
				trPlayerSetDiplomacy(trQuestVarGet("PlayerID"), trQuestVarGet("PlayerID2"), "Ally");
				trPlayerSetDiplomacy(trQuestVarGet("PlayerID2"), trQuestVarGet("PlayerID"), "Ally");
				trPlayerSetDiplomacy(trQuestVarGet("PlayerID2"), 0, "Ally");
				trPlayerSetDiplomacy(0, trQuestVarGet("PlayerID2"), "Enemy");
				trPlayerSetDiplomacy(trQuestVarGet("PlayerID2"), cNumberNonGaiaPlayers, "Enemy");
				trPlayerSetDiplomacy(cNumberNonGaiaPlayers, trQuestVarGet("PlayerID2"), "Enemy");
			trQuestVarSet("PlayerID2", trQuestVarGet("PlayerID2")+1);}
		trQuestVarSet("PlayerID", trQuestVarGet("PlayerID")+1);}
	}
}

rule PaintStageSelect
inactive
highFrequency
{
	PaintAtlantisArea(20,20,80,40,"black");
	trPaintTerrain(21,30,79,30, 0, 50, false);
	trQuestVarSet("StageSelector", trGetNextUnitScenarioNameNumber());
	UnitCreate(1, "Athena", 40, 60, 90);
	trCameraCut(vector(100.463554,153.803818,-59.088593), vector(0.001486,-0.784815,0.619728), vector(0.001882,0.619729,0.784813), vector(0.999997,0.000000,-0.002398));
	trOverlayText("Host, choose a stage", 8.0, 506, 70, 1000);
	for(p = 1; <= 9){
		trQuestVarSet("StageObelisk"+p+"", trGetNextUnitScenarioNameNumber());
		int x = 0;
		if (iModulo(2, p) == 0) { //if is divisble by 2
			x = 20;
		}
		UnitCreate(0, "Outpost", 40+12*p, 50+x, 90);
	}
	xsDisableSelf();
}

/*RULES DISABLED IN THE RAIN DOC THAT STARTS GAMES
rule TEMPdeployP1
rule squarespaint
rule lure
xsEnableRule("lure");
xsEnableRule("TEMPdeployP1");
xsEnableRule("squarespaint");
*/

