#pragma once

#include "PCH.h"

// Pattern: Sliding Window
// https://www.educative.io/courses/grokking-the-coding-interview/B6VypRxPolJ

// Given an array containing 0s and 1s, if you are allowed to replace no more than 'k' 0s with 1s,
// find the length of the longest contiguous subarray having all 1s.

class ReplacingOnes
{
public:
	static int findLength(const vector<int>& arr, int k)
	{
		int maxLength = 0;
		int startIndex = 0;

		int onesCount = 0;  // number of 1s in sliding window
		
		int windowStart = 0;
		for (int windowEnd = 0; windowEnd < arr.size(); ++windowEnd)
		{
			if (arr[windowEnd] == 1)
			{
				onesCount++;
				startIndex = windowStart;
			}
			//else
			{
				// provided version, the result will be correct, but some intermediate state
				// would be incorrect.
				// e.g. k = 2
				// 0 1 1 0 0 0 1
				// after sliding window reach 1 1 0 0,
				// next iteration would yield a sliding window 1 0 0 0. note here we have 
				// 3 0s. 

				/*while*/if(windowEnd - windowStart + 1 - onesCount > k)
				{
					if (arr[windowStart] == 1)
						onesCount--;

					windowStart++;
				}
			}

			maxLength = max(maxLength, windowEnd - windowStart + 1);
		}

		cout << "Longest subarray with 1s after replacement: ";
		for (int i = startIndex; i < startIndex + maxLength; ++i)
		{
			cout << arr[i] << " ";
		}
		cout << "  of size " << maxLength << endl;

		return maxLength;
	}

	static void test()
	{
		findLength({ 0, 1, 1, 0, 0, 0, 1, 1, 0, 1, 1 }, 2);
		findLength({ 0, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 1, 1 }, 3);
	}
};