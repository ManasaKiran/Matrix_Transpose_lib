#ifndef MATRIX_GEN_H
#define MATRIX_GEN_H
#include "responsecode.h"
#include "mtx_multiplication.h"
/*
 Assumptions : input of the matrix is int or float points only
                not big integers
*/

namespace matrix {
class matrix_gen
{
public:
    matrix_gen();
    /*
       default input for transponse is matrix1
       martrix1 input method
       @param input: {row,col,matrix1}
     */
    void input_matrix_1(int row = 0, int col= 0,int **matrix1 = nullptr);
    /*
       martrix2 input method
       @param input: {row,col,matrix1}
     */
    void input_matrix_2(int row = 0,int col = 0,int **matrix2 = nullptr);
    /*initalize mtrix for functionality required
     * @param input : required out matrix ex: multiplication / transponse
     * @param output: response code
     */
    matrix::resposecode matrix_init(matrix::resposecode response_type = resposecode::PERFORM_TRANSPONSE);

    /* returns output matrix according the input in previous steps
     * @param output:{output matrix pointer}
     */
    int ** maxtrix_result();
protected:
    int row1;
    int row2;
    int col1;
    int col2;
    int **max1;
    int **max2;
    int **result;
    std::unique_ptr<matrix::mtx_multiplication> transpose;
    matrix::resposecode result_type = resposecode::PERFORM_TRANSPONSE;
};
}

#endif // MATRIX_GEN_H
