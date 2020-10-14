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
		int uniqueCount = 0;

		int fastIndex = 1, slowIndex = 0;

		// initial step
		if (arr.size() >= 1)
		{
			uniqueCount++;
		}

		while (fastIndex < arr.size())
		{
			if (arr[slowIndex] != arr[fastIndex])
			{
				uniqueCount++;

				if (fastIndex > slowIndex + 1)
				{
					// move elements forward
					for (int i = 0; i < arr.size() - fastIndex; ++i)
					{
						arr[slowIndex + i + 1] = arr[fastIndex + i];
					}

					// remove useless trailing items.
					arr.erase(arr.end() - (fastIndex - slowIndex - 1), arr.end());
				}

				slowIndex++;

				fastIndex = slowIndex;
			}
			
			fastIndex++;
		}

		// remove duplicate items in tail
		arr.erase(arr.begin() + uniqueCount, arr.end());

		cout << "Length of array after dedup: " << uniqueCount << endl;
		for (auto& item : arr)
		{
			cout << item << " ";
		}
		cout << endl;

		return uniqueCount;
	}

	static void test()
	{
		vector<int> input0 = { 2, 3, 3, 3, 6, 9, 9 };
		vector<int> input1 = { 2, 2, 2, 11 };

		remove(input0);
		remove(input1);
	}
};
