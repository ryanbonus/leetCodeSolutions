#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

class Solution {
public:
    std::vector<int> sortedSquares(std::vector<int>& nums) {
        for (int i=0; i<nums.size(), i++;)
        {
            nums[i] = pow(nums[i],2);
        }
        std::sort(nums.begin(), nums.end());
        return nums;
    }
};

int main()
{
    std::vector<int> input = { 2, 7, 4, 1, 8, 1 };
    Solution solution;
    std::vector<int> output = solution.sortedSquares(input);
    std::cout << "Output: [";
    for (int x:output)
    {
        std::cout<<x<<", ";
    }
    std::cout<<"]\n";
}
