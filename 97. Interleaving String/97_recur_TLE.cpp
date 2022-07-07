#include <vector>
#include <cstdbool>
#include <string>
using namespace std;

class Solution {
public:
    bool recur(string s1, string s2, string s3, int i, int j, int k){
        if(i == s1.length() && j == s2.length() && k == s3.length())return true;
        if(s3[k] == s1[i] && s3[k] == s2[j] && i < s1.length() && j < s2.length()){
            return recur(s1, s2, s3, i+1, j, k+1) || recur(s1, s2, s3, i, j+1, k+1);
        }
        else if(i < s1.length() && s3[k] == s1[i])return recur(s1, s2, s3, i+1, j, k+1);
        else if(j < s2.length() && s3[k] == s2[j])return recur(s1, s2, s3, i, j+1, k+1);
        else return false;
        return false;
    }
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.length() + s2.length() != s3.length())return false;
        return recur(s1, s2, s3, 0, 0, 0);
        
    }

};