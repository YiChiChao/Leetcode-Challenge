#include<vector>
using namespace std;
class Solution {
public:
    int max(int a, int b){
        return (a > b)? a:b;
    }
    int rob(vector<int>& nums) {
        if(nums.size() == 1)return nums[0];
        if(nums.size() == 2)return max(nums[0], nums[1]);
        //base case
        //with head no tail
        int Max = nums[1];
        int f1 = nums[2];
        int size = nums.size();
        for(int i = 3; i < size; ++i){
            int temp = f1;
            f1 = max(Max + nums[i], f1);
            Max = max(Max, temp);
        }
        int head = max(Max, f1);
        //without head with tail
        Max = nums[0];
        f1 = nums[1];
        for(int i = 2; i < size-1; ++i){
            int temp = f1;
            f1 = max(Max + nums[i], f1);
            Max = max(Max, temp);
        }
        int tail = max(Max, f1);
        return max(head, tail);
    }
};