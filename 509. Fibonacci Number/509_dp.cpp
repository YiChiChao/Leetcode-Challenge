class Solution {
public:
    int fib(int n) {
        if(n <= 1)return n;
        int f0 = 0;
        int f1 = 1;
        int recent = 0;
        for(int i = 2; i <= n; ++i){
            recent = f0 + f1;
            f0 = f1;
            f1 = recent;
        }
        return recent;
    }
};