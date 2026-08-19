class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();

        vector<int>prefixo(n);
        vector<int>sufixo(n);
        vector<int>out(n);

        prefixo[0] = 1;
        sufixo[n-1]=1;

        int prod = nums[0];
        
        for(int i=1;i<n;i++){
            prefixo[i]=prod;
            prod*=nums[i];
        }

        prod = nums[n-1];
        for(int j=n-2;j>=0;j--){
            sufixo[j]=prod;
            prod*=nums[j];
        }

        for(int k=0; k<nums.size();k++){
            out[k] = sufixo[k]*prefixo[k];
        }

        return out;

    }
};
