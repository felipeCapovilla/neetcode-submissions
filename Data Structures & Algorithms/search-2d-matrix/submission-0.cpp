class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(); //Linhas.
        int m = matrix[0].size(); //Colunas.

        for(int k=0; k<n;k++){
            bool flag = buscaBinaria(0,m-1,target,matrix[k]);
            if(flag == true){
                return true;
            }
        }

        return false;
        
    }



    int buscaBinaria(int ini, int fim, int target, vector<int>& v){
        if(ini == fim){
            if(v[ini] == target){
                return true;
            }
            return false;
        }


        int mid = (fim+ini)/2;
        if(v[mid] == target){
            return true;
        }else if(v[mid] > target){
            return buscaBinaria(ini,mid,target,v);
        }else{
            return buscaBinaria(mid+1,fim,target,v);
        }
    }
};
