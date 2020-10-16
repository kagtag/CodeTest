#pragma once

#include "PCH.h"

class SortedArraySquares
{
public:
	static vector<int> makeSquares(const vector<int>& arr)
	{
		int n = arr.size();
		vector<int> squares(n);

		int firstIndex = 0, lastIndex = n - 1;

		int nextSlot = n - 1;
		while (firstIndex <= lastIndex)
		{
			if (abs(arr[firstIndex]) > abs(arr[lastIndex]))
			{
				squares[nextSlot--] = arr[firstIndex] * arr[firstIndex];
				firstIndex++;
			}
			else
			{
				squares[nextSlot--] = arr[lastIndex] * arr[lastIndex];
				lastIndex--;
			}
		}

		cout << "Squares: ";
		for (auto& i : squares)
		{
			cout << i << " ";
		}
		cout << endl;

		return squares;
	}

	static void test()
	{
		makeSquares({ -2, -1, 0, 2, 3 });
		makeSquares({ -3, -1, 0, 1, 2 });

	}
};