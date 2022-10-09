void playSoundCustom(string BasesoundName = "", string CustomsoundName = ""){
	if((1*trQuestVarGet("CustomContent") == 0) || (CustomsoundName == "")){
		trSoundPlayPaused(""+BasesoundName+"", "1", -1, "", "");
	}
	else{
		trSoundPlayPaused(""+CustomsoundName+"", "1", -1, "", "");
	}
}

void ColouredIconChat(string colour = "1,1,1", string icon = "", string chats = ""){
	trChatSend(0, "<color="+colour+"><icon=(20)("+icon+")> "+chats+"</color>");
}

void ColouredChat(string colour = "1,1,1", string chats = ""){
	trChatSend(0, "<color="+colour+">"+chats+"</color>");
}

void PlayerColouredChat(int colour = 1, string chats = ""){
	trChatSend(0, "<color={PlayerColor("+colour+")}>"+chats+"</color>");
}

void ColouredIconChatToPlayer(int p = 1, string colour = "1,1,1", string icon = "", string chats = ""){
	trChatSendToPlayer(0, p, "<color=" + colour + "><icon=(20)(" + icon + ")> " + chats + "</color>");
}

void ColouredChatToPlayer(int p = 1, string colour = "1,1,1", string chats = ""){
	trChatSendToPlayer(0, p, "<color=" + colour + ">" + chats + "</color>");
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
			name = "Ryloth";
		}
		case 8:
		{
			name = "Triton";
		}
		case 9:
		{
			name = "Sedna";
		}
		case 10:
		{
			name = "Mr. Natas' Ship";
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
				img = "ui\ui map boarder highlight 128x128";
			}
			case 6:
			{
				img = "icons\improvement life drain icon";
			}
			case 7:
			{
				img = "icons\improvement slings of the sun icon 64";
			}
			case 8:
			{
				img = "icons\improvement champion slinger icon 64";
			}
			case 9:
			{
				img = "icons\improvement focus icons 64";
			}
			case 10:
			{
				img = "icons\improvement long serpent icon 64";
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
					if(xGetInt(dPlayerData, xStageUnlocked) >= 4){
						dialog = 0;
					}
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
						ColouredIconChat("1,0.5,0", "icons\siege x fire siphon icons 64", "Press Q to drill to your cursor!");
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
					if(xGetInt(dPlayerData, xStageUnlocked) >= 4){
						dialog = 0;
					}
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
						ColouredIconChat("1,0.5,0", "icons\siege x fire siphon icons 64", "To upgrade your ship - launch this map in singleplayer!");
					}
					if(xGetInt(dPlayerData, xStageUnlocked) == 0){
						uiMessageBox("Try and make as much money as you can.");
						ColouredIconChat("1,0.5,0", "icons\siege x fire siphon icons 64", "Press Q to drill to your cursor!");
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
					if(xGetInt(dPlayerData, xStageUnlocked) >= 5){
						dialog = 0;
					}
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
		case 12:
		{
			switch(dialog)
			{
				case 1:
				{
					uiMessageBox("Welcome to  " + stageName(Stage) + ", more valuable minerals await us here!");
					if(xGetInt(dPlayerData, xStageUnlocked) >= 6){
						dialog = 0;
					}
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
					trChatSend(0, "<color=1,1,1>Type 'goal' to see win conditions for the current planet you are on.</color>");
					trChatSend(0, "<color=1,1,1>Type 'hotkey' to be reminded of available game controls.</color>");
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
					if(xGetInt(dPlayerData, xStageUnlocked) >= 7){
						dialog = 0;
					}
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
						trChatSend(0, "<color=1,1,1>Type 'goal' to see win conditions for the current planet you are on.</color>");
						trChatSend(0, "<color=1,1,1>Type 'hotkey' to be reminded of available game controls.</color>");
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
					if(xGetInt(dPlayerData, xStageUnlocked) >= 8){
						dialog = 0;
					}
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
						uiMessageBox("To unlock the next planet - you need drill level 5 AND sell a diamond AND make 200 profit.");
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
					if(xGetInt(dPlayerData, xStageUnlocked) >= 9){
						dialog = 0;
					}
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
						uiMessageBox("To unlock the next planet - sell a lump of obsidian and make 150 profit.");
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
					if(xGetInt(dPlayerData, xStageUnlocked) >= 9){
						dialog = 0;
					}
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
					trCameraCut(vector(146.952896,98.965134,111.240631), vector(0.001486,-0.784815,0.619728), vector(0.001882,0.619729,0.784813), vector(0.999997,0.000000,-0.002398));
					uiMessageBox("Fuel profits are getting extortionate even out here now, must be something to do with Ukrainium.");
				}
				case 5:
				{
					trCameraCut(vector(100.463554,153.803818,-59.088593), vector(0.001486,-0.784815,0.619728), vector(0.001882,0.619729,0.784813), vector(0.999997,0.000000,-0.002398));
					uiZoomToProto("Hero Greek Atalanta");
					xSetPointer(dPlayerData, p);
					if(xGetInt(dPlayerData, xStageUnlocked) == 7){
						uiMessageBox("To unlock the final planet - make 350 profit here.");
					}
					dialog = 0;
				}
			}
		}
		case 21:
		{
			switch(dialog)
			{
				case 1:
				{
					uiMessageBox("Nuclear explosive. Instantly mines 2 squares around you. Cost = " + Shop2Cost);
					dialog = 0;
				}
			}
		}
		case 22:
		{
			switch(dialog)
			{
				case 1:
				{
					uiMessageBox("YOU SHOULD NOT BE HERE!");
				}
				case 2:
				{
					uiMessageBox("TURN AROUND IMMEDIATELY.");
				}
				case 3:
				{
					trCameraCut(vector(100.463554,153.803818,-59.088593), vector(0.001486,-0.784815,0.619728), vector(0.001882,0.619729,0.784813), vector(0.999997,0.000000,-0.002398));
					uiZoomToProto("Hero Greek Atalanta");
					xSetPointer(dPlayerData, p);
					if(xGetInt(dPlayerData, xStageUnlocked) == 8){
						uiMessageBox("THERE IS NOTHING TO SEE OR MINE HERE!");
					}
					dialog = 0;
				}
			}
		}
		case 23:
		{
			switch(dialog)
			{
				case 1:
				{
					uiMessageBox("MWAHAHAHA!");
				}
				case 2:
				{
					uiMessageBox("YOU SHALL NEVER SUCCEED.");
				}
				case 3:
				{
					uiZoomToProto("Hero Greek Atalanta");
					uiMessageBox("MY RICHES ARE MINE!");
					dialog = 0;
				}
			}
		}
		case 24:
		{
			switch(dialog)
			{
				case 1:
				{
					uiMessageBox("Map percent complete = " + Completion);
					dialog = 0;
				}
			}
		}
		case 99:
		{
			switch(dialog){
				case 1:
				{
					trShowChoiceDialog("Watch introduction cinematic?", "Yes", 15, "No", 16);
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
					string DrillUp = trStringQuestVarGet("DrillL"+1*trQuestVarGet("NextDrillL")+"");
					if(xGetInt(dPlayerData, xGold) < 1*trQuestVarGet("goldCost")){
						uiMessageBox("You do not have enough gold to upgrade your drill! (" + 1*trQuestVarGet("goldCost") + ")");
						dialog = 0;
						trChatHistoryClear();
						trChatSend(0, "<u><color=1,1,1>Current Drill:</color></u>");
						trChatSend(0, trStringQuestVarGet("DrillL"+1*trQuestVarGet("CurrentDrillL")+"") + " "+1*xGetFloat(dPlayerData, xDrillPower)+" m/s");
						trChatSend(0, "<u><color=1,1,1>Upgraded Drill:</color></u>");
						trChatSend(0, DrillUp + " "+1*trQuestVarGet("DrillPowerL"+1*trQuestVarGet("NextDrillL")+"")+" m/s");
					}
					else if(xGetInt(dPlayerData, xGold) >= 1*trQuestVarGet("goldCost")){
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
					trChatHistoryClear();
					trChatSend(0, "<u><color=1,1,1>Current Hull:</color></u>");
					trChatSend(0, trStringQuestVarGet("HullL"+1*trQuestVarGet("CurrentHullL")+"") + " "+1*xGetInt(dPlayerData, xHullHP)+" hp");
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
					if(xGetInt(dPlayerData, xGold) < 1*trQuestVarGet("goldCost")){
						uiMessageBox("You do not have enough gold to upgrade your hull! (" + 1*trQuestVarGet("goldCost") + ")");
						dialog = 0;
						trChatHistoryClear();
						trChatSend(0, "<u><color=1,1,1>Current Hull:</color></u>");
						trChatSend(0, trStringQuestVarGet("HullL"+1*trQuestVarGet("CurrentHullL")+"") + " "+1*xGetInt(dPlayerData, xHullHP)+" hp");
						trChatSend(0, "<u><color=1,1,1>Upgraded Hull:</color></u>");
						trChatSend(0, HullUp + " "+1*trQuestVarGet("HullHPL"+1*trQuestVarGet("NextHullL")+"")+" hp");
					}
					else if(xGetInt(dPlayerData, xGold) >= 1*trQuestVarGet("goldCost")){
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
					trChatHistoryClear();
					trChatSend(0, "<u><color=1,1,1>Current Fuel Tank:</color></u>");
					trChatSend(0, trStringQuestVarGet("FuelL"+1*trQuestVarGet("CurrentFuelL")+"") + " "+1*xGetInt(dPlayerData, xFuelTank)+" L");
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
					if(xGetInt(dPlayerData, xGold) < 1*trQuestVarGet("goldCost")){
						uiMessageBox("You do not have enough gold to upgrade your Fuel! (" + 1*trQuestVarGet("goldCost") + ")");
						dialog = 0;
						trChatHistoryClear();
						trChatSend(0, "<u><color=1,1,1>Current Fuel:</color></u>");
						trChatSend(0, trStringQuestVarGet("FuelL"+1*trQuestVarGet("CurrentFuelL")+"") + " "+1*xGetInt(dPlayerData, xFuelTank)+" L");
						trChatSend(0, "<u><color=1,1,1>Upgraded Fuel:</color></u>");
						trChatSend(0, FuelUp + " "+1*trQuestVarGet("FuelCL"+1*trQuestVarGet("NextFuelL")+"")+" L");
					}
					else if(xGetInt(dPlayerData, xGold) >= 1*trQuestVarGet("goldCost")){
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
					trChatHistoryClear();
					trChatSend(0, "<u><color=1,1,1>Current Cargo Hold:</color></u>");
					trChatSend(0, trStringQuestVarGet("CargoL"+1*trQuestVarGet("CurrentCargoL")+"") + " "+1*xGetInt(dPlayerData, xCargoHold)+" minerals");
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
					if(xGetInt(dPlayerData, xGold) < 1*trQuestVarGet("goldCost")){
						uiMessageBox("You do not have enough gold to upgrade your cargo hold! (" + 1*trQuestVarGet("goldCost") + ")");
						dialog = 0;
						trChatHistoryClear();
						trChatSend(0, "<u><color=1,1,1>Current cargo hold:</color></u>");
						trChatSend(0, trStringQuestVarGet("CargoL"+1*trQuestVarGet("CurrentCargoL")+"") + " "+1*xGetInt(dPlayerData, xCargoHold)+" minerals");
						trChatSend(0, "<u><color=1,1,1>Upgraded cargo hold:</color></u>");
						trChatSend(0, CargoUp + " "+1*trQuestVarGet("CargoCL"+1*trQuestVarGet("NextCargoL")+"")+" minerals");
					}
					else if(xGetInt(dPlayerData, xGold) >= 1*trQuestVarGet("goldCost")){
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
					trChatHistoryClear();
					trChatSend(0, "<u><color=1,1,1>Current Engine:</color></u>");
					trChatSend(0, trStringQuestVarGet("EngineL"+1*trQuestVarGet("CurrentEngineL")+"") + " "+1*xGetInt(dPlayerData, xEnginePower)+" kW");
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
					if(xGetInt(dPlayerData, xGold) < 1*trQuestVarGet("goldCost")){
						uiMessageBox("You do not have enough gold to upgrade your engine! (" + 1*trQuestVarGet("goldCost") + ")");
						dialog = 0;
						trChatHistoryClear();
						trChatSend(0, "<u><color=1,1,1>Current Engine:</color></u>");
						trChatSend(0, trStringQuestVarGet("EngineL"+1*trQuestVarGet("CurrentEngineL")+"") + " "+1*xGetInt(dPlayerData, xEnginePower)+" kW");
						trChatSend(0, "<u><color=1,1,1>Upgraded Engine:</color></u>");
						trChatSend(0, EngineUp + " "+1*trQuestVarGet("EngineCL"+1*trQuestVarGet("NextEngineL")+"")+" kW");
					}
					else if(xGetInt(dPlayerData, xGold) >= 1*trQuestVarGet("goldCost")){
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
					trChatHistoryClear();
					trChatSend(0, "<u><color=1,1,1>Current Radiator:</color></u>");
					trChatSend(0, trStringQuestVarGet("RadiatorL"+1*trQuestVarGet("CurrentRadiatorL")+"") + " "+1*xGetInt(dPlayerData, xRadiator)+" percent");
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
					if(xGetInt(dPlayerData, xGold) < 1*trQuestVarGet("goldCost")){
						uiMessageBox("You do not have enough gold to upgrade your Radiator! (" + 1*trQuestVarGet("goldCost") + ")");
						dialog = 0;
						trChatHistoryClear();
						trChatSend(0, "<u><color=1,1,1>Current Radiator:</color></u>");
						trChatSend(0, trStringQuestVarGet("RadiatorL"+1*trQuestVarGet("CurrentRadiatorL")+"") + " "+1*xGetInt(dPlayerData, xRadiator)+" percent efficient");
						trChatSend(0, "<u><color=1,1,1>Upgraded Radiator:</color></u>");
						trChatSend(0, RadiatorUp + " "+1*trQuestVarGet("RadiatorCL"+1*trQuestVarGet("NextRadiatorL")+"")+" percent efficient");
					}
					else if(xGetInt(dPlayerData, xGold) >= 1*trQuestVarGet("goldCost")){
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
		case 701:
		{
			switch(dialog)
			{
				case 1:
				{
					uiMessageBox("Allows you to hold +1 extra mineral.");
				}
				case 2:
				{
					trShowChoiceDialog("Equip?",
						"Yes", 23, "No", -1);
					dialog = 0;
				}
			}
		}
		case 702:
		{
			switch(dialog)
			{
				case 1:
				{
					uiMessageBox("Allows you to hold +100L extra fuel.");
				}
				case 2:
				{
					trShowChoiceDialog("Equip?",
						"Yes", 24, "No", -1);
					dialog = 0;
				}
			}
		}
		case 703:
		{
			switch(dialog)
			{
				case 1:
				{
					uiMessageBox("Gives you +10 drilling power.");
				}
				case 2:
				{
					trShowChoiceDialog("Equip?",
						"Yes", 25, "No", -1);
					dialog = 0;
				}
			}
		}
		case 704:
		{
			switch(dialog)
			{
				case 1:
				{
					uiMessageBox("Gives you +4 percent radiator efficiency.");
				}
				case 2:
				{
					trShowChoiceDialog("Equip?",
						"Yes", 26, "No", -1);
					dialog = 0;
				}
			}
		}
		case 705:
		{
			switch(dialog)
			{
				case 1:
				{
					uiMessageBox("Gives you +15 engine power.");
				}
				case 2:
				{
					trShowChoiceDialog("Equip?",
						"Yes", 27, "No", -1);
					dialog = 0;
				}
			}
		}
		case 706:
		{
			switch(dialog)
			{
				case 1:
				{
					uiMessageBox("Gives you +250 hull hp.");
				}
				case 2:
				{
					trShowChoiceDialog("Equip?",
						"Yes", 28, "No", -1);
					dialog = 0;
				}
			}
		}
		case 707:
		{
			switch(dialog)
			{
				case 1:
				{
					uiMessageBox("Gives you a free emergency fuel tank at the start of every multiplayer game.");
				}
				case 2:
				{
					trShowChoiceDialog("Equip?", "Yes", 29, "No", -1);
					dialog = 0;
				}
			}
		}
		case 708:
		{
			switch(dialog)
			{
				case 1:
				{
					uiMessageBox("Automatically sells any held minerals when the stage ends.");
				}
				case 2:
				{
					trShowChoiceDialog("Equip?", "Yes", 30, "No", -1);
					dialog = 0;
				}
			}
		}
		case 709:
		{
			switch(dialog)
			{
				case 1:
				{
					uiMessageBox("Nullifies the first two instances of damage you take.");
				}
				case 2:
				{
					trShowChoiceDialog("Equip?", "Yes", 31, "No", -1);
					dialog = 0;
				}
			}
		}
		case 710:
		{
			switch(dialog)
			{
				case 1:
				{
					uiMessageBox("Alerts you if gas pockets are nearby.");
				}
				case 2:
				{
					trShowChoiceDialog("Equip?", "Yes", 32, "No", -1);
					dialog = 0;
				}
			}
		}
		case 711:
		{
			switch(dialog)
			{
				case 1:
				{
					uiMessageBox("Adds 30 seconds to every stage you play.");
				}
				case 2:
				{
					trShowChoiceDialog("Equip?", "Yes", 33, "No", -1);
					dialog = 0;
				}
			}
		}
		case 712:
		{
			switch(dialog)
			{
				case 1:
				{
					uiMessageBox("Your first mineral sale on each stage yields an extra 25 percent profit.");
				}
				case 2:
				{
					trShowChoiceDialog("Equip?", "Yes", 34, "No", -1);
					dialog = 0;
				}
			}
		}
		case 713:
		{
			switch(dialog)
			{
				case 1:
				{
					uiMessageBox("Gives your ship an additional 5 speed when on a planet.");
				}
				case 2:
				{
					trShowChoiceDialog("Equip?", "Yes", 35, "No", -1);
					dialog = 0;
				}
			}
		}
		case 714:
		{
			switch(dialog)
			{
				case 1:
				{
					uiMessageBox("Grants one use of an extremely powerful directional mining laser each round.");
				}
				case 2:
				{
					trShowChoiceDialog("Equip?", "Yes", 36, "No", -1);
					dialog = 0;
				}
			}
		}
		case 715:
		{
			switch(dialog)
			{
				case 1:
				{
					uiMessageBox("Grants one use of an extremely powerful antimatter bomb each round.");
				}
				case 2:
				{
					trShowChoiceDialog("Equip?", "Yes", 37, "No", -1);
					dialog = 0;
				}
			}
		}
		case 716:
		{
			switch(dialog)
			{
				case 1:
				{
					uiMessageBox("Allows you to hold +1000L extra fuel.");
				}
				case 2:
				{
					trShowChoiceDialog("Equip?", "Yes", 38, "No", -1);
					dialog = 0;
				}
			}
		}
		case 717:
		{
			switch(dialog)
			{
				case 1:
				{
					uiMessageBox("Lava resist - lava deals 100 less damage.");
				}
				case 2:
				{
					trShowChoiceDialog("Equip?", "Yes", 39, "No", -1);
					dialog = 0;
				}
			}
		}
		case 718:
		{
			switch(dialog)
			{
				case 1:
				{
					uiMessageBox("Radioactive minerals damage halved.");
				}
				case 2:
				{
					trShowChoiceDialog("Equip?", "Yes", 40, "No", -1);
					dialog = 0;
				}
			}
		}
		case 719:
		{
			switch(dialog)
			{
				case 1:
				{
					uiMessageBox("Grants +100 drill power.");
				}
				case 2:
				{
					trShowChoiceDialog("Equip?", "Yes", 41, "No", -1);
					dialog = 0;
				}
			}
		}
		case 720:
		{
			switch(dialog)
			{
				case 1:
				{
					uiMessageBox("Gives you +1500 hull hp.");
				}
				case 2:
				{
					trShowChoiceDialog("Equip?", "Yes", 42, "No", -1);
					dialog = 0;
				}
			}
		}
		case 721:
		{
			switch(dialog)
			{
				case 1:
				{
					uiMessageBox("Reality drill - Allows you to drill at max speed for 30 seconds.");
				}
				case 2:
				{
					trShowChoiceDialog("Equip?", "Yes", 43, "No", -1);
					dialog = 0;
				}
			}
		}
		case 730:
		{
			switch(dialog)
			{
				case 1:
				{
					uiMessageBox("To unlock - ??????????????????????? Check back later");
					dialog = 0;
				}
			}
		}
		case 731:
		{
			switch(dialog)
			{
				case 1:
				{
					uiMessageBox("To unlock - Subscribe to this map on the Steam Workshop!");
					dialog = 0;
				}
			}
		}
		case 732:
		{
			switch(dialog)
			{
				case 1:
				{
					uiMessageBox("To unlock - Watch the introduction cinematic!");
				}
				case 2:
				{
					trShowChoiceDialog("Watch introduction cinematic now?", "Yes", 15, "No", 16);
					dialog = 0;
				}
			}
		}
		case 733:
		{
			switch(dialog)
			{
				case 1:
				{
					uiMessageBox("To unlock - Drill into egyptian cliff terrain");
					dialog = 0;
				}
			}
		}
		case 734:
		{
			switch(dialog)
			{
				case 1:
				{
					uiMessageBox("To unlock - Reach 750m depth");
					dialog = 0;
				}
			}
		}
		case 735:
		{
			switch(dialog)
			{
				case 1:
				{
					uiMessageBox("To unlock - Reach 1.5km depth");
					dialog = 0;
				}
			}
		}
		case 736:
		{
			switch(dialog)
			{
				case 1:
				{
					uiMessageBox("To unlock - Sell a uranium mineral");
					dialog = 0;
				}
			}
		}
		case 737:
		{
			switch(dialog)
			{
				case 1:
				{
					uiMessageBox("To unlock - Empty your fuel tank");
					dialog = 0;
				}
			}
		}
		case 738:
		{
			switch(dialog)
			{
				case 1:
				{
					uiMessageBox("To unlock - End a stage holding over 100 gold worth of minerals");
					dialog = 0;
				}
			}
		}
		case 739:
		{
			switch(dialog)
			{
				case 1:
				{
					uiMessageBox("To unlock - Destroy your ship");
					dialog = 0;
				}
			}
		}
		case 740:
		{
			switch(dialog)
			{
				case 1:
				{
					uiMessageBox("To unlock - Hit 5 gas pockets in the same stage");
					dialog = 0;
				}
			}
		}
		case 741:
		{
			switch(dialog)
			{
				case 1:
				{
					uiMessageBox("To unlock - Upgrade any ship component to level 3");
					dialog = 0;
				}
			}
		}
		case 742:
		{
			switch(dialog)
			{
				case 1:
				{
					uiMessageBox("To unlock - Make over 100 gold in a single sale");
					dialog = 0;
				}
			}
		}
		case 743:
		{
			switch(dialog)
			{
				case 1:
				{
					uiMessageBox("To unlock - Make exactly 47 gold in a single sale");
					dialog = 0;
				}
			}
		}
		case 744:
		{
			switch(dialog)
			{
				case 1:
				{
					uiMessageBox("To unlock - Upgrade any ship component to level 8");
					dialog = 0;
				}
			}
		}
		case 745:
		{
			switch(dialog)
			{
				case 1:
				{
					uiMessageBox("To unlock - Mine an entire planet");
					dialog = 0;
				}
			}
		}
		case 746:
		{
			switch(dialog)
			{
				case 1:
				{
					uiMessageBox("To unlock - spend " + FuelSpendForBonus + " on fuel. Current = " + xGetInt(dPlayerData, xFuelSpend));
					dialog = 0;
				}
			}
		}
		case 747:
		{
			switch(dialog)
			{
				case 1:
				{
					uiMessageBox("To unlock - drill out 10 lava pockets on Thule");
					dialog = 0;
				}
			}
		}
		case 748:
		{
			switch(dialog)
			{
				case 1:
				{
					uiMessageBox("To unlock - sell " + RadiationBonus + " radioactives. Current = " + xGetInt(dPlayerData, xRadioactivesSold));
					dialog = 0;
				}
			}
		}
		case 749:
		{
			switch(dialog)
			{
				case 1:
				{
					uiMessageBox("To unlock - drill " + SeaIceDrill + " super hard terrains. Current = " + xGetInt(dPlayerData, xIceDrill));
					dialog = 0;
				}
			}
		}
		case 750:
		{
			switch(dialog)
			{
				case 1:
				{
					uiMessageBox("To unlock - spend " + HullSpendForBonus + " on hull repair. Current = " + xGetInt(dPlayerData, xHullSpend));
					dialog = 0;
				}
			}
		}
		case 751:
		{
			switch(dialog)
			{
				case 1:
				{
					uiMessageBox("To unlock - Collect all minerals on Mr. Natas' Ship");
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
