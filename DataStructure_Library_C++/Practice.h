#pragma once
#include "Libraries.h"

class Solution {
public:
	bool twoSum(std::vector<int>& nums, int target)
	{
		for (unsigned int i = 0; i < nums.size(); i++)
		{
			if (i + 1 < nums.size())
			{
				if (nums[i] + nums[i + 1] == target)
				{
					return true;
				}

			}
		}

		return false;
	}



	std::vector<int> twoSumV(std::vector<int>& nums, int target)
	{
		for (unsigned int i = 0; i < nums.size(); i++)
		{
			if (i + 1 < nums.size())
			{
				if (nums[i] + nums[i + 1] == target)
				{
					std::vector<int> temp = { nums[i], nums[i + 1] };
					return temp;
				}
			}


		}
		return nums;
	}

};



std::string reverseString(std::string word)
{
	if (word.empty() || word.size() < 2)
		std::cout << "Error" << std::endl;

	std::string temp;

	for (size_t i = word.size() - 1; i >= 0; i--)
	{
		temp.push_back(word[i]);

		if (i == 0)
			break;
	}


	word = temp;
	return word;
}


void printString(std::string word)
{

	for (size_t i = 0; i < word.size(); i++)
	{
		std::cout << word[i];
	}
}