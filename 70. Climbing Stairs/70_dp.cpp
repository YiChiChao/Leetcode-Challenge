class Solution {
public:
    int climbStairs(int n) {
        int f1 = 1;
        int f2 = 2;
        if(n <= 2)return n;
        int recent = 0;
        for(int i = 3; i <= n; ++i){
            recent = f1 + f2;
            f1 = f2;
            f2 = recent;
        }
        return recent;
    }
};