#pragma once

// Pattern: Sliding Window
// https://www.educative.io/courses/grokking-the-coding-interview/JPKr0kqLGNP#problem-statement

// Description
// Given an array of positive numbers and a positive number ¡®k¡¯, find the maximum sum of any contiguous subarray of size ¡®k¡¯.
// e.g.
// input [2, 1, 5, 1, 3, 2], k=3
// output 9

// input [2, 3, 4, 1, 5], k=2
// output 7


#include<iostream>
#include<vector>

using namespace std;

class MaxSumSubArrayOfSizeK
{
public:
	static int findMaxSumSubArray(int k, const vector<int>& arr)
	{
		int maxSum = 0;
		int startIndex = 0;  // Start index of the max sum subarray

		int windowSum = 0;
		int windowStart = 0;
		for (int windowEnd = 0; windowEnd < arr.size(); ++windowEnd)
		{
			windowSum += arr[windowEnd];			// add the newly included item

			if (windowEnd >= k - 1)
			{
				// Test if it is bigger than the current max sum
				if (windowSum > maxSum)
				{
					maxSum = windowSum;
					startIndex = windowStart;
				}

				windowSum -= arr[windowStart];		// subtract the first item (belongs to the previous sliding window)
				windowStart++;						// move to the next sliding window
			}
		}

		// print the max sum subarray
		for (int i = startIndex; i < startIndex + k; ++i)
		{
			cout << arr[i] << " ";
		}

		cout << endl;

		return maxSum;
	}

	static void test()
	{
		vector<int> input0 = { 2, 1, 5, 1, 3, 2 };
		cout<< "Max sum " << findMaxSumSubArray(3, input0) << endl;

		vector<int> input1 = { 2, 3, 4, 1, 5 };
		cout << "Max sum " << findMaxSumSubArray(2, input1) << endl;
	}
};