#include<iostream>
#include<string>
#include<vector>
#include<allegro5/allegro.h>
#include<allegro5/allegro_image.h>
#include<allegro5/allegro_primitives.h>
#include<allegro5/allegro_audio.h>

#include<string>


using namespace std;

#include "WerJingo.h"

room::room(int px, int py, vector<string>& til, vector<enemy*>& enem, vector<treasure*>& treas, string csvfil) {
	this->px = px;
	this->py = py;
	this->tiles = til;
	this->enemies = enem;
	this->treasures = treas;
	this->csvfile = csvfil;
}

player::player(int x, int y, int w, int h, int heal, int att, int r, string loc[]) {
	this->x = x;
	this->y = y;
	this->w = w;
	this->h = h;
	this->health = heal;
	this->attack = att;
	this->range = r;
	this->w_sprite = al_load_bitmap(loc[0].c_str());
	this->i_sprite = al_load_bitmap(loc[1].c_str());
	this->f_sprite = al_load_bitmap(loc[2].c_str());
	this->d_sprite = al_load_bitmap(loc[3].c_str());
	this->g_sprite = al_load_bitmap(loc[4].c_str());
	this->f2_sprite = al_load_bitmap(loc[5].c_str());
	this->f3_sprite = al_load_bitmap(loc[6].c_str());

}

enemy::enemy(bool fl, int x, int y, int w, int h, int heal, int att, int r, int l, string loc[3]) {
	this->flip = fl;
	this->x = x;
	this->y = y;
	this->w = w;
	this->h = h;
	ix = x;
	iy = y;
	this->health = heal;
	h1 = health;
	this->attack = att;
	this->range = r;
	this->lvl = l;
	this->w_sprite = al_load_bitmap(loc[0].c_str());
	if (!w_sprite) {
		cout << "Eror" << endl;
	}
	this->a_sprite = al_load_bitmap(loc[1].c_str());
	if (!a_sprite) {
		cout << "Eror " << lvl << endl;
		return;
	}
	this->d_sprite = al_load_bitmap(loc[2].c_str());
	if (!d_sprite) {
		cout << "Eror" << endl;
	}
	this->current_sprite = w_sprite;
}

void enemy::draw(int cam_x, int cam_y, int velocity) {

	for (int i = 0; i < (double(health) / double(h1)) * 8; i++) {

		al_draw_filled_rectangle(x - cam_x + 16 + i * 12, y - cam_y + 16, x - cam_x + 16 + i * 12 + 12, y - cam_y + 24, al_map_rgb(255, 0, 0));
	}
	al_draw_scaled_bitmap(current_sprite, f * 128, 0, 128, 128, x - cam_x, y - cam_y + velocity, 128, 128, flip);
}
void highenemy::draw(int cam_x, int cam_y, int velocity) {

	for (int i = 0; i < (double(health) / double(h1)) * 8; i++) {

		al_draw_filled_rectangle(x - cam_x + 16 + i * 12, y - cam_y + 16, x - cam_x + 16 + i * 12 + 12, y - cam_y + 24, al_map_rgb(255, 0, 0));
	}
	al_draw_scaled_bitmap(current_sprite, f * 128, 0, 128, 128, x - cam_x, y - cam_y + velocity, 128, 128, flip);
}


treasure::treasure(int x, int y, int w, int h, string s) {
	this->x = x;
	this->y = y;
	this->w = w;
	this->h = h;
	this->sprite = al_load_bitmap(s.c_str());
}