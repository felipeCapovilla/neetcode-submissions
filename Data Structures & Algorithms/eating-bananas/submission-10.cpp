class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {

        int min_rate = 1;
        int max_rate = *max_element(piles.begin(),piles.end());
        int curr_rate=0;

        while(min_rate < max_rate){
            curr_rate = (min_rate+max_rate)/2;
            int curr_time =0;

            for(int bananas : piles){
                curr_time+=(bananas+curr_rate-1)/curr_rate;

                if(curr_time > h){
                    break;
                }
            }

            if(curr_time > h){
                min_rate=curr_rate+1;
            }else{
                max_rate=curr_rate;
            }

        }

        return min_rate;
        
    }
};
