//This paints the overworld terrain for each stage
void GroundType(int rock = 0) {
	switch(rock)
	{
		case 1:
		{
			OVERTERRAIN_TYPE = 0;
			OVERTERRAIN_SUBTYPE = 1;
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
