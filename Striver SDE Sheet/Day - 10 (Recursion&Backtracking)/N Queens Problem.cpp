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
        
        // traverse all cols in that row, place queen and check if clash with left or right diagonal, or column
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

// Sid's naive solution

class Solution {
public:
    bool isSafe(vector<string> board, int row, int col)
    {
        //i have to check the current row 
        for(int i = 0; i < col; i++)
        {
            if(board[row][i] == 'Q')
                return false;
        }
        for(int i = row, j = col; i < board.size() && j >= 0; i++, j--)
        {
            if(board[i][j] == 'Q')
                return false;
        }
        for(int i = row, j = col; i >= 0 && j >= 0; i--,j--)
        {
            if(board[i][j] == 'Q')
            {
                return false;
            }
        }
        return true;
    }
    void solve(vector<vector<string>> &sol, vector<string> board, int col)
    {
        //base case 
        if(col >= board.size())
        {
            sol.push_back(board);
        }
        for(int row = 0; row < board.size(); row++)
        {
            if(isSafe(board, row, col))
            {
                board[row][col] = 'Q';
                solve(sol, board, col+1);
                board[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board;
        for(int i = 0; i < n; i++)
        {
            string s;
            for(int j = 0; j < n; j++)
            {
                s.push_back('.');
            }
            board.push_back(s);
        }
        vector<vector<string>> sol;
        solve(sol, board, 0);
        return sol;
    }
};

//not working soln 
class Solution {
public:
    bool solve(vector<vector<string>> &sol, vector<string> board, bool rows[], bool ud[], bool ld[], int col)
    {
        if(col == board.size())
        {
            sol.push_back(board);
        }
        for(int row = 0; row < board.size(); row++)
        {
            if(rows[col] == false && ud[row+col] == false && ld[row-col+ board.size()-1] == false)
            {
                board[row][col] = 'Q';
                rows[col] = true;
                ud[row+col] = true;
                ld[row-col+ board.size()-1] = true;
                if(solve(sol, board, rows, ud, ld, col+1))
                    return true;
                board[row][col] = '.';
                rows[col] = false;
                ud[row+col] = false;
                ld[row-col+ board.size()-1] = false;
            }
        }
        return false;
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board;
        for(int i = 0; i < n; i++)
        {
            string s;
            for(int j = 0; j < n; j++)
            {
                s.push_back('.');
            }
            board.push_back(s);
        }
        vector<vector<string>> sol;
        bool ld[100];
        bool ud[100], rows[100];
        for(int i = 0; i < 100; i++)
        {
            ld[i] = false;
            ud[i] = false;
            rows[i] = false;
        }
        
        solve(sol, board, rows, ud, ld, 0);
        return sol;
    }
};
