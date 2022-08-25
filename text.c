string stageName(int stage = 0) {
	string name = "(This stage has not been made yet)";
	switch(stage)
	{
		case 1:
		{
			name = "Thule";
		}
		case 2:
		{
			name = "Lyssa";
		}
		case 3:
		{
			name = "Valler";
		}
		case 4:
		{
			name = "Tian";
		}
		case 5:
		{
			name = "Moxon";
		}
		case 6:
		{
			name = "Curie";
		}
		case 7:
		{
			name = "Ryatt";
		}
		case 8:
		{
			name = "Planet 8 name";
		}
		case 9:
		{
			name = "Planet 9 name";
		}
		case 10:
		{
			name = "Planet X";
		}
	}
	return(name);
}

string stageIcon(int stage = 0) {
	string img = "icons\special e son of osiris icon 64";
	if (1*trQuestVarGet("CustomContent") == 1){
		img = "Yeebaagooon\Motherload\Stage" + stage;
		return(img);
	}
	else if (1*trQuestVarGet("CustomContent") == 0){
		switch(stage)
		{
			case 1:
			{
				img = "ui_x_gp_indicator_on";
				
			}
			case 2:
			{
				img = "sfx e meteor map";
			}
			case 3:
			{
				img = "icons\improvement landlord spirit icon";
			}
			case 4:
			{
				img = "icons\improvement lord of the river icon";
			}
			case 5:
			{
				img = "ui\ui map river styx 256x256";
			}
			case 6:
			{
				img = "icons\improvement life drain icon";
			}
			case 7:
			{
				img = "icons\improvement poseidons secret icons 64";
			}
			case 8:
			{
				img = "icons\improvement safe passage icons 64";
			}
			case 9:
			{
				img = "ui\ui map erebus 256x256";
			}
			case 10:
			{
				img = "ui\ui map missing 256x256";
			}
		}
		return(img);
	}
}

//trShowImageDialog(stageIcon(Stage), stageName(Stage));

/*
Set up the numbers corresponding to dialogs
const int NPC_RELIC_TRANSPORTER = 0;
const int NPC_RELIC_TRANSPORTER_WTF = 1;
*/
void startNPCDialog(int npc = 0) {
	if (trQuestVarGet("currentNPCProgress") == 0) {
		xsEnableRule("npc_talk_01");
		trQuestVarSet("currentNPC", npc);
		trQuestVarSet("currentNPCProgress", 0);
	}
}

int npcDiag(int npc = 0, int dialog = 0) {
	dialog = dialog + 1;
	string extra = "";
	string yesPrompt = "";
	int p = trCurrentPlayer();
	switch(npc)
	{
		/*
		case NPC_THANK_YOU_SUBSCRIBER:
		{
			switch(dialog)
			{
				case 1:
				{
					uiMessageBox("Hey, thanks for subscribing to this map on the Steam Workshop!");
				}
				case 2:
				{
					uiMessageBox("Here, have this Blessing as thanks! You're the best!");
				}
				case 3:
				{
					trShowImageDialog("icons\special e son of osiris icon 64", "Hello!");
				}
				case 4:
				{
					uiMessageBox("Thank you again, and have fun!");
					xsEnableRule("subscribe_complete");
					dialog = 0;
				}
				case 5:
				{
					extra = "" + 1*trQuestVarGet("operand1") + " + " + 1*trQuestVarGet("operand2") + " = " + 1*trQuestVarGet("wrongAnswer");
					uiMessageBox("You fools! We're now trapped in a world where " + extra + "!");
				}
			}
		}
		*/
		case 1:
		{
			switch(dialog)
			{
				case 1:
				{
					trShowImageDialog("icons\special e son of osiris icon 64", "Hello!");
				}
				case 2:
				{
					trShowImageDialog("sfx a spy", "Test");
				}
				case 3:
				{
					trShowImageDialog("icons\infantry g hoplite icon 64", "Success!");
					dialog = 0;
				}
			}
		}
		case 2:
		{
			switch(dialog)
			{
				case 1:
				{
					uiMessageBox("Welcome to  " + stageName(Stage) + ", we need you to dig some minerals out of this planet!");
				}
				case 2:
				{
					uiMessageBox("Use lure or 'Q' on a square to drill it out.");
				}
				case 3:
				{
					uiMessageBox("Then pick up minerals...");
				}
				case 4:
				{
					trCameraCut(vector(62.953140,98.965134,111.442215), vector(0.001486,-0.784815,0.619728), vector(0.001882,0.619729,0.784813), vector(0.999997,0.000000,-0.002398));
					uiMessageBox("And bring them to the processing shop to sell them, no need to drop them.");
				}
				case 5:
				{
					trCameraCut(vector(146.952896,98.965134,111.240631), vector(0.001486,-0.784815,0.619728), vector(0.001882,0.619729,0.784813), vector(0.999997,0.000000,-0.002398));
					uiMessageBox("We are subsidising petrol, so fuel is free here.");
				}
				case 6:
				{
					uiMessageBox("Just remember to fill up and don't run out!");
				}
				case 7:
				{
					trCameraCut(vector(100.463554,153.803818,-59.088593), vector(0.001486,-0.784815,0.619728), vector(0.001882,0.619729,0.784813), vector(0.999997,0.000000,-0.002398));
					uiZoomToProto("Hero Greek Atalanta");
					trMessageSetText("Click the flashing signs on type 'help' for further information.", 10000);
					xSetPointer(dPlayerData, p);
					if(xGetInt(dPlayerData, xStageUnlocked) == 0){
						uiMessageBox("Make 10 gold in 8 minutes to unlock the next planet.");
					}
					dialog = 0;
				}
			}
		}
		case 3:
		{
			switch(dialog)
			{
				case 1:
				{
					uiMessageBox("Move to the sell pad to sell your minerals, no need to drop them.");
					dialog = 0;
				}
			}
		}
		case 4:
		{
			switch(dialog)
			{
				case 1:
				{
					uiMessageBox("Move your vehicle over the green fuel bar to the right to refill your fuel tank.");
				}
				case 2:
				{
					uiMessageBox("Since this is the first stage, fuel is free!");
					dialog = 0;
				}
			}
		}
		case 5:
		{
			switch(dialog)
			{
				case 1:
				{
					uiMessageBox("Move your vehicle over the green fuel bar to the right to refill your fuel tank.");
				}
				case 2:
				{
					uiMessageBox("You have to start paying for fuel now");
				}
				case 3:
				{
					uiMessageBox("Each flag gives 1000x the number on the flag as litres of fuel");
				}
				case 4:
				{
					uiMessageBox("The cost here on " + stageName(Stage) + " is still very cheap, only " + 1*FuelCost + " gold per 1000L");
					dialog = 0;
				}
			}
		}
		case 6:
		{
			switch(dialog)
			{
				case 1:
				{
					uiMessageBox("Welcome to  " + stageName(Stage) + ", you should have the hang of things by now!");
				}
				case 2:
				{
					trCameraCut(vector(146.952896,98.965134,111.240631), vector(0.001486,-0.784815,0.619728), vector(0.001882,0.619729,0.784813), vector(0.999997,0.000000,-0.002398));
					uiMessageBox("You're going to have to start paying for petrol now, but don't worry it's cheap here.");
				}
				case 3:
				{
					uiMessageBox("As always, click the signs to find out more information about refuelling.");
				}
				case 4:
				{
					trCameraCut(vector(100.463554,153.803818,-59.088593), vector(0.001486,-0.784815,0.619728), vector(0.001882,0.619729,0.784813), vector(0.999997,0.000000,-0.002398));
					uiZoomToProto("Hero Greek Atalanta");
					xSetPointer(dPlayerData, p);
					if(xGetInt(dPlayerData, xStageUnlocked) == 1){
						uiMessageBox("To unlock the next planet - upgrade your drill to level 2 and sell a gold relic on this stage.");
					}
					dialog = 0;
				}
			}
		}
		case 7:
		{
			switch(dialog)
			{
				case 1:
				{
					uiMessageBox("Backup fuel tank. Contains 200L. Cost = " + Shop1Cost);
					dialog = 0;
				}
			}
		}
		case 8:
		{
			switch(dialog)
			{
				case 1:
				{
					uiMessageBox("Dynamite. Instantly mines 2 squares in the same direction. Cost = " + Shop2Cost);
				}
				case 2:
				{
					uiMessageBox("Dynamite should be used like a drill, but press 'W' instead.");
					dialog = 0;
				}
			}
		}
		case 9:
		{
			switch(dialog)
			{
				case 1:
				{
					uiMessageBox("Emergency surface teleport. Cost = " + Shop3Cost);
					dialog = 0;
				}
			}
		}
		case 10:
		{
			switch(dialog)
			{
				case 1:
				{
					uiMessageBox("Welcome to  " + stageName(Stage) + ", more riches await us here!");
				}
				case 2:
				{
					trCameraCut(vector(96.952896,98.965134,89.240631), vector(0.001486,-0.784815,0.619728), vector(0.001882,0.619729,0.784813), vector(0.999997,0.000000,-0.002398));
					uiMessageBox("You now have access to an item shop.");
				}
				case 3:
				{
					uiMessageBox("Anything purchased here will not be saved, so it must be used here.");
				}
				case 4:
				{
					trCameraCut(vector(100.463554,153.803818,-59.088593), vector(0.001486,-0.784815,0.619728), vector(0.001882,0.619729,0.784813), vector(0.999997,0.000000,-0.002398));
					uiZoomToProto("Hero Greek Atalanta");
					xSetPointer(dPlayerData, p);
					if(xGetInt(dPlayerData, xStageUnlocked) == 2){
						uiMessageBox("To unlock the next planet - upgrade your hull to level 3 and make 25 profit on this stage.");
					}
					dialog = 0;
				}
			}
		}
		case 11:
		{
			switch(dialog)
			{
				case 1:
				{
					uiMessageBox("Move your vehicle over the green fuel bar to the right to refill your fuel tank.");
				}
				case 2:
				{
					uiMessageBox("Each flag gives 1000x the number on the flag as litres of fuel");
				}
				case 3:
				{
					uiMessageBox("We've had to stop subsidies now, so fuel is a bit more expensive at " + 1*FuelCost + " gold per 1000L");
					dialog = 0;
				}
			}
		}
		case 100:
		{
			switch(dialog)
			{
				case 1:
				{
					trChatHistoryClear();
					trChatSend(0, "<u><color=1,1,1>Current Drill:</color></u>");
					trChatSend(0, trStringQuestVarGet("DrillL"+1*trQuestVarGet("CurrentDrillL")+"") + " "+1*xGetFloat(dPlayerData, xDrillPower)+" m/s");
					uiMessageBox("Your drill power controls how easy it is to drill through harder rock.");
				}
				case 2:
				{
					xSetPointer(dPlayerData, 1);
					uiMessageBox("Current drill power = " + 1*xGetFloat(dPlayerData, xDrillPower) +  " m/s");
					dialog = 0;
				}
			}
		}
		case 12:
		{
			switch(dialog)
			{
				case 1:
				{
					uiMessageBox("Welcome to  " + stageName(Stage) + ", more riches await us here!");
				}
				case 2:
				{
					trCameraCut(vector(96.952896,98.965134,89.240631), vector(0.001486,-0.784815,0.619728), vector(0.001882,0.619729,0.784813), vector(0.999997,0.000000,-0.002398));
					uiMessageBox("Hull repair has been added to the shop.");
				}
				case 3:
				{
					uiMessageBox("With increasing riches come increasing dangers.");
				}
				case 4:
				{
					uiMessageBox("Be careful if you carry radioactive minerals.");
				}
				case 5:
				{
					trCameraCut(vector(100.463554,153.803818,-59.088593), vector(0.001486,-0.784815,0.619728), vector(0.001882,0.619729,0.784813), vector(0.999997,0.000000,-0.002398));
					uiZoomToProto("Hero Greek Atalanta");
					xSetPointer(dPlayerData, p);
					if(xGetInt(dPlayerData, xStageUnlocked) == 3){
						uiMessageBox("To unlock the next planet - upgrade all ship components to at least level 3.");
					}
					dialog = 0;
				}
			}
		}
		case 13:
		{
			switch(dialog)
			{
				case 1:
				{
					uiMessageBox("Hull repair. Cost = " + Shop4Cost + " per 250hp");
					dialog = 0;
				}
			}
		}
		case 14:
		{
			switch(dialog)
			{
				case 1:
				{
					uiMessageBox("Welcome to  " + stageName(Stage) + ", the first of the gas giants!");
				}
				case 2:
				{
					uiMessageBox("The intense pressure here has formed some wonderful gems.");
				}
				case 3:
				{
					trCameraCut(vector(146.952896,98.965134,111.240631), vector(0.001486,-0.784815,0.619728), vector(0.001882,0.619729,0.784813), vector(0.999997,0.000000,-0.002398));
					uiMessageBox("The hull repair mechanic is now the same as refuelling.");
				}
				case 4:
				{
					uiMessageBox("Watch out for escaping gas, and keep an eye on your hull and fuel.");
				}
				case 5:
				{
					trCameraCut(vector(100.463554,153.803818,-59.088593), vector(0.001486,-0.784815,0.619728), vector(0.001882,0.619729,0.784813), vector(0.999997,0.000000,-0.002398));
					uiZoomToProto("Hero Greek Atalanta");
					xSetPointer(dPlayerData, p);
					if(xGetInt(dPlayerData, xStageUnlocked) == 4){
						uiMessageBox("To unlock the next planet - reach a depth of 2km and make 50 profit in the same game.");
					}
					dialog = 0;
				}
			}
		}
		case 15:
		{
			switch(dialog)
			{
				case 1:
				{
					uiMessageBox("Hull repair. Cost = " + HullCost + " per 250hp");
				}
				case 2:
				{
					uiMessageBox("Each flag will repair 250hp x the value stated.");
					dialog = 0;
				}
			}
		}
		case 16:
		{
			switch(dialog)
			{
				case 1:
				{
					uiMessageBox("This planet is toxic, we can't stay here too long!");
				}
				case 2:
				{
					uiMessageBox("There is an abundance of rare radioactive minerals.");
				}
				case 3:
				{
					trCameraCut(vector(96.952896,98.965134,89.240631), vector(0.001486,-0.784815,0.619728), vector(0.001882,0.619729,0.784813), vector(0.999997,0.000000,-0.002398));
					uiMessageBox("We upgraded and changed the shop to help out a bit!");
				}
				case 4:
				{
					trCameraCut(vector(100.463554,153.803818,-59.088593), vector(0.001486,-0.784815,0.619728), vector(0.001882,0.619729,0.784813), vector(0.999997,0.000000,-0.002398));
					uiZoomToProto("Hero Greek Atalanta");
					xSetPointer(dPlayerData, p);
					if(xGetInt(dPlayerData, xStageUnlocked) == 5){
						uiMessageBox("To unlock the next planet - you need drill level 5 and selling a diamond with 200 profit.");
					}
					dialog = 0;
				}
			}
		}
		case 17:
		{
			switch(dialog)
			{
				case 1:
				{
					uiMessageBox("Plastic explosive. Instantly mines all squares around you. Cost = " + Shop2Cost);
					dialog = 0;
				}
			}
		}
		case 18:
		{
			switch(dialog)
			{
				case 1:
				{
					uiMessageBox("Each flag gives 1000x the number on the flag as litres of fuel");
				}
				case 2:
				{
					uiMessageBox("Fuel is " + 1*FuelCost + " gold per 1000L");
					dialog = 0;
				}
			}
		}
		case 19:
		{
			switch(dialog)
			{
				case 1:
				{
					uiMessageBox("The last of the gas giants!");
				}
				case 2:
				{
					uiMessageBox("Our scans indicate some rare gems at great depths.");
				}
				case 3:
				{
					trCameraCut(vector(100.463554,153.803818,-59.088593), vector(0.001486,-0.784815,0.619728), vector(0.001882,0.619729,0.784813), vector(0.999997,0.000000,-0.002398));
					uiZoomToProto("Hero Greek Atalanta");
					xSetPointer(dPlayerData, p);
					if(xGetInt(dPlayerData, xStageUnlocked) == 6){
						uiMessageBox("To unlock the next planet - sell a lump of obsidian with 150 profit.");
					}
					dialog = 0;
				}
			}
		}
		case 20:
		{
			switch(dialog)
			{
				case 1:
				{
					uiMessageBox("It sure is chilly here!");
				}
				case 2:
				{
					uiMessageBox("This glistening planet has a diamond crust.");
				}
				case 3:
				{
					uiMessageBox("This, along with millions of years of gravitationally compacted ice means you'll need a strong drill.");
				}
				case 4:
				{
					trCameraCut(vector(100.463554,153.803818,-59.088593), vector(0.001486,-0.784815,0.619728), vector(0.001882,0.619729,0.784813), vector(0.999997,0.000000,-0.002398));
					uiZoomToProto("Hero Greek Atalanta");
					xSetPointer(dPlayerData, p);
					if(xGetInt(dPlayerData, xStageUnlocked) == 6){
						uiMessageBox("To unlock the next planet - sell x with 500 profit and upgrade all stats to at least level 6.");
					}
					dialog = 0;
				}
			}
		}
		case 101:
		{
			switch(dialog)
			{
				case 1:
				{
					xSetPointer(dPlayerData, 1);
					trQuestVarSet("CurrentDrillL", xGetInt(dPlayerData, xDrillLevel));
					trQuestVarSet("NextDrillL", 1*trQuestVarGet("CurrentDrillL")+1);
					trQuestVarSet("goldCost", 1*trQuestVarGet("DrillCostL"+1*trQuestVarGet("NextDrillL")+""));
					yesPrompt = "Yes (" + 1*trQuestVarGet("goldCost") + " gold )";
					string DrillUp = trStringQuestVarGet("DrillL"+1*trQuestVarGet("NextDrillL")+"");
					if(trPlayerResourceCount(1, "Gold") < 1*trQuestVarGet("goldCost")){
						uiMessageBox("You do not have enough gold to upgrade your drill! (" + 1*trQuestVarGet("goldCost") + ")");
						dialog = 0;
						trChatHistoryClear();
						trChatSend(0, "<u><color=1,1,1>Current Drill:</color></u>");
						trChatSend(0, trStringQuestVarGet("DrillL"+1*trQuestVarGet("CurrentDrillL")+"") + " "+1*xGetFloat(dPlayerData, xDrillPower)+" m/s");
						trChatSend(0, "<u><color=1,1,1>Upgraded Drill:</color></u>");
						trChatSend(0, DrillUp + " "+1*trQuestVarGet("DrillPowerL"+1*trQuestVarGet("NextDrillL")+"")+" m/s");
					}
					else if(trPlayerResourceCount(1, "Gold") >= 1*trQuestVarGet("goldCost")){
						if (xGetInt(dPlayerData, xDrillLevel) < 8) {
							trShowChoiceDialog("Increase drill to level " + 1*trQuestVarGet("NextDrillL") + "?",
								yesPrompt, 17, "No", -1);
						} else {
							uiMessageBox("You have reached the max level!");
						}
						trChatHistoryClear();
						trChatSend(0, "<u><color=1,1,1>Current Drill:</color></u>");
						trChatSend(0, trStringQuestVarGet("DrillL"+1*trQuestVarGet("CurrentDrillL")+"") + " "+1*xGetFloat(dPlayerData, xDrillPower)+" m/s");
						trChatSend(0, "<u><color=1,1,1>Upgraded Drill:</color></u>");
						trChatSend(0, DrillUp + " "+1*trQuestVarGet("DrillPowerL"+1*trQuestVarGet("NextDrillL")+"")+" m/s");
						dialog = 0;
					}
				}
			}
		}
		case 200:
		{
			switch(dialog)
			{
				case 1:
				{
					uiMessageBox("Your hull strength determines how much damage your ship can take before exploding.");
				}
				case 2:
				{
					xSetPointer(dPlayerData, 1);
					uiMessageBox("Current hull strength = " + 1*xGetInt(dPlayerData, xHullHP) +  " hp");
					dialog = 0;
				}
			}
		}
		case 201:
		{
			switch(dialog)
			{
				case 1:
				{
					xSetPointer(dPlayerData, 1);
					trQuestVarSet("CurrentHullL", xGetInt(dPlayerData, xHullLevel));
					trQuestVarSet("NextHullL", 1*trQuestVarGet("CurrentHullL")+1);
					trQuestVarSet("goldCost", 1*trQuestVarGet("HullCostL"+1*trQuestVarGet("NextHullL")+""));
					yesPrompt = "Yes (" + 1*trQuestVarGet("goldCost") + " gold )";
					string HullUp = trStringQuestVarGet("HullL"+1*trQuestVarGet("NextHullL")+"");
					if(trPlayerResourceCount(1, "Gold") < 1*trQuestVarGet("goldCost")){
						uiMessageBox("You do not have enough gold to upgrade your hull! (" + 1*trQuestVarGet("goldCost") + ")");
						dialog = 0;
						trChatHistoryClear();
						trChatSend(0, "<u><color=1,1,1>Current Hull:</color></u>");
						trChatSend(0, trStringQuestVarGet("HullL"+1*trQuestVarGet("CurrentHullL")+"") + " "+1*xGetInt(dPlayerData, xHullHP)+" hp");
						trChatSend(0, "<u><color=1,1,1>Upgraded Hull:</color></u>");
						trChatSend(0, HullUp + " "+1*trQuestVarGet("HullHPL"+1*trQuestVarGet("NextHullL")+"")+" hp");
					}
					else if(trPlayerResourceCount(1, "Gold") >= 1*trQuestVarGet("goldCost")){
						if (xGetInt(dPlayerData, xHullLevel) < 8) {
							trShowChoiceDialog("Increase hull to level " + 1*trQuestVarGet("NextHullL") + "?",
								yesPrompt, 18, "No", -1);
						} else {
							uiMessageBox("You have reached the max level!");
						}
						trChatHistoryClear();
						trChatSend(0, "<u><color=1,1,1>Current Hull:</color></u>");
						trChatSend(0, trStringQuestVarGet("HullL"+1*trQuestVarGet("CurrentHullL")+"") + " "+1*xGetInt(dPlayerData, xHullHP)+" hp");
						trChatSend(0, "<u><color=1,1,1>Upgraded Hull:</color></u>");
						trChatSend(0, HullUp + " "+1*trQuestVarGet("HullHPL"+1*trQuestVarGet("NextHullL")+"")+" hp");
						dialog = 0;
					}
				}
			}
		}
		case 300:
		{
			switch(dialog)
			{
				case 1:
				{
					uiMessageBox("Your fuel tank capacity is fairly self explanatory.");
				}
				case 2:
				{
					uiMessageBox("Current fuel tank capacity =  "+ 1*xGetInt(dPlayerData, xFuelTank) +  " L");
					dialog = 0;
				}
			}
		}
		case 301:
		{
			switch(dialog)
			{
				case 1:
				{
					xSetPointer(dPlayerData, 1);
					trQuestVarSet("CurrentFuelL", xGetInt(dPlayerData, xFuelLevel));
					trQuestVarSet("NextFuelL", 1*trQuestVarGet("CurrentFuelL")+1);
					trQuestVarSet("goldCost", 1*trQuestVarGet("FuelCostL"+1*trQuestVarGet("NextFuelL")+""));
					yesPrompt = "Yes (" + 1*trQuestVarGet("goldCost") + " gold )";
					string FuelUp = trStringQuestVarGet("FuelL"+1*trQuestVarGet("NextFuelL")+"");
					if(trPlayerResourceCount(1, "Gold") < 1*trQuestVarGet("goldCost")){
						uiMessageBox("You do not have enough gold to upgrade your Fuel! (" + 1*trQuestVarGet("goldCost") + ")");
						dialog = 0;
						trChatHistoryClear();
						trChatSend(0, "<u><color=1,1,1>Current Fuel:</color></u>");
						trChatSend(0, trStringQuestVarGet("FuelL"+1*trQuestVarGet("CurrentFuelL")+"") + " "+1*xGetInt(dPlayerData, xFuelTank)+" L");
						trChatSend(0, "<u><color=1,1,1>Upgraded Fuel:</color></u>");
						trChatSend(0, FuelUp + " "+1*trQuestVarGet("FuelCL"+1*trQuestVarGet("NextFuelL")+"")+" L");
					}
					else if(trPlayerResourceCount(1, "Gold") >= 1*trQuestVarGet("goldCost")){
						if (xGetInt(dPlayerData, xFuelLevel) < 8) {
							trShowChoiceDialog("Increase Fuel to level " + 1*trQuestVarGet("NextFuelL") + "?",
								yesPrompt, 19, "No", -1);
						} else {
							uiMessageBox("You have reached the max level!");
						}
						trChatHistoryClear();
						trChatSend(0, "<u><color=1,1,1>Current Fuel:</color></u>");
						trChatSend(0, trStringQuestVarGet("FuelL"+1*trQuestVarGet("CurrentFuelL")+"") + " "+1*xGetInt(dPlayerData, xFuelTank)+" L");
						trChatSend(0, "<u><color=1,1,1>Upgraded Fuel:</color></u>");
						trChatSend(0, FuelUp + " "+1*trQuestVarGet("FuelCL"+1*trQuestVarGet("NextFuelL")+"")+" L");
						dialog = 0;
					}
				}
			}
		}
		case 400:
		{
			switch(dialog)
			{
				case 1:
				{
					uiMessageBox("Your cargo hold specifies how many minerals you can hold at any one time.");
				}
				case 2:
				{
					uiMessageBox("Current cargo hold limit = "+ 1*xGetInt(dPlayerData, xCargoHold) +  " minerals");
					dialog = 0;
				}
			}
		}
		case 401:
		{
			switch(dialog)
			{
				case 1:
				{
					xSetPointer(dPlayerData, 1);
					trQuestVarSet("CurrentCargoL", xGetInt(dPlayerData, xCargoLevel));
					trQuestVarSet("NextCargoL", 1*trQuestVarGet("CurrentCargoL")+1);
					trQuestVarSet("goldCost", 1*trQuestVarGet("CargoCostL"+1*trQuestVarGet("NextCargoL")+""));
					yesPrompt = "Yes (" + 1*trQuestVarGet("goldCost") + " gold )";
					string CargoUp = trStringQuestVarGet("CargoL"+1*trQuestVarGet("NextCargoL")+"");
					if(trPlayerResourceCount(1, "Gold") < 1*trQuestVarGet("goldCost")){
						uiMessageBox("You do not have enough gold to upgrade your cargo hold! (" + 1*trQuestVarGet("goldCost") + ")");
						dialog = 0;
						trChatHistoryClear();
						trChatSend(0, "<u><color=1,1,1>Current cargo hold:</color></u>");
						trChatSend(0, trStringQuestVarGet("CargoL"+1*trQuestVarGet("CurrentCargoL")+"") + " "+1*xGetInt(dPlayerData, xCargoHold)+" minerals");
						trChatSend(0, "<u><color=1,1,1>Upgraded cargo hold:</color></u>");
						trChatSend(0, CargoUp + " "+1*trQuestVarGet("CargoCL"+1*trQuestVarGet("NextCargoL")+"")+" minerals");
					}
					else if(trPlayerResourceCount(1, "Gold") >= 1*trQuestVarGet("goldCost")){
						if (xGetInt(dPlayerData, xCargoLevel) < 8) {
							trShowChoiceDialog("Increase Cargo to level " + 1*trQuestVarGet("NextCargoL") + "?",
								yesPrompt, 20, "No", -1);
						} else {
							uiMessageBox("You have reached the max level!");
						}
						trChatHistoryClear();
						trChatSend(0, "<u><color=1,1,1>Current cargo hold:</color></u>");
						trChatSend(0, trStringQuestVarGet("CargoL"+1*trQuestVarGet("CurrentCargoL")+"") + " "+1*xGetInt(dPlayerData, xCargoHold)+" minerals");
						trChatSend(0, "<u><color=1,1,1>Upgraded cargo hold:</color></u>");
						trChatSend(0, CargoUp + " "+1*trQuestVarGet("CargoCL"+1*trQuestVarGet("NextCargoL")+"")+" minerals");
						dialog = 0;
					}
				}
			}
		}
		case 500:
		{
			switch(dialog)
			{
				case 1:
				{
					uiMessageBox("A more powerful engine will help with fuel efficiency.");
				}
				case 2:
				{
					uiMessageBox("Current engine power = "+ 1*xGetInt(dPlayerData, xEnginePower) +  " kW");
					dialog = 0;
				}
			}
		}
		case 501:
		{
			switch(dialog)
			{
				case 1:
				{
					xSetPointer(dPlayerData, 1);
					trQuestVarSet("CurrentEngineL", xGetInt(dPlayerData, xEngineLevel));
					trQuestVarSet("NextEngineL", 1*trQuestVarGet("CurrentEngineL")+1);
					trQuestVarSet("goldCost", 1*trQuestVarGet("EngineCostL"+1*trQuestVarGet("NextEngineL")+""));
					yesPrompt = "Yes (" + 1*trQuestVarGet("goldCost") + " gold )";
					string EngineUp = trStringQuestVarGet("EngineL"+1*trQuestVarGet("NextEngineL")+"");
					if(trPlayerResourceCount(1, "Gold") < 1*trQuestVarGet("goldCost")){
						uiMessageBox("You do not have enough gold to upgrade your engine! (" + 1*trQuestVarGet("goldCost") + ")");
						dialog = 0;
						trChatHistoryClear();
						trChatSend(0, "<u><color=1,1,1>Current Engine:</color></u>");
						trChatSend(0, trStringQuestVarGet("EngineL"+1*trQuestVarGet("CurrentEngineL")+"") + " "+1*xGetInt(dPlayerData, xEnginePower)+" kW");
						trChatSend(0, "<u><color=1,1,1>Upgraded Engine:</color></u>");
						trChatSend(0, EngineUp + " "+1*trQuestVarGet("EngineCL"+1*trQuestVarGet("NextEngineL")+"")+" kW");
					}
					else if(trPlayerResourceCount(1, "Gold") >= 1*trQuestVarGet("goldCost")){
						if (xGetInt(dPlayerData, xEngineLevel) < 8) {
							trShowChoiceDialog("Increase engine to level " + 1*trQuestVarGet("NextEngineL") + "?",
								yesPrompt, 21, "No", -1);
						} else {
							uiMessageBox("You have reached the max level!");
						}
						trChatHistoryClear();
						trChatSend(0, "<u><color=1,1,1>Current Engine:</color></u>");
						trChatSend(0, trStringQuestVarGet("EngineL"+1*trQuestVarGet("CurrentEngineL")+"") + " "+1*xGetInt(dPlayerData, xEnginePower)+" kW");
						trChatSend(0, "<u><color=1,1,1>Upgraded Engine:</color></u>");
						trChatSend(0, EngineUp + " "+1*trQuestVarGet("EngineCL"+1*trQuestVarGet("NextEngineL")+"")+" kW");
						dialog = 0;
					}
				}
			}
		}
		case 600:
		{
			switch(dialog)
			{
				case 1:
				{
					uiMessageBox("Your radiator will help save fuel and prevent temperature damage.");
				}
				case 2:
				{
					uiMessageBox("Current radiator efficiency = "+ 1*xGetInt(dPlayerData, xRadiator) +  " percent");
					dialog = 0;
				}
			}
		}
		case 601:
		{
			switch(dialog)
			{
				case 1:
				{
					xSetPointer(dPlayerData, 1);
					trQuestVarSet("CurrentRadiatorL", xGetInt(dPlayerData, xRadiatorLevel));
					trQuestVarSet("NextRadiatorL", 1*trQuestVarGet("CurrentRadiatorL")+1);
					trQuestVarSet("goldCost", 1*trQuestVarGet("RadiatorCostL"+1*trQuestVarGet("NextRadiatorL")+""));
					yesPrompt = "Yes (" + 1*trQuestVarGet("goldCost") + " gold )";
					string RadiatorUp = trStringQuestVarGet("RadiatorL"+1*trQuestVarGet("NextRadiatorL")+"");
					if(trPlayerResourceCount(1, "Gold") < 1*trQuestVarGet("goldCost")){
						uiMessageBox("You do not have enough gold to upgrade your Radiator! (" + 1*trQuestVarGet("goldCost") + ")");
						dialog = 0;
						trChatHistoryClear();
						trChatSend(0, "<u><color=1,1,1>Current Radiator:</color></u>");
						trChatSend(0, trStringQuestVarGet("RadiatorL"+1*trQuestVarGet("CurrentRadiatorL")+"") + " "+1*xGetInt(dPlayerData, xRadiator)+" percent efficient");
						trChatSend(0, "<u><color=1,1,1>Upgraded Radiator:</color></u>");
						trChatSend(0, RadiatorUp + " "+1*trQuestVarGet("RadiatorCL"+1*trQuestVarGet("NextRadiatorL")+"")+" percent efficient");
					}
					else if(trPlayerResourceCount(1, "Gold") >= 1*trQuestVarGet("goldCost")){
						if (xGetInt(dPlayerData, xRadiatorLevel) < 8) {
							trShowChoiceDialog("Increase Radiator to level " + 1*trQuestVarGet("NextRadiatorL") + "?",
								yesPrompt, 22, "No", -1);
						} else {
							uiMessageBox("You have reached the max level!");
						}
						trChatHistoryClear();
						trChatSend(0, "<u><color=1,1,1>Current Radiator:</color></u>");
						trChatSend(0, trStringQuestVarGet("RadiatorL"+1*trQuestVarGet("CurrentRadiatorL")+"") + " "+1*xGetInt(dPlayerData, xRadiator)+" percent efficient");
						trChatSend(0, "<u><color=1,1,1>Upgraded Radiator:</color></u>");
						trChatSend(0, RadiatorUp + " "+1*trQuestVarGet("RadiatorCL"+1*trQuestVarGet("NextRadiatorL")+"")+" percent efficient");
						dialog = 0;
					}
				}
			}
		}
	}
	return(dialog);
}

rule npc_talk_01
inactive
highFrequency
{
	xsDisableSelf();
	trQuestVarSet("currentNPCProgress",
		npcDiag(1*trQuestVarGet("currentNPC"), 1*trQuestVarGet("currentNPCProgress")));
	if (trQuestVarGet("currentNPCProgress") > 0) {
		trDelayedRuleActivation("npc_talk_02");
	}
}

rule npc_talk_02
inactive
highFrequency
{
	if ((trQuestVarGet("currentNPCProgress") > 0) &&
		(trIsGadgetVisible("ingame-messagedialog") == false) &&
		(trIsGadgetVisible("ShowImageBox") == false)) {
		trDelayedRuleActivation("npc_talk_01");
		xsDisableSelf();
	}
}
