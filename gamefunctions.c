/* TERRAINS */
const int SandC = 1;
const int DirtA = 2;
const int SandDirt50 = 3;
const int SavannahC = 4;
const int SavannahD = 5;
const int CliffEgyptianB = 6;
const int CliffEgyptianA = 7;

const int Hades7 = 9;
const int PlainDirt50 = 10;
const int PlainDirt75 = 11;
const int CliffPlainB = 12;
const int CliffJungleB = 13;
const int CliffJungleA = 14;
const int CliffGreekA = 15;
const int CliffA = 16;
const int CliffPlainA = 17;
const int Hades4Passable = 18;
const int ShorelinePlainB = 19;
const int ShorelineNorwegianB = 20;
const int UnderwaterRockC = 21;
const int UnderwaterRockB = 22;
const int UnderwaterRockD = 23;
const int UnderwaterRockE = 24;
const int UnderwaterRockF = 25;
const int Hades5 = 26;
const int ShorelineAtlanticC = 27;
const int ShorelineAtlanticB = 28;
const int ShorelineAtlanticA = 29;
const int IceA = 30;
const int IceB = 31;
const int IceC = 32;
const int UnderwaterIceA = 33;
const int UnderwaterIceB = 34;
const int UnderwaterIceC = 35;

const int BlackRock = 36;

const int Hades1 = 37;
const int Hades2 = 38;
const int Hades6 = 39;

const int Hades9 = 40;
const int HadesCliff = 41;


void RockType(int rock = 0) {
	switch(rock)
	//1-7 sandy
	{
		case SandC:
		{
			TERRAIN_TYPE = 0;
			TERRAIN_SUBTYPE = 36;
		}
		case DirtA:
		{
			TERRAIN_TYPE = 0;
			TERRAIN_SUBTYPE = 31;
		}
		case SandDirt50:
		{
			TERRAIN_TYPE = 0;
			TERRAIN_SUBTYPE = 39;
		}
		case SavannahC:
		{
			TERRAIN_TYPE = 0;
			TERRAIN_SUBTYPE = 17;
		}
		case SavannahD:
		{
			TERRAIN_TYPE = 0;
			TERRAIN_SUBTYPE = 18;
		}
		case CliffEgyptianB:
		{
			TERRAIN_TYPE = 0;
			TERRAIN_SUBTYPE = 38;
		}
		case CliffEgyptianA:
		{
			TERRAIN_TYPE = 2;
			TERRAIN_SUBTYPE = 2;
		}
		//Ice C
		case IceC:
		{
			TERRAIN_TYPE = 5;
			TERRAIN_SUBTYPE = 2;
		}
		//Hades 7
		case Hades7:
		{
			TERRAIN_TYPE = 2;
			TERRAIN_SUBTYPE = 10;
		}
		case PlainDirt50:
		{
			TERRAIN_TYPE = 0;
			TERRAIN_SUBTYPE = 28;
		}
		case PlainDirt75:
		{
			TERRAIN_TYPE = 0;
			TERRAIN_SUBTYPE = 29;
		}
		case CliffPlainB:
		{
			TERRAIN_TYPE = 0;
			TERRAIN_SUBTYPE = 30;
		}
		case CliffJungleB:
		{
			TERRAIN_TYPE = 0;
			TERRAIN_SUBTYPE = 24;
		}
		case CliffJungleA:
		{
			TERRAIN_TYPE = 2;
			TERRAIN_SUBTYPE = 4;
		}
		case CliffGreekA:
		{
			TERRAIN_TYPE = 2;
			TERRAIN_SUBTYPE = 1;
		}
		case CliffA:
		{
			TERRAIN_TYPE = 2;
			TERRAIN_SUBTYPE = 0;
		}
		case CliffPlainA:
		{
			TERRAIN_TYPE = 2;
			TERRAIN_SUBTYPE = 5;
		}
		case Hades4Passable:
		{
			TERRAIN_TYPE = 5;
			TERRAIN_SUBTYPE = 7;
		}
		
		case ShorelinePlainB:
		{
			TERRAIN_TYPE = 4;
			TERRAIN_SUBTYPE = 25;
		}
		case ShorelineNorwegianB:
		{
			TERRAIN_TYPE = 4;
			TERRAIN_SUBTYPE = 8;
		}
		case UnderwaterRockC:
		{
			TERRAIN_TYPE = 3;
			TERRAIN_SUBTYPE = 2;
		}
		case UnderwaterRockB:
		{
			TERRAIN_TYPE = 3;
			TERRAIN_SUBTYPE = 1;
		}
		case UnderwaterRockD:
		{
			TERRAIN_TYPE = 3;
			TERRAIN_SUBTYPE = 3;
		}
		case UnderwaterRockE:
		{
			TERRAIN_TYPE = 3;
			TERRAIN_SUBTYPE = 4;
		}
		case UnderwaterRockF:
		{
			TERRAIN_TYPE = 3;
			TERRAIN_SUBTYPE = 5;
		}
		case Hades5:
		{
			TERRAIN_TYPE = 2;
			TERRAIN_SUBTYPE = 8;
		}
		
		case ShorelineAtlanticA:
		{
			TERRAIN_TYPE = 4;
			TERRAIN_SUBTYPE = 14;
		}
		case ShorelineAtlanticB:
		{
			TERRAIN_TYPE = 4;
			TERRAIN_SUBTYPE = 15;
		}
		case ShorelineAtlanticC:
		{
			TERRAIN_TYPE = 4;
			TERRAIN_SUBTYPE = 16;
		}
		
		case IceA:
		{
			TERRAIN_TYPE = 5;
			TERRAIN_SUBTYPE = 0;
		}
		case IceB:
		{
			TERRAIN_TYPE = 5;
			TERRAIN_SUBTYPE = 1;
		}
		
		case UnderwaterIceA:
		{
			TERRAIN_TYPE = 3;
			TERRAIN_SUBTYPE = 6;
		}
		case UnderwaterIceB:
		{
			TERRAIN_TYPE = 3;
			TERRAIN_SUBTYPE = 7;
		}
		case UnderwaterIceC:
		{
			TERRAIN_TYPE = 3;
			TERRAIN_SUBTYPE = 8;
		}
		
		case BlackRock:
		{
			TERRAIN_TYPE = 2;
			TERRAIN_SUBTYPE = 13;
		}
		
		case Hades1:
		{
			TERRAIN_TYPE = 5;
			TERRAIN_SUBTYPE = 5;
		}
		
		case Hades2:
		{
			TERRAIN_TYPE = 5;
			TERRAIN_SUBTYPE = 6;
		}
		
		case Hades6:
		{
			TERRAIN_TYPE = 2;
			TERRAIN_SUBTYPE = 9;
		}
		
		case Hades9:
		{
			TERRAIN_TYPE = 5;
			TERRAIN_SUBTYPE = 9;
		}
		
		case HadesCliff:
		{
			TERRAIN_TYPE = 2;
			TERRAIN_SUBTYPE = 11;
		}
		
	}
}

int GetRockHardness(int rock = 0) {
	switch(rock)
	//1-7 sandy
	{
		case SandC:
		{
			return(10);
		}
		case DirtA:
		{
			return(15);
		}
		case SandDirt50:
		{
			return(20);
		}
		case SavannahC:
		{
			return(40);
		}
		case SavannahD:
		{
			return(60);
		}
		case CliffEgyptianB:
		{
			return(80);
		}
		case CliffEgyptianA:
		{
			return(100);
		}
		case PlainDirt50:
		{
			return(75);
		}
		case PlainDirt75:
		{
			return(90);
		}
		case CliffPlainB:
		{
			return(110);
		}
		case CliffJungleB:
		{
			return(130);
		}
		case CliffJungleA:
		{
			return(150);
		}
		case CliffA:
		{
			return(175);
		}
		case CliffGreekA:
		{
			return(200);
		}
		case Hades4Passable:
		{
			return(225);
		}
		case CliffPlainA:
		{
			return(250);
		}
		case ShorelinePlainB:
		{
			return(275);
		}
		case ShorelineNorwegianB:
		{
			return(300);
		}
		case UnderwaterRockC:
		{
			return(350);
		}
		case UnderwaterRockB:
		{
			return(375);
		}
		case UnderwaterRockD:
		{
			return(400);
		}
		case UnderwaterRockE:
		{
			return(450);
		}
		case UnderwaterRockF:
		{
			return(500);
		}
		case Hades5:
		{
			return(300);
		}
		
		case ShorelineAtlanticA:
		{
			return(450);
		}
		case ShorelineAtlanticB:
		{
			return(500);
		}
		case ShorelineAtlanticC:
		{
			return(550);
		}
		case IceA:
		{
			return(700);
		}
		case IceB:
		{
			return(800);
		}
		case UnderwaterIceA:
		{
			return(1000);
		}
		case UnderwaterIceB:
		{
			return(1200);
		}
		case UnderwaterIceC:
		{
			return(1500);
		}
		case Hades1:
		{
			return(1000);
		}
		case Hades2:
		{
			return(1200);
		}
		case Hades6:
		{
			return(1400);
		}
		case Hades9:
		{
			return(1500);
		}
		case HadesCliff:
		{
			return(2000);
		}
		case BlackRock:
		{
			return(10000);
		}
		
		
		//Ice C
		case IceC:
		{
			return(1000);
		}
		//Hades 7
		case Hades7:
		{
			return(800);
		}
	}
}

int GetRockType(int t = 0, int st = 0){
	if(t == 0){
		if(st == 36){
			return(SandC);
		}
		if(st == 31){
			return(DirtA);
		}
		if(st == 39){
			return(SandDirt50);
		}
		if(st == 17){
			return(SavannahC);
		}
		if(st == 18){
			return(SavannahD);
		}
		if(st == 38){
			return(CliffEgyptianB);
		}
		if(st == 28){
			return(PlainDirt50);
		}
		if(st == 29){
			return(PlainDirt75);
		}
		if(st == 30){
			return(CliffPlainB);
		}
		if(st == 24){
			return(CliffJungleB);
		}
	}
	else if(t == 2){
		if(st == 0){
			return(CliffA);
		}
		if(st == 1){
			return(CliffGreekA);
		}
		if(st == 5){
			return(CliffPlainA);
		}
		if(st == 2){
			return(CliffEgyptianA);
		}
		if(st == 4){
			return(CliffJungleA);
		}
		if(st == 8){
			return(Hades5);
		}
		if(st == 9){
			return(Hades6);
		}
		if(st == 10){
			return(Hades7); //lava
		}
		if(st == 11){
			return(HadesCliff);
		}
		if(st == 13){
			return(BlackRock);
		}
	}
	else if(t == 3){
		if(st == 1){
			return(UnderwaterRockB);
		}
		if(st == 2){
			return(UnderwaterRockC);
		}
		if(st == 3){
			return(UnderwaterRockD);
		}
		if(st == 4){
			return(UnderwaterRockE);
		}
		if(st == 5){
			return(UnderwaterRockF);
		}
		if(st == 6){
			return(UnderwaterIceA);
		}
		if(st == 7){
			return(UnderwaterIceB);
		}
		if(st == 8){
			return(UnderwaterIceC);
		}
	}
	else if(t == 4){
		if(st == 8){
			return(ShorelineNorwegianB);
		}
		if(st == 14){
			return(ShorelineAtlanticA);
		}
		if(st == 15){
			return(ShorelineAtlanticB);
		}
		if(st == 16){
			return(ShorelineAtlanticC);
		}
		if(st == 25){
			return(ShorelinePlainB);
		}
	}
	else if(t == 5){
		if(st == 2){
			return(IceC);
		}
		if(st == 1){
			return(IceB);
		}
		if(st == 0){
			return(IceA);
		}
		if(st == 7){
			return(Hades4Passable);
		}
		if(st == 5){
			return(Hades1);
		}
		if(st == 6){
			return(Hades2);
		}
		if(st == 9){
			return(Hades9);
		}
	}
}

void SetDrillSpeed(int p = 0, int x = 0, int z = 0){
	xsSetContextPlayer(0);
	int terraintype = trGetTerrainType(x,z);
	int terrainsubtype = trGetTerrainSubType(x,z);
	xSetPointer(dPlayerData, p);
	trQuestVarSet("DrillCalc", xGetFloat(dPlayerData, xDrillPower)/GetRockHardness(GetRockType(terraintype, terrainsubtype)));
	if(1*trQuestVarGet("P"+p+"DrillBonusOn") == 1){
		trQuestVarSet("DrillCalc", 30);
	}
	modifyProtounitAbsolute("Wadjet Spit", p, 1, xsMin(30,trQuestVarGet("DrillCalc")*3));
}

rule BronzeUp
inactive
highFrequency
{
	if((trTime()-cActivationTime) >= 1){
		xsDisableSelf();
		int a = BronzeNumber-1;
		int x = BronzeX;
		int z = BronzeZ;
		a = a+1;
		trUnitSelectClear();
		trUnitSelect(""+a);
		trUnitTeleport(x+1.155,0,z+6.015);
		trUnitSelectClear();
		trUnitSelect(""+a);
		trMutateSelected(kbGetProtoUnitID("Wall Long"));
		trUnitSelectClear();
		trUnitSelect(""+a);
		trUnitSetAnimationPath("0,2,0,0,0");
		a = a+1;
		trUnitSelectClear();
		trUnitSelect(""+a);
		trUnitTeleport(x+11.197,0,z+6.097);
		trUnitSelectClear();
		trUnitSelect(""+a);
		trMutateSelected(kbGetProtoUnitID("Wall Long"));
		trUnitSelectClear();
		trUnitSelect(""+a);
		trUnitSetAnimationPath("0,2,0,0,0");
		a = a+1;
		trUnitSelectClear();
		trUnitSelect(""+a);
		trUnitTeleport(x+3.889,0,z+8.872);
		trUnitSelectClear();
		trUnitSelect(""+a);
		trMutateSelected(kbGetProtoUnitID("Wall Medium"));
		trUnitSelectClear();
		trUnitSelect(""+a);
		trUnitSetAnimationPath("0,2,0,0,0");
		a = a+1;
		trUnitSelectClear();
		trUnitSelect(""+a);
		trUnitTeleport(x+8.841,0,z+8.543);
		trUnitSelectClear();
		trUnitSelect(""+a);
		trMutateSelected(kbGetProtoUnitID("Wall Medium"));
		trUnitSelectClear();
		trUnitSelect(""+a);
		trUnitSetAnimationPath("0,2,0,0,0");
		a = a+1;
		trUnitSelectClear();
		trUnitSelect(""+a);
		trUnitTeleport(x+15.666,0,z+6.058);
		trUnitSelectClear();
		trUnitSelect(""+a);
		trMutateSelected(kbGetProtoUnitID("Wall Long"));
		trUnitSelectClear();
		trUnitSelect(""+a);
		trUnitSetAnimationPath("0,2,0,0,0");
		a = a+1;
		trUnitSelectClear();
		trUnitSelect(""+a);
		trUnitTeleport(x+25.708,0,z+6.14);
		trUnitSelectClear();
		trUnitSelect(""+a);
		trMutateSelected(kbGetProtoUnitID("Wall Long"));
		trUnitSelectClear();
		trUnitSelect(""+a);
		trUnitSetAnimationPath("0,2,0,0,0");
		a = a+1;
		trUnitSelectClear();
		trUnitSelect(""+a);
		trUnitTeleport(x+20.646,0,z+11.12);
		trUnitSelectClear();
		trUnitSelect(""+a);
		trMutateSelected(kbGetProtoUnitID("Wall Long"));
		trUnitSelectClear();
		trUnitSelect(""+a);
		trUnitSetAnimationPath("0,2,0,0,0");
		a = a+1;
		trUnitSelectClear();
		trUnitSelect(""+a);
		trUnitTeleport(x+20.728,0,z+1.07);
		trUnitSelectClear();
		trUnitSelect(""+a);
		trMutateSelected(kbGetProtoUnitID("Wall Long"));
		trUnitSelectClear();
		trUnitSelect(""+a);
		trUnitSetAnimationPath("0,2,0,0,0");
		a = a+1;
		trUnitSelectClear();
		trUnitSelect(""+a);
		trUnitTeleport(x+36.121,0,z+6);
		trUnitSelectClear();
		trUnitSelect(""+a);
		trMutateSelected(kbGetProtoUnitID("Wall Long"));
		trUnitSelectClear();
		trUnitSelect(""+a);
		trUnitSetAnimationPath("0,2,0,0,0");
		a = a+1;
		trUnitSelectClear();
		trUnitSelect(""+a);
		trUnitTeleport(x+33.779,0,z+11.05);
		trUnitSelectClear();
		trUnitSelect(""+a);
		trMutateSelected(kbGetProtoUnitID("Wall Medium"));
		trUnitSelectClear();
		trUnitSelect(""+a);
		trUnitSetAnimationPath("0,2,0,0,0");
		a = a+1;
		trUnitSelectClear();
		trUnitSelect(""+a);
		trUnitTeleport(x+39.093,0,z+11.15);
		trUnitSelectClear();
		trUnitSelect(""+a);
		trMutateSelected(kbGetProtoUnitID("Wall Medium"));
		trUnitSelectClear();
		trUnitSelect(""+a);
		trUnitSetAnimationPath("0,2,0,0,0");
		a = a+1;
		trUnitSelectClear();
		trUnitSelect(""+a);
		trUnitTeleport(x+47.133,0,z+6.075);
		trUnitSelectClear();
		trUnitSelect(""+a);
		trMutateSelected(kbGetProtoUnitID("Wall Long"));
		trUnitSelectClear();
		trUnitSelect(""+a);
		trUnitSetAnimationPath("0,2,0,0,0");
		a = a+1;
		trUnitSelectClear();
		trUnitSelect(""+a);
		trUnitTeleport(x+54.03,0,z+6.075);
		trUnitSelectClear();
		trUnitSelect(""+a);
		trMutateSelected(kbGetProtoUnitID("Wall Long"));
		trUnitSelectClear();
		trUnitSelect(""+a);
		trUnitSetAnimationPath("0,2,0,0,0");
		a = a+1;
		trUnitSelectClear();
		trUnitSelect(""+a);
		trUnitTeleport(x+51.2,0,z+6.026);
		trUnitSelectClear();
		trUnitSelect(""+a);
		trMutateSelected(kbGetProtoUnitID("Wall Medium"));
		trUnitSelectClear();
		trUnitSelect(""+a);
		trUnitSetAnimationPath("0,2,0,0,0");
		a = a+1;
		trUnitSelectClear();
		trUnitSelect(""+a);
		trUnitTeleport(x+58.624,0,z+6.215);
		trUnitSelectClear();
		trUnitSelect(""+a);
		trMutateSelected(kbGetProtoUnitID("Wall Long"));
		trUnitSelectClear();
		trUnitSelect(""+a);
		trUnitSetAnimationPath("0,2,0,0,0");
		a = a+1;
		trUnitSelectClear();
		trUnitSelect(""+a);
		trUnitTeleport(x+61.949,0,z+11.177);
		trUnitSelectClear();
		trUnitSelect(""+a);
		trMutateSelected(kbGetProtoUnitID("Wall Medium"));
		trUnitSelectClear();
		trUnitSelect(""+a);
		trUnitSetAnimationPath("0,2,0,0,0");
		a = a+1;
		trUnitSelectClear();
		trUnitSelect(""+a);
		trUnitTeleport(x+61.949,0,z+6.052);
		trUnitSelectClear();
		trUnitSelect(""+a);
		trMutateSelected(kbGetProtoUnitID("Wall Medium"));
		trUnitSelectClear();
		trUnitSelect(""+a);
		trUnitSetAnimationPath("0,2,0,0,0");
		a = a+1;
		trUnitSelectClear();
		trUnitSelect(""+a);
		trUnitTeleport(x+61.949,0,z+1.376);
		trUnitSelectClear();
		trUnitSelect(""+a);
		trMutateSelected(kbGetProtoUnitID("Wall Medium"));
		trUnitSelectClear();
		trUnitSelect(""+a);
		trUnitSetAnimationPath("0,2,0,0,0");
		a = a+1;
		trUnitSelectClear();
		trUnitSelect(""+a);
		trUnitTeleport(x+72.069,0,z+6.35);
		trUnitSelectClear();
		trUnitSelect(""+a);
		trMutateSelected(kbGetProtoUnitID("Wall Long"));
		trUnitSelectClear();
		trUnitSelect(""+a);
		trUnitSetAnimationPath("0,2,0,0,0");
		a = a+1;
		trUnitSelectClear();
		trUnitSelect(""+a);
		trUnitTeleport(x+74.332,0,z+11.576);
		trUnitSelectClear();
		trUnitSelect(""+a);
		trMutateSelected(kbGetProtoUnitID("Wall Short"));
		trUnitSelectClear();
		trUnitSelect(""+a);
		trUnitSetAnimationPath("0,2,0,0,0");
		a = a+1;
		trUnitSelectClear();
		trUnitSelect(""+a);
		trUnitTeleport(x+76.752,0,z+9.586);
		trUnitSelectClear();
		trUnitSelect(""+a);
		trMutateSelected(kbGetProtoUnitID("Wall Short"));
		trUnitSelectClear();
		trUnitSelect(""+a);
		trUnitSetAnimationPath("0,2,0,0,0");
		a = a+1;
		trUnitSelectClear();
		trUnitSelect(""+a);
		trUnitTeleport(x+74.537,0,z+7.406);
		trUnitSelectClear();
		trUnitSelect(""+a);
		trMutateSelected(kbGetProtoUnitID("Wall Short"));
		trUnitSelectClear();
		trUnitSelect(""+a);
		trUnitSetAnimationPath("0,2,0,0,0");
		a = a+1;
		trUnitSelectClear();
		trUnitSelect(""+a);
		trUnitTeleport(x+77.9386,0,z+4.425);
		trUnitSelectClear();
		trUnitSelect(""+a);
		trMutateSelected(kbGetProtoUnitID("Wall Medium"));
		trUnitSelectClear();
		trUnitSelect(""+a);
		trUnitSetAnimationPath("0,2,0,0,0");
		a = a+1;
		trUnitSelectClear();
		trUnitSelect(""+a);
		trUnitTeleport(x+85.773,0,z+6.785);
		trUnitSelectClear();
		trUnitSelect(""+a);
		trMutateSelected(kbGetProtoUnitID("Wall Long"));
		trUnitSelectClear();
		trUnitSelect(""+a);
		trUnitSetAnimationPath("0,2,0,0,0");
		a = a+1;
		trUnitSelectClear();
		trUnitSelect(""+a);
		trUnitTeleport(x+89.147,0,z+1.789);
		trUnitSelectClear();
		trUnitSelect(""+a);
		trMutateSelected(kbGetProtoUnitID("Wall Long"));
		trUnitSelectClear();
		trUnitSelect(""+a);
		trUnitSetAnimationPath("0,2,0,0,0");
		a = a+1;
		trUnitSelectClear();
		trUnitSelect(""+a);
		trUnitTeleport(x+97.093,0,z+6.983);
		trUnitSelectClear();
		trUnitSelect(""+a);
		trMutateSelected(kbGetProtoUnitID("Wall Long"));
		trUnitSelectClear();
		trUnitSelect(""+a);
		trUnitSetAnimationPath("0,2,0,0,0");
		a = a+1;
		trUnitSelectClear();
		trUnitSelect(""+a);
		trUnitTeleport(x+102.073,0,z+12.044);
		trUnitSelectClear();
		trUnitSelect(""+a);
		trMutateSelected(kbGetProtoUnitID("Wall Long"));
		trUnitSelectClear();
		trUnitSelect(""+a);
		trUnitSetAnimationPath("0,2,0,0,0");
		a = a+1;
		trUnitSelectClear();
		trUnitSelect(""+a);
		trUnitTeleport(x+102.155,0,z+2);
		trUnitSelectClear();
		trUnitSelect(""+a);
		trMutateSelected(kbGetProtoUnitID("Wall Long"));
		trUnitSelectClear();
		trUnitSelect(""+a);
		trUnitSetAnimationPath("0,2,0,0,0");
		a = a+1;
		trUnitSelectClear();
		trUnitSelect(""+a);
		trUnitTeleport(x+107.135,0,z+7.064);
		trUnitSelectClear();
		trUnitSelect(""+a);
		trMutateSelected(kbGetProtoUnitID("Wall Long"));
		trUnitSelectClear();
		trUnitSelect(""+a);
		trUnitSetAnimationPath("0,2,0,0,0");
		a = a+1;
		trUnitSelectClear();
		trUnitSelect(""+a);
		trUnitTeleport(x+112.9747,0,z+7.339);
		trUnitSelectClear();
		trUnitSelect(""+a);
		trMutateSelected(kbGetProtoUnitID("Wall Long"));
		trUnitSelectClear();
		trUnitSelect(""+a);
		trUnitSetAnimationPath("0,2,0,0,0");
		a = a+1;
		trUnitSelectClear();
		trUnitSelect(""+a);
		trUnitTeleport(x+116.873,0,z+7.239);
		trUnitSelectClear();
		trUnitSelect(""+a);
		trMutateSelected(kbGetProtoUnitID("Wall Long"));
		trUnitSelectClear();
		trUnitSelect(""+a);
		trUnitSetAnimationPath("0,2,0,0,0");
		a = a+1;
		trUnitSelectClear();
		trUnitSelect(""+a);
		trUnitTeleport(x+114.922,0,z+6.509);
		trUnitSelectClear();
		trUnitSelect(""+a);
		trMutateSelected(kbGetProtoUnitID("Wall Short"));
		trUnitSelectClear();
		trUnitSelect(""+a);
		trUnitSetAnimationPath("0,2,0,0,0");
		a = a+1;
		trUnitSelectClear();
		trUnitSelect(""+a);
		trUnitTeleport(x+124.093,0,z+7.344);
		trUnitSelectClear();
		trUnitSelect(""+a);
		trMutateSelected(kbGetProtoUnitID("Wall Long"));
		trUnitSelectClear();
		trUnitSelect(""+a);
		trUnitSetAnimationPath("0,2,0,0,0");
		a = a+1;
		trUnitSelectClear();
		trUnitSelect(""+a);
		trUnitTeleport(x+125.7286,0,z+3.903);
		trUnitSelectClear();
		trUnitSelect(""+a);
		trMutateSelected(kbGetProtoUnitID("Wall Short"));
		trUnitSelectClear();
		trUnitSelect(""+a);
		trUnitSetAnimationPath("0,2,0,0,0");
		a = a+1;
		trUnitSelectClear();
		trUnitSelect(""+a);
		trUnitTeleport(x+125.641,0,z+10.783);
		trUnitSelectClear();
		trUnitSelect(""+a);
		trMutateSelected(kbGetProtoUnitID("Wall Short"));
		trUnitSelectClear();
		trUnitSelect(""+a);
		trUnitSetAnimationPath("0,2,0,0,0");
		a = a+1;
		trUnitSelectClear();
		trUnitSelect(""+a);
		trUnitTeleport(x+127.395,0,z+7.314);
		trUnitSelectClear();
		trUnitSelect(""+a);
		trMutateSelected(kbGetProtoUnitID("Wall Short"));
		trUnitSelectClear();
		trUnitSelect(""+a);
		trUnitSetAnimationPath("0,2,0,0,0");
		if(aiIsMultiplayer() == false){
			a = a+1;
			trQuestVarSet("CompletionObelisk", a);
			trUnitSelectByQV("CompletionObelisk");
			trUnitTeleport(69,3,66);
			trUnitSelectByQV("CompletionObelisk");
			trMutateSelected(kbGetProtoUnitID("Outpost"));
			trUnitSelectByQV("CompletionObelisk");
			trSetSelectedScale(2,3,2);
		}
	}
}



void MainTitle(int x = 0, int z = 0){
	xsSetContextPlayer(0);
	int a = trGetNextUnitScenarioNameNumber();
	BronzeNumber = a;
	BronzeX = x;
	BronzeZ = z;
	a = trGetNextUnitScenarioNameNumber();
	UnitCreate(0,"Hoplite", 1,1,90);
	xAddDatabaseBlock(dDestroyMe, true);
	xSetInt(dDestroyMe, xDestroyName, a);
	xSetInt(dDestroyMe, xDestroyTime, trTimeMS()+10000);
	a = trGetNextUnitScenarioNameNumber();
	UnitCreate(0,"Hoplite", 1,1,90);
	xAddDatabaseBlock(dDestroyMe, true);
	xSetInt(dDestroyMe, xDestroyName, a);
	xSetInt(dDestroyMe, xDestroyTime, trTimeMS()+10000);
	a = trGetNextUnitScenarioNameNumber();
	UnitCreate(0,"Hoplite", 1,1,45);
	xAddDatabaseBlock(dDestroyMe, true);
	xSetInt(dDestroyMe, xDestroyName, a);
	xSetInt(dDestroyMe, xDestroyTime, trTimeMS()+10000);
	a = trGetNextUnitScenarioNameNumber();
	UnitCreate(0,"Hoplite", 1,1,135);
	xAddDatabaseBlock(dDestroyMe, true);
	xSetInt(dDestroyMe, xDestroyName, a);
	xSetInt(dDestroyMe, xDestroyTime, trTimeMS()+10000);
	a = trGetNextUnitScenarioNameNumber();
	UnitCreate(0,"Hoplite", 1,1,90);
	xAddDatabaseBlock(dDestroyMe, true);
	xSetInt(dDestroyMe, xDestroyName, a);
	xSetInt(dDestroyMe, xDestroyTime, trTimeMS()+10000);
	a = trGetNextUnitScenarioNameNumber();
	UnitCreate(0,"Hoplite", 1,1,90);
	xAddDatabaseBlock(dDestroyMe, true);
	xSetInt(dDestroyMe, xDestroyName, a);
	xSetInt(dDestroyMe, xDestroyTime, trTimeMS()+10000);
	a = trGetNextUnitScenarioNameNumber();
	UnitCreate(0,"Hoplite", 1,1,0);
	xAddDatabaseBlock(dDestroyMe, true);
	xSetInt(dDestroyMe, xDestroyName, a);
	xSetInt(dDestroyMe, xDestroyTime, trTimeMS()+10000);
	a = trGetNextUnitScenarioNameNumber();
	UnitCreate(0,"Hoplite", 1,1,0);
	xAddDatabaseBlock(dDestroyMe, true);
	xSetInt(dDestroyMe, xDestroyName, a);
	xSetInt(dDestroyMe, xDestroyTime, trTimeMS()+10000);
	a = trGetNextUnitScenarioNameNumber();
	UnitCreate(0,"Hoplite", 1,1,90);
	xAddDatabaseBlock(dDestroyMe, true);
	xSetInt(dDestroyMe, xDestroyName, a);
	xSetInt(dDestroyMe, xDestroyTime, trTimeMS()+10000);
	a = trGetNextUnitScenarioNameNumber();
	UnitCreate(0,"Hoplite", 1,1,180);
	xAddDatabaseBlock(dDestroyMe, true);
	xSetInt(dDestroyMe, xDestroyName, a);
	xSetInt(dDestroyMe, xDestroyTime, trTimeMS()+10000);
	a = trGetNextUnitScenarioNameNumber();
	UnitCreate(0,"Hoplite", 1,1,180);
	xAddDatabaseBlock(dDestroyMe, true);
	xSetInt(dDestroyMe, xDestroyName, a);
	xSetInt(dDestroyMe, xDestroyTime, trTimeMS()+10000);
	a = trGetNextUnitScenarioNameNumber();
	UnitCreate(0,"Hoplite", 1,1,90);
	xAddDatabaseBlock(dDestroyMe, true);
	xSetInt(dDestroyMe, xDestroyName, a);
	xSetInt(dDestroyMe, xDestroyTime, trTimeMS()+10000);
	a = trGetNextUnitScenarioNameNumber();
	UnitCreate(0,"Hoplite", 1,1,90);
	xAddDatabaseBlock(dDestroyMe, true);
	xSetInt(dDestroyMe, xDestroyName, a);
	xSetInt(dDestroyMe, xDestroyTime, trTimeMS()+10000);
	a = trGetNextUnitScenarioNameNumber();
	UnitCreate(0,"Hoplite", 1,1,180);
	xAddDatabaseBlock(dDestroyMe, true);
	xSetInt(dDestroyMe, xDestroyName, a);
	xSetInt(dDestroyMe, xDestroyTime, trTimeMS()+10000);
	a = trGetNextUnitScenarioNameNumber();
	UnitCreate(0,"Hoplite", 1,1,90);
	xAddDatabaseBlock(dDestroyMe, true);
	xSetInt(dDestroyMe, xDestroyName, a);
	xSetInt(dDestroyMe, xDestroyTime, trTimeMS()+10000);
	a = trGetNextUnitScenarioNameNumber();
	UnitCreate(0,"Hoplite", 1,1,180);
	xAddDatabaseBlock(dDestroyMe, true);
	xSetInt(dDestroyMe, xDestroyName, a);
	xSetInt(dDestroyMe, xDestroyTime, trTimeMS()+10000);
	a = trGetNextUnitScenarioNameNumber();
	UnitCreate(0,"Hoplite", 1,1,180);
	xAddDatabaseBlock(dDestroyMe, true);
	xSetInt(dDestroyMe, xDestroyName, a);
	xSetInt(dDestroyMe, xDestroyTime, trTimeMS()+10000);
	a = trGetNextUnitScenarioNameNumber();
	UnitCreate(0,"Hoplite", 1,1,180);
	xAddDatabaseBlock(dDestroyMe, true);
	xSetInt(dDestroyMe, xDestroyName, a);
	xSetInt(dDestroyMe, xDestroyTime, trTimeMS()+10000);
	a = trGetNextUnitScenarioNameNumber();
	UnitCreate(0,"Hoplite", 1,1,90);
	xAddDatabaseBlock(dDestroyMe, true);
	xSetInt(dDestroyMe, xDestroyName, a);
	xSetInt(dDestroyMe, xDestroyTime, trTimeMS()+10000);
	a = trGetNextUnitScenarioNameNumber();
	UnitCreate(0,"Hoplite", 1,1,180);
	xAddDatabaseBlock(dDestroyMe, true);
	xSetInt(dDestroyMe, xDestroyName, a);
	xSetInt(dDestroyMe, xDestroyTime, trTimeMS()+10000);
	a = trGetNextUnitScenarioNameNumber();
	UnitCreate(0,"Hoplite", 1,1,90);
	xAddDatabaseBlock(dDestroyMe, true);
	xSetInt(dDestroyMe, xDestroyName, a);
	xSetInt(dDestroyMe, xDestroyTime, trTimeMS()+10000);
	a = trGetNextUnitScenarioNameNumber();
	UnitCreate(0,"Hoplite", 1,1,0);
	xAddDatabaseBlock(dDestroyMe, true);
	xSetInt(dDestroyMe, xDestroyName, a);
	xSetInt(dDestroyMe, xDestroyTime, trTimeMS()+10000);
	a = trGetNextUnitScenarioNameNumber();
	UnitCreate(0,"Hoplite", 1,1,245);
	xAddDatabaseBlock(dDestroyMe, true);
	xSetInt(dDestroyMe, xDestroyName, a);
	xSetInt(dDestroyMe, xDestroyTime, trTimeMS()+10000);
	a = trGetNextUnitScenarioNameNumber();
	UnitCreate(0,"Hoplite", 1,1,90);
	xAddDatabaseBlock(dDestroyMe, true);
	xSetInt(dDestroyMe, xDestroyName, a);
	xSetInt(dDestroyMe, xDestroyTime, trTimeMS()+10000);
	a = trGetNextUnitScenarioNameNumber();
	UnitCreate(0,"Hoplite", 1,1,180);
	xAddDatabaseBlock(dDestroyMe, true);
	xSetInt(dDestroyMe, xDestroyName, a);
	xSetInt(dDestroyMe, xDestroyTime, trTimeMS()+10000);
	a = trGetNextUnitScenarioNameNumber();
	UnitCreate(0,"Hoplite", 1,1,90);
	xAddDatabaseBlock(dDestroyMe, true);
	xSetInt(dDestroyMe, xDestroyName, a);
	xSetInt(dDestroyMe, xDestroyTime, trTimeMS()+10000);
	a = trGetNextUnitScenarioNameNumber();
	UnitCreate(0,"Hoplite", 1,1,0);
	xAddDatabaseBlock(dDestroyMe, true);
	xSetInt(dDestroyMe, xDestroyName, a);
	xSetInt(dDestroyMe, xDestroyTime, trTimeMS()+10000);
	a = trGetNextUnitScenarioNameNumber();
	UnitCreate(0,"Hoplite", 1,1,0);
	xAddDatabaseBlock(dDestroyMe, true);
	xSetInt(dDestroyMe, xDestroyName, a);
	xSetInt(dDestroyMe, xDestroyTime, trTimeMS()+10000);
	a = trGetNextUnitScenarioNameNumber();
	UnitCreate(0,"Hoplite", 1,1,90);
	xAddDatabaseBlock(dDestroyMe, true);
	xSetInt(dDestroyMe, xDestroyName, a);
	xSetInt(dDestroyMe, xDestroyTime, trTimeMS()+10000);
	a = trGetNextUnitScenarioNameNumber();
	UnitCreate(0,"Hoplite", 1,1,112);
	xAddDatabaseBlock(dDestroyMe, true);
	xSetInt(dDestroyMe, xDestroyName, a);
	xSetInt(dDestroyMe, xDestroyTime, trTimeMS()+10000);
	a = trGetNextUnitScenarioNameNumber();
	UnitCreate(0,"Hoplite", 1,1,67);
	xAddDatabaseBlock(dDestroyMe, true);
	xSetInt(dDestroyMe, xDestroyName, a);
	xSetInt(dDestroyMe, xDestroyTime, trTimeMS()+10000);
	a = trGetNextUnitScenarioNameNumber();
	UnitCreate(0,"Hoplite", 1,1,0);
	xAddDatabaseBlock(dDestroyMe, true);
	xSetInt(dDestroyMe, xDestroyName, a);
	xSetInt(dDestroyMe, xDestroyTime, trTimeMS()+10000);
	a = trGetNextUnitScenarioNameNumber();
	UnitCreate(0,"Hoplite", 1,1,90);
	xAddDatabaseBlock(dDestroyMe, true);
	xSetInt(dDestroyMe, xDestroyName, a);
	xSetInt(dDestroyMe, xDestroyTime, trTimeMS()+10000);
	a = trGetNextUnitScenarioNameNumber();
	UnitCreate(0,"Hoplite", 1,1,135);
	xAddDatabaseBlock(dDestroyMe, true);
	xSetInt(dDestroyMe, xDestroyName, a);
	xSetInt(dDestroyMe, xDestroyTime, trTimeMS()+10000);
	a = trGetNextUnitScenarioNameNumber();
	UnitCreate(0,"Hoplite", 1,1,45);
	xAddDatabaseBlock(dDestroyMe, true);
	xSetInt(dDestroyMe, xDestroyName, a);
	xSetInt(dDestroyMe, xDestroyTime, trTimeMS()+10000);
	a = trGetNextUnitScenarioNameNumber();
	UnitCreate(0,"Hoplite", 1,1,90);
	xAddDatabaseBlock(dDestroyMe, true);
	xSetInt(dDestroyMe, xDestroyName, a);
	xSetInt(dDestroyMe, xDestroyTime, trTimeMS()+10000);
	trTechInvokeGodPower(0, "Bronze", vector(11.24, 9.06, 10.94), vector(0,0,0));
	if(aiIsMultiplayer() == false){
		a = trGetNextUnitScenarioNameNumber();
		UnitCreate(0,"Hoplite", 1,1,90);
	}
}


//	if((trGetTerrainSubType(col*4-2,row*4-2) != 13) && (trGetTerrainType(col*4-2,row*4-2) != 2)){
//Doesnt stop black rock from being blown up ... wtf

void MineSquare(int row = 0, int col = 0){
	if(row > 0){
		if((trGetTerrainSubType(col*4-2,row*4-2) != 13) && (trGetTerrainType(col*4-2,row*4-2) != 2)){
			trPaintTerrain(col*4-3,row*4-3,col*4-1,row*4-1,MineT, MineST,false);
			trArmyDispatch("0,0", "Revealer", 1, col*8-4, 1, row*8-4, 180, true);
			//Blow up gas pocket
			for (x= xGetDatabaseCount(dGasPocket); > 0) {
				xDatabaseNext(dGasPocket);
				if((xGetInt(dGasPocket, xGasCol) == col) && (xGetInt(dGasPocket, xGasRow) == row)){
					trVectorQuestVarSet("TempGas", xsVectorSet(8*xGetInt(dGasPocket, xGasCol)-4,3,8*xGetInt(dGasPocket, xGasRow)-4));
					int temp = trGetNextUnitScenarioNameNumber();
					trArmyDispatch("0,0", "Dwarf", 1, 1,1,1, 0, true);
					trUnitSelectClear();
					trUnitSelect(""+temp);
					trUnitSelectClear();
					trUnitSelect(""+temp);
					trUnitTeleport(trVectorQuestVarGetX("TempGas"),trVectorQuestVarGetY("TempGas"),trVectorQuestVarGetZ("TempGas"));
					trMutateSelected(kbGetProtoUnitID("Harpy"));
					trUnitSelectClear();
					trUnitSelect(""+temp);
					trSetSelectedHeight(-10.0);
					trUnitSelectClear();
					trUnitSelect(""+temp);
					trSetSelectedScale(0,0,0);
					trUnitSelectClear();
					trUnitSelect(""+temp);
					trUnitOverrideAnimation(1,0,false,true,-1,-1);
					xFreeDatabaseBlock(dGasPocket);
					trUnitSelectClear();
					trUnitSelect(""+temp);
					xAddDatabaseBlock(dDestroyMe, true);
					xSetInt(dDestroyMe, xDestroyName, temp);
					xSetInt(dDestroyMe, xDestroyTime, trTimeMS()+1500);
				}
			}
		}
		else if((trGetTerrainSubType(col*4-2,row*4-2) == 13) && (trGetTerrainType(col*4-2,row*4-2) == 2)){
			trPaintTerrain(col*4-3,row*4-3,col*4-1,row*4-1,2, 13,false);
		}
	}
}

void RemoveBlack(int row = 0, int col = 0){
	int rowmid = row*4-2;
	int colmid = col*4-2;
	//Wall above
	if((trGetTerrainSubType(col*4-2,row*4-2) == 13) && (trGetTerrainType(col*4-2,row*4-2) == 2)){
		trPaintTerrain(col*4-3,row*4-3,col*4-1,row*4-1,2, 13,false);
		row = 100;
	}
	if(row > 0){
		if(row <= MaxRows){
			if((trGetTerrainSubType((colmid),(rowmid)+4) == MineST) && (trGetTerrainType((colmid),(rowmid)+4) == MineT)){
				trUnitSelectClear();
				trPaintTerrain(col*4-3,row*4-3,col*4-1,row*4,MineT, MineST,false);
				trUnitSelectByQV("R"+row+"C"+col+"WallX");
				trUnitChangeProtoUnit("Meteor Impact Ground");
				trUnitSelectClear();
				trUnitSelectByQV("R"+row+"C"+col+"WallX");
				trUnitDestroy();
				//correct wall but not top layer because terrain above isnt overworld
			}
			if((trGetTerrainSubType((colmid),(rowmid)+4) == OVERTERRAIN_SUBTYPE) && (trGetTerrainType((colmid),(rowmid)+4) == OVERTERRAIN_TYPE)){
				trUnitSelectClear();
				trUnitSelectByQV("R"+row+"C"+col+"WallX");
				trUnitChangeProtoUnit("Meteor Impact Ground");
				trUnitSelectClear();
				trUnitSelectByQV("R"+row+"C"+col+"WallX");
				trUnitDestroy();
			}
			//Wall below
			if((trGetTerrainSubType((colmid),(rowmid)-4) == MineST) && (trGetTerrainType((colmid),(rowmid)-4) == MineT)){
				trPaintTerrain(col*4-3,row*4-4,col*4-1,row*4-1,MineT, MineST,false);
				trUnitSelectClear();
				trUnitSelectByQV("R"+(row-1)+"C"+col+"WallX");
				trUnitChangeProtoUnit("Meteor Impact Ground");
				trUnitSelectClear();
				trUnitSelectByQV("R"+(row-1)+"C"+col+"WallX");
				trUnitDestroy();
				//correct wall but not top layer because terrain above isnt overworld
			}
			if((trGetTerrainSubType((colmid)+4,(rowmid)) == MineST) && (trGetTerrainType((colmid)+4,(rowmid)) == MineT)){
				trPaintTerrain(col*4-3,row*4-3,col*4,row*4-1,MineT, MineST,false);
				trUnitSelectClear();
				trUnitSelectByQV("R"+row+"C"+col+"WallY");
				trUnitChangeProtoUnit("Meteor Impact Ground");
				trUnitSelectClear();
				trUnitSelectByQV("R"+row+"C"+col+"WallY");
				trUnitDestroy();
			}
			if((trGetTerrainSubType((colmid)-4,(rowmid)) == MineST) && (trGetTerrainType((colmid)-4,(rowmid)) == MineT)){
				trPaintTerrain(col*4-4,row*4-3,col*4-1,row*4-1,MineT, MineST,false);
				trUnitSelectClear();
				trUnitSelectByQV("R"+row+"C"+(col-1)+"WallY");
				trUnitChangeProtoUnit("Meteor Impact Ground");
				trUnitSelectClear();
				trUnitSelectByQV("R"+row+"C"+(col-1)+"WallY");
				trUnitDestroy();
			}
			trPaintTerrain(0,4*MaxRows+1,200,4*MaxRows+5,OVERTERRAIN_TYPE,OVERTERRAIN_SUBTYPE,false);
		}
	}
}

void Layout(int row = 0, int col = 0){
	trPaintTerrain(4*col-1,4*row-1,4*col-3,4*row-3,MineT,MineST,false);
	MineSquare(row,col);
	RemoveBlack(row,col);
}
