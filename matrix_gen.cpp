#include "matrix_gen.h"

namespace matrix {
matrix_gen::matrix_gen()
{

}


matrix::resposecode matrix_gen::matrix_init( matrix::resposecode response_type)
{

    result_type = response_type;
   if (response_type == resposecode::PERFORM_MULTIPLICATION)
   {
       if(row2 != 0 && col1 !=0)
       {
       if (row2 == col1 && max1 != nullptr && max2 != nullptr)
       {

           return resposecode::MATRIX_VALIDATE_SUCCESS;
       }
       }

       else {
          return resposecode::MATRIX_RC_VALIDATE_UNSUCCESS;
       }

   }
   if(response_type == resposecode::PERFORM_TRANSPONSE)
   {
       if(row1 !=0 && col1 != 0 && max1 != nullptr)
       {

       return resposecode::MATRIX_VALIDATE_SUCCESS;
       }
       else
       {
           return resposecode::TRANSPOSE_INCOMPLETE;
       }
   }

   return resposecode::UNKNOWN;

}

void matrix_gen::input_matrix_1(int row,int col,int **matrix1)
{
   std::cout<<"matrix one "<<std::endl;
   this->row1 = row;
   this->col1 = col;
   max1 = std::move(matrix1);
}

void matrix_gen::input_matrix_2(int row,int col,int **matrix2)
{
    std::cout<<"matrix two "<<std::endl;
    this->row2 = row;
    this->col2 = col;
    max2 = std::move(matrix2);

}

int **matrix_gen::maxtrix_result()
{
    if(result_type == resposecode::PERFORM_TRANSPONSE)
    {
        std::cout<<"transpose of matrix = "<<std::endl;
        int **res = transpose->perform_transpose(row1,col1,max1);

        return res;
    }

    if(result_type == resposecode::PERFORM_MULTIPLICATION)
    {
        std::cout<<"multiplicaion of matrix ="<<std::endl;
        int **res = transpose->perform_matrix_multiplication(row1,col1,row2,col2,max1,max2);

        return res;
    }

    return nullptr;
}
}



