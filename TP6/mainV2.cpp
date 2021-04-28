#include "Allegro.h"
#include "basicLCD.h"

#include "KevinLCD.h"
#include "SergioLCD.h"
#include "RoccoLCD.h"

#include <iostream>
#include <allegro5/allegro.h>

#define LCD_COUNT	3
#define TIME		2

enum names {KEVIN=0, SERGIO, ROCCO};

using namespace std;

int main() {
	Allegro allegro;

	if (!allegro.init()) {
		return 1;
	};
	
	
	basicLCD* lcd = nullptr;

	for (int i = 0; i < LCD_COUNT; i++) {

		switch (i) {
		case KEVIN:
			lcd = new KevinLCD;
			break;
		case SERGIO:
			lcd = new SergioLCD;
			break;
		case ROCCO:
			lcd = new RoccoLCD;
			break;
		}

		lcd->lcdInitOk();
		*lcd << "Este es un texto muy largo, mucho mas texto";
		al_rest(TIME);
		lcd->lcdClear();
		*lcd << 'a' << 'b' << 'c' << 'd' << 'e' << 'f' << 'g' << 'h' << 'i' << 'j' << 'k' << 'l' << 'm' << 'n' << 'o' << 'p' << 'q' << 'r';
		al_rest(TIME);
		lcd->lcdSetCursorPosition({0, 5});
		lcd->lcdMoveCursorUp();
		lcd->lcdClearToEOL();
		al_rest(TIME);
		*lcd << 'z' << 'w' << 'x';
		al_rest(TIME);
		lcd->lcdClear();
		*lcd << 'H' << 'O' << 'L' << 'A';
		al_rest(TIME);
		lcd->lcdMoveCursorUp();
		*lcd << "TEXTO EN MAYUSCULA";
		al_rest(TIME);
		lcd->lcdMoveCursorLeft();
		lcd->lcdMoveCursorLeft();
		lcd->lcdMoveCursorLeft();
		lcd->lcdMoveCursorLeft();

		*lcd << 'X';
		al_rest(TIME);

		delete lcd;
	}

	std::cout << "FIN. Presione Enter para salir" << endl;

	std::cin.get();

	allegro.destroy();
}