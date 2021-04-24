#include "../TP6/Allegro.h"
#include "../TP6/SergioLCD.h"

#include <iostream>
#include <string>

using namespace std;

int main() {
	Allegro allegro;

	if (!allegro.init()) {
		return 1;
	};

	basicLCD *lcd = new SergioLCD();

	if (lcd->lcdInitOk()) {
		cout << "Todo OK" << endl;
	}
	else return 1;

	// Muevo el cursor

	for (int i = 0; i < 40; i++) {
		cout << lcd->lcdMoveCursorRight() << endl;
		al_rest(0.25);
	}

	for (int i = 0; i < 40; i++) {
		cout << lcd->lcdMoveCursorLeft() << endl;
		al_rest(0.25);
	}

	for (int i = 0; i < 20; i++) {
		cout << lcd->lcdMoveCursorDown() << endl;
		al_rest(0.25);
		cout << lcd->lcdMoveCursorRight() << endl;
		al_rest(0.25);
		cout << lcd->lcdMoveCursorUp() << endl;
		al_rest(0.25);
	}

	lcd->lcdClear();

	// Entrada de texto

	string text;

	// Caracter por caracter

	getline(cin, text);

	for (char c : text) {
		*lcd << c;
	}

	// Como char*

	do {
		getline(cin, text);
		lcd->lcdClear();
		*lcd << text.c_str();
	}
	while (text != "quit");

	delete lcd;

	allegro.destroy();
}