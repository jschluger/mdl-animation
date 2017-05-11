#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"
#include "matrix.h"
#include "parser.h"
#include "stack.h"

/*======== void parse_file () ==========
Inputs:   char * filename 
          struct matrix * transform, 
          struct matrix * pm,
          screen s
Returns: 

Goes through the file named filename and performs all of the actions listed in that file.
The file follows the following format:
     Every command is a single character that takes up a line
     Any command that requires arguments must have those arguments in the second line.
     The commands are as follows:
         sphere: add a sphere to the edge matrix - 
	    takes 4 arguemnts (cx, cy, cz, r)
         torus: add a torus to the edge matrix - 
	    takes 5 arguemnts (cx, cy, cz, r1, r2)
         box: add a rectangular prism to the edge matrix - 
	    takes 6 arguemnts (x, y, z, width, height, depth)	    

	 circle: add a circle to the edge matrix - 
	    takes 4 arguments (cx, cy, cz, r)
	 hermite: add a hermite curve to the edge matrix -
	    takes 8 arguments (x0, y0, x1, y1, rx0, ry0, rx1, ry1)
	 bezier: add a bezier curve to the edge matrix -
	    takes 8 arguments (x0, y0, x1, y1, x2, y2, x3, y3)
	 line: add a line to the edge matrix - 
	    takes 6 arguemnts (x0, y0, z0, x1, y1, z1)
	 ident: set the transform matrix to the identity matrix - 
	 scale: create a scale matrix, 
	    then multiply the transform matrix by the scale matrix - 
	    takes 3 arguments (sx, sy, sz)
	 translate: create a translation matrix, 
	    then multiply the transform matrix by the translation matrix - 
	    takes 3 arguments (tx, ty, tz)
	 rotate: create an rotation matrix,
	    then multiply the transform matrix by the rotation matrix -
	    takes 2 arguments (axis, theta) axis should be x y or z
	 rotate: create a rotation matrix,
	    then multiply the transform matrix by the rotation matrix -
	    takes 2 arguments (axis, theta) axis should be x, y or z
	 apply: apply the current transformation matrix to the 
	    edge matrix
	 display: draw the lines of the edge matrix to the screen
	    display the screen
	 save: draw the lines of the edge matrix to the screen
	    save the screen to a file -
	    takes 1 argument (file name)
	 quit: end parsing

See the file script for an example of the file format

IMPORTANT MATH NOTE:
the trig functions int math.h use radian mesure, but us normal
humans use degrees, so the file will contain degrees for rotations,
be sure to conver those degrees to radians (M_PI is the constant
for PI)
====================*/
void parse_file ( char * filename, 
                  struct stack * cstack,
                  struct matrix * edges, 
                  screen s ) {
  
  FILE *f;
  char line[256];
  char * params[10];
  struct matrix * make = NULL; //new_matrix(4, 4);

  color c;
  c.red = 255;
  c.blue = 15;
  c.green = 0;

  color back; // background color
  back.red = 0;
  back.blue = 0;
  back.green = 0;
  
  clear_screen(s, back);

  if ( strcmp(filename, "stdin") == 0 ) 
    f = stdin;
  else
    f = fopen(filename, "r");
  
  while ( fgets(line, 255, f) != NULL ) {
    line[strlen(line)-1]='\0';
    printf(">%s<", line);
    
    //background
    if (! strncmp(line, "background", 255) ) {
      fgets(line, 255, f);
      line[strlen(line)-1]='\0';
      printf("(%s)", line);
      if (! strncmp(line, "white", 255) ){
	back.red = 255;
	back.blue = 255;
	back.green = 255;
      }
      if (! strncmp(line, "black", 255) ){
	back.red = 0;
	back.blue = 0;
	back.green = 0;
      }
      clear_screen(s, back);
	
    }//push
    if (! strncmp(line, "push", 255) ) {
      push( cstack );
    }
    //pop
    if (! strncmp(line, "pop", 255) ) {
      pop( cstack );
    }
    //display
    else if (! strncmp(line, "display", 255) ) {
      display(s);
      clear_screen(s, back);

    }

    //quit
    else if (! strncmp(line, "quit", 255) ) {
      exit(0);
    }
    
    //save
    else if (! strncmp(line, "save", 255) ) {
      fgets(line, 255, f);
      line[strlen(line)-1]='\0';
      printf("(%s)", line);
      save_extension(s, line); 
    }
    
    //line x0 y0 z0 x1 y1 z1
    else if (! strncmp(line, "line", 255) ) {
      fgets(line, 255, f);
      line[strlen(line)-1]='\0';
      printf("(%s)", line);
      char * tmp = line;
      int i;
      for(i = 0; (params[i] = strsep( &tmp, " ")); i++);
      add_edge( edges, atof(params[0]), atof(params[1]), atof(params[2]), atof(params[3]), atof(params[4]), atof(params[5]) );
      matrix_mult(TOP_OF_(cstack), edges);
      draw_lines( edges, s, c );
      edges->lastcol = 0;
    }

    //scale sx sy sz
    else if (! strncmp(line, "scale", 255) ) {
      fgets(line, 255, f);
      line[strlen(line)-1]='\0';
      printf("(%s)", line);
      char * tmp = line;
      int i;
      for(i = 0; (params[i] = strsep( &tmp, " ")); i++);
      make = make_scale( atof(params[0]), atof(params[1]), atof(params[2]) );
      matrix_mult( TOP_OF_(cstack), make );
      TOP_OF_(cstack) = make;
    }	      

    //translate tx ty tz
    else if (! strncmp(line, "move", 255) ) {
      fgets(line, 255, f);
      line[strlen(line)-1]='\0';
      printf("(%s)", line);
      char * tmp = line;
      int i;
      for(i = 0; (params[i] = strsep( &tmp, " ")); i++);
      make = make_translate( atof(params[0]), atof(params[1]), atof(params[2]) );
      matrix_mult( TOP_OF_(cstack), make );
      TOP_OF_(cstack) = make;
    }	      
    
    //rotate a t
    else if (! strncmp(line, "rotate", 255) ) {
      fgets(line, 255, f);
      line[strlen(line)-1]='\0';
      printf("(%s)", line);
      char * tmp = line;
      int i;
      for(i = 0; (params[i] = strsep( &tmp, " ")); i++);

      if ( !strncmp( params[0], "x", 1 ) )
	make = make_rotX( atof(params[1]) );
      else if ( !strncmp( params[0], "y", 1 ) )
	make = make_rotY( atof(params[1]) );
      else if ( !strncmp( params[0], "z", 1 ) )
	make = make_rotZ( atof(params[1]) );
      matrix_mult( TOP_OF_(cstack), make );
      TOP_OF_(cstack) = make;
    }	      

    //circle cx cy cz r
    else if (! strncmp(line, "circle", 255) ) {
      fgets(line, 255, f);
      line[strlen(line)-1]='\0';
      printf("(%s)", line);
      char * tmp = line;
      int i;
      for(i = 0; (params[i] = strsep( &tmp, " ")); i++);

      add_circle( edges, atof(params[0]), atof(params[1]), atof(params[2]), atof(params[3]), STEP);
      matrix_mult(TOP_OF_(cstack), edges);
      draw_lines( edges, s, c );
      edges->lastcol = 0;
    }
    //hermite: x0 y0 x1 y1 rx0 ry0 rx1 ry1
    else if (! strncmp(line, "hermite", 255) ) {
      fgets(line, 255, f);
      line[strlen(line)-1]='\0';
      printf("(%s)", line);
      char * tmp = line;
      int i;
      for(i = 0; (params[i] = strsep( &tmp, " ")); i++);
      add_curve( edges, atof(params[0]), atof(params[1]), atof(params[2]), atof(params[3]), atof(params[4]), atof(params[5]), atof(params[6]), atof(params[7]), STEP, HERMITE );
      matrix_mult(TOP_OF_(cstack), edges);
      draw_lines( edges, s, c );
      edges->lastcol = 0;
    }
    //bezier: x0 y0 x1 y1 x2 y2 x3 y3
    else if (! strncmp(line, "bezier", 255) ) {
      fgets(line, 255, f);
      line[strlen(line)-1]='\0';
      printf("(%s)", line);
      char * tmp = line;
      int i;
      for(i = 0; (params[i] = strsep( &tmp, " ")); i++);
      add_curve( edges, atof(params[0]), atof(params[1]), atof(params[2]), atof(params[3]), atof(params[4]), atof(params[5]), atof(params[6]), atof(params[7]), STEP, BEZIER );
      matrix_mult(TOP_OF_(cstack), edges);
      draw_lines( edges, s, c );
      edges->lastcol = 0;
    }	 
    //sphere: (cx, cy, cz, r)
    else if (! strncmp(line, "sphere", 255) ) {
      fgets(line, 255, f);
      line[strlen(line)-1]='\0';
      printf("(%s)", line);
      char * tmp = line;
      int i;
      for(i = 0; (params[i] = strsep( &tmp, " ")); i++);
      add_sphere( edges, atof(params[0]), atof(params[1]), atof(params[2]), atof(params[3]), STEP );
      matrix_mult(TOP_OF_(cstack), edges);
      draw_polygons( edges, s, c );
      edges->lastcol = 0;
    }
    //torus: (cx, cy, cz, r1, r2)
    else if (! strncmp(line, "torus", 255) ) {
      fgets(line, 255, f);
      line[strlen(line)-1]='\0';
      printf("(%s)", line);
      char * tmp = line;
      int i;
      for(i = 0; (params[i] = strsep( &tmp, " ")); i++);
      add_torus( edges, atof(params[0]), atof(params[1]), atof(params[2]), atof(params[3]), atof(params[4]), STEP );
      matrix_mult(TOP_OF_(cstack), edges);
      draw_polygons( edges, s, c );
      edges->lastcol = 0;
    }
    //box: (x, y, z, width, height, depth)	    
    else if (! strncmp(line, "box", 255) ) {
      fgets(line, 255, f);
      line[strlen(line)-1]='\0';
      printf("(%s)", line);
      char * tmp = line;
      int i;
      for(i = 0; (params[i] = strsep( &tmp, " ")); i++);
      add_box( edges, atof(params[0]), atof(params[1]), atof(params[2]), atof(params[3]), atof(params[4]), atof(params[5]) );
      matrix_mult(TOP_OF_(cstack), edges);
      draw_polygons( edges, s, c );
      edges->lastcol = 0;
    }

    printf("\n");
    //printf("\ncstack:\n");
    //print_stack(cstack);
  }
}
  
