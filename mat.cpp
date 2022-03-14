#include "mat.hpp"
#include <string>
#include <iostream>
#include <vector>

using namespace std;

namespace ariel {
    string mat(int numOfCols, int numOfRows, char firstChar, char secondChar) {
        const int minPrintableChar = 33; //minimum printable character
        const int maxPrintableChar = 126; //maximum printable character
        //Input validating, throwing exception if any of the following arguments are true
        //(one or both of the numbers negative or even, one or both of the characters are special characters,
        //whitespaces or unprintable characters)
        if (numOfCols % 2 == 0 || numOfRows % 2 == 0 || firstChar == '\n' || firstChar == '\t' || firstChar == ' ' ||
            firstChar == '\r' || secondChar == '\n' || secondChar == '\t' || secondChar == ' ' || secondChar == '\r' ||
            numOfCols <= 0 || numOfRows <= 0 || firstChar < minPrintableChar || maxPrintableChar < firstChar ||
            secondChar < minPrintableChar || maxPrintableChar < secondChar) {
            throw invalid_argument("The input was not of numOfCols correct format");
        }

        vector<vector<char>> arr(numOfRows, vector<char>(numOfCols)); //initializing the 2D array
        for (int i = 0; i < (min(numOfCols, numOfRows) / 2) + 1; i++) { //filling the array layer by layer (from outer to inner).
            if (i % 2 == 0) { //if divisible by 2, then the character to put in layer is the first
                arr = fillSingleLayer(numOfCols, numOfRows, i, firstChar, arr);
            } else { //otherwise, the second
                arr = fillSingleLayer(numOfCols, numOfRows, i, secondChar, arr);
            }
        }

        string str;
        for (int i = 0; i < numOfRows; i++) { //building the string from the pseudo 2D array
            for (int j = 0; j < numOfCols; j++) {
                str += arr[i][j];
            }
            str += '\n'; //after each inner vector (the 1D array), insert a new line
        }

        return str;
    }

    vector<vector<char>> fillSingleLayer(int numOfCols, int numOfRows, int i, char charToFill, vector<vector<char>> arr) {
        /**
         * @brief A function to "fill" a single layer of the mat with the character received as input.
         * This is done by filling first the upper line of the layer, then the bottom and then the sides.
         * Although this method fills the corners of the layer several times, the advantage of readability of code, in my opinion,
         * is greater than the 4 additional iterations, and as the filling is done with the same character,
         * the result does not differ.
         */
        for (int j = i; j < numOfCols - i; j++) //filling upper row of iteration
        {
            arr[i][j] = charToFill;
        }
        for (int j = i; j < numOfCols - i; j++) //filling lower row of iteration
        {
            arr[numOfRows - i - 1][j] = charToFill;
        }
        for (int j = i; j < numOfRows - i; j++) //filling left column of iteration
        {
            arr[j][i] = charToFill;
        }
        for (int j = i; j < numOfRows - i; j++) //filling right column of iteration
        {
            arr[j][numOfCols - i - 1] = charToFill;
        }

        return arr;
    }
}
