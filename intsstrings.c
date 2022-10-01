//--SUGGESTIONS
/*
BUG - The active SP unlock bonuses need a seperate trigger always on
Population will trigger antimatter bomb

Search //VERSION OVERRIDE HERE for release to rewrite all data

--TO DO--
-Trap stage
-Bonuses
-Nick said something recently in SD about linking mousewheel to camera
-100% complete reward? (10 stages, 21 relics, 48 levels, 21 bonsues, ?6SPs, 4 something else for % (cine,use AMB, use laser, ?))
-Migdol and wonder for Natas ship selectable DB
-SP exit effect
-SP exit and go to main menu with map on (modeEnter("Campaign"); modeEnter("Pregame");) trIsGadgetVisible to detect anbd do sequence
-??Immunity relics for S10
*/


//---Test controls
//\Yeebaagooon\Motherload\Test sound.mp3
int QuickStart = 0;
int QuickStage = 1;
bool OverrideSP = true;
bool OverrideStage = false;
string displayz = "lol";

//---
int Stage = 0;
int StageTime = 0;
int savedata = 0;
string MapVersion = "Test Version";
string MapName = "Motherload.xs";
int MaxRows = 20;
int MaxCols = 25;
int GSeller = 0; //dont touch, does the player when selling minerals
vector GVectorSellPos = vector(5,3,180);
vector GVectorChinese = vector(0,0,0);
vector GVectorNorse = vector(0,0,0);
int TERRAIN_TYPE = 2;
int TERRAIN_SUBTYPE = 2;
int OVERTERRAIN_TYPE = 5;
int OVERTERRAIN_SUBTYPE = 4;
int CheckTime = 1;

int MineT = 5;
int MineST = 3;

//Max is 4800
int FuelSpendForBonus = 3000;
int HullSpendForBonus = 4000;
int RadiationBonus = 200;
int SeaIceDrill = 30;

float FuelCost = 0;
float FSOneXMin = 10;
float FSOneXMax = 0;
float FSOneZMin = 10;
float FSOneZMax = 0;
float FSTwoXMin = 10;
float FSTwoXMax = 0;
float FSTwoZMin = 10;
float FSTwoZMax = 0;
float FSThreeXMin = 10;
float FSThreeXMax = 0;
float FSThreeZMin = 10;
float FSThreeZMax = 0;
float Hull1XMin = 10;
float Hull1XMax = 0;
float Hull2XMin = 10;
float Hull2XMax = 0;
float Hull3XMin = 10;
float Hull3XMax = 0;
float Hull4XMin = 10;
float Hull4XMax = 0;

//---
int Shop1XMin = 0;
int Shop1XMax = 0;
int Shop1Item = 0;
int Shop1Cost = 0;
int Shop2XMin = 0;
int Shop2XMax = 0;
int Shop2Item = 0;
int Shop2Cost = 0;
int Shop3XMin = 0;
int Shop3XMax = 0;
int Shop3Item = 0;
int Shop3Cost = 0;
int Shop4XMin = 0;
int Shop4XMax = 0;
int Shop4Item = 0;
int Shop4Cost = 0;
int HullCost = 0;

/* TEMPORARY TEST VARS */
//float P1DrillPower = 10;

//---PLAYER DATA
int dPlayerData = 0;
float xDrillPower = 0;
int xHullHP = 0;
int xEnginePower = 0;
int xRadiator = 0;
int xCargoHold = 3;
int xFuelTank = 1000;
float xFuel = 0;
int xDepth = 0;
int xFuelCountdown = 0;
int xFuelCountdownTime = 0;
int xFuelActivationTime = 0;
int dObelisks = 0;
int xObeliskName = 0;
int xObeliskStage = 0;
int dPlanetEyecandy = 0;
int xPlanetEyecandyName = 0;
int xPlanetEyecandyStage = 0;
int xPlayerActive = 0;
int xDrillLevel = 1;
int xHullLevel = 1;
int xFuelLevel = 1;
int xCargoLevel = 1;
int xEngineLevel = 1;
int xRadiatorLevel = 1;
int xGold = 0;
int xGoldStart = 0;
int xStageUnlocked = 0;
int xStageStatus = 0;

int xBonus = 0;
int xRelicCollected = 0;
int xFuelSpend = 0;
int xHullSpend = 0;
int xRadioactivesSold = 0;

int CinematicObelisk = 0;

int xVersionControl = 0;
int xSpyObject = 0;
int xIceDrill = 0;

int UnitObelisk1 = 0;
int UnitObelisk2 = 0;
int UnitObelisk3 = 0;
int UnitObelisk4 = 0;
int UnitObelisk5 = 0;
int UnitObelisk6 = 0;

rule setup_first_databases
active
highFrequency
{
	dPlayerData = xInitDatabase("playerData");
	xDrillPower = xInitAddFloat(dPlayerData, "drillpower", 10);
	xHullHP = xInitAddInt(dPlayerData, "hullhp", 100);
	xEnginePower = xInitAddInt(dPlayerData, "enginepower", 10);
	xRadiator = xInitAddInt(dPlayerData, "radiator", 10);
	xCargoHold = xInitAddInt(dPlayerData, "cargohold", 2);
	xFuelTank = xInitAddInt(dPlayerData, "fueltank", 1000);
	xFuel = xInitAddFloat(dPlayerData, "fuel", 1000);
	xDepth = xInitAddInt(dPlayerData, "depth", 0);
	xGold = xInitAddInt(dPlayerData, "gold", 0);
	xGoldStart = xInitAddInt(dPlayerData, "goldstart", 0);
	xStageUnlocked = xInitAddInt(dPlayerData, "stage", 0);
	xStageStatus = xInitAddInt(dPlayerData, "stagestatus", 0);
	//LEVELS -- all set to 0 at start as for new players and then data read will update them
	xDrillLevel = xInitAddInt(dPlayerData, "Drill level", 1);
	xHullLevel = xInitAddInt(dPlayerData, "Hull level", 1);
	xFuelLevel = xInitAddInt(dPlayerData, "Fuel level", 1);
	xCargoLevel = xInitAddInt(dPlayerData, "Cargo level", 1);
	xEngineLevel = xInitAddInt(dPlayerData, "Engine level", 1);
	xRadiatorLevel = xInitAddInt(dPlayerData, "Radiator level", 1);
	xFuelCountdown = xInitAddInt(dPlayerData, "fuel countdown boolean", 0);
	xFuelCountdownTime = xInitAddInt(dPlayerData, "fuel countdown time", 3);
	xFuelActivationTime = xInitAddInt(dPlayerData, "fuel activation time", 10000);
	xPlayerActive = xInitAddInt(dPlayerData, "is player alive", 1);
	xBonus = xInitAddInt(dPlayerData, "bonus number", 0);
	for(x=1; <= 21) {
		xInitAddInt(dPlayerData, "bonus number"+x, 0);
		//""+xGetInt(dPlayerData, xBonus+5);
	}
	xRelicCollected = xInitAddInt(dPlayerData, "relic number", 0);
	for(x=1; <= 21) {
		xInitAddInt(dPlayerData, "relic number"+x, 0);
		//""+xGetInt(dPlayerData, xBonus+5);
	}
	xFuelSpend = xInitAddInt(dPlayerData, "fuel spend", 0);
	xHullSpend = xInitAddInt(dPlayerData, "hull spend", 0);
	xVersionControl = xInitAddInt(dPlayerData, "version", 0);
	xSpyObject = xInitAddInt(dPlayerData, "spy id", 0);
	xRadioactivesSold = xInitAddInt(dPlayerData, "radioactives sold", 0);
	xIceDrill = xInitAddInt(dPlayerData, "ice drilled", 0);
	xsDisableSelf();
	for(p=1; <= cNumberNonGaiaPlayers) {
		xAddDatabaseBlock(dPlayerData, true);
	}
}

rule CostofLevels
active
highFrequency
{
	xsDisableSelf();
	//DRILL UPGRADES
	trQuestVarSet("DrillCostL2", 10);
	trQuestVarSet("DrillCostL3", 30);
	trQuestVarSet("DrillPowerL1", 10);
	trQuestVarSet("DrillPowerL2", 25);
	trQuestVarSet("DrillPowerL3", 47);
	trStringQuestVarSet("DrillL1", "Iron Drill");
	trStringQuestVarSet("DrillL2", "Steel Drill");
	trStringQuestVarSet("DrillL3", "Aluminium Drill");
	trQuestVarSet("DrillCostL4", 70);
	trQuestVarSet("DrillPowerL4", 70);
	trStringQuestVarSet("DrillL4", "Titanium Drill");
	trQuestVarSet("DrillCostL5", 125);
	trQuestVarSet("DrillPowerL5", 110);
	trStringQuestVarSet("DrillL5", "Osmium Drill");
	trQuestVarSet("DrillCostL6", 250);
	trQuestVarSet("DrillPowerL6", 200);
	trStringQuestVarSet("DrillL6", "Diamond Drill");
	trQuestVarSet("DrillCostL7", 500);
	trQuestVarSet("DrillPowerL7", 400);
	trStringQuestVarSet("DrillL7", "Nanotech Drill");
	trQuestVarSet("DrillCostL8", 500);
	trQuestVarSet("DrillPowerL8", 500);
	trStringQuestVarSet("DrillL8", "Plasma Drill");
	trQuestVarSet("DrillCostL9", 10000);
	trQuestVarSet("DrillPowerL9", 400);
	trStringQuestVarSet("DrillL9", "NOT MADE YET");
	
	//HULL UPGRADES
	trQuestVarSet("HullCostL2", 10);
	trQuestVarSet("HullCostL3", 40);
	trQuestVarSet("HullHPL1", 100);
	trQuestVarSet("HullHPL2", 300);
	trQuestVarSet("HullHPL3", 500);
	trStringQuestVarSet("HullL1", "Iron hull");
	trStringQuestVarSet("HullL2", "Plastic composite hull");
	trStringQuestVarSet("HullL3", "Aluminium hull");
	trQuestVarSet("HullCostL4", 100);
	trQuestVarSet("HullHPL4", 1000);
	trStringQuestVarSet("HullL4", "Tritanium hull");
	trQuestVarSet("HullCostL5", 150);
	trQuestVarSet("HullHPL5", 1750);
	trStringQuestVarSet("HullL5", "Carbon fibre hull");
	trQuestVarSet("HullCostL6", 300);
	trQuestVarSet("HullHPL6", 3000);
	trStringQuestVarSet("HullL6", "Shield hull");
	trQuestVarSet("HullCostL7", 500);
	trQuestVarSet("HullHPL7", 5000);
	trStringQuestVarSet("HullL7", "Electromagnetic hull");
	trQuestVarSet("HullCostL8", 500);
	trQuestVarSet("HullHPL8", 7000);
	trStringQuestVarSet("HullL8", "Dimondium hull");
	trQuestVarSet("HullCostL9", 10000);
	trQuestVarSet("HullHPL9", 5000);
	trStringQuestVarSet("HullL9", "NOT MADE YET");
	
	//Fuel UPGRADES
	trQuestVarSet("FuelCostL2", 10);
	trQuestVarSet("FuelCostL3", 40);
	trQuestVarSet("FuelCL1", 1000);
	trQuestVarSet("FuelCL2", 1250);
	trQuestVarSet("FuelCL3", 1500);
	trStringQuestVarSet("FuelL1", "Standard tank");
	trStringQuestVarSet("FuelL2", "Injector tank");
	trStringQuestVarSet("FuelL3", "Vacuum tank");
	trQuestVarSet("FuelCostL4", 80);
	trQuestVarSet("FuelCL4", 2000);
	trStringQuestVarSet("FuelL4", "Compression tank");
	trQuestVarSet("FuelCostL5", 100);
	trQuestVarSet("FuelCL5", 2500);
	trStringQuestVarSet("FuelL5", "Crucible tank");
	trQuestVarSet("FuelCostL6", 300);
	trQuestVarSet("FuelCL6", 3200);
	trStringQuestVarSet("FuelL6", "Juggernaut tank");
	trQuestVarSet("FuelCostL7", 400);
	trQuestVarSet("FuelCL7", 4000);
	trStringQuestVarSet("FuelL7", "Oceanic tank");
	trQuestVarSet("FuelCostL8", 400);
	trQuestVarSet("FuelCL8", 5000);
	trStringQuestVarSet("FuelL8", "Whirlpool extraction tank");
	trQuestVarSet("FuelCostL9", 10000);
	trQuestVarSet("FuelCL9", 4000);
	trStringQuestVarSet("FuelL9", "NOT MADE YET");
	
	//Cargo UPGRADES
	trQuestVarSet("CargoCostL2", 10);
	trQuestVarSet("CargoCostL3", 25);
	trQuestVarSet("CargoCL1", 2);
	trQuestVarSet("CargoCL2", 3);
	trQuestVarSet("CargoCL3", 4);
	trStringQuestVarSet("CargoL1", "Micro hold");
	trStringQuestVarSet("CargoL2", "Standard hold");
	trStringQuestVarSet("CargoL3", "Medium Hold");
	trQuestVarSet("CargoCostL4", 100);
	trQuestVarSet("CargoCL4", 6);
	trStringQuestVarSet("CargoL4", "Expanded Hold");
	trQuestVarSet("CargoCostL5", 150);
	trQuestVarSet("CargoCL5", 7);
	trStringQuestVarSet("CargoL5", "Multi-Slot Hold");
	trQuestVarSet("CargoCostL6", 200);
	trQuestVarSet("CargoCL6", 8);
	trStringQuestVarSet("CargoL6", "Tetris Hold");
	trQuestVarSet("CargoCostL7", 230);
	trQuestVarSet("CargoCL7", 9);
	trStringQuestVarSet("CargoL7", "4D Hold");
	trQuestVarSet("CargoCostL8", 300);
	trQuestVarSet("CargoCL8", 10);
	trStringQuestVarSet("CargoL8", "Singularity Hold");
	trQuestVarSet("CargoCostL9", 10000);
	trQuestVarSet("CargoCL9", 9);
	trStringQuestVarSet("CargoL9", "NOT MADE YET");
	
	//Engine UPGRADES
	trQuestVarSet("EngineCostL2", 10);
	trQuestVarSet("EngineCostL3", 35);
	trQuestVarSet("EngineCL1", 10);
	trQuestVarSet("EngineCL2", 20);
	trQuestVarSet("EngineCL3", 35);
	trStringQuestVarSet("EngineL1", "Hamsterwheel engine");
	trStringQuestVarSet("EngineL2", "Horsepower engine");
	trStringQuestVarSet("EngineL3", "Donkeywork engine");
	trQuestVarSet("EngineCostL4", 90);
	trQuestVarSet("EngineCL4", 75);
	trStringQuestVarSet("EngineL4", "Zebraforce engine");
	trQuestVarSet("EngineCostL5", 110);
	trQuestVarSet("EngineCL5", 110);
	trStringQuestVarSet("EngineL5", "Crocodileslam engine");
	trQuestVarSet("EngineCostL6", 250);
	trQuestVarSet("EngineCL6", 150);
	trStringQuestVarSet("EngineL6", "Tyrannosauruschomp engine");
	trQuestVarSet("EngineCostL7", 330);
	trQuestVarSet("EngineCL7", 180);
	trStringQuestVarSet("EngineL7", "Megalodongnaw engine");
	trQuestVarSet("EngineCostL8", 350);
	trQuestVarSet("EngineCL8", 200);
	trStringQuestVarSet("EngineL8", "Squidpull engine");
	trQuestVarSet("EngineCostL9", 10000);
	trQuestVarSet("EngineCL9", 180);
	trStringQuestVarSet("EngineL9", "NOT MADE YET");
	
	//Radiator UPGRADES
	trQuestVarSet("RadiatorCostL2", 10);
	trQuestVarSet("RadiatorCostL3", 30);
	trQuestVarSet("RadiatorCL1", 10);
	trQuestVarSet("RadiatorCL2", 15);
	trQuestVarSet("RadiatorCL3", 20);
	trStringQuestVarSet("RadiatorL1", "Basic Radiator");
	trStringQuestVarSet("RadiatorL2", "Ploddyphut Radiator");
	trStringQuestVarSet("RadiatorL3", "Wheezy Radiator");
	trQuestVarSet("RadiatorCostL4", 80);
	trQuestVarSet("RadiatorCL4", 30);
	trStringQuestVarSet("RadiatorL4", "Vitality Radiator");
	trQuestVarSet("RadiatorCostL5", 100);
	trQuestVarSet("RadiatorCL5", 40);
	trStringQuestVarSet("RadiatorL5", "Conduction Radiator");
	trQuestVarSet("RadiatorCostL6", 100);
	trQuestVarSet("RadiatorCL6", 47);
	trStringQuestVarSet("RadiatorL6", "Convection Radiator");
	trQuestVarSet("RadiatorCostL7", 200);
	trQuestVarSet("RadiatorCL7", 50);
	trStringQuestVarSet("RadiatorL7", "Equilibrium Radiator");
	trQuestVarSet("RadiatorCostL8", 400);
	trQuestVarSet("RadiatorCL8", 60);
	trStringQuestVarSet("RadiatorL8", "Thermal dissipation radiator");
	trQuestVarSet("RadiatorCostL9", 10000);
	trQuestVarSet("RadiatorCL9", 50);
	trStringQuestVarSet("RadiatorL9", "NOT MADE YET");
}
