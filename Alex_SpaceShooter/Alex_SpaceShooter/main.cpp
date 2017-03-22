#include <iostream>

#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <list>

#include "GameObject.h"
#include "SpaceShip.h"
#include "Globals.h"

using namespace std;

bool keys[] = { false,false,false,false,false };
enum KEYS { UP, DOWN, LEFT, RIGHT, SPACE };



//Globals
SpaceShip* ship;

list<GameObject *> objects;
list<GameObject *>::iterator iter;
list<GameObject *>::iterator iter2;



int main() {//start main

	//shell variables
	bool done = false;
	bool render = false;

	float gametime = 0;
	int frames = 0;
	int gameFPS = 0;

	//project variables
	ship = new SpaceShip();


	ALLEGRO_BITMAP *shipImage = NULL;

	//allegro variables
	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_EVENT_QUEUE*event_queue = NULL;
	ALLEGRO_TIMER*timer;
	ALLEGRO_FONT*font;

	//init allegro functions
	al_init(); //initiates allegro

	display = al_create_display(WIDTH, HEIGHT);

	//addon install
	al_install_keyboard();
	al_init_image_addon();
	al_init_font_addon();
	al_init_ttf_addon();
	al_init_primitives_addon();
	al_install_audio();
	al_init_acodec_addon();

	//project init
	font = al_load_font("ariel.ttf", 18, 0);
	al_reserve_samples(18);

	shipImage = al_load_bitmap("Ship_1.png");
	al_convert_mask_to_alpha(shipImage, al_map_rgb(255, 0, 255));
	ship->Init(shipImage);

	objects.push_back(ship);

	//timer stuff
	event_queue = al_create_event_queue();
	timer = al_create_timer(1.0 / 60);
	al_register_event_source(event_queue, al_get_display_event_source(display));
	al_register_event_source(event_queue, al_get_timer_event_source(timer));
	al_register_event_source(event_queue, al_get_keyboard_event_source());
	cout << "flag" << endl;
	al_start_timer(timer);
	while (!done) {//////////////////////////////////////////////////////////////////////////////////////game loop
		cout << "flag loop" << endl;
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);


		//game update
		if (ev.type == ALLEGRO_EVENT_TIMER) {
			render = true;
			cout << "flag derp" << endl;

			//update FPS
			frames++;
			if (al_current_time() - gametime >= 1) {
				gameFPS = frames;
				frames = 0;
			}

			//moves ship
			if (keys[UP])
				ship->MoveUp();
			else if (keys[DOWN])
				ship->MoveDown();
			else if (keys[LEFT])
				ship->MoveLeft();
			else if (keys[RIGHT])
				ship->MoveRight();
			else if (keys[SPACE])
				ship->MoveRight();
			else
				ship->ResetAnimation(0);


			for (iter = objects.begin(); iter != objects.end(); ++iter)
				(*iter)->Update();


		}//end game update


		//input	e
		else if (ev.type == ALLEGRO_EVENT_KEY_DOWN) {
			switch (ev.keyboard.keycode) {
			case ALLEGRO_KEY_ESCAPE:
				done = true;
				break;
			case ALLEGRO_KEY_LEFT:
				keys[LEFT] = true;
				break;
			case ALLEGRO_KEY_RIGHT:
				keys[RIGHT] = true;
				break;
			case ALLEGRO_KEY_UP:
				keys[UP] = true;
				break;
			case ALLEGRO_KEY_DOWN:
				keys[DOWN] = true;
				break;
			case ALLEGRO_KEY_SPACE:
				keys[SPACE] = true;
				break;
			}
		}
		else if (ev.type == ALLEGRO_EVENT_KEY_UP) {
			switch (ev.keyboard.keycode) {
			case ALLEGRO_KEY_ESCAPE:
				done = false;
				break;
			case ALLEGRO_KEY_LEFT:
				keys[LEFT] = false;
				break;
			case ALLEGRO_KEY_RIGHT:
				keys[RIGHT] = false;
				break;
			case ALLEGRO_KEY_UP:
				keys[UP] = false;
				break;
			case ALLEGRO_KEY_DOWN:
				keys[DOWN] = false;
				break;
			case ALLEGRO_KEY_SPACE:
				keys[SPACE] = false;
				break;
			}
		}

		else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			break;
		}


		//render section
		if (render && al_is_event_queue_empty(event_queue)) {
			//flip buffers
			al_clear_to_color(al_map_rgb(0, 0, 0));

			for (iter = objects.begin(); iter != objects.end(); ++iter)
				(*iter)->Render();

			al_flip_display();

		}//end render section

	}//end game loop





	cout << "test" << endl;
	//destroy objects 
	for (iter = objects.begin(); iter != objects.end();) {
		(*iter)->Destroy();
		delete (*iter);
		iter = objects.erase(iter);

	}//end destroy



	return 0;
}//end main