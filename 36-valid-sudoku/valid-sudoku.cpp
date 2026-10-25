class Solution {
public:
    bool validbox(vector<vector<char>>& board,int sr, int er,int sc,int ec){
        unordered_set<char>st;
        for (int i = sr; i <= er; i++) {
            for (int j = sc; j <= ec; j++) {
                if (board[i][j] == '.')
                    continue;
                if (st.find(board[i][j]) != st.end()) {
                    return false;
                }
                st.insert(board[i][j]);
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        // row
        for (int i = 0; i < 9; i++) {
            unordered_set<char> st;
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.')
                    continue;
                if (st.find(board[i][j]) != st.end()) {
                    return false;
                }
                st.insert(board[i][j]);
            }
        }
        // col 
        for (int j = 0; j < 9; j++) {
            unordered_set<char> st;
            for (int i = 0; i < 9; i++) {
                if (board[i][j] == '.')
                    continue;
                if (st.find(board[i][j]) != st.end()) {
                    return false;
                }
                st.insert(board[i][j]);
            }
        }
        // boxes 
        for(int i = 0 ; i < 9 ; i+=3){
            int i_end = i+2;
            for(int j = 0 ;j < 9;j+=3){
                int j_end = j+2;
                if(!validbox(board,i,i_end,j,j_end)){
                    return false;
                }
            }
        }
        return true;
    }
};