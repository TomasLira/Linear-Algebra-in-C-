#include "MAT_DEF.h"

float **init_mat(const int rowSize, const int colSize)
{
    float **mat = (float **)malloc(rowSize * sizeof(float *));
    if (mat != NULL)
    {
        for (int i = 0; i < rowSize; i++)
        {
            mat[i] = (float *)malloc(colSize * sizeof(float));
        }
    }
    return mat;
}

MatType *init_matType()
{
    MatType *mat_struct = (MatType *)malloc(sizeof(MatType));

    if (mat_struct == NULL)
    {
        printf("Memory for the matrices Types weren't properly allocated");
        exit(1);
    }
    mat_struct->zeros = zeros;
    mat_struct->eye = eye;
    return mat_struct;
}

float **eye(float **mat, const int rowSize, const int colSize)
{
    if (rowSize != colSize)
    {
        printf("Invalid Output, Matrix is not square");
        return NULL;
    }

    for (int i = 0; i < rowSize; i++)
    {
        for (int j = 0; j < colSize; j++)
        {
            if (i == j)
            {
                mat[i][j] = 1;
            }
            else
            {
                mat[i][j] = 0;
            }
        }
    }
    return mat;
}

float **zeros(float **mat, const int rowSize, const int colSize)
{
    for (int i = 0; i < rowSize; i++)
    {
        for (int j = 0; j < colSize; j++)
        {
            mat[i][j] = 0;
        }
    }
    return mat;
}

void show_mat(float **mat, const int rowSize, const int colSize)
{
    for (int i = 0; i < rowSize; i++)
    {
        for (int j = 0; j < colSize; j++)
        {
            printf("%f\t", mat[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void free_mat(float **mat, const int rowSize)
{
    if (mat != NULL)
    {
        for (int i = 0; i < rowSize; i++)
        {
            if (mat[i] != NULL)
            {
                free(mat[i]);
            }
        }
    }
    free(mat);
}

float **insert(float **mat, const int rowSize, const int colSize, const int row_i, const int col_j, float num)
{
    if (row_i > rowSize || col_j > colSize)
    {
        printf("Invalid Input!");
        exit(1);
    }
    mat[row_i][col_j] = num;
    return mat;
}

float **transpose(float **mat, const int rowSize, const int colSize)
{
    float **new_mat = init_mat(colSize, rowSize);

    for (int i = 0; i < rowSize; i++)
    {
        for (int j = 0; j < colSize; j++)
        {
            new_mat[j][i] = mat[i][j];
        }
    }
    return new_mat;
}

int find(float **mat, const int rowSize, const int colSize, const int fixed_idx, int type = 0)
{
    int max_idx = 0;
    if (type == 0 && fixed_idx < colSize)
    {
        for (int i = 0; i < rowSize; i++)
        {
            if (mat[i][fixed_idx] > mat[max_idx][fixed_idx])
            {
                max_idx = i;
            }
        }
    }
    else if (type == 1 && fixed_idx < rowSize)
    {
        for (int j = 0; j < colSize; j++)
        {
            if (mat[fixed_idx][j] > mat[fixed_idx][max_idx])
            {
                max_idx = j;
            }
        }
    }
    else
    {
        printf("Invalid Input!");
        exit(1);
    }
    return max_idx;
}

void swap_rows(float **mat, const int rowSize, const int colSize, const int row1, const int row2)
{
    float tmp_var = 0;
    for (int j = 0; j < colSize; j++)
    {
        tmp_var = mat[row2][j];
        mat[row2][j] = mat[row1][j];
        mat[row1][j] = tmp_var;
    }
}

void swap_cols(float **mat, const int rowSize, const int colSize, const int col1, const int col2)
{
    float tmp_var = 0;
    for (int i = 0; i < rowSize; i++)
    {
        tmp_var = mat[i][col2];
        mat[i][col2] = mat[i][col1];
        mat[i][col1] = tmp_var;
    }
}

void free_matType(MatType **mat)
{
    if (*mat != NULL && *mat != NULL)
    {
        free(*mat);
        *mat = NULL;
    }
}
