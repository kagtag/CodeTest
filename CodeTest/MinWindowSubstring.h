#pragma once

// Pattern : Sliding Window
// https://www.educative.io/courses/grokking-the-coding-interview/3wDJAYG2pAR

// Description
// Given a string and a pattern, find the smallest substring in the given string which has 
// all the characters of the given pattern.

// My version, removes duplicated characters in pattern.   Does a character in pattern appears in substring?
// Provided version, still considers the frequency of the character in pattern,  just like Permutation in a String
// e.g., pattern "aabc"  , string "abc"
// it would output "abc" in my version, since the pattern would be recognized as "abc",
// while output "" in provided version, since there's not enough 'a's.

#include "PCH.h"

class MinimumWindowSubstring
{
public:
	static string findSubstring(const string& str, const string& pattern)
	{
		unordered_map<char, int> charFrequencyMap;

		for (auto c : pattern)
		{
			charFrequencyMap[c]++;
		}

		int matched = 0;
		int startIndex = 0;

		int windowStart = 0;
		int minSize = numeric_limits<int>::max();
		for (int windowEnd = 0; windowEnd < str.size(); ++windowEnd)
		{
			// Include 1 more character
			char rightChar = str[windowEnd];
			if (charFrequencyMap.find(rightChar) != charFrequencyMap.end())
			{
				charFrequencyMap[rightChar]--;
				if (charFrequencyMap[rightChar] >= 0)
				{
					matched++;
				}

			}

			// When found a matched substring, shrink the window as
			// much as we can to see if there's a smaller matched substring.
			while (matched == pattern.size())
			{
				int curSize = windowEnd - windowStart + 1;
				if (minSize > curSize)
				{
					minSize = curSize;
					startIndex = windowStart;
				}


				char leftChar = str[windowStart++];
				if (charFrequencyMap.find(leftChar) != charFrequencyMap.end())
				{
					charFrequencyMap[leftChar]++;
					if (charFrequencyMap[leftChar] == 1)
					{
						// not matched anymore, try to include more characters.
						matched--;
						break;
					}
				}

			}
		}


		string result = (minSize == numeric_limits<int>::max()) ? "" : str.substr(startIndex, minSize);

		
		cout << "Smallest substring having all characters of the pattern is : " << result << endl;

		return result;
	}

	static void test()
	{
		findSubstring("aabdec", "abc");
		findSubstring("abdbca", "abc");
		findSubstring("adcad", "abc");

	}
};

