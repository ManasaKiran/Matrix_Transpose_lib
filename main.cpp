#include <iostream>
#include "matrix_gen.h"
#include "responsecode.h"
using namespace matrix;

int main()
{
    matrix_gen create_matrix;
    int **inp;
    inp = new int*[2];
    for(int i=0; i<2;i++)
    {
        inp[i] = new int[2];
    }
    int **inp2;
    inp2 = new int*[2];
    for(int i=0; i<2;i++)
    {
        inp2[i] = new int[2];
    }

    for(int i=0; i<2;i++)
    {  static int count = 0;
        for(int j=0; j<2; j++)
        {
            inp[i][j] = count++;
        }
    }
    for(int i=0; i<2;i++)
    {  static int count = 0;
        for(int j=0; j<2; j++)
        {
            inp2[i][j] = count++;
        }
    }

    for(int i=0; i<2;i++)
    {
        for(int j=0; j<2; j++)
        {
            std::cout<<inp[i][j]<<"\t";
        }
        std::cout<<"\n";
    }
    for(int i=0; i<2;i++)
    {
        for(int j=0; j<2; j++)
        {
            std::cout<<inp2[i][j]<<"\t";
        }
        std::cout<<"\n";
    }
    std::cout << "Hello World!" << std::endl;


    create_matrix.input_matrix_1(2,1,std::move(inp));
    create_matrix.input_matrix_2(1,2,std::move(inp2));
    resposecode rc = create_matrix.matrix_init(resposecode::PERFORM_MULTIPLICATION);
    if(rc == resposecode::MATRIX_VALIDATE_SUCCESS)
    {

        std::cout<< "successfull";
        int **res = create_matrix.maxtrix_result();
        for(int i=0; i<2;i++)
        {
            for(int j=0; j<2; j++)
            {
                std::cout<<res[i][j]<<"\t";
            }
            std::cout<<"\n";
        }
    }
    else
    {
        std::cout<<"unsuccessfull";
    }
    return 0;
}
