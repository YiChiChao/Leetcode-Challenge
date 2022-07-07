#include <vector>
#include <cstdbool>
#include <string>
using namespace std;
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int str1 = s1.length();
        int str2 = s2.length();
        vector<vector<bool>> dp ( str1+1, vector<bool>(str2+1, false));
        if(s1.length() + s2.length() != s3.length())return false;
        
        for(int i = 0; i <= str1; ++i){
            for(int j = 0; j <= str2; ++j){
                if(i == 0 && j == 0)dp[i][j] = true;
                else if(i == 0) dp[i][j] = dp[i][j-1] && s2[j-1] == s3[j-1];
                else if(j == 0)dp[i][j] =dp[i-1][j] && s1[i-1] == s3[i-1];
                else dp[i][j] = (dp[i][j-1] && s2[j-1] == s3[i+j-1]) || (dp[i-1][j] && s1[i-1] == s3[i+j-1]);
            }
        }
        return dp[str1][str2];
        
    }

};