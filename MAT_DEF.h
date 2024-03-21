#ifndef MAT_DEF_H
#define MAT_DEF_H
#include <stdlib.h>
#include <stdio.h>
#include <random>
#include <time.h>

float **init_mat(const int rowSize, const int colSize);
void free_mat(float **mat, const int rowSize);

void show_mat(float **mat, const int rowSize, const int colSize);

float **zeros(float **mat, const int rowSize, const int colSize);
float **eye(float **mat, const int rowSize, const int colSize);

typedef float **(*zerosPtr)(float **, const int, const int);
typedef float **(*eyePtr)(float **, const int, const int);

typedef struct mat_type
{
    eyePtr eye;
    zerosPtr zeros;
} MatType;

MatType *init_matType();
void free_matType(MatType **mat);


float  **insert(float **mat,const int rowSize, const int colSize,const int row_i,const int col_j, float num);
float **find(float **mat,const int rowSize,const int fixed_idx, int type);
void swap_rows(float **mat, const int rowSize, const int colSize, const int row1, const int row2);
void swap_cols(float **mat, const int rowSize, const int colSize, const int col1, const int col2);


#endif
