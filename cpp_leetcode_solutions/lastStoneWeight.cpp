#include <iostream>
#include <vector>
#include <algorithm>
#include <gtest/gtest.h>

class Solution {
public:
    static int lastStoneWeight(std::vector<int>& stones) {
        std::sort(stones.begin(), stones.end());
        while (1) {
            if (stones.empty())
            {
                return 0;
            }
            if (stones.size() == 1) 
            {
                return stones[0];
            }
            int stone1 = std::move(stones.back());
            stones.pop_back();
            int stone2 = std::move(stones.back());
            stones.pop_back();
            if (stone1 != stone2) {
                stone1 -= stone2;
                if (stones.empty()) 
                {
                    return stone1;
                }
                stones.push_back(stone1);
            	std::sort(stones.begin(), stones.end());
            }
        }
    }
};


TEST(lastStoneWeightTest, HandlesEmptyInput) {
	std::vector<int> input = {};
	EXPECT_EQ(Solution::lastStoneWeight(input), 0);
}

TEST(lastStoneWeightTest, HandlesSingleInput) {
	std::vector<int> input = { 1 };
	EXPECT_EQ(Solution::lastStoneWeight(input), 1);
}

TEST(lastStoneWeightTest, HandlesEqualStones) {
	std::vector<int> input = { 1, 1 };
	EXPECT_EQ(Solution::lastStoneWeight(input), 0);
}

TEST(lastStoneWeightTest, HandlesUnequalStones) {
	std::vector<int> input = { 1, 2 };
	EXPECT_EQ(Solution::lastStoneWeight(input), 1);
}

TEST(lastStoneWeightTest, HandlesEdgeCases) {
	std::vector<int> input = { 2, 7, 4, 1, 8, 1 };
	EXPECT_EQ(Solution::lastStoneWeight(input), 1);
}
