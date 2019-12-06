// huffcode.cpp  UNFINISHED
// Glenn G. Chappell
// 29 Nov 2015
//
// For CS 411/611 Fall 2015
// Assignment 6, Exercise A
// Source for class HuffCode
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



#include "huffcode.hpp"  // for class HuffCode declaration
#include <string>
using std::string;
#include <unordered_map>
using std::unordered_map;


void HuffCode::setWeights(const unordered_map<char, int> & theweights)
{
    if(theweights.empty())
    {
    	return;
    }
    struct MinHeapNode *left, *right, *top;
    for(auto i:theweights)
    {
    	_minHeap.push(new MinHeapNode(i.first, i.second));
    }

    while(_minHeap.size()!=1)
    {
    	left = _minHeap.top();
    	_minHeap.pop();

    	right = _minHeap.top();
    	_minHeap.pop();
    	
    	top = new MinHeapNode('$', left->_frequency + right->_frequency);

    	top->_left = left; 
        top->_right = right; 
  
        _minHeap.push(top); 
    }
    storeCodes(_minHeap.top(), "");
}





string HuffCode::encode(const string & text) const
{   
    string encoding;
    for(auto letter:text)
    {
    	encoding+=_letters.find(letter)->second;
    }
    return encoding;
}


string HuffCode::decode(const string & codestr) const
{
    string decoded, temp;

    for(auto cha:codestr)
    {
    	temp+=cha;
    	for(auto iter =_letters.begin(); iter != _letters.end(); ++iter)
    	{
    		if(iter->second == temp)
    		{
    			decoded+=iter->first;
    			temp.clear();
    		}
    	}
    }
    return decoded;
}



void HuffCode::storeCodes(struct MinHeapNode* root, string str)
{ 
    if (!root) 
        return; 
  
    if (root->_data != '$') 
        _letters[root->_data]=str; 
  
    storeCodes(root->_left, str + "0"); 
    storeCodes(root->_right, str + "1"); 
} 