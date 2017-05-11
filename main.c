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


int main(int argc, char **argv) {
  screen s;
  struct matrix * edges;
  struct stack * cstack;
  edges = new_matrix(4, 4);
  edges->lastcol=0;
  cstack = new_stack();
    
  if ( argc == 2 )
    parse_file( argv[1], cstack, edges, s );
  else
    parse_file( "stdin", cstack, edges, s );

  free_matrix( edges );
  free_stack( cstack );
}  
