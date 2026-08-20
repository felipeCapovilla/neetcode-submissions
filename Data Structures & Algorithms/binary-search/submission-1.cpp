class Solution {
public:
    int search(vector<int>& nums, int target) {

        int ini,fim,n;
        n =nums.size();
        ini=0;
        fim = n-1;
        return buscaBinaria(target,ini,fim,nums);

    }

    int buscaBinaria(int target, int ini, int fim, vector<int>& v){
        
        if(ini > fim){
            return -1;
        }
        if(ini == fim){
            if(v[ini] == target){
                return ini;
            }
            return -1;
        }

        int mid = (ini+fim)/2;
        if(v[mid] == target){
            return mid;
        }
        if(target > v[mid]){
            return buscaBinaria(target,mid+1,fim,v);
        }else{
            return buscaBinaria(target,ini,mid-1,v);
        }

    }
};

