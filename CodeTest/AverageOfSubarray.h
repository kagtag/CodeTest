#pragma once

// Pattern: Sliding Window
// https://www.educative.io/courses/grokking-the-coding-interview/7D5NNZWQ8Wr

// Description: 
// Given an array, find the average of all contiguous subarrays of size ¡®K¡¯ in it.
// e.g.
// input : [1, 3, 2, 6, -1, 4, 1, 8, 2], K=5
// output : [2.2, 2.8, 2.4, 3.6, 2.8]

#include<iostream>
#include<vector>
using namespace std;

class AverageOfSubArrayOfSizeK
{
public:
	static vector<double> findAverages(int K, const vector<int>& arr)
	{
		vector<double> result(arr.size() - K + 1);

		double windowSum = 0.0;
		int windowStart = 0;
		for (int windowEnd = 0; windowEnd < arr.size(); ++windowEnd)
		{
			windowSum += arr[windowEnd];			// add the newly included item

			// Start sliding window 
			if (windowEnd >= K - 1)
			{
				result[windowStart] = windowSum / K; // compute average
				
				windowSum -= arr[windowStart];		// subtract the first item (belong to the previous sliding window)
				windowStart++;						// move to the next sliding window
			}
		}

		return result;
	}

	static void test()
	{
		vector<int> input = { 1, 3, 2, 6, -1, 4, 1, 8, 2 };
		int K = 5;
		vector<double> subarryAverages = AverageOfSubArrayOfSizeK::findAverages(K, input);

		cout << "Average of subarrays of size K :" << endl;
		for (auto& a : subarryAverages)
		{
			cout << a << " ";
		}
		cout << endl;
	}
};