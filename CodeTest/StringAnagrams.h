#pragma once

// Pattern: Sliding Window
// https://www.educative.io/courses/grokking-the-coding-interview/YQ8N2OZq0VM

// Description
// Anagram is the same as Permutation.
// Given a string and a pattern, find all anagrams of the pattern in the given string.

// Can just use the same algorithm as Permutation in a String.
// but in this case, we need to find all of them.

#include "PCH.h"

class StringAnagrams
{
public:
	static vector<int> findStringAnagrams(const string& str, const string& pattern)
	{
		vector<int> resultIndices;
		
		int windowStart = 0;
		int matched = 0;
		unordered_map<char, int> charFrequencyMap;

		for (auto c : pattern)
		{
			charFrequencyMap[c]++;
		}

		for (int windowEnd = 0; windowEnd < str.size(); ++windowEnd)
		{
			char rightChar = str[windowEnd];
			if (charFrequencyMap.find(rightChar) != charFrequencyMap.end())
			{
				charFrequencyMap[rightChar]--;
				if (charFrequencyMap[rightChar] == 0)
					matched++;
			}

			if (windowEnd > pattern.size() - 1)
			{
				char leftChar = str[windowStart++];
				if (charFrequencyMap.find(leftChar) != charFrequencyMap.end())
				{
					if (charFrequencyMap[leftChar] == 0)
						matched--;
					charFrequencyMap[leftChar]++;
				}
			}

			// everytime we encounter a permutation, record the 
			// windowStart index.
			if (matched == charFrequencyMap.size())
			{
				resultIndices.push_back(windowStart);
			}
		}

		if (resultIndices.size() != 0)
		{
			cout << "Found permutation: ";
			for (auto& i : resultIndices)
			{
				cout <<"* "<< i <<" "<<  str.substr(i, pattern.size()) << " ";
			}
			cout << endl;
		}
		else
		{
			cout << "No permutation found." << endl;
		}

		return resultIndices;
	}

	static void test()
	{
		findStringAnagrams("ppqp", "pq");
		findStringAnagrams("abbcabc", "abc");
	}
};