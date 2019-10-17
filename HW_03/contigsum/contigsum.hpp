//Contiguous sums by Bradley Morton
//Created for Dr. Hartman's CS411 (Analysis of Algorithms) course
//Finds largest continuous sum with divide and conquer algorithm

#ifndef CONTIGSUM_HPP
#define CONTIGSUM_HPP
#include <iterator>
using std::distance;
#include <algorithm>
using std::max;
#include <iostream>
using std::cout;
using std::endl;


//Class used to store four variables as in homework description
class GCSValues
{
public: 
	int a = 0;
	int b = 0;
	int c = 0;
	int d = 0;
};

template<typename RAiter>
GCSValues baseCase(RAiter first)
{
        GCSValues values;
        if((*first <0))
        {
            return {0, 0, 0, (*first)};
        }
        else
        {
            return {(*first), (*first), (*first), (*first)};
        }
}

int maxOfThree(int a, int b,int c)
{
    return max(a, max(b,c));
}


template<typename RAIter>
GCSValues recurse(RAIter first, RAIter last)
{
	if(distance(first, last) ==1)
	{
		return baseCase(first);
	}

	RAIter mid = first + ((last - first)/2);
    GCSValues valsLeft = recurse(first, mid);
	GCSValues valsRight = recurse(mid, last);
	GCSValues vals_total =
	{
            maxOfThree(valsLeft.a, valsRight.a, valsLeft.c + valsRight.b),
            max(valsLeft.b, (valsLeft.d + valsRight.b)),
            max(valsRight.c, (valsLeft.c + valsRight.d)),
            valsLeft.d + valsRight.d
	};

	return vals_total;
}





template<typename RAIter>
int contigSum(RAIter first, RAIter last)
{	
	int sum =0;
	if(first == last)
	{
	return sum;
	}

	GCSValues vals = recurse(first, last);
	return vals.a;


}


















#endif