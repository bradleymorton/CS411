//Written by Bradley Morton for CS411, taught by Dr. Chris Hartman
//Created September 24th 2019
//https://www.geeksforgeeks.org/power-set/ was looked at for help finding the power set
//I loosely followed their approach, which is similar if not the same to the one
//shown by Dr. Hartman in class


#include "build.h"
#include <math.h>





int build(int w, int e, const vector<Bridge> & bridges)
{
	return findMax(powerSet(bridges));
}

vector<vector<Bridge>> powerSet(int w, int e, const vector<Bridge> & bridges)
{
	vector<vector<Bridge>> powerSet;

	int n = bridges.size();
	int sizeOfPowerset = pow(2, n);
	powerSet.resize(sizeOfPowerset);

	vector<int> set;
	set.resize(n);
	for(auto i:set)
	{
		set[i]=0;
	}

	for (int i = 0; i <sizeOfPowerset; ++i)
	{
		for (int j=0; j<n; ++j)
		{
			if(j && (1<<j))
			{
				set[j]=1;
			}
			else
			{
				set[j]=0;
			}
		}

		for(int iter = 0; iter; ++iter)
		{
			if(set[iter]==1)
			{
				powerSet[i].push_back(bridges[iter]);
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
		for(int j = 0; j<(bridges[i]).size(); ++j)
		{
			for(int k =j+1; k<bridges[i].size(); ++k)
			{
				if(bridges[i][j][0] <= bridges[i][k][0] && bridges[i][j][1] >= bridges[i][k][1] 
				|| bridges[i][j][0] >= bridges[i][k][0] && bridges[i][j][1] <= bridges[i][k][1])
				{
					break;
				}
			}
			toll += bridges[i][j][2];
		}
		if(toll>max)
		{
			max = toll;
		}
	}


	return max;
}