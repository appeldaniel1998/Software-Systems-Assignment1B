#include "doctest.h"
#include "mat.hpp"
using namespace ariel;

#include <string>
#include <algorithm>
using namespace std;

TEST_CASE("Invalid Input")
{
    CHECK_THROWS(mat(10, 5, '$', '%')); //1st number even
    CHECK_THROWS(mat(5, 10, '$', '%')); //2nd number even
    CHECK_THROWS(mat(6, 10, '$', '%')); //both numbers even
    CHECK_THROWS(mat(5, -1, '$', '%')); //2nd number negative
    CHECK_THROWS(mat(-1, 5, '$', '%')); //1st number negative
    CHECK_THROWS(mat(-1, -3, '$', '%')); //both numbers negative
    CHECK_THROWS(mat(5, 5, '!', ' ')); //one symbol is a whitespace (unacceptable)
}

TEST_CASE("Valid Input: Basic Correct Outputs") 
{
    CHECK(mat(3, 5, '$', '%') == "$$$\n" //simple input 1
                                 "$%$\n"
                                 "$%$\n"
                                 "$%$\n"
                                 "$%$");
                                 
    CHECK(mat(5, 3, '$', '%') == "$$$$$\n" //simple input 2
                                 "$%%%$\n"
                                 "$$$$$");

    CHECK(mat(5, 3, '!', '-') == "!!!!!\n" //simple input 2 with different characters
                                 "!---!\n"
                                 "!!!!!");
}

TEST_CASE("Valid Input: Multiple Layers Correct Outputs")
{
    CHECK(mat(7, 7, '!', '-') == "!!!!!!!\n" //test of multiple layers - square matrix
                                 "!-----!\n"
                                 "!-!!!-!\n"
                                 "!-!-!-!\n"
                                 "!-!!!-!\n"
                                 "!-----!\n"
                                 "!!!!!!!");

    CHECK(mat(7, 9, '!', '-') == "!!!!!!!\n" //test of multiple layers - rectangle (non square) matrix - More Rows
                                 "!-----!\n"
                                 "!-!!!-!\n"
                                 "!-!-!-!\n"
                                 "!-!-!-!\n"
                                 "!-!-!-!\n"
                                 "!-!!!-!\n"
                                 "!-----!\n"
                                 "!!!!!!!");

    CHECK(mat(9, 7, '!', '-') == "!!!!!!!!!\n" //test of multiple layers - rectangle (non square) matrix - More Columns
                                 "!-------!\n"
                                 "!-!!!!!-!\n"
                                 "!-!---!-!\n"
                                 "!-!!!!!-!\n"
                                 "!-------!\n"
                                 "!!!!!!!!!");
}

TEST_CASE("Valid Input: Incorrect Answers")
{
    CHECK(mat(9, 7, '!', '-') != "!!!!!!!!!\n" //missing a single '!'
                                 "!-------!\n"
                                 "!-!!!!!-!\n"
                                 "!-!---!-!\n"
                                 "!-!!!!!-!\n"
                                 "!-------!\n"
                                 "!!!!!!!!");

    CHECK(mat(9, 7, '!', '-') != "!!!!!!!!!" //missing '\n'
                                 "!-------!\n"
                                 "!-!!!!!-!\n"
                                 "!-!---!-!\n"
                                 "!-!!!!!-!\n"
                                 "!-------!\n"
                                 "!!!!!!!!!");
    
    CHECK(mat(3, 3, '!', '-') != "---" //The order of the characters was changes
                                 "!-!"
                                 "---");

    CHECK(mat(1, 1, '!', '-') != "-"); //The single character returned was not the correct one

    CHECK(mat(7, 7, '!', '-') == "!!!!!!!\n" // middle character was not correct
                                 "!-----!\n"
                                 "!-!!!-!\n"
                                 "!-!-!-!\n"
                                 "!-!!!-!\n"
                                 "!-----!\n"
                                 "!!!!!!!");
}

TEST_CASE("Valid Input: Edge Cases")
{
    CHECK(mat(1, 1, '$', '%') == "$"); //1 by 1 test case
    CHECK(mat(1, 1, '-', '!') == "-"); //1 by 1 with different characters
    CHECK(mat(5, 5, '!', '!') == "!!!!!\n" //same 1st and 2nd character
                                 "!!!!!\n"
                                 "!!!!!\n"
                                 "!!!!!\n"
                                 "!!!!!");
}