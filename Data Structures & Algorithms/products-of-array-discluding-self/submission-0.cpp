class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> output(n,0);
        
        
        vector<int> prefixo(n,0);
        vector<int> sufixo(n,0);
        int prodPre =1;
        int prodSu =1;

        for(int k=0;k<n;k++){
            prefixo[k]=prodPre*nums[k];
            prodPre=prodPre*nums[k];
        }

        for(int k = n-1; k>=0;k--){
            sufixo[k]=prodSu*nums[k];
            prodSu=prodSu*nums[k];
        }


        for(int j=0;j<n;j++){
            if(j == 0){
                output[j] = sufixo[j+1];
            }
            else if(j == n-1){
                output[j] = prefixo[j-1];
            }else{
                output[j] = prefixo[j-1]*sufixo[j+1];
            }
        }


        return output;
    }   
};
