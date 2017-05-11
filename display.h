#ifndef DISPLAY_H
#define DISPLAY_H

#include "ml6.h"

void plot( screen s, color c, int x, int y);
void clear_screen( screen s);
void save_ppm( screen s, char *file);
void save_extension( screen s, char *file);
void display( screen s);
void make_animation( char * name );
void clear_screen( screen s, color c );
void save_ppm( screen s, char *file);
void save_extension( screen s, char *file);
void display( screen s);
void swap( int * a, int * b );

#endif
