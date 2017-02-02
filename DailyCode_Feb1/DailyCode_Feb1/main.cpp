#include<allegro5\allegro.h>
#include<allegro5\allegro_primitives.h>

int main() {

	int width = 1440;
	int height = 960;

	al_init();
	al_init_primitives_addon();
	ALLEGRO_DISPLAY* display = al_create_display(width, height);
	al_clear_to_color(al_map_rgb(0, 0, 0));

	al_draw_filled_triangle(1000, 23, 450, 200, 500, 726, al_map_rgb(50, 215, 67));
	al_draw_filled_triangle(100, 2.3, 45, 20, 50, 72.6, al_map_rgb(50, 255, 167));
	al_draw_filled_triangle(10, .23, 4.5, 2, 5, 7.26, al_map_rgb(130, 0, 0.67));



	al_flip_display();
	al_rest(5.0);
	return 0;
}