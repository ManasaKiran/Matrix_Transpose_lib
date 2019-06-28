#ifndef MTX_MULTIPLICATION_H
#define MTX_MULTIPLICATION_H
#include <thread>
#include <iostream>
namespace matrix {
class mtx_multiplication
{
private:
    /* transpose thread
     * @param input: row, column, matrix, pointer for result
     * @param output : res
     */
    void perform_transpose_by_index(int row, int col, int **matrix, int **res);
    /* multiplication thread
     * @param input: column, row2, column2, matrix1, matrix2, pointer for result
     * @param output : res
     */
    void perform_mult_by_index(int index, int r2, int c2, int **matrix1, int **matrix2, int **res);
public:
    mtx_multiplication();
    /* transpose function
     * @param input: row, column, matrix
     * @param output : result matrix
     */
    int** perform_transpose(int row, int col, int **matrix);
    /* mutiplication method
     * @param input: row1, column1,row2,colum2, matrix1,matrix2
     * @param output : result
     */
    int** perform_matrix_multiplication(int r1, int c1, int r2, int c2, int **matrix1, int **matrix2);

};
}


#endif // MTX_MULTIPLICATION_H
