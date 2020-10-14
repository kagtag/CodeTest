#pragma once

// Pattern : Sliding Window
// https://www.educative.io/courses/grokking-the-coding-interview/Y5YDWzqPn7O

// Description:
// Given a string and a list of words, find all the starting indices of substrings in the given string 
// that are a concatenation of all the given words exactly once without any overlapping of words. 
// It is given that all words are of the same length.

#include "PCH.h"

class WordConcatenation
{
public:
	static vector<int> findWordConcatenation(const string& str, const vector<string>& words)
	{
		vector<int> resultIndices;

		int windowStart = 0;

		int wordLength = words[0].size();
		int windowLength = wordLength * words.size();

		unordered_map<string, int> originalMap;
		unordered_map<string, int> wordFrequencyMap;

		int matched = 0;

		for (auto& w : words)
		{
			originalMap[w]++;
		}

		wordFrequencyMap = originalMap;

		for (int windowEnd = 0; windowEnd < str.size(); )
		{
			string rightWord = str.substr(windowEnd, wordLength);


			if(wordFrequencyMap.find(rightWord) == wordFrequencyMap.end())
			{
				// no matched word

				// reset the window
				windowStart++;

				windowEnd = windowStart;

				// reset all
				matched = 0;
				wordFrequencyMap = originalMap;
				continue;
			}
			else
			{
				wordFrequencyMap[rightWord]--;
				if (wordFrequencyMap[rightWord] >= 0)
					matched++;

				windowEnd += wordLength;
			}

			// Shrink the window
			while(windowEnd - windowStart > windowLength)
			{
				string leftWord = str.substr(windowStart, wordLength);
				
				if (wordFrequencyMap.find(leftWord) != wordFrequencyMap.end())
				{
					if (wordFrequencyMap[leftWord] == 0)
						matched--;
					wordFrequencyMap[leftWord]++;
				}
				
				//windowStart++;     // ???
				windowStart += wordLength;
			}

			if (matched == words.size())
			{
				resultIndices.push_back(windowStart);
			}
		}

		for (auto& i : resultIndices)
		{
			cout << "* " << i << " " << str.substr(i, windowLength) << " ";
		}
		cout << endl;

		return resultIndices;
	}

	static void test()
	{
		findWordConcatenation("catfoxcat", { "cat", "fox" });
		findWordConcatenation("catcatfoxfox", { "cat", "fox" });

		findWordConcatenation("gatecatgate", { "gat","ate","cat" });
	}
};