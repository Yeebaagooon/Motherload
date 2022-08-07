//---Test controls
int QuickStart = 1;
bool OverrideSP = false;

//---
int Stage = 0;
int StageTime = 0;
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
	trQuestVarSet("DrillCostL2", 25);
	trQuestVarSet("DrillCostL3", 50);
	trQuestVarSet("DrillPowerL1", 10);
	trQuestVarSet("DrillPowerL2", 15);
	trQuestVarSet("DrillPowerL3", 20);
	trStringQuestVarSet("DrillL1", "Iron Drill");
	trStringQuestVarSet("DrillL2", "Steel Drill");
	trStringQuestVarSet("DrillL3", "Aluminium Drill");
}
