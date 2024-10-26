#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

class Solution {
public:
    int myAtoi(std::string s) {
        bool positive {true};
        for (char x : s)
        {
            if (x == ' ')
            {
                continue;
            }
            if (x=='-')
            {
                positive = false;
            }
            try 
            {
                x = int(x);
            }

        }
    }
};

int main()
{
    
}