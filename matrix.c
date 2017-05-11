#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "matrix.h"

/*======== struct matrix * make_bezier() ==========
  Inputs:   
  Returns: The correct 4x4 matrix that can be used 
  to generate the coefiecients for a bezier curve
  ====================*/
struct matrix * make_bezier() {
  struct matrix * M = new_matrix(4, 4);
  M->lastcol = 4;
  ident(M);
  M->m[0][0] = -1;
  M->m[0][1] =  3;
  M->m[0][2] = -3;
  M->m[0][3] =  1;

  M->m[1][0] =  3;
  M->m[1][1] = -6;
  M->m[1][2] =  3;
  M->m[1][3] =  0;

  M->m[2][0] = -3;
  M->m[2][1] =  3;
  M->m[2][2] =  0;
  M->m[2][3] =  0;

  M->m[3][0] =  1;
  M->m[3][1] =  0;
  M->m[3][2] =  0;
  M->m[3][3] =  0;

  return M;
}

/*======== struct matrix * make_hermite() ==========
  Inputs:   
  Returns: 

  The correct 4x4 matrix that can be used to generate
  the coefiecients for a hermite curve
  ====================*/
struct matrix * make_hermite() {
  struct matrix * M = new_matrix(4, 4);
  M->lastcol = 4;
  ident(M);
  M->m[0][0] =  2;
  M->m[0][1] = -2;
  M->m[0][2] =  1;
  M->m[0][3] =  1;

  M->m[1][0] = -3;
  M->m[1][1] =  3;
  M->m[1][2] = -2;
  M->m[1][3] = -1;

  M->m[2][0] =  0;
  M->m[2][1] =  0;
  M->m[2][2] =  1;
  M->m[2][3] =  0;

  M->m[3][0] =  1;
  M->m[3][1] =  0;
  M->m[3][2] =  0;
  M->m[3][3] =  0;

  return M;
}

/*======== struct matrix * generate_curve_coefs() ==========
  Inputs:   double p1
            double p2
	    double p3
	    double p4
	    int type
  Returns: 
  
  A matrix containing the values for a, b, c and d of the
  equation at^3 + bt^2 + ct + d for the curve defined 
  by p0, p1, p2 and p3.

  For hermite curves, p0 and p1 are endpoints, p2 and p3
  are rates of change
  
  Type determines whether the curve is bezier or hermite
  ====================*/
struct matrix * generate_curve_coefs( double p1, double p2, 
				      double p3, double p4, int type) {
  struct matrix * M = new_matrix(4, 1);
  M->lastcol = 1;
  M->m[0][0] = p1;
  M->m[1][0] = p2;
  M->m[2][0] = p3;
  M->m[3][0] = p4;
  
  struct matrix * curve = NULL;

  if ( type == BEZIER )
    curve = make_bezier();
  else if ( type == HERMITE )
    curve = make_hermite();
  else printf("INVALID VALUE FOR type\n");

  matrix_mult( curve, M );

  return M;
}
/*======== struct matrix * make_translate() ==========
Inputs:  int x
         int y
         int z 
Returns: The translation matrix created using x, y and z 
as the translation offsets.
====================*/
struct matrix * make_translate(double x, double y, double z) {
  struct matrix * M = new_matrix(4, 4);
  M->lastcol = 4;
  ident(M);
  M->m[0][3] = x;
  M->m[1][3] = y;
  M->m[2][3] = z;
  return M;
}

/*======== struct matrix * make_scale() ==========
Inputs:  int x
         int y
         int z 
Returns: The translation matrix creates using x, y and z
as the scale factors
====================*/
struct matrix * make_scale(double x, double y, double z) {
  struct matrix * M = new_matrix(4, 4);
  M->lastcol = 4;
  ident(M);
  M->m[0][0] = x;
  M->m[1][1] = y;
  M->m[2][2] = z;
  return M;
}

/*======== struct matrix * make_rotX() ==========
Inputs:  double theta

Returns: The rotation matrix created using theta as the 
angle of rotation and X as the axis of rotation.
====================*/
struct matrix * make_rotX(double theta) {
  struct matrix * M = new_matrix(4, 4);
  M->lastcol = 4;
  ident(M);
  theta *= M_PI / 180;
  M->m[1][1] = cos(theta);
  M->m[1][2] = -1 * sin(theta);
  M->m[2][1] = sin(theta);
  M->m[2][2] = cos(theta);
  return M;
}

/*======== struct matrix * make_rotY() ==========
Inputs:  double theta
         char c 
Returns: The rotation matrix created using theta as the 
angle of rotation and Y as the axis of rotation.
====================*/
struct matrix * make_rotY(double theta) {
  struct matrix * M = new_matrix(4, 4);
  M->lastcol = 4;
  ident(M);
  theta *= M_PI / 180;
  M->m[0][0] = cos(theta);
  M->m[0][2] = sin(theta);
  M->m[2][0] = -1 * sin(theta);
  M->m[2][2] = cos(theta);
  return M;
}

/*======== struct matrix * make_rotZ() ==========
Inputs:  double theta
         char c 
Returns: The rotation matrix created using theta as the 
angle of rotation and Z as the axis of rotation.
====================*/
struct matrix * make_rotZ(double theta) {
  struct matrix * M = new_matrix(4, 4);
  M->lastcol = 4;
  ident(M);
  theta *= M_PI / 180;
  M->m[0][0] = cos(theta);
  M->m[0][1] = -1 * sin(theta);
  M->m[1][0] = sin(theta);
  M->m[1][1] = cos(theta);
  return M;
}

/*-------------- void print_matrix() --------------
Inputs:  struct matrix *m 
Returns: 

print the matrix
*/
void print_matrix(struct matrix *m) {
  int i, j;
  for ( i = 0; i < m->rows; i++) {
    for ( j = 0; j < m->lastcol; j++) {
      printf("%.2f\t", m->m[i][j]);
    }
    printf("\n");
  }
}

/*-------------- void print_matrix_v() --------------
   **VERBOSE matrix print funciton**
Inputs:  struct matrix *m 
Returns: 

print the matrix with indicies of points
*/
void print_matrix_v(struct matrix *m) {
  int i, j;
  for ( i = 0; i < m->rows; i++) {
    for ( j = 0; j < m->lastcol; j++) {
      printf("%.2f(%d,%d)\t", m->m[i][j], i, j);
    }
    printf("\n");
  }
}

/*-------------- void ident() --------------
Inputs:  struct matrix *m <-- assumes m is a square matrix
Returns: 

turns m in to an identity matrix
*/
void ident(struct matrix *m) {
  int i, j;
  for (i = 0; i < m->rows; i++)
    for (j = 0; j < m->cols; j++) {
      if (i - j)
	m->m[i][j] = 0;
      else
	m->m[i][j] = 1;
    }
}//end ident


/*-------------- void scalar_mult() --------------
Inputs:  double x
         struct matrix *m 
Returns: 

multiply each element of m by x
*/
void scalar_mult(double x, struct matrix *m) {  
  int r, c;
  for (r=0; r < m->rows; r++)
    for (c=0; c < m->lastcol; c++) 
      m->m[r][c] *= x;
}//end scalar_mult


/*-------------- void matrix_mult() --------------
Inputs:  struct matrix *a
         struct matrix *b 
Returns: 

a*b -> b
*/
void matrix_mult(struct matrix *a, struct matrix *b) {
  struct matrix *tmp = new_matrix(b->rows, b->lastcol);
  tmp->lastcol = b->lastcol;
  copy_matrix(b, tmp);
  
  int r, c, J;
  for (r = 0; r < a->rows; r++) {
    for (c = 0; c < tmp->lastcol; c++) {
      b->m[r][c] = 0;
      for(J = 0; J < tmp->rows && J < a->lastcol; J++) {
	b->m[r][c] += a->m[r][J] * tmp->m[J][c];
      }
    }
  }
  free_matrix(tmp);
}

/*===============================================
  These Functions do not need to be modified
  ===============================================*/

/*-------------- struct matrix *new_matrix() --------------
Inputs:  int rows
         int cols 
Returns: 

Once allocated, access the matrix as follows:
m->m[r][c]=something;
if (m->lastcol)... 
*/
struct matrix *new_matrix(int rows, int cols) {
  double **tmp;
  int i;
  struct matrix *m;

  tmp = (double **)malloc(rows * sizeof(double *));
  for (i=0;i<rows;i++) {
      tmp[i]=(double *)malloc(cols * sizeof(double));
    }

  m=(struct matrix *)malloc(sizeof(struct matrix));
  m->m=tmp;
  m->rows = rows;
  m->cols = cols;
  m->lastcol = cols;
  //m->lastcol = 0;

  return m;
}


/*-------------- void free_matrix() --------------
Inputs:  struct matrix *m 
Returns: 

1. free individual rows
2. free array holding row pointers
3. free actual matrix
*/
void free_matrix(struct matrix *m) {

  int i;
  for (i=0;i<m->rows;i++) {
      free(m->m[i]);
    }
  free(m->m);
  free(m);
}


/*======== void grow_matrix() ==========
Inputs:  struct matrix *m
         int newcols 
Returns: 

Reallocates the memory for m->m such that it now has
newcols number of collumns
====================*/
void grow_matrix(struct matrix *m, int newcols) {
  newcols++;
  int i;
  for (i=0;i<m->rows;i++) {
    m->m[i] = realloc(m->m[i],newcols*sizeof(double));
  }
  m->cols = newcols;
}


/*-------------- void copy_matrix() --------------
Inputs:  struct matrix *a
         struct matrix *b 
Returns: 

copy matrix a to matrix b
*/
void copy_matrix(struct matrix *a, struct matrix *b) {
  int r, c;
  for (r=0; r < a->rows; r++) 
    for (c=0; c < a->lastcol; c++)  
      b->m[r][c] = a->m[r][c];  
}
