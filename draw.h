#ifndef DRAW_H
#define DRAW_H

#include "matrix.h"
#include "ml6.h"


//polygon organization
void add_polygons( struct matrix * points, 
		   double x0, double y0, double z0, 
		   double x1, double y1, double z1,
		   double x2, double y2, double z2);
void draw_polygons( struct matrix * points, screen s, color c);
struct matrix * generate_normal( struct matrix * polygon, int point );

//3d shapes
void add_box( struct matrix * edges,
	      double x, double y, double z,
	      double width, double height, double depth );
void add_sphere( struct matrix * edges, 
		 double cx, double cy, double cz,
		 double r, double step );
struct matrix * generate_sphere(double cx, double cy, double cz,
				double r, double step );
void add_torus( struct matrix * edges, 
		double cx, double cy, double cz,
		double r1, double r2, double step );
struct matrix * generate_torus( double cx, double cy, double cz,
				double r1, double r2, double step );

//advanced shapes
void add_circle( struct matrix * edges, 
		 double cx, double cy, double cz,
		 double r, double step );
void add_curve( struct matrix *edges, 
		double x0, double y0,
		double x1, double y1,
		double x2, double y2,
		double x3, double y3,
		double step, int type );

double cubic_parametric( struct matrix * cos, double t );
void add_point( struct matrix * points, double x, double y, double z);
void add_edge( struct matrix * points, 
	       double x0, double y0, double z0, 
	       double x1, double y1, double z1);
void draw_lines( struct matrix * points, screen s, color c);
void draw_line(int x0, int y0, int x1, int y1, screen s, color c);
void draw_line_1(int x0, int y0, int x1, int y1, screen s, color c);
void draw_line_2(int x0, int y0, int x1, int y1, screen s, color c);
void draw_line_7(int x0, int y0, int x1, int y1, screen s, color c);
void draw_line_8(int x0, int y0, int x1, int y1, screen s, color c);

#endif
