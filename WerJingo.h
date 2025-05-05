#pragma once
#include <iostream>
#include<string>
#include<vector>

using namespace std;
#ifndef WERJINGO_H
#define WERJINGO_H







class player {
public:
	ALLEGRO_BITMAP* w_sprite; ALLEGRO_BITMAP* i_sprite; ALLEGRO_BITMAP* f_sprite; ALLEGRO_BITMAP* f2_sprite; ALLEGRO_BITMAP* f3_sprite; ALLEGRO_BITMAP* d_sprite; ALLEGRO_BITMAP* g_sprite;
	int x, y, w, h, health, attack, range, lvl=1, exp=0;
	player(int x, int y, int w, int h, int heal, int att, int r, string loc[]);

	virtual ~player () {}

};

class knight : public player {
public:
	knight(int x, int y, int w, int h, int heal, int att, int r, string loc[4]) : player(x, y, w, h, heal, att, r, loc) {};
	
	~knight(){}
};

class mage : public player {
public:
	mage(int x, int y, int w, int h, int heal, int att, int r, string loc[4]) : player(x, y, w, h, heal, att, r, loc) {};

	~mage() {}
};

class archer : public player {
public:
	archer(int x, int y, int w, int h, int heal, int att, int r, string loc[4]) : player(x, y, w, h, heal, att, r, loc) {};

	~archer() {}
};
class rogue : public player {
public:
	rogue(int x, int y, int w, int h, int heal, int att, int r, string loc[4]) : player(x, y, w, h, heal, att, r, loc) {};

	~rogue() {}
};

class enemy {
public:
	virtual void jst() {} 
	bool att = false, aggro = false, wback= false, alive = true;
	int f = 0;
	int ix, iy;
	int x, y, w, h, health, h1, attack, range, lvl;
	ALLEGRO_BITMAP* w_sprite; ALLEGRO_BITMAP* a_sprite; ALLEGRO_BITMAP* d_sprite;
	bool flip, death;
	ALLEGRO_BITMAP* current_sprite;
	enemy(bool fl, int x, int y, int w, int h, int heal, int att, int r, int l, string loc[3]);

	virtual void draw(int cam_x, int cam_y, int velocity);

	virtual ~enemy(){}
};

class highenemy : public enemy {
public:
	int range2;
	ALLEGRO_BITMAP* a2_sprite;ALLEGRO_BITMAP* charge_sprite;
	highenemy(bool flip, int x, int y, int w, int h, int heal, int att, int r, int r2, int l, string loc[3], string a2, string ch) : enemy(flip, x, y, w, h, heal, att, r, l, loc) {
		this->a2_sprite = al_load_bitmap(a2.c_str());
		this->charge_sprite = al_load_bitmap(ch.c_str());
		this->range2 = r2;
	};
	void draw(int cam_x, int cam_y, int velocity) override;

	virtual ~highenemy() {}
};

class boss : public highenemy {
public :
	ALLEGRO_BITMAP* r_sprite;
	boss(bool flip, int x, int y, int w, int h, int heal, int att, int r, int r2, int l, string loc[3], string a2, string ch, string run) : highenemy(flip, x, y, w, h, heal, att, r, r2, l, loc, a2, ch) {
		this->r_sprite = al_load_bitmap(run.c_str());
	};

	~boss() {}
};

class fb : public boss {
public:
	ALLEGRO_BITMAP* shot;
	fb(bool flip, int x, int y, int w, int h, int heal, int att, int r, int r2, int l, string loc[3], string a2, string ch, string run, string shot) : boss(flip, x, y, w, h, heal, att, r, r2, l, loc, a2, ch, run) {
		this->shot = al_load_bitmap(shot.c_str());
	}
	
};





class treasure {
public:
	bool taken = false;
	int x, y, w, h;
	ALLEGRO_BITMAP* sprite;
	treasure(int x, int y, int w, int h, string s);

};


class room {
public:

	vector<string> tiles;

	string csvfile;
	player* p;
	vector<enemy*> enemies;
	vector<treasure*> treasures;
	int px, py;

	room(int px, int py, vector<string>& til, vector<enemy*>& enem, vector<treasure*>& treas, string csvfil);


};


int screen1(room& r, fb fb1);


#endif

