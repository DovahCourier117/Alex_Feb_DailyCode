#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>

enum KEYS {UP, DOWN, LEFT, RIGHT};

int main(void) {//start main

	bool done = false;//variable for game loop
	int count = 0;

	int width = 1824;//size of screen
	int height = 1026;

	int player_width;//size of player
	int player_height;

	float pos_x = width /2;
	float pos_y = height -50;
	

	bool keys[4] = {false, false, false, false};

	ALLEGRO_DISPLAY* display = NULL;
	ALLEGRO_EVENT_QUEUE*event_queue = NULL;

	if (!al_init())//initialize allegro
		return -1;

	display = al_create_display(width, height);//create display
	

	if (!display)//test display
		return -1;

	al_init_primitives_addon();//initializes allegro graphics library

	al_install_keyboard();//allows keyboard input

	event_queue = al_create_event_queue();

	al_register_event_source(event_queue, al_get_keyboard_event_source());
	al_register_event_source(event_queue, al_get_display_event_source(display));

	

	while (!done) {//open game loop

		count++;




		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);


		if (ev.type == ALLEGRO_EVENT_KEY_DOWN) {//start if (controls keyboard input)

			switch (ev.keyboard.keycode) {//start switch

			//case ALLEGRO_KEY_UP:
			//	keys[UP] = true;
			//	break;

			//case ALLEGRO_KEY_DOWN:
			//	keys[DOWN] = true;
			//	break;

			case ALLEGRO_KEY_LEFT:
				keys[LEFT] = true;
				break;

			case ALLEGRO_KEY_RIGHT:
				keys[RIGHT] = true;
				break;

			case ALLEGRO_KEY_ESCAPE://close game
				done = true;
				break;

			}//end switch



		}//end if (keyboard input)

		else if (ev.type == ALLEGRO_EVENT_KEY_UP) {//makes it so input is deactivated after lifting key

			switch (ev.keyboard.keycode) {//start switch

			//case ALLEGRO_KEY_UP:
			//	keys[UP] = false;
			//	break;

			//case ALLEGRO_KEY_DOWN:
			//	keys[DOWN] = false;
			//	break;

			case ALLEGRO_KEY_LEFT:
				keys[LEFT] = false;
				break;

			case ALLEGRO_KEY_RIGHT:
				keys[RIGHT] = false;
				break;

			}
		}

		else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {//allows closure via red 'x' in corner 
			done = true; 
		}

		float speed = 10;//dictates speed of player

		//dictates game borders and links input to movement
		if (pos_y >= 10) {
			pos_y -= keys[UP] * speed;
		}
		if (pos_y <= (height-10)) {
			pos_y += keys[DOWN] * speed;
		}
		if (pos_x >= 10) {
			pos_x -= keys[LEFT] * speed;
		}
		if (pos_x <= (width-25)) {
			pos_x += keys[RIGHT] * speed;
		}




		al_draw_filled_rectangle(pos_x, pos_y, pos_x+50, pos_y+30, al_map_rgb(100, 100, 100));//draw player

		al_flip_display();

		al_clear_to_color(al_map_rgb(0, 0, 0));
	}//close game loop


	al_destroy_display(display);//destroy display

	return 0;
}//end main	