class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum,ini,fim,tam;
        sum=0;
        ini=0;
        fim=0;
        tam=100001;

        while(fim < nums.size()){
            sum+=nums[fim];
            while(sum >= target){
                tam = min(tam,fim-ini+1);
                sum-=nums[ini];
                ini++;
            }
            fim++;
        }

        if(tam > 100000){
            return 0;
        }

        return tam;
        
    }
};