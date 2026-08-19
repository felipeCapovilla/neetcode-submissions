class Solution {
public:
    int findMin(vector<int> &nums) {
        return binarySearch(0,nums.size()-1,nums);
    
    
    }


    int binarySearch(int ini, int fim, vector<int>& nums){
        if(ini == fim){
            return nums[ini];
        }

        int mid;
        mid = (fim+ini)/2;
        if(nums[mid] >= nums[fim]){
            return binarySearch(mid+1,fim,nums);
        }else{
            return binarySearch(ini,mid,nums);
        }
    }
};
