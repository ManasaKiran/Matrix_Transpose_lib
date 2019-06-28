#ifndef RESPONSECODE_H
#define RESPONSECODE_H

#pragma once
#include <string>
#include <iostream>

namespace matrix {
enum class resposecode{
  MATRIX_RC_VALIDATE_SUCCESS = 100, // checking MxN for multiplication
  MATRIX_TRANSPONSE_VALIDATED = 101, // checking transponse validity
  MATRIX_RC_VALIDATE_UNSUCCESS = 102, // MxN multiplication not possible
  MATRIX_MULTIPLICATION_SUCCESS = 103, // muplitplication complete
  MATRIX_VALIDATE_SUCCESS = 104, // matrix validation for multiplication or transpose


  PERFORM_TRANSPONSE = 201, // input to perform transpose
  PERFORM_MULTIPLICATION = 202, // input to perform multiplication


  MULTIPLICATION_SUCCESS = 301, //mutiplication completed

  TRANSPONSE_SUCCESS = 401, // transponse completed
  TRANSPOSE_INCOMPLETE = 402, //transponse

  UNKNOWN = 501, // unknown result
};
}


#endif // RESPONSECODE_H
