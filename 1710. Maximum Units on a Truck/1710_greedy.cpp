#include<vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), [](vector<int> a, vector<int> b){
            return a[1] > b[1]; //decreasing
        });
        int totalUnit = 0;
        int numberOfBoxes, numberOfUnitsPerBox;
        for(int i = 0; truckSize > 0 && i < boxTypes.size() ; ++i){
            numberOfBoxes = boxTypes[i][0];
            numberOfUnitsPerBox = boxTypes[i][1];
            if(truckSize >= numberOfBoxes){
                totalUnit += numberOfBoxes * numberOfUnitsPerBox;
                truckSize -= numberOfBoxes;
            }
            else{
                totalUnit += truckSize * numberOfUnitsPerBox;
                truckSize = 0;
            }
            
        }
        return totalUnit;
    }
};