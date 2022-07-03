#include <vector>
using namespace std;
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        //bounding condition
        if(nums.size() == 1)return 1;
        if(nums.size() == 2){
            if(nums[0] != nums[1]) return 2;
            else return 1;
        }
        //1. same element f(i) = 1
        //2. sign * (nums[i] - nums[i-1] < 0 -> +1
        //3. sign * (nums[i] - nums[i-1] == 0 (same element) ignore
        //4. sign * (nums[i] - nums[i-1] > 0 (same sign) ignore
        int size = nums.size();
        int maxlength = (nums[0] - nums[1] == 0) ? 1 : 2;
        int sign = (nums[1] - nums[0] >= 0) ? 1 : -1;
        for(int i = 2; i < size; ++i){
            if(maxlength == 1 && (nums[i] - nums[i-1]) != 0) maxlength += 1;
            else if(sign * (nums[i] - nums[i-1]) < 0) maxlength += 1;
            else continue;
            sign = (nums[i] - nums[i-1] >= 0) ? 1 : -1;
        }
        return maxlength;
    }
};