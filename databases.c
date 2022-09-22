//declare the db first
int dFreeRelics = 0;
int dHeldRelics = 0;
int dHiddenRelics = 0;
int xRelicName = 0;
int xRelicValue = 0;
int xRelicTick = 50;
int xRelicDamage = 0;
int xOwner = 0;
//int xRelicPrice = 0;

int dSelectables = 0;
int xSelectablesName = 0;
int xSelectablesPrompt = 0;

int dGasPocket = 0;
int xGasCol = 0;
int xGasRow = 0;

int dDestroyMe = 0;
int xDestroyName = 0;
int xDestroyTime = 0;

int dSpaceHull = 0;
int xSpaceRow = 0;
int xSpaceCol = 0;

int dSpace = 0;
int xSpaceName = 0;

int spysearch = 0;
int spyreset = 0;
int spyProto = 0;
int spyUnit = 1;
int spyDest = 2;
int spyScale = 3;
int spyActive = 4;
int spyAnim = 5;

//traps
int dTrap = 0;
int xTrapXMin = 0;
int xTrapZMin = 0;
int xTrapXMax = 0;
int xTrapZMax = 0;
int xTrapType = 0;
int xTrapOn = 0;
int xTrapReady = 0;
int xTrapReset = 0;
int xTrapResetTime = 0;
int xTrapUnit = 0;
int xTrapStartVector = 0;
int xTrapTargetVector = 0;
int xTrapHitVector = 0;
int xTrapHitboxX = 0;
int xTrapHitboxZ = 0;

int dKey = 0;
int xKey = 0;
int xKeyUnitName = 0;

rule setup_databases
active
highFrequency
{
	//RELIC DATABASES
	dFreeRelics = xInitDatabase("FreeRelics"); //db name
	xRelicName = xInitAddInt(dFreeRelics, "name"); //unit name
	xRelicValue = xInitAddInt(dFreeRelics, "value", 1); //value of the relic, default to 1=iron
	xRelicTick = xInitAddInt(dFreeRelics, "tick", 50);
	xRelicDamage = xInitAddInt(dFreeRelics, "damage", 0);
	dHeldRelics = xInitDatabase("HeldRelics"); //db name
	xRelicName = xInitAddInt(dHeldRelics, "name"); //unit name
	xRelicValue = xInitAddInt(dHeldRelics, "value", 1); //value of the relic, default to 1=iron
	xRelicTick = xInitAddInt(dHeldRelics, "tick", 50);
	xRelicDamage = xInitAddInt(dHeldRelics, "damage", 0);
	dHiddenRelics = xInitDatabase("HiddenRelics"); //db name
	xRelicName = xInitAddInt(dHiddenRelics, "name"); //unit name
	xRelicValue = xInitAddInt(dHiddenRelics, "value", 1); //value of the relic, default to 1=iron
	xRelicTick = xInitAddInt(dHiddenRelics, "tick", 50);
	xRelicDamage = xInitAddInt(dHiddenRelics, "damage", 0);
	xOwner = xInitAddInt(dHiddenRelics, "owner", 0); //value of the relic, default to 0
	xsDisableSelf();
	//Obelisk Stage DB
	dObelisks = xInitDatabase("Obelisks");
	xObeliskName = xInitAddInt(dObelisks, "name"); //unit name
	xObeliskStage = xInitAddInt(dObelisks, "stage");
	//Selectables DB
	dSelectables = xInitDatabase("Selectables");
	xSelectablesName = xInitAddInt(dSelectables, "name"); //unit name
	xSelectablesPrompt = xInitAddInt(dSelectables, "prompt", 0);
	//Eyecandy DB
	dPlanetEyecandy = xInitDatabase("PlanetEyecandy");
	xPlanetEyecandyName = xInitAddInt(dPlanetEyecandy, "name"); //unit name
	xPlanetEyecandyStage = xInitAddInt(dPlanetEyecandy, "stage");
	
	dSpace = xInitDatabase("SpaceEyecandy");
	xSpaceName = xInitAddInt(dSpace, "name"); //unit name
	
	//GasPockets
	dGasPocket = xInitDatabase("GasPocket");
	xGasRow = xInitAddInt(dGasPocket, "gasrow", 0);
	xGasCol = xInitAddInt(dGasPocket, "gascol", 0);
	
	//Space tiles
	dSpaceHull = xInitDatabase("Space Hull");
	xSpaceCol = xInitAddInt(dSpaceHull, "col", 0);
	xSpaceRow = xInitAddInt(dSpaceHull, "Row", 0);
	
	dDestroyMe = xInitDatabase("Destroy");
	xDestroyName = xInitAddInt(dDestroyMe, "unitname");
	xDestroyTime = xInitAddInt(dDestroyMe, "timetodie", 1500);
	
	//Trap DB
	dTrap = xInitDatabase("Traps");
	xTrapXMin = xInitAddInt(dTrap, "TrapXMin");
	xTrapZMin = xInitAddInt(dTrap, "TrapZMin");
	xTrapXMax = xInitAddInt(dTrap, "TrapXMax");
	xTrapZMax = xInitAddInt(dTrap, "TrapZMax");
	xTrapType = xInitAddInt (dTrap, "Trap type");
	xTrapOn = xInitAddBool (dTrap, "On", true);
	xTrapReady = xInitAddBool (dTrap, "Ready", true);
	xTrapReset = xInitAddInt(dTrap, "Reset delay", 10);
	xTrapResetTime = xInitAddInt(dTrap, "Reset time", 10);
	xTrapUnit = xInitAddInt (dTrap, "Trap unit ID");
	xTrapStartVector = xInitAddVector(dTrap, "Start vector");
	xTrapTargetVector = xInitAddVector(dTrap, "Target vector");
	xTrapHitVector = xInitAddVector(dTrap, "Hitbox centre vector");
	xTrapHitboxX = xInitAddInt (dTrap, "Hitbox X");
	xTrapHitboxZ = xInitAddInt (dTrap, "Hitbox Z");
	
	//KEy DB
	dKey = xInitDatabase("Key");
	xKey = xInitAddInt(dKey, "Key ID");
	xKeyUnitName = xInitAddInt(dKey, "Key eyecandy name");
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


rule initialise_spy_database
active
highFrequency
{
	xsDisableSelf();
	xsSetContextPlayer(0);
	modularCounterInit("spyFind", 63);
	modularCounterInit("spyFound", 63);
	spyProto = zNewArray(mInt,64,"spyProto");
	spyUnit = zNewArray(mInt,64,"spyUnit");
	spyDest = zNewArray(mVector,64,"spyDest");
	spyScale = zNewArray(mVector,64,"spyScale");
	spyActive = zNewArray(mBool,64,"spyActive");
	spyAnim = zNewArray(mInt,64,"spyAnim");
}

void spyEffect(int unit = 0, int proto = 0, vector dest = vector(0,0,0), vector scale = vector(1,1,1), int anim = 0) {
	if (peekModularCounterNext("spyFind") != trQuestVarGet("spyFound")) {
		trUnitSelectClear();
		trUnitSelect(""+unit, true);
		if (trUnitAlive()) {
			int x = modularCounterNext("spyFind");
			aiPlanSetUserVariableInt(ARRAYS,spyProto,x,proto);
			aiPlanSetUserVariableInt(ARRAYS,spyUnit,x,unit);
			aiPlanSetUserVariableBool(ARRAYS,spyActive,x,true);
			aiPlanSetUserVariableVector(ARRAYS,spyDest,x,dest);
			aiPlanSetUserVariableVector(ARRAYS,spyScale,x,scale);
			aiPlanSetUserVariableInt(ARRAYS,spyAnim,x,anim);
			trBlockAllSounds();
			trTechInvokeGodPower(0, "spy", vector(0,0,0), vector(0,0,0));
			trUnblockAllSounds();
		}
	} else {
		debugLog("Spy buffer overflow");
	}
}

rule spy_find
active
highFrequency
{
	int x = 0;
	int id = 0;
	vector scale = vector(0,0,0);
	vector dest = vector(0,0,0);
	while(spysearch < trGetNextUnitScenarioNameNumber()) {
		id = kbGetBlockID(""+spysearch, true);
		if (kbGetUnitBaseTypeID(id) == kbGetProtoUnitID("Spy Eye")) {
			x = modularCounterNext("spyfound");
			if (aiPlanGetUserVariableBool(ARRAYS,spyActive,x)) {
				spyreset = 0;
				aiPlanSetUserVariableBool(ARRAYS,spyActive,x,false);
				trUnitSelectClear();
				trUnitSelect(""+aiPlanGetUserVariableInt(ARRAYS,spyUnit,x),true);
				dest = aiPlanGetUserVariableVector(ARRAYS,spyDest,x);
				if (trUnitAlive() == false) {
					if (aiPlanSetUserVariableInt(1*xsVectorGetX(dest),1*xsVectorGetY(dest),1*xsVectorGetZ(dest),-1) == false) {
						debugLog("spy error dead: " + 1*xsVectorGetX(dest) + "," + 1*xsVectorGetY(dest) + "," + 1*xsVectorGetZ(dest));
					}
				} else {
					trUnitSelectClear();
					trUnitSelectByID(id);
					trMutateSelected(aiPlanGetUserVariableInt(ARRAYS,spyProto,x));
					scale = aiPlanGetUserVariableVector(ARRAYS,spyScale,x);
					trSetSelectedScale(xsVectorGetX(scale),xsVectorGetY(scale),xsVectorGetZ(scale));
					trUnitSelectClear();
					trUnitSelectByID(id);
					int anim = aiPlanGetUserVariableInt(ARRAYS,spyAnim,x);
					if(anim != 0){
						trUnitOverrideAnimation(anim, 0, false, false, -1, 0);
					}
					if (aiPlanSetUserVariableInt(1*xsVectorGetX(dest),1*xsVectorGetY(dest),1*xsVectorGetZ(dest),spysearch) == false) {
						//Zeno uses a vector as unit ID in an array
						//debugLog("spy error N/A: " + 1*xsVectorGetX(dest) + "," + 1*xsVectorGetY(dest) + "," + 1*xsVectorGetZ(dest));
					}
				}
			}
		}
		spysearch = 1 + spysearch;
	}
	if (trQuestVarGet("spyfind") != trQuestVarGet("spyfound")) {
		spyreset = 1 + spyreset;
		if (spyreset >= 5) {
			while (trQuestVarGet("spyfind") != trQuestVarGet("spyfound")) {
				x = modularCounterNext("spyFound");
				if (aiPlanGetUserVariableBool(ARRAYS,spyActive,x)) {
					aiPlanSetUserVariableBool(ARRAYS,spyActive,x,false);
					aiPlanSetUserVariableInt(xsVectorGetX(dest),xsVectorGetY(dest),xsVectorGetZ(dest),-1);
				}
			}
			debugLog("resetting spyfound");
		}
	} else {
		spyreset = 0;
	}
}
