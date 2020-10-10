#pragma once

// Pattern: Sliding Window
// https://www.educative.io/courses/grokking-the-coding-interview/7D5NNZWQ8Wr

// Description: 
// Given an array, find the average of all contiguous subarrays of size ��K�� in it.
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

		// Compute sum for the first sliding window
		for (int i = 0; i < K; ++i)
		{
			result[0] += arr[i];
		}

		// Compute sum for each sliding window
		for (int i = 1; i <= arr.size() - K; ++i)
		{
			result[i] = result[i - 1];

			result[i] -= arr[i - 1];
			result[i] += arr[i + K - 1];
		}

		// Compute average
		for (int i = 0; i < result.size(); ++i)
		{
			result[i] /= K;
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