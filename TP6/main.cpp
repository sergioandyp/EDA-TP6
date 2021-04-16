#include "Allegro.h"
#include "basicLCD.h"
#include <iostream>

int main() {
	Allegro allegro;

	if (!allegro.init()) {
		return 1;
	};
	basicLCD* lcd;
	lcd = &kevinLCD;

	//
	//	Código fantástico (...)
	//
	allegro.destroy();
}