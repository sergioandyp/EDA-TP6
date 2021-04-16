#include "Allegro.h"
#include <allegro5/allegro5.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <iostream>

using namespace std;

bool Allegro::init(void) {                       //Funcion que inicializa todo allegro. No recibe nada. Devuelve un true si esta todo ok, false si hay error.

    if (!al_init()) {
        cout << "failed to initialize allegro!" << endl;
        return false;      
    }

    if (!al_init_image_addon()) {       // ADDON necesario para manejo de imagenes 
        cout << "Failed to initialize image addon!" << endl;
        return false;      
    }

    if (!al_init_font_addon()) {        // ADDON necesario para manejo de fuentes 
        cout << "Failed to initialize font addon!" << endl;
        al_shutdown_image_addon();
        return false;
    }

    if (!al_init_primitives_addon()) {   
        cout << "Failed to initialize primitives addon!" << endl;
        al_shutdown_image_addon();
        al_shutdown_font_addon();
        return false;
    }

    if (!al_init_ttf_addon()) {   
        cout << "Failed to initialize ttf addon!" << endl;
        al_shutdown_image_addon();
        al_shutdown_font_addon();
        al_shutdown_primitives_addon();
        return false;
    }

    return true;          
}

void Allegro::destroy(void) {
    al_shutdown_image_addon();
    al_shutdown_ttf_addon();
    al_shutdown_font_addon();
    al_shutdown_primitives_addon();
}