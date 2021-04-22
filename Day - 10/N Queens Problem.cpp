// Hari

class Solution {
public:
    
    vector<vector<string>> finalBoard;
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<int>> board( n , vector<int> (n, 0));
        unordered_set<int> diag1;
        unordered_set<int> diag2;
        unordered_set<int> vert;
        placeQueen(0, board, diag1,diag2, vert);
        return finalBoard;
    }
    
    void placeQueen(int i, vector<vector<int>> &board, unordered_set<int> &diag1,
                   unordered_set<int> &diag2, unordered_set<int> &vert){
        //diag1 is rightdiag, diag2 is leftdiag of board matrix
        // base case
        if(i == board.size()){
            addToList(board);
            return;
        } 
        
        // traverse all cols in that row, place queen and check if clash with left or             right diagonal, or column
        for(int j = 0; j<board.size(); j++){
            if(diag1.find(i+j) == diag1.end() && diag2.find(j-i) == diag2.end()
              && vert.find(j) == vert.end()){
                // this queen spot is valid
                board[i][j] = 1;
                // fill the resp sets w this valid position
                diag1.insert(i+j); diag2.insert(j-i); vert.insert(j);
                // call fun
                placeQueen(i+1, board, diag1, diag2, vert);
                // after coming back from rec, remove these pos from all ds
                board[i][j] = 0;
                diag1.erase(i+j); diag2.erase(j-i); vert.erase(j);
            }
        }
    }
    
    void addToList(vector<vector<int>> &board){
        // covert pos with 1 to Q and rest to .
        vector<string> res;
        for(int i = 0; i<board.size(); i++){
            string temp = ""; // new string for each row
            for(int j = 0; j<board.size(); j++){
                if(board[i][j] == 0) temp+=".";
                else temp+="Q";
            }
            res.push_back(temp);
        }
        finalBoard.push_back(res);
    }
    
    
};
