const int RELIC_NUMBER = 21;

const int RELIC_IRON = 1;
const int RELIC_BRONZE = 2;
const int RELIC_SILVER = 3;
const int RELIC_GOLD = 4;
const int RELIC_PLATINUM = 5;
const int RELIC_URANIUM = 6;
const int RELIC_RUBY = 7;
const int RELIC_SAPPHIRE = 8;
const int RELIC_DIAMOND = 9;
const int RELIC_PROMETHIUM = 10;
const int RELIC_EINSTEINIUM = 11;
const int RELIC_EMERALD = 12;
const int RELIC_AMETHYST = 13;
const int RELIC_OBSIDIAN = 14;
const int RELIC_TOPAZ = 15;
const int RELIC_ICE = 16;
const int RELIC_QUARTZ = 17;
const int RELIC_OPAL = 18;
const int RELIC_HYDROGEN = 19;
const int RELIC_ANTIMATTER = 20;
const int RELIC_YEEBIUM = 21;

const int RELIC_KEY_CHINA = 22;
const int RELIC_KEY_GREEK = 23;
const int RELIC_KEY_NORSE = 24;
const int RELIC_KEY_EGYPT = 25;
const int RELIC_KEY_ATLANTEAN = 26;

const int RELIC_RELIGION = 27;
const int RELIC_SKELETON = 28;
const int RELIC_RUINS = 29;
const int RELIC_SHIP = 30;

const int RELIC_FUEL = 31;
const int RELIC_HULL = 32;


const int URANIUM_DAMAGE = 1;
const int PROMETHIUM_DAMAGE = 2;
const int EINSTEINIUM_DAMAGE = 3;
const int HYDROGEN_DAMAGE = 4;
const int ANTIMATTER_DAMAGE = 10;

string relicName(int relic = 0) {
	string msg = "WTF That's not a relic!";
	if ((relic >= RELIC_KEY_CHINA) && (relic <= RELIC_KEY_ATLANTEAN)) {
		msg = "A key that opens something";
	}
	else{
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
			case RELIC_PLATINUM:
			{
				msg = "Platinum";
			}
			case RELIC_URANIUM:
			{
				msg = "Uranium";
			}
			case RELIC_RUBY:
			{
				msg = "Ruby";
			}
			case RELIC_SAPPHIRE:
			{
				msg = "Sapphire";
			}
			case RELIC_DIAMOND:
			{
				msg = "Diamond";
			}
			case RELIC_PROMETHIUM:
			{
				msg = "Promethium";
			}
			case RELIC_EINSTEINIUM:
			{
				msg = "Einsteinium";
			}
			case RELIC_EMERALD:
			{
				msg = "Emerald";
			}
			case RELIC_AMETHYST:
			{
				msg = "Amethyst";
			}
			case RELIC_OBSIDIAN:
			{
				msg = "Obsidian";
			}
			case RELIC_TOPAZ:
			{
				msg = "Topaz";
			}
			case RELIC_ICE:
			{
				msg = "Ice Core";
			}
			case RELIC_QUARTZ:
			{
				msg = "Quartz";
			}
			case RELIC_OPAL:
			{
				msg = "Opal";
			}
			case RELIC_HYDROGEN:
			{
				msg = "Hydrogen Ice";
			}
			case RELIC_ANTIMATTER:
			{
				msg = "Antimatter";
			}
			case RELIC_YEEBIUM:
			{
				msg = "Yeebium";
			}
			case RELIC_RELIGION:
			{
				msg = "Religious artefact";
			}
			case RELIC_SKELETON:
			{
				msg = "A mysterious skeleton";
			}
			case RELIC_RUINS:
			{
				msg = "Ruins of an ancient civilisation";
			}
			case RELIC_SHIP:
			{
				msg = "Destroyed ship of former player";
			}
			case RELIC_FUEL:
			{
				msg = "Spare fuel";
			}
			case RELIC_HULL:
			{
				msg = "Hull repair nanobots";
			}
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
		case RELIC_PLATINUM:
		{
			price = 7;
		}
		case RELIC_URANIUM:
		{
			price = 9;
		}
		case RELIC_RUBY:
		{
			price = 10;
		}
		case RELIC_SAPPHIRE:
		{
			price = 12;
		}
		case RELIC_DIAMOND:
		{
			price = 15;
		}
		case RELIC_PROMETHIUM:
		{
			price = 15;
		}
		case RELIC_EINSTEINIUM:
		{
			price = 20;
		}
		case RELIC_EMERALD:
		{
			price = 13;
		}
		case RELIC_AMETHYST:
		{
			price = 14;
		}
		case RELIC_OBSIDIAN:
		{
			price = 20;
		}
		case RELIC_TOPAZ:
		{
			price = 25;
		}
		case RELIC_ICE:
		{
			price = 30;
		}
		case RELIC_QUARTZ:
		{
			price = 35;
		}
		case RELIC_OPAL:
		{
			price = 40;
		}
		case RELIC_HYDROGEN:
		{
			price = 50;
		}
		case RELIC_ANTIMATTER:
		{
			price = 250;
		}
		case RELIC_YEEBIUM:
		{
			price = 1000;
		}
		case RELIC_RELIGION:
		{
			price = 10;
		}
		case RELIC_SKELETON:
		{
			price = 25;
		}
		case RELIC_RUINS:
		{
			price = 60;
		}
		case RELIC_SHIP:
		{
			price = 90;
		}
	}
	return(price);
}

string RelicColour(int relic = 0) {
	string colour = "1,1,1";
	switch(relic)
	{
		case RELIC_IRON:
		{
			colour = "0.22,0.25,0.23";
		}
		case RELIC_BRONZE:
		{
			colour = "0.69,0.55,0.34";
		}
		case RELIC_SILVER:
		{
			colour = "0.66,0.66,0.66";
		}
		case RELIC_GOLD:
		{
			colour = "0.83,0.68,0.21";
		}
		case RELIC_PLATINUM:
		{
			colour = "1,1,1";
		}
		case RELIC_URANIUM:
		{
			colour = "0.08,0.84,0.2";
		}
		case RELIC_RUBY:
		{
			colour = "0.68,0,0.11";
		}
		case RELIC_SAPPHIRE:
		{
			colour = "0,0.44,1";
		}
		case RELIC_DIAMOND:
		{
			colour = "1,1,1";
		}
		case RELIC_PROMETHIUM:
		{
			colour = "0.26,0.88,0.6";
		}
		case RELIC_EINSTEINIUM:
		{
			colour = "0.01,0.27,0.76";
		}
		case RELIC_EMERALD:
		{
			colour = "0.01,0.47,0.09";
		}
		case RELIC_AMETHYST:
		{
			colour = "0.38,0.04,0.38";
		}
		case RELIC_OBSIDIAN:
		{
			colour = "0.01,0.01,0.01";
		}
		case RELIC_TOPAZ:
		{
			colour = "0.98,0.89,0.23";
		}
		case RELIC_ICE:
		{
			colour = "0.65,0.79,0.87";
		}
		case RELIC_QUARTZ:
		{
			colour = "0.95,0.76,0.8";
		}
		case RELIC_OPAL:
		{
			colour = "0.47,0.04,0";
		}
		case RELIC_HYDROGEN:
		{
			colour = "0.64,0.56,0.87";
		}
		case RELIC_ANTIMATTER:
		{
			colour = "0.91,0.89,0.81";
		}
		case RELIC_YEEBIUM:
		{
			colour = "1,0.47,0";
		}
		case RELIC_RELIGION:
		{
			colour = "1,0,1";
		}
		case RELIC_SKELETON:
		{
			colour = "1,0,1";
		}
		case RELIC_RUINS:
		{
			colour = "1,0,1";
		}
		case RELIC_SHIP:
		{
			colour = "1,0,1";
		}
		case RELIC_FUEL:
		{
			colour = "0,1,0";
		}
		case RELIC_HULL:
		{
			colour = "0,1,0";
		}
	}
	return(colour);
}

string relicIcon(int relic = 0) {
	string icon = "icons\infantry g hoplite icon 64";
	if (1*trQuestVarGet("CustomContent") == 1){
		icon = "Yeebaagooon\Motherload\mineral" + relic;
		if(relic == RELIC_KEY_CHINA){
			icon = "ui range indicator chinese";
		}
		if(relic == RELIC_KEY_NORSE){
			icon = "ui range indicator norse";
		}
		if(relic == RELIC_KEY_ATLANTEAN){
			icon = "ui range indicator atlantean";
		}
		if(relic == RELIC_KEY_EGYPT){
			icon = "ui range indicator egypt";
		}
		if(relic == RELIC_KEY_GREEK){
			icon = "ui range indicator greek";
		}
		return(icon);
	}
	else{
		switch(relic)
		{
			case RELIC_IRON:
			{
				icon = "icons\scenario thors hammer icon 64";
			}
			case RELIC_BRONZE:
			{
				icon = "icons\special x behemoth icons 64";
			}
			case RELIC_SILVER:
			{
				icon = "icons\special x automaton icons 64";
			}
			case RELIC_GOLD:
			{
				icon = "icons\special n battle boar icon 64";
			}
			case RELIC_PLATINUM:
			{
				icon = "icons\hero g bellerophon icon 64";
			}
			case RELIC_URANIUM:
			{
				icon = "icons\special g medusa icon 64";
			}
			case RELIC_RUBY:
			{
				icon = "icons\special g manticore icon 64";
			}
			case RELIC_SAPPHIRE:
			{
				icon = "icons\special x servant icons 64";
			}
			case RELIC_DIAMOND:
			{
				icon = "icons\building lighthouse icon 64";
			}
			case RELIC_PROMETHIUM:
			{
				icon = "icons\special x promethean icons 64";
			}
			case RELIC_EINSTEINIUM:
			{
				icon = "icons\hero g physician icon";
			}
			case RELIC_EMERALD:
			{
				icon = "icons\special x argus icons 64";
			}
			case RELIC_AMETHYST:
			{
				icon = "icons\special x lampades icons 64";
			}
			case RELIC_OBSIDIAN:
			{
				icon = "icons\scenario c danzhu icon";
			}
			case RELIC_TOPAZ:
			{
				icon = "icons\special g nemean lion icon 64";
			}
			case RELIC_ICE:
			{
				icon = "icons\special n frost giant icon 64";
			}
			case RELIC_QUARTZ:
			{
				icon = "icons\special c vermilion bird icon";
			}
			case RELIC_OPAL:
			{
				icon = "icons\special c qilin icon";
			}
			case RELIC_HYDROGEN:
			{
				icon = "icons\special n fire giant icon 64";
			}
			case RELIC_ANTIMATTER:
			{
				icon = "icons\icon building wonder 64";
			}
			case RELIC_YEEBIUM:
			{
				icon = "icons\special e son of osiris icon 64";
			}
			case RELIC_KEY_CHINA:
			{
				icon = "ui range indicator chinese";
			}
			case RELIC_KEY_NORSE:
			{
				icon = "ui range indicator norse";
			}
			case RELIC_KEY_ATLANTEAN:
			{
				icon = "ui range indicator atlantean";
			}
			case RELIC_KEY_EGYPT:
			{
				icon = "ui range indicator egypt";
			}
			case RELIC_KEY_GREEK:
			{
				icon = "ui range indicator greek";
			}
			case RELIC_RELIGION:
			{
				icon = "ankh";
			}
			case RELIC_SKELETON:
			{
				icon = "animal chicken corpse skeletona";
			}
			case RELIC_RUINS:
			{
				icon = "ui\overlay_ruins_12";
			}
			case RELIC_SHIP:
			{
				icon = "siege x fire siphon corpse bodya";
			}
			case RELIC_FUEL:
			{
				icon = "icons\improvement murder holes icon 64";
			}
			case RELIC_HULL:
			{
				icon = "icons\improvement murder holes icon 64";
			}
		}
		return(icon);
	}
}

int relicProto(int relic = 0) {
	int proto = kbGetProtoUnitID("Hoplite");
	switch(relic)
	{
		case RELIC_IRON:
		{
			proto = kbGetProtoUnitID("Thor Hammer Head");
		}
		case RELIC_BRONZE:
		{
			proto = kbGetProtoUnitID("Behemoth");
		}
		case RELIC_SILVER:
		{
			proto = kbGetProtoUnitID("Automaton SPC");
		}
		case RELIC_GOLD:
		{
			proto = kbGetProtoUnitID("Battle Boar");
		}
		case RELIC_PLATINUM:
		{
			proto = kbGetProtoUnitID("Hero Greek Bellerophon");
		}
		case RELIC_URANIUM:
		{
			proto = kbGetProtoUnitID("Medusa");
		}
		case RELIC_RUBY:
		{
			proto = kbGetProtoUnitID("Manticore");
		}
		case RELIC_SAPPHIRE:
		{
			proto = kbGetProtoUnitID("Servant");
		}
		case RELIC_DIAMOND:
		{
			proto = kbGetProtoUnitID("Lighthouse");
		}
		case RELIC_PROMETHIUM:
		{
			proto = kbGetProtoUnitID("Titan Prometheus");
		}
		case RELIC_EINSTEINIUM:
		{
			proto = kbGetProtoUnitID("Physician");
		}
		case RELIC_EMERALD:
		{
			proto = kbGetProtoUnitID("Argus");
		}
		case RELIC_AMETHYST:
		{
			proto = kbGetProtoUnitID("Lampades");
		}
		case RELIC_OBSIDIAN:
		{
			proto = kbGetProtoUnitID("Danzhu");
		}
		case RELIC_TOPAZ:
		{
			proto = kbGetProtoUnitID("Nemean Lion");
		}
		case RELIC_ICE:
		{
			proto = kbGetProtoUnitID("Frost Giant");
		}
		case RELIC_QUARTZ:
		{
			proto = kbGetProtoUnitID("Vermilion Bird");
		}
		case RELIC_OPAL:
		{
			proto = kbGetProtoUnitID("Qilin");
		}
		case RELIC_HYDROGEN:
		{
			proto = kbGetProtoUnitID("Fire Giant");
		}
		case RELIC_ANTIMATTER:
		{
			proto = kbGetProtoUnitID("Outpost");
		}
		case RELIC_YEEBIUM:
		{
			proto = kbGetProtoUnitID("Pharaoh of Osiris");
		}
		case RELIC_KEY_CHINA:
		{
			proto = kbGetProtoUnitID("UI Range Indicator Chinese SFX");
		}
		case RELIC_KEY_NORSE:
		{
			proto = kbGetProtoUnitID("UI Range Indicator Norse SFX");
		}
		case RELIC_KEY_ATLANTEAN:
		{
			proto = kbGetProtoUnitID("UI Range Indicator Atlantean SFX");
		}
		case RELIC_KEY_EGYPT:
		{
			proto = kbGetProtoUnitID("UI Range Indicator Egypt SFX");
		}
		case RELIC_KEY_GREEK:
		{
			proto = kbGetProtoUnitID("UI Range Indicator Greek SFX");
		}
	}
	return(proto);
}

void relicDescription(int relic = 0) {
	string icon = relicIcon(relic);
	string message = " ";
	if ((relic < RELIC_KEY_CHINA) || (relic > RELIC_KEY_ATLANTEAN)) {
		string msg = relicName(relic);
		string textgap = " - Value = ";
		int price = relicCost(relic);
		if (1*trQuestVarGet("CustomContent") == 0){
			message = msg + textgap + price;
		}
	}
	else{
		message = "A key that opens something";
	}
	if(relic == RELIC_FUEL){
		int fuelamount = xGetInt(dFreeRelics, xRelicTick);
		message = ""+fuelamount+"L spare fuel";
	}
	if(relic == RELIC_HULL){
		int hullamount = xGetInt(dFreeRelics, xRelicTick);
		message = "Hull repair nanobots - "+hullamount+"hp";
	}
	trShowImageDialog(icon, message);
}

void spawnFuelRelic(vector v = vector (0,0,0), int val = 100){
	trQuestVarSet("TEMPRELIC", trGetNextUnitScenarioNameNumber());
	trArmyDispatch(""+cNumberNonGaiaPlayers+",0", "Dwarf", 1,xsVectorGetX(v),0,xsVectorGetZ(v),0,true);
	xAddDatabaseBlock(dFreeRelics, true);
	xSetInt(dFreeRelics, xRelicName, 1*trQuestVarGet("TEMPRELIC"));
	xSetInt(dFreeRelics, xRelicValue, 31);
	xSetInt(dFreeRelics, xRelicTick, val);
	xSetInt(dFreeRelics, xRelicDamage, 0);
	trUnitSelectClear();
	trUnitSelectByQV("TEMPRELIC");
	if(aiIsMultiplayer() == true){
		trUnitChangeProtoUnit("Titan Atlantean");
	}
	trUnitChangeProtoUnit("Relic");
	if(aiIsMultiplayer() == true){
		yFindLatestReverse("TempRelicSFX", "Titan Gate Dead", cNumberNonGaiaPlayers);
		xSetInt(dFreeRelics, xSFX, 1*trQuestVarGet("TempRelicSFX"));
		//SPECIAL EFFECTS
		trUnitSelectByQV("TempRelicSFX");
		trUnitChangeProtoUnit("Spy Eye");
		trUnitSelectByQV("TempRelicSFX");
		trMutateSelected(kbGetProtoUnitID("Well of Urd"));
		trSetSelectedScale(0.1,0.5,0.1);
	}
}

void spawnHullRelic(vector v = vector (0,0,0), int val = 100){
	trQuestVarSet("TEMPRELIC", trGetNextUnitScenarioNameNumber());
	trArmyDispatch(""+cNumberNonGaiaPlayers+",0", "Dwarf", 1,xsVectorGetX(v),0,xsVectorGetZ(v),0,true);
	xAddDatabaseBlock(dFreeRelics, true);
	xSetInt(dFreeRelics, xRelicName, 1*trQuestVarGet("TEMPRELIC"));
	xSetInt(dFreeRelics, xRelicValue, 32);
	xSetInt(dFreeRelics, xRelicTick, val);
	xSetInt(dFreeRelics, xRelicDamage, 0);
	trUnitSelectClear();
	trUnitSelectByQV("TEMPRELIC");
	if(aiIsMultiplayer() == true){
		trUnitChangeProtoUnit("Titan Atlantean");
	}
	trUnitChangeProtoUnit("Relic");
	if(aiIsMultiplayer() == true){
		yFindLatestReverse("TempRelicSFX", "Titan Gate Dead", cNumberNonGaiaPlayers);
		xSetInt(dFreeRelics, xSFX, 1*trQuestVarGet("TempRelicSFX"));
		//SPECIAL EFFECTS
		trUnitSelectByQV("TempRelicSFX");
		trUnitChangeProtoUnit("Spy Eye");
		trUnitSelectByQV("TempRelicSFX");
		trMutateSelected(kbGetProtoUnitID("Timeshift in"));
		trUnitSelectByQV("TempRelicSFX");
		trUnitSetAnimationPath("0,1,1,0,1,0,0");
	}
}

void spawnRelicSpecific(vector v = vector (0,0,0), int val = 1){
	trQuestVarSet("TEMPRELIC", trGetNextUnitScenarioNameNumber());
	trArmyDispatch(""+cNumberNonGaiaPlayers+",0", "Dwarf", 1,xsVectorGetX(v),0,xsVectorGetZ(v),0,true);
	xAddDatabaseBlock(dFreeRelics, true);
	xSetInt(dFreeRelics, xRelicName, 1*trQuestVarGet("TEMPRELIC"));
	xSetInt(dFreeRelics, xRelicValue, val);
	xSetInt(dFreeRelics, xRelicTick, (trTimeMS()+50));
	if(xGetInt(dFreeRelics, xRelicValue) == RELIC_URANIUM){
		xSetInt(dFreeRelics, xRelicDamage, URANIUM_DAMAGE);
	}
	else if(xGetInt(dFreeRelics, xRelicValue) == RELIC_PROMETHIUM){
		xSetInt(dFreeRelics, xRelicDamage, PROMETHIUM_DAMAGE);
	}
	else if(xGetInt(dFreeRelics, xRelicValue) == RELIC_EINSTEINIUM){
		xSetInt(dFreeRelics, xRelicDamage, EINSTEINIUM_DAMAGE);
	}
	else if(xGetInt(dFreeRelics, xRelicValue) == RELIC_HYDROGEN){
		xSetInt(dFreeRelics, xRelicDamage, HYDROGEN_DAMAGE);
	}
	else if(xGetInt(dFreeRelics, xRelicValue) == RELIC_ANTIMATTER){
		xSetInt(dFreeRelics, xRelicDamage, ANTIMATTER_DAMAGE);
	}
	else{
		xSetInt(dFreeRelics, xRelicDamage, 0);
	}
	trUnitSelectClear();
	trUnitSelectByQV("TEMPRELIC");
	if(aiIsMultiplayer() == true){
		trUnitChangeProtoUnit("Titan Atlantean");
	}
	trUnitChangeProtoUnit("Relic");
	if(aiIsMultiplayer() == true){
		yFindLatestReverse("TempRelicSFX", "Titan Gate Dead", cNumberNonGaiaPlayers);
		xSetInt(dFreeRelics, xSFX, 1*trQuestVarGet("TempRelicSFX"));
		//SPECIAL EFFECTS
		if(val == RELIC_IRON){
			trUnitSelectByQV("TempRelicSFX");
			trUnitChangeProtoUnit("Spy Eye");
			trUnitSelectByQV("TempRelicSFX");
			trMutateSelected(kbGetProtoUnitID("Rock Limestone Sprite"));
			trSetSelectedScale(2,2,2);
		}
		if(val == RELIC_BRONZE){
			trUnitSelectByQV("TempRelicSFX");
			trUnitChangeProtoUnit("Spy Eye");
			trUnitSelectByQV("TempRelicSFX");
			trMutateSelected(kbGetProtoUnitID("Rock Dirt Sprite"));
			trSetSelectedScale(2,2,2);
		}
		if(val == RELIC_SILVER){
			trUnitSelectByQV("TempRelicSFX");
			trUnitChangeProtoUnit("Spy Eye");
			trUnitSelectByQV("TempRelicSFX");
			trMutateSelected(kbGetProtoUnitID("Rock Granite Sprite"));
			trSetSelectedScale(2,2,2);
		}
		if(val == RELIC_GOLD){
			trUnitSelectByQV("TempRelicSFX");
			trUnitChangeProtoUnit("Spy Eye");
			trUnitSelectByQV("TempRelicSFX");
			trMutateSelected(kbGetProtoUnitID("Rock Sandstone Sprite"));
			trSetSelectedScale(2,2,2);
		}
		if(val == RELIC_PLATINUM){
			trUnitSelectByQV("TempRelicSFX");
			trUnitChangeProtoUnit("Spy Eye");
			trUnitSelectByQV("TempRelicSFX");
			trMutateSelected(kbGetProtoUnitID("Ragnorok SFX"));
		}
		if(val == RELIC_URANIUM){
			trUnitSelectByQV("TempRelicSFX");
			trUnitChangeProtoUnit("Spy Eye");
			trUnitSelectByQV("TempRelicSFX");
			trMutateSelected(kbGetProtoUnitID("Acid Pool"));
			trSetSelectedScale(0,0,0);
			trUnitSelectByQV("TempRelicSFX");
			trUnitSetAnimationPath("0,1,0,0,0,0,0");
		}
		if(val == RELIC_RUBY){
			trUnitSelectByQV("TempRelicSFX");
			trUnitChangeProtoUnit("Spy Eye");
			trUnitSelectByQV("TempRelicSFX");
			trMutateSelected(kbGetProtoUnitID("Einheriar Boost SFX"));
		}
		if(val == RELIC_SAPPHIRE){
			trUnitSelectByQV("TempRelicSFX");
			trUnitChangeProtoUnit("Spy Eye");
			trUnitSelectByQV("TempRelicSFX");
			trMutateSelected(kbGetProtoUnitID("Vortex Finish Linked"));
			trUnitSelectByQV("TempRelicSFX");
			trUnitSetAnimationPath("0,0,1,0,0,0,0");
		}
		if(val == RELIC_DIAMOND){
			trUnitSelectByQV("TempRelicSFX");
			trUnitChangeProtoUnit("Spy Eye");
			trUnitSelectByQV("TempRelicSFX");
			trMutateSelected(kbGetProtoUnitID("Healing SFX"));
		}
		if(val == RELIC_PROMETHIUM){
			trUnitSelectByQV("TempRelicSFX");
			trUnitChangeProtoUnit("Spy Eye");
			trUnitSelectByQV("TempRelicSFX");
			trMutateSelected(kbGetProtoUnitID("Poison SFX"));
		}
		if(val == RELIC_EINSTEINIUM){
			trUnitSelectByQV("TempRelicSFX");
			trUnitChangeProtoUnit("Spy Eye");
			trUnitSelectByQV("TempRelicSFX");
			trMutateSelected(kbGetProtoUnitID("Fire Giant"));
			trSetSelectedScale(0,0,0);
		}
		if(val == RELIC_OBSIDIAN){
			trUnitSelectByQV("TempRelicSFX");
			trUnitChangeProtoUnit("Spy Eye");
			trUnitSelectByQV("TempRelicSFX");
			trMutateSelected(kbGetProtoUnitID("Smoke"));
		}
		if(val == RELIC_TOPAZ){
			trUnitSelectByQV("TempRelicSFX");
			trUnitChangeProtoUnit("Spy Eye");
			trUnitSelectByQV("TempRelicSFX");
			trMutateSelected(kbGetProtoUnitID("Hero Birth"));
			trUnitSetAnimationPath("0,1,0,0,0,0,0");
		}
		if(val == RELIC_QUARTZ){
			trUnitSelectByQV("TempRelicSFX");
			trUnitChangeProtoUnit("Spy Eye");
			trUnitSelectClear();
			trUnitSelectByQV("TempRelicSFX");
			trMutateSelected(kbGetProtoUnitID("Arkantosman"));
			trUnitSelectClear();
			trUnitSelectByQV("TempRelicSFX");
			trSetSelectedScale(0,0,0);
		}
		if(val == RELIC_OPAL){
			trUnitSelectByQV("TempRelicSFX");
			trUnitChangeProtoUnit("Spy Eye");
			trUnitSelectByQV("TempRelicSFX");
			trMutateSelected(kbGetProtoUnitID("Flying Purple Hippo"));
			trSetSelectedScale(0,0,0);
			trUnitSelectByQV("TempRelicSFX");
			trUnitOverrideAnimation(15,0,true,false,-1,0);
		}
		if(val == RELIC_AMETHYST){
			trUnitSelectByQV("TempRelicSFX");
			trUnitChangeProtoUnit("Spy Eye");
			trMutateSelected(kbGetProtoUnitID("Pharaoh of Osiris XP"));
			trSetSelectedScale(0.01,0.5,0);
			trUnitSelectByQV("TempRelicSFX");
			trUnitOverrideAnimation(50,0,true,false,-1,0);
		}
		if(val == RELIC_EMERALD){
			trUnitSelectByQV("TempRelicSFX");
			trUnitChangeProtoUnit("Spy Eye");
			trUnitSelectByQV("TempRelicSFX");
			trMutateSelected(kbGetProtoUnitID("Acid Pool"));
			trUnitSelectByQV("TempRelicSFX");
			trUnitSetAnimationPath("0,1,1,0,0,0,0");
		}
		if(val == RELIC_ICE){
			trUnitSelectByQV("TempRelicSFX");
			trUnitChangeProtoUnit("Spy Eye");
			trUnitSelectByQV("TempRelicSFX");
			trMutateSelected(kbGetProtoUnitID("Frost Giant"));
			trSetSelectedScale(0,0,0);
		}
		if(val == RELIC_HYDROGEN){
			trUnitSelectByQV("TempRelicSFX");
			trUnitChangeProtoUnit("Spy Eye");
			trUnitSelectByQV("TempRelicSFX");
			trMutateSelected(kbGetProtoUnitID("Lighthouse"));
			trSetSelectedScale(0,0,0);
		}
		if(val == RELIC_ANTIMATTER){
			trUnitSelectByQV("TempRelicSFX");
			trUnitChangeProtoUnit("Spy Eye");
			trUnitSelectByQV("TempRelicSFX");
			trMutateSelected(kbGetProtoUnitID("Tower Mirror"));
			trSetSelectedScale(0,0,0);
		}
		if(val == RELIC_YEEBIUM){
			trUnitSelectByQV("TempRelicSFX");
			trUnitChangeProtoUnit("Spy Eye");
			trUnitSelectByQV("TempRelicSFX");
			trMutateSelected(kbGetProtoUnitID("Valkyrie"));
			trSetSelectedScale(0,0,0);
		}
		if(val == RELIC_KEY_CHINA){
			trUnitSelectByQV("TempRelicSFX");
			trUnitChangeProtoUnit("Spy Eye");
			trUnitSelectByQV("TempRelicSFX");
			trMutateSelected(kbGetProtoUnitID("UI Range Indicator Chinese SFX"));
		}
		if(val == RELIC_KEY_NORSE){
			trUnitSelectByQV("TempRelicSFX");
			trUnitChangeProtoUnit("Spy Eye");
			trUnitSelectByQV("TempRelicSFX");
			trMutateSelected(kbGetProtoUnitID("UI Range Indicator Norse SFX"));
		}
		if(val == RELIC_KEY_GREEK){
			trUnitSelectByQV("TempRelicSFX");
			trUnitChangeProtoUnit("Spy Eye");
			trUnitSelectByQV("TempRelicSFX");
			trMutateSelected(kbGetProtoUnitID("UI Range Indicator Greek SFX"));
		}
		if(val == RELIC_KEY_ATLANTEAN){
			trUnitSelectByQV("TempRelicSFX");
			trUnitChangeProtoUnit("Spy Eye");
			trUnitSelectByQV("TempRelicSFX");
			trMutateSelected(kbGetProtoUnitID("UI Range Indicator Atlantean SFX"));
		}
		if(val == RELIC_KEY_EGYPT){
			trUnitSelectByQV("TempRelicSFX");
			trUnitChangeProtoUnit("Spy Eye");
			trUnitSelectByQV("TempRelicSFX");
			trMutateSelected(kbGetProtoUnitID("UI Range Indicator Egypt SFX"));
		}
		if(val == RELIC_RELIGION){
			trUnitSelectByQV("TempRelicSFX");
			trUnitChangeProtoUnit("Spy Eye");
			trUnitSelectByQV("TempRelicSFX");
			trMutateSelected(kbGetProtoUnitID("Hero Birth"));
			xSetInt(dFreeRelics, xSFX, 1*trQuestVarGet("TempRelicSFX"));
		}
		if(val == RELIC_SKELETON){
			trUnitSelectByQV("TempRelicSFX");
			trUnitChangeProtoUnit("Skeleton Giant");
			trSetSelectedScale(2,2,2);
			xSetInt(dFreeRelics, xSFX, 1*trQuestVarGet("TempRelicSFX"));
		}
		if(val == RELIC_RUINS){
			trUnitSelectByQV("TempRelicSFX");
			trSetSelectedScale(0.8,0.8,0.8);
			xSetInt(dFreeRelics, xSFX, 1*trQuestVarGet("TempRelicSFX"));
		}
		if(val == RELIC_SHIP){
			trUnitSelectByQV("TempRelicSFX");
			trUnitChangeProtoUnit("Cinematic Dead Bodies Xpack");
			trSetSelectedScale(2,2,2);
			trUnitChangeProtoUnit("Cinematic Dead Bodies Xpack");
			trUnitSetAnimationPath("18,0,0,0,0,0,0");
			xSetInt(dFreeRelics, xSFX, 1*trQuestVarGet("TempRelicSFX"));
		}
	}
	if(val == 0){
		trChatSend(0, "ERROR AT" + v);
	}
	//trChatSend(0, "Free relics = "+xGetDatabaseCount(dFreeRelics)+"");
}

void reselectMyself(int p = 0) {
	if(trCurrentPlayer() == p){
		trBlockAllSounds();
		uiClearSelection();
		trackInsert();
		trackAddWaypoint();
		trackAddWaypoint();
		uiFindType(kbGetProtoUnitName(554));
		trackPlay(1,999);
		trUnblockAllSounds();
	}
	
}

void processFreeRelics(int count = 1) {
	float amt = 0;
	int db = 0;
	//vector pos = vector(0,0,0);
	for (x=xsMin(count, xGetDatabaseCount(dFreeRelics)); > 0) {
		amt = 0;
		xDatabaseNext(dFreeRelics);
		xUnitSelect(dFreeRelics, xRelicName);
		if (trUnitGetIsContained("Unit")) {
			for(p=1; < cNumberNonGaiaPlayers) {
				if (trUnitIsOwnedBy(p)) {
					trMutateSelected(relicProto(xGetInt(dFreeRelics, xRelicValue)));
					if(xGetInt(dFreeRelics, xRelicValue) <= RELIC_NUMBER){
						trSetSelectedScale(0,0,-1);
						trUnitSetAnimationPath("1,0,1,1,0,0,0");
					}
					if (trCurrentPlayer() == p) {
						//trChatSend(0, relicName(xGetInt(dFreeRelics, xRelicValue)) + " stored in cargo hold!");
						if(xGetInt(dFreeRelics, xRelicValue) <= RELIC_NUMBER){
							ColouredChatToPlayer(p, RelicColour(xGetInt(dFreeRelics, xRelicValue)), relicName(xGetInt(dFreeRelics, xRelicValue)) + " stored in cargo hold!");
						}
						else if ((xGetInt(dFreeRelics, xRelicValue) >= RELIC_KEY_CHINA) && (xGetInt(dFreeRelics, xRelicValue) <= RELIC_KEY_ATLANTEAN)) {
							ColouredChatToPlayer(p, RelicColour(xGetInt(dFreeRelics, xRelicValue)), relicName(xGetInt(dFreeRelics, xRelicValue)) + "! <icon=(20)("+relicIcon(xGetInt(dFreeRelics, xRelicValue))+")>");
						}
						trSoundPlayFN("researchcomplete.wav","1",-1,"","");
					}
					trUnitSelectByQV("P"+p+"Siphon");
					trMutateSelected(kbGetProtoUnitID("Hero Greek Atalanta"));
					/*
					db = getWarehouseDB(p);
					xAddDatabaseBlock(db, true);
					xSetInt(db, xRelicName, xGetInt(dFreeRelics, xRelicName));
					xSetInt(db, xRelicType, xGetInt(dFreeRelics, xRelicType));
					*/
					trUnitSelectClear();
					xUnitSelect(dFreeRelics, xSFX);
					trUnitChangeProtoUnit("Rocket");
					xAddDatabaseBlock(dHeldRelics, true);
					xSetInt(dHeldRelics, xRelicName, 1*xGetInt(dFreeRelics, xRelicName));
					xSetInt(dHeldRelics, xRelicValue, 1*xGetInt(dFreeRelics, xRelicValue));
					xSetInt(dHeldRelics, xSFX, 1*xGetInt(dFreeRelics, xSFX));
					if(xGetInt(dFreeRelics, xRelicValue) <= 30){
						xSetInt(dHeldRelics, xRelicTick, (trTimeMS()+50));
					}
					else{
						xSetInt(dHeldRelics, xRelicTick, 1*xGetInt(dFreeRelics, xRelicTick));
					}
					if(xGetInt(dFreeRelics, xRelicValue) == RELIC_URANIUM){
						xSetInt(dHeldRelics, xRelicDamage, URANIUM_DAMAGE);
					}
					else if(xGetInt(dFreeRelics, xRelicValue) == RELIC_PROMETHIUM){
						xSetInt(dHeldRelics, xRelicDamage, PROMETHIUM_DAMAGE);
					}
					else if(xGetInt(dFreeRelics, xRelicValue) == RELIC_EINSTEINIUM){
						xSetInt(dHeldRelics, xRelicDamage, EINSTEINIUM_DAMAGE);
					}
					else if(xGetInt(dFreeRelics, xRelicValue) == RELIC_HYDROGEN){
						xSetInt(dHeldRelics, xRelicDamage, HYDROGEN_DAMAGE);
					}
					else if(xGetInt(dFreeRelics, xRelicValue) == RELIC_ANTIMATTER){
						xSetInt(dHeldRelics, xRelicDamage, ANTIMATTER_DAMAGE);
					}
					
					else{
						xSetInt(dHeldRelics, xRelicDamage, 0);
					}
					xFreeDatabaseBlock(dFreeRelics);
					break; //ends the loop
				}
				
			}
		} else if (trUnitIsSelected()) {
			relicDescription(xGetInt(dFreeRelics, xRelicValue));
			reselectMyself(1*trCurrentPlayer());
		}
	}
}

void processHeldRelics(int count = 1) {
	float amt = 0;
	int dropper = 0;
	int db = 0;
	float currentDistance = 0;
	float keyDistance = 0;
	float keyDistance2 = 0;
	float keyDistance3 = 0;
	for (x=xsMin(count, xGetDatabaseCount(dHeldRelics)); > 0) {
		amt = 0;
		xDatabaseNext(dHeldRelics);
		xUnitSelect(dHeldRelics, xRelicName);
		//If relic is dropped
		currentDistance = unitDistanceToVector(xGetInt(dHeldRelics, xRelicName), GVectorSellPos);
		for(p=1; < cNumberNonGaiaPlayers) {
			if (trUnitIsOwnedBy(p)) {
				//trChatSend(0, "Dropped by p"+p+""); //WHO DROPPED THE RELIC
				dropper = p;
			}
		}
		if (trUnitGetIsContained("Unit") == false) {
			if (currentDistance > 80) {
				trUnitChangeProtoUnit("Relic");
				xUnitSelect(dHeldRelics, xRelicName);
				if(xGetInt(dHeldRelics, xRelicValue) == RELIC_ANTIMATTER){
					trVectorSetUnitPos("RelicPos", "P"+dropper+"Siphon");
					trVectorSnapToGrid("RelicPos");
					int Col = (trVectorQuestVarGetX("RelicPos") ) / 8 +1;
					int Row = (trVectorQuestVarGetZ("RelicPos") ) / 8 +1;
					trUnitChangeProtoUnit("Implode Sphere Effect");
					trUnitSelectClear();
					xUnitSelect(dHeldRelics, xRelicName);
					trDamageUnitPercent(100);
					xFreeDatabaseBlock(dHeldRelics);
					playSoundCustom("implode explode.wav", "implode explode.wav");
					if(Row <= MaxRows){
						if(Row < MaxRows){
							MineSquare(Row+1, Col+1);
							MineSquare(Row+1, Col);
							MineSquare(Row+1, Col-1);
						}
						MineSquare(Row, Col+1);
						MineSquare(Row, Col-1);
						MineSquare(Row-1, Col+1);
						MineSquare(Row-1, Col);
						MineSquare(Row-1, Col-1);
						if(Row < MaxRows){RemoveBlack(Row+1, Col+1);
							RemoveBlack(Row+1, Col);
							RemoveBlack(Row+1, Col-1);
						}
						RemoveBlack(Row, Col+1);
						RemoveBlack(Row, Col-1);
						RemoveBlack(Row-1, Col+1);
						RemoveBlack(Row-1, Col);
						RemoveBlack(Row-1, Col-1);
					}
					break;
				}
				else{
					xAddDatabaseBlock(dFreeRelics, true);
					xSetInt(dFreeRelics, xRelicName, 1*xGetInt(dHeldRelics, xRelicName));
					xSetInt(dFreeRelics, xRelicValue, 1*xGetInt(dHeldRelics, xRelicValue));
					xSetInt(dFreeRelics, xRelicTick, (trTimeMS()+50));
					if(xGetInt(dHeldRelics, xRelicValue) == RELIC_URANIUM){
						xSetInt(dFreeRelics, xRelicDamage, 1);
					}
					else if(xGetInt(dFreeRelics, xRelicValue) == RELIC_PROMETHIUM){
						xSetInt(dHeldRelics, xRelicDamage, PROMETHIUM_DAMAGE);
					}
					else if(xGetInt(dFreeRelics, xRelicValue) == RELIC_EINSTEINIUM){
						xSetInt(dHeldRelics, xRelicDamage, EINSTEINIUM_DAMAGE);
					}
					else if(xGetInt(dFreeRelics, xRelicValue) == RELIC_HYDROGEN){
						xSetInt(dHeldRelics, xRelicDamage, HYDROGEN_DAMAGE);
					}
					else if(xGetInt(dFreeRelics, xRelicValue) == RELIC_ANTIMATTER){
						xSetInt(dHeldRelics, xRelicDamage, ANTIMATTER_DAMAGE);
					}
					else{
						xSetInt(dFreeRelics, xRelicDamage, 0);
					}
					xUnitSelect(dHeldRelics, xRelicName);
					trUnitChangeProtoUnit("Titan Atlantean");
					xUnitSelect(dHeldRelics, xRelicName);
					trUnitChangeProtoUnit("Relic");
					yFindLatestReverse("TempRelicSFX", "Titan Gate Dead");
					trUnitSelectClear();
					if(xGetInt(dHeldRelics, xRelicValue) == RELIC_IRON){
						trUnitSelectByQV("TempRelicSFX");
						trUnitChangeProtoUnit("Spy Eye");
						trUnitSelectByQV("TempRelicSFX");
						trMutateSelected(kbGetProtoUnitID("Rock Limestone Sprite"));
						trSetSelectedScale(2,2,2);
					}
					if(xGetInt(dHeldRelics, xRelicValue) == RELIC_BRONZE){
						trUnitSelectByQV("TempRelicSFX");
						trUnitChangeProtoUnit("Spy Eye");
						trUnitSelectByQV("TempRelicSFX");
						trMutateSelected(kbGetProtoUnitID("Rock Dirt Sprite"));
						trSetSelectedScale(2,2,2);
					}
					if(xGetInt(dHeldRelics, xRelicValue) == RELIC_SILVER){
						trUnitSelectByQV("TempRelicSFX");
						trUnitChangeProtoUnit("Spy Eye");
						trUnitSelectByQV("TempRelicSFX");
						trMutateSelected(kbGetProtoUnitID("Rock Granite Sprite"));
						trSetSelectedScale(2,2,2);
					}
					if(xGetInt(dHeldRelics, xRelicValue) == RELIC_GOLD){
						trUnitSelectByQV("TempRelicSFX");
						trUnitChangeProtoUnit("Spy Eye");
						trUnitSelectByQV("TempRelicSFX");
						trMutateSelected(kbGetProtoUnitID("Rock Sandstone Sprite"));
						trSetSelectedScale(2,2,2);
					}
					if(xGetInt(dHeldRelics, xRelicValue) == RELIC_PLATINUM){
						trUnitSelectByQV("TempRelicSFX");
						trUnitChangeProtoUnit("Spy Eye");
						trUnitSelectByQV("TempRelicSFX");
						trMutateSelected(kbGetProtoUnitID("Ragnorok SFX"));
					}
					if(xGetInt(dHeldRelics, xRelicValue) == RELIC_URANIUM){
						trUnitSelectByQV("TempRelicSFX");
						trUnitChangeProtoUnit("Spy Eye");
						trUnitSelectByQV("TempRelicSFX");
						trMutateSelected(kbGetProtoUnitID("Acid Pool"));
						trSetSelectedScale(0,0,0);
						trUnitSelectByQV("TempRelicSFX");
						trUnitSetAnimationPath("0,1,0,0,0,0,0");
					}
					if(xGetInt(dHeldRelics, xRelicValue) == RELIC_RUBY){
						trUnitSelectByQV("TempRelicSFX");
						trUnitChangeProtoUnit("Spy Eye");
						trUnitSelectByQV("TempRelicSFX");
						trMutateSelected(kbGetProtoUnitID("Einheriar Boost SFX"));
					}
					if(xGetInt(dHeldRelics, xRelicValue) == RELIC_SAPPHIRE){
						trUnitSelectByQV("TempRelicSFX");
						trUnitChangeProtoUnit("Spy Eye");
						trUnitSelectByQV("TempRelicSFX");
						trMutateSelected(kbGetProtoUnitID("Vortex Finish Linked"));
						trUnitSelectByQV("TempRelicSFX");
						trUnitSetAnimationPath("0,0,1,0,0,0,0");
					}
					if(xGetInt(dHeldRelics, xRelicValue) == RELIC_DIAMOND){
						trUnitSelectByQV("TempRelicSFX");
						trUnitChangeProtoUnit("Spy Eye");
						trUnitSelectByQV("TempRelicSFX");
						trMutateSelected(kbGetProtoUnitID("Healing SFX"));
					}
					if(xGetInt(dHeldRelics, xRelicValue) == RELIC_PROMETHIUM){
						trUnitSelectByQV("TempRelicSFX");
						trUnitChangeProtoUnit("Spy Eye");
						trUnitSelectByQV("TempRelicSFX");
						trMutateSelected(kbGetProtoUnitID("Poison SFX"));
					}
					if(xGetInt(dHeldRelics, xRelicValue) == RELIC_EINSTEINIUM){
						trUnitSelectByQV("TempRelicSFX");
						trUnitChangeProtoUnit("Spy Eye");
						trUnitSelectByQV("TempRelicSFX");
						trMutateSelected(kbGetProtoUnitID("Fire Giant"));
						trSetSelectedScale(0,0,0);
					}
					if(xGetInt(dHeldRelics, xRelicValue) == RELIC_OBSIDIAN){
						trUnitSelectByQV("TempRelicSFX");
						trUnitChangeProtoUnit("Spy Eye");
						trUnitSelectByQV("TempRelicSFX");
						trMutateSelected(kbGetProtoUnitID("Smoke"));
					}
					if(xGetInt(dHeldRelics, xRelicValue) == RELIC_TOPAZ){
						trUnitSelectByQV("TempRelicSFX");
						trUnitChangeProtoUnit("Spy Eye");
						trUnitSelectByQV("TempRelicSFX");
						trMutateSelected(kbGetProtoUnitID("Hero Birth"));
						trUnitSetAnimationPath("0,1,0,0,0,0,0");
					}
					if(xGetInt(dHeldRelics, xRelicValue) == RELIC_QUARTZ){
						trUnitSelectByQV("TempRelicSFX");
						trUnitChangeProtoUnit("Spy Eye");
						trUnitSelectClear();
						trUnitSelectByQV("TempRelicSFX");
						trMutateSelected(kbGetProtoUnitID("Arkantosman"));
						trUnitSelectClear();
						trUnitSelectByQV("TempRelicSFX");
						trSetSelectedScale(0,0,0);
					}
					if(xGetInt(dHeldRelics, xRelicValue) == RELIC_OPAL){
						trUnitSelectByQV("TempRelicSFX");
						trUnitChangeProtoUnit("Spy Eye");
						trUnitSelectByQV("TempRelicSFX");
						trMutateSelected(kbGetProtoUnitID("Flying Purple Hippo"));
						trSetSelectedScale(0,0,0);
						trUnitSelectByQV("TempRelicSFX");
						trUnitOverrideAnimation(15,0,true,false,-1,0);
					}
					if(xGetInt(dHeldRelics, xRelicValue) == RELIC_AMETHYST){
						trUnitSelectByQV("TempRelicSFX");
						trUnitChangeProtoUnit("Spy Eye");
						trMutateSelected(kbGetProtoUnitID("Pharaoh of Osiris XP"));
						trSetSelectedScale(0.01,0.5,0);
						trUnitSelectByQV("TempRelicSFX");
						trUnitOverrideAnimation(50,0,true,false,-1,0);
					}
					if(xGetInt(dHeldRelics, xRelicValue) == RELIC_EMERALD){
						trUnitSelectByQV("TempRelicSFX");
						trUnitChangeProtoUnit("Spy Eye");
						trUnitSelectByQV("TempRelicSFX");
						trMutateSelected(kbGetProtoUnitID("Acid Pool"));
						trUnitSelectByQV("TempRelicSFX");
						trUnitSetAnimationPath("0,1,1,0,0,0,0");
					}
					if(xGetInt(dHeldRelics, xRelicValue) == RELIC_ICE){
						trUnitSelectByQV("TempRelicSFX");
						trUnitChangeProtoUnit("Spy Eye");
						trUnitSelectByQV("TempRelicSFX");
						trMutateSelected(kbGetProtoUnitID("Frost Giant"));
						trSetSelectedScale(0,0,0);
					}
					if(xGetInt(dHeldRelics, xRelicValue) == RELIC_HYDROGEN){
						trUnitSelectByQV("TempRelicSFX");
						trUnitChangeProtoUnit("Spy Eye");
						trUnitSelectByQV("TempRelicSFX");
						trMutateSelected(kbGetProtoUnitID("Lighthouse"));
						trSetSelectedScale(0,0,0);
					}
					if(xGetInt(dHeldRelics, xRelicValue) == RELIC_ANTIMATTER){
						trUnitSelectByQV("TempRelicSFX");
						trUnitChangeProtoUnit("Spy Eye");
						trUnitSelectByQV("TempRelicSFX");
						trMutateSelected(kbGetProtoUnitID("Tower Mirror"));
						trSetSelectedScale(0,0,0);
					}
					if(xGetInt(dHeldRelics, xRelicValue) == RELIC_YEEBIUM){
						trUnitSelectByQV("TempRelicSFX");
						trUnitChangeProtoUnit("Spy Eye");
						trUnitSelectByQV("TempRelicSFX");
						trMutateSelected(kbGetProtoUnitID("xGetInt(dHeldRelics, xRelicValue)kyrie"));
						trSetSelectedScale(0,0,0);
					}
					xSetInt(dFreeRelics, xSFX, 1*trQuestVarGet("TempRelicSFX"));
					xFreeDatabaseBlock(dHeldRelics);
					//xUnitSelect(dFreeRelics, xSFX);
					
					
					//break;
				}
			}
		}
		if (currentDistance < 80) {
			for(p=1; < cNumberNonGaiaPlayers) {
				if (trUnitIsOwnedBy(p)) {
					dropper = p;
					trUnitChangeProtoUnit("Rocket");
					trUnitSelectClear();
					spyEffect(1*trQuestVarGet("P"+dropper+"Siphon"), kbGetProtoUnitID("Automaton"), vector(0,0,0), vector(0,0,0), 18);
					//trMutateSelected(kbGetProtoUnitID("Rocket"));
					xUnitSelect(dHeldRelics, xRelicName);
					xSetPointer(dPlayerData, p);
					xSetInt(dPlayerData, xGold, xGetInt(dPlayerData, xGold)+1*relicCost(1*xGetInt(dHeldRelics, xRelicValue)));
					trQuestVarSet("P"+p+"Invoice", 1*trQuestVarGet("P"+p+"Invoice") + 1*relicCost(1*xGetInt(dHeldRelics, xRelicValue)));
					if (trCurrentPlayer() == dropper) {
						//trChatSend(0, relicName(xGetInt(dHeldRelics, xRelicValue)) + " sold!");
						playSoundCustom("tributereceived.wav", "\Yeebaagooon\Motherload\Sell.mp3");
					}
					GSeller = dropper;
					trQuestVarModify("P"+dropper+"R"+1*xGetInt(dHeldRelics, xRelicValue)+"", "+", 1);
					trQuestVarSet("TEMPValue", 1*xGetInt(dHeldRelics, xRelicValue));
					trQuestVarModify("TEMPNumber", "+", 1);
					xFreeDatabaseBlock(dHeldRelics);
					trDelayedRuleActivation("SellMinerals");
					reselectMyself(GSeller);
					break;
				}
			}
		}
		if(xGetInt(dHeldRelics, xRelicValue) == RELIC_URANIUM || xGetInt(dHeldRelics, xRelicValue) == RELIC_PROMETHIUM || xGetInt(dHeldRelics, xRelicValue) == RELIC_EINSTEINIUM || xGetInt(dHeldRelics, xRelicValue) == RELIC_HYDROGEN || xGetInt(dHeldRelics, xRelicValue) == RELIC_ANTIMATTER){
			if(trTimeMS() > xGetInt(dHeldRelics, xRelicTick)){
				for(p=1; < cNumberNonGaiaPlayers) {
					if(1*trQuestVarGet("P"+p+"B18") == 0){
						trDamageUnitsInArea(p,"Hero Greek Atalanta",4, xGetInt(dHeldRelics, xRelicDamage));
						trDamageUnit(-1*xGetInt(dHeldRelics, xRelicDamage));
					}
					if(1*trQuestVarGet("P"+p+"B18") == 1){
						trDamageUnitsInArea(p,"Hero Greek Atalanta",4, 0.500*xGetInt(dHeldRelics, xRelicDamage));
						trDamageUnit(-1*xGetInt(dHeldRelics, xRelicDamage));
					}
				}
				xSetInt(dHeldRelics, xRelicTick,(trTimeMS()+50));
			}
		}
		if((xGetInt(dHeldRelics, xRelicValue) >= RELIC_RELIGION) && (xGetInt(dHeldRelics, xRelicValue) <= RELIC_SHIP)){
			ColouredChatToPlayer(dropper, RelicColour(xGetInt(dHeldRelics, xRelicValue)), relicName(xGetInt(dHeldRelics, xRelicValue)) + " sold!");
			xSetPointer(dPlayerData, dropper);
			xSetInt(dPlayerData, xGold, xGetInt(dPlayerData, xGold)+1*relicCost(1*xGetInt(dHeldRelics, xRelicValue)));
			xSetInt(dPlayerData, xGoldStart, xGetInt(dPlayerData, xGoldStart)+1*relicCost(1*xGetInt(dHeldRelics, xRelicValue)));
			trUnitSelectClear();
			xUnitSelect(dHeldRelics, xSFX);
			trUnitChangeProtoUnit("Olympus Temple SFX");
			trUnitSelectClear();
			xUnitSelect(dHeldRelics, xRelicName);
			trUnitChangeProtoUnit("Osiris Box Glow");
			xFreeDatabaseBlock(dHeldRelics);
			if (trCurrentPlayer() == dropper) {
				playSoundCustom("plentybirth.wav", "\Yeebaagooon\Motherload\SellExtra.mp3");
			}
		}
		if(xGetInt(dHeldRelics, xRelicValue) == RELIC_FUEL){
			ColouredChatToPlayer(dropper, RelicColour(xGetInt(dHeldRelics, xRelicValue)), ""+xGetInt(dHeldRelics, xRelicTick)+"L fuel picked up!");
			xSetPointer(dPlayerData, dropper);
			xSetFloat(dPlayerData, xFuel, xGetFloat(dPlayerData, xFuel)+xGetInt(dHeldRelics, xRelicTick));
			trUnitSelectClear();
			xUnitSelect(dHeldRelics, xSFX);
			trUnitChangeProtoUnit("Lightning Sparks Ground");
			trUnitSelectClear();
			xUnitSelect(dHeldRelics, xRelicName);
			trUnitChangeProtoUnit("Cinematic Block");
			xFreeDatabaseBlock(dHeldRelics);
			spyEffect(1*trQuestVarGet("P"+dropper+"Siphon"), kbGetProtoUnitID("Mountain Giant"), vector(0,0,0), vector(0,0,0), 18);
			if (trCurrentPlayer() == dropper) {
				playSoundCustom("suckup1.wav", "\Yeebaagooon\Motherload\Refuel.mp3");
			}
		}
		if(xGetInt(dHeldRelics, xRelicValue) == RELIC_HULL){
			ColouredChatToPlayer(dropper, RelicColour(xGetInt(dHeldRelics, xRelicValue)), ""+xGetInt(dHeldRelics, xRelicTick)+"hp hull repaired!");
			xSetPointer(dPlayerData, dropper);
			trUnitSelectClear();
			trUnitSelectByQV("P"+dropper+"Siphon");
			trDamageUnit(-1*xGetInt(dHeldRelics, xRelicTick));
			trUnitSelectClear();
			xUnitSelect(dHeldRelics, xSFX);
			trUnitChangeProtoUnit("Lightning Sparks Ground");
			trUnitSelectClear();
			xUnitSelect(dHeldRelics, xRelicName);
			trUnitChangeProtoUnit("Cinematic Block");
			xFreeDatabaseBlock(dHeldRelics);
			spyEffect(1*trQuestVarGet("P"+dropper+"Siphon"), kbGetProtoUnitID("White Tiger"), vector(0,0,0), vector(0,0,0), 18);
			if (trCurrentPlayer() == dropper) {
				playSoundCustom("roll.wav", "\Yeebaagooon\Motherload\Repair.mp3");
			}
		}
		if(Stage == 10){
			if ((xGetInt(dHeldRelics, xRelicValue) >= RELIC_KEY_CHINA) && (xGetInt(dHeldRelics, xRelicValue) <= RELIC_KEY_ATLANTEAN)) {
				keyDistance = unitDistanceToVector(xGetInt(dHeldRelics, xRelicName), GVectorChinese);
				keyDistance2 = unitDistanceToVector(xGetInt(dHeldRelics, xRelicName), GVectorNorse);
				keyDistance3 = unitDistanceToVector(xGetInt(dHeldRelics, xRelicName), GVectorEgypt);
				if ((keyDistance < 50) || (keyDistance2 < 50) || (keyDistance3 < 50)) {
					trUnitSelectClear();
					xUnitSelect(dHeldRelics, xRelicName);
					trUnitChangeProtoUnit("Osiris Box Glow");
					xFreeDatabaseBlock(dHeldRelics);
					playSoundCustom("\cinematics\13_in\jerrygarcia.mp3", "\Yeebaagooon\Motherload\DoorUnlock.mp3");
					if (keyDistance < 50){
						trDelayedRuleActivation("UnlockChinese");
					}
					if (keyDistance2 < 50){
						trDelayedRuleActivation("UnlockNorse");
					}
					if (keyDistance3 < 50){
						trDelayedRuleActivation("UnlockEgypt");
					}
				}
			}
		}
	}
}

rule UnlockChinese
inactive
highFrequency
{
	if(1*trQuestVarGet("ChineseProgress") == 0){
		trQuestVarSet("ChineseProgress", trTimeMS()+50);
	}
	if(trTimeMS() > 1*trQuestVarGet("ChineseProgress")){
		trQuestVarModify("ChineseAnim", "+", 1);
		float scale = 1.00-(trQuestVarGet("ChineseAnim")/100);
		for(x=xGetDatabaseCount(dKey); >0) {
			xDatabaseNext(dKey);
			if(xGetInt(dKey, xKey) == RELIC_KEY_CHINA){
				trUnitSelectClear();
				xUnitSelect(dKey, xKeyUnitName);
				trSetSelectedScale(1.2,scale,1.2);
			}
		}
	}
	if(1*trQuestVarGet("ChineseAnim") >= 100){
		for(x=xGetDatabaseCount(dKey); >0) {
			xDatabaseNext(dKey);
			if(xGetInt(dKey, xKey) == RELIC_KEY_CHINA){
				trUnitSelectClear();
				xUnitSelect(dKey, xKeyUnitName);
				trUnitChangeProtoUnit("Dust Large");
				xFreeDatabaseBlock(dKey);
				playSoundCustom("\cinematics\14_in\Chimes.mp3");
			}
		}
		xsDisableSelf();
	}
}

rule UnlockNorse
inactive
highFrequency
{
	if(1*trQuestVarGet("NorseProgress") == 0){
		trQuestVarSet("NorseProgress", trTimeMS()+50);
	}
	if(trTimeMS() > 1*trQuestVarGet("NorseProgress")){
		trQuestVarModify("NorseAnim", "+", 1);
		float scale = 1.00-(trQuestVarGet("NorseAnim")/100);
		for(x=xGetDatabaseCount(dKey); >0) {
			xDatabaseNext(dKey);
			if(xGetInt(dKey, xKey) == RELIC_KEY_NORSE){
				trUnitSelectClear();
				xUnitSelect(dKey, xKeyUnitName);
				trSetSelectedScale(1.2,scale,1.2);
			}
		}
	}
	if(1*trQuestVarGet("NorseAnim") >= 100){
		for(x=xGetDatabaseCount(dKey); >0) {
			xDatabaseNext(dKey);
			if(xGetInt(dKey, xKey) == RELIC_KEY_NORSE){
				trUnitSelectClear();
				xUnitSelect(dKey, xKeyUnitName);
				trUnitChangeProtoUnit("Dust Large");
				xFreeDatabaseBlock(dKey);
				playSoundCustom("\cinematics\14_in\Chimes.mp3");
			}
		}
		xsDisableSelf();
	}
}

rule UnlockEgypt
inactive
highFrequency
{
	for(x=xGetDatabaseCount(dKey); >0) {
		xDatabaseNext(dKey);
		if(xGetInt(dKey, xKey) == RELIC_KEY_EGYPT){
			trUnitSelectClear();
			xUnitSelect(dKey, xKeyUnitName);
			trUnitChangeProtoUnit("Dust Large");
			xFreeDatabaseBlock(dKey);
			playSoundCustom("\cinematics\14_in\Chimes.mp3");
		}
	}
	xsDisableSelf();
}

rule SellMinerals
inactive
highFrequency
{
	//trChatSendToPlayer(0, GSeller, ""+1*trQuestVarGet("TEMPNumber")+"x "+relicName(1*trQuestVarGet("TEMPValue"))+" sold!");
	trChatSendToPlayer(0, GSeller, "<color=1,0.5,0><u>Receipt:</u></color>");
	for(r=RELIC_NUMBER; >= 1) {
		if(trQuestVarGet("P"+GSeller+"R"+r+"") > 0){
			ColouredChatToPlayer(GSeller, RelicColour(r), ""+1*trQuestVarGet("P"+GSeller+"R"+r+"")+"x "+relicName(r)+" sold!");
			if (xGetInt(dPlayerData, xBonus+18) == 0){
				if(r == RELIC_URANIUM){
					xSetInt(dPlayerData, xRadioactivesSold, xGetInt(dPlayerData, xRadioactivesSold)+1*trQuestVarGet("P"+GSeller+"R"+r+""));
				}
				if(r == RELIC_PROMETHIUM){
					xSetInt(dPlayerData, xRadioactivesSold, xGetInt(dPlayerData, xRadioactivesSold)+1*trQuestVarGet("P"+GSeller+"R"+r+""));
				}
				if(r == RELIC_EINSTEINIUM){
					xSetInt(dPlayerData, xRadioactivesSold, xGetInt(dPlayerData, xRadioactivesSold)+1*trQuestVarGet("P"+GSeller+"R"+r+""));
				}
				if(xGetInt(dPlayerData, xRadioactivesSold) >= RadiationBonus){
					xSetInt(dPlayerData, xBonus+18, 1);
					if(trCurrentPlayer() == GSeller){
						saveAllData();
						ColouredIconChat("1,0.5,0", "icons\special e son of osiris icon 64","Bonus unlocked (18)!");
						playSoundCustom("cinematics\10_in\clearedcity.wav", "\Yeebaagooon\Motherload\UnlockBonus.mp3");
					}
				}
			}
			trQuestVarSet("P"+GSeller+"R"+r+"", 0);
			//Stage unlock conditions
			xSetPointer(dPlayerData, GSeller);
			if(xGetInt(dPlayerData, xRelicCollected+r) == 0){
				xSetInt(dPlayerData, xRelicCollected+r, 1);
			}
			if (xGetInt(dPlayerData, xBonus+6) == 0){
				if(r == RELIC_URANIUM){
					xSetInt(dPlayerData, xBonus+6, 1);
					if(trCurrentPlayer() == GSeller){
						saveAllData();
						ColouredIconChat("1,0.5,0", "icons\special e son of osiris icon 64","Bonus unlocked (6)!");
						playSoundCustom("cinematics\10_in\clearedcity.wav", "\Yeebaagooon\Motherload\UnlockBonus.mp3");
					}
				}
			}
			//Stage 2
			if((xGetInt(dPlayerData, xStageUnlocked) == 1) && (xGetInt(dPlayerData, xStageStatus) == 0) && (r == RELIC_GOLD) && (Stage == 2)){
				xSetInt(dPlayerData, xStageStatus, 1);
				if (trCurrentPlayer() == GSeller) {
					ColouredIconChat("1,0.5,0", "icons/star", "Progression goal achieved.");
				}
			}
			//Stage 6
			if((xGetInt(dPlayerData, xStageUnlocked) == 5) && (xGetInt(dPlayerData, xStageStatus) == 0) && (r == RELIC_DIAMOND) && (Stage == 6)){
				xSetInt(dPlayerData, xStageStatus, 1);
				if (trCurrentPlayer() == GSeller) {
					ColouredIconChat("1,0.5,0", "icons/star", "Progression goal achieved.");
				}
			}
			//Stage 7
			if((xGetInt(dPlayerData, xStageUnlocked) == 6) && (xGetInt(dPlayerData, xStageStatus) == 0) && (r == RELIC_OBSIDIAN) && (Stage == 7)){
				xSetInt(dPlayerData, xStageStatus, 1);
				if (trCurrentPlayer() == GSeller) {
					ColouredIconChat("1,0.5,0", "icons/star", "Progression goal achieved.");
				}
			}
		}
	}
	xSetPointer(dPlayerData, GSeller);
	if ((xGetInt(dPlayerData, xBonus+12) == 2) && (1*trQuestVarGet("P"+GSeller+"B12") == 1)){
		trQuestVarSet("P"+GSeller+"B12", 0);
		xSetInt(dPlayerData, xGold, xGetInt(dPlayerData, xGold)+0.25*trQuestVarGet("P"+GSeller+"Invoice"));
	}
	int CurrentProfit = xGetInt(dPlayerData, xGold)-xGetInt(dPlayerData, xGoldStart);
	string first = "<color=1,0.5,0>Total: ";
	string seco = " | Current profit: ";
	string colred = "<color=1,0,0>";
	string colgrn = "<color=0,1,0>";
	string outof = "<color=1,0.5,0>/ ";
	int goal = 0;
	if(Stage == 1){
		goal = 10;
	}
	if(Stage == 3){
		goal = 25;
	}
	if(Stage == 5){
		goal = 50;
	}
	if(Stage == 6){
		goal = 200;
	}
	if(Stage == 7){
		goal = 150;
	}
	if(Stage == 8){
		goal = 350;
	}
	trChatSendToPlayer(0, GSeller, "<color=1,0.5,0>--------------------</color>");
	if(xGetInt(dPlayerData, xStageUnlocked) == Stage-1){
		if((CurrentProfit < goal) && (goal != 0)){
			trChatSendToPlayer(0, GSeller, first + 1*trQuestVarGet("P"+GSeller+"Invoice") + seco + colred + CurrentProfit + outof + goal);
		}
		else if((CurrentProfit >= goal) && (goal != 0)){
			trChatSendToPlayer(0, GSeller, first + 1*trQuestVarGet("P"+GSeller+"Invoice") + seco + colgrn + CurrentProfit + outof + goal);
		}
		else if(goal == 0){
			trChatSendToPlayer(0, GSeller, first + 1*trQuestVarGet("P"+GSeller+"Invoice") + seco + CurrentProfit);
		}
	}
	else{
		trChatSendToPlayer(0, GSeller, first + 1*trQuestVarGet("P"+GSeller+"Invoice") + seco + CurrentProfit);
	}
	if (xGetInt(dPlayerData, xBonus+12) == 0){
		if(1*trQuestVarGet("P"+GSeller+"Invoice") >= 100){
			xSetInt(dPlayerData, xBonus+12, 1);
			if(trCurrentPlayer() == GSeller){
				ColouredIconChat("1,0.5,0", "icons\special e son of osiris icon 64","Bonus unlocked (12)!");
				saveAllData();
				playSoundCustom("cinematics\10_in\clearedcity.wav", "\Yeebaagooon\Motherload\UnlockBonus.mp3");
			}
		}
	}
	if (xGetInt(dPlayerData, xBonus+13) == 0){
		if(1*trQuestVarGet("P"+GSeller+"Invoice") == 47){
			xSetInt(dPlayerData, xBonus+13, 1);
			if(trCurrentPlayer() == GSeller){
				ColouredIconChat("1,0.5,0", "icons\special e son of osiris icon 64","Bonus unlocked (13)!");
				saveAllData();
				playSoundCustom("cinematics\10_in\clearedcity.wav", "\Yeebaagooon\Motherload\UnlockBonus.mp3");
			}
		}
	}
	trQuestVarSet("P"+GSeller+"Invoice", 0);
	xsDisableSelf();
	xSetPointer(dPlayerData, GSeller);
	int profit = xGetInt(dPlayerData, xGold) - xGetInt(dPlayerData, xGoldStart);
	trSetCivilizationNameOverride(GSeller, "Profit: " + profit);
	gadgetRefresh("unitStatPanel");
}

//These two are probably wrong anyway, also DB set
void HideRelics(int owner = 1) {
	int db = 0;
	float currentDistance = 0;
	vector pos = vector(1,1,1);
	for (x=xsMin(30, xGetDatabaseCount(dHeldRelics)); > 0) {
		xDatabaseNext(dHeldRelics);
		xUnitSelect(dHeldRelics, xRelicName);
		//If relic is owned
		if (trUnitIsOwnedBy(owner)) {
			trUnitChangeProtoUnit("Cinematic Block");
			xUnitSelect(dHeldRelics, xRelicName);
			xAddDatabaseBlock(dHiddenRelics, true);
			xSetInt(dHiddenRelics, xRelicName, 1*xGetInt(dHeldRelics, xRelicName));
			xSetInt(dHiddenRelics, xRelicValue, 1*xGetInt(dHeldRelics, xRelicValue));
			xSetInt(dHiddenRelics, xRelicTick, 1*xGetInt(dHeldRelics, xRelicTick));
			xSetInt(dHiddenRelics, xRelicDamage, 1*xGetInt(dHeldRelics, xRelicDamage));
			xSetInt(dHiddenRelics, xOwner, owner);
			xFreeDatabaseBlock(dHeldRelics);
			//break;
		}
	}
}

void ReturnRelics(int owner = 1) {
	xsSetContextPlayer(0);
	for (x= xGetDatabaseCount(dHiddenRelics); > 0) {
		xDatabaseNext(dHiddenRelics);
		xUnitSelect(dHiddenRelics, xRelicName);
		if (xGetInt(dHiddenRelics, xOwner) == owner) {
			trUnitChangeProtoUnit("Relic");
			xUnitSelect(dHiddenRelics, xRelicName);
			trBlockAllSounds();
			trImmediateUnitGarrison(""+(1*trQuestVarGet("P"+owner+"Siphon"))+"");
			trUnblockAllSounds();
			trSetSelectedScale(0,0,-1);
			trMutateSelected(relicProto(xGetInt(dHiddenRelics, xRelicValue)));
			trUnitSetAnimationPath("1,0,1,1,0,0,0");
			xAddDatabaseBlock(dHeldRelics, true);
			xSetInt(dHeldRelics, xRelicName, 1*xGetInt(dHiddenRelics, xRelicName));
			xSetInt(dHeldRelics, xRelicValue, 1*xGetInt(dHiddenRelics, xRelicValue));
			xSetInt(dHeldRelics, xRelicTick, 1*xGetInt(dHiddenRelics, xRelicTick));
			xSetInt(dHeldRelics, xRelicDamage, 1*xGetInt(dHiddenRelics, xRelicDamage));
			xFreeDatabaseBlock(dHiddenRelics);
			//break;
		}
	}
}

rule eternal_loops
active
highFrequency
{
	int T5Temp = 0;
	processFreeRelics(10);
	processHeldRelics(10);
	if((Stage != 0) || (aiIsMultiplayer() == false)){
		for(p=1; < cNumberNonGaiaPlayers) {
			DrillBonusOff(p);
			xSetPointer(dPlayerData, p);
			if(trPlayerResourceCount(p, "Gold") != xGetInt(dPlayerData, xGold)){
				trPlayerGrantResources(p, "Gold", -1000000);
				trPlayerGrantResources(p, "Gold", xGetInt(dPlayerData, xGold));
			}
		}
	}
	//Cargo hold capacity gadget
	if(aiIsMultiplayer() == false){
		trUnitSelectByQV("MainSiphon");
		if (trUnitIsSelected()) {
			xSetPointer(dPlayerData, 1);
			gadgetReal("unitStatPanel-stat-Capacity");
			gadgetReal("CapacityTextDisplay");
			trSetCivilizationNameOverride(0, "Fuel: " + 1*trQuestVarGet("FuelCL"+xGetInt(dPlayerData, xFuelLevel)+"") + "L");
			gadgetRefresh("unitStatPanel");
		}
		else{
			trSetCivilizationNameOverride(0, "Mr. Natas");
		}
		trUnitSelectClear();
	}
	for(p=1; < cNumberNonGaiaPlayers) {
		if(trPlayerUnitCountSpecific(p, "Hero Greek Atalanta") == 1){
			trUnitSelectByQV("P"+p+"Siphon");
			if (trUnitIsSelected()) {
				gadgetReal("unitStatPanel-stat-Capacity");
				gadgetReal("CapacityTextDisplay");
			}
			trUnitSelectClear();
		}
	}
	
	//debug destroymedb not destroying because not in db???
	/*trChatHistoryClear();
	trChatSend(0, ""+xGetDatabaseCount(dDestroyMe));
	trChatSend(0, ""+xGetInt(dDestroyMe, xDestroyTime));*/
	for (x= xGetDatabaseCount(dDestroyMe); > 0) {
		xDatabaseNext(dDestroyMe);
		if(trTimeMS() > xGetInt(dDestroyMe, xDestroyTime)){
			xUnitSelect(dDestroyMe, xDestroyName);
			trUnitDestroy();
			//trChatSend(0, "<color=1,0,0>"+xGetInt(dDestroyMe, xDestroyName));
			xFreeDatabaseBlock(dDestroyMe);
		}
	}
	for (x= xGetDatabaseCount(dGasPocket); > 0) {
		xDatabaseNext(dGasPocket);
		trVectorQuestVarSet("TempGas", xsVectorSet(8*xGetInt(dGasPocket, xGasCol)-4,3,8*xGetInt(dGasPocket, xGasRow)-4));
		//trVectorQuestVarEcho("TempGas");
		//trVectorQuestVarEcho("P1Pos");
		for(p = 1; <= cNumberNonGaiaPlayers){
			if(trQuestVarGet("P"+p+"Drilling") > 1){
				if(trDistanceBetweenVectorsSquared("TempGas", "P"+p+"Pos") < 30){
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
					xAddDatabaseBlock(dDestroyMe, true);
					xSetInt(dDestroyMe, xDestroyName, temp);
					xSetInt(dDestroyMe, xDestroyTime, trTimeMS()+2000);
					trUnitSelectClear();
					trUnitSelectByQV("P"+p+"Siphon");
					trDamageUnit(400);
					trChatSendToPlayer(0, p, "<color=1,0,0>You hit a gas pocket!</color>");
					trQuestVarModify("P"+p+"GasHit", "+", 1);
					if(1*trQuestVarGet("P"+p+"GasHit") >= 5){
						xSetPointer(dPlayerData, p);
						if (xGetInt(dPlayerData, xBonus+10) == 0){
							xSetInt(dPlayerData, xBonus+10, 1);
							if(trCurrentPlayer() == p){
								ColouredIconChat("1,0.5,0", "icons\special e son of osiris icon 64","Bonus unlocked (10)!");
								saveAllData();
								playSoundCustom("cinematics\10_in\clearedcity.wav", "\Yeebaagooon\Motherload\UnlockBonus.mp3");
							}
						}
					}
					if(trCurrentPlayer() == p){
						trSoundPlayFN("meteorbighit.wav","1",-1,"","");
						trSoundPlayFN("uprootbirth.wav","1",-1,"","");
					}
				}
			}
			
			if(xGetInt(dPlayerData, xBonus+10) == 2){
				if(trDistanceBetweenVectorsSquared("TempGas", "P"+p+"Pos") < 150){
					if(trTime() > 1*trQuestVarGet("TimeS"+p+"")){
						trChatSendToPlayer(0, p, "<color=0.7,0,0>You are near a gas pocket!</color>");
						trQuestVarSet("TimeS"+p+"", trTime()+1);
					}
				}
			}
			
		}
	}
	if(trTime() > 1*trQuestVarGet("Time1S")){
		trQuestVarModify("Time1S", "+", 1);
		for(p=1; < cNumberNonGaiaPlayers) {
			xSetPointer(dPlayerData, p);
			if ((xGetInt(dPlayerData, xBonus+9) == 2) && (1*trQuestVarGet("P"+p+"B9") != 0)){
				trUnitSelectByQV("P"+p+"Siphon");
				if(trUnitPercentDamaged() > 0){
					trDamageUnitPercent(-100);
					trQuestVarModify("P"+p+"B9", "-", 1);
					spyEffect(1*trQuestVarGet("P"+p+"Siphon"), kbGetProtoUnitID("Heavenlight"), vector(0,0,0), vector(0,0,0));
					trChatSendToPlayer(0, p, "<color=1,0.5,0>Bonus utilised!</color>");
				}
			}
		}
	}
	if(Stage == 10){
		xsSetContextPlayer(0);
		for(p=1; < cNumberNonGaiaPlayers) {
			if((trGetTerrainSubType(1*trVectorQuestVarGetX("P"+p+"Pos")/2,1*trVectorQuestVarGetZ("P"+p+"Pos")/2) == 10) && (trGetTerrainType(1*trVectorQuestVarGetX("P"+p+"Pos")/2,1*trVectorQuestVarGetZ("P"+p+"Pos")/2) == 2)){
				trUnitSelectByQV("P"+p+"Siphon");
				if(trQuestVarGet("P"+p+"B17") == 1){
					trDamageUnit(80);
				}
				else{
					trDamageUnit(100);
				}
			}
			if((trVectorQuestVarGetX("P"+p+"Pos") >= 130) && (trVectorQuestVarGetX("P"+p+"Pos") < 134) && (trVectorQuestVarGetZ("P"+p+"Pos") >= 66) && (trVectorQuestVarGetZ("P"+p+"Pos") <= 70)){
				if(1*trQuestVarGet("P"+p+"WinNatas") == 0){
					trUnitSelectByQV("P"+p+"Siphon");
					trUnitChangeProtoUnit("Flag");
					trUnitSelectByQV("P"+p+"Siphon");
					trUnitSetAnimationPath("0,1,0,0,0,0");
					trQuestVarSet("P"+p+"WinNatas", 1);
					trQuestVarModify("TotalNatasWinners", "+", 1);
					trPlayerKillAllGodPowers(p);
					xSetPointer(dPlayerData, p);
					trUnitSelectClear();
					xUnitSelect(dPlayerData, xSpySiphonID);
					trMutateSelected(kbGetProtoUnitID("Hero Birth"));
					if(trCurrentPlayer() == p){
						playSound("xwin.wav");
						trChatSend(0, "<color=1,0.5,0><u>YOU WIN!");
						trChatSend(0, "<color=1,0.5,0>Waiting on other players...</color>");
						if(xGetInt(dPlayerData, xStageUnlocked) == 9){
							xSetInt(dPlayerData, xStageUnlocked, 10);
							xSetInt(dPlayerData, xRelicCollected+21, 1);
							saveAllData();
						}
					}
				}
			}
		}
		/*trChatHistoryClear();
		trChatSend(0, "Trap count = " + xGetDatabaseCount(dTrap));
		xSetPointer(dTrap, xGetDatabaseCount(dTrap));
		trChatSend(0, "Trap ZMin = " + xGetInt(dTrap, xTrapZMin));
		trChatSend(0, "Trap ZMax = " + xGetInt(dTrap, xTrapZMax));
		trChatSend(0, "My Z = " + 1*trVectorQuestVarGetZ("P"+1+"Pos"));*/
		for (x= xGetDatabaseCount(dTrap); > 0) {
			xDatabaseNext(dTrap);
			if((xGetBool(dTrap, xTrapOn) == true) && (xGetBool(dTrap, xTrapReady) == true) && (trTimeMS() > xGetInt(dTrap, xTrapReset))){
				//Trap active, on, and ready
				if(xGetInt(dTrap, xTrapType) == 3){
					//Trap 3, if within square hitbox
					for(p=1; < cNumberNonGaiaPlayers) {
						if((trVectorQuestVarGetX("P"+p+"Pos") >= xsVectorGetX(xGetVector(dTrap, xTrapHitVector))-xGetInt(dTrap, xTrapHitboxX)) && (trVectorQuestVarGetX("P"+p+"Pos") < xsVectorGetX(xGetVector(dTrap, xTrapHitVector))+xGetInt(dTrap, xTrapHitboxX)) && (trVectorQuestVarGetZ("P"+p+"Pos") >= xsVectorGetZ(xGetVector(dTrap, xTrapHitVector))-xGetInt(dTrap, xTrapHitboxZ)) && (trVectorQuestVarGetZ("P"+p+"Pos") <= xsVectorGetZ(xGetVector(dTrap, xTrapHitVector))+xGetInt(dTrap, xTrapHitboxZ))){
							/*
							trQuestVarSet("timeSinceLastHeal", trTimeMS() - yGetVar("creeps","lastHealed")); // get time that has passed since we last checked this creep
							trQuestVarSet("healAmount", trQuestVarGet("timeSinceLastHeal") * trQuestVarGet("P"+1*yGetVar("creeps",
										"player")+"Regen")); // multiply the time by the heal per second
							trDamageUnit(-0.001*trQuestVarGet("healAmount")); // heal the unit
							ySetVar("creeps", "lastHealed", trTimeMS()); // set last healed time to current time
							*/
							trUnitSelectByQV("P"+p+"Siphon");
							trDamageUnit(10000);
						}
					}
				}
				for(p=1; < cNumberNonGaiaPlayers) {
					if((trVectorQuestVarGetX("P"+p+"Pos") >= xGetInt(dTrap, xTrapXMin)) && (trVectorQuestVarGetX("P"+p+"Pos") < xGetInt(dTrap, xTrapXMax)) && (trVectorQuestVarGetZ("P"+p+"Pos") >= xGetInt(dTrap, xTrapZMin)) && (trVectorQuestVarGetZ("P"+p+"Pos") <= xGetInt(dTrap, xTrapZMax))){
						//Trap activate
						//trChatSend(0, "Trap activated!");
						xSetInt(dTrap, xTrapResetTime, trTimeMS()+xGetInt(dTrap, xTrapReset));
						xSetBool(dTrap, xTrapReady, false);
						if(xGetInt(dTrap, xTrapType) == 1){
							playSoundCustom("crocsnap.wav");
							trUnitSelectClear();
							trUnitSelect(""+1*xGetInt(dTrap, xTrapUnit)+"");
							trUnitSetAnimationPath("0,0,0,0,0,0");
							trUnitSelectClear();
							trUnitSelect(""+1*xGetInt(dTrap, xTrapUnit)+"");
							trUnitOverrideAnimation(18,0,true,true,-1,-1);
						}
						if(xGetInt(dTrap, xTrapType) == 2){
							playSoundCustom("crocsnap.wav");
							trUnitSelectClear();
							trUnitSelect(""+1*xGetInt(dTrap, xTrapUnit)+"");
							trMutateSelected(kbGetProtoUnitID("Lampades"));
							trUnitSelectClear();
							trUnitSelect(""+1*xGetInt(dTrap, xTrapUnit)+"");
							trUnitMoveToPoint(xsVectorGetX(xGetVector(dTrap, xTrapStartVector)+xGetVector(dTrap, xTrapTargetVector)),3,xsVectorGetZ(xGetVector(dTrap, xTrapStartVector)+xGetVector(dTrap, xTrapTargetVector)),-1,false);
						}
						//trap 3 active
						if(xGetInt(dTrap, xTrapType) == 3){
							playSoundCustom("crocsnap.wav", "\Yeebaagooon\Motherload\Forcefield Down.wav");
							for(t=1*xGetInt(dTrap, xTrapUnit) ; < 1*xGetInt(dTrap, xTrapUnit)+xsVectorGetX(xGetVector(dTrap, xTrapTargetVector))){
								trUnitSelectClear();
								trUnitSelect(""+t+"");
								trUnitChangeProtoUnit("Cinematic Block");
							}
						}
						//trap 4 active
						if(xGetInt(dTrap, xTrapType) == 4){
							playSoundCustom("crocsnap.wav", "\Yeebaagooon\Motherload\Forcefield Up.wav");
							for(t=1*xGetInt(dTrap, xTrapUnit) ; < 1*xGetInt(dTrap, xTrapUnit)+xsVectorGetX(xGetVector(dTrap, xTrapTargetVector))){
								trUnitSelectClear();
								trUnitSelect(""+t+"");
								trUnitChangeProtoUnit("Garrison Flag Sky Passage");
							}
						}
						//trap 5 active
						if(xGetInt(dTrap, xTrapType) == 5){
							playSoundCustom("crocsnap.wav", "\Yeebaagooon\Motherload\Forcefield Down.wav");
							xSetBool(dTrap, xTrapOn, false);
							for(t=xGetDatabaseCount(dT5); >0) {
								xDatabaseNext(dT5);
								if(xGetInt(dT5, xT5XPos) == xGetInt(dTrap, xTrapXMin)/2){
									trUnitSelectClear();
									xUnitSelect(dT5,xT5Name);
									trUnitChangeProtoUnit("Cinematic Block");
								}
							}
						}
						//trap 6 active
						if(xGetInt(dTrap, xTrapType) == 6){
							playSoundCustom("crocsnap.wav", "\Yeebaagooon\Motherload\Forcefield Down.wav");
							xSetBool(dTrap, xTrapOn, false);
							for(t=xGetDatabaseCount(dT5); >0) {
								xDatabaseNext(dT5);
								trUnitSelectClear();
								xUnitSelect(dT5,xT5Name);
								trUnitDestroy();
							}
							for (u= xGetDatabaseCount(dTrap); > 0) {
								xDatabaseNext(dTrap);
								if(xGetInt(dTrap, xTrapType) == 5){
									xSetBool(dTrap, xTrapOn, false);
									xSetBool(dTrap, xTrapReady, true);
								}
							}
							PaintSellTerrain(81,3);
							GVectorSellPos = vector(170,1,9);
							trPaintTerrain(11,49,18,51,0,70,false);
							//trPaintTerrain(37,14,39,40,0,73,true);
							//Win key command - terrain refresh disables drilling - you get trapped after a drill because of the black rock between squares
						}
						//trap 7 active
						if(xGetInt(dTrap, xTrapType) == 7){
							playSoundCustom("crocsnap.wav", "\Yeebaagooon\Motherload\Forcefield Up.wav");
							xSetBool(dTrap, xTrapOn, false);
							xSetInt(dTrap, xTrapResetTime, trTimeMS()+500);
							xSetInt(dTrap, xTrapUnit, xGetInt(dTrap, xTrapHitboxX));
						}
					}
					//trap 5 dmg
					if(xGetInt(dTrap, xTrapType) == 5){
						if((trVectorQuestVarGetX("P"+p+"Pos") >= xsVectorGetX(xGetVector(dTrap, xTrapHitVector))-xGetInt(dTrap, xTrapHitboxX)) && (trVectorQuestVarGetX("P"+p+"Pos") < xsVectorGetX(xGetVector(dTrap, xTrapHitVector))+xGetInt(dTrap, xTrapHitboxX)) && (trVectorQuestVarGetZ("P"+p+"Pos") >= xsVectorGetZ(xGetVector(dTrap, xTrapHitVector))-xGetInt(dTrap, xTrapHitboxZ)) && (trVectorQuestVarGetZ("P"+p+"Pos") <= xsVectorGetZ(xGetVector(dTrap, xTrapHitVector))+xGetInt(dTrap, xTrapHitboxZ))){
							trUnitSelectByQV("P"+p+"Siphon");
							trDamageUnit(10000);
						}
					}
				}
			}
			else if((xGetBool(dTrap, xTrapOn) == true) && (xGetBool(dTrap, xTrapReady) == false) && (trTimeMS() < xGetInt(dTrap, xTrapResetTime))){
				if(xGetInt(dTrap, xTrapType) == 1){
					//Trap 1, if within square hitbox
					for(p=1; < cNumberNonGaiaPlayers) {
						if((trVectorQuestVarGetX("P"+p+"Pos") >= xsVectorGetX(xGetVector(dTrap, xTrapHitVector))-xGetInt(dTrap, xTrapHitboxX)) && (trVectorQuestVarGetX("P"+p+"Pos") < xsVectorGetX(xGetVector(dTrap, xTrapHitVector))+xGetInt(dTrap, xTrapHitboxX)) && (trVectorQuestVarGetZ("P"+p+"Pos") >= xsVectorGetZ(xGetVector(dTrap, xTrapHitVector))-xGetInt(dTrap, xTrapHitboxZ)) && (trVectorQuestVarGetZ("P"+p+"Pos") <= xsVectorGetZ(xGetVector(dTrap, xTrapHitVector))+xGetInt(dTrap, xTrapHitboxZ))){
							/*
							trQuestVarSet("timeSinceLastHeal", trTimeMS() - yGetVar("creeps","lastHealed")); // get time that has passed since we last checked this creep
							trQuestVarSet("healAmount", trQuestVarGet("timeSinceLastHeal") * trQuestVarGet("P"+1*yGetVar("creeps",
										"player")+"Regen")); // multiply the time by the heal per second
							trDamageUnit(-0.001*trQuestVarGet("healAmount")); // heal the unit
							ySetVar("creeps", "lastHealed", trTimeMS()); // set last healed time to current time
							*/
							trUnitSelectByQV("P"+p+"Siphon");
							trDamageUnit(10000);
						}
					}
				}
				if(xGetInt(dTrap, xTrapType) == 2){
					//Check missile status, QV needed as first frame is idle and this is our reset condition
					trUnitSelectClear();
					xUnitSelect(dTrap, xTrapUnit);
					for(p=1; < cNumberNonGaiaPlayers) {
						trDamageUnitsInArea(1, "Hero Greek Atalanta", 2, 40);
					}
					if(kbUnitGetAnimationActionType(kbGetBlockID(""+xGetInt(dTrap, xTrapUnit)+"")) == 9){
						if(trTimeMS() > 1*trQuestVarGet("Temp"+1*xGetInt(dTrap, xTrapUnit)+"")){
							trQuestVarSet("Temp"+1*xGetInt(dTrap, xTrapUnit)+"", trTimeMS()+50);
						}
						else{
							xSetInt(dTrap, xTrapResetTime, trTimeMS()-10);
						}
					}
				}
				if(xGetInt(dTrap, xTrapType) == 4){
					//Trap 4, if within square hitbox
					for(p=1; < cNumberNonGaiaPlayers) {
						if((trVectorQuestVarGetX("P"+p+"Pos") >= xsVectorGetX(xGetVector(dTrap, xTrapHitVector))-xGetInt(dTrap, xTrapHitboxX)) && (trVectorQuestVarGetX("P"+p+"Pos") < xsVectorGetX(xGetVector(dTrap, xTrapHitVector))+xGetInt(dTrap, xTrapHitboxX)) && (trVectorQuestVarGetZ("P"+p+"Pos") >= xsVectorGetZ(xGetVector(dTrap, xTrapHitVector))-xGetInt(dTrap, xTrapHitboxZ)) && (trVectorQuestVarGetZ("P"+p+"Pos") <= xsVectorGetZ(xGetVector(dTrap, xTrapHitVector))+xGetInt(dTrap, xTrapHitboxZ))){
							trUnitSelectByQV("P"+p+"Siphon");
							trDamageUnit(10000);
						}
					}
				}
			}
			else if((xGetBool(dTrap, xTrapOn) == true) && (xGetBool(dTrap, xTrapReady) == false) && (trTimeMS() > xGetInt(dTrap, xTrapResetTime))){
				xSetBool(dTrap, xTrapReady, true);
				if(xGetInt(dTrap, xTrapType) == 1){
					//Reset trap to ready
					trUnitSelectClear();
					trUnitSelect(""+1*xGetInt(dTrap, xTrapUnit)+"");
					trUnitOverrideAnimation(2,0,true,true,-1,-1);
					trUnitSelectClear();
					trUnitSelect(""+1*xGetInt(dTrap, xTrapUnit)+"");
					trUnitSetAnimationPath("0,0,1,1,0,0");
				}
				if(xGetInt(dTrap, xTrapType) == 2){
					if(xsVectorGetX(xGetVector(dTrap, xTrapTargetVector)+xGetVector(dTrap, xTrapStartVector)) >= trVectorQuestVarGetX("TrapV"+xGetInt(dTrap, xTrapUnit)+"")){
						trUnitSelectClear();
						trUnitSelect(""+1*xGetInt(dTrap, xTrapUnit)+"");
						trMutateSelected(kbGetProtoUnitID("Victory Marker"));
						trUnitSelectClear();
						trUnitSelect(""+1*xGetInt(dTrap, xTrapUnit)+"");
						trUnitTeleport(xsVectorGetX(xGetVector(dTrap, xTrapStartVector)),3,xsVectorGetZ(xGetVector(dTrap, xTrapStartVector)));
					}
				}
				if(xGetInt(dTrap, xTrapType) == 3){
					//Reset trap to ready
					playSoundCustom("crocsnap.wav", "\Yeebaagooon\Motherload\Forcefield Up.wav");
					for(t=1*xGetInt(dTrap, xTrapUnit) ; < 1*xGetInt(dTrap, xTrapUnit)+xsVectorGetX(xGetVector(dTrap, xTrapTargetVector))){
						trUnitSelectClear();
						trUnitSelect(""+t+"");
						trUnitChangeProtoUnit("Garrison Flag Sky Passage");
					}
				}
				if(xGetInt(dTrap, xTrapType) == 4){
					//Reset trap to ready - next 2 lines added ???forplayer
					playSoundCustom("crocsnap.wav", "\Yeebaagooon\Motherload\Forcefield Down.wav");
					for(t=1*xGetInt(dTrap, xTrapUnit) ; < 1*xGetInt(dTrap, xTrapUnit)+xsVectorGetX(xGetVector(dTrap, xTrapTargetVector))){
						trUnitSelectClear();
						trUnitSelect(""+t+"");
						trUnitChangeProtoUnit("Cinematic Block");
					}
				}
			}
			else if((xGetBool(dTrap, xTrapOn) == false) && (xGetBool(dTrap, xTrapReady) == false) && (xGetInt(dTrap, xTrapType) == 5)){
				T5Temp = 0;
				for(p=1; < cNumberNonGaiaPlayers) {
					if((trVectorQuestVarGetX("P"+p+"Pos") >= xGetInt(dTrap, xTrapXMin)) && (trVectorQuestVarGetX("P"+p+"Pos") < xGetInt(dTrap, xTrapXMax)) && (trVectorQuestVarGetZ("P"+p+"Pos") >= xGetInt(dTrap, xTrapZMin)) && (trVectorQuestVarGetZ("P"+p+"Pos") <= xGetInt(dTrap, xTrapZMax))){
						T5Temp = 1;
					}
					
				}
				if(T5Temp == 0){
					playSoundCustom("crocsnap.wav", "\Yeebaagooon\Motherload\Forcefield Up.wav");
					xSetBool(dTrap, xTrapOn, true);
					xSetBool(dTrap, xTrapReady, true);
					for(t=xGetDatabaseCount(dT5); >0) {
						xDatabaseNext(dT5);
						if(xGetInt(dT5, xT5XPos) == xGetInt(dTrap, xTrapXMin)/2){
							trUnitSelectClear();
							xUnitSelect(dT5,xT5Name);
							trUnitChangeProtoUnit("Garrison Flag Sky Passage");
						}
					}
				}
			}
			else if((xGetBool(dTrap, xTrapOn) == false) && (xGetBool(dTrap, xTrapReady) == false) && (xGetInt(dTrap, xTrapType) == 7)){
				if(trTimeMS() > xGetInt(dTrap, xTrapResetTime)){
					//trChatSend(0, "DEBUG - " + xGetInt(dTrap, xTrapUnit));
					xSetInt(dTrap, xTrapResetTime, trTimeMS()+500);
					xSetInt(dTrap, xTrapUnit, xGetInt(dTrap, xTrapUnit)-1);
					trPaintTerrain(xGetInt(dTrap, xTrapHitboxZ),xGetInt(dTrap, xTrapUnit),xGetInt(dTrap, xTrapHitboxZ)+1,xGetInt(dTrap, xTrapUnit)-2,0,73,false);
					//black divder = 39
					if(xGetInt(dTrap, xTrapUnit) <= 31){
						trPaintTerrain(xGetInt(dTrap, xTrapHitboxZ),xGetInt(dTrap, xTrapUnit)+3,xGetInt(dTrap, xTrapHitboxZ)+1,xGetInt(dTrap, xTrapUnit)+2,2,10,false);
					}
					else{
						trPaintTerrain(xGetInt(dTrap, xTrapHitboxZ),xGetInt(dTrap, xTrapUnit)+3,xGetInt(dTrap, xTrapHitboxZ)+1,xGetInt(dTrap, xTrapUnit)+2,0,70,false);
					}
					if(xGetInt(dTrap, xTrapUnit) <= 1){
						trPaintTerrain(xGetInt(dTrap, xTrapHitboxZ),1,xGetInt(dTrap, xTrapHitboxZ)+1,4,0,70,false);
						xSetBool(dTrap, xTrapOn, true);
						xSetBool(dTrap, xTrapReady, true);
						xSetInt(dTrap, xTrapUnit, xGetInt(dTrap, xTrapHitboxX));
						trPaintTerrain(90,0,100,0,5,4,false);
					}
				}
			}
		}
	}
	
}
