//This paints the overworld terrain for each stage
void GroundType(int rock = 0) {
	switch(rock)
	{
		case 1:
		{
			OVERTERRAIN_TYPE = 3;
			OVERTERRAIN_SUBTYPE = 13;
		}
	}
}

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
			name = "Planet 2 name";
		}
		case 3:
		{
			name = "Planet 3 name";
		}
		case 4:
		{
			name = "Planet 4 name";
		}
		case 5:
		{
			name = "Planet 5 name";
		}
		case 6:
		{
			name = "Planet 6 name";
		}
		case 7:
		{
			name = "Planet 7 name";
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
				img = "ui\ui map deep jungle 256x256";
			}
			case 3:
			{
				img = "ui\ui map jotunheim 256x256";
			}
			case 4:
			{
				img = "ui\ui map open fields 256x256";
			}
			case 5:
			{
				img = "ui\ui map river styx 256x256";
			}
			case 6:
			{
				img = "icons\building siege workshop icon 64";
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
					uiMessageBox("Welcome to Thule, we need you to dig some minerals out of this planet!");
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
					uiMessageBox("And drop them infront of the processing shop to sell them");
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
					uiMessageBox("Make 10 gold in 8 minutes to unlock the next planet, as well as the ability to upgrade your ship.");
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
					uiMessageBox("Drop garrisoned minerals on the 'sell' pad to sell them.");
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
					if(trPlayerResourceCount(1, "Gold") < 1*trQuestVarGet("goldCost")){
						uiMessageBox("You do not have enough gold to upgrade your drill! (" + 1*trQuestVarGet("goldCost") + ")");
						dialog = 0;
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
						string DrillUp = trStringQuestVarGet("DrillL"+1*trQuestVarGet("NextDrillL")+"");
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
					if(trPlayerResourceCount(1, "Gold") < 1*trQuestVarGet("goldCost")){
						uiMessageBox("You do not have enough gold to upgrade your hull! (" + 1*trQuestVarGet("goldCost") + ")");
						dialog = 0;
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
						string HullUp = trStringQuestVarGet("HullL"+1*trQuestVarGet("NextHullL")+"");
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
					if(trPlayerResourceCount(1, "Gold") < 1*trQuestVarGet("goldCost")){
						uiMessageBox("You do not have enough gold to upgrade your Fuel! (" + 1*trQuestVarGet("goldCost") + ")");
						dialog = 0;
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
						string FuelUp = trStringQuestVarGet("FuelL"+1*trQuestVarGet("NextFuelL")+"");
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
