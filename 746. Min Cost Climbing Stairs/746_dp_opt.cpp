#include<vector>
using namespace std;
class Solution {
public:
    int min(int a, int b){
        return (a < b) ? a:b;
    }
    int minCostClimbingStairs(vector<int>& cost) {
        //base case
        int f0 = cost[0];
        int f1 = cost[1];
        int stepLength = cost.size();
        
        //Recursive Form
        for(int i = 2 ; i < stepLength; ++i){
            int temp = f1;
            f1 = cost[i] + min(f0, f1);
            f0 = temp;
        }
        
        return min(f0, f1);
    }
};