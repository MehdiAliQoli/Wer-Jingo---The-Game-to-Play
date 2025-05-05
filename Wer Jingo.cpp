#include <iostream>
#include<fstream>
#include<sstream>
#include<vector>
#include <string>

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>

#include "WerJingo.h"




using namespace std;


int main() {
    
    if (!al_init()) {
        std::cerr << "al_init() failed\n";
        return -1;
    }

    if (!al_init_image_addon()) {
        cerr << "Failed to initialize al_init_image_addon!" << endl;
        return -1;
    }

    if (!al_init_primitives_addon()) {
        std::cerr << "al_init_primitives_addon() failed\n";
        return -1;
    }

    vector<string> tiles1 = {
    "Tiles/IndustrialTile_01.png",  "Tiles/IndustrialTile_02.png",  "Tiles/IndustrialTile_03.png",    "Tiles/IndustrialTile_04.png",  "Tiles/IndustrialTile_05.png",  "Tiles/IndustrialTile_06.png",
    "Tiles/IndustrialTile_07.png",  "Tiles/IndustrialTile_08.png",  "Tiles/IndustrialTile_09.png",    "Tiles/IndustrialTile_10.png",  "Tiles/IndustrialTile_11.png",  "Tiles/IndustrialTile_12.png",
    "Tiles/IndustrialTile_13.png",  "Tiles/IndustrialTile_14.png",  "Tiles/IndustrialTile_15.png",    "Tiles/IndustrialTile_16.png",  "Tiles/IndustrialTile_17.png",  "Tiles/IndustrialTile_18.png",
    "Tiles/IndustrialTile_19.png",  "Tiles/IndustrialTile_20.png",  "Tiles/IndustrialTile_21.png",    "Tiles/IndustrialTile_22.png",  "Tiles/IndustrialTile_23.png",  "Tiles/IndustrialTile_24.png",
    "Tiles/IndustrialTile_25.png",  "Tiles/IndustrialTile_26.png",  "Tiles/IndustrialTile_27.png",    "Tiles/IndustrialTile_28.png",  "Tiles/IndustrialTile_29.png",  "Tiles/IndustrialTile_30.png",
    "Tiles/IndustrialTile_31.png",  "Tiles/IndustrialTile_32.png",  "Tiles/IndustrialTile_33.png",    "Tiles/IndustrialTile_34.png",  "Tiles/IndustrialTile_35.png",  "Tiles/IndustrialTile_36.png",
    "Tiles/IndustrialTile_37.png",  "Tiles/IndustrialTile_38.png",  "Tiles/IndustrialTile_39.png",    "Tiles/IndustrialTile_40.png",  "Tiles/IndustrialTile_41.png",  "Tiles/IndustrialTile_42.png",
    "Tiles/IndustrialTile_43.png",  "Tiles/IndustrialTile_44.png",  "Tiles/IndustrialTile_45.png",    "Tiles/IndustrialTile_46.png",  "Tiles/IndustrialTile_47.png",  "Tiles/IndustrialTile_48.png",
    "Tiles/IndustrialTile_49.png",  "Tiles/IndustrialTile_50.png",  "Tiles/IndustrialTile_51.png",    "Tiles/IndustrialTile_52.png",  "Tiles/IndustrialTile_53.png",  "Tiles/IndustrialTile_54.png",
    "Tiles/IndustrialTile_55.png",  "Tiles/IndustrialTile_56.png",  "Tiles/IndustrialTile_57.png",    "Tiles/IndustrialTile_58.png",  "Tiles/IndustrialTile_59.png",  "Tiles/IndustrialTile_60.png",
    "Tiles/IndustrialTile_61.png",  "Tiles/IndustrialTile_62.png",  "Tiles/IndustrialTile_63.png",    "Tiles/IndustrialTile_64.png",  "Tiles/IndustrialTile_65.png",  "Tiles/IndustrialTile_66.png",
    "Tiles/IndustrialTile_67.png",  "Tiles/IndustrialTile_68.png",  "Tiles/IndustrialTile_69.png",    "Tiles/IndustrialTile_70.png",  "Tiles/IndustrialTile_71.png",  "Tiles/IndustrialTile_72.png",
    "Tiles/IndustrialTile_73.png",  "Tiles/IndustrialTile_74.png",  "Tiles/IndustrialTile_75.png",    "Tiles/IndustrialTile_76.png",  "Tiles/IndustrialTile_77.png",  "Tiles/IndustrialTile_78.png",
    "Tiles/IndustrialTile_79.png",  "Tiles/IndustrialTile_80.png",  "Tiles/IndustrialTile_81.png",    "Tiles/IndustrialTile_82.png",  "Tiles/IndustrialTile_83.png",  "Tiles/IndustrialTile_84.png",
    "Tiles/IndustrialTile_85.png",  "Tiles/IndustrialTile_86.png",  "Tiles/IndustrialTile_87.png",    "Tiles/IndustrialTile_88.png",  "Tiles/IndustrialTile_89.png",  "Tiles/IndustrialTile_90.png",
    "Tiles/IndustrialTile_91.png",  "Tiles/IndustrialTile_92.png",  "Tiles/IndustrialTile_93.png",    "Tiles/IndustrialTile_94.png",  "Tiles/IndustrialTile_95.png",  "Tiles/IndustrialTile_96.png",
    "Tiles/IndustrialTile_97.png",  "Tiles/IndustrialTile_98.png",  "Tiles/IndustrialTile_99.png"
    };

	string e1[3] = { "Livings/1skel_walk.png", "Livings/1skel_att.png", "Livings/1skel_dead.png" };
	string e2[3] = { "Livings/2skel_walk.png", "Livings/2skel_att.png", "Livings/2skel_dead.png" };
	string e3[3] = { "Livings/min_walk.png", "Livings/min_att.png", "Livings/min_dead.png" };
    string e4_1[3] = { "Livings/wizz_walk.png", "Livings/wiz_att1.png", "Livings/wizz_dead.png" };
    string e4_charge = "Livings/wizz_charge.png";
    string e4_a2 = "Livings/wiz_spell1.png";
    string e5_1[3] = { "Livings/1yok_walk.png", "Livings/1yok_att1.png", "Livings/1yok_dead.png" };
	string e5_1_charge = "Livings/1yok_charge.png";
	string e5_1_a2 = "Livings/1yok_att2.png";
	string e5_2[3] = { "Livings/2yok_walk.png", "Livings/2yok_att1.png", "Livings/2yok_dead.png" };
	string e5_2_charge = "Livings/2yok_fire.png";
	string e5_2_a2 = "Livings/2yok_att2.png";
	string e5_3[3] = { "Livings/3yok_walk.png", "Livings/3yok_a1.png", "Livings/3yok_dead.png" };
	string e5_3_charge = "Livings/3yok_charge.png";
	string e5_3_a2 = "Livings/3yok_att2.png";
	string eb[3] = { "Livings/b_walk.png", "Livings/b_att1.png", "Livings/b_dead.png" };
	string eb_charge = "Livings/b_charge.png";
	string eb_a2 = "Livings/b_att2.png";
	string eb_run = "Livings/b_run.png";
	string efb[3] = { "Livings/fb_walk.png", "Livings/fb_att1.png", "Livings/fb_dead.png" };
	string efb_charge = "Livings/fb_arrow.png";
	string efb_a2 = "Livings/fb_att2.png";
	string efb_run = "Livings/fb_run.png";
	string efb_shot = "Livings/fb_shot.png";

    
    
	vector<treasure*> treas1;
    string csv1 = "lvl1..csv";
    std::vector<enemy*> enemies;

    treas1.push_back(new treasure(12800, 1856, 100, 100, "coins.png"));
    treas1.push_back(new treasure(12960, 2526, 100, 100, "coins.png"));
    treas1.push_back(new treasure(3616,  1216, 100, 100, "coins.png"));

    enemies.push_back(new enemy(true,      2176,  2432,   128, 128, 40, 2, 25, 1, e1)); 
    enemies.push_back(new enemy(true,      3712,  2336,   128, 128, 45, 3, 35, 2, e2)); 
    enemies.push_back(new enemy(true,      4992,  2240,   128, 128, 50, 3, 35, 2, e2)); 
    enemies.push_back(new enemy(true,      9408,  2496,   128, 128, 60, 6, 40, 3, e3)); 
    enemies.push_back(new enemy(true,      10720, 2464,   128, 128, 60, 6, 40, 3, e3));
    enemies.push_back(new enemy(true,      11488, 2432,   128, 128, 60, 6, 40, 3, e3));
    enemies.push_back(new enemy(true,      12448, 2464,   128, 128, 50, 3, 35, 2, e2));
    enemies.push_back(new enemy(true,      10400, 1504,   128, 128, 80, 5, 40, 3, e3));
    enemies.push_back(new enemy(true,      11040, 1504,   128, 128, 50, 4, 35, 2, e2));
    enemies.push_back(new enemy(true,      11872, 1600,   128, 128, 90, 7, 40, 3, e3));
    enemies.push_back(new highenemy(false, 14144, 800,    128, 128, 270, 8, 40, 90, 4, e4_1, e4_a2, e4_charge)); 
    enemies.push_back(new highenemy(false, 12576, 800,    128, 128, 280, 9, 40, 90, 4, e4_1, e4_a2, e4_charge)); 
    enemies.push_back(new highenemy(false, 8064,  1376,   128, 128, 400, 9, 35, 90, 5, e5_1, e5_1_a2, e5_1_charge)); 
    enemies.push_back(new highenemy(false, 4384,  1152,   128, 128, 450, 18, 35, 90, 5, e5_2, e5_2_a2, e5_2_charge)); 
    enemies.push_back(new highenemy(false, 11712, 288,    128, 128, 400, 12, 35, 90, 5, e5_3, e5_3_a2, e5_3_charge)); 

    enemies.push_back(new boss(false, 4864, 384, 128, 128, 600, 15, 45, 90, 8, eb, eb_a2, eb_charge, eb_run)); 

    fb fb1(false, 1200, 512, 256, 256, 1000, 17, 96, 500, 10, efb, efb_a2, efb_charge, efb_run, efb_shot); 



    room r1(1880/2-100, 992/2-200, tiles1, enemies, treas1, csv1);


	screen1(r1, fb1);

	return 0;
}
