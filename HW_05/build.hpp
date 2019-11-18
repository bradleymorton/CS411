//build.hpp by Bradley Morton, Nov 17 2019
//Created for CS411 taught by Dr. Hartman

#ifndef BUILD_HPP
#define BUILD_HPP

#include <vector>


using Bridge = std::vector<int>;

int build(int w, int e, const std::vector<Bridge> & bridges);

void findMaxValue(int i, int j, std::vector<std::vector<int>> & matrix);








#endif