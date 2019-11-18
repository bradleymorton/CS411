//build.cpp by Bradley Morton, Nov 17 2019
//Created for CS411 taught by Dr. Hartman

#include <algorithm>
using std::max;
#include <vector>
using std::vector;

#include "build.hpp"




void findMaxValue(int i, int j, std::vector<std::vector<int>> & matrix)
{
    if(i != 0 && j != 0)
        {
            matrix[i][j] += matrix[i-1][j-1];
        }
        if(i !=0)
        {
            matrix[i][j] = max(matrix[i][j], matrix[i-1][j]);
        }
        if(j != 0)
        {
            matrix[i][j] = max(matrix[i][j], matrix[i][j-1]);
        }
}



int build(int w, int e, const vector<Bridge> & bridges)
{
    vector<vector<int>> matrix(w, vector<int>(e));

    for(auto i:bridges)
    {
        matrix[(i[0])][(i[1])] = max(i[2], matrix[i[0]][i[1]]);
    }

    for(int i=0; i<w; ++i) //not using auto because I need to know the index
    {
        for(int j=0; j<e; ++j)// as above, I need to know the index
        {
          findMaxValue(i, j, matrix);
        }
    }



    return matrix[w-1][e-1];
}















