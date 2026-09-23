#include <iostream>
#include <vector>
#include <algorithm>

int longestConsecutive(std::vector<int> nums) {
        if (nums.empty()){
            return 0;
        }
        std::sort(nums.begin(), nums.end());
        int seqLength = 1;
        int champ = 1;
        int lastVal = nums[0];
        for (int value: nums) {
            if (value == lastVal + 1){
                seqLength++;
            }
            else if (value != lastVal){
                if (seqLength > champ){
                    champ = seqLength;
                }
                seqLength = 1;
            }
            lastVal = value;
        }
        if (seqLength > champ){
                champ = seqLength;
            }
        return champ;
    }

int main(){
    std::vector<int> test = {1,1,1};
    std::cout <<"Output: "<< longestConsecutive(test)<<"\n";
}