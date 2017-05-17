/*========== my_main.c ==========

  This is the only file you need to modify in order
  to get a working mdl project (for now).

  my_main.c will serve as the interpreter for mdl.
  When an mdl script goes through a lexer and parser, 
  the resulting operations will be in the array op[].

  Your job is to go through each entry in op and perform
  the required action from the list below:

  push: push a new origin matrix onto the origin stack
  pop: remove the top matrix on the origin stack

  move/scale/rotate: create a transformation matrix 
  based on the provided values, then 
  multiply the current top of the
  origins stack by it.

  box/sphere/torus: create a solid object based on the
  provided values. Store that in a 
  temporary matrix, multiply it by the
  current top of the origins stack, then
  call draw_polygons.

  line: create a line based on the provided values. Store 
  that in a temporary matrix, multiply it by the
  current top of the origins stack, then call draw_lines.

  save: call save_extension with the provided filename

  display: view the image live
  
  jdyrlandweaver
  =========================*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "parser.h"
#include "symtab.h"
#include "y.tab.h"

#include "matrix.h"
#include "ml6.h"
#include "display.h"
#include "draw.h"
#include "stack.h"

/*======== void first_pass() ==========
  Inputs:   
  Returns: 

  Checks the op array for any animation commands
  (frames, basename, vary)
  
  Should set num_frames and basename if the frames 
  or basename commands are present

  If vary is found, but frames is not, the entire
  program should exit.

  If frames is found, but basename is not, set name
  to some default value, and print out a message
  with the name being used.

  jdyrlandweaver
  ====================*/
int first_pass() {
  //in order to use name and num_frames
  //they must be extern variables
  extern int num_frames;
  extern char name[128];

  char frames = 0;
  char vary = 0;
  char basename = 0;
  int i;
  
  for (i=0;i<lastop;i++) {  
    printf("(first pass)%d: ",i);
    switch (op[i].opcode)
      {
	
      case FRAMES:
	frames = 1;
	num_frames = op[i].op.frames.num_frames;
	////
	printf("Num frames: %4.0f",op[i].op.frames.num_frames);
	break;
	
      case VARY:
	vary = 1;

	////
	printf("Vary: %4.0f %4.0f, %4.0f %4.0f",
	       op[i].op.vary.start_frame,
	       op[i].op.vary.end_frame,
	       op[i].op.vary.start_val,
	       op[i].op.vary.end_val);
	break;
	
      case BASENAME:
	basename = 1;
	strncpy( name, op[i].op.basename.p->name, sizeof(name) );
	////
	printf("Basename: %s",op[i].op.basename.p->name);
	break;
      }
    printf("\n");
    }
  if ( vary && ! frames ) {
    printf("error: vary found, but frames not set\n"); 
    exit(14);
  }
  if ( frames ) {
      if ( !basename ) {
	strncpy( name, "frame", sizeof(name) );
	printf( "no basename set, using default '%s'\n", name );
      }
      printf( "num_frames: %d\nname: '%s'\n", num_frames, name );
      return 1;
  }
    
  return 0;
}

/*======== struct vary_node ** second_pass() ==========
  Inputs:   
  Returns: An array of vary_node linked lists

  In order to set the knobs for animation, we need to keep
  a seaprate value for each knob for each frame. We can do
  this by using an array of linked lists. Each array index
  will correspond to a frame (eg. knobs[0] would be the first
  frame, knobs[2] would be the 3rd frame and so on).

  Each index should contain a linked list of vary_nodes, each
  node contains a knob name, a value, and a pointer to the
  next node.

  Go through the opcode array, and when you find vary, go 
  from knobs[0] to knobs[frames-1] and add (or modify) the
  vary_node corresponding to the given knob with the
  appropirate value. 

  jdyrlandweaver
  ====================*/
struct vary_node ** second_pass() {
  struct vary_node ** knobs;
  knobs = calloc( num_frames, sizeof(struct vary_node *) );
  
  int i, j;
  
  printf("(second pass)%lu\n", sizeof(knobs));

  for (i=0;i<lastop;i++) {
    printf("(second pass)%d: ",i);
    switch (op[i].opcode)
      {

      case VARY:
	for (j = 0; j < num_frames; j++) {
	  if (j >= op[i].op.vary.start_frame && j <= op[i].op.vary.end_frame ) {
	    struct vary_node * tmp = (struct vary_node *)malloc(sizeof(struct vary_node));
	    strncpy( tmp->name, op[i].op.vary.p->name, sizeof(tmp->name) );
	    tmp->value = j * ((op[i].op.vary.end_val - op[i].op.vary.start_val) /
			      (op[i].op.vary.end_frame - op[i].op.vary.start_frame) );

	    tmp->next = knobs[j];
	    knobs[j] = tmp;
	    printf("(second pass) setting vary %s to %.3f for frame %d, next = %p\n",
		   tmp->name,
		   tmp->value,
		   j, tmp->next);
	  }
	}
	////
	printf("setting Vary: %4.0f %4.0f, %4.0f %4.0f",
	       op[i].op.vary.start_frame,
	       op[i].op.vary.end_frame,
	       op[i].op.vary.start_val,
	       op[i].op.vary.end_val);
	break;
      }
    printf("\n");
  }
  
  return knobs;
}


/*======== void print_knobs() ==========
Inputs:   
Returns: 

Goes through symtab and display all the knobs and their
currnt values

jdyrlandweaver
====================*/
void print_knobs() {
  
  int i;

  printf( "ID\tNAME\t\tTYPE\t\tVALUE\n" );
  for ( i=0; i < lastsym; i++ ) {

    if ( symtab[i].type == SYM_VALUE ) {
      printf( "%d\t%s\t\t", i, symtab[i].name );

      printf( "SYM_VALUE\t");
      printf( "%6.2f\n", symtab[i].s.value);
    }
  }
}


/*======== void my_main() ==========
  Inputs: 
  Returns: 

  This is the main engine of the interpreter, it should
  handle most of the commadns in mdl.

  If frames is not present in the source (and therefore 
  num_frames is 1, then process_knobs should be called.

  If frames is present, the enitre op array must be
  applied frames time. At the end of each frame iteration
  save the current screen to a file named the
  provided basename plus a numeric string such that the
  files will be listed in order, then clear the screen and
  reset any other data structures that need it.

  Important note: you cannot just name your files in 
  regular sequence, like pic0, pic1, pic2, pic3... if that
  is done, then pic1, pic10, pic11... will come before pic2
  and so on. In order to keep things clear, add leading 0s
  to the numeric portion of the name. If you use sprintf, 
  you can use "%0xd" for this purpose. It will add at most
  x 0s in front of a number, if needed, so if used correctly,
  and x = 4, you would get numbers like 0001, 0002, 0011,
  0487

  jdyrlandweaver
  ====================*/
void my_main() {

  struct vary_node ** knobs = NULL;
  if ( first_pass() )
    knobs = second_pass();
  else
    num_frames = 1;

  /* int k; */
  /* for (k = 0;k < num_frames;k++) { */
  /*   struct vary_node * tmp = knobs[k]; */

  /*   printf("frame number %d: ", k); */
  /*   while (tmp){ */
  /*     printf("\t%s: %.3f, ", tmp->name, tmp->value); */
  /*     tmp = tmp->next; */
  /*   } */
  /*   printf("\n"); */
  /*     } */
    
  print_knobs();
  
  int i, frame;
  screen s;
  double tmp_value;
  char frame_name[150];
  
  struct matrix * make;
  make = NULL;
  
  struct matrix * edges;
  edges = new_matrix(4, 4);
  edges->lastcol=0;

  struct stack * cstack;
  cstack = new_stack();
  
  color back;
  back.red = 0;
  back.blue = 0;
  back.green = 0;

  color c;
  c.red = 0;
  c.blue = 0;
  c.green = 255;
  
  clear_screen( s, back );

  for (frame = 0; frame<num_frames; frame++) {
    printf("frame # %d of %d\n", frame, num_frames);
    for (i=0;i<lastop;i++) {  
      printf("%d: ",i);
      switch (op[i].opcode)
	{ 
	case LIGHT:
	  printf("Light: %s at: %6.2f %6.2f %6.2f",
		 op[i].op.light.p->name,
		 op[i].op.light.c[0], op[i].op.light.c[1],
		 op[i].op.light.c[2]);
	  break;
	case AMBIENT:
	  printf("Ambient: %6.2f %6.2f %6.2f",
		 op[i].op.ambient.c[0],
		 op[i].op.ambient.c[1],
		 op[i].op.ambient.c[2]);
	  break;

	case CONSTANTS:
	  printf("Constants: %s",op[i].op.constants.p->name);
	  break;
	case SAVE_COORDS:
	  printf("Save Coords: %s",op[i].op.save_coordinate_system.p->name);
	  break;
	case CAMERA:
	  printf("Camera: eye: %6.2f %6.2f %6.2f\taim: %6.2f %6.2f %6.2f",
		 op[i].op.camera.eye[0], op[i].op.camera.eye[1],
		 op[i].op.camera.eye[2],
		 op[i].op.camera.aim[0], op[i].op.camera.aim[1],
		 op[i].op.camera.aim[2]);

	  break;
	case SPHERE:
	  add_sphere( edges,
		      op[i].op.sphere.d[0],
		      op[i].op.sphere.d[1],
		      op[i].op.sphere.d[2],
		      op[i].op.sphere.r, STEP );
	  matrix_mult(TOP_OF_(cstack), edges);
	  draw_polygons( edges, s, c );
	  edges->lastcol = 0;
	  ////
	  printf("Sphere: %6.2f %6.2f %6.2f r=%6.2f",
		 op[i].op.sphere.d[0],op[i].op.sphere.d[1],
		 op[i].op.sphere.d[2],
		 op[i].op.sphere.r);
	  if (op[i].op.sphere.constants != NULL)
	    {
	      printf("\tconstants: %s",op[i].op.sphere.constants->name);
	    }
	  if (op[i].op.sphere.cs != NULL)
	    {
	      printf("\tcs: %s",op[i].op.sphere.cs->name);
	    }
	
	  break;
	case TORUS:
	  add_torus( edges,
		     op[i].op.torus.d[0],
		     op[i].op.torus.d[1],
		     op[i].op.torus.d[2],
		     op[i].op.torus.r0,
		     op[i].op.torus.r1, STEP );
	  matrix_mult(TOP_OF_(cstack), edges);
	  draw_polygons( edges, s, c );
	  edges->lastcol = 0;
	  ////
	  printf("Torus: %6.2f %6.2f %6.2f r0=%6.2f r1=%6.2f",
		 op[i].op.torus.d[0],op[i].op.torus.d[1],
		 op[i].op.torus.d[2],
		 op[i].op.torus.r0,op[i].op.torus.r1);
	  if (op[i].op.torus.constants != NULL)
	    {
	      printf("\tconstants: %s",op[i].op.torus.constants->name);
	    }
	  if (op[i].op.torus.cs != NULL)
	    {
	      printf("\tcs: %s",op[i].op.torus.cs->name);
	    }

	  break;
	case BOX:
	  add_box( edges,
		   op[i].op.box.d0[0],
		   op[i].op.box.d0[1],
		   op[i].op.box.d0[2],
		   op[i].op.box.d1[0],
		   op[i].op.box.d1[1],
		   op[i].op.box.d1[2]);
	  matrix_mult(TOP_OF_(cstack), edges);
	  draw_polygons( edges, s, c );
	  edges->lastcol = 0;
	  ////
	  printf("Box: d0: %6.2f %6.2f %6.2f d1: %6.2f %6.2f %6.2f",
		 op[i].op.box.d0[0],op[i].op.box.d0[1],
		 op[i].op.box.d0[2],
		 op[i].op.box.d1[0],op[i].op.box.d1[1],
		 op[i].op.box.d1[2]);
	  if (op[i].op.box.constants != NULL)
	    {
	      printf("\tconstants: %s",op[i].op.box.constants->name);
	    }
	  if (op[i].op.box.cs != NULL)
	    {
	      printf("\tcs: %s",op[i].op.box.cs->name);
	    }

	  break;
	case LINE:
	  add_edge( edges,
		    op[i].op.line.p0[0],
		    op[i].op.line.p0[1],
		    op[i].op.line.p0[1],
		    op[i].op.line.p1[0],
		    op[i].op.line.p1[1],
		    op[i].op.line.p1[1] );
	  matrix_mult(TOP_OF_(cstack), edges);
	  draw_lines( edges, s, c );
	  edges->lastcol = 0;
	  ////
	  printf("Line: from: %6.2f %6.2f %6.2f to: %6.2f %6.2f %6.2f",
		 op[i].op.line.p0[0],op[i].op.line.p0[1],
		 op[i].op.line.p0[1],
		 op[i].op.line.p1[0],op[i].op.line.p1[1],
		 op[i].op.line.p1[1]);
	  if (op[i].op.line.constants != NULL)
	    {
	      printf("\n\tConstants: %s",op[i].op.line.constants->name);
	    }
	  if (op[i].op.line.cs0 != NULL)
	    {
	      printf("\n\tCS0: %s",op[i].op.line.cs0->name);
	    }
	  if (op[i].op.line.cs1 != NULL)
	    {
	      printf("\n\tCS1: %s",op[i].op.line.cs1->name);
	    }
	  break;
	case MESH:
	  printf("Mesh: filename: %s",op[i].op.mesh.name);
	  if (op[i].op.mesh.constants != NULL)
	    {
	      printf("\tconstants: %s",op[i].op.mesh.constants->name);
	    }
	  break;
	case SET:
	  printf("Set: %s %6.2f",
		 op[i].op.set.p->name,
		 op[i].op.set.p->s.value);
	  break;
	case MOVE:
	  tmp_value = 1;
	  if (op[i].op.move.p != NULL){
	    struct vary_node * tmp;
	    for(tmp = knobs[frame]; tmp; tmp = tmp->next){
	      if ( !strcmp(tmp->name, op[i].op.move.p->name) ){
		tmp_value = tmp->value;
		break;
	      }
	    }
	  }
	  make = make_translate( op[i].op.move.d[0] * tmp_value,
				 op[i].op.move.d[1] * tmp_value,
				 op[i].op.move.d[2] * tmp_value );
	  matrix_mult( TOP_OF_(cstack), make );
	  TOP_OF_(cstack) = make;
	  ////
	  printf("Move: %6.2f %6.2f %6.2f",
		 op[i].op.move.d[0],op[i].op.move.d[1],
		 op[i].op.move.d[2]);
	  if (op[i].op.move.p != NULL)
	    {
	      printf("\tknob: %s = %.2f",op[i].op.move.p->name, tmp_value);
	    }
	  break;
	case SCALE:
	  tmp_value = 1;
	  if (op[i].op.move.p != NULL){
	    struct vary_node * tmp;
	    for(tmp = knobs[frame]; tmp; tmp = tmp->next){
	      if ( !strcmp(tmp->name, op[i].op.scale.p->name) ){
		tmp_value = tmp->value;
		break;
	      }
	    }
	  }
	  make = make_scale( op[i].op.scale.d[0] * tmp_value,
			      op[i].op.scale.d[1] * tmp_value,
			      op[i].op.scale.d[2] * tmp_value );
	  matrix_mult( TOP_OF_(cstack), make );
	  TOP_OF_(cstack) = make;
	  ////
	  printf("Scale: %6.2f %6.2f %6.2f",
		 op[i].op.scale.d[0],op[i].op.scale.d[1],
		 op[i].op.scale.d[2]);
	  if (op[i].op.scale.p != NULL)
	    {
	      printf("\tknob: %s = %.2f",op[i].op.scale.p->name, tmp_value);
	    }
	  break;
	case ROTATE:
	  tmp_value = 1;
	  if (op[i].op.move.p != NULL){
	    struct vary_node * tmp;
	    for(tmp = knobs[frame]; tmp; tmp = tmp->next){
	      if ( !strcmp(tmp->name, op[i].op.rotate.p->name) ){
		tmp_value = tmp->value;
		break;
	      }
	    }
	  }
	  if ( op[i].op.rotate.axis == X )
	    make = make_rotX( op[i].op.rotate.degrees * tmp_value );
	  else if ( op[i].op.rotate.axis == Y )
	    make = make_rotY( op[i].op.rotate.degrees * tmp_value );
	  else if ( op[i].op.rotate.axis == Z )
	    make = make_rotZ( op[i].op.rotate.degrees * tmp_value );
	  matrix_mult( TOP_OF_(cstack), make );
	  TOP_OF_(cstack) = make;
	  ////
	  printf("Rotate: axis: %6.2f degrees: %6.2f",
		 op[i].op.rotate.axis,
		 op[i].op.rotate.degrees);
	  if (op[i].op.rotate.p != NULL)
	    {
	      printf("\tknob: %s = %.2f",op[i].op.rotate.p->name, tmp_value);
	    }
	  break;
	case SAVE_KNOBS:
	  printf("Save knobs: %s",op[i].op.save_knobs.p->name);
	  break;
	case TWEEN:
	  printf("Tween: %4.0f %4.0f, %s %s",
		 op[i].op.tween.start_frame,
		 op[i].op.tween.end_frame,
		 op[i].op.tween.knob_list0->name,
		 op[i].op.tween.knob_list1->name);
	  break;
	case PUSH:
	  push( cstack );
	  ////
	  printf("Push");
	  break;
	case POP:
	  pop( cstack );
	  ////
	  printf("Pop");
	  break;
	case GENERATE_RAYFILES:
	  printf("Generate Ray Files");
	  break;
	case SAVE:
	  save_extension(s, op[i].op.save.p->name); 
	  clear_screen(s, back);
	  ////
	  printf("Save: %s",op[i].op.save.p->name);
	  break;
	case SHADING:
	  printf("Shading: %s",op[i].op.shading.p->name);
	  break;
	case SETKNOBS:
	  printf("Setknobs: %f",op[i].op.setknobs.value);
	  break;
	case FOCAL:
	  printf("Focal: %f",op[i].op.focal.value);
	  break;
	case DISPLAY:
	  display(s);
	  clear_screen(s, back);
	  printf("Display");
	  break;
	}
      printf("\n");
    }
    if (num_frames - 1){
      printf("saving frame %03d\n", frame);
      sprintf( frame_name, "anim/%s%03d.png", name, frame);
      save_extension(s, frame_name); 
      clear_screen(s, back);
    }
  }
}
