#pragma once

// Pattern : Sliding Window
// https://www.educative.io/courses/grokking-the-coding-interview/YQQwQMWLx80

// Description
// Given a string, find the length of the longest substring in it with no more than K distinct characters


// Fruits into baskets.
// This problem can also be solved with this algorithm
// https://www.educative.io/courses/grokking-the-coding-interview/Bn2KLlOR0lQ

// Description
// Given an array of characters where each character represents a fruit tree, you are given 2 baskets and 
// your goal is to put maximum number of fruits in each basket. 
// The only restriction is that each basket can have only one type of fruit

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class LongestSubstringKDistinct
{
public:
	static int findLength(const string& str, int k)
	{
		int maxLength = 0;

		unordered_map<char, int> charCount; // count of each character in current sliding window.

		int windowStart = 0;
		int startIndex = 0;
		for (int windowEnd = 0; windowEnd < str.size(); ++windowEnd)
		{
			// add 1 more character into the window
			charCount[str[windowEnd]]++;

			// Shrink window until there're no more than k distinct characters in the window
			while (charCount.size() > k)
			{
				char leftChar = str[windowStart];
				charCount[leftChar]--;
				if (charCount[leftChar] == 0) charCount.erase(leftChar);
				windowStart++;
			}
			
			
			// Sub array no more than k distinct characters, update maxLength
			int windowSize = windowEnd - windowStart + 1;
			if (windowSize > maxLength)
			{
				maxLength = windowSize;
				startIndex = windowStart;
			}
		}

		cout << str.substr(startIndex, maxLength) << endl;

		return maxLength;
	}

	static void test()
	{
		auto test_print = [](int k, const string& str)
		{
			cout << "The longest substring with no more than " << k << " distinct characters is " << findLength(str, k) << endl << endl;
		};

		test_print(2, "araaci");
		test_print(1, "araaci");
		test_print(3, "cbbebi");

		
		auto basket_test_print = [](const vector<char>& chars)
		{
			string str;
			for (auto c : chars)
			{
				str += c;
			}

			cout << " Fruits in baskets " << findLength(str, 2) << endl << endl;
		};

		basket_test_print({ 'A', 'B', 'C', 'A', 'C' });
		basket_test_print({ 'A', 'B', 'C', 'B', 'B', 'C' });

	}
};