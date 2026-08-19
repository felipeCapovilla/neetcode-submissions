class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        return buscaBinaria(0,n-1,target,nums);
    }


    int buscaBinaria(int ini, int fim, int target, vector<int>& nums){
        
        if(ini == fim){
            if(target == nums[ini]){
                return ini;
            }
            return -1;
        }

        int mid = (ini+fim)/2;

        if(nums[mid] == target){
            return mid;
        }else if(nums[mid] > target){
            return buscaBinaria(ini,mid,target,nums);
        }else{
            return buscaBinaria(mid+1,fim,target,nums);
        }
    }
};
