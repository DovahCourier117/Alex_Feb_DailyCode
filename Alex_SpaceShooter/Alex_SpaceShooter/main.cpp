#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>

int main() {//start main

	int width = 1824;//size of screen
	int height = 1026;

	bool done = false;//variable for game loop

	int pos_x = width / 2;
	int pos_y = height / 2;


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

		if (ev.type == ALLEGRO_EVENT_KEY_DOWN) {




		}

	}//close game loop


	al_destroy_display(display);//destroy display

	return 0;
}//end main	