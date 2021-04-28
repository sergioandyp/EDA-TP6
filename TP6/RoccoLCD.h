#ifndef __ROCCOLCD__
#define __ROCCOLCD__

#include "../TP6/Allegro.h"
#include "../TP6/basicLCD.h"

#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>

#include <string>
#include <iostream>

#define LCD_WIDTH 643
#define LCD_HEIGHT 294

#define COLUMS 16
#define ROWS 2


#define VERTICAL_OFFSET 150
#define HORIZONTAL_OFFSET 120
#define FONT_SIZE 50
#define SPACE_BETWEEN_CHARS 46 
#define SPACE_BETWEEN_ROWS 80

enum ERRORS { NO_ERROR_ENUM = 1, ERROR_LCD_INIT_ENUM, ERROR_RESOURCE_FILE_ENUM };

class RoccoLCD : public basicLCD {
public:

	RoccoLCD();

	~RoccoLCD();

	/*=====================================================
	* Name: lcdInitOk
	* Entra: -
	* Resulta: No genera ningún cambio en el display.
	* Devuelve en su nombre “true” si el display se inicializó
	* correctamente (el constructor no tuvo errores) o “false
	* en caso contrario.
	*=====================================================*/
	bool lcdInitOk() override; //

   /*=====================================================
   * Name: lcdGetError
   * Entra: -
   * Resulta: No genera ningún cambio en el display.
   * Devuelve en su nombre un lcdError&
   *=====================================================*/
	lcdError& lcdGetError() override;//

   /*=====================================================
   * Name: lcdClear
   * Entra: -
   * Resulta: Borra el display y el cursor va a HOME
   *
   * Devuelve en su nombre “true” si fue satisfactoria “false”
   * en caso contrario.
   *=====================================================*/
	bool lcdClear() override; // falta printearlo

   /*=====================================================
   * Name: lcdClearToEOL
   * Entra: -
   * Resulta: Borra el display desde la posición actual
   * del cursor hasta el final de la línea.
   *
   * Devuelve en su nombre “true” si fue satisfactoria “false”
   * en caso contrario.
   *=====================================================*/
	bool lcdClearToEOL() override; //falta printarlo y DUDOSISIMO

   /*=====================================================
   * Name: operator<<()
   * Entra: Un carácter
   * Resulta: Pone el carácter en la posición actual
   * del cursor del display y avanza el cursor a la próxima
   * posición respetando el gap (si el carácter no es imprimible
   * lo ignora)
   *
   * Devuelve en su nombre una referencia a un basicLCD que permite
   * encascar la función:
   * basicLCD lcd;
   * lcd << ‘a’ << ‘b’ << ‘c’;
   *=====================================================*/
	basicLCD& operator<<(const char c) override; //falta printearlo

   /*=====================================================
   * Name: operator<<()
   * Entra: Una cadena de caracteres NULL terminated
   * Resulta: imprime la cadena de caracteres en la posición actual
   * del cursor y avanza el cursor al final de la cadena respetando
   * el gap (si algún carácter no es imprimible lo ignora). Si recibe una
   * cadena de más de 32 caracteres, muestra los últimos 32 en el display.
   *
   * Devuelve en su nombre una referencia a un basicLCD que permite
   * encascar la función:
   * basicLCD lcd;
   * lcd << “Hola” << “ “ << “Mundo”;
   *=====================================================*/
	basicLCD& operator<<(const char* c) override; //no verifica caracteres e inchequeable

   /*=====================================================
   * Name: lcdMoveCursorUp
   *
   * Entra: -
   * Resulta: Pasa el cursor a la primera línea del display sin
   * alterar la columna en la que estaba.
   *
   * Devuelve en su nombre “true” si fue satisfactoria “false”
   * en caso contrario.
   *=====================================================*/
	bool lcdMoveCursorUp() override; // inchequeable

   /*=====================================================
   * Name: lcdMoveCursorDown
   *
   * Entra: -
   * Resulta: Pasa el cursor a la segunda línea del display sin
   * alterar la columna en la que estaba.
   *
   * Devuelve en su nombre “true” si fue satisfactoria “false”
   * en caso contrario.
   *=====================================================*/
	bool lcdMoveCursorDown() override; // inchequeable

   /*=====================================================
   * Name: lcdMoveCursorRight
   *
   * Entra: -
   * Resulta: Avanza el cursor una posición
   *
   * Devuelve en su nombre “true” si fue satisfactoria “false”
   * en caso contrario.
   *=====================================================*/
	bool lcdMoveCursorRight() override; // inchequeable

   /*=====================================================
   * Name: lcdMoveCursorLeft
   *
   * Entra: -
   * Resulta: Retrocede el cursor una posición
   *
   * Devuelve en su nombre “true” si fue satisfactoria “false”
   * en caso contrario.
   *=====================================================*/
	bool lcdMoveCursorLeft() override; // inchequebale 

   /*=====================================================
   * Name: lcdSetCursorPosition
   * Entra: Recibe una estructura tipo cursorPosition
   * Resulta: Posiciona el cursor en la posición dada
   * por row y column. row[0-1] col[0-19]. Ante un valor inválido
   * de row y/o column ignora la instrucción (no hace nada).
   *
   * Devuelve en su nombre “true” si fue satisfactoria “false”
   * en caso contrario.
   *=====================================================*/
	bool lcdSetCursorPosition(const cursorPosition pos);

	/*=====================================================
	* Name: lcdGetCursorPosition
	* Entra: -
	* Resulta: Devuelve la posición actual del cursor.
	*
	*
	* Devuelve una estructura tipo cursorPosition
	*=====================================================*/
	cursorPosition lcdGetCursorPosition() override;

	void printScreen();
	void setError(std::string error, std::string desc, unsigned long code);

private:

	lcdError lcdError;
	cursorPosition theCursorPosition;

	ALLEGRO_DISPLAY* display = nullptr;
	ALLEGRO_BITMAP* bitmap = nullptr;
	ALLEGRO_FONT* font = nullptr;

	std::string texto;

	//void set_error(std::string name, std::string desc, unsigned long code);
};




#endif __ROCCOLCD__

