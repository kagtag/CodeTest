#pragma once

// Pattern : Sliding Window
// https://www.educative.io/courses/grokking-the-coding-interview/YQQwQMWLx80

// Description
// Given a string, find the length of the longest substring in it with no more than K distinct characters


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
			cout << "The longest substring with no more than " << k << " distinct characters is " << findLength(str, k) << endl;
			;
		};

		test_print(2, "araaci");
		test_print(1, "araaci");
		test_print(3, "cbbebi");
	}
};