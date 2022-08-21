//This paints the overworld terrain for each stage
void GroundType(int rock = 0) {
	switch(rock)
	{
		case 1:
		{
			OVERTERRAIN_TYPE = 3;
			OVERTERRAIN_SUBTYPE = 13;
		}
		case 2:
		{
			OVERTERRAIN_TYPE = 4;
			OVERTERRAIN_SUBTYPE = 2;
		}
		case 3:
		{
			OVERTERRAIN_TYPE = 0;
			OVERTERRAIN_SUBTYPE = 63;
		}
		case 4:
		{
			OVERTERRAIN_TYPE = 4;
			OVERTERRAIN_SUBTYPE = 34;
		}
		case 5:
		{
			OVERTERRAIN_TYPE = 4;
			OVERTERRAIN_SUBTYPE = 15;
		}
		case 6:
		{
			OVERTERRAIN_TYPE = 2;
			OVERTERRAIN_SUBTYPE = 6;
		}
	}
}

rule squarespaint
inactive
highFrequency
{
	if((trTime()-cActivationTime) >= 1){
		//trPaintTerrain(0,0,4*col+4,4*row+4,2,13,false);
		trPaintTerrain(0,0,4*MaxCols,4*MaxRows,2,13,false);
		GroundType(Stage);
		trPaintTerrain(0,4*MaxRows+1,200,200,OVERTERRAIN_TYPE,OVERTERRAIN_SUBTYPE,false); //paints the land above the dig area
		for(col = 1; <= MaxCols){
			for(row = 1; <= MaxRows){
				trQuestVarSet("R"+row+"C"+col+"WallX", 1*trGetNextUnitScenarioNameNumber());
				UnitCreate(cNumberNonGaiaPlayers, "Victory Marker", 8*col-4, 8*row, 0);
				trQuestVarSet("R"+row+"C"+col+"WallY", 1*trGetNextUnitScenarioNameNumber());
				UnitCreate(cNumberNonGaiaPlayers, "Victory Marker", 8*col, 8*row-4, 90);
				if(Stage == 1){
					if((col > 5) && (col < 20)){
						if(row > 18){
							RockType(1);
						}
						else if((row > 15) && (row <= 18 )){
							trQuestVarSetFromRand("Temp",1,2,true);
							RockType(1*trQuestVarGet("Temp"));
						}
						else if((row > 13) && (row <= 15 )){
							trQuestVarSetFromRand("Temp",1,3,true);
							if(trQuestVarGet("Temp") == 3){
								trQuestVarModify("Temp", "-", 1);
							}
							RockType(1*trQuestVarGet("Temp"));
						}
						else if((row > 10) && (row <= 13 )){
							trQuestVarSetFromRand("Temp",2,4,true);
							if(trQuestVarGet("Temp") == 4){
								trQuestVarModify("Temp", "-", 1);
							}
							RockType(1*trQuestVarGet("Temp"));
						}
						else if((row > 7) && (row <= 10 )){
							trQuestVarSetFromRand("Temp",2,4,true);
							if(trQuestVarGet("Temp") == 2){
								trQuestVarModify("Temp", "+", 1);
							}
							RockType(1*trQuestVarGet("Temp"));
						}
						else if((row > 5) && (row <= 7 )){
							trQuestVarSetFromRand("Temp",3,4,true);
							RockType(1*trQuestVarGet("Temp"));
						}
						else if((row > 2) && (row <= 5 )){
							trQuestVarSetFromRand("Temp",4,7,true);
							if(trQuestVarGet("Temp") != 4){
								trQuestVarSet("Temp", 5);
							}
							RockType(1*trQuestVarGet("Temp"));
						}
						else if(row <= 2 ){
							RockType(5);
						}
					}
					if(col >= 20){
						RockType(8);
					}
					if(col <= 5){
						RockType(9);
					}
				}
				if(Stage == 2){
					if(row > 18){
						RockType(3);
					}
					else if((row > 15) && (row <= 18 )){
						trQuestVarSetFromRand("Temp",3,4,true);
						RockType(1*trQuestVarGet("Temp"));
					}
					else if((row > 12) && (row <= 15 )){
						trQuestVarSetFromRand("Temp",3,5,true);
						RockType(1*trQuestVarGet("Temp"));
					}
					else if((row > 9) && (row <= 12 )){
						trQuestVarSetFromRand("Temp",4,5,true);
						RockType(1*trQuestVarGet("Temp"));
					}
					else if((row > 4) && (row <= 9 )){
						trQuestVarSetFromRand("Temp",5,7,true);
						RockType(1*trQuestVarGet("Temp"));
					}
					else{
						trQuestVarSetFromRand("Temp",6,7,true);
						RockType(1*trQuestVarGet("Temp"));
					}
				}
				if(Stage == 3){
					if(row > 18){
						RockType(10);
					}
					else if((row > 15) && (row <= 18 )){
						trQuestVarSetFromRand("Temp",10,11,true);
						RockType(1*trQuestVarGet("Temp"));
					}
					else if((row > 12) && (row <= 15 )){
						RockType(12);
					}
					else if((row > 9) && (row <= 12 )){
						trQuestVarSetFromRand("Temp",12,13,true);
						RockType(1*trQuestVarGet("Temp"));
					}
					else{
						trQuestVarSetFromRand("Temp",13,14,true);
						RockType(1*trQuestVarGet("Temp"));
					}
				}
				if(Stage == 4){
					if(row > 18){
						trQuestVarSetFromRand("Temp",13,14,true);
						RockType(1*trQuestVarGet("Temp"));
					}
					else if((row > 15) && (row <= 18 )){
						trQuestVarSetFromRand("Temp",14,15,true);
						RockType(1*trQuestVarGet("Temp"));
					}
					else if((row > 9) && (row <= 15 )){
						trQuestVarSetFromRand("Lava",1,10,true);
						trQuestVarSetFromRand("Temp",15,16,true);
						if(1*trQuestVarGet("Lava") == 1){
							RockType(18);
						}
						else{
							RockType(1*trQuestVarGet("Temp"));
						}
					}
					else if((row > 3) && (row <= 9 )){
						trQuestVarSetFromRand("Temp",15,17,true);
						trQuestVarSetFromRand("Lava",1,8,true);
						if(1*trQuestVarGet("Lava") == 1){
							RockType(18);
						}
						else{
							RockType(1*trQuestVarGet("Temp"));
						}
					}
					else{
						trQuestVarSetFromRand("Lava",1,6,true);
						if(1*trQuestVarGet("Lava") == 1){
							RockType(18);
						}
						else{
							RockType(17);
						}
					}
				}
				if(Stage == 5){
					if(row > 18){
						RockType(18);
					}
					else if((row > 15) && (row <= 18 )){
						trQuestVarSetFromRand("Temp",14,15,true);
						RockType(1*trQuestVarGet("Temp"));
					}
					else if((row > 9) && (row <= 15 )){
						trQuestVarSetFromRand("Lava",1,10,true);
						trQuestVarSetFromRand("Temp",15,16,true);
						if(1*trQuestVarGet("Lava") == 1){
							RockType(18);
						}
						else{
							RockType(1*trQuestVarGet("Temp"));
						}
					}
					else if((row > 3) && (row <= 9 )){
						trQuestVarSetFromRand("Temp",15,17,true);
						trQuestVarSetFromRand("Lava",1,8,true);
						if(1*trQuestVarGet("Lava") == 1){
							RockType(18);
						}
						else{
							RockType(1*trQuestVarGet("Temp"));
						}
					}
					else{
						trQuestVarSetFromRand("Lava",1,6,true);
						if(1*trQuestVarGet("Lava") == 1){
							RockType(18);
						}
						else{
							RockType(17);
						}
					}
				}
				if(Stage == 6){
					if(row > 18){
						RockType(19);
					}
					else if((row > 15) && (row <= 18 )){
						trQuestVarSetFromRand("Temp",19,21,true);
						RockType(1*trQuestVarGet("Temp"));
					}
					else if((row > 9) && (row <= 15 )){
						trQuestVarSetFromRand("Lava",1,10,true);
						trQuestVarSetFromRand("Temp",20,23,true);
						if(1*trQuestVarGet("Lava") == 1){
							RockType(18);
						}
						else{
							RockType(1*trQuestVarGet("Temp"));
						}
					}
					else if((row > 3) && (row <= 9 )){
						trQuestVarSetFromRand("Temp",21,24,true);
						trQuestVarSetFromRand("Lava",1,8,true);
						if(1*trQuestVarGet("Lava") == 1){
							RockType(26);
						}
						else{
							RockType(1*trQuestVarGet("Temp"));
						}
					}
					else if(row == 2){
						RockType(26);
					}
					else{
						trQuestVarSetFromRand("Temp",22,25,true);
						trQuestVarSetFromRand("Lava",1,6,true);
						if(1*trQuestVarGet("Lava") == 1){
							RockType(26);
						}
						else{
							RockType(1*trQuestVarGet("Temp"));
						}
					}
				}
				trPaintTerrain(4*col-1,4*row-1,4*col-3,4*row-3,TERRAIN_TYPE,TERRAIN_SUBTYPE,false);
				trQuestVarSet("R"+row+"C"+col+"CentreY", row*4-2);
				trQuestVarSet("R"+row+"C"+col+"CentreX", col*4-2);
				//trVectorQuestVarSet("R"+row+"C"+col+"", xsVectorSet(col*8-3, 3, row*8-3));
				//trQuestVarSet("R"+row+"C"+col+"Drilled", 0);
				//trQuestVarSet("R"+row+"C"+col+"HP", 0);
			}
		}
		/*
		trQuestVarEcho("R4C3CentreX");
		trQuestVarEcho("R4C3CentreY");
		trVectorQuestVarEcho("R4C3");
		trPaintTerrain(1*trQuestVarGet("R4C3CentreX"),
			1*trQuestVarGet("R4C3CentreY"),1*trQuestVarGet("R4C3CentreX"),
			1*trQuestVarGet("R4C3CentreY"),2,2,false);
		*/
		xsDisableSelf();
		trPaintTerrain(0,80,100,80,5,3,false);
		xsEnableRule("PaintLoot");
		xsEnableRule("PainSmeltShop");
		xsEnableRule("Selectables");
		//UnitCreate(0, "Hoplite", 20, 180, 180);
	}
}

rule PainSmeltShop
inactive
highFrequency
{
	int temp = 0;
	if(Stage == 1){
		PaintSmelter(20,180);
		PaintSellTerrain(15,89);
		temp = trGetNextUnitScenarioNameNumber();
		trArmyDispatch("0,0", "Dwarf", 1, 31,3,180, 90, true);
		xAddDatabaseBlock(dSelectables, true);
		xSetInt(dSelectables, xSelectablesName,temp);
		xSetInt(dSelectables, xSelectablesPrompt, 3);
		trUnitSelectClear();
		trUnitSelect(""+temp);
		trUnitChangeProtoUnit("Sign");
		trUnitSetVariation(temp, 2);
		trUnitSelectClear();
		trUnitSelect(""+temp);
		trUnitHighlight(1000, true);
		PaintFuelTerrain(80,89);
		temp = trGetNextUnitScenarioNameNumber();
		trArmyDispatch("0,0", "Dwarf", 1, 167,3,181, 90, true);
		xAddDatabaseBlock(dSelectables, true);
		xSetInt(dSelectables, xSelectablesName,temp);
		xSetInt(dSelectables, xSelectablesPrompt, 4);
		trUnitSelectClear();
		trUnitSelect(""+temp);
		trUnitChangeProtoUnit("Sign");
		trUnitSetVariation(temp, 2);
		trUnitSelectClear();
		trUnitSelect(""+temp);
		trUnitHighlight(1000, true);
		//fuel full pump
		PaintAtlantisArea(88,87,90,92,"GrassB");
		FSOneXMin = 176;
		FSOneXMax = 182;
		FSOneZMin = 174;
		FSOneZMax = 186;
		GVectorSellPos = vector(38,3,176);
		FloatingUnitAnimIdle("Earth", 190, -10, 190, 0, 4.5,-0.1,4.5);
		temp = 1*trQuestVarGet("QVRelic");
		trUnitSelectClear();
		trUnitSelect(""+temp);
		trUnitHighlight(1000, false);
		FloatingUnitAnimIdle("Earth", 10, -10, 190, 0, 4.5,-0.1,4.5);
		temp = 1*trQuestVarGet("QVRelic");
		trUnitSelectClear();
		trUnitSelect(""+temp);
		trUnitHighlight(1000, false);
		FloatingUnitAnimIdle("Earth", 105, -10, 190, 0, -4.5,-0.15,-4.5);
		temp = 1*trQuestVarGet("QVRelic");
		trUnitSelectClear();
		trUnitSelect(""+temp);
		trUnitHighlight(1000, false);
		trSetSunPosition(0,90,true);
		sunColor(255,255,255);
		ambientColor(255,255,100);
		terrainAmbient(255,255,255);
	}
	if(Stage == 2){
		FuelCost = 2;
		PaintSmelter(20,180);
		PaintSellTerrain(15,89);
		temp = trGetNextUnitScenarioNameNumber();
		trArmyDispatch("0,0", "Dwarf", 1, 31,3,180, 90, true);
		xAddDatabaseBlock(dSelectables, true);
		xSetInt(dSelectables, xSelectablesName,temp);
		xSetInt(dSelectables, xSelectablesPrompt, 3);
		trUnitSelectClear();
		trUnitSelect(""+temp);
		trUnitChangeProtoUnit("Sign");
		trUnitSetVariation(temp, 2);
		trUnitSelectClear();
		trUnitSelect(""+temp);
		trUnitHighlight(1000, true);
		PaintFuelTerrain(80,89);
		//fuel full pump
		temp = trGetNextUnitScenarioNameNumber();
		trArmyDispatch("0,0", "Dwarf", 1, 167,3,181, 90, true);
		xAddDatabaseBlock(dSelectables, true);
		xSetInt(dSelectables, xSelectablesName,temp);
		xSetInt(dSelectables, xSelectablesPrompt, 5);
		trUnitSelectClear();
		trUnitSelect(""+temp);
		trUnitChangeProtoUnit("Sign");
		trUnitSetVariation(temp, 2);
		trUnitSelectClear();
		trUnitSelect(""+temp);
		trUnitHighlight(1000, false);
		PaintAtlantisArea(88,87,90,89,"GrassA");
		FSOneXMin = 176;
		FSOneXMax = 182;
		FSOneZMin = 174;
		FSOneZMax = 180;
		PaintAtlantisArea(91,87,93,90,"GrassB");
		FSTwoXMin = 182;
		FSTwoXMax = 188;
		FSTwoZMin = 174;
		FSTwoZMax = 182;
		GVectorSellPos = vector(38,3,176);
		FloatingUnitAnimIdle("Earth", 190, -10, 190, 0, 4.5,-0.1,4.5);
		temp = 1*trQuestVarGet("QVRelic");
		trUnitSelectClear();
		trUnitSelect(""+temp);
		trUnitHighlight(1000, false);
		FloatingUnitAnimIdle("Earth", 10, -10, 190, 0, 4.5,-0.1,4.5);
		temp = 1*trQuestVarGet("QVRelic");
		trUnitSelectClear();
		trUnitSelect(""+temp);
		trUnitHighlight(1000, false);
		FloatingUnitAnimIdle("Earth", 105, -10, 190, 0, -4.5,-0.15,-4.5);
		temp = 1*trQuestVarGet("QVRelic");
		trUnitSelectClear();
		trUnitSelect(""+temp);
		trUnitHighlight(1000, false);
		temp = trGetNextUnitScenarioNameNumber();
		trArmyDispatch("0,0", "Dwarf", 1, 179,3,181, 0, true);
		trUnitSelectClear();
		trUnitSelect(""+temp);
		trUnitChangeProtoUnit("Flag Numbered");
		trUnitSetVariation(temp, 0);
		trUnitSelectClear();
		trUnitSelect(""+temp);
		trSetSelectedScale(2,2,2);
		temp = trGetNextUnitScenarioNameNumber();
		trArmyDispatch("0,0", "Dwarf", 1, 185,3,183, 0, true);
		trUnitSelectClear();
		trUnitSelect(""+temp);
		trUnitChangeProtoUnit("Flag Numbered");
		trUnitSetVariation(temp, 1);
		trUnitSelectClear();
		trUnitSelect(""+temp);
		trSetSelectedScale(2,2,2);
		sunColor(255,255,255);
		ambientColor(255,55,10);
		terrainAmbient(255,155,5);
	}
	if(Stage == 3){
		FuelCost = 4;
		PaintSmelter(20,180);
		PaintSellTerrain(15,89);
		SelectableSign(31, 180, 3);
		PaintFuelTerrain(80,89);
		//fuel full pump
		SelectableSign(167, 181, 5);
		PaintAtlantisArea(88,87,90,89,"GrassA");
		FSOneXMin = 176;
		FSOneXMax = 182;
		FSOneZMin = 174;
		FSOneZMax = 180;
		PaintAtlantisArea(91,87,93,90,"GrassB");
		FSTwoXMin = 182;
		FSTwoXMax = 188;
		FSTwoZMin = 174;
		FSTwoZMax = 182;
		GVectorSellPos = vector(38,3,176);
		temp = trGetNextUnitScenarioNameNumber();
		trArmyDispatch("0,0", "Dwarf", 1, 179,3,181, 0, true);
		trUnitSelectClear();
		trUnitSelect(""+temp);
		trUnitChangeProtoUnit("Flag Numbered");
		trUnitSetVariation(temp, 0);
		trUnitSelectClear();
		trUnitSelect(""+temp);
		trSetSelectedScale(2,2,2);
		temp = trGetNextUnitScenarioNameNumber();
		trArmyDispatch("0,0", "Dwarf", 1, 185,3,183, 0, true);
		trUnitSelectClear();
		trUnitSelect(""+temp);
		trUnitChangeProtoUnit("Flag Numbered");
		trUnitSetVariation(temp, 1);
		trUnitSelectClear();
		trUnitSelect(""+temp);
		trSetSelectedScale(2,2,2);
		//paint extra shop
		PaintShopTerrain(45,93);
		Shop1XMin = 43;
		Shop1XMax = 45;
		Shop1Cost = 2;
		Shop2XMin = 47;
		Shop2XMax = 49;
		Shop2Cost = 2;
		Shop3XMin = 51;
		Shop3XMax = 53;
		Shop3Cost = 20;
		PaintAtlantisArea(Shop1XMin,95,Shop1XMax,97,"CityTileAtlantis");
		PaintAtlantisArea(Shop2XMin,95,Shop2XMax,97,"UnderwaterRockF"); //UnderwaterRockF
		PaintAtlantisArea(Shop3XMin,95,Shop3XMax,97,"UnderwaterIceC"); //UnderwaterIceC
		xsEnableRule("ExtraShop");
		SelectableSign(88, 197, 7);
		SelectableSign(96, 197, 8);
		SelectableSign(104, 197, 9);
		xsEnableRule("Audrey");
		xsEnableRule("Rain");
		xsEnableRule("Ragnorok");
		temp = trGetNextUnitScenarioNameNumber();
		for(x=0; < 24){
			trArmyDispatch("0,0", "Victory Marker", 1, x*15,3,196, 180, true);
			trUnitSelectClear();
			trUnitSelect(""+(temp+x));
			trUnitChangeProtoUnit("UI Cloud Boarder");
			trUnitSelectClear();
			trUnitSelect(""+(temp+x));
			trSetSelectedScale(1, -0.3, -0.5);
			trUnitSelectClear();
			trUnitSelect(""+(temp+x));
			trSetSelectedUpVector(4,2,2);
		}
		trSetLighting("Dawn", 1.0);
	}
	if(Stage == 4){
		FuelCost = 8;
		PaintSmelter(20,180);
		PaintSellTerrain(15,89);
		SelectableSign(31, 180, 3);
		PaintFuelTerrain(80,89);
		//fuel full pump
		SelectableSign(167, 181, 11);
		PaintAtlantisArea(88,87,90,89,"GrassA");
		FSOneXMin = 176;
		FSOneXMax = 182;
		FSOneZMin = 174;
		FSOneZMax = 180;
		PaintAtlantisArea(91,87,93,90,"GrassB");
		FSTwoXMin = 182;
		FSTwoXMax = 188;
		FSTwoZMin = 174;
		FSTwoZMax = 182;
		GVectorSellPos = vector(38,3,176);
		temp = trGetNextUnitScenarioNameNumber();
		trArmyDispatch("0,0", "Dwarf", 1, 179,3,181, 0, true);
		trUnitSelectClear();
		trUnitSelect(""+temp);
		trUnitChangeProtoUnit("Flag Numbered");
		trUnitSetVariation(temp, 0);
		trUnitSelectClear();
		trUnitSelect(""+temp);
		trSetSelectedScale(2,2,2);
		temp = trGetNextUnitScenarioNameNumber();
		trArmyDispatch("0,0", "Dwarf", 1, 185,3,183, 0, true);
		trUnitSelectClear();
		trUnitSelect(""+temp);
		trUnitChangeProtoUnit("Flag Numbered");
		trUnitSetVariation(temp, 1);
		trUnitSelectClear();
		trUnitSelect(""+temp);
		trSetSelectedScale(2,2,2);
		//paint extra shop
		PaintShopTerrain(45,93);
		Shop1XMin = 43;
		Shop1XMax = 45;
		Shop1Cost = 4;
		Shop2XMin = 47;
		Shop2XMax = 49;
		Shop2Cost = 5;
		Shop3XMin = 51;
		Shop3XMax = 53;
		Shop3Cost = 25;
		Shop4XMin = 55;
		Shop4XMax = 57;
		Shop4Cost = 2;
		PaintAtlantisArea(Shop1XMin,95,Shop1XMax,97,"CityTileAtlantis");
		PaintAtlantisArea(Shop2XMin,95,Shop2XMax,97,"UnderwaterRockF"); //UnderwaterRockF
		PaintAtlantisArea(Shop3XMin,95,Shop3XMax,97,"UnderwaterIceC"); //UnderwaterIceC
		PaintAtlantisArea(Shop4XMin,95,Shop4XMax,97,"CityTileWaterPool");
		xsEnableRule("ExtraShop");
		SelectableSign(88, 197, 7);
		SelectableSign(96, 197, 8);
		SelectableSign(104, 197, 9);
		SelectableSign(112, 197, 13);
		xsEnableRule("Audrey");
		xsEnableRule("Rain");
		xsEnableRule("Ragnorok");
		temp = trGetNextUnitScenarioNameNumber();
		for(x=0; < 24){
			trArmyDispatch("0,0", "Victory Marker", 1, x*15,3,196, 180, true);
			trUnitSelectClear();
			trUnitSelect(""+(temp+x));
			trUnitChangeProtoUnit("UI Cloud Boarder");
			trUnitSelectClear();
			trUnitSelect(""+(temp+x));
			trSetSelectedScale(1, -0.3, -0.5);
			trUnitSelectClear();
			trUnitSelect(""+(temp+x));
			trSetSelectedUpVector(4,2,2);
		}
		sunColor(25,155,25);
		ambientColor(55,155,10);
		terrainAmbient(55,55,5);
	}
	if(Stage == 5){
		FuelCost = 10;
		PaintSmelter(20,180);
		PaintSellTerrain(15,89);
		SelectableSign(31, 180, 3);
		PaintHullTerrain(80,97);
		Hull1XMin = 88;
		Hull1XMax = 90;
		Hull2XMin = 91;
		Hull2XMax = 93;
		HullCost = 2;
		PaintAtlantisArea(Hull1XMin,95,Hull1XMax,97,"GrassA");
		PaintAtlantisArea(Hull2XMin,95,Hull2XMax,97,"GrassB");
		SelectableSign(167, 197, 15);
		temp = trGetNextUnitScenarioNameNumber();
		trArmyDispatch("0,0", "Dwarf", 1, 179,3,196, 0, true);
		trUnitSelectClear();
		trUnitSelect(""+temp);
		trUnitChangeProtoUnit("Flag Numbered");
		trUnitSetVariation(temp, 0);
		trUnitSelectClear();
		trUnitSelect(""+temp);
		trSetSelectedScale(2,2,2);
		temp = trGetNextUnitScenarioNameNumber();
		trArmyDispatch("0,0", "Dwarf", 1, 185,3,196, 0, true);
		trUnitSelectClear();
		trUnitSelect(""+temp);
		trUnitChangeProtoUnit("Flag Numbered");
		trUnitSetVariation(temp, 1);
		trUnitSelectClear();
		trUnitSelect(""+temp);
		trSetSelectedScale(2,2,2);
		
		PaintFuelTerrain(80,89);
		//fuel full pump
		SelectableSign(167, 181, 11);
		PaintAtlantisArea(88,87,90,89,"GrassA");
		FSOneXMin = 176;
		FSOneXMax = 182;
		FSOneZMin = 174;
		FSOneZMax = 180;
		PaintAtlantisArea(91,87,93,90,"GrassB");
		FSTwoXMin = 182;
		FSTwoXMax = 188;
		FSTwoZMin = 174;
		FSTwoZMax = 182;
		GVectorSellPos = vector(38,3,176);
		temp = trGetNextUnitScenarioNameNumber();
		trArmyDispatch("0,0", "Dwarf", 1, 179,3,181, 0, true);
		trUnitSelectClear();
		trUnitSelect(""+temp);
		trUnitChangeProtoUnit("Flag Numbered");
		trUnitSetVariation(temp, 0);
		trUnitSelectClear();
		trUnitSelect(""+temp);
		trSetSelectedScale(2,2,2);
		temp = trGetNextUnitScenarioNameNumber();
		trArmyDispatch("0,0", "Dwarf", 1, 185,3,183, 0, true);
		trUnitSelectClear();
		trUnitSelect(""+temp);
		trUnitChangeProtoUnit("Flag Numbered");
		trUnitSetVariation(temp, 1);
		trUnitSelectClear();
		trUnitSelect(""+temp);
		trSetSelectedScale(2,2,2);
		//paint extra shop
		PaintShopTerrain(45,93);
		Shop1XMin = 43;
		Shop1XMax = 45;
		Shop1Cost = 4;
		Shop2XMin = 47;
		Shop2XMax = 49;
		Shop2Cost = 5;
		Shop3XMin = 51;
		Shop3XMax = 53;
		Shop3Cost = 25;
		PaintAtlantisArea(Shop1XMin,95,Shop1XMax,97,"CityTileAtlantis");
		PaintAtlantisArea(Shop2XMin,95,Shop2XMax,97,"UnderwaterRockF"); //UnderwaterRockF
		PaintAtlantisArea(Shop3XMin,95,Shop3XMax,97,"UnderwaterIceC"); //UnderwaterIceC
		xsEnableRule("ExtraShop");
		SelectableSign(88, 197, 7);
		SelectableSign(96, 197, 8);
		SelectableSign(104, 197, 9);
		xsEnableRule("Audrey");
		xsEnableRule("Rain");
		xsEnableRule("Ragnorok");
		temp = trGetNextUnitScenarioNameNumber();
		for(x=0; < 24){
			trArmyDispatch("0,0", "Victory Marker", 1, x*15,3,196, 180, true);
			trUnitSelectClear();
			trUnitSelect(""+(temp+x));
			trUnitChangeProtoUnit("UI Cloud Boarder");
			trUnitSelectClear();
			trUnitSelect(""+(temp+x));
			trSetSelectedScale(1, -0.3, -0.5);
			trUnitSelectClear();
			trUnitSelect(""+(temp+x));
			trSetSelectedUpVector(4,6,2);
		}
		sunColor(57,22,102);
		ambientColor(17,15,200);
		terrainAmbient(55,55,100);
		xAddDatabaseBlock(dGasPocket, true);
		xSetPointer(dGasPocket, 1);
		trQuestVarSetFromRand("temp", 1, 20);
		xSetInt(dGasPocket, xGasCol, 1*trQuestVarGet("temp"));
		xSetInt(dGasPocket, xGasRow, 19);
		for(x=2; < 5*cNumberNonGaiaPlayers){
			xAddDatabaseBlock(dGasPocket, true);
			xSetPointer(dGasPocket, x);
			trQuestVarSetFromRand("temp", 1, 20);
			xSetInt(dGasPocket, xGasCol, 1*trQuestVarGet("temp"));
			trQuestVarSetFromRand("temp", 1, 17);
			xSetInt(dGasPocket, xGasRow, 1*trQuestVarGet("temp"));
		}
	}
	xsDisableSelf();
}

rule PaintLoot
inactive
highFrequency
{
	xsDisableSelf();
	for(col = 1; <= MaxCols){
		for(row = 1; <= MaxRows){
			vector v = xsVectorSet(col*8-4,0,row*8-4);
			if(Stage == 1){
				if((col > 5) && (col < 20)){
					if(row > 16){
						trQuestVarSetFromRand("Temp",1,15);
						if(1*trQuestVarGet("Temp") <= cNumberNonGaiaPlayers){
							spawnRelicSpecific(v,1);
						}
					}
					else if((row > 10) && (row <= 16)){
						trQuestVarSetFromRand("Temp",1,15);
						trQuestVarSetFromRand("Temp2",1,2);
						if(1*trQuestVarGet("Temp") <= cNumberNonGaiaPlayers){
							spawnRelicSpecific(v,1*trQuestVarGet("Temp2"));
						}
					}
					else if((row > 6) && (row <= 10)){
						trQuestVarSetFromRand("Temp",1,15);
						trQuestVarSetFromRand("Temp2",1,3);
						if(1*trQuestVarGet("Temp") <= cNumberNonGaiaPlayers){
							spawnRelicSpecific(v,1*trQuestVarGet("Temp2"));
						}
					}
					else if((row > 3) && (row <= 6)){
						trQuestVarSetFromRand("Temp",1,15);
						trQuestVarSetFromRand("Temp2",2,3);
						if(1*trQuestVarGet("Temp") <= cNumberNonGaiaPlayers){
							spawnRelicSpecific(v,1*trQuestVarGet("Temp2"));
						}
					}
					else if(row <= 3){
						trQuestVarSetFromRand("Temp",1,15);
						trQuestVarSetFromRand("Temp2",2,4);
						if(1*trQuestVarGet("Temp") <= cNumberNonGaiaPlayers){
							spawnRelicSpecific(v,1*trQuestVarGet("Temp2"));
						}
					}
				}
			}
			if(Stage == 2){
				if(row > 18){
					trQuestVarSetFromRand("Temp",1,15);
					if(1*trQuestVarGet("Temp") <= cNumberNonGaiaPlayers){
						spawnRelicSpecific(v,1);
					}
				}
				else if((row > 10) && (row <= 18)){
					trQuestVarSetFromRand("Temp",1,15);
					trQuestVarSetFromRand("Temp2",1,2);
					if(1*trQuestVarGet("Temp") <= cNumberNonGaiaPlayers){
						spawnRelicSpecific(v,1*trQuestVarGet("Temp2"));
					}
				}
				else if((row > 6) && (row <= 10)){
					trQuestVarSetFromRand("Temp",1,13);
					trQuestVarSetFromRand("Temp2",2,3);
					if(1*trQuestVarGet("Temp") <= cNumberNonGaiaPlayers){
						spawnRelicSpecific(v,1*trQuestVarGet("Temp2"));
					}
				}
				else if((row > 3) && (row <= 6)){
					trQuestVarSetFromRand("Temp",1,10);
					trQuestVarSetFromRand("Temp2",3,4);
					if(1*trQuestVarGet("Temp") <= cNumberNonGaiaPlayers){
						spawnRelicSpecific(v,1*trQuestVarGet("Temp2"));
					}
				}
				else if(row <= 3){
					trQuestVarSetFromRand("Temp",1,4);
					if(1*trQuestVarGet("Temp") == 3){
						trQuestVarSetFromRand("Temp2",3,4);
						spawnRelicSpecific(v,1*trQuestVarGet("Temp2"));
					}
				}
			}
			if(Stage == 3){
				if(row > 18){
					trQuestVarSetFromRand("Temp",1,15);
					if(1*trQuestVarGet("Temp") <= cNumberNonGaiaPlayers){
						spawnRelicSpecific(v,2);
					}
				}
				else if((row > 10) && (row <= 18)){
					trQuestVarSetFromRand("Temp",1,15);
					trQuestVarSetFromRand("Temp2",2,3);
					if(1*trQuestVarGet("Temp") <= cNumberNonGaiaPlayers){
						spawnRelicSpecific(v,1*trQuestVarGet("Temp2"));
					}
				}//
				else if((row > 6) && (row <= 10)){
					trQuestVarSetFromRand("Temp",1,13);
					trQuestVarSetFromRand("Temp2",3,4);
					if(1*trQuestVarGet("Temp") <= cNumberNonGaiaPlayers){
						spawnRelicSpecific(v,1*trQuestVarGet("Temp2"));
					}
				}
				else if((row > 3) && (row <= 6)){
					trQuestVarSetFromRand("Temp",1,9);
					trQuestVarSetFromRand("Temp2",3,4);
					if(1*trQuestVarGet("Temp") <= cNumberNonGaiaPlayers){
						spawnRelicSpecific(v,1*trQuestVarGet("Temp2"));
					}
				}
				else if(row <= 3){
					trQuestVarSetFromRand("Temp",1,4);
					if(1*trQuestVarGet("Temp") == 3){
						trQuestVarSetFromRand("Temp2",4,5);
						spawnRelicSpecific(v,1*trQuestVarGet("Temp2"));
					}
				}
			}
			if(Stage == 4){
				//iron first two rows
				if(row >= 19){
					spawnRelicSpecific(v,1);
				}
				
				else if((row > 17) && (row <= 18)){
					trQuestVarSetFromRand("Temp",1,15);
					trQuestVarSetFromRand("Temp2",6,6);
					if(1*trQuestVarGet("Temp") <= cNumberNonGaiaPlayers){
						spawnRelicSpecific(v,1*trQuestVarGet("Temp2"));
					}
				}
				else if((row > 10) && (row <= 16)){
					trQuestVarSetFromRand("Temp",1,13);
					trQuestVarSetFromRand("Temp2",2,5);
					if(1*trQuestVarGet("Temp") <= cNumberNonGaiaPlayers){
						spawnRelicSpecific(v,1*trQuestVarGet("Temp2"));
					}
				}
				else if((row > 5) && (row <= 10)){
					trQuestVarSetFromRand("Temp",1,9);
					trQuestVarSetFromRand("Temp2",3,6);
					if(1*trQuestVarGet("Temp") <= cNumberNonGaiaPlayers){
						spawnRelicSpecific(v,1*trQuestVarGet("Temp2"));
					}
				}
				else if(row <= 5){
					trQuestVarSetFromRand("Temp",1,6);
					if(1*trQuestVarGet("Temp") == 3){
						trQuestVarSetFromRand("Temp2",4,6);
						spawnRelicSpecific(v,1*trQuestVarGet("Temp2"));
					}
				}
			}
			if(Stage == 5){
				//iron first two rows
				if(row == 18){
					spawnRelicSpecific(v,3);
				}
				else if((row == 17)){
					trQuestVarSetFromRand("Temp",1,12);
					if(1*trQuestVarGet("Temp") == 1){
						spawnRelicSpecific(v,5);
					}
					else if(1*trQuestVarGet("Temp") == 2){
						spawnRelicSpecific(v,7);
					}
				}
				else if((row > 10) && (row <= 16)){
					trQuestVarSetFromRand("Temp",1,13);
					trQuestVarSetFromRand("Temp2",4,7);
					if(1*trQuestVarGet("Temp") <= cNumberNonGaiaPlayers){
						spawnRelicSpecific(v,1*trQuestVarGet("Temp2"));
					}
				}
				else if((row > 5) && (row <= 10)){
					trQuestVarSetFromRand("Temp",1,9);
					trQuestVarSetFromRand("Temp2",5,8);
					if(1*trQuestVarGet("Temp") <= cNumberNonGaiaPlayers){
						spawnRelicSpecific(v,1*trQuestVarGet("Temp2"));
					}
				}
				else if(row <= 5){
					trQuestVarSetFromRand("Temp",1,7);
					if(1*trQuestVarGet("Temp") == 3){
						trQuestVarSetFromRand("Temp2",6,9);
						spawnRelicSpecific(v,1*trQuestVarGet("Temp2"));
					}
				}
			}
		}
	}
	xsEnableRule("WallUp");
	trDelayedRuleActivation("ChangeRelics");
}

rule WallUp
inactive
highFrequency
{
	for(col = 1; <= MaxCols){
		for(row = 1; <= MaxRows){
			trUnitSelectByQV("R"+row+"C"+col+"WallX");
			trUnitChangeProtoUnit("Invisible Wall");
			trUnitSelectByQV("R"+row+"C"+col+"WallY");
			trUnitChangeProtoUnit("Invisible Wall");
		}
	}
	xsDisableSelf();
}
