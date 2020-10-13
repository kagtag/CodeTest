#pragma once

// Pattern : Sliding Window
// https://www.educative.io/courses/grokking-the-coding-interview/N8vB7OVYo2D

// Description
// Given a string and a pattern, find out if the string contains any permutation of the pattern.
// e.g. "abc" has 6 permutations.  3!
// abc
// acb
// bac
// bca
// cab
// cba

#include "PCH.h"

class StringPermutation
{
public:
	static bool findPermutation(const string& str, const string& pattern)
	{
		unordered_map<char, int> charFrequencyMap;
		
		int windowStart = 0;

		int matched = 0;

		// pattern maps recording pattern characters and their count.
		for (auto c : pattern)
		{
			charFrequencyMap[c]++;
		}

		for (int windowEnd = 0; windowEnd < str.size(); ++windowEnd)
		{
			// Include 1 more character
			char rightChar = str[windowEnd];
			if (charFrequencyMap.find(rightChar) != charFrequencyMap.end())
			{
				charFrequencyMap[rightChar]--;
				if (charFrequencyMap[rightChar] == 0)
					matched++;
			}

			// Shrink window to ensure window size <= pattern size
			if (windowEnd > (pattern.size() - 1))  
			{
				char leftChar = str[windowStart];
				if (charFrequencyMap.find(leftChar) != charFrequencyMap.end())
				{
					if (charFrequencyMap[leftChar] == 0)
						matched--;
					charFrequencyMap[leftChar]++;
				}
				windowStart++;
			}

			// Check if there's a permutation achieved.
			if (matched == charFrequencyMap.size())
			{
				cout << "Found permutation: " << str.substr(windowStart, windowEnd - windowStart + 1) << endl;
				return true;
			}
		}

		cout << "No permutation found." <<endl;
		return false;
	}

	static void test()
	{
		findPermutation("oidbcaf", "abc");
		findPermutation("odicf", "dc");
		findPermutation("bcdxabcdy", "bcdyabcdx");
		findPermutation("aaacb", "abc");
	}

};
