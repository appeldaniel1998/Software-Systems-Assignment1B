#include <string>
#include <vector>
using namespace std;

namespace ariel
{
    string mat(int numOfCols, int numOfRows, char firstChar, char secondChar);
    vector<vector<char>> fillSingleLayer(int numOfCols, int numOfRows, int i, char charToFill, vector<vector<char>> arr);
}