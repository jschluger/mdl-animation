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

void my_main() {

  int i;

  screen s;

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
	make = make_translate( op[i].op.move.d[0],
			       op[i].op.move.d[1],
			       op[i].op.move.d[2] );
	matrix_mult( TOP_OF_(cstack), make );
	TOP_OF_(cstack) = make;
      	////
	printf("Move: %6.2f %6.2f %6.2f",
	       op[i].op.move.d[0],op[i].op.move.d[1],
	       op[i].op.move.d[2]);
	if (op[i].op.move.p != NULL)
	  {
	    printf("\tknob: %s",op[i].op.move.p->name);
	  }
	break;
      case SCALE:
	make = make_scale( op[i].op.scale.d[0],
			   op[i].op.scale.d[1],
			   op[i].op.scale.d[2] );
	matrix_mult( TOP_OF_(cstack), make );
	TOP_OF_(cstack) = make;
	////
	printf("Scale: %6.2f %6.2f %6.2f",
	       op[i].op.scale.d[0],op[i].op.scale.d[1],
	       op[i].op.scale.d[2]);
	if (op[i].op.scale.p != NULL)
	  {
	    printf("\tknob: %s",op[i].op.scale.p->name);
	  }
	break;
      case ROTATE:
	if ( op[i].op.rotate.axis == X )
	  make = make_rotX( op[i].op.rotate.degrees );
	else if ( op[i].op.rotate.axis == Y )
	  make = make_rotY( op[i].op.rotate.degrees );
	else if ( op[i].op.rotate.axis == Z )
	  make = make_rotZ( op[i].op.rotate.degrees );
	matrix_mult( TOP_OF_(cstack), make );
	TOP_OF_(cstack) = make;
	////
	printf("Rotate: axis: %6.2f degrees: %6.2f",
	       op[i].op.rotate.axis,
	       op[i].op.rotate.degrees);
	if (op[i].op.rotate.p != NULL)
	  {
	    printf("\tknob: %s",op[i].op.rotate.p->name);
	  }
	break;
      case BASENAME:
	printf("Basename: %s",op[i].op.basename.p->name);
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
      case FRAMES:
	printf("Num frames: %4.0f",op[i].op.frames.num_frames);
	break;
      case VARY:
	printf("Vary: %4.0f %4.0f, %4.0f %4.0f",
	       op[i].op.vary.start_frame,
	       op[i].op.vary.end_frame,
	       op[i].op.vary.start_val,
	       op[i].op.vary.end_val);
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
}


