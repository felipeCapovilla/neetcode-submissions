class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int buy_price=prices[0];
        int max_profit = 0;

        for(int k=0;k<prices.size();k++){
            if(prices[k] < buy_price){
                buy_price = prices[k];
            }else{

                max_profit = max(max_profit,prices[k]-buy_price);
            }
        }

        return max_profit;
        
    }
};
