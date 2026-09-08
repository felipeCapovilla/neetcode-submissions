class Solution {
public:
    int findMin(vector<int> &nums) {
        int n = nums.size();
        int r= n-1;
        int l=0;

        while(r>l){
            int mid = (l+r)/2;
            if(nums[r] > nums[mid]){
                r=mid;
            }else{
                l = mid+1;
            }
        }

        return nums[r];      
    }
};
