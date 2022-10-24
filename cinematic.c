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

void BuildNatasShip(int x = 0, int z = 0){
	xsSetContextPlayer(0);
	FloatingUnitAnimIdle("Wonder SPC", x*2+120, 9, z*2+20, 270, 1,1,1);
	trUnitSelectByQV("QVHero");
	trUnitSetAnimationPath("2,0,0,0,0,0,0");
	trUnitSelectByQV("QVRelic");
	trUnitSetAnimationPath("2,0,0,0,0,0,0");
	FloatingUnit("Migdol Stronghold", x*2+120, 9, z*2+20, 270, 1.5,1,1.5);
	FloatingUnit("Migdol Stronghold", x*2+120, 15, z*2+20, 90, 1,1,1.5);
	FloatingUnitAnimIdle("Cinematic Wake", x*2+120, 12, z*2+20, 90, 1,1,1);
	FloatingUnit("Columns Fallen", x*2+126, 12, z*2+16, 90, 3,2,3);
	trUnitSelectByQV("QVHero");
	trUnitSetAnimationPath("3,0,0,0,0,0,0");
	trUnitSelectByQV("QVRelic");
	trUnitSetAnimationPath("3,0,0,0,0,0,0");
	FloatingUnit("Columns Fallen", x*2+126, 12, z*2+24, 90, 3,2,3);
	trUnitSelectByQV("QVHero");
	trUnitSetAnimationPath("3,0,0,0,0,0,0");
	trUnitSelectByQV("QVRelic");
	trUnitSetAnimationPath("3,0,0,0,0,0,0");
	FloatingUnit("Hades Fire", x*2+130, 12, z*2+24, 90, 1,1,1);
	trUnitSelectByQV("QVHero");
	trSetUnitOrientation(xsVectorSet(0,0.0,0.0), xsVectorSet(1,0,0.0), true);
	trUnitSelectByQV("QVRelic");
	trSetUnitOrientation(xsVectorSet(0,0.0,0.0), xsVectorSet(1,0,0.0), true);
	FloatingUnit("Hades Fire", x*2+130, 12, z*2+16, 90, 1,1,1);
	trUnitSelectByQV("QVHero");
	trSetUnitOrientation(xsVectorSet(0,0.0,0.0), xsVectorSet(1,0,0.0), true);
	trUnitSelectByQV("QVRelic");
	trSetUnitOrientation(xsVectorSet(0,0.0,0.0), xsVectorSet(1,0,0.0), true);
	FloatingUnit("Columns", x*2+125, 21.5, z*2+20, 90, 1,1,1);
	FloatingUnit("Columns", x*2+125, 21.5, z*2+22, 90, 1,1,1);
	FloatingUnit("Columns", x*2+125, 21.5, z*2+18, 90, 1,1,1);
	FloatingUnit("Columns", x*2+124, 21.5, z*2+17, 0, 1,1,1);
	FloatingUnit("Columns", x*2+122, 21.5, z*2+17, 0, 1,1,1);
	FloatingUnit("Columns", x*2+120, 21.5, z*2+17, 0, 1,1,1);
	FloatingUnit("Columns", x*2+118, 21.5, z*2+17, 0, 1,1,1);
	FloatingUnit("Columns", x*2+116, 21.5, z*2+17, 0, 1,1,1);
	FloatingUnit("Columns", x*2+115, 21.5, z*2+18, 90, 1,1,1);
	FloatingUnit("Columns", x*2+115, 21.5, z*2+20, 90, 1,1,1);
	FloatingUnit("Columns", x*2+115, 21.5, z*2+22, 90, 1,1,1);
	FloatingUnit("Columns", x*2+124, 21.5, z*2+23, 0, 1,1,1);
	FloatingUnit("Columns", x*2+122, 21.5, z*2+23, 0, 1,1,1);
	FloatingUnit("Columns", x*2+120, 21.5, z*2+23, 0, 1,1,1);
	FloatingUnit("Columns", x*2+118, 21.5, z*2+23, 0, 1,1,1);
	FloatingUnit("Columns", x*2+116, 21.5, z*2+23, 0, 1,1,1);
	FloatingUnitAnimIdle("Pyramid Osiris Xpack", x*2+120, 25.5, z*2+20, 270, 0.3,0.3,0.4);
	//END
}

rule CineSetup
inactive
highFrequency
{
	xsDisableSelf();
	trRenderSky(false, "SkyBlue");
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
		trFadeOutMusic(3);
		trFadeOutAllSounds(3);
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
		characterDialog("Mr Natas", "Host this map in multiplayer to drill for minerals.", "icons\scenario g gargarensis icon 64");
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
		//xsEnableRule("Natas_Cine_Off");
	}
}
*/

rule Natas_Cine_01
inactive
highFrequency
{
	trOverlayTextColour(255,125,0);
	trOverlayText("Loading...", 3.0, 600, 450, 1000);
	xsDisableSelf();
	xsEnableRule("Natas_Cine_02");
	trFadeOutMusic(3);
	trFadeOutAllSounds(3);
	unitTransform("Valkyrie", "Rocket");
}

rule Natas_Cine_02
inactive
highFrequency
{
	int remain = 0;
	remain = xGetDatabaseCount(dHeldRelics)+xGetDatabaseCount(dHiddenRelics)+xGetDatabaseCount(dFreeRelics);
	for (x=xGetDatabaseCount(dHeldRelics); > 0) {
		xDatabaseNext(dHeldRelics);
		xUnitSelect(dHeldRelics, xRelicName);
		trUnitDestroy();
		xFreeDatabaseBlock(dHeldRelics);
	}
	for (x=xGetDatabaseCount(dHiddenRelics); > 0) {
		xDatabaseNext(dHiddenRelics);
		xUnitSelect(dHiddenRelics, xRelicName);
		trUnitDestroy();
		xFreeDatabaseBlock(dHiddenRelics);
	}
	for (x=xGetDatabaseCount(dFreeRelics); > 0) {
		xDatabaseNext(dFreeRelics);
		xUnitSelect(dFreeRelics, xRelicName);
		trUnitDestroy();
		xFreeDatabaseBlock(dFreeRelics);
	}
	for (x=xGetDatabaseCount(dTrap); > 0) {
		xDatabaseNext(dTrap);
		xFreeDatabaseBlock(dFreeRelics);
	}
	for(p=1; < cNumberNonGaiaPlayers) {
		trUnitSelectClear();
		xUnitSelect(dPlayerData, xSpySiphonID);
		trMutateSelected(kbGetProtoUnitID("Fire Siphon"));
		trUnitSelectByQV("P"+p+"Siphon");
		trUnitChangeProtoUnit("Cinematic Block");
		trUnitSelectByQV("P"+p+"Siphon");
		trUnitTeleport(1,1,1);
	}
	unitTransform("Garrison Flag Sky Passage", "Cinematic Block");
	unitTransform("Tartarian Gate", "Cinematic Block");
	unitTransform("Sentinel Base", "Cinematic Block");
	xsEnableRule("Natas_Cine_3");
	if(remain == 2){
		//bonus 21
		for(p=1; < cNumberNonGaiaPlayers) {
			xSetPointer(dPlayerData, p);
			xSetInt(dPlayerData, xBonus+21, 1);
		}
		ColouredIconChat("1,0.5,0", "icons\special e son of osiris icon 64","Bonus unlocked! (21)");
		characterDialog("Bonus Unlocked!", "(21)", "icons\special e son of osiris icon 64");
		playSoundCustom("cinematics\10_in\clearedcity.wav", "\Yeebaagooon\Motherload\UnlockBonus.mp3");
	}
	trPaintTerrain(53,36,79,48,0,73,true);
	//Area behind Natas for gate
	int temp = 0;
	for(x = 53 ; <= 80){
		for(z = 40; <= 48){
			if((trGetTerrainSubType(x,z) == 73) && (trGetTerrainType(x,z) == 0)){
				temp = trGetNextUnitScenarioNameNumber();
				trArmyDispatch("0,2", "Dwarf", 1, x*2,3,z*2, 0, true);
				trUnitSelectClear();
				trUnitSelect(""+temp);
				trUnitChangeProtoUnit("Hoplite");
				trUnitSelectClear();
				trUnitSelect(""+temp);
				trSetSelectedScale(2,2,2);
			}
		}
	}
	trQuestVarSet("MrNatasGate", trGetNextUnitScenarioNameNumber());
	trArmyDispatch("0,0", "Dwarf", 1,134,0,80,0,true);
	trUnitSelectClear();
	trUnitSelectByQV("MrNatasGate");
	trUnitChangeProtoUnit("Gate");
	trUnitSelectByQV("MrNatasGate");
	trSetSelectedScale(2,2,2);
	trUnitSelectByQV("MrNatasGate");
	trUnitSetAnimationPath("3,4,0,0,0,0");
	trPaintTerrain(0,60,100,100,5,4,false);
	BuildNatasShip(0,70);
	xsDisableSelf();
	trModifyProtounit("Lampades", 0, 1, 8);
	int a = trGetNextUnitScenarioNameNumber();
	BronzeNumber = a;
	for(b = 1; < 5){
		a = trGetNextUnitScenarioNameNumber();
		trQuestVarSetFromRand("TempX", 20, 90);
		trQuestVarSetFromRand("TempZ", 160, 200);
		trArmyDispatch("0,0", "Dwarf", 1,1*trQuestVarGet("TempX"),0,1*trQuestVarGet("TempZ"),0,true);
		trUnitSelectClear();
		trUnitSelect(""+a);
		trUnitChangeProtoUnit("Lampades");
		trSetSelectedScale(0,0,0);
	}
	a = trGetNextUnitScenarioNameNumber();
	trArmyDispatch("0,0", "Dwarf", 1,124,0,80,0,true);
	trUnitSelectClear();
	trUnitSelect(""+a);
	trUnitChangeProtoUnit("Columns");
	trSetSelectedScale(2,3,2);
	a = trGetNextUnitScenarioNameNumber();
	trArmyDispatch("0,0", "Dwarf", 1,144,0,80,0,true);
	trUnitSelectClear();
	trUnitSelect(""+a);
	trUnitChangeProtoUnit("Columns");
	trSetSelectedScale(2,3,2);
	a = trGetNextUnitScenarioNameNumber();
	trArmyDispatch("0,0", "Dwarf", 1,114,0,80,0,true);
	trUnitSelectClear();
	trUnitSelect(""+a);
	trUnitChangeProtoUnit("Gate");
	trSetSelectedScale(2,2,2);
	trUnitSetAnimationPath("3,4,0,0,0,0");
	a = trGetNextUnitScenarioNameNumber();
	trArmyDispatch("0,0", "Dwarf", 1,154,0,80,0,true);
	trUnitSelectClear();
	trUnitSelect(""+a);
	trUnitChangeProtoUnit("Gate");
	trSetSelectedScale(2,2,2);
	trUnitSetAnimationPath("3,4,0,0,0,0");
	trTechInvokeGodPower(0, "Bronze", vector(128, 9.06, 90), vector(0,0,0));
}

rule Natas_Cine_3
inactive
highFrequency
{
	if((trTime()-cActivationTime) >= 2){
		xsDisableSelf();
		xsEnableRule("Natas_Cine_4");
		xsEnableRule("Natas_Cine_Cut1");
		trUIFadeToColor(0,0,0,1500,100,false);
		characterDialog(" ", " ", " ");
		createCameraTrack(8000);
		trCameraCut(vector(65.802376,54.842648,93.671890), vector(0.524368,-0.434423,0.732335), vector(0.252909,0.900709,0.353215), vector(0.813065,0.000000,-0.582173));
		addCameraTrackWaypoint();
		trCameraCut(vector(124.851067,54.842648,73.539864), vector(-0.008649,-0.434423,0.900667), vector(-0.004171,0.900709,0.434403), vector(0.999954,-0.000000,0.009602));
		addCameraTrackWaypoint();
		trCameraCut(vector(169.476303,54.842644,88.641670), vector(-0.399547,-0.434423,0.807241), vector(-0.192706,0.900709,0.389343), vector(0.896229,-0.000000,0.443592));
		addCameraTrackWaypoint();
		trCameraCut(vector(124.728424,20.102650,150.140289), vector(-0.256233,-0.327256,0.909532), vector(-0.088740,0.944936,0.314994), vector(0.962533,-0.000000,0.271164));
		addCameraTrackWaypoint();
		playCameraTrack();
		characterDialog("Mr Natas", "Ahahahaha!", "icons\scenario g gargarensis icon 64");
		playSound("xpack\xcinematics\7_in\music2.mp3");
		for(a = 1; < 10){
			BronzeNumber = BronzeNumber+1;
			trUnitSelectClear();
			trUnitSelect(""+BronzeNumber);
			trUnitMoveToPoint(190,0,xsVectorGetZ(kbGetBlockPosition(""+1*0)), -1, false);
		}
		unitTransform("Hoplite", "Statue of Automaton Base");
	}
}

rule Natas_Cine_4
inactive
highFrequency
{
	if((trTime()-cActivationTime) >= 3){
		xsDisableSelf();
		xsEnableRule("Natas_Cine_5");
		characterDialog("Mr Natas", "All those minerals you have been mining has made me a fortune.", "icons\scenario g gargarensis icon 64");
	}
}

rule Natas_Cine_Cut1
inactive
highFrequency
{
	if((trTime()-cActivationTime) >= 8){
		xsDisableSelf();
		createCameraTrack(8000);
		trCameraCut(vector(133.962296,11.083123,51.621403), vector(-0.042182,-0.137956,0.989540), vector(-0.005875,0.990438,0.137831), vector(0.999093,-0.000000,0.042589));
		addCameraTrackWaypoint();
		trCameraCut(vector(133.599854,11.083123,54.488567), vector(-0.041852,-0.185320,0.981787), vector(-0.007893,0.982678,0.185152), vector(0.999093,-0.000000,0.042589));
		addCameraTrackWaypoint();
		playCameraTrack();
		trUIFadeToColor(0,0,0,500,100,false);
	}
}

rule Natas_Cine_5
inactive
highFrequency
{
	if((trTime()-cActivationTime) >= 4){
		xsDisableSelf();
		xsEnableRule("Natas_Cine_6");
		characterDialog("Mr Natas", "So kind of you to also bring your ships to me.", "icons\scenario g gargarensis icon 64");
		trUnitSelectClear();
		trUnitSelectByQV("MrNatas");
		trUnitOverrideAnimation(25,8,false,false,-1,0);
	}
}

rule Natas_Cine_6
inactive
highFrequency
{
	if((trTime()-cActivationTime) >= 3){
		xsDisableSelf();
		xsEnableRule("Natas_Cine_7");
		characterDialog("Mr Natas", "It will be fun to break them down for parts.", "icons\scenario g gargarensis icon 64");
		trUnitSelectClear();
		trUnitSelectByQV("MrNatas");
	}
}

rule Natas_Cine_7
inactive
highFrequency
{
	if((trTime()-cActivationTime) >= 4){
		xsDisableSelf();
		xsEnableRule("Natas_Cine_8");
		characterDialog("Mr Natas", "With you still inside of course.", "icons\scenario g gargarensis icon 64");
		trUnitSelectByQV("MrNatas");
		trUnitOverrideAnimation(25,33,false,false,-1,0);
		playSound("cinematics\20_out\music.mp3");
	}
}

rule Natas_Cine_8
inactive
highFrequency
{
	if((trTime()-cActivationTime) >= 3){
		xsDisableSelf();
		xsEnableRule("Natas_Cine_9");
		characterDialog("SHIP PROXIMITY ALERT", " ", "world n brazier map");
		sunColor(255,0,0);
		trCameraShake(3,0.1);
		playSound("attackwarning.wav");
	}
}

rule Natas_Cine_9
inactive
highFrequency
{
	if((trTime()-cActivationTime) >= 2){
		xsDisableSelf();
		xsEnableRule("Natas_Cine_10");
		characterDialog("Mr Natas", "WHAT?", "icons\scenario g gargarensis icon 64");
		trUnitSelectByQV("MrNatas");
		trUnitOverrideAnimation(25,1,false,false,-1,0);
		trQuestVarSet("Dwarf", trGetNextUnitScenarioNameNumber());
		trArmyDispatch(""+cNumberNonGaiaPlayers+",0", "Dwarf", 1,114,0,180,0,true);
		spyEffect(1*trQuestVarGet("Dwarf"), kbGetProtoUnitID("Tower Mirror"), vector(0,0,0),vector(0,1.4,0));
		FloatingUnitAnimIdle("Vortex Landing", 114, 3, 178, 0,1,1,1,"0,0,0,0,0",2);
		playSound("cinematics\32_out\music.mp3");
	}
}

rule Natas_Cine_10
inactive
highFrequency
{
	if((trTime()-cActivationTime) >= 2){
		xsDisableSelf();
		xsEnableRule("Natas_Cine_11");
		characterDialog(" ", " ", "");
		trSetLighting("default", 0.1);
		trCameraCut(vector(66.338997,19.423120,160.450455), vector(0.976032,-0.149754,0.157910), vector(0.147831,0.988723,0.023917), vector(0.159712,-0.000000,-0.987164));
		trUnitSelectByQV("Dwarf");
		trUnitMoveToPoint(114,0,160, -1, false);
		trSetSelectedScale(0,0,0);
		playSound("meteorapproach.wav");
		trQuestVarSet("Yeeb", trGetNextUnitScenarioNameNumber());
		trArmyDispatch(""+cNumberNonGaiaPlayers+",0", "Dwarf", 1,132,3,55,0,true);
		//spyEffect(1*trQuestVarGet("Yeeb"), kbGetProtoUnitID("Phoenix Egg"), vector(0,0,0),vector(2,2,2));
	}
}

rule Natas_Cine_11
inactive
highFrequency
{
	if((trTime()-cActivationTime) >= 5){
		xsDisableSelf();
		xsEnableRule("Natas_Cine_12");
		createCameraTrack(10000);
		trCameraCut(vector(132.962524,26.306038,-4.607869), vector(0.002250,-0.346088,0.938199), vector(0.000830,0.938202,0.346087), vector(0.999997,-0.000000,-0.002398));
		addCameraTrackWaypoint();
		trCameraCut(vector(133.046265,26.306038,30.312029), vector(0.002093,-0.487652,0.873036), vector(0.001169,0.873038,0.487650), vector(0.999997,-0.000000,-0.002398));
		addCameraTrackWaypoint();
		playCameraTrack();
		trUnitSelectByQV("Yeeb");
		trUnitChangeProtoUnit("Pharaoh of Osiris XP");
		trUnitSelectByQV("Yeeb");
		trUnitMoveToPoint(132,3,70,-1,false);
		characterDialog("Yeebaagooon", "NATAS!", "icons\special e son of osiris icon 64");
	}
}

rule Natas_Cine_12
inactive
highFrequency
{
	if((trTime()-cActivationTime) >= 2){
		xsDisableSelf();
		xsEnableRule("Natas_Cine_13");
		characterDialog("Mr Natas", "Yeebaagooon!", "icons\scenario g gargarensis icon 64");
		trUnitSelectByQV("MrNatas");
		trUnitOverrideAnimation(25,12,false,false,-1,0);
	}
}

rule Natas_Cine_13
inactive
highFrequency
{
	if((trTime()-cActivationTime) >= 2){
		characterDialog("Yeebaagooon", "This is how you repay me? Besmirching the name of my company and thieving my money.", "icons\special e son of osiris icon 64");
		xsEnableRule("Natas_Cine_14");
		xsDisableSelf();
	}
}

rule Natas_Cine_14
inactive
highFrequency
{
	if((trTime()-cActivationTime) >= 5){
		characterDialog("Yeebaagooon", "I simply cannot allow this to continue.", "icons\special e son of osiris icon 64");
		xsEnableRule("Natas_Cine_15");
		xsDisableSelf();
	}
}

rule Natas_Cine_15
inactive
highFrequency
{
	if((trTime()-cActivationTime) >= 2){
		xsDisableSelf();
		xsEnableRule("Natas_Cine_16");
		characterDialog("Mr Natas", "And what are you going to do?", "icons\scenario g gargarensis icon 64");
		trUnitSelectByQV("MrNatas");
		trUnitOverrideAnimation(25,34,false,false,-1,0);
		createCameraTrack(3000);
		trCameraCut(vector(133.046265,26.306038,30.312029), vector(0.002093,-0.487652,0.873036), vector(0.001169,0.873038,0.487650), vector(0.999997,-0.000000,-0.002398));
		addCameraTrackWaypoint();
		trCameraCut(vector(133.599854,11.083123,54.488567), vector(-0.041852,-0.185320,0.981787), vector(-0.007893,0.982678,0.185152), vector(0.999093,-0.000000,0.042589));
		addCameraTrackWaypoint();
		playCameraTrack();
		//here
		trQuestVarSet("Temp", trGetNextUnitScenarioNameNumber());
		trChangeTerrainHeight(63,80,64,81,15,true);
		//trPaintTerrain(63,80,64,81,0,70,false);
		trArmyDispatch(""+cNumberNonGaiaPlayers+",0", "Dwarf", 1,130,3,156,120,true);
		trCameraCut(vector(147.439651,38.248768,142.507339), vector(-0.397862,-0.707107,0.584556), vector(-0.397862,0.707107,0.584556), vector(0.826687,0.000000,0.562662));
		trUnitSelectClear();
		trUnitSelect(""+1*trQuestVarGet("Temp"));
		trUnitChangeProtoUnit("Gargarensis");
		trUnitOverrideAnimation(25, 7, false,false, -1, 0);
		trUnitSelect(""+1*trQuestVarGet("Temp"));
		trUnitTeleport(128,3,161);
		trUnitSelect(""+1*trQuestVarGet("Temp"));
		trSetSelectedScale(0.3,0.3,0.3);
		trQuestVarSet("Timer2", trTimeMS()+13210);
	}
}

rule Natas_Cine_16
inactive
highFrequency
{
	if((trTime()-cActivationTime) >= 3){
		xsDisableSelf();
		characterDialog("Mr Natas", "AGAINST THE POWER OF SATAN", "icons\scenario g gargarensis icon 64");
		xsEnableRule("Natas_Cine_17");
		createCameraTrack(5000);
		trCameraCut(vector(133.599854,11.083123,54.488567), vector(-0.041852,-0.185320,0.981787), vector(-0.007893,0.982678,0.185152), vector(0.999093,-0.000000,0.042589));
		addCameraTrackWaypoint();
		trCameraCut(vector(133.046265,26.306038,30.312029), vector(0.002093,-0.487652,0.873036), vector(0.001169,0.873038,0.487650), vector(0.999997,-0.000000,-0.002398));
		addCameraTrackWaypoint();
		playCameraTrack();
	}
}

rule Natas_Cine_17
inactive
highFrequency
{
	if((trTime()-cActivationTime) >= 3){
		characterDialog("Yeebaagooon", "Please.", "icons\special e son of osiris icon 64");
		xsEnableRule("Natas_Cine_18");
		xsDisableSelf();
	}
}

rule Natas_Cine_18
inactive
highFrequency
{
	if((trTime()-cActivationTime) >= 2){
		characterDialog("Yeebaagooon", "You're embarassing yourself.", "icons\special e son of osiris icon 64");
		xsEnableRule("Natas_Cine_19");
		xsDisableSelf();
	}
}

rule Natas_Cine_19
inactive
highFrequency
{
	if((trTime()-cActivationTime) >= 3){
		characterDialog(" ", " ", "");
		xsEnableRule("Natas_Cine_20");
		xsDisableSelf();
		trUnitSelectByQV("Yeeb");
		trUnitOverrideAnimation(19,0,false,false,-1,0);
		trQuestVarSet("Timer1", trTimeMS()+1650);
	}
}

rule Natas_Cine_20
inactive
highFrequency
{
	if(trTimeMS() > 1*trQuestVarGet("Timer1")){
		xsDisableSelf();
		xsEnableRule("Natas_Cine_21");
		characterDialog("Mr Natas", "Noooooooooo!", "icons\scenario g gargarensis icon 64");
		trUnitSelectByQV("MrNatas");
		trUnitOverrideAnimation(25,35,false,false,-1,0);
	}
}

rule Natas_Cine_21
inactive
highFrequency
{
	if(trTimeMS() > 1*trQuestVarGet("Timer2")){
		xsDisableSelf();
		xsEnableRule("Natas_Cine_22");
		characterDialog("Mr Natas", "Blargh!", "icons\scenario g gargarensis icon 64");
		playSound("gargarensisdie.wav");
		trCameraCut(vector(147.439651,38.248768,142.507339), vector(-0.397862,-0.707107,0.584556), vector(-0.397862,0.707107,0.584556), vector(0.826687,0.000000,0.562662));
	}
}

rule Natas_Cine_22
inactive
highFrequency
{
	if((trTime()-cActivationTime) >= 1){
		xsDisableSelf();
		trUnitSelectByQV("MrNatas");
		trUnitDestroy();
		trUnitSelectByQV("Temp");
		trUnitDestroy();
		trUnitSelectByQV("Yeeb");
		trUnitDestroy();
		xsEnableRule("Natas_Cine_23");
		trFadeOutMusic(3);
		trFadeOutAllSounds(3);
		trQuestVarSet("Yeeb", trGetNextUnitScenarioNameNumber());
		trArmyDispatch(""+cNumberNonGaiaPlayers+",0", "Dwarf", 1,132,0,70,180,true);
		trUnitSelectClear();
		trUnitSelectByQV("Yeeb");
		trUnitChangeProtoUnit("Pharaoh of Osiris XP");
	}
}

rule Natas_Cine_23
inactive
highFrequency
{
	if((trTime()-cActivationTime) >= 2){
		xsDisableSelf();
		xsEnableRule("Natas_Cine_24");
		trCameraCut(vector(133.222977,9.386039,53.951668), vector(0.002277,-0.313046,0.949735), vector(0.000750,0.949738,0.313044), vector(0.999997,-0.000000,-0.002398));
		characterDialog("Yeebaagooon", "Miners, I apologise for making your supervisor actual Satan.", "icons\special e son of osiris icon 64");
		trSetLighting("default", 0.1);
		playSound("cinematics\29_in\music2.mp3");
	}
}

rule Natas_Cine_24
inactive
highFrequency
{
	if((trTime()-cActivationTime) >= 4){
		xsDisableSelf();
		xsEnableRule("Natas_Cine_25");
		trSetLighting("Dawn", 15);
		characterDialog("Yeebaagooon", "I am an equal opportunity employer you see.", "icons\special e son of osiris icon 64");
		trQuestVarSet("MrNatasGate2", trGetNextUnitScenarioNameNumber());
		trArmyDispatch("0,0", "Dwarf", 1,134,0,94,0,true);
		trUnitSelectClear();
		trUnitSelectByQV("MrNatasGate2");
		trUnitChangeProtoUnit("Gate");
		trUnitSelectByQV("MrNatasGate2");
		trSetSelectedScale(2,2,2);
		trUnitSelectByQV("MrNatasGate2");
		trUnitSetAnimationPath("3,4,0,0,0,0");
		trUnitSelectByQV("MrNatasGate2");
		trUnitTeleport(134,3,94);
	}
}

rule Natas_Cine_25
inactive
highFrequency
{
	if((trTime()-cActivationTime) >= 4){
		xsDisableSelf();
		xsEnableRule("Natas_Cine_26");
		characterDialog("Yeebaagooon", "Regardless we have both been stolen from.", "icons\special e son of osiris icon 64");
		createCameraTrack(3500);
		trCameraCut(vector(133.222977,9.386039,53.951668), vector(0.002277,-0.313046,0.949735), vector(0.000750,0.949738,0.313044), vector(0.999997,-0.000000,-0.002398));
		addCameraTrackWaypoint();
		trCameraCut(vector(133.250748,9.386039,65.531639), vector(0.002372,-0.143897,0.989590), vector(0.000345,0.989593,0.143896), vector(0.999997,-0.000000,-0.002398));
		addCameraTrackWaypoint();
		playCameraTrack();
	}
}

rule Natas_Cine_26
inactive
highFrequency
{
	if((trTime()-cActivationTime) >= 4){
		xsDisableSelf();
		xsEnableRule("Natas_Cine_27");
		characterDialog("Yeebaagooon", "So I feel it is only right you take what Mr Natas was hoarding.", "icons\special e son of osiris icon 64");
		BronzeNumber = trGetNextUnitScenarioNameNumber();
		trArmyDispatch("0,2", "Dwarf", 1,11,11,11,0,true);
	}
}

rule Natas_Cine_27
inactive
highFrequency
{
	if((trTime()-cActivationTime) >= 4){
		xsDisableSelf();
		xsEnableRule("Natas_Cine_28");
		characterDialog("Yeebaagooon", "Behold, The Motherload.", "icons\special e son of osiris icon 64");
		trFadeOutMusic(0.1);
		trFadeOutAllSounds(0.1);
		playSound("cinematics\35_out\music2.mp3");
		trUnitSelectByQV("MrNatasGate");
		trUnitOverrideAnimation(41,0,true,true,-1,0);
		createCameraTrack(3500);
		trCameraCut(vector(133.232895,13.346039,58.091667), vector(0.002328,-0.239060,0.971002), vector(0.000573,0.971005,0.239059), vector(0.999997,-0.000000,-0.002398));
		addCameraTrackWaypoint();
		trCameraCut(vector(133.250748,9.386039,65.531639), vector(0.002372,-0.143897,0.989590), vector(0.000345,0.989593,0.143896), vector(0.999997,-0.000000,-0.002398));
		addCameraTrackWaypoint();
		playCameraTrack();
		//Motherload
		spawnRelicSpecific(vector(136,3,92), 21);
		spawnRelicSpecific(vector(136,3,90), 21);
		spawnRelicSpecific(vector(132,3,90), 21);
		spawnRelicSpecific(vector(132,3,92), 21);
		spawnRelicSpecific(vector(128,3,90), 21);
		spawnRelicSpecific(vector(128,3,92), 21);
		trUnitSelectClear();
		trUnitSelect(""+BronzeNumber);
		trMutateSelected(kbGetProtoUnitID("Plenty Vault"));
		trUnitSelectClear();
		trUnitSelect(""+BronzeNumber);
		trSetSelectedScale(1,-1,1);
		trUnitSelectClear();
		trUnitSelect(""+BronzeNumber);
		trUnitTeleport(134,3,92);
	}
}

rule Natas_Cine_28
inactive
highFrequency
{
	if((trTime()-cActivationTime) >= 3){
		xsDisableSelf();
		xsEnableRule("Natas_Cine_29");
		characterDialog(" ", " ", "");
	}
}

rule Natas_Cine_29
inactive
highFrequency
{
	if((trTime()-cActivationTime) >= 3){
		xsDisableSelf();
		xsEnableRule("Natas_Cine_30");
		trUIFadeToColor(0,0,0,1500,1,true);
	}
}

rule Natas_Cine_30
inactive
highFrequency
{
	if((trTime()-cActivationTime) >= 2){
		xsDisableSelf();
		xsEnableRule("Natas_Cine_31");
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
		int p = trCurrentPlayer();
		xSetPointer(dPlayerData, p);
		if (xGetInt(dPlayerData, xStageUnlocked) >= Stage-1) {
			trShowImageDialog(stageIcon(Stage), "Stage complete!");
		}
		else{
			trShowImageDialog(stageIcon(Stage), "Unlock this stage first to claim further rewards!");
		}
	}
}

rule Natas_Cine_31
inactive
highFrequency
{
	if((trTime()-cActivationTime) >= 3){
		xsDisableSelf();
		xsEnableRule("Natas_Cine_32");
		int p = trCurrentPlayer();
		xSetPointer(dPlayerData, p);
		if (xGetInt(dPlayerData, xStageUnlocked) >= Stage-1) {
			relicDescription(21);
			playSoundCustom("tributereceived.wav", "\Yeebaagooon\Motherload\Sell.mp3");
			xSetInt(dPlayerData, xGold, xGetInt(dPlayerData, xGold)+1000);
		}
		else{
			trShowImageDialog(stageIcon(Stage), "Unlock this stage first to claim further rewards!");
		}
	}
}

rule Natas_Cine_32
inactive
highFrequency
{
	if((trTime()-cActivationTime) >= 3){
		xsDisableSelf();
		xsEnableRule("End1");
		gadgetUnreal("ShowImageBox");
		gadgetReal("ShowImageBox-BordersTop");
		gadgetReal("ShowImageBox-BordersBottom");
		gadgetReal("ShowImageBox-BordersLeft");
		gadgetReal("ShowImageBox-BordersRight");
		gadgetReal("ShowImageBox-BordersLeftTop");
		gadgetReal("ShowImageBox-BordersLeftBottom");
		gadgetReal("ShowImageBox-BordersRightBottom");
		gadgetReal("ShowImageBox-BordersRightTop");
		gadgetReal("ShowImageBox-CloseButton");
		int p = trCurrentPlayer();
		xSetPointer(dPlayerData, p);
		trQuestVarSet("Profit", xGetInt(dPlayerData, xGold)-xGetInt(dPlayerData, xGoldStart));
		characterDialog(stageName(Stage) + " complete!", "You have made " +1*trQuestVarGet("Profit") + " gold profit here.", "icons\special e son of osiris icon 64");
		saveAllData();
	}
}

rule Natas_Cine_Off
inactive
highFrequency
{
	if((trTime()-cActivationTime) >= 2){
		xsDisableSelf();
		trLetterBox(false);
	}
}
//anoterher gate 14 back

rule Win_Cine_Off
inactive
highFrequency
{
	if((trTime()-cActivationTime) >= 5){
		xsDisableSelf();
		trLetterBox(false);
		createCameraTrack(50000);
		trCameraCut(vector(62.603432,140.663559,106.860794), vector(0.000019,-0.999990,0.004398), vector(0.004397,0.004397,0.999981), vector(0.999990,0.000000,-0.004398));
		addCameraTrackWaypoint();
		trCameraCut(vector(62.603432,140.663559,106.860794), vector(0.000019,-0.999990,0.004398), vector(0.004397,0.004397,0.999981), vector(0.999990,0.000000,-0.004398));
		addCameraTrackWaypoint();
		modeEnter("Campaign");
		modeEnter("Pregame");
	}
}

rule Win_Cine_Start
inactive
highFrequency
{
	xsDisableSelf();
	trUnitSelectByQV("ExitYeeb");
	trUnitChangeProtoUnit("Cinematic Block");
	trPlayerSetDiplomacy(0,1,"Enemy");
	trLetterBox(true);
	trRenderSky(false, "SkyBlue");
	trArmyDispatch("1,0", "Victory Marker", 1, 1,0,199,0,false);
	trSetFogAndBlackmap(false, false);
	createCameraTrack(5000);
	trCameraCut(vector(69.173103,9.863888,42.203957), vector(0.018607,-0.282499,0.959087), vector(0.005480,0.959267,0.282446), vector(0.999812,0.000000,-0.019397));
	addCameraTrackWaypoint();
	trCameraCut(vector(69.173103,34.543886,42.203957), vector(0.018607,-0.282499,0.959087), vector(0.005480,0.959267,0.282446), vector(0.999812,0.000000,-0.019397));
	addCameraTrackWaypoint();
	playCameraTrack();
	xsEnableRule("Win_Cine_01");
	for(x=xGetDatabaseCount(dObelisks); >0) {
		xDatabaseNext(dObelisks);
		xUnitSelect(dObelisks,xObeliskName);
		trUnitDestroy();
		xFreeDatabaseBlock(dObelisks);
	}
	aiPlanDestroy(dObelisks);
	for(x=xGetDatabaseCount(dPlanetEyecandy); >0) {
		xDatabaseNext(dPlanetEyecandy);
		xUnitSelect(dPlanetEyecandy,xPlanetEyecandyName);
		trUnitDestroy();
		xFreeDatabaseBlock(dPlanetEyecandy);
	}
	aiPlanDestroy(dPlanetEyecandy);
	trPaintTerrain(0,31,200,200,5,4,false);
}

rule Win_Cine_01
inactive
highFrequency
{
	if((trTime()-cActivationTime) >= 5){
		xsDisableSelf();
		xsEnableRule("Win_Cine_02");
		trOverlayTextColour(255,125,0);
		trOverlayText("Map Complete!", 3.0, 550, 450, 1000);
		FloatingUnitAnimIdle("Guardian XP", xsVectorGetX(kbGetBlockPosition(""+1*trQuestVarGet("CompletionObelisk")))-1, 23.1, xsVectorGetZ(kbGetBlockPosition(""+1*trQuestVarGet("CompletionObelisk")))-1, 180, 0,0,0);
		FloatingUnitAnimIdle("Healing SFX", xsVectorGetX(kbGetBlockPosition(""+1*trQuestVarGet("CompletionObelisk")))-1, 27.1, xsVectorGetZ(kbGetBlockPosition(""+1*trQuestVarGet("CompletionObelisk")))-1, 180, 0,0,0);
		trUnitSelectByQV("CompletionObelisk");
		trUnitSetAnimationPath("0,0,0,0,0");
		playSoundCustom("ageadvance.wav", "\Yeebaagooon\Motherload\UnlockBonus.mp3");
	}
}

rule Win_Cine_02
inactive
highFrequency
{
	if((trTime()-cActivationTime) >= 3){
		xsDisableSelf();
		xsEnableRule("Win_Cine_03");
		characterDialog("Coordinates received", "Preparing for imminent launch...", "icons\special e son of osiris icon 64");
	}
}

rule Win_Cine_03
inactive
highFrequency
{
	if((trTime()-cActivationTime) >= 3){
		xsDisableSelf();
		trCameraCut(vector(68.745613,147.463852,-83.793297), vector(0.000866,-0.784816,0.619729), vector(0.001097,0.619729,0.784815), vector(0.999999,-0.000000,-0.001398));
		characterDialog(" ", " ", "");
		xsEnableRule("ExitAnim");
		trUnitSelectByQV("ExitYeeb");
		trUnitChangeProtoUnit("Underworld Smoke");
		FloatingUnit("Fire Siphon", 68, 3, 7, 0,1,1,1);
		trQuestVarSet("Flight", 3);
		trQuestVarSet("FUnit", 1*trQuestVarGet("QVHero"));
		trUnitSelectByQV("QVHero");
		trSetUnitOrientation(xsVectorSet(trQuestVarGet("tempCosH"),90,trQuestVarGet("tempSinH")),xsVectorSet(trQuestVarGet("tempSinT")*trQuestVarGet("tempSinH"),
				trQuestVarGet("tempCosT"),0.0-trQuestVarGet("tempSinT")*trQuestVarGet("tempCosH")),true);
		trUnitSelectByQV("MainSiphon");
		trUnitChangeProtoUnit("Rocket");
		FloatingUnitAnimIdle("Implode Sphere Effect", 68, 3, 7, 0,10,10,10,"0,0,0,0,0",2);
		trQuestVarSet("FObject1", 1*trQuestVarGet("QVHero"));
		for (x=2 ; < 15){
			FloatingUnitAnimIdle("Vortex Finish Linked", 68, 3, 7, 0,1,1,1,"0,0,0,0,0",2);
			trQuestVarSet("FObject"+x+"", 1*trQuestVarGet("QVHero"));
		}
		FloatingUnit("Columns", 68, -1, 7, 0,2,2,2);
		trQuestVarSet("FObjectCol", 1*trQuestVarGet("QVHero"));
		int temp = trGetNextUnitScenarioNameNumber();
		UnitCreate(0, "Tartarian Gate", 68,7,0);
		trUnitSelectClear();
		trUnitSelect(""+temp);
		trUnitTeleport(68,3,7);
		trUnitSelectClear();
		trUnitSelect(""+temp);
		trUnitOverrideAnimation(18,0,false,false,-1,-1);
		trUnitSelectClear();
		trUnitSelect(""+temp);
		trSetSelectedScale(0,0,0);
		trUIFadeToColor(255,255,255,500,2500,true);
		trCameraShake(5,0.3);
		playSound("tartarianopen2.wav");
		playSound("meteorwhoosh.wav");
		playSound("meteordustcloud.wav");
		playSound("lightthunder.wav");
		playSound("lightningbirth.wav");
		xsEnableRule("Win_Cine_04");
		trUnitSelectByQV("CompletionFlag1");
		trUnitDestroy();
		trUnitSelectByQV("CompletionFlag2");
		trUnitDestroy();
		trUnitSelectByQV("CompletionObelisk");
		trUnitDestroy();
	}
}


rule Win_Cine_04
inactive
highFrequency
{
	if((trTime()-cActivationTime) >= 4){
		xsDisableSelf();
		createCameraTrack(10000);
		trCameraCut(vector(70.296402,17.280727,44.553116), vector(-0.014243,-0.408125,0.912815), vector(-0.006367,0.912926,0.408075), vector(0.999878,0.000000,0.015601));
		addCameraTrackWaypoint();
		trCameraCut(vector(69.998711,13.440729,63.630783), vector(-0.015515,-0.105204,0.994330), vector(-0.001641,0.994451,0.105191), vector(0.999878,0.000000,0.015601));
		addCameraTrackWaypoint();
		playCameraTrack();
		trUIFadeToColor(255,255,255,1500,300,false);
		FloatingUnit("Fire Siphon", 68, 6.5, 73, 0,1,1,1);
		trQuestVarSet("FUnit", 1*trQuestVarGet("QVHero"));
		FloatingUnit("Columns Fallen", 68, 5, 70, 0,2,2,2);
		trQuestVarSet("FObjectCol", 1*trQuestVarGet("QVHero"));
		FloatingUnit("Fire Hades", 68, 5, 68, 0,0.5,0.5,0.5);
		trUnitSelectByQV("QVHero");
		trSetUnitOrientation(xsVectorSet(0,0.0,0.0), xsVectorSet(0,0,-1), true);
		trUnitSelectByQV("QVRelic");
		trSetUnitOrientation(xsVectorSet(0,0.0,0.0), xsVectorSet(0,0,-1), true);
		trQuestVarSet("FObject1", 1*trQuestVarGet("QVHero"));
		xsEnableRule("Win_Cine_05");
		FloatingUnitAnimIdle("Stalagtite", 68, 5, 0, 140,2,-2,2);
		FloatingUnitAnimIdle("Healing SFX", 68, 8, 140, 0,10,10,10,"0,0,0,0,0",2);
		FloatingUnitAnimIdle("Valkyrie", 68, 8, 140, 0,0,0,0,"0,0,0,0,0",2);
		FloatingUnitAnimIdle("Vortex Landing", 68, 4, 140, 0,1,1,1);
		FloatingUnit("Shrine", 68, 8, 140, 0,0.4,0.4,0.4);
		FloatingUnit("Rock Granite Big", 68, 8, 140, 0, 2,-2,2);
		FloatingUnit("Rock Granite Big", 66, 8, 140, 90, 1,1,1);
		FloatingUnit("Rock Granite Big", 70, 8, 140, 90, 1,1,1);
		xsDisableRule("ExitAnim");
		trQuestVarSet("Flight", 0);
		trUnitSelectByQV("FUnit");
		trUnitMoveToPoint(68, 6.5, 163, -1, false);
		trUnitSelectByQV("FObjectCol");
		trUnitMoveToPoint(68,5,160, -1, false);
		trUnitSelectByQV("FObject1");
		trUnitMoveToPoint(68,5,158, -1, false);
		modifyProtounitAbsolute("Wadjet Spit", 0, 1, 4);
		for(n=1 ; <= 150){
			trQuestVarSetFromRand("TempX", 30, 90, false);
			trQuestVarSetFromRand("TempZ", 100, 199, false);
			trQuestVarSet("TempUnit", trGetNextUnitScenarioNameNumber());
			trArmyDispatch("0,0", "Victory Marker", 1, 1*trQuestVarGet("TempX"),0,1*trQuestVarGet("TempZ"),0,false);
			trUnitSelectByQV("TempUnit");
			trUnitChangeProtoUnit("Armor Glow Small");
			xAddDatabaseBlock(dSpace, true);
			xSetInt(dSpace, xSpaceName,1*trQuestVarGet("TempUnit"));
		}
		for(n=1 ; <= 20){
			trQuestVarSetFromRand("TempX", 30, 90, false);
			trQuestVarSetFromRand("TempZ", 100, 199, false);
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
			trQuestVarSetFromRand("TempX", 30, 90, false);
			trQuestVarSetFromRand("TempZ", 100, 199, false);
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
			trQuestVarSetFromRand("TempX", 30, 90, false);
			trQuestVarSetFromRand("TempZ", 100, 199, false);
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
}

rule Win_Cine_05
inactive
highFrequency
{
	if((trTime()-cActivationTime) >= 10){
		xsDisableSelf();
		xsEnableRule("Win_Cine_06");
		trUIFadeToColor(255,255,255,2000,700,true);
		if(1*trQuestVarGet("CustomContent") == 1){
			trFadeOutMusic(2);
			trFadeOutAllSounds(2);
			playSound("\Yeebaagooon\Motherload\WinTrack.mp3");
		}
	}
}

rule Win_Cine_06
inactive
highFrequency
{
	if((trTime()-cActivationTime) >= 3){
		xsDisableSelf();
		xsEnableRule("Win_Cine_07");
		trUIFadeToColor(255,255,255,2000,700,false);
		createCameraTrack(8000);
		trCameraCut(vector(151.447128,34.612152,79.050674), vector(0.002389,-0.087287,0.996180), vector(0.000209,0.996183,0.087287), vector(0.999997,-0.000000,-0.002398));
		addCameraTrackWaypoint();
		trCameraCut(vector(151.447128,9.532150,79.050674), vector(0.002389,-0.087287,0.996180), vector(0.000209,0.996183,0.087287), vector(0.999997,-0.000000,-0.002398));
		addCameraTrackWaypoint();
		playCameraTrack();
		for(x=xGetDatabaseCount(dSpace); >0) {
			xDatabaseNext(dSpace);
			xUnitSelect(dSpace,xSpaceName);
			trUnitDestroy();
		}
		aiPlanDestroy(dSpace);
	}
}

void BuildYeebCol(int x = 0, int z = 0, int y = 0){
	FloatingUnit("Wall Connector", x, 3, z, 0,1,2,1);
	trUnitSelectByQV("QVRelic");
	trUnitSetAnimationPath("0,2,0,0,0,0");
	FloatingUnit("Wall Connector", x, 11, z, 0,1,2,1);
	trUnitSelectByQV("QVRelic");
	trUnitSetAnimationPath("0,2,0,0,0,0");
	FloatingUnit("Wall Connector", x, 3, z-2, 0,1,1,1);
	trUnitSelectByQV("QVRelic");
	trUnitSetAnimationPath("0,2,0,0,0,0");
	FloatingUnit("Wall Connector", x, 3, z+2, 0,1,1,1);
	trUnitSelectByQV("QVRelic");
	trUnitSetAnimationPath("0,2,0,0,0,0");
	FloatingUnit("Wall Connector", x+2, 3, z, 0,1,1,1);
	trUnitSelectByQV("QVRelic");
	trUnitSetAnimationPath("0,2,0,0,0,0");
	FloatingUnit("Wall Connector", x-2, 3, z, 0,1,1,1);
	trUnitSelectByQV("QVRelic");
	trUnitSetAnimationPath("0,2,0,0,0,0");
	FloatingUnit("Monument", x-2, 7, z, 270,1,1,1);
	FloatingUnit("Monument", x+2, 7, z, 90,1,1,1);
	FloatingUnit("Monument", x, 7, z+2, 0,1,1,1);
	FloatingUnit("Monument", x, 7, z-2, 180,1,1,1);
	FloatingUnit("Flag", x, 19, z, 90,1,1,4);
	trUnitSelectByQV("QVRelic");
	trUnitSetAnimationPath("0,0,0,0,0,0");
	trUnitSelectByQV("QVRelic");
	if(y == 0){
		trSetSelectedUpVector(1,1,0);
	}
	else{
		trSetSelectedUpVector(-1,1,0);
	}
	if(y == 0){
		FloatingUnit("Flag", x+2, 19, z, 90,1,-1,1);
	}
	else{
		FloatingUnit("Flag", x-1.6, 19, z, 90,1,-1,1);
	}
	trUnitSelectByQV("QVRelic");
	trUnitSetAnimationPath("0,1,0,0,0,0");
	trUnitSelectByQV("QVRelic");
	FloatingUnitAnimIdle("Plenty Vault", x, 3, z, 0,0.6,-1,0.6);
}

rule Win_Cine_07
inactive
highFrequency
{
	if((trTime()-cActivationTime) >= 1){
		trSetObscuredUnits(false);
		int temp = trGetNextUnitScenarioNameNumber();
		xsDisableSelf();
		xsEnableRule("Win_Cine_08");
		for(x = 30 ; < 46){
			for(z = 26 ; < 50){
				temp = trGetNextUnitScenarioNameNumber();
				UnitCreate(0, "Dwarf", x*4, z*4, 0);
				trUnitSelectClear();
				trUnitSelect(""+temp);
				trUnitChangeProtoUnit("Spy Eye");
				trUnitSelectClear();
				trUnitSelect(""+temp);
				trMutateSelected(kbGetProtoUnitID("Wall Connector"));
				trUnitSetAnimationPath("0,1,0,0,0,0,0");
				trSetSelectedScale(2,0.01,2);
			}
		}
		trPlayerSetDiplomacy(0, 1, "Ally");
		BuildYeebCol(160,130,1);
		BuildYeebCol(160,110,1);
		BuildYeebCol(140,110,0);
		BuildYeebCol(140,130,0);
		BuildYeebCol(140,150,0);
		BuildYeebCol(160,150,1);
		BuildYeebCol(140,170,0);
		BuildYeebCol(160,170,1);
		BuildYeebCol(140,190,0);
		BuildYeebCol(160,190,1);
		trPaintTerrain(60,52,90,100,0,53, false);
		trPaintTerrain(70,52,80,100,0,73, false);
		temp = trGetNextUnitScenarioNameNumber();
		for(x = 0 ; < 7){
			UnitCreate(1, "Underworld Passage SPC", 120+x*10, 199, 0);
			trUnitSelectClear();
			trUnitSelect(""+(temp+x));
			trSetSelectedUpVector(0,3,0);
			trSetSelectedScale(2,1,1);
			trUnitSelectClear();
			trUnitSelect(""+(temp+x));
			trUnitSetAnimationPath("2,0,0,0,0,0,0");
		}
		UnitCreate(0, "Pharaoh of Osiris XP", 150, 190, 180);
		temp = trGetNextUnitScenarioNameNumber();
		for(x = 0 ; < 9){
			UnitCreate(1, "Underworld Passage SPC", 120, 109+x*10, 90);
			trUnitSelectClear();
			trUnitSelect(""+(temp+x));
			trSetSelectedUpVector(0,3,0);
			trSetSelectedScale(2,1,1);
			trUnitSelectClear();
			trUnitSelect(""+(temp+x));
			trUnitSetAnimationPath("2,0,0,0,0,0,0");
		}
		temp = trGetNextUnitScenarioNameNumber();
		for(x = 0 ; < 9){
			UnitCreate(1, "Underworld Passage SPC", 180, 109+x*10, 270);
			trUnitSelectClear();
			trUnitSelect(""+(temp+x));
			trSetSelectedUpVector(0,3,0);
			trSetSelectedScale(2,1,1);
			trUnitSelectClear();
			trUnitSelect(""+(temp+x));
			trUnitSetAnimationPath("2,0,0,0,0,0,0");
		}
		temp = trGetNextUnitScenarioNameNumber();
		UnitCreate(1, "Hero Greek Atalanta", 150, 80, 0);
		trQuestVarSet("CineUnit", temp);
		trUnitSelectClear();
		trUnitSelectByQV("CineUnit");
		trUnitMoveToPoint(153,3,184,-1,false);
	}
}

rule Win_Cine_08
inactive
highFrequency
{
	if((trTime()-cActivationTime) >= 9){
		xsDisableSelf();
		xsEnableRule("Win_Cine_09");
		createCameraTrack(6500);
		trCameraCut(vector(187.656906,9.532150,81.314079), vector(-0.487300,0.046585,0.871991), vector(0.022725,0.998914,-0.040666), vector(0.872939,0.000000,0.487830));
		addCameraTrackWaypoint();
		trCameraCut(vector(189.625168,13.432149,117.879936), vector(-0.706263,-0.135976,0.694769), vector(-0.096935,0.990712,0.095357), vector(0.701282,0.000000,0.712884));
		addCameraTrackWaypoint();
		playCameraTrack();
	}
}

rule Win_Cine_09
inactive
highFrequency
{
	if((trTime()-cActivationTime) >= 7){
		xsDisableSelf();
		xsEnableRule("Win_Cine_10");
		createCameraTrack(8000);
		trCameraCut(vector(153.827408,84.532089,104.050842), vector(-0.006560,-0.646814,0.762620), vector(-0.005564,0.762648,0.646790), vector(0.999963,0.000000,0.008602));
		addCameraTrackWaypoint();
		trCameraCut(vector(153.827408,57.352131,104.050842), vector(-0.007240,-0.539968,0.841655), vector(-0.004645,0.841686,0.539948), vector(0.999963,0.000000,0.008602));
		addCameraTrackWaypoint();
		trCameraCut(vector(153.741226,31.372126,114.070450), vector(-0.008117,-0.331033,0.943584), vector(-0.002848,0.943619,0.331021), vector(0.999963,0.000000,0.008602));
		addCameraTrackWaypoint();
		trCameraCut(vector(151.283646,16.312134,144.830353), vector(-0.008330,-0.249727,0.968280), vector(-0.002148,0.968316,0.249718), vector(0.999963,0.000000,0.008602));
		addCameraTrackWaypoint();
		playCameraTrack();
		trUnitSelectByQV("CineUnit");
		trUnitDestroy();
		int temp = trGetNextUnitScenarioNameNumber();
		UnitCreate(1, "Hero Greek Atalanta", 150, 184, 0);
		trQuestVarSet("CineUnit", temp);
		characterDialog("Yeebaagooon", "Impressive. Most impressive.", "icons\special e son of osiris icon 64");
		WinText1();
	}
}

rule Win_Cine_10
inactive
highFrequency
{
	if((trTime()-cActivationTime) >= 3){
		xsDisableSelf();
		xsEnableRule("Win_Cine_11");
		characterDialog("Yeebaagooon", "Not only have you defeated Satan, you've become the most successful space miner.", "icons\special e son of osiris icon 64");
		trTechInvokeGodPower(0, "Bronze", vector(11.24, 9.06, 10.94), vector(0,0,0));
	}
}

rule Win_Cine_11
inactive
highFrequency
{
	if((trTime()-cActivationTime) >= 4){
		xsDisableSelf();
		xsEnableRule("Win_Cine_12");
		characterDialog("Yeebaagooon", "And rich. Rich beyond your wildest dreams.", "icons\special e son of osiris icon 64");
	}
}

rule Win_Cine_12
inactive
highFrequency
{
	if((trTime()-cActivationTime) >= 4){
		xsDisableSelf();
		xsEnableRule("Win_Cine_13");
		characterDialog("Yeebaagooon", "Congratulations, you win!", "icons\special e son of osiris icon 64");
		WinText2(20,100);
		//trCameraCut(vector(60.514080,120.241547,20.382381), vector(0.001486,-0.784815,0.619728), vector(0.001882,0.619730,0.784813), vector(0.999997,-0.000000,-0.002398));
		for(n=1 ; <= 150){
			trQuestVarSetFromRand("TempX", 10, 100, false);
			trQuestVarSetFromRand("TempZ", 90, 139, false);
			trQuestVarSet("TempUnit", trGetNextUnitScenarioNameNumber());
			trArmyDispatch("0,0", "Victory Marker", 1, 1*trQuestVarGet("TempX"),0,1*trQuestVarGet("TempZ"),0,false);
			trUnitSelectByQV("TempUnit");
			trUnitChangeProtoUnit("Armor Glow Small");
			xAddDatabaseBlock(dSpace, true);
			xSetInt(dSpace, xSpaceName,1*trQuestVarGet("TempUnit"));
		}
		for(n=1 ; <= 20){
			trQuestVarSetFromRand("TempX", 10, 100, false);
			trQuestVarSetFromRand("TempZ", 90, 139, false);
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
			trQuestVarSetFromRand("TempX", 10, 100, false);
			trQuestVarSetFromRand("TempZ", 90, 139, false);
			trQuestVarSet("TempUnit", trGetNextUnitScenarioNameNumber());
			trArmyDispatch("0,2", "Victory Marker", 1, 1*trQuestVarGet("TempX"),0,1*trQuestVarGet("TempZ"),0,false);
			trUnitSelectByQV("TempUnit");
			trUnitChangeProtoUnit("Pixiu");
			trUnitSelectByQV("TempUnit");
			trSetSelectedScale(0,0,0);
			xAddDatabaseBlock(dSpace, true);
			xSetInt(dSpace, xSpaceName,1*trQuestVarGet("TempUnit"));
		}
		for(n=1 ; <= 20){
			trQuestVarSetFromRand("TempX", 10, 100, false);
			trQuestVarSetFromRand("TempZ", 90, 139, false);
			trQuestVarSet("TempUnit", trGetNextUnitScenarioNameNumber());
			trArmyDispatch("0,2", "Victory Marker", 1, 1*trQuestVarGet("TempX"),0,1*trQuestVarGet("TempZ"),0,false);
			trUnitSelectByQV("TempUnit");
			trUnitChangeProtoUnit("Lampades");
			trUnitSelectByQV("TempUnit");
			trSetSelectedScale(0,0,0);
			xAddDatabaseBlock(dSpace, true);
			xSetInt(dSpace, xSpaceName,1*trQuestVarGet("TempUnit"));
		}
		for(n=1 ; <= 4){
			trQuestVarSetFromRand("TempX", 10, 100, false);
			trQuestVarSetFromRand("TempZ", 90, 139, false);
			trQuestVarSet("TempUnit", trGetNextUnitScenarioNameNumber());
			trArmyDispatch("0,2", "Victory Marker", 1, 1*trQuestVarGet("TempX"),0,1*trQuestVarGet("TempZ"),0,false);
			trUnitSelectByQV("TempUnit");
			trUnitChangeProtoUnit("Plenty Vault");
			trUnitSelectByQV("TempUnit");
			trSetSelectedScale(0,0,0);
			xAddDatabaseBlock(dSpace, true);
			xSetInt(dSpace, xSpaceName,1*trQuestVarGet("TempUnit"));
		}
	}
}

rule Win_Cine_13
inactive
highFrequency
{
	if((trTime()-cActivationTime) >= 3){
		xsDisableSelf();
		trQuestVarSet("CineStatus", 3);
		saveAllData();
		xsEnableRule("Win_Cine_Off");
		characterDialog(" ", " ", "");
		trCameraCut(vector(62.603432,140.663559,106.860794), vector(0.000019,-0.999990,0.004398), vector(0.004397,0.004397,0.999981), vector(0.999990,0.000000,-0.004398));
	}
}
