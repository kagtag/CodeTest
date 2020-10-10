#pragma once

// Pattern : Sliding Window
// https://www.educative.io/courses/grokking-the-coding-interview/7XMlMEQPnnQ

// Description
// Given an array of positive numbers and a positive number 'S', find the length of the smallest contiguous subarray 
// whose sum is greater than or equal to 'S'. Return 0, if no such subarray exists.
// e.g.
// input [2, 1, 5, 2, 3, 2], S=7 
// output 2

// input [2, 1, 5, 2, 8], S=7 
// output 1

// input [3, 4, 1, 1, 6], S=8
// output 3

#include <iostream>
#include <vector>
#include <limits>

using namespace std;

class MinSizeSubArraySum
{
public:
	static int findMinSubArray(int S, const vector<int>& arr)
	{
		int windowStart = 0, windowSum = 0;
		int minCount = numeric_limits<int>::max(); //min subarray size
		int startIndex = 0; // start index of the min subarray

		for (int windowEnd = 0; windowEnd < arr.size(); ++windowEnd)
		{
			windowSum += arr[windowEnd];
			
			// Check if the window sum >= S, if so, check if the current sliding window size < minCount.
			// repeatedly removing one element from the front of the window to reduce subarray size.
			for (; windowSum >= S /*&& windowStart <= windowEnd*/; ++windowStart) // useless when S > 0
			{
				int count = windowEnd - windowStart + 1;
				if (count < minCount)
				{
					minCount = count;
					startIndex = windowStart;
				}

				windowSum -= arr[windowStart];

			}

			if (minCount == 1)
				break;

		}

		for (int i = startIndex; i < startIndex + minCount; ++i)
		{
			cout << arr[i] << " ";
		}

		cout << endl;

		return minCount == numeric_limits<int>::max() ? -1 : minCount;
	}

	static void test()
	{
		auto test_print = [](int S, int output)
		{
			cout << "Smallest subarrays with a sum >= to " << S << " is of size " << output << endl;
		};

		vector<int> input0 = { 2, 1, 5, 2, 3, 2 };
		test_print(7, findMinSubArray(7, input0));

		vector<int> input1 = { 2, 1, 5, 2, 8 };
		test_print(7, findMinSubArray(7, input1));

		vector<int> input2 = { 3, 4, 1, 1, 6 };
		test_print(8, findMinSubArray(8, input2));

	}
};