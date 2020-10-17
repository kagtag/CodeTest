#pragma once

#include "PCH.h"

// https://www.educative.io/courses/grokking-the-coding-interview/gxk639mrr5r

// Description:
// Given an array of unsorted numbers, find all unique triplets in it that add up to zero.

class TripletSumToZero
{
private:
	static void searchPair(const vector<int>&arr, int targetSum, int left,
		vector<vector<int>>&triplects)
	{

		int right = arr.size() - 1;

		while (left < right)
		{
			int currentSum = arr[left] + arr[right];

			if (currentSum == targetSum)
			{
				triplects.push_back({ -targetSum, arr[left], arr[right] });
				left++;
				right--;

				// skip same element to avoid duplicate triplets
				while (left < right && arr[left] == arr[left - 1])
				{
					left++;
				}
				while (left < right && arr[right] == arr[right + 1])
				{
					right--;
				}
			}

			else if (currentSum < targetSum)
			{
				left++;
			}
			else
			{
				right--;
			}
		}

	}

public:
	static vector<vector<int>> searchTriplets(vector<int>& arr)
	{
		vector<vector<int>> triplets;

		sort(arr.begin(), arr.end());
		for (int i = 0; i < arr.size() - 2; ++i)
		{
			// skip duplicate items
			if(i > 0 && arr[i] == arr[i-1])
				continue;

			searchPair(arr, -arr[i], i + 1, triplets);
		}





		for (auto& v : triplets)
		{
			cout << " [ ";
			for (auto& item : v)
			{
				cout << item << " ";
			}
			cout << "] ";
		}
		cout << endl;

		return triplets;
	}

	static void test()
	{
		vector<int> input0 = { -3, 0, 1, 2, -1, 1, -2 };
		vector<int> input1 = { -5, 2, -1, -2, 3 };

		searchTriplets(input0);
		searchTriplets(input1);
	}
};