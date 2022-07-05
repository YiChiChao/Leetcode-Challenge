#include<vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int max(int a, int b){
        return (a>b)?a:b;
    }
    
    void unionRoot(vector<int>& parent, vector<int>& countTable, int root1, int root2){
        if(root1 != root2){
            if(countTable[root1] >= countTable[root2]){
                parent[root2] = root1;
                countTable[root1] += countTable[root2];
                countTable[root2] = 0;
            }
            else{
                parent[root1] = root2;
                countTable[root2] += countTable[root1];
                countTable[root1] = 0;
            }
        }
    }
    
    int findParent(vector<int> parent, int idx){
        if(parent[idx] == -1) return idx;
        int parentidx = parent[idx];
        int root = findParent(parent, parentidx);
        return root;
    }
    
    int longestConsecutive(vector<int>& nums) {
        int size = nums.size();
        vector<int> parent(size, -1); //store the parent of the disjoint set
        vector<int> countTable(size, 1);//store the root count
        unordered_map<int, int> map;
        int i = 0;
        for(auto x : nums){
            map.insert({x, i++});
        }
        for(int j = 0; j < size; ++j){
            if(map.find(nums[j]+1) == map.end())continue; //not in the array
            int root1 = findParent(parent, map[nums[j]+1]);
            int root2 =  findParent(parent, map[nums[j]]);
            unionRoot(parent, countTable, root1, root2);
        }
        int maxlength = -1;
        for(int j = 0; j < size; ++j){
            maxlength = max(maxlength, countTable[j]); 
        }
        return (maxlength > 0) ? maxlength : 0;  
        
    }
    
    
};