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
		case 7:
		{
			OVERTERRAIN_TYPE = 4;
			OVERTERRAIN_SUBTYPE = 36;
		}
		case 8:
		{
			OVERTERRAIN_TYPE = 0;
			OVERTERRAIN_SUBTYPE = 51;
		}
		case 9:
		{
			OVERTERRAIN_TYPE = 0;
			OVERTERRAIN_SUBTYPE = 85;
		}
		case 10:
		{
			OVERTERRAIN_TYPE = 5;
			OVERTERRAIN_SUBTYPE = 4;
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
						RockType(32);
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
				if(Stage == 7){
					if(row > 18){
						RockType(26);
					}
					else if(row == 18){
						RockType(24);
					}
					else if((row > 11) && (row <= 17 )){
						trQuestVarSetFromRand("Lava",1,10,true);
						trQuestVarSetFromRand("Temp",20,24,true);
						if(1*trQuestVarGet("Lava") == 1){
							RockType(18);
						}
						else{
							RockType(1*trQuestVarGet("Temp"));
						}
					}
					else if((row > 5) && (row <= 11 )){
						trQuestVarSetFromRand("Temp",21,25,true);
						trQuestVarSetFromRand("Lava",1,8,true);
						if(1*trQuestVarGet("Lava") == 1){
							RockType(26);
						}
						else{
							RockType(1*trQuestVarGet("Temp"));
						}
					}
					else if((row > 2) && (row <= 5 )){
						RockType(26);
					}
					else{
						trQuestVarSetFromRand("Temp",24,25,true);
						trQuestVarSetFromRand("Lava",1,3,true);
						if(1*trQuestVarGet("Lava") == 1){
							RockType(26);
						}
						else{
							RockType(1*trQuestVarGet("Temp"));
						}
					}
				}
				if(Stage == 8){
					if(row > 18){
						RockType(27);
					}
					else if(row == 18){
						RockType(28);
					}
					else if((row > 15) && (row <= 17 )){
						RockType(29);
					}
					else if((row > 11) && (row <= 15 )){
						trQuestVarSetFromRand("Temp",30,32,true);
						RockType(1*trQuestVarGet("Temp"));
					}
					else if((row > 8) && (row <= 11 )){
						trQuestVarSetFromRand("Temp",31,32,true);
						RockType(1*trQuestVarGet("Temp"));
					}
					
					else if((row > 4) && (row <= 8 )){
						trQuestVarSetFromRand("Temp",33,34,true);
						RockType(1*trQuestVarGet("Temp"));
					}
					else{
						RockType(35);
					}
				}
				if(Stage == 9){
					if(row == 20){
						RockType(36);
						if(col <= 3){
							trQuestVarSetFromRand("Temp",21,25,true);
							RockType(1*trQuestVarGet("Temp"));
						}
					}
					else if((row >= 17) && (row <= 18)){
						trQuestVarSetFromRand("Temp",23,26,true);
						if(1*trQuestVarGet("Temp") == 26){
							RockType(18);
						}
						else{
							RockType(1*trQuestVarGet("Temp"));
						}
					}
					else if((row >= 14) && (row <= 16)){
						RockType(36);
						if(col >= 23){
							RockType(18);
						}
					}
					else if((row >= 11) && (row <= 13)){
						trQuestVarSetFromRand("Temp",37,40,true);
						if(1*trQuestVarGet("Temp") == 40){
							RockType(26);
						}
						else{
							RockType(1*trQuestVarGet("Temp"));
						}
					}
					else if((row >= 9) && (row <= 10)){
						RockType(36);
						if(col <= 2){
							RockType(26);
						}
					}
					else if((row >= 7) && (row <= 8)){
						//edit harder terrain
						trQuestVarSetFromRand("Temp",40,42,true);
						if(1*trQuestVarGet("Temp") == 42){
							RockType(26);
						}
						else{
							RockType(1*trQuestVarGet("Temp"));
						}
					}
					else if(row == 6){
						RockType(36);
						if(col >= 24){
							RockType(26);
						}
					}
					else if((row >= 4) && (row <= 5)){
						//edit
						trQuestVarSetFromRand("Temp",37,39,true);
						if(1*trQuestVarGet("Temp") < 39){
							RockType(26);
						}
						else{
							RockType(1*trQuestVarGet("Temp"));
						}
					}
					else if(row == 3){
						RockType(36);
						if(col <= 2){
							RockType(26);
						}
					}
					else if(row == 2){
						RockType(9);
					}
					else if(row == 1){
						RockType(36);
						if(col == 25){
							RockType(22);
						}
					}
					/*
					else{
						RockType(35);
					}*/
				}
				if(Stage == 10){
					if((row >= 19) && (row <= 20)){
						RockType(33);
					}
					else{
						RockType(36);
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
		MineT = 0;
		MineST = 14;
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
		MineT = 0;
		MineST = 10;
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
		SelectableSign(167, 181, 18);
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
		trChatSend(0, "Gas is col "+1*trQuestVarGet("temp")+"");
		for(x=2; < 5*cNumberNonGaiaPlayers){
			xAddDatabaseBlock(dGasPocket, true);
			xSetPointer(dGasPocket, x);
			trQuestVarSetFromRand("temp", 1, 20);
			xSetInt(dGasPocket, xGasCol, 1*trQuestVarGet("temp"));
			trQuestVarSetFromRand("temp", 1, 17);
			xSetInt(dGasPocket, xGasRow, 1*trQuestVarGet("temp"));
		}
	}
	if(Stage == 6){
		MineT = 0;
		MineST = 4;
		FuelCost = 12;
		PaintSmelter(20,180);
		PaintSellTerrain(15,89);
		SelectableSign(31, 180, 3);
		PaintHullTerrain(80,97);
		Hull1XMin = 88;
		Hull1XMax = 90;
		Hull2XMin = 91;
		Hull2XMax = 93;
		Hull3XMin = 94;
		Hull3XMax = 96;
		Hull4XMin = 97;
		Hull4XMax = 99;
		HullCost = 3;
		PaintAtlantisArea(Hull1XMin,95,Hull1XMax,97,"GrassA");
		PaintAtlantisArea(Hull2XMin,95,Hull2XMax,97,"GrassB");
		PaintAtlantisArea(Hull3XMin,95,Hull3XMax,97,"GrassB");
		PaintAtlantisArea(Hull4XMin,95,Hull4XMax,97,"GrassB");
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
		temp = trGetNextUnitScenarioNameNumber();
		trArmyDispatch("0,0", "Dwarf", 1, 191,3,196, 0, true);
		trUnitSelectClear();
		trUnitSelect(""+temp);
		trUnitChangeProtoUnit("Flag Numbered");
		trUnitSetVariation(temp, 2);
		trUnitSelectClear();
		trUnitSelect(""+temp);
		trSetSelectedScale(2,2,2);
		temp = trGetNextUnitScenarioNameNumber();
		trArmyDispatch("0,0", "Dwarf", 1, 197,3,196, 0, true);
		trUnitSelectClear();
		trUnitSelect(""+temp);
		trUnitChangeProtoUnit("Flag Numbered");
		trUnitSetVariation(temp, 3);
		trUnitSelectClear();
		trUnitSelect(""+temp);
		trSetSelectedScale(2,2,2);
		
		PaintFuelTerrain(80,89);
		//fuel full pump
		SelectableSign(167, 181, 18);
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
		Shop1Cost = 5;
		Shop2XMin = 47;
		Shop2XMax = 49;
		Shop2Cost = 20;
		Shop3XMin = 51;
		Shop3XMax = 53;
		Shop3Cost = 35;
		PaintAtlantisArea(Shop1XMin,95,Shop1XMax,97,"CityTileAtlantis");
		PaintAtlantisArea(Shop2XMin,95,Shop2XMax,97,"UnderwaterRockF"); //UnderwaterRockF
		PaintAtlantisArea(Shop3XMin,95,Shop3XMax,97,"UnderwaterIceC"); //UnderwaterIceC
		xsEnableRule("ExtraShop");
		SelectableSign(88, 197, 7);
		SelectableSign(96, 197, 17);
		SelectableSign(104, 197, 9);
		xsEnableRule("AudreyL2");
		xsEnableRule("Rain");
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
		sunColor(57,222,202);
		ambientColor(17,15,200);
		terrainAmbient(55,55,100);
		for(x=1; < 25){
			xAddDatabaseBlock(dGasPocket, true);
			xSetPointer(dGasPocket, x);
			trQuestVarSetFromRand("temp", 1, 20);
			xSetInt(dGasPocket, xGasCol, 1*trQuestVarGet("temp"));
			trQuestVarSetFromRand("temp", 1, 17);
			xSetInt(dGasPocket, xGasRow, 1*trQuestVarGet("temp"));
		}
	}
	if(Stage == 7){
		MineT = 0;
		MineST = 87;
		FuelCost = 15;
		PaintSmelter(20,180);
		PaintSellTerrain(15,89);
		SelectableSign(31, 180, 3);
		PaintHullTerrain(80,97);
		Hull1XMin = 88;
		Hull1XMax = 90;
		Hull2XMin = 91;
		Hull2XMax = 93;
		Hull3XMin = 94;
		Hull3XMax = 96;
		Hull4XMin = 97;
		Hull4XMax = 99;
		HullCost = 6;
		PaintAtlantisArea(Hull1XMin,95,Hull1XMax,97,"GrassA");
		PaintAtlantisArea(Hull2XMin,95,Hull2XMax,97,"GrassB");
		PaintAtlantisArea(Hull3XMin,95,Hull3XMax,97,"GrassB");
		PaintAtlantisArea(Hull4XMin,95,Hull4XMax,97,"GrassB");
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
		temp = trGetNextUnitScenarioNameNumber();
		trArmyDispatch("0,0", "Dwarf", 1, 191,3,196, 0, true);
		trUnitSelectClear();
		trUnitSelect(""+temp);
		trUnitChangeProtoUnit("Flag Numbered");
		trUnitSetVariation(temp, 3);
		trUnitSelectClear();
		trUnitSelect(""+temp);
		trSetSelectedScale(2,2,2);
		temp = trGetNextUnitScenarioNameNumber();
		trArmyDispatch("0,0", "Dwarf", 1, 197,3,196, 0, true);
		trUnitSelectClear();
		trUnitSelect(""+temp);
		trUnitChangeProtoUnit("Flag Numbered");
		trUnitSetVariation(temp, 7);
		trUnitSelectClear();
		trUnitSelect(""+temp);
		trSetSelectedScale(2,2,2);
		
		PaintFuelTerrain(80,89);
		//fuel full pump
		SelectableSign(167, 181, 18);
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
		PaintAtlantisArea(94,87,96,91,"GaiaCreepA");
		FSThreeXMin = 188;
		FSThreeXMax = 194;
		FSThreeZMin = 174;
		FSThreeZMax = 184;
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
		temp = trGetNextUnitScenarioNameNumber();
		trArmyDispatch("0,0", "Dwarf", 1, 191,3,185, 0, true);
		trUnitSelectClear();
		trUnitSelect(""+temp);
		trUnitChangeProtoUnit("Flag Numbered");
		trUnitSetVariation(temp, 2);
		trUnitSelectClear();
		trUnitSelect(""+temp);
		trSetSelectedScale(2,2,2);
		//paint extra shop
		PaintShopTerrain(45,93);
		Shop1XMin = 43;
		Shop1XMax = 45;
		Shop1Cost = 5;
		Shop2XMin = 47;
		Shop2XMax = 49;
		Shop2Cost = 40;
		Shop3XMin = 51;
		Shop3XMax = 53;
		Shop3Cost = 40;
		PaintAtlantisArea(Shop1XMin,95,Shop1XMax,97,"CityTileAtlantis");
		PaintAtlantisArea(Shop2XMin,95,Shop2XMax,97,"UnderwaterRockF"); //UnderwaterRockF
		PaintAtlantisArea(Shop3XMin,95,Shop3XMax,97,"UnderwaterIceC"); //UnderwaterIceC
		xsEnableRule("ExtraShop");
		SelectableSign(88, 197, 7);
		SelectableSign(96, 197, 17);
		SelectableSign(104, 197, 9);
		xsEnableRule("AudreyL2");
		xsEnableRule("Rain");
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
		sunColor(57,47,222);
		ambientColor(17,15,211);
		terrainAmbient(55,55,200);
		//Somehow this explodes on surface
		/*for(x=1; < 10){
			xAddDatabaseBlock(dGasPocket);
			xSetPointer(dGasPocket, x);
			trQuestVarSetFromRand("temp", 1, 19);
			xSetInt(dGasPocket, xGasCol, 1*trQuestVarGet("temp"));
			trQuestVarSetFromRand("temp", 18, 19);
			xSetInt(dGasPocket, xGasRow, 1*trQuestVarGet("temp"));
		}*/
		for(x=1; < 40){
			xAddDatabaseBlock(dGasPocket);
			xSetPointer(dGasPocket, x);
			trQuestVarSetFromRand("temp", 1, 20);
			xSetInt(dGasPocket, xGasCol, 1*trQuestVarGet("temp"));
			trQuestVarSetFromRand("temp", 1, 18);
			xSetInt(dGasPocket, xGasRow, 1*trQuestVarGet("temp"));
		}
	}
	if(Stage == 8){
		MineT = 0;
		MineST = 53;
		FuelCost = 25;
		PaintSmelter(20,180);
		PaintSellTerrain(15,89);
		SelectableSign(31, 180, 3);
		PaintHullTerrain(80,97);
		Hull1XMin = 88;
		Hull1XMax = 90;
		Hull2XMin = 91;
		Hull2XMax = 93;
		Hull3XMin = 94;
		Hull3XMax = 96;
		Hull4XMin = 97;
		Hull4XMax = 99;
		HullCost = 10;
		PaintAtlantisArea(Hull1XMin,95,Hull1XMax,97,"GrassA");
		PaintAtlantisArea(Hull2XMin,95,Hull2XMax,97,"GrassB");
		PaintAtlantisArea(Hull3XMin,95,Hull3XMax,97,"GrassB");
		PaintAtlantisArea(Hull4XMin,95,Hull4XMax,97,"GrassB");
		SelectableSign(167, 197, 15);
		temp = trGetNextUnitScenarioNameNumber();
		trArmyDispatch("0,0", "Dwarf", 1, 179,3,196, 0, true);
		trUnitSelectClear();
		trUnitSelect(""+temp);
		trUnitChangeProtoUnit("Flag Numbered");
		trUnitSetVariation(temp, 1);
		trUnitSelectClear();
		trUnitSelect(""+temp);
		trSetSelectedScale(2,2,2);
		temp = trGetNextUnitScenarioNameNumber();
		trArmyDispatch("0,0", "Dwarf", 1, 185,3,196, 0, true);
		trUnitSelectClear();
		trUnitSelect(""+temp);
		trUnitChangeProtoUnit("Flag Numbered");
		trUnitSetVariation(temp, 3);
		trUnitSelectClear();
		trUnitSelect(""+temp);
		trSetSelectedScale(2,2,2);
		temp = trGetNextUnitScenarioNameNumber();
		trArmyDispatch("0,0", "Dwarf", 1, 191,3,196, 0, true);
		trUnitSelectClear();
		trUnitSelect(""+temp);
		trUnitChangeProtoUnit("Flag Numbered");
		trUnitSetVariation(temp, 7);
		trUnitSelectClear();
		trUnitSelect(""+temp);
		trSetSelectedScale(2,2,2);
		temp = trGetNextUnitScenarioNameNumber();
		trArmyDispatch("0,0", "Dwarf", 1, 197,3,196, 0, true);
		trUnitSelectClear();
		trUnitSelect(""+temp);
		trUnitChangeProtoUnit("Flag Numbered");
		trUnitSetVariation(temp, 9);
		trUnitSelectClear();
		trUnitSelect(""+temp);
		trSetSelectedScale(2,2,2);
		
		PaintFuelTerrain(80,89);
		//fuel full pump
		SelectableSign(167, 181, 18);
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
		PaintAtlantisArea(94,87,96,91,"GaiaCreepA");
		FSThreeXMin = 188;
		FSThreeXMax = 194;
		FSThreeZMin = 174;
		FSThreeZMax = 184;
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
		temp = trGetNextUnitScenarioNameNumber();
		trArmyDispatch("0,0", "Dwarf", 1, 191,3,185, 0, true);
		trUnitSelectClear();
		trUnitSelect(""+temp);
		trUnitChangeProtoUnit("Flag Numbered");
		trUnitSetVariation(temp, 2);
		trUnitSelectClear();
		trUnitSelect(""+temp);
		trSetSelectedScale(2,2,2);
		//paint extra shop
		PaintShopTerrain(45,93);
		Shop1XMin = 43;
		Shop1XMax = 45;
		Shop1Cost = 5;
		Shop2XMin = 47;
		Shop2XMax = 49;
		Shop2Cost = 125;
		Shop3XMin = 51;
		Shop3XMax = 53;
		Shop3Cost = 40;
		PaintAtlantisArea(Shop1XMin,95,Shop1XMax,97,"CityTileAtlantis");
		PaintAtlantisArea(Shop2XMin,95,Shop2XMax,97,"UnderwaterRockF"); //UnderwaterRockF
		PaintAtlantisArea(Shop3XMin,95,Shop3XMax,97,"UnderwaterIceC"); //UnderwaterIceC
		xsEnableRule("ExtraShop");
		SelectableSign(88, 197, 7);
		SelectableSign(96, 197, 21);
		SelectableSign(104, 197, 9);
		xsEnableRule("AudreyL2");
		xsEnableRule("Rain");
		temp = trGetNextUnitScenarioNameNumber();
		for(x=0; < 48){
			if (iModulo(2, x) == 0) { //if is divisble by 2
				trArmyDispatch("0,0", "Victory Marker", 1, x*7.5,3,199, 180, true);
			}
			else{trArmyDispatch("0,0", "Victory Marker", 1, x*7.5,3,199, 0, true);
			}
			trUnitSelectClear();
			trUnitSelect(""+(temp+x));
			trUnitChangeProtoUnit("Ice Block");
			trUnitSelectClear();
			trUnitSelect(""+(temp+x));
			trSetSelectedScale(20, 10, 0.2);
			trUnitSelectClear();
			trUnitSelect(""+(temp+x));
			trSetSelectedUpVector(1,6,0.2);
		}
		trSetLighting("Fimbulwinter", 0.1);
		for(x=1; < 40){
			xAddDatabaseBlock(dGasPocket, true);
			xSetPointer(dGasPocket, x);
			trQuestVarSetFromRand("temp", 1, 20);
			xSetInt(dGasPocket, xGasCol, 1*trQuestVarGet("temp"));
			trQuestVarSetFromRand("temp", 1, 18);
			xSetInt(dGasPocket, xGasRow, 1*trQuestVarGet("temp"));
		}
	}
	if(Stage == 9){
		MineT = 5;
		MineST = 8;
		FuelCost = 30;
		PaintSmelter(20,180);
		PaintSellTerrain(15,89);
		SelectableSign(31, 180, 3);
		PaintHullTerrain(80,97);
		Hull1XMin = 88;
		Hull1XMax = 90;
		Hull2XMin = 91;
		Hull2XMax = 93;
		Hull3XMin = 94;
		Hull3XMax = 96;
		Hull4XMin = 97;
		Hull4XMax = 99;
		HullCost = 10;
		PaintAtlantisArea(Hull1XMin,95,Hull1XMax,97,"GrassA");
		PaintAtlantisArea(Hull2XMin,95,Hull2XMax,97,"GrassB");
		PaintAtlantisArea(Hull3XMin,95,Hull3XMax,97,"GrassB");
		PaintAtlantisArea(Hull4XMin,95,Hull4XMax,97,"GrassB");
		SelectableSign(167, 197, 15);
		temp = trGetNextUnitScenarioNameNumber();
		trArmyDispatch("0,0", "Dwarf", 1, 179,3,196, 0, true);
		trUnitSelectClear();
		trUnitSelect(""+temp);
		trUnitChangeProtoUnit("Flag Numbered");
		trUnitSetVariation(temp, 1);
		trUnitSelectClear();
		trUnitSelect(""+temp);
		trSetSelectedScale(2,2,2);
		temp = trGetNextUnitScenarioNameNumber();
		trArmyDispatch("0,0", "Dwarf", 1, 185,3,196, 0, true);
		trUnitSelectClear();
		trUnitSelect(""+temp);
		trUnitChangeProtoUnit("Flag Numbered");
		trUnitSetVariation(temp, 3);
		trUnitSelectClear();
		trUnitSelect(""+temp);
		trSetSelectedScale(2,2,2);
		temp = trGetNextUnitScenarioNameNumber();
		trArmyDispatch("0,0", "Dwarf", 1, 191,3,196, 0, true);
		trUnitSelectClear();
		trUnitSelect(""+temp);
		trUnitChangeProtoUnit("Flag Numbered");
		trUnitSetVariation(temp, 7);
		trUnitSelectClear();
		trUnitSelect(""+temp);
		trSetSelectedScale(2,2,2);
		temp = trGetNextUnitScenarioNameNumber();
		trArmyDispatch("0,0", "Dwarf", 1, 197,3,196, 0, true);
		trUnitSelectClear();
		trUnitSelect(""+temp);
		trUnitChangeProtoUnit("Flag Numbered");
		trUnitSetVariation(temp, 9);
		trUnitSelectClear();
		trUnitSelect(""+temp);
		trSetSelectedScale(2,2,2);
		PaintFuelTerrain(80,89);
		//fuel full pump
		SelectableSign(167, 181, 18);
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
		PaintAtlantisArea(94,87,96,91,"GaiaCreepA");
		FSThreeXMin = 188;
		FSThreeXMax = 194;
		FSThreeZMin = 174;
		FSThreeZMax = 184;
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
		temp = trGetNextUnitScenarioNameNumber();
		trArmyDispatch("0,0", "Dwarf", 1, 191,3,185, 0, true);
		trUnitSelectClear();
		trUnitSelect(""+temp);
		trUnitChangeProtoUnit("Flag Numbered");
		trUnitSetVariation(temp, 2);
		trUnitSelectClear();
		trUnitSelect(""+temp);
		trSetSelectedScale(2,2,2);
		//paint extra shop
		PaintShopTerrain(45,93);
		Shop1XMin = 43;
		Shop1XMax = 45;
		Shop1Cost = 5;
		Shop2XMin = 47;
		Shop2XMax = 49;
		Shop2Cost = 125;
		Shop3XMin = 51;
		Shop3XMax = 53;
		Shop3Cost = 40;
		PaintAtlantisArea(Shop1XMin,95,Shop1XMax,97,"CityTileAtlantis");
		PaintAtlantisArea(Shop2XMin,95,Shop2XMax,97,"UnderwaterRockF"); //UnderwaterRockF
		PaintAtlantisArea(Shop3XMin,95,Shop3XMax,97,"UnderwaterIceC"); //UnderwaterIceC
		xsEnableRule("ExtraShop");
		SelectableSign(88, 197, 7);
		SelectableSign(96, 197, 21);
		SelectableSign(104, 197, 9);
		//end
		xsEnableRule("AudreyL2");
		xsEnableRule("Rain");
		temp = trGetNextUnitScenarioNameNumber();
		for(x=0; < 24){
			if (iModulo(2, x) == 0) { //if is divisble by 2
				trArmyDispatch("0,0", "Victory Marker", 1, x*15,3,199.8, 180, true);
			}
			else{trArmyDispatch("0,0", "Victory Marker", 1, x*15,3,199.8, 0, true);
			}
			trUnitSelectClear();
			trUnitSelect(""+(temp+x));
			trUnitChangeProtoUnit("Spy Eye");
			trUnitSelectClear();
			trUnitSelect(""+(temp+x));
			trMutateSelected(kbGetProtoUnitID("Bolder Rolling"));
			trUnitSelectClear();
			trUnitSelect(""+(temp+x));
			trSetSelectedScale(10, 3, 0.1);
		}
		sunColor(57,20,2);
		ambientColor(57,55,40);
		terrainAmbient(255,155,155);
		for(x=1; < 40){
			xAddDatabaseBlock(dGasPocket, true);
			xSetPointer(dGasPocket, x);
			trQuestVarSetFromRand("temp", 1, 20);
			xSetInt(dGasPocket, xGasCol, 1*trQuestVarGet("temp"));
			trQuestVarSetFromRand("temp", 1, 18);
			xSetInt(dGasPocket, xGasRow, 1*trQuestVarGet("temp"));
		}
	}
	if(Stage == 10){
		MineT = 0;
		MineST = 70;
		FuelCost = 1;
		xsEnableRule("AudreyL2");
		temp = trGetNextUnitScenarioNameNumber();
		for(x=0; < 147){
			trQuestVarSetFromRand("TempX",1,200);
			trQuestVarSetFromRand("TempZ",170,199);
			trArmyDispatch("0,0", "Victory Marker", 1, 1*trQuestVarGet("TempX"),3,1*trQuestVarGet("TempZ"), 0, true);
			trUnitSelectClear();
			trUnitSelect(""+(temp+x));
			trUnitChangeProtoUnit("Armor Glow Small");
		}
		trPlayerSetDiplomacy(cNumberNonGaiaPlayers,1,"Ally");
		trPlayerSetDiplomacy(1,cNumberNonGaiaPlayers,"Ally");
		sunColor(57,20,2);
		ambientColor(57,55,40);
		terrainAmbient(255,155,155);
		//This is the ship layout
		for(a=1; <= 25){
			Layout(18,a);
			if(iModulo(3, a) == 0){
				Layout(17,a);
				//Trap 1
				trPaintTerrain(a*4-4,69,a*4-4,71,0,73,false);
				trPaintTerrain(a*4-4,68,a*4-4,68,2,13,false);
				trPaintTerrain(a*4-4,72,a*4-4,72,2,13,false);
				xAddDatabaseBlock(dTrap);
				xSetPointer(dTrap, xGetDatabaseCount(dTrap));
				xSetInt(dTrap, xTrapXMin, a*8-8);
				xSetInt(dTrap, xTrapXMax, a*8-6);
				xSetInt(dTrap, xTrapZMin, 69*2);
				xSetInt(dTrap, xTrapZMax, 71*2+2);
				xSetInt(dTrap, xTrapType, 1);
				xSetBool(dTrap, xTrapOn, true);
				xSetBool(dTrap, xTrapReady, true);
				xSetInt(dTrap, xTrapReset, 5000);
				xSetInt(dTrap, xTrapUnit, 1*trGetNextUnitScenarioNameNumber());
				xSetVector(dTrap, xTrapHitVector, xsVectorSet(a*8-4,3,132));
				xSetInt(dTrap, xTrapHitboxX, 4);
				xSetInt(dTrap, xTrapHitboxZ, 4);
				temp = trGetNextUnitScenarioNameNumber();
				trArmyDispatch("0,0", "Dwarf", 1, a*8-4,3,132, 0, true);
				trUnitSelectClear();
				trUnitSelect(""+temp);
				trUnitChangeProtoUnit("Spy Eye");
				trUnitSelectClear();
				trUnitSelect(""+temp);
				trMutateSelected(kbGetProtoUnitID("Tartarian Gate"));
				trUnitSelectClear();
				trUnitSelect(""+temp);
				trSetSelectedScale(0.5,-0.5,0.5);
				trUnitSelectClear();
				trUnitSelect(""+temp);
				trUnitOverrideAnimation(2,0,true,true,-1,-1);
				trUnitSelectClear();
				trUnitSelect(""+temp);
				trUnitSetAnimationPath("0,0,1,1,0,0");
			}
		}
		Layout(16,24);
		for(a=1; <=25){
			Layout(15,a);
		}
		for(a=1; <=5){
			temp = trGetNextUnitScenarioNameNumber();
			trArmyDispatch("0,0", "Dwarf", 1, 182+a*2,3,126, 0, true);
			trUnitSelectClear();
			trUnitSelect(""+temp);
			trUnitChangeProtoUnit("Wall Connector");
			trUnitSelectClear();
			trUnitSelect(""+temp);
			trUnitSetAnimationPath("3,2,0,0,0,0");
			trUnitSelectClear();
			trUnitSelect(""+temp);
			trSetSelectedScale(1.2,1,1.2);
			xAddDatabaseBlock(dKey, true);
			xSetInt(dKey, xKeyUnitName, temp);
			xSetInt(dKey, xKey, RELIC_KEY_CHINA);
		}
		GVectorChinese = vector(188,3,126);
		FloatingUnitAnimIdle("UI Range Indicator Chinese SFX", 188, 6.5, 126, 0, 1,1,1);
		xAddDatabaseBlock(dKey, true);
		xSetInt(dKey, xKeyUnitName, 1*trQuestVarGet("QVHero"));
		xSetInt(dKey, xKey, RELIC_KEY_CHINA);
		xAddDatabaseBlock(dKey, true);
		xSetInt(dKey, xKeyUnitName, 1*trQuestVarGet("QVRelic"));
		xSetInt(dKey, xKey, RELIC_KEY_CHINA);
		//TRAP 1 a=3
		
		//--a=6
		/*
		trPaintTerrain(19,68,19,72,0,73,false);
		xAddDatabaseBlock(dTrap);
		xSetPointer(dTrap, xGetDatabaseCount(dTrap));
		xSetInt(dTrap, xTrapXMin, 38);
		xSetInt(dTrap, xTrapXMax, 40);
		xSetInt(dTrap, xTrapZMin, 68*2);
		xSetInt(dTrap, xTrapZMax, 72*2+2);
		xSetInt(dTrap, xTrapType, 1);
		xSetBool(dTrap, xTrapOn, true);
		xSetBool(dTrap, xTrapReady, true);
		xSetInt(dTrap, xTrapReset, 1000);
		xSetInt(dTrap, xTrapUnit, 1*trGetNextUnitScenarioNameNumber());
		temp = trGetNextUnitScenarioNameNumber();
		trArmyDispatch("0,0", "Dwarf", 1, 44,3,132, 0, true);
		trUnitSelectClear();
		trUnitSelect(""+temp);
		trUnitChangeProtoUnit("Spy Eye");
		trUnitSelectClear();
		trUnitSelect(""+temp);
		trMutateSelected(kbGetProtoUnitID("Tartarian Gate"));
		trUnitSelectClear();
		trUnitSelect(""+temp);
		trSetSelectedScale(0.5,-0.5,0.5);
		trUnitSelectClear();
		trUnitSelect(""+temp);
		trUnitOverrideAnimation(2,0,true,true,-1,-1);
		trUnitSelectClear();
		trUnitSelect(""+temp);
		trUnitSetAnimationPath("0,0,1,1,0,0");*/
		//TRAP 2
		trPaintTerrain(85,56,85,59,0,73,false);
		xAddDatabaseBlock(dTrap);
		xSetPointer(dTrap, xGetDatabaseCount(dTrap));
		xSetInt(dTrap, xTrapXMin, 85*2);
		xSetInt(dTrap, xTrapXMax, 85*2+2);
		xSetInt(dTrap, xTrapZMin, 56*2);
		xSetInt(dTrap, xTrapZMax, 59*2+2);
		xSetInt(dTrap, xTrapType, 2);
		xSetBool(dTrap, xTrapOn, true);
		xSetBool(dTrap, xTrapReady, true);
		xSetInt(dTrap, xTrapReset, 20000);
		xSetVector(dTrap, xTrapStartVector, vector(171,3,124));
		//Direction
		xSetVector(dTrap, xTrapTargetVector, vector(0,0,-16));
		xSetInt(dTrap, xTrapUnit, 1*trGetNextUnitScenarioNameNumber());
		temp = trGetNextUnitScenarioNameNumber();
		trArmyDispatch(""+cNumberNonGaiaPlayers+",0", "Dwarf", 1, 171,3,124, 0, true);
		trUnitSelectClear();
		trUnitSelect(""+temp);
		trUnitChangeProtoUnit("Lampades");
		trUnitSelectClear();
		trUnitSelect(""+temp);
		trSetSelectedScale(0,0,0);
		temp = trGetNextUnitScenarioNameNumber();
		trArmyDispatch(""+cNumberNonGaiaPlayers+",0", "Dwarf", 1, 171,3,124, 0, true);
		trUnitSelectClear();
		trUnitSelect(""+temp);
		trUnitChangeProtoUnit("Wall Connector");
		trUnitSelectClear();
		trUnitSelect(""+temp);
		trUnitTeleport(171,3,124);
		
		//TRAP 2
		trPaintTerrain(80,56,80,59,0,73,false);
		xAddDatabaseBlock(dTrap);
		xSetPointer(dTrap, xGetDatabaseCount(dTrap));
		xSetInt(dTrap, xTrapXMin, 80*2);
		xSetInt(dTrap, xTrapXMax, 80*2+2);
		xSetInt(dTrap, xTrapZMin, 56*2);
		xSetInt(dTrap, xTrapZMax, 59*2+2);
		xSetInt(dTrap, xTrapType, 2);
		xSetBool(dTrap, xTrapOn, true);
		xSetBool(dTrap, xTrapReady, true);
		xSetInt(dTrap, xTrapReset, 20000);
		xSetVector(dTrap, xTrapStartVector, vector(151,3,124));
		//Direction
		xSetVector(dTrap, xTrapTargetVector, vector(0,0,-16));
		xSetInt(dTrap, xTrapUnit, 1*trGetNextUnitScenarioNameNumber());
		temp = trGetNextUnitScenarioNameNumber();
		trArmyDispatch(""+cNumberNonGaiaPlayers+",0", "Dwarf", 1, 151,3,124, 0, true);
		trUnitSelectClear();
		trUnitSelect(""+temp);
		trUnitChangeProtoUnit("Lampades");
		trUnitSelectClear();
		trUnitSelect(""+temp);
		trSetSelectedScale(0,0,0);
		temp = trGetNextUnitScenarioNameNumber();
		trArmyDispatch(""+cNumberNonGaiaPlayers+",0", "Dwarf", 1, 151,3,124, 0, true);
		trUnitSelectClear();
		trUnitSelect(""+temp);
		trUnitChangeProtoUnit("Wall Connector");
		trUnitSelectClear();
		trUnitSelect(""+temp);
		trUnitTeleport(151,3,124);
		
		//TRAP 2
		trPaintTerrain(70,56,70,59,0,73,false);
		xAddDatabaseBlock(dTrap);
		xSetPointer(dTrap, xGetDatabaseCount(dTrap));
		xSetInt(dTrap, xTrapXMin, 70*2);
		xSetInt(dTrap, xTrapXMax, 70*2+2);
		xSetInt(dTrap, xTrapZMin, 56*2);
		xSetInt(dTrap, xTrapZMax, 59*2+2);
		xSetInt(dTrap, xTrapType, 2);
		xSetBool(dTrap, xTrapOn, true);
		xSetBool(dTrap, xTrapReady, true);
		xSetInt(dTrap, xTrapReset, 20000);
		xSetVector(dTrap, xTrapStartVector, vector(131,3,108));
		//Direction
		xSetVector(dTrap, xTrapTargetVector, vector(0,0,16));
		xSetInt(dTrap, xTrapUnit, 1*trGetNextUnitScenarioNameNumber());
		temp = trGetNextUnitScenarioNameNumber();
		trArmyDispatch(""+cNumberNonGaiaPlayers+",0", "Dwarf", 1, 131,3,108, 0, true);
		trUnitSelectClear();
		trUnitSelect(""+temp);
		trUnitChangeProtoUnit("Lampades");
		trUnitSelectClear();
		trUnitSelect(""+temp);
		trSetSelectedScale(0,0,0);
		temp = trGetNextUnitScenarioNameNumber();
		trArmyDispatch(""+cNumberNonGaiaPlayers+",0", "Dwarf", 1, 131,3,108, 0, true);
		trUnitSelectClear();
		trUnitSelect(""+temp);
		trUnitChangeProtoUnit("Wall Connector");
		trUnitSelectClear();
		trUnitSelect(""+temp);
		trUnitTeleport(131,3,108);
		
		//TRAP 2
		trPaintTerrain(60,56,60,59,0,73,false);
		xAddDatabaseBlock(dTrap);
		xSetPointer(dTrap, xGetDatabaseCount(dTrap));
		xSetInt(dTrap, xTrapXMin, 60*2);
		xSetInt(dTrap, xTrapXMax, 60*2+2);
		xSetInt(dTrap, xTrapZMin, 56*2);
		xSetInt(dTrap, xTrapZMax, 59*2+2);
		xSetInt(dTrap, xTrapType, 2);
		xSetBool(dTrap, xTrapOn, true);
		xSetBool(dTrap, xTrapReady, true);
		xSetInt(dTrap, xTrapReset, 20000);
		xSetVector(dTrap, xTrapStartVector, vector(131,3,124));
		//Direction
		xSetVector(dTrap, xTrapTargetVector, vector(0,0,-16));
		xSetInt(dTrap, xTrapUnit, 1*trGetNextUnitScenarioNameNumber());
		temp = trGetNextUnitScenarioNameNumber();
		trArmyDispatch(""+cNumberNonGaiaPlayers+",0", "Dwarf", 1, 131,3,124, 0, true);
		trUnitSelectClear();
		trUnitSelect(""+temp);
		trUnitChangeProtoUnit("Lampades");
		trUnitSelectClear();
		trUnitSelect(""+temp);
		trSetSelectedScale(0,0,0);
		temp = trGetNextUnitScenarioNameNumber();
		trArmyDispatch(""+cNumberNonGaiaPlayers+",0", "Dwarf", 1, 131,3,124, 0, true);
		trUnitSelectClear();
		trUnitSelect(""+temp);
		trUnitChangeProtoUnit("Wall Connector");
		trUnitSelectClear();
		trUnitSelect(""+temp);
		trUnitTeleport(131,3,124);
		
		//TRAP 2
		trPaintTerrain(53,56,54,57,0,73,false);
		xAddDatabaseBlock(dTrap);
		xSetPointer(dTrap, xGetDatabaseCount(dTrap));
		xSetInt(dTrap, xTrapXMin, 53*2);
		xSetInt(dTrap, xTrapXMax, 54*2+2);
		xSetInt(dTrap, xTrapZMin, 56*2);
		xSetInt(dTrap, xTrapZMax, 57*2+2);
		xSetInt(dTrap, xTrapType, 2);
		xSetBool(dTrap, xTrapOn, true);
		xSetBool(dTrap, xTrapReady, true);
		xSetInt(dTrap, xTrapReset, 20000);
		xSetVector(dTrap, xTrapStartVector, vector(101,3,114));
		//Direction
		xSetVector(dTrap, xTrapTargetVector, vector(-100,0,0));
		xSetInt(dTrap, xTrapUnit, 1*trGetNextUnitScenarioNameNumber());
		temp = trGetNextUnitScenarioNameNumber();
		trArmyDispatch(""+cNumberNonGaiaPlayers+",0", "Dwarf", 1, 101,3,114, 0, true);
		trUnitSelectClear();
		trUnitSelect(""+temp);
		trUnitChangeProtoUnit("Lampades");
		trUnitSelectClear();
		trUnitSelect(""+temp);
		trSetSelectedScale(0,0,0);
		temp = trGetNextUnitScenarioNameNumber();
		trArmyDispatch(""+cNumberNonGaiaPlayers+",0", "Dwarf", 1, 101,3,114, 0, true);
		trUnitSelectClear();
		trUnitSelect(""+temp);
		trUnitChangeProtoUnit("Wall Connector");
		trUnitSelectClear();
		trUnitSelect(""+temp);
		trUnitTeleport(101,3,114);
		
		//Trap 1
		trPaintTerrain(50,56,50,59,0,73,false);
		xAddDatabaseBlock(dTrap);
		xSetPointer(dTrap, xGetDatabaseCount(dTrap));
		xSetInt(dTrap, xTrapXMin, 50*2);
		xSetInt(dTrap, xTrapXMax, 50*2+2);
		xSetInt(dTrap, xTrapZMin, 56*2);
		xSetInt(dTrap, xTrapZMax, 59*2+2);
		xSetInt(dTrap, xTrapType, 1);
		xSetBool(dTrap, xTrapOn, true);
		xSetBool(dTrap, xTrapReady, true);
		xSetInt(dTrap, xTrapReset, 5000);
		xSetInt(dTrap, xTrapUnit, 1*trGetNextUnitScenarioNameNumber());
		xSetVector(dTrap, xTrapHitVector, xsVectorSet(115,3,117));
		xSetInt(dTrap, xTrapHitboxX, 4);
		xSetInt(dTrap, xTrapHitboxZ, 4);
		temp = trGetNextUnitScenarioNameNumber();
		trArmyDispatch("0,0", "Dwarf", 1, 115,3,117, 0, true);
		trUnitSelectClear();
		trUnitSelect(""+temp);
		trUnitChangeProtoUnit("Spy Eye");
		trUnitSelectClear();
		trUnitSelect(""+temp);
		trMutateSelected(kbGetProtoUnitID("Tartarian Gate"));
		trUnitSelectClear();
		trUnitSelect(""+temp);
		trSetSelectedScale(0.5,-0.5,0.5);
		trUnitSelectClear();
		trUnitSelect(""+temp);
		trUnitOverrideAnimation(2,0,true,true,-1,-1);
		trUnitSelectClear();
		trUnitSelect(""+temp);
		trUnitSetAnimationPath("0,0,1,1,0,0");
		
		//TRAP 2
		trPaintTerrain(23,58,24,59,0,73,false);
		xAddDatabaseBlock(dTrap);
		xSetPointer(dTrap, xGetDatabaseCount(dTrap));
		xSetInt(dTrap, xTrapXMin, 23*2);
		xSetInt(dTrap, xTrapXMax, 24*2+2);
		xSetInt(dTrap, xTrapZMin, 58*2);
		xSetInt(dTrap, xTrapZMax, 59*2+2);
		xSetInt(dTrap, xTrapType, 2);
		xSetBool(dTrap, xTrapOn, true);
		xSetBool(dTrap, xTrapReady, true);
		xSetInt(dTrap, xTrapReset, 20000);
		xSetVector(dTrap, xTrapStartVector, vector(21,3,118));
		//Direction
		xSetVector(dTrap, xTrapTargetVector, vector(167,0,0));
		xSetInt(dTrap, xTrapUnit, 1*trGetNextUnitScenarioNameNumber());
		temp = trGetNextUnitScenarioNameNumber();
		trArmyDispatch(""+cNumberNonGaiaPlayers+",0", "Dwarf", 1, 21,3,118, 0, true);
		trUnitSelectClear();
		trUnitSelect(""+temp);
		trUnitChangeProtoUnit("Lampades");
		trUnitSelectClear();
		trUnitSelect(""+temp);
		trSetSelectedScale(0,0,0);
		temp = trGetNextUnitScenarioNameNumber();
		trArmyDispatch(""+cNumberNonGaiaPlayers+",0", "Dwarf", 1, 21,3,118, 0, true);
		trUnitSelectClear();
		trUnitSelect(""+temp);
		trUnitChangeProtoUnit("Wall Connector");
		trUnitSelectClear();
		trUnitSelect(""+temp);
		trUnitTeleport(21,3,118);
	}
	xsEnableRule("Ragnorok");
	xsDisableSelf();
	trPaintTerrain(0,80,100,80,MineT,MineST,false);
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
				//EXTRA THULE STUFF
				for(p = 1; < cNumberNonGaiaPlayers){
					xSetPointer(dPlayerData, p);
					if(xGetInt(dPlayerData, xDrillLevel) >= 6){
						if(col > 20){
							trQuestVarSetFromRand("Temp",1,40);
							if(1*trQuestVarGet("Temp") <= cNumberNonGaiaPlayers){
								spawnRelicSpecific(v,16);
							}
						}
						if(col < 5){
							trQuestVarSetFromRand("Temp",1,40);
							if(1*trQuestVarGet("Temp") <= cNumberNonGaiaPlayers){
								trQuestVarSetFromRand("Temp2",1,8);
								if(trQuestVarGet("Temp2") < 8){
									spawnRelicSpecific(v,18);
								}
								else{
									spawnRelicSpecific(v,20);
								}
							}
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
			if(Stage == 6){
				//iron first two rows
				if(row == 20){
					spawnRelicSpecific(v,2);
				}
				if(row == 18){
					trQuestVarSetFromRand("Temp",1,12);
					trQuestVarSetFromRand("Temp2",5,7);
					if(1*trQuestVarGet("Temp") <= cNumberNonGaiaPlayers){
						spawnRelicSpecific(v,1*trQuestVarGet("Temp2"));
					}
				}
				else if((row > 10) && (row <= 17)){
					trQuestVarSetFromRand("Temp",1,20);
					trQuestVarSetFromRand("Temp2",10,11);
					if(1*trQuestVarGet("Temp") <= cNumberNonGaiaPlayers){
						spawnRelicSpecific(v,1*trQuestVarGet("Temp2"));
					}
					if(1*trQuestVarGet("Temp") >= 18){
						spawnRelicSpecific(v,6);
					}
				}
				else if((row > 2) && (row <= 10)){
					trQuestVarSetFromRand("Temp",1,13);
					trQuestVarSetFromRand("Temp2",6,11);
					if(1*trQuestVarGet("Temp") <= cNumberNonGaiaPlayers){
						spawnRelicSpecific(v,1*trQuestVarGet("Temp2"));
					}
				}
				else if(row <= 2){
					trQuestVarSetFromRand("Temp",1,7);
					if(1*trQuestVarGet("Temp") == 3){
						trQuestVarSetFromRand("Temp2",9,11);
						spawnRelicSpecific(v,1*trQuestVarGet("Temp2"));
					}
				}
			}
			if(Stage == 7){
				//iron first two rows
				if(row == 18){
					trQuestVarSetFromRand("Temp",1,12);
					if(1*trQuestVarGet("Temp") <= cNumberNonGaiaPlayers){
						spawnRelicSpecific(v,6);
					}
				}
				else if((row > 10) && (row <= 17)){
					trQuestVarSetFromRand("Temp",1,20);
					trQuestVarSetFromRand("Temp2",6,9);
					if(1*trQuestVarGet("Temp") <= cNumberNonGaiaPlayers){
						spawnRelicSpecific(v,1*trQuestVarGet("Temp2"));
					}
					if(1*trQuestVarGet("Temp") >= 18){
						spawnRelicSpecific(v,6);
					}
				}
				else if((row > 2) && (row <= 10)){
					trQuestVarSetFromRand("Temp",1,5);
					if(1*trQuestVarGet("Temp") == 1){
						trQuestVarSetFromRand("Temp2",6,9);
						spawnRelicSpecific(v,1*trQuestVarGet("Temp2"));
					}
					if(1*trQuestVarGet("Temp") == 2){
						trQuestVarSetFromRand("Temp2",12,13);
						spawnRelicSpecific(v,1*trQuestVarGet("Temp2"));
					}
				}
				else if(row <= 2){
					if(GetRockType(trGetTerrainType(col*4-2,row*4-2),trGetTerrainSubType(col*4-2,row*4-2)) == Hades5){
						spawnRelicSpecific(v,14);
					}
					else{
						trQuestVarSetFromRand("Temp",1,7);
						if(1*trQuestVarGet("Temp") == 3){
							trQuestVarSetFromRand("Temp2",12,13);
							spawnRelicSpecific(v,1*trQuestVarGet("Temp2"));
						}
					}
				}
			}
			if(Stage == 8){
				if(row == 18){
					trQuestVarSetFromRand("Temp",1,10);
					if(1*trQuestVarGet("Temp") <= cNumberNonGaiaPlayers){
						spawnRelicSpecific(v, 9);
					}
				}
				else if((row > 14) && (row <= 16)){
					trQuestVarSetFromRand("Temp",1,20);
					trQuestVarSetFromRand("Temp2",4,13);
					if(1*trQuestVarGet("Temp") <= cNumberNonGaiaPlayers){
						spawnRelicSpecific(v,1*trQuestVarGet("Temp2"));
					}
					if(1*trQuestVarGet("Temp") >= 18){
						spawnRelicSpecific(v,6);
					}
				}
				else if((row > 10) && (row <= 13)){
					trQuestVarSetFromRand("Temp",1,20);
					trQuestVarSetFromRand("Temp2",15,17);
					if(1*trQuestVarGet("Temp") <= cNumberNonGaiaPlayers){
						spawnRelicSpecific(v,1*trQuestVarGet("Temp2"));
					}
				}
				else if((row > 4) && (row <= 8)){
					trQuestVarSetFromRand("Temp",1,19);
					trQuestVarSetFromRand("Temp2",15,18);
					if(1*trQuestVarGet("Temp") <= cNumberNonGaiaPlayers){
						spawnRelicSpecific(v,1*trQuestVarGet("Temp2"));
					}
				}
				else if(row <= 4){
					trQuestVarSetFromRand("Temp",1,16);
					trQuestVarSetFromRand("Temp2",16,19);
					if(1*trQuestVarGet("Temp") <= cNumberNonGaiaPlayers){
						spawnRelicSpecific(v,1*trQuestVarGet("Temp2"));
					}
				}
			}
			if(Stage == 9){
				if((row >= 17) && (row <= 18)){
					trQuestVarSetFromRand("Temp",1,10);
					trQuestVarSetFromRand("Temp2",1,9);
					if(1*trQuestVarGet("Temp") <= cNumberNonGaiaPlayers){
						spawnRelicSpecific(v,1*trQuestVarGet("Temp2"));
					}
				}
				else if((row >= 14) && (row <= 16)){
					if(col >= 23){
						trQuestVarSetFromRand("Temp",1,2);
						trQuestVarSetFromRand("Temp2",7,9);
						if(1*trQuestVarGet("Temp") <= 2){
							spawnRelicSpecific(v,1*trQuestVarGet("Temp2"));
						}
					}
				}
				else if((row >= 11) && (row <= 13)){
					if(GetRockType(trGetTerrainType(col*4-2,row*4-2),trGetTerrainSubType(col*4-2,row*4-2)) == Hades5){
						trQuestVarSetFromRand("Temp",1,3);
						if(1*trQuestVarGet("Temp") == 1){
							spawnRelicSpecific(v,9);
						}
						if(1*trQuestVarGet("Temp") == 2){
							spawnRelicSpecific(v,14);
						}
					}
					else{
						trQuestVarSetFromRand("Temp",1,3);
						if(1*trQuestVarGet("Temp") == 3){
							trQuestVarSetFromRand("Temp2",7,13);
							spawnRelicSpecific(v,1*trQuestVarGet("Temp2"));
						}
					}
				}
				else if((row >= 9) && (row <= 10)){
					RockType(36);
					if(col <= 2){
						trQuestVarSetFromRand("Temp2",12,13);
						spawnRelicSpecific(v,1*trQuestVarGet("Temp2"));
					}
				}
				else if((row >= 7) && (row <= 8)){
					if(GetRockType(trGetTerrainType(col*4-2,row*4-2),trGetTerrainSubType(col*4-2,row*4-2)) == Hades5){
						trQuestVarSetFromRand("Temp",1,2);
						if(1*trQuestVarGet("Temp") == 1){
							spawnRelicSpecific(v,9);
						}
					}
					else{
						trQuestVarSetFromRand("Temp",1,3);
						if(1*trQuestVarGet("Temp") == 3){
							trQuestVarSetFromRand("Temp2",10,15);
							spawnRelicSpecific(v,1*trQuestVarGet("Temp2"));
						}
					}
				}
				else if(row == 6){
					if(col >= 24){
						trQuestVarSetFromRand("Temp",1,3);
						if(1*trQuestVarGet("Temp") == 3){
							trQuestVarSetFromRand("Temp2",13,15);
							spawnRelicSpecific(v,1*trQuestVarGet("Temp2"));
						}
					}
				}
				else if((row >= 4) && (row <= 5)){
					if(GetRockType(trGetTerrainType(col*4-2,row*4-2),trGetTerrainSubType(col*4-2,row*4-2)) == Hades5){
						trQuestVarSetFromRand("Temp",1,2);
						if(1*trQuestVarGet("Temp") == 1){
							spawnRelicSpecific(v,19);
						}
					}
					else{
						trQuestVarSetFromRand("Temp",1,3);
						if(1*trQuestVarGet("Temp") == 3){
							trQuestVarSetFromRand("Temp2",17,18);
							spawnRelicSpecific(v,1*trQuestVarGet("Temp2"));
						}
					}
				}
				else if(row == 3){
					if(col <= 2){
						trQuestVarSetFromRand("Temp2",17,18);
						spawnRelicSpecific(v,1*trQuestVarGet("Temp2"));
					}
				}
				else if(row == 2){
					if (iModulo(4, col) == 0) {
						spawnRelicSpecific(v,20);
					}
				}
			}
			if(Stage == 10){
				if((row >= 19) && (row <= 20)){
					trQuestVarSet("TEMPRELIC", trGetNextUnitScenarioNameNumber());
					trArmyDispatch(""+cNumberNonGaiaPlayers+",0", "Dwarf", 1,xsVectorGetX(v),0,xsVectorGetZ(v),0,true);
					trUnitSelectClear();
					trUnitSelectByQV("TEMPRELIC");
					trUnitChangeProtoUnit("Spy Eye");
					trUnitSelectClear();
					trUnitSelectByQV("TEMPRELIC");
					trMutateSelected(kbGetProtoUnitID("Sentinel Base"));
					trUnitSelectClear();
					trUnitSelectByQV("TEMPRELIC");
					trSetSelectedScale(4,0.3,4);
					trUnitSelectClear();
					trQuestVarSet("HullR"+row+"C"+col+"", 1*trQuestVarGet("TEMPRELIC"));
				}
				if((row == 18) && (col == 1)){
					spawnFuelRelic(v,100);
				}
				if((row == 15) && (col == 25)){
					spawnFuelRelic(v,100);
				}
				if(row == 17){
					if(iModulo(3, col) == 0){
						if(1*trQuestVarGet("TEMPkey") == 0){
							trQuestVarSetFromRand("TEMPkey", 1, 5, true);
						}
						if(col == 3*trQuestVarGet("TEMPkey")){
							spawnRelicSpecific(v,22);
						}
						else {
							spawnRelicSpecific(v,9);
						}
					}
					/*else if((row >= 14) && (row <= 16)){
						if(col >= 23){
							trQuestVarSetFromRand("Temp",1,2);
							trQuestVarSetFromRand("Temp2",7,9);
							if(1*trQuestVarGet("Temp") <= 2){
								spawnRelicSpecific(v,1*trQuestVarGet("Temp2"));
							}
						}
					}*/
				}
			}
		}
	}
	xsEnableRule("SecretRelics");
}

void ExtraRelic(int colmin = 1, int colmax = 25, int rowmin = 1, int rowmax = 20, int value = 1, int number = 1, int extra = 0){
	int relicsplaced = 0;
	int col = 0;
	int row = 0;
	vector v = vector(0,0,0);
	int temp = 0;
	int ABORT = 0;
	while (relicsplaced != number) {
		trQuestVarSetFromRand("TempCol",colmin,colmax,true);
		trQuestVarSetFromRand("TempRow",rowmin,rowmax,true);
		col = 1*trQuestVarGet("TempCol");
		row = 1*trQuestVarGet("TempRow");
		v = xsVectorSet(col*8-4,0,row*8-4);
		temp = trGetNextUnitScenarioNameNumber();
		trArmyDispatch(""+cNumberNonGaiaPlayers+",0", "Dwarf", 1,xsVectorGetX(v),0,xsVectorGetZ(v),0,true);
		if(trCountUnitsInArea(""+temp, 0, "Relic", 4) != 0){
			trUnitSelectClear();
			trUnitSelect(""+temp);
			trUnitChangeProtoUnit("Rocket");
			//trChatSend(0, "Fail at R"+row+" C"+col+"");
			ABORT = ABORT +1;
		}
		else if(trCountUnitsInArea(""+temp, 0, "Relic", 4) == 0){
			trUnitSelectClear();
			trUnitSelect(""+temp);
			trUnitChangeProtoUnit("Rocket");
			if(value <= 30){
				spawnRelicSpecific(v, value);
			}
			if(value == 31){
				spawnFuelRelic(v, extra);
			}
			if(value == 32){
				spawnHullRelic(v, extra);
			}
			//trChatSend(0, "Placed at R"+row+" C"+col+"");
			relicsplaced = relicsplaced+1;
		}
		if(ABORT > 99){
			//trChatSend(0, "ABORT");
			break;
		}
	}
}

rule SecretRelics
inactive
highFrequency
{
	if(Stage == 1){
		trQuestVarSetFromRand("Temp", 1, 5, true);
		if(1*trQuestVarGet("Temp") < 3){
			ExtraRelic(6,19,1,10,27,1*trQuestVarGet("Temp"));
		}
		trQuestVarSetFromRand("Temp", 1, 47, true);
		if(1*trQuestVarGet("Temp") == 1){
			ExtraRelic(6,19,3,16,28,1);
		}
		for(p = 1; < cNumberNonGaiaPlayers){
			xSetPointer(dPlayerData, p);
			if(xGetInt(dPlayerData, xDrillLevel) >= 6){
				//for every extra
				trQuestVarSetFromRand("Temp", 1, 5, true);
				if(1*trQuestVarGet("Temp") == 1){
					ExtraRelic(1,5,1,10,30,1);
				}
				if(1*trQuestVarGet("Temp") == 2){
					trQuestVarSetFromRand("Temp2", 1, 5, true);
					ExtraRelic(1,5,1,10,32,1,50*trQuestVarGet("Temp2"));
				}
			}
			else{
				//for every normal
				trQuestVarSetFromRand("Temp", 1, 2, true);
				if(1*trQuestVarGet("Temp") == 1){
					trQuestVarSetFromRand("Temp2", 1, 4, true);
					ExtraRelic(6,19,10,18,31,1,50*trQuestVarGet("Temp2"));
				}
			}
		}
	}
	if(Stage == 2){
		trQuestVarSetFromRand("Temp", 1, 5, true);
		if(1*trQuestVarGet("Temp") < 3){
			ExtraRelic(1,25,5,15,27,1*trQuestVarGet("Temp"));
		}
		trQuestVarSetFromRand("Temp", 1, 47, true);
		if(1*trQuestVarGet("Temp") == 1){
			ExtraRelic(6,19,3,13,28,1);
		}
		for(p = 1; < cNumberNonGaiaPlayers){
			xSetPointer(dPlayerData, p);
			if(xGetInt(dPlayerData, xDrillLevel) >= 6){
				//for every extra
				trQuestVarSetFromRand("Temp", 1, 5, true);
				if(1*trQuestVarGet("Temp") == 1){
					ExtraRelic(1,25,1,3,30,1);
				}
			}
			else{
				//for every normal
				trQuestVarSetFromRand("Temp", 1, 2, true);
				if(1*trQuestVarGet("Temp") == 1){
					trQuestVarSetFromRand("Temp2", 1, 4, true);
					ExtraRelic(1,25,9,16,31,1,50*trQuestVarGet("Temp2"));
				}
			}
		}
	}
	if(Stage == 3){
		trQuestVarSetFromRand("Temp", 1, 5, true);
		if(1*trQuestVarGet("Temp") < 3){
			ExtraRelic(1,25,5,15,27,1*trQuestVarGet("Temp"));
		}
		trQuestVarSetFromRand("Temp", 1, 20, true);
		if(1*trQuestVarGet("Temp") == 1){
			ExtraRelic(6,19,3,13,28,1);
		}
		for(p = 1; < cNumberNonGaiaPlayers){
			xSetPointer(dPlayerData, p);
			if(xGetInt(dPlayerData, xDrillLevel) >= 6){
				//for every extra
				trQuestVarSetFromRand("Temp", 1, 5, true);
				if(1*trQuestVarGet("Temp") == 1){
					ExtraRelic(1,25,1,3,30,1);
				}
			}
			else{
				//for every normal
				trQuestVarSetFromRand("Temp", 1, 3, true);
				if(1*trQuestVarGet("Temp") == 1){
					trQuestVarSetFromRand("Temp2", 1, 4, true);
					ExtraRelic(1,25,3,13,31,1,100*trQuestVarGet("Temp2"));
				}
			}
		}
	}
	if(Stage == 4){
		trQuestVarSetFromRand("Temp", 1, 5, true);
		if(1*trQuestVarGet("Temp") < 3){
			ExtraRelic(1,25,5,15,27,1*trQuestVarGet("Temp"));
		}
		trQuestVarSetFromRand("Temp", 1, 5, true);
		if(1*trQuestVarGet("Temp") < 2){
			ExtraRelic(6,19,3,13,28,1*trQuestVarGet("Temp"));
		}
		for(p = 1; < cNumberNonGaiaPlayers){
			xSetPointer(dPlayerData, p);
			if(xGetInt(dPlayerData, xDrillLevel) >= 6){
				//for every extra
				trQuestVarSetFromRand("Temp", 1, 5, true);
				if(1*trQuestVarGet("Temp") == 1){
					ExtraRelic(1,25,1,3,30,1);
				}
			}
			else{
				//for every normal
				trQuestVarSetFromRand("Temp", 1, 3, true);
				if(1*trQuestVarGet("Temp") == 1){
					trQuestVarSetFromRand("Temp2", 1, 4, true);
					ExtraRelic(1,25,5,9,31,1,100*trQuestVarGet("Temp2"));
				}
			}
		}
	}
	if(Stage == 5){
		trQuestVarSetFromRand("Temp", 1, 5, true);
		if(1*trQuestVarGet("Temp") < 3){
			ExtraRelic(1,25,5,15,28,1*trQuestVarGet("Temp"));
		}
		trQuestVarSetFromRand("Temp", 1, 47, true);
		if(1*trQuestVarGet("Temp") == 1){
			ExtraRelic(6,19,3,13,29,1);
		}
		for(p = 1; < cNumberNonGaiaPlayers){
			//for every normal
			trQuestVarSetFromRand("Temp", 1, 3, true);
			if(1*trQuestVarGet("Temp") == 1){
				trQuestVarSetFromRand("Temp2", 1, 4, true);
				ExtraRelic(1,25,10,16,31,1,100*trQuestVarGet("Temp2"));
			}
		}
	}
	if(Stage == 6){
		trQuestVarSetFromRand("Temp", 1, 5, true);
		if(1*trQuestVarGet("Temp") < 3){
			ExtraRelic(1,25,3,15,28,1*trQuestVarGet("Temp"));
		}
		trQuestVarSetFromRand("Temp", 1, 47, true);
		if(1*trQuestVarGet("Temp") == 1){
			ExtraRelic(6,19,3,13,29,1);
		}
		if(1*trQuestVarGet("Temp") == 2){
			ExtraRelic(6,19,1,6,30,1);
		}
		for(p = 1; < cNumberNonGaiaPlayers){
			//for every normal
			trQuestVarSetFromRand("Temp", 1, 3, true);
			if(1*trQuestVarGet("Temp") == 1){
				trQuestVarSetFromRand("Temp2", 1, 4, true);
				ExtraRelic(1,25,10,16,31,1,100*trQuestVarGet("Temp2"));
			}
			if(1*trQuestVarGet("Temp") != 2){
				trQuestVarSetFromRand("Temp2", 1, 10, true);
				ExtraRelic(1,25,10,16,32,1,25*trQuestVarGet("Temp2"));
			}
		}
	}
	if(Stage == 7){
		trQuestVarSetFromRand("Temp", 1, 5, true);
		if(1*trQuestVarGet("Temp") < 3){
			ExtraRelic(1,25,3,15,28,1*trQuestVarGet("Temp"));
		}
		trQuestVarSetFromRand("Temp", 1, 20, true);
		if(1*trQuestVarGet("Temp") == 1){
			ExtraRelic(6,19,3,13,29,1);
		}
		if(1*trQuestVarGet("Temp") == 2){
			ExtraRelic(6,19,1,6,30,1);
		}
		for(p = 1; < cNumberNonGaiaPlayers){
			//for every normal
			trQuestVarSetFromRand("Temp", 1, 4, true);
			if(1*trQuestVarGet("Temp") == 1){
				trQuestVarSetFromRand("Temp2", 1, 10, true);
				ExtraRelic(1,25,10,16,31,1,75*trQuestVarGet("Temp2"));
			}
			if(1*trQuestVarGet("Temp") != 2){
				trQuestVarSetFromRand("Temp2", 1, 40, true);
				ExtraRelic(1,25,10,16,32,1,25*trQuestVarGet("Temp2"));
			}
		}
	}
	if(Stage == 8){
		trQuestVarSetFromRand("Temp", 1, 5, true);
		if(1*trQuestVarGet("Temp") < 3){
			ExtraRelic(1,25,5,15,29,1*trQuestVarGet("Temp"));
		}
		trQuestVarSetFromRand("Temp", 1, 10, true);
		if(1*trQuestVarGet("Temp") == 1){
			ExtraRelic(6,19,3,13,29,1);
		}
		if(1*trQuestVarGet("Temp") == 2){
			ExtraRelic(6,19,1,6,30,1);
		}
		for(p = 1; < cNumberNonGaiaPlayers){
			//for every normal
			trQuestVarSetFromRand("Temp", 1, 4, true);
			if(1*trQuestVarGet("Temp") != 1){
				trQuestVarSetFromRand("Temp2", 1, 10, true);
				ExtraRelic(1,25,10,16,31,1,50*trQuestVarGet("Temp2"));
			}
			if(1*trQuestVarGet("Temp") == 2){
				trQuestVarSetFromRand("Temp2", 1, 20, true);
				ExtraRelic(1,25,10,16,32,1,50*trQuestVarGet("Temp2"));
			}
		}
	}
	xsDisableSelf();
	xsEnableRule("WallUp");
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
