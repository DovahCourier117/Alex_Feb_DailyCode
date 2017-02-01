#include<allegro5\allegro.h>
#include<allegro5\allegro_primitives.h>

int main() {

	int width = 1440;
	int height = 960;

	al_init();
	al_init_primitives_addon();
	ALLEGRO_DISPLAY* display = al_create_display(width, height);
	al_clear_to_color(al_map_rgb(0, 0, 0));

	al_draw_filled_triangle(1000, 1, 45, 45, 547, 726, al_map_rgb(50, 215, 67));
	al_draw_filled_triangle(109, 23, 450, 485, 547, 726, al_map_rgb(50, 255, 167));
	al_draw_filled_triangle(107, 29, 5, 245, 547, 726, al_map_rgb(130, 0, 0.67));



	al_flip_display();
	al_rest(5.0);
	return 0;
}