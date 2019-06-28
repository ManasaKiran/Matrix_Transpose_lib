#include "mtx_multiplication.h"

namespace matrix {

mtx_multiplication::mtx_multiplication()
{

}

int **mtx_multiplication::perform_transpose(int row, int col, int **matrix)
{
//    for(int i=0; i<row; i++)
//    {
//        for(int j=0; j<col; j++)
//        {
//            std::cout<<matrix[i][j]<<"\t";
//        }
//        std::cout<<"\n";
//    }
    int **result;
    result = new int*[row];
    for(int i=0; i<col;i++)
    {
        result[i] = new int[row];
    }
    std::thread mythreads[col];
    for(int i= 0; i<col; i++)
    {
        mythreads[i] = std::thread(&mtx_multiplication::perform_transpose_by_index,this,row,i,matrix,result);
    }
    for(int i=0; i<col; i++)
    {
        mythreads[i].join();
    }

    return result;
}

void mtx_multiplication::perform_transpose_by_index(int row, int index, int **matrix, int **res)
{
    for(int i=0; i<row;i++)
    {

        res[index][i] = matrix[i][index] ;
    }
}

int **mtx_multiplication::perform_matrix_multiplication(int r1, int c1, int r2, int c2, int **matrix1, int **matrix2)
{
    int **res;
    res = new int*[r2];
    for(int i=0; i<r1; i++)
    {
        res[i]= new int[r2];
    }
    int **temp_mat = mtx_multiplication::perform_transpose(r2,c2,matrix2);
    std::thread my_threads[r1];
    for(int i=0; i<r1;i++)
    {
      // mtx_multiplication::perform_mult_by_index(i,r1,c2,matrix1,temp_mat,res);
       my_threads[i] = std::thread(&mtx_multiplication::perform_mult_by_index,this,i,c1,c2,matrix1,temp_mat,res);
    }
    for(int i=0; i<r1; i++)
    {
        my_threads[i].join();
    }

    return res;
}

void mtx_multiplication::perform_mult_by_index(int index,int r1, int c2, int **matrix1, int **matrix2, int **res)
{
    int sum = 0;
    for(int i= 0; i<c2;i++)
    {
        sum = 0;
        for(int j=0; j<r1; j++)
        {
            sum = sum+(matrix1[index][j]*matrix2[i][j]);
        }

        res[index][i] = sum;

    }
}



}

