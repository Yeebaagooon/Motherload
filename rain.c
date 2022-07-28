/* lure ability */

rule lure
active
highFrequency
{
	for(p = 1; <= cNumberNonGaiaPlayers){
		if (trPlayerUnitCountSpecific(p, "Animal Attractor") == 1) {
			yFindLatestReverse("p"+p+"LureObject", "Animal Attractor", p);
			trVectorSetUnitPos("V1", "p"+p+"LureObject", true);
						trMutateSelected(kbGetProtoUnitID("Osiris SFX"));
							trArmyDispatch(""+p+",0", "Ajax", 1, trVectorQuestVarGetX("V1"), trVectorQuestVarGetY("V1"),
					trVectorQuestVarGetZ("V1"), 0, true);
							trVectorQuestVarEcho("V1");
		}
		else {
			trQuestVarSet("p"+p+"LureObject", trGetNextUnitScenarioNameNumber() - 1);
		}
	}
}

int MaxRows = 20;
int MaxCols = 25;

rule squarespaint
active
highFrequency
{
	if(trChatHistoryContains("1", 1)){
		//trPaintTerrain(0,0,4*col+4,4*row+4,2,13,false);
		trPaintTerrain(0,0,4*MaxCols,4*MaxRows,2,13,false);
		for(col = 1; <= MaxCols){
			for(row = 1; <= MaxRows){
				trPaintTerrain(4*col-1,4*row-1,4*col-3,4*row-3,0,73,false);
				trQuestVarSet("R"+row+"C"+col+"CentreY", row*4-2);
				trQuestVarSet("R"+row+"C"+col+"CentreX", col*4-2);
				//trQuestVarSet("R"+row+"C"+col+"Drilled", 0);
				//trQuestVarSet("R"+row+"C"+col+"HP", 0);
			}
		}
		trQuestVarEcho("R8C3CentreX");
		trQuestVarEcho("R8C3CentreY");
		trPaintTerrain(1*trQuestVarGet("R8C3CentreX"),
			1*trQuestVarGet("R8C3CentreY"),1*trQuestVarGet("R8C3CentreX"),
			1*trQuestVarGet("R8C3CentreY"),2,2,false);
		xsDisableSelf();
		trQuestVarSet("P1Siphon", trGetNextUnitScenarioNameNumber());
		UnitCreate(1, "Fire Siphon", 12, 180, 180);
		yAddToDatabase("Siphon1", "P1Siphon");
	}
}
