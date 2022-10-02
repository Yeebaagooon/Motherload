//PLANET RUN TRACK
/*
trCameraCut(vector(172.973831,17.603882,68.110535), vector(-0.924538,-0.119115,0.361996), vector(-0.110916,0.992880,0.043429), vector(0.364592,-0.000001,0.931167));
trCameraCut(vector(32.666248,17.603880,88.336098), vector(-0.956699,-0.282499,0.070150), vector(-0.281743,0.959267,0.020660), vector(0.073129,-0.000001,0.997322));


//ZOOM STAR TRACK
trCameraCut(vector(13.696568,-162.156204,187.372375), vector(0.047790,0.997395,-0.054029), vector(-0.660807,0.072132,0.747082), vector(-0.749033,0.000000,-0.662533));
trCameraCut(vector(38.738640,-8.136196,160.419250), vector(0.047790,0.997395,-0.054029), vector(-0.660807,0.072132,0.747082), vector(-0.749033,0.000000,-0.662533));


//TV TRACK
trCameraCut(vector(184.909134,14.763709,182.640610), vector(0.002345,-0.209853,0.977730), vector(0.000503,0.977733,0.209853), vector(0.999997,-0.000000,-0.002398));
trCameraCut(vector(181.387436,17.402742,156.046768), vector(0.002357,-0.184338,0.982860), vector(0.000442,0.982863,0.184337), vector(0.999997,-0.000000,-0.002398));
trCameraCut(vector(178.336853,23.402742,134.933929), vector(0.002322,-0.249727,0.968314), vector(0.000599,0.968316,0.249726), vector(0.999997,-0.000000,-0.002398));
*/

rule CineSetup
inactive
highFrequency
{
	xsDisableSelf();
	trUnitSelectByQV("ExitYeeb");
	trUnitChangeProtoUnit("Cinematic Block");
	trPlayerSetDiplomacy(0,1,"Enemy");
	trLetterBox(true);
	trUIFadeToColor(0,0,0,1,1,true);
	trQuestVarSet("StarUnit", trGetNextUnitScenarioNameNumber());
	trArmyDispatch("1,0", "Victory Marker", 1, 1,0,199,0,false);
	//PaintAtlantisArea(0,79,20,99,"black");
	trUnitSelectByQV("StarUnit");
	trUnitChangeProtoUnit("Priest");
	trUnitSelectByQV("StarUnit");
	trSetSelectedScale(-0.01,1,-0.01);
	spyEffect(1*trQuestVarGet("StarUnit"), kbGetProtoUnitID("Tower Mirror"), vector(0,0,0),vector(0,0,0));
	spyEffect(1*trQuestVarGet("StarUnit"), kbGetProtoUnitID("Tower Mirror"), vector(0,0,0),vector(0,0,0));
	spyEffect(1*trQuestVarGet("StarUnit"), kbGetProtoUnitID("Tower Mirror"), vector(0,0,0),vector(0,0,0));
	spyEffect(1*trQuestVarGet("StarUnit"), kbGetProtoUnitID("Tower Mirror"), vector(0,0,0),vector(0,0,0));
	spyEffect(1*trQuestVarGet("StarUnit"), kbGetProtoUnitID("Implode Sphere Effect"), vector(0,0,0),vector(0,0,0), 18);
	xsEnableRule("Cine_01");
	trModifyProtounit("Priest", 1, 55, 4);
	trSetFogAndBlackmap(false, false);
	xAddDatabaseBlock(dSpace, true);
	xSetInt(dSpace, xSpaceName,1*trQuestVarGet("StarUnit"));
	for(n=1 ; <= 150){
		trQuestVarSetFromRand("TempX", 0, 60, false);
		trQuestVarSetFromRand("TempZ", 140, 199, false);
		trQuestVarSet("TempUnit", trGetNextUnitScenarioNameNumber());
		trArmyDispatch("0,0", "Victory Marker", 1, 1*trQuestVarGet("TempX"),0,1*trQuestVarGet("TempZ"),0,false);
		trUnitSelectByQV("TempUnit");
		trUnitChangeProtoUnit("Armor Glow Small");
		xAddDatabaseBlock(dSpace, true);
		xSetInt(dSpace, xSpaceName,1*trQuestVarGet("TempUnit"));
	}
	for(n=1 ; <= 20){
		trQuestVarSetFromRand("TempX", 0, 60, false);
		trQuestVarSetFromRand("TempZ", 140, 199, false);
		trQuestVarSet("TempUnit", trGetNextUnitScenarioNameNumber());
		trArmyDispatch("1,0", "Victory Marker", 1, 1*trQuestVarGet("TempX"),0,1*trQuestVarGet("TempZ"),0,false);
		trUnitSelectByQV("TempUnit");
		trUnitChangeProtoUnit("Relic");
		trUnitSelectByQV("TempUnit");
		trSetSelectedScale(0,0,0);
		xAddDatabaseBlock(dSpace, true);
		xSetInt(dSpace, xSpaceName,1*trQuestVarGet("TempUnit"));
	}
	for(n=1 ; <= 20){
		trQuestVarSetFromRand("TempX", 0, 60, false);
		trQuestVarSetFromRand("TempZ", 140, 199, false);
		trQuestVarSet("TempUnit", trGetNextUnitScenarioNameNumber());
		trArmyDispatch("1,0", "Victory Marker", 1, 1*trQuestVarGet("TempX"),0,1*trQuestVarGet("TempZ"),0,false);
		trUnitSelectByQV("TempUnit");
		trUnitChangeProtoUnit("Lampades");
		trUnitSelectByQV("TempUnit");
		trSetSelectedScale(0,0,0);
		xAddDatabaseBlock(dSpace, true);
		xSetInt(dSpace, xSpaceName,1*trQuestVarGet("TempUnit"));
	}
	for(n=1 ; <= 4){
		trQuestVarSetFromRand("TempX", 0, 60, false);
		trQuestVarSetFromRand("TempZ", 140, 199, false);
		trQuestVarSet("TempUnit", trGetNextUnitScenarioNameNumber());
		trArmyDispatch("1,0", "Victory Marker", 1, 1*trQuestVarGet("TempX"),0,1*trQuestVarGet("TempZ"),0,false);
		trUnitSelectByQV("TempUnit");
		trUnitChangeProtoUnit("Plenty Vault");
		trUnitSelectByQV("TempUnit");
		trSetSelectedScale(0,0,0);
		xAddDatabaseBlock(dSpace, true);
		xSetInt(dSpace, xSpaceName,1*trQuestVarGet("TempUnit"));
	}
}

rule Cine_01
inactive
highFrequency
{
	if((trTime()-cActivationTime) >= 2){
		xsDisableSelf();
		createCameraTrack(20000);
		trCameraCut(vector(13.696568,-162.156204,187.372375), vector(0.047790,0.997395,-0.054029), vector(-0.660807,0.072132,0.747082), vector(-0.749033,0.000000,-0.662533));
		addCameraTrackWaypoint();
		trCameraCut(vector(38.738640,-8.136196,160.419250), vector(0.047790,0.997395,-0.054029), vector(-0.660807,0.072132,0.747082), vector(-0.749033,0.000000,-0.662533));
		addCameraTrackWaypoint();
		playCameraTrack();
		trUnitSelectByQV("StarUnit");
		trUnitMoveToPoint(40,3,160,-1,false);
		trUIFadeToColor(0,0,0,1000,1,false);
		xsEnableRule("Cine_02");
		characterDialog("Yeebaagooon", "Space. The final frontier.", "icons\special e son of osiris icon 64");
		playSound("cinematics\35_out\music2.mp3");
	}
}

rule Cine_02
inactive
highFrequency
{
	if((trTime()-cActivationTime) >= 5){
		xsDisableSelf();
		characterDialog("Yeebaagooon", "We are approaching the rogue star known as Sol.", "icons\special e son of osiris icon 64");
		xsEnableRule("Cine_03");
	}
}

rule Cine_03
inactive
highFrequency
{
	if((trTime()-cActivationTime) >= 5){
		xsDisableSelf();
		characterDialog("Yeebaagooon", "This is where you will be operating for the duration of the contract.", "icons\special e son of osiris icon 64");
		xsEnableRule("Cine_04");
	}
}

rule Cine_04
inactive
highFrequency
{
	if((trTime()-cActivationTime) >= 5){
		xsDisableSelf();
		characterDialog("Yeebaagooon", "Great riches and the chance of a stellar reputation beckon.", "icons\special e son of osiris icon 64");
		xsEnableRule("Cine_05");
	}
}

rule Cine_05
inactive
highFrequency
{
	if((trTime()-cActivationTime) >= 4){
		xsDisableSelf();
		characterDialog(" ", " ", " ");
		trUIFadeToColor(255,255,255,1000,1,true);
		xsEnableRule("Cine_06");
	}
}

rule Cine_06
inactive
highFrequency
{
	if((trTime()-cActivationTime) >= 2){
		xsDisableSelf();
		playSound("cinematics\22_out\music (wussy mix).mp3");
		xsEnableRule("Cine_07");
		characterDialog(" ", " ", " ");
		trUIFadeToColor(255,255,255,1000,1,false);
		createCameraTrack(15000);
		trCameraCut(vector(172.973831,17.603882,68.110535), vector(-0.924538,-0.119115,0.361996), vector(-0.110916,0.992880,0.043429), vector(0.364592,-0.000001,0.931167));
		addCameraTrackWaypoint();
		trCameraCut(vector(32.666248,17.603880,88.336098), vector(-0.956699,-0.282499,0.070150), vector(-0.281743,0.959267,0.020660), vector(0.073129,-0.000001,0.997322));
		addCameraTrackWaypoint();
		playCameraTrack();
		trUnitSelectClear();
		trUnitSelectByQV("StarUnit");
		trUnitTeleport(0,0,0);
		trPaintTerrain(0,0,200,200,5,4,false);
		for(x=xGetDatabaseCount(dSpace); >0) {
			xDatabaseNext(dSpace);
			xUnitSelect(dSpace,xSpaceName);
			trUnitDestroy();
		}
		aiPlanDestroy(dSpace);
		for(x=xGetDatabaseCount(dObelisks); >0) {
			xDatabaseNext(dObelisks);
			xUnitSelect(dObelisks,xObeliskName);
			trUnitChangeProtoUnit("Cinematic Block");
		}
		unitTransform("Implode Sphere Effect", "Rocket");
		unitTransform("Tower Mirror", "Rocket");
	}
}

rule Cine_07
inactive
highFrequency
{
	if((trTime()-cActivationTime) >= 2){
		xsDisableSelf();
		characterDialog("Yeebaagooon", "Behold, the nine planets in this system.", "icons\special e son of osiris icon 64");
		xsEnableRule("Cine_08");
	}
}

rule Cine_08
inactive
highFrequency
{
	if((trTime()-cActivationTime) >= 4){
		xsDisableSelf();
		characterDialog("Yeebaagooon", "Now you'll probably want to know how to get rich.", "icons\special e son of osiris icon 64");
		xsEnableRule("Cine_09");
	}
}

rule Cine_09
inactive
highFrequency
{
	if((trTime()-cActivationTime) >= 4){
		xsDisableSelf();
		characterDialog("Yeebaagooon", "And for this part I'll hand you over to your supervisor.", "icons\special e son of osiris icon 64");
		xsEnableRule("Cine_10");
		trFadeOutMusic(8);
		trFadeOutAllSounds(8);
	}
}

rule Cine_10
inactive
highFrequency
{
	if((trTime()-cActivationTime) >= 4){
		//-----WALL---------------------------------------------
		for(x=1 ; <= 30){
			for(y=1 ; <= 2){
				FloatingUnit("Columns", 140+x*2, y*6-7, 192, 90, 1,4,3);
				trUnitSetVariation(1*trQuestVarGet("QVRelic"), 2);
				trUnitSetVariation(1*trQuestVarGet("QVHero"), 2);
			}
		}
		//----------------------------------------------
		//-----FLOOR---------------------------------------------
		for(x=1 ; <= 30){
			for(z=1 ; <= 20){
				trQuestVarSet("TempUnit", trGetNextUnitScenarioNameNumber());
				trArmyDispatch("1,0", "Victory Marker", 1, 140+x*2,0,170+z*2,180,false);
				trUnitSelectByQV("TempUnit");
				trUnitChangeProtoUnit("Statue of Automaton Base");
				trUnitSelectByQV("TempUnit");
				trSetSelectedScale(2,0.5,2);
			}
		}
		//----------------------------------------------
		trLetterBox(true);
		xsDisableSelf();
		trQuestVarSet("MrNatas", trGetNextUnitScenarioNameNumber());
		trArmyDispatch("1,0", "Victory Marker", 1, 175,0,190,180,false);
		trUnitSelectByQV("MrNatas");
		trUnitChangeProtoUnit("Gargarensis");
		//-----TV---------------------------------------
		FloatingUnit("Columns", 180, 8, 190, 0, 1,2,1);
		FloatingUnit("Columns", 188, 8, 190, 0, 1,2,1);
		FloatingUnit("Columns Fallen", 186, 8, 190, 90, 1,1,1);
		FloatingUnit("Columns Fallen", 182, 8, 190, 270, 1,1,1);
		FloatingUnit("Columns Fallen", 186, 15, 190, 90, 1,1,1);
		FloatingUnit("Columns Fallen", 182, 15, 190, 270, 1,1,1);
		FloatingUnitAnimIdle("Waterfall", 184, 8, 190, 180, 1.6,0.66,0.1);
		//----------------------------------------------
		xsEnableRule("Cine_11");
		characterDialog(" ", " ", " ");
		createCameraTrack(4500);
		trCameraCut(vector(184.909134,14.763709,182.640610), vector(0.002345,-0.209853,0.977730), vector(0.000503,0.977733,0.209853), vector(0.999997,-0.000000,-0.002398));
		addCameraTrackWaypoint();
		trCameraCut(vector(184.909134,14.763709,182.640610), vector(0.002345,-0.209853,0.977730), vector(0.000503,0.977733,0.209853), vector(0.999997,-0.000000,-0.002398));
		playCameraTrack();
	}
}

rule Cine_11
inactive
highFrequency
{
	if((trTime()-cActivationTime) >= 1){
		xsDisableSelf();
		createCameraTrack(4500);
		trCameraCut(vector(184.909134,14.763709,182.640610), vector(0.002345,-0.209853,0.977730), vector(0.000503,0.977733,0.209853), vector(0.999997,-0.000000,-0.002398));
		addCameraTrackWaypoint();
		trCameraCut(vector(181.387436,17.402742,156.046768), vector(0.002357,-0.184338,0.982860), vector(0.000442,0.982863,0.184337), vector(0.999997,-0.000000,-0.002398));
		addCameraTrackWaypoint();
		trCameraCut(vector(178.336853,23.402742,128.643524), vector(0.002322,-0.249727,0.968314), vector(0.000599,0.968316,0.249726), vector(0.999997,-0.000000,-0.002398));
		addCameraTrackWaypoint();
		playCameraTrack();
		xsEnableRule("Cine_12");
		playSoundCustom("waterfallloop.wav");
	}
}

rule Cine_12
inactive
highFrequency
{
	if((trTime()-cActivationTime) >= 1){
		xsDisableSelf();
		characterDialog("Mr Natas", "My name is Mr Natas.", "icons\scenario g gargarensis icon 64");
		xsEnableRule("Cine_13");
		trUnitSelectClear();
		trUnitSelectByQV("MrNatas");
		trUnitOverrideAnimation(25,0,false,false,-1,0);
		playSound("cinematics\23_out\music 1.mp3");
	}
}

rule Cine_13
inactive
highFrequency
{
	if((trTime()-cActivationTime) >= 2){
		xsDisableSelf();
		characterDialog("Mr Natas", "Enough of that corporate video rubbish, this job is dangerous.", "icons\scenario g gargarensis icon 64");
		xsEnableRule("Cine_14");
		trUnitSelectClear();
		trUnitSelectByQV("MrNatas");
		trUnitOverrideAnimation(25,2,false,false,-1,0);
	}
}

rule Cine_14
inactive
highFrequency
{
	if((trTime()-cActivationTime) >= 4){
		xsDisableSelf();
		characterDialog("Mr Natas", "And you're only here so Yeebaagooon can get rich by exploiting us.", "icons\scenario g gargarensis icon 64");
		xsEnableRule("Cine_15");
		trUnitSelectClear();
		trUnitSelectByQV("MrNatas");
		trUnitOverrideAnimation(25,16,false,false,-1,0);
		createCameraTrack(5000);
		trCameraCut(vector(178.336853,23.402742,128.643524), vector(0.002322,-0.249727,0.968314), vector(0.000599,0.968316,0.249726), vector(0.999997,-0.000000,-0.002398));
		addCameraTrackWaypoint();
		trCameraCut(vector(170.945755,11.402742,163.928833), vector(0.181878,-0.216666,0.959154), vector(0.040366,0.976246,0.212873), vector(0.982492,-0.000000,-0.186303));
		addCameraTrackWaypoint();
		playCameraTrack();
	}
}

rule Cine_15
inactive
highFrequency
{
	if((trTime()-cActivationTime) >= 4){
		xsDisableSelf();
		characterDialog("Mr Natas", "Anyway, down to business...", "icons\scenario g gargarensis icon 64");
		xsEnableRule("Cine_16");
	}
}

rule Cine_16
inactive
highFrequency
{
	if((trTime()-cActivationTime) >= 2){
		xsDisableSelf();
		characterDialog("Mr Natas", "You will touch down on a planet and drill for minerals.", "icons\scenario g gargarensis icon 64");
		xsEnableRule("Cine_17");
		createCameraTrack(6000);
		trCameraCut(vector(170.945755,11.402742,163.928833), vector(0.181878,-0.216666,0.959154), vector(0.040366,0.976246,0.212873), vector(0.982492,-0.000000,-0.186303));
		addCameraTrackWaypoint();
		trCameraCut(vector(184.909134,14.763709,182.640610), vector(0.002345,-0.209853,0.977730), vector(0.000503,0.977733,0.209853), vector(0.999997,-0.000000,-0.002398));
		addCameraTrackWaypoint();
		trCameraCut(vector(184.909134,14.763709,182.640610), vector(0.002345,-0.209853,0.977730), vector(0.000503,0.977733,0.209853), vector(0.999997,-0.000000,-0.002398));
		addCameraTrackWaypoint();
		playCameraTrack();
		trUIFadeToColor(255,255,255,2000,1500,true);
		trFadeOutMusic(8);
		trFadeOutAllSounds(8);
	}
}

//Next in former space, build a mini map

rule Cine_17
inactive
highFrequency
{
	if((trTime()-cActivationTime) >= 3){
		xsDisableSelf();
		characterDialog(" ", " ", " ");
		trPaintTerrain(0,0,200,200,3,15,false);
		trPaintTerrain(0,60,36,80,5,4,false);
		for(x=1 ; <= 9){
			for(z=1 ; <= 5){
				trPaintTerrain(4*x-1,60+4*z-1,4*x-3,60+4*z-3,0,31,false);
			}
		}
		xsEnableRule("Cine_18");
	}
}

rule Cine_18
inactive
highFrequency
{
	if((trTime()-cActivationTime) >= 1){
		xsDisableSelf();
		createCameraTrack(6);
		trCameraCut(vector(38.436657,91.262711,161.452484), vector(0.000003,-0.999999,0.001399), vector(0.002398,0.001399,0.999996), vector(0.999997,-0.000000,-0.002398));
		addCameraTrackWaypoint();
		trCameraCut(vector(38.436657,91.262711,161.452484), vector(0.000003,-0.999999,0.001399), vector(0.002398,0.001399,0.999996), vector(0.999997,-0.000000,-0.002398));
		addCameraTrackWaypoint();
		playCameraTrack();
		trUIFadeToColor(255,255,255,1800,1,false);
		characterDialog("Mr Natas", "Relics are the minerals you are aiming to collect.", "icons\scenario g gargarensis icon 64");
		xsEnableRule("Cine_19");
		trQuestVarSet("TempRelic", trGetNextUnitScenarioNameNumber());
		trArmyDispatch("1,0", "Victory Marker", 1, 36.5,3,157.3,180,false);
		trUnitSelectByQV("TempRelic");
		trUnitChangeProtoUnit("Relic");
		trQuestVarSet("TempSiphon", trGetNextUnitScenarioNameNumber());
		trArmyDispatch("1,0", "Victory Marker", 1, 36.5,3,170,180,false);
		trUnitSelectByQV("TempSiphon");
		trUnitChangeProtoUnit("Fire Siphon");
		PaintSmelter(20,180);
		PaintSellTerrain(15,89);
		playSound("xpack\xcinematics\12_a\musicdown.mp3");
		
		//36.55, 3.00, 157.29
	}
}

rule Cine_19
inactive
highFrequency
{
	if((trTime()-cActivationTime) >= 2){
		xsDisableSelf();
		trUnitSelectClear();
		trUnitSelectByQV("TempSiphon");
		trUnitMoveToPoint(36.5,3,164,-1,false);
		xsEnableRule("Cine_20");
	}
}

rule Cine_20
inactive
highFrequency
{
	if((trTime()-cActivationTime) >= 2){
		xsDisableSelf();
		characterDialog("Mr Natas", "Move your mouse to the square you want to drill and then press 'Q'.", "icons\scenario g gargarensis icon 64");
		xsEnableRule("Cine_21");
	}
}

rule Cine_21
inactive
highFrequency
{
	if((trTime()-cActivationTime) >= 4){
		xsDisableSelf();
		characterDialog("Mr Natas", "Different rocks vary in hardness.", "icons\scenario g gargarensis icon 64");
		trOverlayTextColour(0,0,0);
		trOverlayText("Q", 3.0, 600, 450, 1000);
		trUnitSelectClear();
		trModifyProtounit("Fire Siphon", 1, 55, 4);
		trUnitSelectByQV("TempSiphon");
		trUnitMoveToPoint(36.5,3,157,-1,false);
		xsEnableRule("Cine_22");
		trModifyProtounit("Fire Siphon", 1, 1, -1.5);
		spyEffect(1*trQuestVarGet("TempSiphon"), kbGetProtoUnitID("Heka Shockwave SFX"), vector(0,0,0),vector(0,0,0));
	}
}

rule Cine_22
inactive
highFrequency
{
	if((trTime()-cActivationTime) >= 5){
		xsDisableSelf();
		characterDialog("Mr Natas", "Then pick up the relic.", "icons\scenario g gargarensis icon 64");
		xsEnableRule("Cine_23");
		trUnitSelectClear();
		trUnitSelectByQV("TempRelic");
		trUnitDestroy();
		playSound("garrison.wav");
		unitTransform("Heka Shockwave SFX", "Rocket");
		trPaintTerrain(17,77,19,79,5,3,false);
		trModifyProtounit("Fire Siphon", 1, 1, 3);
		trOverlayTextColour(255,125,0);
		trOverlayText(".", 0.1, 1, 1, 10);
	}
}

rule Cine_23
inactive
highFrequency
{
	if((trTime()-cActivationTime) >= 3){
		xsDisableSelf();
		characterDialog("Mr Natas", "And return to the surface to sell it.", "icons\scenario g gargarensis icon 64");
		xsEnableRule("Cine_24");
		trUnitSelectClear();
		trUnitSelectByQV("TempSiphon");
		trUnitMoveToPoint(36.5,3,178,-1,false);
		createCameraTrack(4000);
		trCameraCut(vector(38.436657,91.262711,161.452484), vector(0.000003,-0.999999,0.001399), vector(0.002398,0.001399,0.999996), vector(0.999997,-0.000000,-0.002398));
		addCameraTrackWaypoint();
		trCameraCut(vector(38.484264,91.262711,181.312469), vector(0.000003,-0.999999,0.001399), vector(0.002398,0.001399,0.999996), vector(0.999997,-0.000000,-0.002398));
		addCameraTrackWaypoint();
		playCameraTrack();
	}
}

rule Cine_24
inactive
highFrequency
{
	if((trTime()-cActivationTime) >= 4){
		xsDisableSelf();
		characterDialog("Mr Natas", "You can initially hold up to 2 relics.", "icons\scenario g gargarensis icon 64");
		spyEffect(1*trQuestVarGet("TempSiphon"), kbGetProtoUnitID("Automaton"), xsVectorSet(dPlayerData,xSpyObject,1),vector(0,0,0), 18);
		playSound("favordump.wav");
		xsEnableRule("Cine_25");
	}
}

rule Cine_25
inactive
highFrequency
{
	if((trTime()-cActivationTime) >= 4){
		xsDisableSelf();
		characterDialog("Mr Natas", "Also watch your fuel gauge on the right of your screen when playing.", "icons\scenario g gargarensis icon 64");
		xsEnableRule("Cine_26");
	}
}

rule Cine_26
inactive
highFrequency
{
	if((trTime()-cActivationTime) >= 4){
		xsDisableSelf();
		characterDialog("Mr Natas", "You can refuel on the surface at the fuel shop.", "icons\scenario g gargarensis icon 64");
		xsEnableRule("Cine_27");
		trPaintTerrain(0,0,200,200,3,15,false);
		PaintFuelTerrain(15,89);
		SelectableSign(37, 181, 18);
		PaintAtlantisArea(24,87,26,89,"GrassA");
		trUnitSelectByQV("TempSiphon");
		trUnitMoveToPoint(50,3,178,-1,false);
		trUnitSelectByQV("TempSiphon");
		trUnitChangeInArea(0,0,"Dwarven Forge", "Rocket",40);
		//unitTransform("Dwarven Forge", "Rocket");
		trUnitSelectClear();
		xUnitSelect(dPlayerData, xSpyObject);
		trUnitChangeProtoUnit("Rocket");
	}
}

rule Cine_27
inactive
highFrequency
{
	if((trTime()-cActivationTime) >= 4){
		xsDisableSelf();
		characterDialog("Mr Natas", "You will be extracted after a set time, and can unlock the right to mine other planets based on your performance.", "icons\scenario g gargarensis icon 64");
		trPaintTerrain(0,0,200,200,3,15,false);
		trUnitSelectByQV("TempSiphon");
		trUnitChangeProtoUnit("Hero Death");
		xsEnableRule("Cine_28");
		trUnitSelectByQV("ExitYeeb");
		trUnitChangeProtoUnit("Pharaoh of Osiris XP");
	}
}

rule Cine_28
inactive
highFrequency
{
	if((trTime()-cActivationTime) >= 5){
		xsDisableSelf();
		characterDialog("Mr Natas", "Launch this map in singleplayer to upgrade your ship.", "icons\scenario g gargarensis icon 64");
		PaintSP();
		trCameraCut(vector(70.313728,125.462654,-71.500542), vector(0.001486,-0.784815,0.619728), vector(0.001882,0.619730,0.784813), vector(0.999997,-0.000000,-0.002398));
		xsEnableRule("Cine_29");
		playSound("cinematics\26_in\music.mp3");
	}
}

rule Cine_29
inactive
highFrequency
{
	if((trTime()-cActivationTime) >= 4){
		xsDisableSelf();
		characterDialog("Mr Natas", "Click the obelisks to upgrade certain aspects such as your engine or fuel tank.", "icons\scenario g gargarensis icon 64");
		xsEnableRule("Cine_30");
		for(x=xGetDatabaseCount(dSelectables); >0) {
			xDatabaseNext(dSelectables);
			xUnitSelect(dSelectables,xSelectablesName);
			trUnitHighlight(4, true);
		}
	}
}

rule Cine_30
inactive
highFrequency
{
	if((trTime()-cActivationTime) >= 4){
		xsDisableSelf();
		characterDialog("Mr Natas", "And then garrison Yeeb in the underworld passage to save.", "icons\scenario g gargarensis icon 64");
		trPaintTerrain(0,32,60,80,5,4,false);
		xsEnableRule("Cine_301");
		trUnitSelectClear();
		trUnitSelectByQV("ExitTunnel");
		trUnitHighlight(4, true);
		trUnitSelectClear();
		trUnitSelectByQV("ExitYeeb");
		trUnitHighlight(4, true);
	}
}

rule Cine_301
inactive
highFrequency
{
	if((trTime()-cActivationTime) >= 4){
		xsDisableSelf();
		characterDialog("Mr Natas", "Keep coming back to check the bonus bar (flashing).", "icons\scenario g gargarensis icon 64");
		trCameraCut(vector(30.535799,60.188759,3.073936), vector(0.000989,-0.707107,0.707106), vector(0.000988,0.707106,0.707107), vector(0.999999,0.000000,-0.001398));
		xsEnableRule("Cine_302");
		for(a=1 ; <13){
			trUnitSelectByQV("Bonus"+a+"");
			trUnitHighlight(5, true);
		}
	}
}

rule Cine_302
inactive
highFrequency
{
	if((trTime()-cActivationTime) >= 4){
		xsDisableSelf();
		characterDialog("Mr Natas", "Click an unlocked bonus to find out what it does and equip it.", "icons\scenario g gargarensis icon 64");
		xsEnableRule("Cine_303");
	}
}

rule Cine_303
inactive
highFrequency
{
	if((trTime()-cActivationTime) >= 4){
		xsDisableSelf();
		characterDialog("Mr Natas", "Click an obelisk that is lit up for instructions on how to unlock that bonus.", "icons\scenario g gargarensis icon 64");
		xsEnableRule("Cine_31");
	}
}

rule Cine_31
inactive
highFrequency
{
	if((trTime()-cActivationTime) >= 4){
		xsDisableSelf();
		createCameraTrack(4500);
		trCameraCut(vector(184.909134,14.763709,182.640610), vector(0.002345,-0.209853,0.977730), vector(0.000503,0.977733,0.209853), vector(0.999997,-0.000000,-0.002398));
		addCameraTrackWaypoint();
		trCameraCut(vector(181.387436,17.402742,156.046768), vector(0.002357,-0.184338,0.982860), vector(0.000442,0.982863,0.184337), vector(0.999997,-0.000000,-0.002398));
		addCameraTrackWaypoint();
		trCameraCut(vector(178.336853,23.402742,128.643524), vector(0.002322,-0.249727,0.968314), vector(0.000599,0.968316,0.249726), vector(0.999997,-0.000000,-0.002398));
		addCameraTrackWaypoint();
		playCameraTrack();
		xsEnableRule("Cine_32");
		characterDialog(" ", " ", " ");
	}
}

rule Cine_32
inactive
highFrequency
{
	if((trTime()-cActivationTime) >= 1){
		xsDisableSelf();
		characterDialog("Mr Natas", "That concludes the portion of my life I am forced to waste talking to you.", "icons\scenario g gargarensis icon 64");
		xsEnableRule("Cine_33");
		trUnitSelectClear();
		trUnitSelectByQV("MrNatas");
		trUnitOverrideAnimation(25,11,false,false,-1,0);
		playSound("xpack\xcinematics\7_out\music.mp3");
	}
}

rule Cine_33
inactive
highFrequency
{
	if((trTime()-cActivationTime) >= 4){
		xsDisableSelf();
		characterDialog("Mr Natas", "Although I'm also expected to give you encouragement and bounties for completing menial objectives.", "icons\scenario g gargarensis icon 64");
		xsEnableRule("Cine_34");
		trUnitSelectClear();
		trUnitSelectByQV("MrNatas");
		trUnitOverrideAnimation(25,15,false,false,-1,0);
	}
}

rule Cine_34
inactive
highFrequency
{
	if((trTime()-cActivationTime) >= 5){
		xsDisableSelf();
		characterDialog("Mr Natas", "Regretfully, I will remain contractually in touch.", "icons\scenario g gargarensis icon 64");
		trUIFadeToColor(0,0,0,2000,2500,true);
		xsEnableRule("Cine_35");
	}
}

rule Cine_35
inactive
highFrequency
{
	if((trTime()-cActivationTime) >= 5){
		xsDisableSelf();
		characterDialog(" ", " ", " ");
		if(1*trQuestVarGet("CineStatus") == 0){
			xsEnableRule("Cine_36");
		}
		if(1*trQuestVarGet("CineStatus") != 0){
			xsEnableRule("Cine_Off");
			characterDialog("You already have the cine watch reward (+100L fuel).", "", "");
		}
	}
}

rule Cine_36
inactive
highFrequency
{
	if((trTime()-cActivationTime) >= 1){
		xsDisableSelf();
		characterDialog("Reward gained", "+100L fuel - Select this from the bonus bar in singleplayer", "icons\improvement murder holes icon 64");
		playSoundCustom("cinematics\10_in\clearedcity.wav", "\Yeebaagooon\Motherload\UnlockBonus.mp3");
		xsEnableRule("Cine_37");
	}
}

rule Cine_37
inactive
highFrequency
{
	if((trTime()-cActivationTime) >= 4){
		xsDisableSelf();
		xSetPointer(dPlayerData, 1);
		if(xGetInt(dPlayerData, xGold) == 0){
			xSetInt(dPlayerData, xGold, 10);
			characterDialog("Mr Natas", "And you've also been given enough gold for one free ship upgrade.", "icons\scenario g gargarensis icon 64");
			xsEnableRule("Cine_38");
			UpgradeEffect();
		}
		else{
			xsEnableRule("Cine_Off");
		}
	}
}

rule Cine_38
inactive
highFrequency
{
	if((trTime()-cActivationTime) >= 3){
		xsDisableSelf();
		xsEnableRule("Cine_Off");
	}
}


rule Cine_Off
inactive
highFrequency
{
	if((trTime()-cActivationTime) >= 2){
		if(1*trQuestVarGet("CineStatus") == 0){
			trQuestVarSet("CineStatus", 1);
			saveAllData();
		}
		xsDisableSelf();
		trUnitSelectClear();
		trUnitSelectByQV("MrNatas");
		trUnitDestroy();
		trLetterBox(false);
		trUIFadeToColor(0,0,0,1300,1,false);
		createCameraTrack(6);
		trCameraCut(vector(70.313728,125.462654,-71.500542), vector(0.001486,-0.784815,0.619728), vector(0.001882,0.619730,0.784813), vector(0.999997,-0.000000,-0.002398));
		addCameraTrackWaypoint();
		trCameraCut(vector(70.313728,125.462654,-71.500542), vector(0.001486,-0.784815,0.619728), vector(0.001882,0.619730,0.784813), vector(0.999997,-0.000000,-0.002398));
		addCameraTrackWaypoint();
		playCameraTrack();
		trPaintTerrain(0,0,200,200,5,4,false);
		PaintSP();
		PaintAtlantisArea(8,35,8+60,35+20,"black");
		trPaintTerrain(8+1,35+10,8+59,35+10, 0, 50, false);
		for(x=xGetDatabaseCount(dObelisks); >0) {
			xDatabaseNext(dObelisks);
			xUnitSelect(dObelisks,xObeliskName);
			trUnitChangeProtoUnit("Outpost");
		}
		trBlockAllSounds();
		int temp = trGetNextUnitScenarioNameNumber();
		trArmyDispatch("0,0","Dwarf",1,8*2+84,0,35*2+10,90,true);
		trArmySelect("0,0");
		trUnitChangeProtoUnit("Spy Eye");
		trUnitSelectClear();
		trUnitSelect(""+temp, true);
		trMutateSelected(kbGetProtoUnitID("Hades Door"));
		trSetSelectedScale(0,0,0);
		trUnitOverrideAnimation(25,0,false,false,-1);
		trUnitSetAnimationPath("3,0,0,0,0,0,0");
		trSetUnitOrientation(vector(-1,-1,-1),vector(0,0,0),true);
		xAddDatabaseBlock(dPlanetEyecandy, true);
		xSetInt(dPlanetEyecandy, xPlanetEyecandyName,temp);
		xSetInt(dPlanetEyecandy, xPlanetEyecandyStage, 7);
		temp = trGetNextUnitScenarioNameNumber();
		trArmyDispatch("0,0","Dwarf",1,8*2+84,0,35*2+10,180,true);
		trArmySelect("0,0");
		trUnitChangeProtoUnit("Spy Eye");
		trUnitSelectClear();
		trUnitSelect(""+temp, true);
		trMutateSelected(kbGetProtoUnitID("Hades Door"));
		trSetSelectedScale(0,0,0);
		trUnitOverrideAnimation(25,0,false,false,-1);
		trUnitSetAnimationPath("3,0,0,0,0,0,0");
		trSetUnitOrientation(vector(-1,-1,-1),vector(0,0,0),true);
		xAddDatabaseBlock(dPlanetEyecandy, true);
		xSetInt(dPlanetEyecandy, xPlanetEyecandyName,temp);
		xSetInt(dPlanetEyecandy, xPlanetEyecandyStage, 7);
		temp = trGetNextUnitScenarioNameNumber();
		trArmyDispatch("0,0","Dwarf",1,8*2+84,0,35*2+10,270,true);
		trArmySelect("0,0");
		trUnitChangeProtoUnit("Spy Eye");
		trUnitSelectClear();
		trUnitSelect(""+temp, true);
		trMutateSelected(kbGetProtoUnitID("Hades Door"));
		trSetSelectedScale(0,0,0);
		trUnitOverrideAnimation(25,0,false,false,-1);
		trUnitSetAnimationPath("3,0,0,0,0,0,0");
		trSetUnitOrientation(vector(-1,-1,-1),vector(0,0,0),true);
		xAddDatabaseBlock(dPlanetEyecandy, true);
		xSetInt(dPlanetEyecandy, xPlanetEyecandyName,temp);
		xSetInt(dPlanetEyecandy, xPlanetEyecandyStage, 7);
		trUnitSetVariation(trQuestVarGet("QVRelic"), 0);
		xsEnableRule("Bonus_Display");
		subModeEnter("Simulation", "Editor");
		uiMessageBox("moo","restartCurrentGame()");
		uiCycleCurrentActivate();
		subModeLeave("Simulation", "Editor");
		modeEnter("pregame");
		modeEnter("Simulation");
	}
}

/*
rule Cine_02
inactive
highFrequency
{
	if((trTime()-cActivationTime) >= 2){
		xsDisableSelf();
		//xsEnableRule("Cine_Off");
	}
}
*/
