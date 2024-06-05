# TESTS

We started testing the provided library against a set of expected mathmeatical proprieties for the matrix multiplication operation. From these we were able to catch the errors inserted in the code.

## Test 0 (provided)
This is the classical example of multiplication. There are no constraints.

$$
\begin{bmatrix} 
8 & 2 & 3\\
4 & 5 & 8
\end{bmatrix}
\begin{bmatrix}
7 & 8 \\
9 & 10 \\
11 & 12 
\end{bmatrix}
$$

We got

$$
Res = 
\begin{bmatrix}
2077 & 127 \\
169 & 184 \\
\end{bmatrix}
\neq
\begin{bmatrix}
107 & 120 \\
161 & 178 \\
\end{bmatrix} = Expected
$$
and we were able to catch the following errors:

```
Error 6: Result matrix contains a number bigger than 100!
Error 6: Result matrix contains a number bigger than 100!
Error 6: Result matrix contains a number bigger than 100!
Error 6: Result matrix contains a number bigger than 100!
Error 12: The number of rows in A is equal to the number of columns in B!
Error 14: The result matrix C has an even number of rows!
Error 19: Every row in matrix A contains the number 8!
Error 20: Number of columns in matrix A is odd!
```
we understand erros come from structure of matrix or from its elements.

## Test 1 - Identity multiplication
The test's aim is to verify the correctness of the simplest type of multiplication. It wants to test the neutral element.

$$
\begin{bmatrix} 
99 & 6 & 12\\
14 & 99 & 16\\
17 & 18 & 11
\end{bmatrix}
\begin{bmatrix}
1 & 0 & 0\\
0 & 1 & 0\\
0 & 0 & 1
\end{bmatrix}
$$

Our expected result was the left operand of the matrix multiplication. This test was failed getting:
$$
\begin{bmatrix}
2025 & 6 & 19\\
17 & 109 &18\\ 
20 & 26 &11 
\end{bmatrix}
$$
and we were able to catch the following errors:

```
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

```
the simplest multiplication fails. It is difficult that more sofisticated types of multiplication are correct. Previous errors are about matrix structure and matrix elements.

## Test 2 - Zero multiplication
The test aims to verify the existence of the null multiplication element.

$$
\begin{bmatrix} 
1 & 1 & 1\\
5 & 5 & 5\\
1 & 0 & 1
\end{bmatrix}
\begin{bmatrix}
0 & 0 & 0\\
0 & 0 & 0\\
0 & 0 & 0
\end{bmatrix}
$$

Our expected result was the zero matrix. This test was failed getting:
$$
\begin{bmatrix}
1987 & 3 & 7\\
2 & 9 & 8 \\
10 & 3 & 1
\end{bmatrix}
$$
and we were able to catch the following errors:

```
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
```

results show the that zero matrix is not the null multiplication element.


## Test 3 - Negative numbers
The test aims to discover eventually changing when matrix is composed of negative numbers:

$$
\begin{bmatrix} 
-1 & 2 & 3\\
4 & -5 & -6
\end{bmatrix}
\begin{bmatrix}
7 & -8 \\
-9 & 1000000 \\
-11 & 12 
\end{bmatrix}
$$


$$
Res = 
\begin{bmatrix}
2066 & 2000064\\
154 & -5000090
\end{bmatrix}
\neq
\begin{bmatrix}
-58 & 2000044\\
139 & -5000104
\end{bmatrix} = Expected
$$

The result is still wrong and we were able to catch the following errors:

```
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
Error 20: Number of columns in matrix A is odd!
```

## Test 4 - Transpose multiplication 
The last test try to find a relation between a matrix and its transpose:
$$
\begin{bmatrix} 
1 & 2 & 3\\
4 & 5 & 6\\
7 & 8 & 9
\end{bmatrix}
\begin{bmatrix}
1 & 4 & 7 \\
2 & 5 & 8 \\
3 & 6 & 9 
\end{bmatrix}
$$


$$
Res = 
\begin{bmatrix}
1999 & 32 & 50 \\
37 & 77 & 130 \\
63 & 139 & 206
\end{bmatrix}
\neq
\begin{bmatrix}
14 & 32 & 50 \\
32 & 77 & 122 \\
50 & 122 & 194
\end{bmatrix} = Expected
$$

The result is still wrong and we were able to catch the following errors:

```

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
Error 20: Number of columns in matrix A is odd!
```
