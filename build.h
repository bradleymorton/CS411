//Written by Bradley Morton for CS411, taught by Dr. Chris Hartman
//Created September 24th 2019



#ifndef BUILD_H
#define BUILD_H

#include <vector>
using std::vector;


using Bridge = vector<int>;

int build(int w, int e, const vector<Bridge> & bridges);

vector<vector<Bridge>> powerSet(int w, int e, const vector<Bridge> & bridges);

int findMax(const vector<vector<Bridge>> & bridges);

int findToll(const vector<Bridge> & bridges);

















#endif