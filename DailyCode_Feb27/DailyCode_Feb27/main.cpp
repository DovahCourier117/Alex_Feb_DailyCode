#include <iostream>

#include <allegro5\allegro.h>
#include<allegro5\allegro_primitives.h>

using namespace std;

int main() {

	float picture[5][5] = { {200,400},{200,800},{400,600},{300,200},{200,400} };

	al_init();
	al_init_primitives_addon();
	ALLEGRO_DISPLAY* display = al_create_display(1280, 1000);

	al_draw_ribbon(*picture, sizeof(*picture), al_map_rgb(200,20,20),5,5);

	al_flip_display();
	al_rest(20);

}