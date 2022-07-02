#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int max(int a, int b){
        return (a > b)? a : b;
    }
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        long long int maxhor = max(horizontalCuts[0], h - horizontalCuts[horizontalCuts.size()-1]);
        long long int maxver = max(verticalCuts[0], w - verticalCuts[verticalCuts.size()-1]);
        //printf("%d %d\n", maxhor, maxver);
        for(int i = 1; i < horizontalCuts.size(); ++i){
            maxhor = max(maxhor, horizontalCuts[i] - horizontalCuts[i-1]);
        }
        maxhor %= 1000000007;
        for(int i = 1; i < verticalCuts.size(); ++i){
            maxver = max(maxver, verticalCuts[i] - verticalCuts[i-1]);
            //printf("%d %d\n", maxhor, maxver);
        }
        maxver %= 1000000007;
        //printf("%d %d\n", maxhor, maxver);
        long long int returnVal = (maxhor * maxver) % 1000000007;
        return returnVal;
    }
};