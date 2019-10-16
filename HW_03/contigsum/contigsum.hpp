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

class GCSIntermediateValues
{
public: 
	int gcs = 0;
	int gcsWithFirst = 0;
	int gcsWithLast = 0;
	int sum = 0;
};


template<typename RAIter>
GCSIntermediateValues recurse(RAIter first, RAIter last, int size)
{
	GCSIntermediateValues vals_0;
	if(size == 1)
	{
		if((*first) < 0)
		{
			vals_0.sum += (*first);
			return vals_0;
		}
		vals_0.gcs += (*first);
		vals_0.gcsWithFirst += (*first);
		vals_0.gcsWithLast += (*first);
		vals_0.sum += (*first);
	}

	RAIter mid = first + ((last - first)/2);
	size = distance(first, mid)+1;
	vals_0 = recurse(first, mid, size);
	size = distance(mid +1, last)+1;
	GCSIntermediateValues vals_1 = recurse(mid+1, last, size);
	GCSIntermediateValues vals_2 = 
	{
		max(vals_0.gcs, max(vals_1.gcs, (vals_0.gcsWithLast + vals_0.gcsWithLast))),
		max(vals_0.gcsWithFirst, (vals_0.sum + vals_1.gcsWithFirst)),
		max(vals_1.gcsWithLast, (vals_0.gcsWithLast + vals_1.sum)),
		vals_0.sum + vals_1.sum
	};

	return vals_2;
}





template<typename RAIter>
int contigSum(RAIter first, RAIter last)
{	
	int sum =0;
	if(first == last)
	{
	return sum;
	}
	
	int size = distance(first, last);
    GCSIntermediateValues vals;
    vals = recurse(first, last, size);
	return vals.sum;


}


















#endif