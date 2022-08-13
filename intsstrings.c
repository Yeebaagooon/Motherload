//---Test controls
int QuickStart = 1;
bool OverrideSP = true;

//---
int Stage = 0;
int StageTime = 0;
int savedata = 0;
int loadProgress = 0;
int currentdata = 0;
string MapVersion = "Test Version";
string MapName = "Motherload.xs";
int MaxRows = 20;
int MaxCols = 25;
int GSeller = 0; //dont touch, does the player when selling minerals
vector GVectorSellPos = vector(5,3,180);
int TERRAIN_TYPE = 2;
int TERRAIN_SUBTYPE = 2;
int OVERTERRAIN_TYPE = 5;
int OVERTERRAIN_SUBTYPE = 4;
int CheckTime = 1;

int FuelCost = 0;
int FSOneXMin = 10;
int	FSOneXMax = 0;
int	FSOneZMin = 10;
int	FSOneZMax = 0;
int FSTwoXMin = 10;
int	FSTwoXMax = 0;
int	FSTwoZMin = 10;
int	FSTwoZMax = 0;

/* TERRAINS */
const int SandC = 1;
const int DirtA = 2;
const int SandDirt50 = 3;
const int SavannahC = 4;
const int SavannahD = 5;
const int CliffEgyptianB = 6;
const int CliffEgyptianA = 7;
const int IceC = 8;
const int Hades7 = 9;

/* TEMPORARY TEST VARS */
//float P1DrillPower = 10;


rule CostofLevels
active
highFrequency
{
	xsDisableSelf();
	//DRILL UPGRADES
	trQuestVarSet("DrillCostL2", 10);
	trQuestVarSet("DrillCostL3", 30);
	trQuestVarSet("DrillPowerL1", 10);
	trQuestVarSet("DrillPowerL2", 18);
	trQuestVarSet("DrillPowerL3", 30);
	trStringQuestVarSet("DrillL1", "Iron Drill");
	trStringQuestVarSet("DrillL2", "Steel Drill");
	trStringQuestVarSet("DrillL3", "Aluminium Drill");
	
	//HULL UPGRADES
	trQuestVarSet("HullCostL2", 10);
	trQuestVarSet("HullCostL3", 40);
	trQuestVarSet("HullHPL1", 100);
	trQuestVarSet("HullHPL2", 300);
	trQuestVarSet("HullHPL3", 500);
	trStringQuestVarSet("HullL1", "Iron hull");
	trStringQuestVarSet("HullL2", "Plastic composite hull");
	trStringQuestVarSet("HullL3", "Aluminium hull");
	
	//Fuel UPGRADES
	trQuestVarSet("FuelCostL2", 10);
	trQuestVarSet("FuelCostL3", 40);
	trQuestVarSet("FuelCL1", 1000);
	trQuestVarSet("FuelCL2", 1250);
	trQuestVarSet("FuelCL3", 1500);
	trStringQuestVarSet("FuelL1", "Standard tank");
	trStringQuestVarSet("FuelL2", "Injector tank");
	trStringQuestVarSet("FuelL3", "Vaccum tank");
	
	//Cargo UPGRADES
	trQuestVarSet("CargoCostL2", 10);
	trQuestVarSet("CargoCostL3", 25);
	trQuestVarSet("CargoCL1", 2);
	trQuestVarSet("CargoCL2", 3);
	trQuestVarSet("CargoCL3", 4);
	trStringQuestVarSet("CargoL1", "Micro hold");
	trStringQuestVarSet("CargoL2", "Standard hold");
	trStringQuestVarSet("CargoL3", "Medium Hold");
	
	//Engine UPGRADES
	trQuestVarSet("EngineCostL2", 10);
	trQuestVarSet("EngineCostL3", 35);
	trQuestVarSet("EngineCL1", 10);
	trQuestVarSet("EngineCL2", 20);
	trQuestVarSet("EngineCL3", 35);
	trStringQuestVarSet("EngineL1", "Hamsterwheel engine");
	trStringQuestVarSet("EngineL2", "Horsepower engine");
	trStringQuestVarSet("EngineL3", "Zebraforce engine");
	
	//Radiator UPGRADES
	trQuestVarSet("RadiatorCostL2", 10);
	trQuestVarSet("RadiatorCostL3", 30);
	trQuestVarSet("RadiatorCL1", 10);
	trQuestVarSet("RadiatorCL2", 15);
	trQuestVarSet("RadiatorCL3", 20);
	trStringQuestVarSet("RadiatorL1", "Basic Radiator");
	trStringQuestVarSet("RadiatorL2", "Ploddyphut Radiator");
	trStringQuestVarSet("RadiatorL3", "Wheezy Radiator");
}
