class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();

        for(int i=0;i<n;i++){
            unordered_map<char,int> row;
            for(int j=0;j<m;j++){
                if(board[i][j]=='.') continue;
                row[board[i][j]]++;
            }
            for(auto [x,y]:row) if(y>1) return false;
        }

        for(int j=0;j<m;j++){
            unordered_map<char,int> col;
            for(int i=0;i<n;i++){
                if(board[i][j]=='.') continue;
                col[board[i][j]]++;
            }
            for(auto [x,y]:col) if(y>1) return false;
        }

        for(int i=0;i<n;i+=3){
            for(int j=0;j<n;j+=3){
                unordered_map<char,int> square;
                for(int x=i;x<i+3;x++){
                    for(int y=j;y<j+3;y++){
                        if(board[x][y]=='.') continue;
                        square[board[x][y]]++;
                    }
                }
                for(auto [x,y]:square)  if(y>1) return false;
            }
        }

        return true;
    }
};
