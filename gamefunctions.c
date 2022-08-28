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
			return(1200);
		}
		case UnderwaterIceB:
		{
			return(1500);
		}
		case UnderwaterIceC:
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
		if(st == 10){
			return(Hades7); //lava
		}
		if(st == 13){
			return(BlackRock); //lava
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
	}
}

void SetDrillSpeed(int p = 0, int x = 0, int z = 0){
	xsSetContextPlayer(0);
	int terraintype = trGetTerrainType(x,z);
	int terrainsubtype = trGetTerrainSubType(x,z);
	xSetPointer(dPlayerData, p);
	trQuestVarSet("DrillCalc", xGetFloat(dPlayerData, xDrillPower)/GetRockHardness(GetRockType(terraintype, terrainsubtype)));
	modifyProtounitAbsolute("Wadjet Spit", p, 1, trQuestVarGet("DrillCalc")*3);
}
