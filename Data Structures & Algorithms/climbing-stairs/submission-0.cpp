class Solution {
public:
    int climbStairs(int n) {
        if(n == 1){
            return 1;
        }else if(n == 2){
            return 2;
        }else{
            vector<int> tabulation(n,0);

            tabulation[0]=1;
            tabulation[1]=2;

            for(int k=2;k<n;k++){
                tabulation[k] = tabulation[k-1]+tabulation[k-2];
            }
        
            return tabulation[n-1];
        }


        
    }
};
