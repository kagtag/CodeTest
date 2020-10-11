#pragma once

// Pattern : Sliding Window (changing window size)
// https://www.educative.io/courses/grokking-the-coding-interview/YMzBx1gE5EO

// Description
// Given a string, find the length of the longest substring which has no repeating characters.

#include "PCH.h"

class NoRepeatSubstring
{
public:
	static int findLength(const string& str)
	{
		int maxLength = 0;
		int startIndex = 0;

		unordered_map<char, int> charCount;

		int windowStart = 0;
		for (int windowEnd = 0; windowEnd < str.size(); ++windowEnd)
		{
			char rightChar = str[windowEnd];
			if (charCount.find(rightChar) != charCount.end())
			{
				while (str[windowStart] != rightChar)
				{
					charCount.erase(str[windowStart]);
					windowStart++;
				}

				windowStart++;
			}
			else
			{
				charCount.emplace(rightChar, 1);
				int count = windowEnd - windowStart + 1;
				if (count > maxLength)
				{
					maxLength = count;
					startIndex = windowStart;
				}
			}
		}

		cout << str.substr(startIndex, maxLength) << endl;

		return maxLength;
	}

	static void test()
	{
		auto test_print = [](const string& str)
		{
			cout << "The longest substring without any repeating characters is ";
			cout << findLength(str) << endl << endl;
		};

		test_print("aabccbb");
		test_print("abbbb");
		test_print("abccde");
	}
};