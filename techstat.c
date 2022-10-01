rule Technologies
inactive
highFrequency
{
	for(p = 1; <= cNumberNonGaiaPlayers){
		trTechSetStatus(p, 1, 4);
		trTechSetStatus(p, 2, 4);
		trTechSetStatus(p, 116, 4);
		trTechSetStatus(p, 29, 4);
		trTechSetStatus(p, 353, 0);
		trTechSetStatus(p, 394, 0);
		trTechSetStatus(p, 510, 0);
		trTechSetStatus(p, 145, 0);
		trTechSetStatus(p, 144, 0);
		trTechSetStatus(p, 143, 0);
		trTechSetStatus(p, 379, 0);
		trTechSetStatus(p, 28, 4);
		trTechSetStatus(p, 30, 4);
		trTechSetStatus(p, 350, 4);
		trTechSetStatus(p, 27, 4);
		for(n=930; >0) {
			trForbidProtounit(p,kbGetProtoUnitName(n));
		}
	}
	//      trUnforbidProtounit(p, "Outpost");
	//  trUnforbidProtounit(1*p, "Oracle Hero");
	xsDisableSelf();
}

rule Stats
inactive
highFrequency
{
	trModifyProtounit("Dwarf", 0, 55, 4);
	trModifyProtounit("Relic", 0, 55, 4); //recent change
	trModifyProtounit("Armory", 0, 55, 4);
	trModifyProtounit("Heka Shockwave SFX", cNumberNonGaiaPlayers, 8, 1);
	//movetype to air for mutated relics means they ungarrison in a pile
	trModifyProtounit("Wadjet Spit", 0, 8, -1000);
	trModifyProtounit("Alfred", 0, 1, -1000);
	trModifyProtounit("Athena", 1, 1, 4);
	trModifyProtounit("Meteorite", 0, 8, 4);
	trModifyProtounit("Lampades", cNumberNonGaiaPlayers, 0, 1000);
	trModifyProtounit("Lampades", cNumberNonGaiaPlayers, 1, 5);
	trModifyProtounit("Lampades", cNumberNonGaiaPlayers, 55, 4);
	xsDisableSelf();
}

rule PlayerStats
inactive
highFrequency
{
	for(p = 1; <= cNumberNonGaiaPlayers){
		trModifyProtounit("Dwarf", p, 55, 4);
		trModifyProtounit("Audrey", p, 55, 4);
		trModifyProtounit("Armory", p, 55, 4);
		trModifyProtounit("Meteorite", p, 8, 4);
		trModifyProtounit("Animal Attractor", p, 2, -40);
		trModifyProtounit("Animal Attractor", p, 55, 4);
		trModifyProtounit("Earth Dragon", p, 55, 4);
		trModifyProtounit("Wadjet Spit", p, 8, -1000);
		trModifyProtounit("Hero Greek Atalanta", p, 1, 10);
		trModifyProtounit("Vision Revealer", p, 6, 10000);
		xSetPointer(dPlayerData, p);
		modifyProtounitAbsolute("Hero Greek Atalanta", p, 5, xGetInt(dPlayerData, xCargoHold));
		modifyProtounitAbsolute("Hero Greek Atalanta", p, 0, xGetInt(dPlayerData, xHullHP));
		modifyProtounitAbsolute("Heka Shockwave SFX", p, 0, xGetInt(dPlayerData, xHullHP));
		modifyProtounitAbsolute("Wadjet Spit", p, 0, xGetInt(dPlayerData, xHullHP));
		modifyProtounitAbsolute("Hero Greek Atalanta", p, 29, xGetFloat(dPlayerData, xDrillPower));
		modifyProtounitAbsolute("Hero Greek Atalanta", p, 24, 0.01*xGetInt(dPlayerData, xRadiator)+0.01);
		modifyProtounitAbsolute("Hero Greek Atalanta", p, 25, 0.01*xGetInt(dPlayerData, xRadiator)+0.01);
	}
	xsDisableSelf();
}

rule SPSiphonStats
inactive
highFrequency
{
	xSetPointer(dPlayerData, 1);
	modifyProtounitAbsolute("Fire Siphon", 0, 0, xGetInt(dPlayerData, xHullHP));
	modifyProtounitAbsolute("Fire Siphon", 0, 32, xGetFloat(dPlayerData, xDrillPower));
	modifyProtounitAbsolute("Fire Siphon", 0, 24, 0.01*xGetInt(dPlayerData, xRadiator)+0.01);
	modifyProtounitAbsolute("Fire Siphon", 0, 25, 0.01*xGetInt(dPlayerData, xRadiator)+0.01);
	modifyProtounitAbsolute("Fire Siphon", 0, 11, xGetInt(dPlayerData, xEnginePower));
	xsDisableSelf();
}

/*
The field ids are as follows:
Hitpoints=0
Speed=1
LOS=2
Train Points=3
Build Points=4
Max Contained=5
Population Count=6
Pop Cap Addition=7
Lifespan=8
Recharge Time=9
Build Limit=10
Range=11
Minimum Range=12
Num Projectiles=13
Healing Rate=14
Healing Range=15
Cost Gold=16
Cost Wood=17
Cost Food=18
Cost Favor=19
Carry Capacity Gold=20
Carry Capacity Wood=21
Carry Capacity Food=22
Carry Capacity Favor=23
Armor Hack=24
Armor Pierce=25
Armor Crush=26
Hand Attack Hack=27
Hand Attack Pierce=28
Hand Attack Crush=29
Ranged Attack Hack=30
Ranged Attack Pierce=31
Ranged Attack Crush=32
Movetype = 55
*/
