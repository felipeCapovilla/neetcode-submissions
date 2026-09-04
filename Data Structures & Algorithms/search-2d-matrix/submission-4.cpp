class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int i = rowSearch(matrix,target);
        return search(matrix[i],target);
        
    }

    int rowSearch(vector<vector<int>>& m, int target){
        int l = 0;
        int r = m.size()-1;

        int end = m[0].size()-1;

        while(l < r){
            int mid = (l+r)/2;
            
            if(m[mid][end] == target){
                return mid;
            }else if(m[mid][end] < target){
                l = mid+1;
            }else{
                r = mid;
            }
        }

        return r;
    }

    bool search(vector<int>&v, int target){
        int l=0;
        int r = v.size()-1;

        while(r>=l){
            int mid = (r+l)/2;
            if(v[mid] == target){
                return true;
            }else if(v[mid] > target){
                r=mid-1;
            }else{
                l=mid+1;
            }
        }

        return false;
    }
};
