#include "Allegro.h"
#include "basicLCD.h"
#include "KevinLCD.h"
#include <iostream>

int main() {
	Allegro allegro;

	if (!allegro.init()) {
		return 1;
	};
	basicLCD* lcd;
	KevinLCD kevin_lcd;
	lcd = &kevin_lcd;
	lcd->lcdInitOk();
	const char* hola = (const char*)"Este es un texto muy largo, mucho mas texto";
	*lcd << hola;
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
	while (1);

	allegro.destroy();
}