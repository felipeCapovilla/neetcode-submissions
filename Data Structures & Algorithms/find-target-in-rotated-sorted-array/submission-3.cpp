class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();

        int mid_idx = findMin(0,n-1,nums);
        int b1,b2;
        b1 = search(mid_idx,n-1,target,nums);
        b2 = search(0,mid_idx-1,target,nums);

        if(b1 == b2){
            return -1;
        }else if(b1 != -1){
            return b1;
        }else{
            return b2;
        }

    }   

    int findMin(int ini, int fim, vector<int>& v){
        if(ini == fim){
            return ini;
        }

        int mid = (ini+fim)/2;
        if(v[mid] >= v[fim]){ //Buscar na direita.
            return findMin(mid+1,fim,v);
        }else{
            return findMin(ini,mid,v);
        }
    }

    int search(int l, int r, int target, vector<int>& v){
        if(l > r){
            return -1;
        }

        int mid = (l+r)/2;
        if(v[mid] == target){
            return mid;
        }
        if(v[mid] > target){
            return search(l,mid-1,target,v);
        }else{
            return search(mid+1,r,target,v);
        }
    }



};
