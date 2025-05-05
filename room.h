#pragma once  
#ifndef room_H  
#define room_H
#include"header.h"




class room {
public:

	vector<ALLEGRO_BITMAP*> tiles;

};




class player {
public:
	ALLEGRO_BITMAP* sprite;
	int px, py, pw, ph;
	player();

};

class enemy {
public:
	int px, py, pw, ph;
	enemy();
	ALLEGRO_BITMAP* sprite;
};

class treasure {
public:

	int px, py, pw, ph;
	treasure();
	ALLEGRO_BITMAP* sprite;

};


#endif