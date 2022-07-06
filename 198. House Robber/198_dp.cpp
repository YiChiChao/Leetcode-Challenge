#include <vector>
using namespace std;
class Solution {
public:
    int max(int a, int b){
        return (a > b)? a:b;
    }
    int rob(vector<int>& nums) {
        if(nums.size() == 1)return nums[0];
        //base case
        int Max = nums[0];
        int f1 = nums[1];
        int size = nums.size();
        for(int i = 2; i < size; ++i){
            int temp = f1;
            f1 = max(Max + nums[i], f1);
            Max = max(Max, temp);
        }
        return max(Max, f1);
    }
};