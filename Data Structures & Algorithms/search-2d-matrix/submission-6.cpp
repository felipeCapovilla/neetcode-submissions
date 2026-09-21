class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int line = find_line(matrix,target);
        int res = search(target,matrix[line]);

        return res == -1 ? false : true;
        
    }

    int find_line(vector<vector<int>>& v, int target){

        int m = v.size();
        int n = v[0].size();

        int r=m-1;
        int l= 0;

        while(r>l){
            int mid = (l+r)/2;

            if(v[mid][n-1] == target){
                return mid;
            }else if(v[mid][n-1] > target){
                r=mid;
            }else{
                l=mid+1;
            }
        }

        return l;
    }

    int search(int target, vector<int>&v){
        int l=0;
        int r = v.size()-1;

        while(l<=r){
            int mid = (l+r)/2;

            if(v[mid] == target){
                return mid;
            }else if(v[mid] > target){
                r=mid-1;
            }else{
                l=mid+1;
            }
        }

        return -1;
    }
};
