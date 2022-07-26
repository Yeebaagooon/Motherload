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
					else if((row == 14) && (col == 8)){
						RockType(33);
					}
					else if((row == 14) && (col == 2)){
						RockType(35);
					}
					else if((row == 14) && (col == 24)){
						RockType(33);
					}
					else if((row == 14) && (col == 25)){
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
		trSetCloudData(1.0, 1, 1, 3.0, 1.0, 0.2);
		trSetCloudMap("sfx g lightning skyflash");
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
		trSetCloudData(1.0, 1, 1, 17.0, 1.0, 0.2);
		trSetCloudMap("sfx g lightning skyflash");
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
		trSetCloudData(1.0, 1, 1, 13.0, 1.0, 0.2);
		trSetCloudMap("sfx g lightning skyflash");
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
		trSetCloudData(1.0, 1, 1, 16.0, 1.0, 0.2);
		trSetCloudMap("sfx g lightning skyflash");
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
		trSetCloudData(1.0, 1, 1, 17.0, 1.0, 0.2);
		trSetCloudMap("ui\ui button radial 32x32");
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
				Trap1(a*4-4,69,a*4-4,71, xsVectorSet(a*8-4,3,132), 5000);
			}
		}
		Layout(16,24);
		SelectableSign(31, 185, 25);
		SelectableSign(180, 114, 26);
		SelectableSign(80, 114, 27);
		SelectableSign(76, 16, 28);
		SelectableSign(180, 95, 29);
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
		Layout(13,1);
		Layout(13,2);
		Layout(12,2);
		Layout(13,3);
		Layout(13,4);
		Layout(13,5);
		if(QuickStart == 1){
			Layout(16,6); //DELETE ME SHORTCUT LAYOUT
			Layout(14,10); //DELETE ME SHORTCUT LAYOUT
		}
		for(a=4; <=11){
			for(b=1; <=5){
				Layout(a,b);
			}
		}
		Layout(3,4);
		Layout(2,4);
		Layout(1,4);
		Layout(1,5);
		Layout(1,6);
		//Builds key command room
		for(a=7; <=7+3){
			Layout(1,a);
		}
		Layout(2,10);
		for(a=8; <=12){
			Layout(3,a);
		}
		Layout(4,10);
		for(a=5; <=10){
			for(b=8; <=12){
				Layout(a,b);
			}
		}
		Layout(11,10);
		Layout(12,10);
		Layout(13,10);
		Layout(13,11);
		for(a=11; <=13){
			for(b=12; <=20){
				Layout(a,b);
			}
		}
		Layout(12,21);
		Layout(12,20);
		//above is for flaming minefield
		//trPaintTerrain(48,42,76,49,2,13,false);
		
		//X row = 11
		Trap1(11*4+1,12*4+1,11*4+3,12*4+3, xsVectorSet(12*8+5,3,12*8+5), 5000);
		Trap1(11*4+1,11*4+1,11*4+3,11*4+3, xsVectorSet(11*8+5,3,10*8+5), 5000);
		Trap1(11*4+1,10*4+1,11*4+3,10*4+3, xsVectorSet(13*8+5,3,10*8+5), 5000);
		//X row = 12
		Trap1(12*4+1,12*4+1,12*4+3,12*4+3, xsVectorSet(14*8+5,3,12*8+5), 5000);
		Trap1(12*4+1,11*4+1,12*4+3,11*4+3, xsVectorSet(11*8+5,3,11*8+5), 5000);
		Trap1(12*4+1,10*4+1,12*4+3,10*4+3, xsVectorSet(19*8+5,3,10*8+5), 5000);
		
		//X row = 13
		Trap1(13*4+1,12*4+1,13*4+3,12*4+3, xsVectorSet(15*8+5,3,12*8+5), 5000);
		Trap1(13*4+1,11*4+1,13*4+3,11*4+3, xsVectorSet(16*8+5,3,11*8+5), 5000);
		Trap1(13*4+1,10*4+1,13*4+3,10*4+3, xsVectorSet(18*8+5,3,10*8+5), 5000);
		
		//X row = 14
		Trap1(14*4+1,12*4+1,14*4+3,12*4+3, xsVectorSet(11*8+5,3,12*8+5), 5000);
		Trap1(14*4+1,11*4+1,14*4+3,11*4+3, xsVectorSet(12*8+5,3,11*8+5), 5000);
		Trap1(14*4+1,10*4+1,14*4+3,10*4+3, xsVectorSet(16*8+5,3,10*8+5), 5000);
		
		//X row = 15
		Trap1(15*4+1,10*4+1,15*4+3,10*4+3, xsVectorSet(14*8+5,3,10*8+5), 5000);
		Trap1(15*4+1,11*4+1,15*4+3,11*4+3, xsVectorSet(15*8+5,3,11*8+5), 5000);
		Trap1(15*4+1,12*4+1,15*4+3,12*4+3, xsVectorSet(16*8+5,3,12*8+5), 5000);
		
		//X row = 16
		Trap1(16*4+1,12*4+1,16*4+3,12*4+3, xsVectorSet(13*8+5,3,12*8+5), 5000);
		Trap1(16*4+1,11*4+1,16*4+3,11*4+3, xsVectorSet(14*8+5,3,11*8+5), 5000);
		Trap1(16*4+1,10*4+1,16*4+3,10*4+3, xsVectorSet(15*8+5,3,10*8+5), 5000);
		
		//X row = 17
		Trap1(17*4+1,12*4+1,17*4+3,12*4+3, xsVectorSet(19*8+5,3,12*8+5), 5000);
		//Manual fix
		Trap1(17*4+1,11*4+1,17*4+3,11*4+3, xsVectorSet(18*8+5,3,11*8+5), 5000, 1);
		//Manual fix
		Trap1(17*4+1,10*4+1,17*4+3,10*4+3, xsVectorSet(19*8+5,3,11*8+5), 5000);
		
		//X row = 18
		Trap1(18*4+1,12*4+1,18*4+3,12*4+3, xsVectorSet(17*8+5,3,12*8+5), 5000);
		//Manual fix
		Trap1(18*4+1,11*4+1,18*4+3,11*4+3, xsVectorSet(17*8+5,3,11*8+5), 5000, 1);
		//Manual fix
		Trap1(18*4+1,10*4+1,18*4+3,10*4+3, xsVectorSet(17*8+5,3,10*8+5), 5000);
		
		//X row = 19
		Trap1(19*4+1,12*4+1,19*4+3,12*4+3, xsVectorSet(18*8+5,3,12*8+5), 5000);
		Trap1(19*4+1,11*4+1,19*4+3,11*4+3, xsVectorSet(13*8+5,3,11*8+5), 5000);
		Trap1(19*4+1,10*4+1,19*4+3,10*4+3, xsVectorSet(12*8+5,3,10*8+5), 5000);
		
		
		trPaintTerrain(29,16,48,39,2,13,false);
		trPaintTerrain(37,14,39,16,0,73,false);
		trPaintTerrain(28,17,39,18,0,73,false);
		trPaintTerrain(28,19,29,20,0,73,false);
		trPaintTerrain(28,21,47,22,0,73,false);
		trPaintTerrain(46,23,47,25,0,73,false);
		trPaintTerrain(28,25,47,26,0,73,false);
		trPaintTerrain(28,27,29,28,0,73,false);
		trPaintTerrain(28,29,47,30,0,73,false);
		trPaintTerrain(46,31,47,32,0,73,false);
		trPaintTerrain(28,33,47,34,0,73,false);
		trPaintTerrain(28,35,29,36,0,73,false);
		trPaintTerrain(28,37,39,38,0,73,false);
		trPaintTerrain(37,39,39,40,0,73,false);
		//Paint key command room mask, passability done in setup
		for(x = 28 ; <= 47){
			for(z = 14; <= 40){
				if((trGetTerrainSubType(x,z) == 73) && (trGetTerrainType(x,z) == 0)){
					temp = trGetNextUnitScenarioNameNumber();
					trArmyDispatch("0,0", "Dwarf", 1, x*2,3,z*2, 0, true);
					trUnitSelectClear();
					trUnitSelect(""+temp);
					trUnitChangeProtoUnit("Statue of Automaton Base");
					trUnitSelectClear();
					trUnitSelect(""+temp);
					trSetSelectedScale(2,2,2);
					if((x == 30) || (x == 34) || (x == 41) || (x == 45)){
						temp = trGetNextUnitScenarioNameNumber();
						trArmyDispatch(""+cNumberNonGaiaPlayers+",0", "Dwarf", 1, x*2,3,z*2, 0, true);
						trUnitSelectClear();
						trUnitSelect(""+temp);
						trUnitChangeProtoUnit("Garrison Flag Sky Passage");
						//add to DB - x as state
						xAddDatabaseBlock(dT5, true);
						xSetInt(dT5, xT5XPos, x);
						xSetInt(dT5, xT5Name, temp);
					}
				}
			}
		}
		//above does automaton floor from key command room
		trPaintTerrain(30,10,30,10,10,10,false);
		trPaintTerrain(34,10,34,10,10,10,false);
		trPaintTerrain(41,10,41,10,10,10,false);
		trPaintTerrain(45,10,45,10,10,10,false);
		Trap5(30,30,10);
		Trap5(34,34,10);
		Trap5(41,41,10);
		Trap5(45,45,10);
		
		for(a=1; <=5){
			temp = trGetNextUnitScenarioNameNumber();
			trArmyDispatch("0,0", "Dwarf", 1, 70+a*2,3,82, 0, true);
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
			xSetInt(dKey, xKey, RELIC_KEY_NORSE);
		}
		GVectorNorse = vector(76,3,82);
		FloatingUnitAnimIdle("UI Range Indicator Norse SFX", 76, 6.5, 82, 0, 1,1,1);
		xAddDatabaseBlock(dKey, true);
		xSetInt(dKey, xKeyUnitName, 1*trQuestVarGet("QVHero"));
		xSetInt(dKey, xKey, RELIC_KEY_NORSE);
		xAddDatabaseBlock(dKey, true);
		xSetInt(dKey, xKeyUnitName, 1*trQuestVarGet("QVRelic"));
		xSetInt(dKey, xKey, RELIC_KEY_NORSE);
		
		xAddDatabaseBlock(dTrap);
		xSetPointer(dTrap, xGetDatabaseCount(dTrap));
		//pressure pad
		xSetInt(dTrap, xTrapXMin, 37);
		xSetInt(dTrap, xTrapXMax, 39*2+2);
		xSetInt(dTrap, xTrapZMin, 44*2);
		xSetInt(dTrap, xTrapZMax, 46*2+2);
		xSetInt(dTrap, xTrapType, 6);
		xSetBool(dTrap, xTrapOn, true);
		xSetBool(dTrap, xTrapReady, true);
		PaintAtlantisArea(37,44,39,46,"black");
		trPaintTerrain(38,45,38,45,10,2,false);
		
		
		//key command
		PaintSellTerrain(11,51);
		GVectorSellPos = vector(27,3,97);
		GVectorChinese = vector(188,3,126);
		FloatingUnitAnimIdle("UI Range Indicator Chinese SFX", 188, 6.5, 126, 0, 1,1,1);
		xAddDatabaseBlock(dKey, true);
		xSetInt(dKey, xKeyUnitName, 1*trQuestVarGet("QVHero"));
		xSetInt(dKey, xKey, RELIC_KEY_CHINA);
		xAddDatabaseBlock(dKey, true);
		xSetInt(dKey, xKeyUnitName, 1*trQuestVarGet("QVRelic"));
		xSetInt(dKey, xKey, RELIC_KEY_CHINA);
		trPaintTerrain(1,12,20,43,0,70,false);
		//above removes black bits from 4x4 leftover 1st room
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
		
		//2nd row traps
		Trap2(85,85,56,59,171,124,vector(0,0,-16));
		Trap2(80,80,56,59,151,124,vector(0,0,-16));
		Trap2(70,70,56,59,131,108,vector(0,0,16));
		Trap2(60,60,56,59,131,124,vector(0,0,-16));
		Trap2(53,54,56,57,101,114,vector(-100,0,0));
		Trap2(23,24,58,59,21,118, vector(167,0,0));
		trPaintTerrain(34,57,34,59,0,71,false);
		
		//Trap 1
		Trap1(50,56,50,59, vector(115,3,117), 5000);
		
		//gate effect
		xAddDatabaseBlock(dTrap);
		xSetPointer(dTrap, xGetDatabaseCount(dTrap));
		//pressure pad
		trPaintTerrain(38,58,38,58,10,10,false);
		xSetInt(dTrap, xTrapXMin, 38*2);
		xSetInt(dTrap, xTrapXMax, 38*2+2);
		xSetInt(dTrap, xTrapZMin, 58*2);
		xSetInt(dTrap, xTrapZMax, 58*2+2);
		xSetInt(dTrap, xTrapType, 3);
		xSetBool(dTrap, xTrapOn, true);
		xSetBool(dTrap, xTrapReady, true);
		xSetInt(dTrap, xTrapReset, 7000);
		xSetInt(dTrap, xTrapUnit, 1*trGetNextUnitScenarioNameNumber());
		xSetVector(dTrap, xTrapHitVector, xsVectorSet(34*2+1,3,117));
		xSetInt(dTrap, xTrapHitboxX, 1);
		xSetInt(dTrap, xTrapHitboxZ, 3.5);
		for(x = 0 ; < 5){
			temp = trGetNextUnitScenarioNameNumber();
			trArmyDispatch(""+cNumberNonGaiaPlayers+",0", "Dwarf", 1, 34*2+1,3,112+x*2, 0, true);
			trUnitSelectClear();
			trUnitSelect(""+temp);
			trUnitChangeProtoUnit("Garrison Flag Sky Passage");
		}
		xSetVector(dTrap, xTrapTargetVector, xsVectorSet(1*trGetNextUnitScenarioNameNumber()-xGetInt(dTrap, xTrapUnit),0,0));
		
		Trap3Horizontal(12, 16, 12, 2, 2, 42, 42, 15000);
		//TRAPS in first big room
		//Trap3Horizontal(12, 16, 20, 9, 9, 40, 40, 5000);
		//2 below are traps for bottom right corner
		Trap3Horizontal(16, 20, 16, 17, 17, 42, 42, 15000);
		Trap3Vertical(16, 12, 16, 17, 17, 42, 42, 15000);
		//Sometimes this one vanishes?
		//Trap3Vertical(8, 20, 24, 6, 6, 38, 38, 5000);
		//2 below are traps for top right corner
		Trap3Horizontal(16, 20, 40, 2, 2, 14, 14, 15000);
		Trap3Vertical(16, 40, 44, 2, 2, 14, 14, 15000);
		//2 below are traps for top left corner
		Trap3Horizontal(0, 4, 40, 18, 18, 14, 14, 15000);
		Trap3Vertical(4, 40, 44, 18, 18, 14, 14, 15000);
		//2 below are traps for bottom left corner
		Trap3Horizontal(0, 4, 16, 18, 18, 23, 23, 15000);
		Trap3Vertical(4, 12, 16, 18, 18, 23, 23, 15000);
		
		Trap4Horizontal(4, 8, 40, 6, 6, 42, 42, 5000);
		Trap4Vertical(8, 12, 16, 10, 10, 20, 20, 5000);
		Trap4Horizontal(12, 16, 16, 2, 2, 42, 42, 12500);
		Trap4Vertical(12, 12, 16, 2, 2, 42, 42, 12500);
		
		//void Trap2(int PPXmin = 0, int PPXmax = 0, int PPZmin = 0, int PPZmax = 0, int WallX = 0, int WallZ = 0, vector Vtarget = vector(0,0,0), int Timer = 20000){
		Trap2(9,10,41,42, 0, 38*2, vector(46,0,0));
		
		Trap2(8,12,28,32, 21, 61, vector(20,0,0));
		Trap2(8,12,28,32, 21, 61, vector(-20,0,0));
		Trap2(8,12,28,32, 21, 61, vector(0,0,30));
		Trap2(8,12,28,32, 21, 61, vector(0,0,-30));
		
		Trap2(14,15,22,23, 38, 22, vector(0,0,65));
		Trap2(3,4,19,20, 6, 22, vector(0,0,65));
		Trap2(13,14,37,38, 0, 34*2, vector(46,0,0));
		Trap2(9,10,33,34, 0, 30*2, vector(46,0,0));
		Trap2(5,6,29,30, 0, 26*2, vector(46,0,0));
		Trap2(8,9,25,26, 0, 22*2, vector(46,0,0));
		Trap4Horizontal(12, 16, 24, 18, 18, 37, 37, 15000);
		Trap4Horizontal(8, 12, 24, 18, 18, 37, 37, 15000);
		Trap4Horizontal(4, 8, 24, 18, 18, 37, 37, 15000);
		Trap4Horizontal(12, 16, 36, 2, 2, 23, 23, 15000);
		Trap4Horizontal(8, 12, 36, 2, 2, 23, 23, 15000);
		Trap4Horizontal(4, 8, 36, 2, 2, 23, 23, 15000);
		Trap2(5,6,37,38, 0, 18*2, vector(46,0,0));
		Trap2(6,7,14,15, 0, 14*2, vector(46,0,0));
		Trap2(9,10,13,14, 45, 14*2, vector(-44,0,0));
		Trap2(9,10,13,14, 45, 18*2, vector(-44,0,0));
		Trap2(17,18,34,35, 45, 22*2, vector(-44,0,0));
		Trap2(2,3,34,35, 45, 26*2, vector(-44,0,0));
		Trap2(18,19,29,30, 45, 30*2, vector(-44,0,0));
		Trap2(2,3,29,30, 45, 34*2, vector(-44,0,0));
		Trap2(18,19,25,26, 45, 38*2, vector(-44,0,0));
		Trap4Vertical(4, 24, 28, 10, 10, 18, 18, 15000);
		Trap4Vertical(4, 28, 32, 10, 10, 18, 18, 15000);
		Trap4Vertical(4, 32, 36, 10, 10, 18, 18, 15000);
		Trap4Vertical(16, 24, 28, 14, 14, 26, 26, 15000);
		Trap4Vertical(16, 28, 32, 14, 14, 26, 26, 15000);
		Trap4Vertical(16, 32, 36, 14, 14, 26, 26, 15000);
		for(x = 1 ; <= 20){
			for(z = 12; <= 43){
				if((trGetTerrainSubType(x,z) == 70) && (trGetTerrainType(x,z) == 0)){
					temp = trGetNextUnitScenarioNameNumber();
					trArmyDispatch("0,0", "Dwarf", 1, x*2,3,z*2, 0, true);
					trUnitSelectClear();
					trUnitSelect(""+temp);
					trUnitChangeProtoUnit("Statue of Automaton Base");
					trUnitSelectClear();
					trUnitSelect(""+temp);
					trSetSelectedScale(2,2,2);
					
				}
			}
		}
		PaintAtlantisArea(8,28,12,32,"BlackRock");
		
		Layout(12,21);
		Layout(12,22);
		for(a = 1 ; <= 12){
			for(b = 23; <= 25){
				Layout(a,b);
			}
		}
		for(b = 17; <= 25){
			Layout(1,b);
		}
		trPaintTerrain(88,5,100,34,2,10,false);
		//lava room
		Trap7(90,42,90,42, 92);
		Trap7(98,42,98,42, 94);
		Layout(2,17);
		//could be 21
		for(b = 14; <= 20){
			for(a = 3; <= 8){
				//could be 9 - if not use for Yeebium
				Layout(a,b);
			}
		}
		Layout(9,17);
		trQuestVarSet("MrNatas", trGetNextUnitScenarioNameNumber());
		trArmyDispatch(""+cNumberNonGaiaPlayers+",0", "Dwarf", 1,132,0,75,180,true);
		trUnitSelectClear();
		trUnitSelectByQV("MrNatas");
		trUnitChangeProtoUnit("Gargarensis");
		trPaintTerrain(53,9,79,31,0,73,false);
		for(x = 53 ; <= 79){
			for(z = 9; <= 31){
				if((trGetTerrainSubType(x,z) == 73) && (trGetTerrainType(x,z) == 0)){
					temp = trGetNextUnitScenarioNameNumber();
					trArmyDispatch("0,0", "Dwarf", 1, x*2,3,z*2, 0, true);
					trUnitSelectClear();
					trUnitSelect(""+temp);
					trUnitChangeProtoUnit("Statue of Automaton Base");
					trUnitSelectClear();
					trUnitSelect(""+temp);
					trSetSelectedScale(2,2,2);
				}
			}
		}
		//Natas room playable area
		PaintAtlantisArea(65,33,67,35,"BlackRock");
		trPaintTerrain(66,34,66,34,10,10,false);
		trPaintTerrain(65,32,65,32,0,79,false);
		trPaintTerrain(66,32,66,32,0,75,false);
		trPaintTerrain(67,32,67,32,0,77,false);
		//Victory Square and key door terrain
		spawnRelicSpecific(vector(126,3,75), 21);
		spawnRelicSpecific(vector(138,3,75), 21);
		//Yeebiums
		for(a=1; <=5){
			temp = trGetNextUnitScenarioNameNumber();
			trArmyDispatch("0,0", "Dwarf", 1, 126+a*2,3,65, 0, true);
			trUnitSelectClear();
			trUnitSelect(""+temp);
			trUnitChangeProtoUnit("Wall Connector");
			trUnitSelectClear();
			trUnitSelect(""+temp);
			trUnitSetAnimationPath("3,3,0,0,0,0");
			trUnitSelectClear();
			trUnitSelect(""+temp);
			trSetSelectedScale(1.2,1,1.2);
			xAddDatabaseBlock(dKey, true);
			xSetInt(dKey, xKeyUnitName, temp);
			xSetInt(dKey, xKey, RELIC_KEY_EGYPT);
		}
		GVectorEgypt = vector(132,3,64);
		FloatingUnitAnimIdle("UI Range Indicator Egypt SFX", 132, 7.5, 64, 180, 1,1,1);
		xAddDatabaseBlock(dKey, true);
		xSetInt(dKey, xKeyUnitName, 1*trQuestVarGet("QVHero"));
		xSetInt(dKey, xKey, RELIC_KEY_EGYPT);
		xAddDatabaseBlock(dKey, true);
		xSetInt(dKey, xKeyUnitName, 1*trQuestVarGet("QVRelic"));
		xSetInt(dKey, xKey, RELIC_KEY_EGYPT);
		spawnRelicSpecific(vector(132,3,8), RELIC_KEY_EGYPT);
		
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
				if((row == 15) && (col == 1)){
					spawnHullRelic(v,500);
				}
				if((row == 14) && (col == 24)){
					spawnFuelRelic(v,800);
				}
				if((row == 14) && (col == 25)){
					spawnRelicSpecific(v, 30);
				}
				if(row == 17){
					if(iModulo(3, col) == 0){
						if(1*trQuestVarGet("TEMPkey") == 0){
							trQuestVarSetFromRand("TEMPkey", 1, 5, true);
						}
						if(col == 3*trQuestVarGet("TEMPkey")){
							spawnRelicSpecific(v,22);
							//chinese key
						}
						else {
							spawnRelicSpecific(v,18);
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
				if((row == 14) && (col == 8)){
					spawnRelicSpecific(v,20);
				}
				if((row >= 4) && (row <= 11) && (col >= 2) && (col <= 4)){
					trQuestVarSetFromRand("Temp2",12,15);
					spawnRelicSpecific(v,1*trQuestVarGet("Temp2"));
				}
				if((row >= 5) && (row <= 10) && (col == 1)){
					trQuestVarSetFromRand("Temp2",1,cNumberNonGaiaPlayers);
					spawnFuelRelic(v,50*trQuestVarGet("Temp2"));
				}
				if((row >= 5) && (row <= 10) && (col == 5)){
					trQuestVarSetFromRand("Temp2",1,cNumberNonGaiaPlayers);
					spawnFuelRelic(v,50*trQuestVarGet("Temp2"));
				}
				if((row == 8) && (col == 3)){
					spawnFuelRelic(v,1000);
					spawnRelicSpecific(v, 18);
					spawnRelicSpecific(v, 28);
					spawnRelicSpecific(v, 27);
				}
				if((row == 4) && (col == 10)){
					spawnRelicSpecific(v,24);
					//command room key
				}
				if((row == 10) && (col == 10)){
					spawnFuelRelic(v,150);
					//command room fuel
				}
				if((row >= 13) && (row <= 13) && (col >= 12) && (col <= 20)){
					trQuestVarSetFromRand("Temp2",7,9);
					spawnRelicSpecific(v,1*trQuestVarGet("Temp2"));
				}
				//if(cNumberNonGaiaPlayers > 4){
				if((row >= 11) && (row <= 11) && (col >= 12) && (col <= 20)){
					trQuestVarSetFromRand("Temp2",12,18);
					spawnRelicSpecific(v,1*trQuestVarGet("Temp2"));
				}
				//}
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
