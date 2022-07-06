#include<vector>
using namespace std;
class Solution {
public:
    int min(int a, int b){
        return (a < b) ? a:b;
    }
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> total(cost.size(), 0);
        //base case
        total[0] = cost[0];
        total[1] = cost[1];
        int stepLength = cost.size();
        
        //Recursive Form
        for(int i = 2 ; i < stepLength; ++i){
            total[i] = cost[i] + min(total[i-1], total[i-2]);
        }
        
        return min(total[stepLength -1], total[stepLength -2]);
    }
};