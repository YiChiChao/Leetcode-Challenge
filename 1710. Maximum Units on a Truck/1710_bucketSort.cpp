#include<vector>
using namespace std;

class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        vector<int> bucket(1001, 0);
        for(auto x: boxTypes){
            bucket[x[1]] += x[0];
        }
        int totalUnit = 0;
        for(int i = 1000; i > 0 ; --i){
            if(bucket[i] == 0)continue;
            if(truckSize >= bucket[i]){
                totalUnit += i * bucket[i];
                truckSize -= bucket[i];
            }
            else{
                totalUnit += truckSize * i;
                return totalUnit;
            }
            
        }
        return totalUnit;
    }
};