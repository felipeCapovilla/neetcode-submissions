class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {

        int minRate = *max_element(weights.begin(),weights.end());
        while(true){
            int dias = 1;
            int capacidade = minRate;

            for(int w : weights){
                if(capacidade - w <0){
                    dias++;
                    capacidade = minRate;
                }
                capacidade-=w;
            }

            if(dias <= days){
                return minRate;
            }

            minRate++;
        }

        return minRate;
        
    }
};