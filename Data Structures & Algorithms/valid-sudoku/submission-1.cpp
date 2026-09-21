class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {


        int n = board.size();

        vector<vector<int>> lines(n+1,vector<int>(n+1,0));
        vector<vector<int>> columns(n+1,vector<int>(n+1,0));
        vector<vector<int>> box(n+1,vector<int>(n+1,0));
        

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){

                if(board[i][j] == '.'){
                    continue;
                }else{
                    int num = board[i][j] - '0';

                    if(lines[i][num] == 1){
                        return false;
                    }
                    lines[i][num] =1;

                    if(columns[j][num] == 1){
                        return false;
                    }
                    columns[j][num]=1;

                    int box_idx = (i/3)*3 + (j/3);
                    if(box[box_idx][num] == 1){
                        return false;
                    }
                    box[box_idx][num] =1;
                }
            }
        }

        return true;
    }
};
