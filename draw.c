#include <stdio.h>
#include <stdlib.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"
#include "matrix.h"
#include "math.h"

/*======== void add_polygon() ==========
Inputs:   struct matrix *surfaces
         double x0
         double y0
         double z0
         double x1
         double y1
         double z1
         double x2
         double y2
         double z2  
Returns: 
Adds the vertices (x0, y0, z0), (x1, y1, z1)
and (x2, y2, z2) to the polygon matrix. They
define a single triangle surface.
====================*/
void add_polygon( struct matrix *polygons, 
		  double x0, double y0, double z0, 
		  double x1, double y1, double z1, 
		  double x2, double y2, double z2 ) {

  add_point( polygons, x0, y0, z0 );
  add_point( polygons, x1, y1, z1 );
  add_point( polygons, x2, y2, z2 );
}

/*======== struct matrix * generate_normal() ==========
Inputs:   struct matrix *polygon
          int point -- starting point in the matrix
Returns: 
normal line from given polygon
====================*/
struct matrix * generate_normal( struct matrix * polygon, int point ) {
  struct matrix * A = new_matrix(4, 0);
  struct matrix * B = new_matrix(4, 0);
  struct matrix * ret = new_matrix(4, 0);
  add_point( A,
	     polygon->m[X][1 + point] - polygon->m[X][point],
	     polygon->m[Y][1 + point] - polygon->m[Y][point],
	     polygon->m[Z][1 + point] - polygon->m[Z][point] );
  add_point( B,
	     polygon->m[X][2 + point] - polygon->m[X][point],
	     polygon->m[Y][2 + point] - polygon->m[Y][point],
	     polygon->m[Z][2 + point] - polygon->m[Z][point] );
  add_point( ret,
	     A->m[Y][0]*B->m[Z][0] - A->m[Z][0]*B->m[Y][0],
	     A->m[Y][0]*B->m[X][0] - A->m[X][0]*B->m[Z][0],
	     A->m[X][0]*B->m[Y][0] - A->m[Y][0]*B->m[X][0] );
  return ret;
	     
}

void scanline( struct matrix * polygon, int point, screen s ) {
  int B, M, T; // index of where Bottom, Middle, and Top point of the polygon are
  B = point;
  M = point + 1;
  T = point + 2;

  color c;
  
  printf("y[point]: %.2f\n", polygon->m[Y][point]);
  printf("y[point+1]: %.2f\n", polygon->m[Y][point+1]);
  printf("y[point+2]: %.2f\n", polygon->m[Y][point+2]);
  
  if ( polygon->m[Y][point] >= polygon->m[Y][point + 1] ) {
    if ( polygon->m[Y][point + 1] >= polygon->m[Y][point + 2] ) {
      T = point;
      M = point + 1;
      B = point + 2;
    }
    else if ( polygon->m[Y][point + 2] >= polygon->m[Y][point] ) {
      T = point + 2;
      M = point;
      B = point + 1;
    }
    else {
      T = point;
      M = point + 2;
      B = point + 1;
    }
  }
  else { //if ( polygon->m[Y][point + 1] >= polygon->m[Y][point] ) {
    if ( polygon->m[Y][point] >= polygon->m[Y][point + 2] ) {
      T = point + 1;
      M = point;
      B = point + 2;
    }
    else if ( polygon->m[Y][point + 2] >= polygon->m[Y][point + 1] ) {
      T = point + 2;
      M = point + 1;
      B = point;
    }
    else {
      T = point + 1;
      M = point + 2;
      B = point;
    }
  }

  /* c.red = abs((int)(polygon->m[X][B] - polygon->m[Y][B])) % 255; */
  /* c.blue = abs((int)(polygon->m[Z][M])) % 255; */
  /* c.green = abs((int)(polygon->m[X][T] - polygon->m[Z][B])) % 255; */

  c.red = 0;
  c.blue = 255;
  c.green = 0;

  color top;
  top.red = 255;
  top.green = 0;
  top.blue = 0;

  color mid;
  mid.red = 0;
  mid.green = 255;
  mid.blue = 0;

  color bot;
  bot.red = 0;
  bot.green = 0;
  bot.blue = 250;
  

  /* int k; */
  /* for (k = 0; k< point; k++){ */
  /*   plot(s, top, (int)(polygon->m[X][T]), (int)(polygon->m[Y][T])); */
  /*   plot(s, top, (int)(polygon->m[X][T])+k, (int)(polygon->m[Y][T])); */
  /*   plot(s, top, (int)(polygon->m[X][T])-k, (int)(polygon->m[Y][T])); */
  /*   plot(s, top, (int)(polygon->m[X][T]), (int)(polygon->m[Y][T])+k); */
  /*   plot(s, top, (int)(polygon->m[X][T]), (int)(polygon->m[Y][T])-k); */
  /*   plot(s, top, (int)(polygon->m[X][T])+k, (int)(polygon->m[Y][T])+k); */
  /*   plot(s, top, (int)(polygon->m[X][T])-k, (int)(polygon->m[Y][T])-k); */
  /*   plot(s, top, (int)(polygon->m[X][T])+k, (int)(polygon->m[Y][T])-k); */
  /*   plot(s, top, (int)(polygon->m[X][T])-k, (int)(polygon->m[Y][T])+k); */

  /*   plot(s, mid, (int)(polygon->m[X][M]), (int)(polygon->m[Y][M])); */
  /*   plot(s, mid, (int)(polygon->m[X][M])+k, (int)(polygon->m[Y][M])); */
  /*   plot(s, mid, (int)(polygon->m[X][M])-k, (int)(polygon->m[Y][M])); */
  /*   plot(s, mid, (int)(polygon->m[X][M]), (int)(polygon->m[Y][M])+k); */
  /*   plot(s, mid, (int)(polygon->m[X][M]), (int)(polygon->m[Y][M])-k); */
  /*   plot(s, mid, (int)(polygon->m[X][M])+k, (int)(polygon->m[Y][M])+k); */
  /*   plot(s, mid, (int)(polygon->m[X][M])-k, (int)(polygon->m[Y][M])-k); */
  /*   plot(s, mid, (int)(polygon->m[X][M])+k, (int)(polygon->m[Y][M])-k); */
  /*   plot(s, mid, (int)(polygon->m[X][M])-k, (int)(polygon->m[Y][M])+k); */

  /*   plot(s, bot, (int)(polygon->m[X][B]), (int)(polygon->m[Y][B])); */
  /*   plot(s, bot, (int)(polygon->m[X][B])+k, (int)(polygon->m[Y][B])); */
  /*   plot(s, bot, (int)(polygon->m[X][B])-k, (int)(polygon->m[Y][B])); */
  /*   plot(s, bot, (int)(polygon->m[X][B]), (int)(polygon->m[Y][B])+k); */
  /*   plot(s, bot, (int)(polygon->m[X][B]), (int)(polygon->m[Y][B])-k); */
  /*   plot(s, bot, (int)(polygon->m[X][B])+k, (int)(polygon->m[Y][B])+k); */
  /*   plot(s, bot, (int)(polygon->m[X][B])-k, (int)(polygon->m[Y][B])-k); */
  /*   plot(s, bot, (int)(polygon->m[X][B])+k, (int)(polygon->m[Y][B])-k); */
  /*   plot(s, bot, (int)(polygon->m[X][B])-k, (int)(polygon->m[Y][B])+k); */
    
  /* } */

  printf("T: %d\n", T);
  printf("M: %d\n", M);
  printf("B: %d\n", B);
  printf("top: %.2f\tmiddle: %.2f\t bottom: %.2f\n", polygon->m[Y][T], polygon->m[Y][M], polygon->m[Y][B]);
  double y = polygon->m[Y][T] - polygon->m[Y][B];
  int dy = 1;

  double x0 = polygon->m[X][T] - polygon->m[X][B];
  double xd0 = ( polygon->m[Y][T] - polygon->m[Y][B])?
    ( x0 / (polygon->m[Y][T] - polygon->m[Y][B]) ): 0;
  
  double x1 = polygon->m[X][T] - polygon->m[X][M];
  double xd1 = ( polygon->m[Y][T] - polygon->m[Y][M] )?
    ( x1 / (polygon->m[Y][T] - polygon->m[Y][M]) ): 0;

  double x2 = x0 - x1;
  double xd2 = ( polygon->m[Y][M] - polygon->m[Y][B] )?
    ( x2 / (polygon->m[Y][M] - polygon->m[Y][B]) ): x2;
  
  /* printf( "%.2f\n",  ( polygon->m[Y][T] - polygon->m[Y][B])? */
  /* 	  ( x0 / (polygon->m[Y][T] - polygon->m[Y][B]) ): 1 ); */
  
  /* printf( "%.2f\n", ( polygon->m[Y][T] - polygon->m[Y][M] )? */
  /* 	  ( x1 / (polygon->m[Y][T] - polygon->m[Y][M]) ): 1 ); */
  

  printf("y: %.2f\tdy: %d\tx0: %.2f\txd0: %.2f\tx1: %.2f\txd1: %.2f\tx2: %.2f\txd2: %.2f\n", y, dy, x0, xd0, x1, xd1, x2, xd2);

  int yy;
  double xA, xB;

  //if (! x1 ) xd1 *= -1;
  //if (! x2 ) xd2 *= -1;
  
  for (yy = polygon->m[Y][B], xA = polygon->m[X][B], xB = polygon->m[X][B];
       yy < polygon->m[Y][T];
       yy+=dy) {
    
    draw_line( xA, yy, xB, yy, s, c ) ;
    printf("drawing line (%.2f, %d) to (%.2f, %d)\n", xA, yy, xB, yy);
    xA += xd0;
    
    if ( yy <= polygon->m[Y][M] )
      xB += xd2;
    else
      xB += xd1;

  }
}


/*======== void draw_polygons() ==========
Inputs:   struct matrix *polygons
          screen s
          color c  
Returns: 
Goes through polygons 3 points at a time, drawing 
lines connecting each points to create bounding
triangles
====================*/
void draw_polygons( struct matrix *polygons, screen s, color c ) {
  if ( polygons->lastcol < 3 ) {
    printf("Need at least 3 points to draw a polygon!\n");
   return;
  }
  
  int point;
  struct matrix * normal = NULL;
  for (point=0; point < polygons->lastcol-2; point+=3) {
    normal = generate_normal( polygons, point );
    //printf("\npolygon #%d...z of normal: %f", point, normal->m[Z][0]);

    if ( normal->m[Z][0] >= 0 ) {
      printf("before scan, point: %d of %d\n", point, polygons->lastcol);
      scanline( polygons, point, s );
      printf("after scan\n");
      draw_line( polygons->m[0][point],
		 polygons->m[1][point],
		 polygons->m[0][point+1],
		 polygons->m[1][point+1],
		 s, c );	       
      draw_line( polygons->m[0][point],
		 polygons->m[1][point],
		 polygons->m[0][point+2],
		 polygons->m[1][point+2],
		 s, c );	       
      draw_line( polygons->m[0][point+2],
		 polygons->m[1][point+2],
		 polygons->m[0][point+1],
		 polygons->m[1][point+1],
		 s, c );	       
      printf("after drawigng lines\n");
    }
  }
  printf("after loop\n");
}

/*======== void add_box() ==========
  Inputs:   struct matrix * edges
            double x
	    double y
	    double z
	    double width
	    double height
	    double depth
  Returns: 

  add the points for a rectagular prism whose 
  upper-left corner is (x, y, z) with width, 
  height and depth dimensions.
  ====================*/
void add_box( struct matrix * edges,
	      double x, double y, double z,
	      double width, double height, double depth ) {

  double x0, y0, z0, x1, y1, z1;
  x0 = x;
  x1 = x+width;
  y0 = y;
  y1 = y-height;
  z0 = z;
  z1 = z-depth;

  //front
  add_polygon( edges,
	       x0, y0, z0,
	       x0, y1, z0,
	       x1, y0, z0 );
  add_polygon( edges,
	       x0, y1, z0,
	       x1, y1, z0, 
	       x1, y0, z0 );
  
  //right side
  add_polygon( edges,
	       x1, y1, z0,
	       x1, y0, z1,
	       x1, y0, z0 );
  add_polygon( edges,
	       x1, y1, z0,
	       x1, y1, z1, 
	       x1, y0, z1 );
  
  //left side
  add_polygon( edges,
  	       x0, y0, z0,
  	       x0, y1, z1,
  	       x0, y1, z0 );
  add_polygon( edges,
  	       x0, y0, z0,
  	       x0, y0, z1,
  	       x0, y1, z1 );
  //top
  add_polygon( edges,
  	       x1, y0, z0,
  	       x1, y0, z1,
  	       x0, y0, z1 );
  add_polygon( edges,
  	       x1, y0, z0,
  	       x0, y0, z1,
  	       x0, y0, z0 );
  //bottom
  add_polygon( edges,
  	       x1, y1, z0,
  	       x0, y1, z0,
  	       x0, y1, z1 );
  add_polygon( edges,
  	       x1, y1, z0,
  	       x0, y1, z1,
  	       x1, y1, z1 );
  //back
  add_polygon( edges,
  	       x1, y0, z1,
  	       x1, y1, z1,
  	       x0, y1, z1 );
  add_polygon( edges,
  	       x1, y0, z1,
  	       x0, y1, z1,
  	       x0, y0, z1 );

}

/*======== void add_sphere() ==========
  Inputs:   struct matrix * points
            double cx
	    double cy
	    double cz
	    double r
	    double step  
  Returns: 

  adds all the points for a sphere with center 
  (cx, cy, cz) and radius r.

  should call generate_sphere to create the
  necessary points
  ====================*/
void add_sphere( struct matrix * edges, 
		 double cx, double cy, double cz,
		 double r, double step ) {
  struct matrix * points = generate_sphere( cx, cy, cz, r, step );
  
  int i;
  int n = (1 / step) + 1;
  //n+=1;
  //i < points->lastcol - (n + 1)
  for (i = 0; i<points->lastcol - (n); i++){
    //printf("i: %d\nn: %d\n", i, n );
    if ((i+1) % (n)) {
      //printf("drawing polygon %d %d %d\n--------\n", i, i + n + 1, i + n);
      add_polygon( edges,
		   points->m[0][i], points->m[1][i], points->m[2][i], 
		   points->m[0][i + n + 1], points->m[1][i + n + 1], points->m[2][i + n + 1],
		   points->m[0][i + n], points->m[1][i + n], points->m[2][i + n]
		   );
      add_polygon( edges,
      		   points->m[0][i], points->m[1][i], points->m[2][i],
      		   points->m[0][i + 1], points->m[1][i + 1], points->m[2][i + 1],
      		   points->m[0][i + n + 1], points->m[1][i + n + 1], points->m[2][i + n + 1]
      		   );
    }
  }
}

/*======== void generate_sphere() ==========
  Inputs:   struct matrix * points
            double cx
	    double cy
	    double cz
	    double r
	    double step  
  Returns: Generates all the points along the surface 
           of a sphere with center (cx, cy, cz) and
	   radius r.
	   Returns a matrix of those points
  ====================*/
struct matrix * generate_sphere(double cx, double cy, double cz,
				double r, double step ) {
  struct matrix * pear = new_matrix(4, 0);
  int n = 1 / step;
  int i, j;
  double thy, theta, x, y, z;
  for (i = 0; i <= n; i++) {
    thy = 2 * M_PI * step * i;
    
    for (j = 0; j <= n; j++) {
      theta = M_PI * step * j;
      x = r * cos( theta ) + cx;
      y = r * sin( theta ) * cos( thy ) + cy;
      z = r * sin( theta ) * sin( thy ) + cz;
      add_point( pear, x, y, z );
      //printf("generating point (%.2f, %.2f, %.2f) on sphere\n", x, y, z);
    }
  }
  return pear;
}

/*======== void add_torus() ==========
  Inputs:   struct matrix * points
            double cx
	    double cy
	    double cz
	    double r1
	    double r2
	    double step  
  Returns: 

  adds all the points required to make a torus
  with center (cx, cy, cz) and radii r1 and r2.

  should call generate_torus to create the
  necessary points
  ====================*/
void add_torus( struct matrix * edges, 
		double cx, double cy, double cz,
		double r1, double r2, double step ) {
  struct matrix * points = generate_torus( cx, cy, cz, r1, r2, step );
  
  int i;
   int n = (1 / step) + 1;
  //n+=1;
  //i < points->lastcol - (n + 1)
  for (i = 0; i<points->lastcol - (n); i++){
    //printf("i: %d\nn: %d\n", i, n );
    if ((i+1) % (n)) {
      //printf("drawing polygon %d %d %d\n--------\n", i, i + n + 1, i + n);
      add_polygon( edges,
		   points->m[0][i], points->m[1][i], points->m[2][i], 
		   points->m[0][i + n + 1], points->m[1][i + n + 1], points->m[2][i + n + 1],
		   points->m[0][i + n], points->m[1][i + n], points->m[2][i + n]
		   );
      add_polygon( edges,
      		   points->m[0][i], points->m[1][i], points->m[2][i],
      		   points->m[0][i + 1], points->m[1][i + 1], points->m[2][i + 1],
      		   points->m[0][i + n + 1], points->m[1][i + n + 1], points->m[2][i + n + 1]
      		   );
    }
  }
}

/*======== void generate_torus() ==========
  Inputs:   struct matrix * points
            double cx
	    double cy
	    double cz
	    double r
	    double step  
  Returns: Generates all the points along the surface 
           of a torus with center (cx, cy, cz) and
	   radii r1 and r2.
	   Returns a matrix of those points
  ====================*/
struct matrix * generate_torus( double cx, double cy, double cz,
				double r1, double r2, double step ) {
  struct matrix * dough = new_matrix(4, 0);
  int n = 1 / step;
  int i, j;
  double thy, theta, x, y, z;
  for (i = 0; i <= n; i++) {
    thy = 2 * M_PI * step * i;
    
    for (j = 0; j <= n; j++) {
      theta = 2 * M_PI * step * j;
      
      x = cos(thy) * ( r1 * cos(theta) + r2) + cx;
      y = r1 * sin(theta) +  cy;
      z = -1 * sin(thy) * ( r1 * cos(theta) + r2 ) + cz;
      add_point( dough, x, y, z );
      //printf("generating point (%.2f, %.2f, %.2f) on sphere\n", x, y, z);
    }
  }
  return dough;
}

/*======== void add_circle() ==========
  Inputs:   struct matrix * points
            double cx
	    double cy
	    double r
	    double step  
  Returns: 

  Adds the circle at (cx, cy) with radius r to points
  ====================*/
void add_circle( struct matrix * points, 
		 double cx, double cy, double cz,
		 double r, double step ) {

  double lastX, lastY, x, y;
  
  lastX = r * cos( 0 ) + cx;
  lastY = r * sin( 0 ) + cy;

  double t;
  for (t = step; t < 1; t += step){
    x = r * cos( 2 * M_PI * t ) + cx;
    y = r * sin( 2 * M_PI * t ) + cy;

    add_edge( points, lastX, lastY, cz, x, y, cz );
    
    lastX = x;
    lastY = y;
  }
  
  x = r * cos( 0 ) + cx;
  y = r * sin( 0 ) + cy;
  add_edge( points, lastX, lastY, cz, x, y, cz );
}

/*======== void add_curve() ==========
Inputs:   struct matrix *points
         double x0
         double y0
         double x1
         double y1
         double x2
         double y2
         double x3
         double y3
         double step
         int type  
Returns: 

Adds the curve bounded by the 4 points passsed as parameters
of type specified in type (see matrix.h for curve type constants)
to the matrix points
====================*/
void add_curve( struct matrix *points, 
		double x0, double y0, 
		double x1, double y1, 
		double x2, double y2, 
		double x3, double y3, 
		double step, int type ) {

  //printf("add_curve: x0: %.2f\ty0: %.2f \nx1: %.2f \ty1: %.2f \nx2: %.2f \ty2:  %.2f \nx3: %.2f \ty3: %.2f\n", x0, y0, x1, y1, x2, y2, x3, y3 );
  
  struct matrix * coX = generate_curve_coefs(x0, x1, x2, x3, type);
  struct matrix * coY = generate_curve_coefs(y0, y1, y2, y3, type);
  
  double lastX, lastY, x, y;
  
  lastX = cubic_parametric( coX, 0 );
  lastY = cubic_parametric( coY, 0 );

  double t;
  for (t = step; t < 1; t += step){
    
    x = cubic_parametric( coX, t );
    y = cubic_parametric( coY, t );

    add_edge( points, lastX, lastY, 0, x, y, 0 );
    //printf("adding edge (%.2f, %.2f) -> (%.2f, %.2f)\n", lastX, lastY, x, y);
    
    lastX = x;
    lastY = y;
  }
}

double cubic_parametric( struct matrix * cofs, double t ) {
  double val = 
      cofs->m[0][0] * t * t * t
    + cofs->m[1][0] * t * t 
    + cofs->m[2][0] * t 
    + cofs->m[3][0];
  return val;
}

/*======== void add_point() ==========
Inputs:   struct matrix * points
         int x
         int y
         int z 
Returns: 
adds point (x, y, z) to points and increment points.lastcol
if points is full, should call grow on points
====================*/
void add_point( struct matrix * points, double x, double y, double z) {
  points->lastcol++;
  if (points->lastcol >= points->cols)
    grow_matrix(points, points->lastcol * 2);
  int r;
  double tmp[] = {x, y, z, 1};
  for(r = 0; r < points->rows; r++)
    points->m[r][points->lastcol - 1] = tmp[r];
  
}

/*======== void add_edge() ==========
Inputs:   struct matrix * points
          int x0, int y0, int z0, int x1, int y1, int z1
Returns: 
add the line connecting (x0, y0, z0) to (x1, y1, z1) to points
should use add_point
====================*/
void add_edge( struct matrix * points, 
	       double x0, double y0, double z0, 
	       double x1, double y1, double z1) {
  add_point( points, x0, y0, z0 );
  add_point( points, x1, y1, z1 );
}

/*======== void draw_lines() ==========
Inputs:   struct matrix * points
         screen s
         color c 
Returns: 
Go through points 2 at a time and call draw_line to add that line
to the screen
====================*/
void draw_lines( struct matrix * points, screen s, color c) {

  if ( points->lastcol < 2 ) {
   printf("Need at least 2 points to draw a line!\n");
   return;
  }
  
  int point;
  for (point=0; point < points->lastcol-1; point+=2)
    draw_line( points->m[0][point],
	       points->m[1][point],
	       points->m[0][point+1],
	       points->m[1][point+1],
	      s, c);	       
}// end draw_lines

//Insert your line algorithm here
void draw_line(int x0, int y0, int x1, int y1, screen s, color c) {
  //printf("start draw line...\n");
  //printf("(%d, %d) to (%d, %d)\n", x0, y0, x1, y1);
  if (x0 > x1){
    swap( &x1, &x0 );
    swap( &y1, &y0 );
    //printf("swapping endpoints\n");
    //printf("\tnow, (%d, %d) to (%d, %d)\n", x0, y0, x1, y1);

  }
  
  int dx = x1 - x0;
  int dy = y1 - y0;

  if ( dy > 0 ) {
    if ( dx > dy ) {
      draw_line_1(x0, y0, x1, y1, s, c);
      //printf("drawing oct 1 line\n");
    }
    else {
      draw_line_2(x0, y0, x1, y1, s, c);
      //printf("drawing oct 2 line\n");
    }
  }
  else {
    dy *= -1;
    if ( dx > dy ) {
      draw_line_8(x0, y0, x1, y1, s, c);
      //printf("drawing oct 8 line\n");

    }
    else {
      draw_line_7(x0, y0, x1, y1, s, c);
      //printf("drawing oct 7 line\n");
    }
  }
}
  
void draw_line_1(int x0, int y0, int x1, int y1, screen s, color c) {
  
  int A = y1 - y0;
  int B = x0 - x1;
  
  A *= 2;
  int d = A + B;
  B *= 2;
  
  int x, y;
  for ( x = x0, y = y0; x <= x1; x++, d+=A) {
    plot(s, c, x, y);
    //printf("plotting (%d, %d)\n", x, y);
    if (d > 0){
      y++;
      d+= B;
    }
  }
}

void draw_line_2(int x0, int y0, int x1, int y1, screen s, color c) {
  
  int A = y1 - y0;
  int B = x0 - x1;
  
  B *= 2;
  int d = A + B;
  A *= 2;
  
  int x = x0;
  int y = y0;
  for ( ; y <= y1; y++, d+=B) {
    plot(s, c, x, y);
    if (d < 0){
      x++;
      d+= A;
    }
  }

}

void draw_line_7(int x0, int y0, int x1, int y1, screen s, color c) {
  
  int A = y1 - y0;
  int B = x0 - x1;
  
  B *= 2;
  int d = A - B;
  A *= 2;
  
  int x, y;
  for ( x = x0, y = y0; y >= y1; y--, d-=B) {
    plot(s, c, x, y);
    if (d > 0){
      x++;
      d+= A;
    }
  }

}

void draw_line_8(int x0, int y0, int x1, int y1, screen s, color c) {
  
  int A = y1 - y0;
  int B = x0 - x1;
  
  A *= 2;
  int d = A - B;
  B *= 2;
  
  int x, y;
  for ( x = x0, y = y0; x <= x1; x++, d+=A) {
    plot(s, c, x, y);
    if (d < 0){
      y--;
      d-= B;
    }
  }
}
