//declare the db first
int dFreeRelics = 0;
int dHeldRelics = 0;
int dHiddenRelics = 0;
int xRelicName = 0;
int xRelicValue = 0;
int xOwner = 0;
//int xRelicPrice = 0;
int dPlayerData = 0;
float xDrillPower = 0;
int xHullHP = 0;
int xEnginePower = 0;
int xRadiator = 0;
int xCargoHold = 2;
int xFuelTank = 1000;
int dObelisks = 0;
int xObeliskName = 0;
int xObeliskStage = 0;
int dPlanetEyecandy = 0;
int xPlanetEyecandyName = 0;
int xPlanetEyecandyStage = 0;

rule setup_databases
active
highFrequency
{
	//RELIC DATABASES
	dFreeRelics = xInitDatabase("FreeRelics"); //db name
	xRelicName = xInitAddInt(dFreeRelics, "name"); //unit name
	xRelicValue = xInitAddInt(dFreeRelics, "value", 1); //value of the relic, default to 1=iron
	dHeldRelics = xInitDatabase("HeldRelics"); //db name
	xRelicName = xInitAddInt(dHeldRelics, "name"); //unit name
	xRelicValue = xInitAddInt(dHeldRelics, "value", 1); //value of the relic, default to 1=iron
	dHiddenRelics = xInitDatabase("HiddenRelics"); //db name
	xRelicName = xInitAddInt(dHiddenRelics, "name"); //unit name
	xRelicValue = xInitAddInt(dHiddenRelics, "value", 1); //value of the relic, default to 1=iron
	xOwner = xInitAddInt(dHiddenRelics, "owner", 0); //value of the relic, default to 0
	xsDisableSelf();
	//Obelisk Stage DB
	dObelisks = xInitDatabase("Obelisks");
	xObeliskName = xInitAddInt(dObelisks, "name"); //unit name
	xObeliskStage = xInitAddInt(dObelisks, "stage");
	//Eyecandy DB
	dPlanetEyecandy = xInitDatabase("PlanetEyecandy");
	xPlanetEyecandyName = xInitAddInt(dPlanetEyecandy, "name"); //unit name
	xPlanetEyecandyStage = xInitAddInt(dPlanetEyecandy, "stage");
	//PLAYER DATA
	dPlayerData = xInitDatabase("playerData");
	xDrillPower = xInitAddFloat(dPlayerData, "drillpower", 10);
	xHullHP = xInitAddInt(dPlayerData, "hullhp", 1000);
	xEnginePower = xInitAddInt(dPlayerData, "enginepower", 10);
	xRadiator = xInitAddInt(dPlayerData, "radiator", 10);
	xCargoHold = xInitAddInt(dPlayerData, "cargohold", 2);
	xFuelTank = xInitAddInt(dPlayerData, "fueltank", 1000);
	xsEnableRule("fill_database");
}

rule fill_database
inactive
highFrequency
{
	for(p=1; < cNumberNonGaiaPlayers) {
		xAddDatabaseBlock(dPlayerData);
	}
	//This sets up basic stats for all players
	//xSetPointer(dPlayerData, 1);
	//xSetFloat(dPlayerData, xDrillPower, 10);
	//Sets the drill power for that player (1)
	xsDisableSelf();
	
	//xSetPointer(dPlayerData, 1);
	//xGetInt(dPlayerData, xDrillPower);
	//Retrieves the drill power for that player (1)
}

/*DB HELP
dPlayerData = xInitDatabase("playerData");
xDrillPower = xInitAddInt(dPlayerData, "drillpower", 10);
xHullHP = xInitAddInt(dPlayerData, "hullhp", 1000);
xsEnableRule("fill_database");


rule fill_database
inactive
highFrequency

for(p=1; < cNumberNonGaiaPlayers) {
	xAddDatabaseBlock(dPlayerData);
}
//This sets up basic stats for all players
xSetPointer(dPlayerData, 1);
xSetInt(dPlayerData, xDrillPower, 10);
//Sets the drill power for that player (1)
xsDisableSelf();

xSetPointer(dPlayerData, 1);
xGetInt(dPlayerData, xDrillPower)
//Retrieves the drill power for that player (1)

*/
