#include <allegro5/allegro5.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

#include <iostream>

using namespace std;

int main() {

	if (!al_init()) {
		return 1;
	}

	if (!al_init_image_addon()) {
		return 1;
	}

	ALLEGRO_BITMAP* img = al_load_bitmap("sergioLCD.jpg");

	if (img == NULL) {
		cout << "img es NULL" << endl;
		return 1;
	}

	ALLEGRO_DISPLAY* disp = al_create_display(al_get_bitmap_width(img), al_get_bitmap_height(img));

	al_draw_bitmap(img, 0, 0, 0);
	al_flip_display();

	al_rest(5);

	al_destroy_bitmap(img);
	al_shutdown_image_addon();
	
}