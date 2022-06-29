#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), [](vector<int> a, vector<int> b){
            if(a[0] == b[0]){
                return a[1] < b[1];
            }
            return a[0] > b[0];//decreasing
        });
        /*for(auto x: people){
            cout << x[0] << " " << x[1] << endl;
        }*/
        vector<vector<int>>ans;
        for(auto x: people){
            ans.insert(ans.begin() + x[1], x);
            
        }
        return ans;
        
    }
};