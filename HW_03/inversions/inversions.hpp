//Inversions.hpp created by Bradley Morton
//Created for CS411 (Analysis of Algorithms) for Dr Hartman
//Last Modified Oct 15 2019
//This started with code from merge_sort.cpp, provided by Dr. Hartman and written by Dr. Chappel


#ifndef INVERSIONS_HPP
#define INVERSIONS_HPP

#include <vector>
using std::vector;
#include <cstddef>
using std::size_t;
#include <algorithm>
using std::copy;
#include <iterator>
using std::distance;
using std::advance;



// stableMerge
// Merge two halves of a sequence, each sorted, into a single sorted
// sequence in the same location. Merge is done in a stable manner.
// Requirements on Types:
//     FDIter is a forward iterator type.
//     The value type of FDIter has default ctor, dctor, copy=,
//      operator<.
//     operator< is a total order on the value type of FDIter.
// Pre:
//     [first, middle) and [middle, last) are valid ranges, each sorted
//      by <.
// Post:
//     [first, last) contains the same items as it did initially, but
//      now sorted by < (in a stable manner).
template <typename RAIter>
size_t stableMerge(RAIter first, RAIter middle, RAIter last)
{
    // ** C++03:
    using Value = typename std::iterator_traits<RAIter>::value_type;
    // ** C++11:
//    using Value = typename remove_reference<decltype(*first)>::type;
    // ** Is this really better?

    vector<Value> buffer(static_cast<unsigned long>(distance(first, last)));
    // Buffer for temporary copy of data
    RAIter in1 = first;         // Read location in 1st half
    RAIter in2 = middle;        // Read location in 2nd half
    auto out = buffer.begin();  // Write location in buffer
    // ** auto! That *is* better than vector<Value>::iterator

    size_t inversions = 0;
    // Merge two sorted lists into a single list in buff.
    while (in1 != middle && in2 != last)
    {
        if (*in2 < *in1)
        {// Must do comparison this way, to be stable.
            *out++ = *in2++;
            inversions += middle - in1;
        }
        else
            *out++ = *in1++;
    }

    // Copy remainder of original sequence to buffer.
    // Only one of the following two copy calls will do anything, since
    //  the other is given an empty source range.
    copy(in1, middle, out);
    copy(in2, last, out);

    // Copy buffer contents back to original sequence location.
    copy(buffer.begin(), buffer.end(), first);
    return inversions;
}


// mergeSort
// Sorts a sequence, using Merge Sort.
// Recursive.
// Requirements on Types:
//     FDIter is a forward iterator type.
//     The value type of FDIter has default ctor, dctor, copy=,
//      operator<.
//     operator< is a total order on the value type of FDIter.
// Pre:
//     [first, last) is a valid range.
// Post:
//     [first, last) contains the same items as it did initially,
//      but now sorted by < (in a stable manner).

template<typename RAIter>
size_t mergeSort(RAIter first, RAIter last)
{
    // Compute size of sequence
    size_t size = static_cast<size_t>(distance(first, last));

    // BASE CASE
    if (size <= 1)
    {
        return 0;
    }

    // RECURSIVE CASE
    RAIter middle = first;
    advance(middle, size/2);  // middle is iterator to middle of range

    // Recursively sort the two lists
    size_t firstHalf = mergeSort(first, middle);
    size_t secondHalf = mergeSort(middle, last);

    // And merge them
    return (stableMerge(first, middle, last)+firstHalf+secondHalf);
}


template<typename RAIter>
size_t inversions(RAIter first, RAIter last)
{
    if(first == last)
    {
        return 0;
    }
    return mergeSort(first, last);
}


















#endif