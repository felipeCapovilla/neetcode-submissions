class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> prefixo(n);
        vector<int> sufixo(n);

        int prod=1;
        for(int k=0;k<n;k++){
            prefixo[k]=prod*nums[k];
            prod*=nums[k];
        }

        prod =1;
        for(int k=n-1;k>=0;k--){
            sufixo[k]=prod*nums[k];
            prod*=nums[k];
        }

        vector<int> output(n);
        for(int k=0; k<n;k++){
            if(k ==0){
                output[k] = sufixo[k+1];
            }else if(k == n-1){
                output[k] = prefixo[n-2];
            }else{
                output[k] = prefixo[k-1]*sufixo[k+1];
            }
        }

        return output;
        

    }
};
