int TERRAIN_TYPE = 2;
int TERRAIN_SUBTYPE = 2;

void RockType(int rock = 0) {
	switch(rock)
	//1-7 sandy
	{
		case 1:
		{
			TERRAIN_TYPE = 0;
			TERRAIN_SUBTYPE = 36;
		}
		case 2:
		{
			TERRAIN_TYPE = 0;
			TERRAIN_SUBTYPE = 31;
		}
		case 3:
		{
			TERRAIN_TYPE = 0;
			TERRAIN_SUBTYPE = 39;
		}
		case 4:
		{
			TERRAIN_TYPE = 0;
			TERRAIN_SUBTYPE = 17;
		}
		case 5:
		{
			TERRAIN_TYPE = 0;
			TERRAIN_SUBTYPE = 18;
		}
		case 6:
		{
			TERRAIN_TYPE = 0;
			TERRAIN_SUBTYPE = 38;
		}
		case 7:
		{
			TERRAIN_TYPE = 2;
			TERRAIN_SUBTYPE = 2;
		}
		//Ice C
		case 8:
		{
			TERRAIN_TYPE = 5;
			TERRAIN_SUBTYPE = 2;
		}
		//Hades 7
		case 9:
		{
			TERRAIN_TYPE = 2;
			TERRAIN_SUBTYPE = 10;
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
			name = "Murkwood";
		}
		case 3:
		{
			name = "Frozen Canyon";
		}
		case 4:
		{
			name = "Emerald Fields";
		}
		case 5:
		{
			name = "Miasma Crypt";
		}
		case 6:
		{
			name = "The Factory";
		}
		case 7:
		{
			name = "The Deep";
		}
		case 8:
		{
			name = "The Clouds";
		}
		case 9:
		{
			name = "The Pit";
		}
		case 10:
		{
			name = "The Apex";
		}
	}
	return(name);
}

string stageIcon(int stage = 0) {
	string img = "icons\special e son of osiris icon 64";
	string customimg = "icons\special e son of osiris icon 64";
	switch(stage)
	{
		case 1:
		{
			img = "Yeebaagooon\Motherload\testicon";
			customimg = "ui_x_gp_indicator_on";
			//Yeebaagooon\Motherload\testicon
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
