#include <iostream>

#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <list>

#include "Globals.h"

bool keys[] = { false,false,false,false,false };

using namespace std;

int main(void) {//start main

	//shell variables
	bool done = false;
	bool render = false;

	float gametime = 0;
	int frames = 0;
	int gameFPS = 0;

	//project variables

	//allegro variables
	ALLEGRO_DISPLAY*display = NULL;
	ALLEGRO_EVENT_QUEUE*event_queue = NULL;
	ALLEGRO_TIMER*timer;
	ALLEGRO_FONT*font;




}//end main