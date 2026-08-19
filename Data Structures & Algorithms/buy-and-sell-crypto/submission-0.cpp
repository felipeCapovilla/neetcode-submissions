class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit,buy;
        buy = prices[0];
        profit =0;

        for(int k=1; k<prices.size();k++){
            if(prices[k] < buy){
                buy = prices[k];
            }

            if(prices[k] - buy > profit){
                profit = prices[k]-buy;
            }
        }

        return profit;
        
    }
};
