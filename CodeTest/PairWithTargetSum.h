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
		// Get 2 pointers, pointing to the start and end of the array respectively.
		int startIndex = 0, endIndex = arr.size() - 1;

		auto result = make_pair(-1, -1);

		while (startIndex < endIndex)
		{
			int sum = arr[startIndex] + arr[endIndex];

			if (sum == targetSum)
			{
				result = make_pair(startIndex, endIndex);
				break;
				//return make_pair(startIndex, endIndex);
			}

			if (sum > targetSum)
			{
				--endIndex;
			}
			else
			{
				++startIndex;
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