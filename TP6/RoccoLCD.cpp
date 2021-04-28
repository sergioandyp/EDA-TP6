
#include "RoccoLCD.h"
#include "../TP6/Allegro.h"
#include "../TP6/basicLCD.h"

#include <iostream>
#include <string>

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

//void lcdError::set_error(std::string name, std::string desc, unsigned long code) {
	//this->name = name;
	//this->description = desc;
	//this->code = code;
//
//}

RoccoLCD::RoccoLCD()
	: lcdError("OK", "Funciona", 1), theCursorPosition{ 0 , 0 },
	display(nullptr), bitmap(nullptr), font(nullptr), texto("                                ")
{
	
	bitmap = al_load_bitmap("16x2_LCD_displayF.jpg");
	font = al_load_ttf_font("DS-DIGI.ttf", FONT_SIZE, 0);
	if (bitmap == nullptr || font == nullptr) {
		std::cerr << "Could not find resource files!" << std::endl;
		//set_error("Load_resource_error", "Could not load Resource files", ERROR_RESOURCE_FILE_ENUM);
	}
	display = al_create_display(al_get_bitmap_width(bitmap), al_get_bitmap_height(bitmap));

	printScreen();
}

RoccoLCD::~RoccoLCD() {
	if (al_is_system_installed()) {
		al_destroy_bitmap(bitmap);
		al_destroy_display(display);
		al_destroy_font(font);
	}
}

bool RoccoLCD::lcdInitOk() {
	if (lcdError.getErrorCode() == NO_ERROR_ENUM) {
		return 1;
	}
	else {
		return 0;
	}
}

lcdError& RoccoLCD::lcdGetError() {
	return lcdError;
}

bool RoccoLCD::lcdClear() {
	texto = "                                ";
	theCursorPosition.row = 0;
	theCursorPosition.column = 0;
	printScreen();
	return true;
}

bool RoccoLCD::lcdClearToEOL() {
	for (unsigned int i = theCursorPosition.column; i < COLUMS; i++) {
		texto[i] = ' ';
	}
	printScreen();
	return true;
}

basicLCD& RoccoLCD::operator<<(const char c) {
	if (c >= ' ' && c <= '~') {
		texto[theCursorPosition.row * COLUMS + theCursorPosition.column] = c;
	}
	lcdMoveCursorRight();
	printScreen();
	return *this;
}

basicLCD& RoccoLCD::operator<<(const char* c) {
	std::string string = c;
	
	size_t sizeOfString = string.length();
	for ( int i = 0; i < sizeOfString; i++) {
		texto[theCursorPosition.row * COLUMS + theCursorPosition.column] = c[i];
		lcdMoveCursorRight();
		printScreen();
	}
	return *this;

}

bool RoccoLCD::lcdMoveCursorUp() {
	if (theCursorPosition.row <= 0) {
		printScreen();
		return true;
	}
	else {
		theCursorPosition.row--;
		printScreen();
		return true;
	}
}

bool RoccoLCD::lcdMoveCursorDown() {
	if (theCursorPosition.row == 1) {
		printScreen();
		return true;
	}
	else {
		theCursorPosition.row++;
		printScreen();
		return true;
	}
}

bool RoccoLCD::lcdMoveCursorRight() {
	if (theCursorPosition.column == COLUMS - 1 && theCursorPosition.row == ROWS - 1) {
		theCursorPosition.column = 0;
		theCursorPosition.row = 0;
		printScreen();
		return true;
	}
	else if (theCursorPosition.column == COLUMS - 1) {
		theCursorPosition.column = 0;
		theCursorPosition.row++;
		printScreen();
	}
	else {
		theCursorPosition.column++;
		printScreen();
	}
	return true;
}

bool RoccoLCD::lcdMoveCursorLeft() {
	if (theCursorPosition.column == 0 && theCursorPosition.row == 0) {
		printScreen();
		return true;
	}
	else if (theCursorPosition.column == COLUMS - 1 && theCursorPosition.row == ROWS - 1) {
		theCursorPosition.column = 0;
		theCursorPosition.row = 0;
	}
	else if (theCursorPosition.row == ROWS - 1 && theCursorPosition.column == 0) {
		theCursorPosition.column = COLUMS - 1;
		theCursorPosition.row = 0;
	}
	else {
		theCursorPosition.column--;
	}
	printScreen();
	return true;
}
bool RoccoLCD::lcdSetCursorPosition(const cursorPosition pos) {
	if (pos.column >= COLUMS || pos.column < 0) {
		return false;
	}
	else if (pos.row >= ROWS || pos.row < 0) {
		return false;
	}
	else {
		theCursorPosition = pos;
		return true;
	}
	
}

cursorPosition RoccoLCD::lcdGetCursorPosition() {
	return theCursorPosition;
}

void RoccoLCD::printScreen() {

	al_draw_bitmap(bitmap, 0.0, 0.0, 0);
	for (unsigned int i = 0; i < ROWS; i++) {
		for (unsigned int j = 0; j < COLUMS; j++) {
			al_draw_textf(font, al_map_rgb(0, 0, 0), HORIZONTAL_OFFSET + j * SPACE_BETWEEN_CHARS, VERTICAL_OFFSET + i * SPACE_BETWEEN_ROWS, 0, "%c", texto[(i * COLUMS) + j]);
		}
	}
	al_flip_display();
	return;
}
