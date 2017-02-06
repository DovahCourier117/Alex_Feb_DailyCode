#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>

int main() {

	int width = 1824;
	int height = 1026;

	ALLEGRO_DISPLAY* display = NULL;
	ALLEGRO_EVENT_QUEUE*event_queue = NULL;

	if (!al_init())
		return -1;

	display = al_create_display(width, height);

	if (!display)
		return -1;



	al_destroy_display(display);

	return 0;
}		