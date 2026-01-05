#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

/*
 * ------------------------------------------------------------
 * Algorithm Challenge – Level 3 | #20 Palindrome Matrix (3x3)
 *
 * This program checks whether a matrix is a palindrome.
 * A matrix is considered palindrome if each row reads the same from left to right and from right to left.
 *
 * Core concepts:
 * - Symmetry in matrix structures
 * - Two-pointer comparison technique
 * - Early termination for efficiency
 * - Understanding palindromes beyond strings
 *
 * Author: Ahmad Sindi
 * Language: C++
 * ------------------------------------------------------------
 */

// Prints a matrix in a formatted layout
void PrintMatrix(int Matrix1[3][3], short Rows, short Colms)
{
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Colms; j++)
        {
            cout << setw(3) << Matrix1[i][j] << "  ";
        }
        cout << endl;
    }
}

// Checks whether the matrix is palindrome row-wise
bool IsPalindromeMatrix(int Matrix1[3][3], short Rows, short Colms)
{
    /*
     * The idea:
     * Compare elements from left and right simultaneously.
     * If all corresponding elements match, the row is palindrome.
     * Only half of the row needs to be checked.
     */
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Colms / 2; j++)
        {
            // Compare symmetric elements
            if (Matrix1[i][j] != Matrix1[i][Colms - 1 - j])
                return false;
        }
    }
    return true;
}

int main()
{
    // Palindrome example
    int Matrix1[3][3] = {
        {1, 7, 1},
        {5, 5, 5},
        {8, 2, 8}};

    // Non-palindrome example
    // int Matrix1[3][3] = {
    //     {7, 4, 1},
    //     {5, 5, 5},
    //     {8, 2, 8}
    // };

    cout << "Matrix:\n";
    PrintMatrix(Matrix1, 3, 3);

    if (IsPalindromeMatrix(Matrix1, 3, 3))
        cout << "\nYes: Matrix is Palindrome.\n";
    else
        cout << "\nNo: Matrix is NOT Palindrome.\n";

    return 0;
}
