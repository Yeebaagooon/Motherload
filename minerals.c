/* MINERALS */
const int RELIC_IRON = 1;
const int RELIC_BRONZE = 2;
const int RELIC_SILVER = 3;
const int RELIC_GOLD = 4;

string relicName(int relic = 0) {
	string msg = "WTF That's not a relic!";
	switch(relic)
	{
		case RELIC_IRON:
		{
			msg = "Iron";
		}
		case RELIC_BRONZE:
		{
			msg = "Bronze";
		}
		case RELIC_SILVER:
		{
			msg = "Silver";
		}
		case RELIC_GOLD:
		{
			msg = "Gold";
		}
	}
	return(msg);
}

int relicCost(int relic = 0) {
	int price = 0;
	switch(relic)
	{
		case RELIC_IRON:
		{
			price = 1;
		}
		case RELIC_BRONZE:
		{
			price = 2;
		}
		case RELIC_SILVER:
		{
			price = 3;
		}
		case RELIC_GOLD:
		{
			price = 5;
		}
	}
	return(price);
}

string relicIcon(int relic = 0) {
	string icon = "icons\infantry g hoplite icon 64";
	switch(relic)
	{
		case RELIC_IRON:
		{
			icon = "icons\villager x male icons 64";
		}
		case RELIC_BRONZE:
		{
			icon = "icons\villager x male icons 64";
		}
		case RELIC_SILVER:
		{
			icon = "icons\villager x male icons 64";
		}
		case RELIC_GOLD:
		{
			icon = "icons\villager x male icons 64";
		}
	}
	return(icon);
}

void relicDescription(int relic = 0) {
	string icon = relicIcon(relic);
	string msg = relicName(relic);
	string textgap = " - Value = ";
	int price = relicCost(relic);
	string message = msg + textgap + price;
	trShowImageDialog(icon, message);
}

//declare the db first
int dRelicUnits = 0;
int xRelicName = 0;
int xRelicValue = 0;

rule setup_databases
active
highFrequency
{
	dRelicUnits = xInitDatabase("Relics"); //db name
	xRelicName = xInitAddInt(dRelicUnits, "name"); //unit name
	xRelicValue = xInitAddInt(dRelicUnits, "value", 1); //value of the relic, default to 1=iron
	//xRelicValue = xInitAddFloat(dRelicUnits, "value", 10.0); //float value of the relic
	/*
	trQuestVarSet("TEMP", trGetNextUnitScenarioNameNumber());
	trArmyDispatch("0,0", "Dwarf", 1,1,0,1,0,true);
	xAddDatabaseBlock(dRelicUnits, true);
	xSetInt(dRelicUnits, xRelicName, 1*trQuestVarGet("TEMP"));
	*/
	xsDisableSelf();
}

void spawnRelicSpecific(vector v = vector (0,0,0), int val = 1){
	trQuestVarSet("TEMP", trGetNextUnitScenarioNameNumber());
	trArmyDispatch("0,0", "Dwarf", 1,xsVectorGetX(v),0,xsVectorGetZ(v),0,true);
	xAddDatabaseBlock(dRelicUnits, true);
	xSetInt(dRelicUnits, xRelicName, 1*trQuestVarGet("TEMP"));
	xSetInt(dRelicUnits, xRelicValue, val);
	trUnitSelectClear();
	trUnitSelectByQV("TEMP");
	trUnitChangeProtoUnit("Relic");
	trChatSend(0, "Free relics = "+xGetDatabaseCount(dRelicUnits)+"");
}

void reselectMyself() {
	uiClearSelection();
	/*
	int p = trCurrentPlayer();
	int class = xGetInt(dPlayerData, xPlayerClass, p);
	trackInsert();
	trackAddWaypoint();
	trackAddWaypoint();
	trBlockAllSounds(false);
	uiFindType(kbGetProtoUnitName(xGetInt(dClass, xClassProto, class)));
	trackPlay(1,999);
	*/
}

void processFreeRelics(int count = 1) {
	float amt = 0;
	int db = 0;
	vector pos = vector(0,0,0);
	for (x=xsMin(count, xGetDatabaseCount(dRelicUnits)); > 0) {
		amt = 0;
		xDatabaseNext(dRelicUnits);
		xUnitSelect(dRelicUnits, xRelicName);
		//STARRED CODE HERE AND BELOW ELSEIF
		if(trUnitIsSelected()) {
			//trShowImageDialog(relicIcon(xGetInt(dRelicUnits, xRelicValue)), relicName(xGetInt(dRelicUnits, xRelicValue)));
			relicDescription(xGetInt(dRelicUnits, xRelicValue));
			reselectMyself();
		}
	}
}

rule eternal_loops
active
highFrequency
{
	processFreeRelics(5);
	//trChatSend(0, "Free relics = "+xGetDatabaseCount(dRelicUnits)+"");
}
