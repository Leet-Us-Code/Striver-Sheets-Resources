// Hari and Sid

class Solution{
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> res;
        string path;
        vector<vector<int>> seen( n , vector<int> (n, 0));
        helper(0,0,m,n, res, path, seen);
        return res;
    }
    
    bool isSafe(int row, int col, vector<vector<int>> &m, vector<vector<int>> &seen){
        if(row < 0 || row >= m.size() || col < 0 || col >= m.size() || seen[row][col] == 1 ||
        m[row][col] == 0) return false;
        
        return true;
    }
    
    void helper(int row, int col, vector<vector<int>> &m, int n, vector<string> &res,
        string &path, vector<vector<int>> &seen){
            if(row >= n || col >= n) return; // bounding case
            // destination reached? (base case)
            if(row == n-1 && col == n-1){
                res.push_back(path);
                return;
            }
            // destination not reached
            if(isSafe(row, col, m, seen)){
                seen[row][col] = 1;
                if(isSafe(row+1, col, m, seen)){ // D
                    path.push_back('D');
                    helper(row+1, col, m, n, res, path, seen);
                    path.pop_back();
                }
                if(isSafe(row, col-1, m, seen)){ // L
                    path.push_back('L');
                    helper(row, col-1, m, n, res, path, seen);
                    path.pop_back();
                }
                if(isSafe(row, col+1, m, seen)){ // R
                    path.push_back('R');
                    helper(row, col+1, m, n, res, path, seen);
                    path.pop_back();
                }
                if(isSafe(row-1, col, m, seen)){ // U
                    path.push_back('U');
                    helper(row-1, col, m, n, res, path, seen);
                    path.pop_back();
                }
                seen[row][col] = 0;
            }
            
            
        }
};
