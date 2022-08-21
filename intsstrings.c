//--SUGGESTIONS
/*
*Highlight Earths for sexier bg effect
*Auto sell
*/


//---Test controls
int QuickStart = 0;
bool OverrideSP = true;
bool OverrideStage = true;

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
int GVortex = 0;
vector GVectorSellPos = vector(5,3,180);
int TERRAIN_TYPE = 2;
int TERRAIN_SUBTYPE = 2;
int OVERTERRAIN_TYPE = 5;
int OVERTERRAIN_SUBTYPE = 4;
int CheckTime = 1;

float FuelCost = 0;
float FSOneXMin = 10;
float FSOneXMax = 0;
float FSOneZMin = 10;
float FSOneZMax = 0;
float FSTwoXMin = 10;
float FSTwoXMax = 0;
float FSTwoZMin = 10;
float FSTwoZMax = 0;
float Hull1XMin = 10;
float Hull1XMax = 0;
float Hull2XMin = 10;
float Hull2XMax = 0;

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
	trQuestVarSet("DrillCostL4", 60);
	trQuestVarSet("DrillPowerL4", 47);
	trStringQuestVarSet("DrillL4", "Titanium Drill");
	
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
	trStringQuestVarSet("HullL4", "Titanium hull");
	
	//Fuel UPGRADES
	trQuestVarSet("FuelCostL2", 10);
	trQuestVarSet("FuelCostL3", 40);
	trQuestVarSet("FuelCL1", 1000);
	trQuestVarSet("FuelCL2", 1250);
	trQuestVarSet("FuelCL3", 1500);
	trStringQuestVarSet("FuelL1", "Standard tank");
	trStringQuestVarSet("FuelL2", "Injector tank");
	trStringQuestVarSet("FuelL3", "Vaccum tank");
	trQuestVarSet("FuelCostL4", 80);
	trQuestVarSet("FuelCL4", 2000);
	trStringQuestVarSet("FuelL4", "Compression tank");
	
	//Cargo UPGRADES
	trQuestVarSet("CargoCostL2", 10);
	trQuestVarSet("CargoCostL3", 25);
	trQuestVarSet("CargoCL1", 2);
	trQuestVarSet("CargoCL2", 3);
	trQuestVarSet("CargoCL3", 4);
	trStringQuestVarSet("CargoL1", "Micro hold");
	trStringQuestVarSet("CargoL2", "Standard hold");
	trStringQuestVarSet("CargoL3", "Medium Hold");
	trQuestVarSet("CargoCostL4", 70);
	trQuestVarSet("CargoCL4", 6);
	trStringQuestVarSet("CargoL4", "Expanded Hold");
	
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
}
