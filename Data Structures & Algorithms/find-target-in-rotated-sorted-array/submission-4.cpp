class Solution {
public:
    int search(vector<int>& nums, int target) {
        int min_idx = start(nums);


        int first_idx = busca(target,0,min_idx-1,nums);
        int second_idx = busca(target,min_idx,nums.size()-1,nums);

        return first_idx == -1 ? second_idx : first_idx;
        
    }

    int busca(int target, int ini, int fim, vector<int>& v){
        
        while(ini <= fim){
            int mid = (ini+fim)/2;
            
            if(v[mid] == target){
                return mid;
            }

            if(v[mid] > target){
                fim = mid-1;
            }else{
                ini = mid+1;
            }

        }

        return -1;
    }

    int start(vector<int>& v){
        int ini,fim;
        ini=0;
        fim = v.size()-1;

        while(ini < fim){
            int mid = (ini+fim)/2;

            if(v[mid] > v[fim]){
                ini=mid+1;
            }else{
                fim=mid;
            }
        }

        return ini;
    }

};
