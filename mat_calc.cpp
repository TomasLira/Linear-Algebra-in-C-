#include "MAT_DEF.h"
#include "mat_operations.cpp"

int main()
{

    const int rowSize = 3, colSize = 3;
    float **mat = init_mat(rowSize, colSize);
    MatType *out = init_matType();

    float **a = out->eye(mat, rowSize, colSize);
    mat = insert(mat,rowSize,colSize,2,0,12);
    show_mat(a, rowSize, colSize);
    printf("%d\n",find(mat,rowSize,colSize,0,0));
    mat = transpose(mat,rowSize,colSize);
    swap_rows(mat,rowSize,colSize,0,1);
    show_mat(mat,rowSize,colSize);
    swap_cols(mat,rowSize,colSize,0,1);
    show_mat(mat,rowSize,colSize);
    free_matType(&out);
    return 0;
}