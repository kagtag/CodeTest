#pragma once
#include "PCH.h"

// https://www.educative.io/courses/grokking-the-coding-interview/xog6q15W9GP

// Description:
// Given an array of sorted numbers and a target sum, find a pair in the array whose sum 
// is equal to the given target.

class PairWithTargetSum
{
public:
	static pair<int, int> search(const vector<int>& arr, int targetSum)
	{
		auto result = make_pair(-1, -1);

		unordered_map<int, int> numberIndexMap;

		for (int i = 0; i < arr.size(); ++i)
		{
			int y = targetSum - arr[i];
			if (numberIndexMap.find(y) == numberIndexMap.end())
			{
				numberIndexMap[arr[i]] = i;
			}
			else
			{
				result = make_pair(numberIndexMap[y], i);
				break;
			}
		}

		if (result.first != -1)
		{
			cout << "Found pair : index: " << result.first << " " << result.second <<
				" number: " << arr[result.first] << " " << arr[result.second] << endl;
		}
		else
		{
			cout << "Not found." << endl;
		}

		return result;
	}

	static void test()
	{
		search({ 1, 2, 3, 4, 6 }, 6);
		search({ 2, 5, 9, 11 }, 11);
	}
};