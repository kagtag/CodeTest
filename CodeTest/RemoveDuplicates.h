#pragma once

// https://www.educative.io/courses/grokking-the-coding-interview/mEEA22L5mNA

// Description
// Given an array of sorted numbers, remove all duplicates from it. You should not use any extra space;
// after removing the duplicates in-place, return the length of the subarray that has no duplicate in it.

#include "PCH.h"

class RemoveDuplicates
{
public:
	static int remove(vector<int>& arr)
	{
		int nextNonDuplicate = 1; 

		for (int i = 1; i < arr.size(); ++i)
		{
			if (arr[i] != arr[nextNonDuplicate -1])
			{
				arr[nextNonDuplicate] = arr[i];
				nextNonDuplicate++;
			}
		}

		arr.erase(arr.begin() + nextNonDuplicate, arr.end());

		cout << "Length of array after dedup: " << nextNonDuplicate << endl;
		for (auto& item : arr)
		{
			cout << item << " ";
		}
		cout << endl;

		return nextNonDuplicate;
	}

	static void test()
	{
		vector<int> input0 = { 2, 3, 3, 3, 6, 9, 9 };
		vector<int> input1 = { 2, 2, 2, 11 };

		remove(input0);
		remove(input1);
	}
};
