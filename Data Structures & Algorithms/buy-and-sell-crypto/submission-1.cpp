class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int esq,dir;
        int profit;
        profit =0;
        esq = 0;
        dir = 1;

        while(dir < prices.size()){
            if(prices[dir] > prices[esq]){
                int currProfit = prices[dir] - prices[esq];
                profit = max(profit, currProfit);
            }else{
                esq = dir;
            }
            dir++;

        }

        return profit;

    }
};
