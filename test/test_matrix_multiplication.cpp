#include "matrix_multiplication.h"
#include <iostream>
#include <vector>
#include <gtest/gtest.h>

// ######################### Source code of multiplyMatrices in src/matrix_mult




/*This is the classical example of multiplication. There are no constraints.
we were able to catch the following errors:

Error 6: Result matrix contains a number bigger than 100!
Error 6: Result matrix contains a number bigger than 100!
Error 6: Result matrix contains a number bigger than 100!
Error 6: Result matrix contains a number bigger than 100!
Error 12: The number of rows in A is equal to the number of columns in B!
Error 14: The result matrix C has an even number of rows!
Error 19: Every row in matrix A contains the number 8!
Error 20: Number of columns in matrix A is odd!

we understand erros come from structure of matrix or from its elements.*/

TEST(MatrixMultiplicationTest, TestMultiplyMatrices) {
    std::vector<std::vector<int>> A = {
        {8, 2, 3},
        {4, 5, 8}
    };
    std::vector<std::vector<int>> B = {
        {7, 8},
        {9, 10},
        {11, 12}
    };
    std::vector<std::vector<int>> C(2, std::vector<int>(2, 0));

    multiplyMatrices(A, B, C, 2, 3, 2);

    std::vector<std::vector<int>> expected = {
        {107, 120},
        {161, 178}
    };

    ASSERT_EQ(C, expected) << "Matrix multiplication test failed! :(((()";
}






/*The test's aim is to verify the correctness of the simplest type of multiplication. It wants to test the neutral element.
we were able to catch the following errors:

Error 9: Result matrix contains the number 99!
Error 7: Result matrix contains a number between 11 and 20!
Error 7: Result matrix contains a number between 11 and 20!
Error 9: Result matrix contains the number 99!
Error 7: Result matrix contains a number between 11 and 20!
Error 7: Result matrix contains a number between 11 and 20!
Error 7: Result matrix contains a number between 11 and 20!
Error 11: Every row in matrix B contains at least one '0'!
Error 12: The number of rows in A is equal to the number of columns in B!
Error 17: Result matrix C contains the number 17!
Error 18: Matrix A is a square matrix!
Error 20: Number of columns in matrix A is odd!

the simplest multiplication fails. It is difficult that more sofisticated types of multiplication are correct. Previous errors are about matrix structure and matrix elements.*/


TEST(MatrixMultiplicationTest, TestMultiplyIdentity) {
    std::vector<std::vector<int>> A = {
        {99, 6, 12},
        {14, 99, 16},
        {17, 18, 11}
    };
    std::vector<std::vector<int>> B = {
        {1, 0, 0},
        {0, 1, 0},
        {0, 0, 1}
    };
    std::vector<std::vector<int>> C(3, std::vector<int>(3, 0));

    multiplyMatrices(A, B, C, 3, 3, 3);

    std::vector<std::vector<int>> expected = {
        {99, 6, 12},
        {14, 99, 16},
        {17, 18, 11}
    };

    ASSERT_EQ(C, expected) << "Matrix multiplication test failed! :(((()";
}







/*The test aims to verify the existence of the null multiplication element.
we were able to catch the following errors:

Error 8: Result matrix contains zero!
Error 8: Result matrix contains zero!
Error 8: Result matrix contains zero!
Error 8: Result matrix contains zero!
Error 8: Result matrix contains zero!
Error 8: Result matrix contains zero!
Error 8: Result matrix contains zero!
Error 8: Result matrix contains zero!
Error 8: Result matrix contains zero!
Error 10: A row in matrix A contains more than one '1'!
Error 11: Every row in matrix B contains at least one '0'!
Error 12: The number of rows in A is equal to the number of columns in B!
Error 15: A row in matrix A is filled entirely with 5s!
Error 18: Matrix A is a square matrix!
Error 20: Number of columns in matrix A is odd!

results show the that zero matrix is not the null multiplication element.*/



TEST(MatrixMultiplicationTest, TestMultipyZeros) {
    std::vector<std::vector<int>> A = {
        {1, 1, 1},
        {5, 5, 5},
        {1, 0, 1}
    };
    std::vector<std::vector<int>> B = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}
    };
    std::vector<std::vector<int>> C(3, std::vector<int>(3, 0));

    multiplyMatrices(A, B, C, 3, 3, 3);

    std::vector<std::vector<int>> expected = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}
    };

    ASSERT_EQ(C, expected) << "Matrix multiplication test failed! :(((()";
}









/*The test aims to discover eventually changing when matrix is composed of negative numbers:
The result is still wrong and we were able to catch the following errors:

Error 3: Matrix A contains a negative number!
Error 5: Matrix B contains a negative number!
Error 5: Matrix B contains a negative number!
Error 3: Matrix A contains a negative number!
Error 5: Matrix B contains a negative number!
Error 6: Result matrix contains a number bigger than 100!
Error 3: Matrix A contains a negative number!
Error 5: Matrix B contains a negative number!
Error 3: Matrix A contains a negative number!
Error 5: Matrix B contains a negative number!
Error 6: Result matrix contains a number bigger than 100!
Error 5: Matrix B contains a negative number!
Error 3: Matrix A contains a negative number!
Error 3: Matrix A contains a negative number!
Error 12: The number of rows in A is equal to the number of columns in B!
Error 14: The result matrix C has an even number of rows!
Error 20: Number of columns in matrix A is odd!*/



TEST(MatrixMultiplicationTest, TestNegativeNumbers) {
    std::vector<std::vector<int>> A = {
        {-1, 2, 3},
        {4, -5, -6}
    };
    std::vector<std::vector<int>> B = {
        {7, -8},
        {-9, 1000000},
        {-11, 12}
    };
    std::vector<std::vector<int>> C(2, std::vector<int>(2, 0));

    multiplyMatrices(A, B, C, 2, 3, 2);

    std::vector<std::vector<int>> expected = {
        {-58, 2000044},
        {139, -5000104}
    };

    ASSERT_EQ(C, expected) << "Matrix multiplication test failed! :(((()";
}












/*The last test try to find a relation between a matrix and its transpose:
The result is still wrong and we were able to catch the following errors:


Error 1: Element-wise multiplication of ones detected!
Error 4: Matrix B contains the number 3!
Error 4: Matrix B contains the number 3!
Error 6: Result matrix contains a number bigger than 100!
Error 2: Matrix A contains the number 7!
Error 4: Matrix B contains the number 3!
Error 2: Matrix A contains the number 7!
Error 6: Result matrix contains a number bigger than 100!
Error 2: Matrix A contains the number 7!
Error 6: Result matrix contains a number bigger than 100!
Error 12: The number of rows in A is equal to the number of columns in B!
Error 13: The first element of matrix A is equal to the first element of matrix B!
Error 16: Matrix B contains the number 6!
Error 18: Matrix A is a square matrix!
Error 20: Number of columns in matrix A is odd!*/

TEST(MatrixMultiplicationTest, TestMultiplyTranspose) {
    std::vector<std::vector<int>> A = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    std::vector<std::vector<int>> B = {
        {1, 4, 7},
        {2, 5, 8},
        {3, 6, 9}
    };
    std::vector<std::vector<int>> C(3, std::vector<int>(3, 0));

    multiplyMatrices(A, B, C, 3, 3, 3);

    std::vector<std::vector<int>> expected = {
        {14, 32, 50},
        {32, 77, 122},
        {50, 122, 194}
    };
        ASSERT_EQ(C, expected) << "Matrix multiplication test failed! :(((()";
}









int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
