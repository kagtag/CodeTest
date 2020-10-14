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

		unordered_map<string, int> wordFrequencyMap;
		for (auto word : words)
		{
			wordFrequencyMap[word]++;
		}

		int wordCount = words.size(), wordLength = words[0].size();

		for (int i = 0; i <= str.size() - wordCount * wordLength; ++i)
		{
			unordered_map<string, int> wordSeen;
			for (int j = 0; j < wordCount; ++j)
			{
				string word = str.substr(i + j * wordLength, wordLength);

				// word not included in pattern
				if (wordFrequencyMap.find(word) == wordFrequencyMap.end())
					break;

				wordSeen[word]++;

				// more words than needed
				if (wordSeen[word] > wordFrequencyMap[word])
					break;

				if (j + 1 == wordCount)
				{
					resultIndices.push_back(i);
				}
			}
		}


		for (auto& i : resultIndices)
		{
			cout << "* " << i << " " << str.substr(i, wordLength*wordCount) << " ";
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