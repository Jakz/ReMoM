
/*

    MoO2
        Module: NEWGAME
            Newgame_Screen_
                Address: 01:000CD435
            Reload_Newgame_Screen_
                Address: 01:000CCA1C
            Draw_Newgame_Screen_
                Address: 01:000CCD3C
            Draw_Pictures_
                Address: 01:000CCC3D
            Add_Fields_
                Address: 01:000CCE2E
            Update_Fields_
                Address: 01:000CCE24
            data (0 bytes) _fields
                Address: 02:0019933C
            data (0 bytes) _background_seg
                Address: 02:00199354

        Module: MAPGEN
    
Reload_Newgame_Screen_
is where the loading happens
i.e., (Re-)Load

*/
/*

terrain_stats_table
770 records
6 bytes
half movement cost per movement type
0 unknwon
1 walking
2 Forster
3 Mountaineer
4 Swimming
5 Sailing
But, also, why 770? world_map terrain_type offset is 762 ?

*/

/*
Load_TERRSTAT()
terrain_stats_table = SA_MK_FP0( LBXR_LoadSingle("TERRSTAT", 0, 0, 770, 6) )

    XREF NEWG_SetMoveMaps+61  les     si, [terrain_stats_table]
    XREF NEWG_SetMoveMaps+94  les     si, [terrain_stats_table]
    XREF NEWG_SetMoveMaps+C4  les     si, [terrain_stats_table]
    XREF NEWG_SetMoveMaps+F7  les     si, [terrain_stats_table]
    XREF NEWG_SetMoveMaps+12A les     si, [terrain_stats_table]
    XREF NEWG_SetMoveMaps+15D les     si, [terrain_stats_table]
*/

/*
Load_SPELLDAT()
spell_data_table    = SA_MK_FP0( LBXR_LoadSingle("SPELLDAT", 0, 0, 215, 36) )

*/

#include "NewGame.h"

#include "MoX.H"

#include "Graphics.H"
#include "Video.H"
#include "MainMenu.H"


// MGC dseg:309C
char cnst_Set_File4[] = "MAGIC.SET";

// MGC dseg:8e68
SAMB_ptr IMG_NewG_RgtOverlay;
// MGC dseg:5cb0
SAMB_ptr newgame_ok_button;
// MGC dseg:8e8e
SAMB_ptr _quit_active_seg;
// MGC dseg:8e4a
SAMB_ptr IMG_NewG_ButtonBG[4];

char* cnst_Diff0_Text = "Intro";
char* cnst_Diff1_Text = "Normal";
char* cnst_Diff2_Text = "Hard";
char* cnst_Diff3_Text = "Impossible";

// in dseg they are all 11 bytes long
char* cnst_Diff_Texts[] = { "Intro", "Normal", "Hard", "Impossible" };

int16_t _ok_button;
// MGC dseg:52c0
int16_t _quit_button;
int16_t newgame_difficulty_button_field;
int16_t newgame_opponents_button_field;
int16_t newgame_landsize_button_field;
int16_t newgame_magic_button_field;

struct s_mouse_list mouse_list_newgame[1] = {
    {crsr_Finger, 0, 0, 0, SCREEN_XMAX, SCREEN_YMAX}
};

//TODO use: dseg:28d0
// MGC dseg:3059
char cnst_HOTKEY_Esc3 = '\x1b';


int New_Game_Screen()
{
  int16_t first_draw_done_flag;
  int16_t finished_flag;
  int16_t input_field_idx; // _SI_
  int16_t screen_change = ST_FALSE;
  
  Fade_Out();
  Fill(SCREEN_XMIN, SCREEN_YMIN, SCREEN_XMAX, SCREEN_YMAX, 0);
  Set_Page_On();
  Fill(SCREEN_XMIN, SCREEN_YMIN, SCREEN_XMAX, SCREEN_YMAX, 0);
  Set_Page_Off();
  Load_Palette(0, -1, 0);

  mainmenu_background_seg = LBX_Reload("NEWGAME", 0, _screen_seg);
  IMG_NewG_RgtOverlay = LBX_Reload_Next("NEWGAME", 1, _screen_seg);
  newgame_ok_button = LBX_Reload_Next("NEWGAME", 2, _screen_seg);
  _quit_active_seg = LBX_Reload_Next("NEWGAME", 3, _screen_seg);

  for (int i = 0; i < 4; ++i)
    IMG_NewG_ButtonBG[i] = LBX_Reload_Next("NEWGAME", 4 + 1, _screen_seg);

  //DIR(cnst_Set_File4, Read_Buffer);
  /* TODO: load MAGIC.SET */
  Set_Default_Game_Settings();
  
  // ovr050:0923
  if (magic_set.Difficulty < 0 || magic_set.Difficulty > 4)
    magic_set.Difficulty = 0;
  if (magic_set.Opponents < 1 || magic_set.Opponents > 4)
    magic_set.Opponents = 1;
  if (magic_set.LandSize < 0 || magic_set.Opponents > 2)
    magic_set.LandSize = 0;
  if (magic_set.MagicPower < 0 || magic_set.MagicPower > 2)
    magic_set.MagicPower = 0;
  
  Set_Mouse_List(1, mouse_list_newgame);
  Clear_Fields();
  Set_Page_On();
  Fill(0, 0, 319, 199, 0);
  Set_Page_Off();
  Fill(0, 0, 319, 199, 0);
  _ok_button = Add_Button_Field(252, 179, "", newgame_ok_button, "", ST_UNDEFINED);
  _quit_button = Add_Button_Field(171, 179, "", _quit_active_seg, cnst_HOTKEY_Esc3, ST_UNDEFINED);
  
  newgame_difficulty_button_field = Add_Hidden_Field(250, 38, 315, 43, "", -1);
  newgame_opponents_button_field = Add_Hidden_Field(250, 65, 315, 81, "", -1);
  newgame_landsize_button_field = Add_Hidden_Field(250, 92, 315, 108, "", -1);
  newgame_magic_button_field = Add_Hidden_Field(250, 119, 315, 135, "", -1);

  first_draw_done_flag = ST_FALSE;
  finished_flag = ST_FALSE;

  New_Game_Screen_Draw();

  Assign_Auto_Function(New_Game_Screen_Draw, 1);

  // HLP_Load_NewGOptions

  while (finished_flag == ST_FALSE)
  {
    input_field_idx = Get_Input();
    Mark_Time();

    if (input_field_idx == _quit_button)
    {
      Deactivate_Auto_Function();
      Deactivate_Help_List();
      return -1;
    }
    else if (input_field_idx == _ok_button)
    {

    }
    else if (input_field_idx == newgame_difficulty_button_field)
    {
      ++magic_set.Difficulty;
      if (magic_set.Difficulty > 4)
        magic_set.Difficulty = 0;
    }

    if (finished_flag == ST_FALSE)
    {
      New_Game_Screen_Draw();
      Toggle_Pages();

      // do a full draw - initial or on-change
      if ((screen_change != ST_FALSE) || (first_draw_done_flag == ST_FALSE))
      {
        //Copy_Off_To_On_Page();
        Fade_In();
        first_draw_done_flag = ST_TRUE;
      }
      Release_Time(2);
    }
  }
}

int New_Game_Screen_Draw()
{
  char Opponents_Texts[8];
  char Magic_Texts[9];
  char LandSize_Texts[7];
  char Difficulty_Texts[55]; // 4 difficulties * 11 bytes
  uint8_t Color_Array_2[4] = { 0xbb, 0xbb, 0xbb, 0xbb };
  uint8_t Color_Array_1[4] = { 0x1f, 0x1f, 0x1f, 0x1f };

 

  memcpy(Difficulty_Texts, cnst_Diff0_Text, strlen(cnst_Diff0_Text));
  
  // background
  FLIC_Draw(0, 0, mainmenu_background_seg);
  
  // buttons background
  Fill(250, 38, 315, 54, 0);
  Fill(250, 65, 315, 82, 0);
  Fill(250, 92, 315, 107, 0);
  Fill(250, 119, 315, 134, 0);
  Fill(251, 178, 315, 193, 0);
  Fill(170, 178, 234, 193, 0);
  
  FLIC_Draw(165, 0, IMG_NewG_RgtOverlay);

  // AKA Get_Mouse_Field()
  current_menu_screen = Auto_Input();

  Set_Font_Style(3, 15, 0, 0);
  
  if (current_menu_screen != newgame_difficulty_button_field)
    FLIC_Draw(251, 39, IMG_NewG_ButtonBG[0]);
  else
    FLIC_Draw(252, 40, IMG_NewG_ButtonBG[0]);

  Set_Font_Colors_15(3, Color_Array_1);
  Print_Centered(283, 43, "Intro");
  Set_Font_Colors_15(3, Color_Array_2);
  Print_Centered(282, 42, "Intro");
}