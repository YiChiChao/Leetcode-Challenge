#include<vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int max(int a, int b){
        return (a>b)?a:b;
    }
    
    
    
    int longestConsecutive(vector<int>& nums) {
        int size = nums.size();
        unordered_map<int, int> map;
        int i = 0;
        for(auto x : nums){
            map.insert({x, i});
        }
        int maxlength = -1;
        for(auto x: map){
            int count = 1;
            for(int i = 1; map.find(x.first +i) != map.end(); ++i){
                map.erase(x.first +i);
                count++;
            }
            for(int i = 1; map.find(x.first -i) != map.end(); ++i){
                map.erase(x.first -i);
                count++;
            }
            maxlength = max(maxlength, count);    
        }
        return (maxlength > 0) ? maxlength : 0;    
    }  
};