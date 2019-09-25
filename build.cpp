//Written by Bradley Morton for CS411, taught by Dr. Chris Hartman
//Created September 24th 2019
//https://www.geeksforgeeks.org/power-set/ was looked at for help finding the power set
//I loosely followed their approach, which is similar if not the same to the one
//shown by Dr. Hartman in class


#include "build.h"
#include <math.h>
#include <iostream>
using std::cout;
using std::endl;




int build(int w, int e, const vector<Bridge> & bridges)
{
	return findMax(powerSet(w, e, bridges));
}

vector<vector<Bridge>> powerSet(int w, int e, const vector<Bridge> & bridges)
{

	int n = bridges.size();
	int sizeOfPowerset = pow(2, n);


	vector<int> set(n);
	vector<vector<Bridge>> powerSet(sizeOfPowerset);
	

	for (int i = 0; i <sizeOfPowerset; ++i)
	{
		for (int j=0; j<n; ++j)
		{
			if(i & (1<<j))
			{
				set[j]=1;
				powerSet[i].push_back(bridges[j]);
			}
			else
			{
				set[j]=0;
			}
		}
	}

	return powerSet;

}


int findMax(const vector<vector<Bridge>> & bridges)
{
	int max =0;


	for(auto i:bridges)
	{
		int toll = 0;
		//If valid, check against max and increase it if larger.
		//If invalid, don't. 
		for(int j = 0; j<i.size(); ++j)
		{
			for(int k =j+1; k<i.size(); ++k)
			{
				if((i[j][0] <= i[k][0] && i[j][1] >= i[k][1]) 
				|| (i[j][0] >= i[k][0] && i[j][1] <= i[k][1]))
				{
					break;
				}
			}
			toll += i[j][2];
		}
		if(toll>max)
		{
			max = toll;
		}
	}


	return max;
}