#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findGCD(vector<int>& nums) {
       int min_num = nums[0];
       int max_num = nums[0];
       for(int i = 1; i<nums.size(); i++){
        min_num = min(min_num,nums[i]);
        max_num = max(max_num,nums[i]);
       } 
       return __gcd(min_num,max_num);
    }
};