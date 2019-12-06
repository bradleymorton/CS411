// huffcode.hpp  UNFINISHED
// Glenn G. Chappell
// 29 Nov 2015
//
// For CS 411/611 Fall 2015
// Assignment 6, Exercise A
// Header for class HuffCode
//
// Modified 11/22/17
// Chris Hartman
// For CS 411 Fall 2017
//
// Modified 12/5/2019
// Bradley Morton
// For CS 411 Fall 2019
// Worked on George Meier
// https://www.geeksforgeeks.org/huffman-coding-greedy-algo-3/ was consulted

#ifndef FILE_HUFFCODE_H_INCLUDED
#define FILE_HUFFCODE_H_INCLUDED

#include <string>
#include <unordered_map>
#include <queue>

struct MinHeapNode
{
	char _data;
	int _frequency;
	MinHeapNode *_left, *_right;

	MinHeapNode(char data, int frequency)
	{
		_left = _right = NULL;
		this->_data=data;
		this->_frequency=frequency;
	}
};

struct compare 
{
    bool operator()(MinHeapNode* left, MinHeapNode* right) 
    { 
        return (left->_frequency > right->_frequency); 
    } 
}; 


// Class HuffCode
// Encoding & decoding using a Huffman code
class HuffCode {

// ***** HuffCode: ctors, dctor, op= *****
public:

    // Compiler-generated default ctor, copy ctor, copy =, dctor used

// ***** HuffCode: general public functions *****
public:

    void setWeights(const std::unordered_map<char, int> & theweights);

    std::string encode(const std::string & text) const;

    std::string decode(const std::string & codestr) const;

    void storeCodes(struct MinHeapNode* root, std::string str);

// ***** HuffCode: data members *****
private:
	std::priority_queue<MinHeapNode *, std::vector<MinHeapNode *>, compare> _minHeap;
	std::unordered_map<char, std::string> _letters;
};  // End class HuffCode


#endif //#ifndef FILE_HUFFCODE_H_INCLUDED

