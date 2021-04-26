#include "Allegro.h"
#include "basicLCD.h"
#include "KevinLCD.h"
#include <iostream>

using namespace std;

int main() {
	Allegro allegro;

	if (!allegro.init()) {
		return 1;
	};
	basicLCD* lcd;
	KevinLCD kevin_lcd;


	/////

	basicLCD* lcd[3];
	lcd[0] = new KevinLCD;
	lcd[1] = new SergioLCD;
	lcd[2] = new RoccoLCD;

	//



	for (int i = 0; i < 3; i++) {
		lcd = &kevin_lcd;
		lcd->lcdInitOk();
		*lcd << "Este es un texto muy largo, mucho mas texto";
		lcd->lcdClear();
		*lcd << 'a' << 'b' << 'c' << 'd' << 'e' << 'f' << 'g' << 'h' << 'i' << 'j' << 'k' << 'l' << 'm' << 'n' << 'o' << 'p' << 'q' << 'r';
		lcd->lcdMoveCursorUp();
		lcd->lcdClearToEOL();
		*lcd << 'z' << 'w' << 'x';
		lcd->lcdMoveCursorDown();
		*lcd << 'H' << 'O' << 'L' << 'A';
		lcd->lcdMoveCursorUp();
		*lcd << 'C' << 'H' << 'U';
		lcd->lcdMoveCursorLeft();
		*lcd << 'A';
		lcd++;
	}

	int x;
	cin >> x;

	allegro.destroy();
}