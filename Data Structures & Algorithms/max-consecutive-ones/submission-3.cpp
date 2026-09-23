class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {

        if(nums.size() ==0){
            return 0;
        }
        
        int tam=0;

        for(int i=0;i<nums.size();i++){
            
            int start =i;
            while(start < nums.size() && nums[start] == 1){
                tam = max(tam,start-i+1);
                start++;
            }
            i=start;

        }

        return tam;
        
    }
};