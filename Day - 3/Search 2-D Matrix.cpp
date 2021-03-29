class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // abstract binary search method O(n*m), O(1) -> TLE
           if(!matrix.size()) return false; 
        
           int rows = matrix.size(); int cols = matrix[0].size();
           int lo = 0, hi = (rows*cols) - 1;
        
        while(lo <= hi){
            int mid = (lo+(hi-lo)) / 2;
            //int indexRow = mid/cols; int indexCol = mid%cols;
            if(matrix[mid/cols][mid%cols] == target) return true;
            
            else if(matrix[mid/cols][mid%cols] < target) lo = mid+1;
            else hi = mid-1;
        }
        return false;
    }
        
        // Manually moving method -> Works perfectly
    //     int i = 0, j = cols-1;
    //     while(i < rows && j >= 0){
    //         if(matrix[i][j] == target) return true;
    //         else if(matrix[i][j] < target) i++;
    //         else j--;
    //     }
    //     return false;
    // }
};
