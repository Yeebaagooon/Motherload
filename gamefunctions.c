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
		//Ice C
		case IceC:
		{
			return(2000);
		}
		//Hades 7
		case Hades7:
		{
			return(100);
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
	}
	else if(t == 2){
		if(st == 2){
			return(CliffEgyptianA);
		}
		if(st == 10){
			return(Hades7); //lava
		}
	}
	else if(t == 5){
		if(st == 2){
			return(IceC); //IceC
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
