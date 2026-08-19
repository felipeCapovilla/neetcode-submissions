class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int,unordered_set<char>> rows,columns;
        map<pair<int,int>,unordered_set<char>> squares;

        
        int lim_r = board.size();
        int lim_c = board[0].size();

        for(int r=0;r<lim_r;r++){
            for(int c=0; c<lim_c;c++){
                
                if(board[r][c] == '.'){
                    continue;
                }

                pair <int,int> squareKey = {r/3,c/3};

                if(rows[r].count(board[r][c]) || columns[c].count(board[r][c]) || squares[squareKey].count(board[r][c])){
                    return false; //Aqui estamos verificando se ja apareceu.
                }

                rows[r].insert(board[r][c]);
                columns[c].insert(board[r][c]);
                squares[squareKey].insert(board[r][c]);


            }
        }
                    return true;
        
    }
};
