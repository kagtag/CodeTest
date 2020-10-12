#pragma once

// Pattern : Sliding Window
// https://www.educative.io/courses/grokking-the-coding-interview/R8DVgjq78yR

// Description
// Given a string with lowercase letters only, if you are allowed to replace
// no more than 'k' letters with any letter, find the length of the longest substring 
// having the same letters after replacement.

#include "PCH.h"

class CharacterReplacement
{
public:
	static int findLength(const string& str, int k)
	{
		int maxLength = 0;
		int startIndex = 0;
		char repeatChar = 0;

		int windowStart = 0, maxRepeatLetterCount = 0;

		unordered_map<char, int> letterFrequencyMap;
		for (int windowEnd = 0; windowEnd < str.size(); ++windowEnd)
		{
			char rightChar = str[windowEnd];
			letterFrequencyMap[rightChar]++;

			if (letterFrequencyMap[rightChar] > maxRepeatLetterCount)
			{
				maxRepeatLetterCount = letterFrequencyMap[rightChar];
				startIndex = windowStart;
				repeatChar = rightChar;
			}

			if (windowEnd - windowStart + 1 - maxRepeatLetterCount > k)
			{
				char leftChar = str[windowStart];
				letterFrequencyMap[leftChar]--;
				windowStart++;
			}

			maxLength = max(maxLength, windowEnd - windowStart + 1);
		}

		// incorrect if k maxRepeatLetterCount + k > str.size()
		//maxLength = maxRepeatLetterCount + k;

		cout << " Longest substring after replacement: " << str.substr(startIndex, maxLength)
			<< " of size " << maxLength << " . Repeat letter: " << repeatChar << endl;

		return maxLength;
	}

	static void test()
	{
		findLength("aabccbb", 2);
		findLength("abbcb", 1);
		findLength("abccde", 1);
	}
};
