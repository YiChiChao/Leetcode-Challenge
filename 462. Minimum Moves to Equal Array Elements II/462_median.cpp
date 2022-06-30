#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int sum = 0;
        int median = nums.size() /2;
        median = nums[median];
        for(auto x: nums){
            sum += abs(x-median);
        }

        return sum;
    }
};