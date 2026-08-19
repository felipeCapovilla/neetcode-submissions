class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        
        long maxTime = *max_element(piles.begin(),piles.end());
        long currH =0;
        for(int k=1; k<=maxTime;k++){
            currH =0;
            for(int i=0; i<piles.size();i++){
                currH += ((piles[i]+k-1)/k);
            }
            if(currH <= h){
                return k;
            }
        }
        
    }
};
