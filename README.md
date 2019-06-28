# Matrix_Transpose_lib

Clone the repository and run the make file 

            
Things considered:
   1. avoided L1 and L2 cache misses by taking the inputs in terms of blocks
   2. Used threads for faster commutation which might conflict with point made above. 
   
Limitation: 
   1. Currently build only for interger values 
   2. File input not supported 
   3. Output matrix size i.e M and N values are not outputted 
   4. Mutexes are not implimented because same memory block happening at any point of time. 
