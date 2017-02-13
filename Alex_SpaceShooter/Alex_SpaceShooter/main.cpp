#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>

int main() {//start main

	int width = 1824;//size of screen
	int height = 1026;

	bool done = false;//variable for game loop

	float pos_x = width / 2;
	float pos_y = height / 2;


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

	while (!done) {//open game loop
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);


		if (ev.type == ALLEGRO_EVENT_KEY_DOWN) {//start if (controls keyboard input)

			switch (ev.keyboard.keycode) {//start switch

			case ALLEGRO_KEY_UP:
				pos_y -= 10;
				break;
			case ALLEGRO_KEY_DOWN:
				pos_y += 10;
				break;
			case ALLEGRO_KEY_LEFT:
				pos_x -= 10;
				break;
			case ALLEGRO_KEY_RIGHT:
				pos_x += 10;
				break;
			case ALLEGRO_KEY_ESCAPE://close game
				done = true;
				break;
			}//end switch


		}//end if

		if (ev.type == ALLEGRO_EVENT_KEY_UP) {//open if

			if(ev.keyboard.keycode)


		}//close if



		al_draw_filled_rectangle(pos_x, pos_y, pos_x+30, pos_y+30, al_map_rgb(100, 100, 100));
		al_flip_display();
		al_clear_to_color(al_map_rgb(0, 0, 0));

	}//close game loop


	al_destroy_display(display);//destroy display

	return 0;
}//end main	