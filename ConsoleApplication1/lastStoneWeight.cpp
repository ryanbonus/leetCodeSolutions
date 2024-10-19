#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    int lastStoneWeight(std::vector<int>& stones) {
        while (1) {
            if (stones.size() == 1) 
            {
                return stones[0];
            }
            std::sort(stones.begin(), stones.end());
            int stone1 = stones.back();
            stones.pop_back();
            int stone2 = stones.back();
            stones.pop_back();
            if (stone1 != stone2) {
                int smashedStone = stone1 - stone2;
                if (stones.empty()) 
                {
                    return smashedStone;
                }
                stones.push_back(smashedStone);
            }
            else if (stones.empty())
            {
                return 0;
            }
        }
    }
};

int main()
{
    std::vector<int> input = { 2, 7, 4, 1, 8, 1 };
    Solution solution;
    int output = solution.lastStoneWeight(input);
    std::cout<<"Output: " << output;
}
