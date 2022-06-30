class Solution {
public:
    int tribonacci(int n) {
        int t0 = 0;
        int t1 = 1;
        int t2 = 1;
        if(n == 0)return 0;
        if(n <= 2)return 1;
        int recent = 0;
        for(int i = 3; i <= n; ++i){
            recent = t0 + t1 + t2;
            t0 = t1;
            t1 = t2;
            t2 = recent;
        }
        return recent;
    }
};