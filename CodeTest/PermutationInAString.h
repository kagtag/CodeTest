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
		unordered_map<char, int> pattMap, countMap;
		
		int windowStart = 0;

		// pattern maps recording pattern characters and their count.
		for (auto c : pattern)
		{
			pattMap[c]++;
		}

		for (int windowEnd = 0; windowEnd < str.size(); ++windowEnd)
		{
			char rightChar = str[windowEnd];

			while (pattMap.find(rightChar) == pattMap.end() && windowEnd < str.size())
			{
				// character not in pattern, skip to the next character.
				// and clear all records.
				windowStart = windowEnd = windowEnd + 1;
				countMap.clear();

				// since windowEnd changed, update rightChar
				rightChar = str[windowEnd];
			}
			
			if(countMap[rightChar] == pattMap[rightChar])
			{
				// More rightChar than needed. Shrink the window until we
				// remove 1 rightChar from window.
				while (str[windowStart] != rightChar)
				{
					char leftChar = str[windowStart];
					countMap[leftChar]--;
					windowStart++;
				}

				windowStart++;
				countMap[rightChar]--;
			}

			countMap[rightChar]++;
			if (countMap[rightChar] == pattMap[rightChar])
			{
				// Check if there's a permutation achieved.
				bool bFinished= true;
				for (auto& item : pattMap)
				{
					auto c = item.first;
					if (countMap[c] != pattMap[c])
					{
						// Still missing some characters 
						bFinished = false;
						break;
					}
				}

				if (bFinished)
				{
					cout << "Found permutation: " << str.substr(windowStart, windowEnd - windowStart + 1) << endl;
					return true;
				}
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
