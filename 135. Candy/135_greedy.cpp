class Solution {
public:
    int candy(vector<int>& ratings) {
        //initial the array [1,1,1,1,1]
        //set a variable to record which level of the peak or valley is in right now
        //if it is not same as the last interval(peak or valley), then renew the variable to 1
        //else add one
        
        int i = 1;
        int candies = ratings.size();
        int size = ratings.size();
        while(i < size){
            if(ratings[i] - ratings[i-1] == 0){
                i++;
                continue;
            }
            
            int peak = 0;
            while(ratings[i] - ratings[i-1] > 0){
                peak += 1;
                candies += peak;
                i++;
                if(i >= size) return candies;
            }
            int valley = 0;
            while(ratings[i] - ratings[i-1] < 0){
                valley += 1;
                candies += valley;
                i++;
                if(i >= size)break;
            }
            
            candies -= ((valley < peak)? valley : peak);
        }
        
        return candies;
    }
};