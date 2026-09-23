#include <vector>
#include <unordered_map>
#include <algorithm>
#include <gtest/gtest.h>

class Solution {
public:
	static std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
		std::sort(nums.begin(), nums.end());
		std::vector<std::vector<int>> solution;
		auto start = nums.begin();

		while (start < std::prev(nums.end(), 2)){
			if(start > nums.begin() && *start == *std::prev(start)){
				++start;
				continue;
			}

			auto left = start + 1;
			auto right = std::prev(nums.end());

			while (left < right){
				int sum = *start + *left + *right;
				if ( sum < 0 ){
					++left;
				}
				else if ( sum > 0 ){
					--right;
				}
				else if (sum == 0){
					solution.push_back({*start, *left, *right});
					++left;
					--right;

					while(left < right && *left == *std::prev(left)){
						++left;
					}

					while(left < right && *right == *std::next(right)){
						--right;
					}
				}
			}
			++start;
		}
		return solution;
	}
};

TEST(threeSumTest, HandlesNoMatch){
	std::vector<int> input = { 1, 1, 0 };
	std::vector<std::vector<int>> expectedOutput = {};
	EXPECT_EQ(Solution::threeSum(input), expectedOutput);
}

TEST(threeSumTest, HandlesOneMatch){
	std::vector<int> input = { 0, 0, 0 };
	std::vector<std::vector<int>> expectedOutput = {{ 0, 0, 0 }};
	EXPECT_EQ(Solution::threeSum(input), expectedOutput);
}

TEST(threeSumTest, HandlesMultiMatch){
	std::vector<int> input = { -1, 0, 1, 2, -1, -4 };
	std::vector<std::vector<int>> expectedOutput = {{ -1, -1, 2 }, { -1, 0, 1 }};
	EXPECT_EQ(Solution::threeSum(input), expectedOutput);

	input = { 3, 0, 3, 2, -4, 0, -3, 2, 2, 0, -1, -5 } ;
	expectedOutput = { { -5, 2, 3 }, { -4, 2, 2 }, { -3, 0, 3 }, { 0, 0, 0 } } ;
	EXPECT_EQ(Solution::threeSum(input), expectedOutput);
}

TEST(threeSumTest, HandlesMultiMatchWithTwoSumCollision){
	std::vector<int> input = { -1, 0, 1, 2, -1, -4, -2, -3, 3, 0, 4 };
	std::vector<std::vector<int>> expectedOutput = { { -4, 0, 4 }, { -4, 1, 3 }, { -3, -1, 4 }, { -3, 0, 3 }, { -3, 1, 2 }, { -2, -1, 3 }, { -2, 0, 2 }, { -1, -1, 2 }, { -1, 0, 1 } };
	EXPECT_EQ(Solution::threeSum(input), expectedOutput);
}

TEST(threeSumTest, HandlesZeroFilledArrayEdgeCase){
	std::vector<int> input(3000,0);
	std::vector<std::vector<int>> expectedOutput = {{0,0,0}};
	EXPECT_EQ(Solution::threeSum(input), expectedOutput);
}

TEST(threeSumTest, HandlesRepeatedTargetEdgeCase){
	std::vector<int> input;
	input.reserve(3000);
	input.insert(input.end(), 1000, 0);
	input.insert(input.end(), 1000, 1);
	input.insert(input.end(), 1000, -1);

	std::vector<std::vector<int>> expectedOutput = {{-1,0,1}, {0,0,0}};
	EXPECT_EQ(Solution::threeSum(input), expectedOutput);
}


