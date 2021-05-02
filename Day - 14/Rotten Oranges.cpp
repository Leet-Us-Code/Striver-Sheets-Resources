// Hari

int orangesRotting(vector<vector<int>>& grid) {
        // solved using BFS
        queue<pair<int, int>> rotten;
        
        int freshCnt = 0;
        for(int i = 0; i<grid.size(); i++){
            for(int j = 0; j<grid[0].size(); j++){
                if(grid[i][j] == 2) rotten.push(make_pair(i,j)); // add coordinate to queue
                if(grid[i][j] == 1) freshCnt++; 
            }
        }
        
        vector<vector<int>> dxy = {{1,0}, {-1,0}, {0,1}, {0,-1}}; // down up right left
        int time = 0;
        while(!rotten.empty() && freshCnt > 0){
            time++;
            int sz = rotten.size();
            while(sz-- > 0){
                auto pick = rotten.front(); rotten.pop();
                for(auto it: dxy){
                    int xC = pick.first + it[0]; // x coordinate 
                    int yC = pick.second + it[1]; // y coordinate
                    // check bounds or if no fresh orange in x and yCoords
                    if(xC < 0 || xC >= grid.size() || yC < 0 || yC >= grid[0].size() ||
                      grid[xC][yC] == 0 || grid[xC][yC] == 2) continue;
                    
                    // so we have a fresh orange here. It becomes rotten so add to rotten Q and change grid val from 1 to 2
                    rotten.push(make_pair(xC, yC));
                    grid[xC][yC] = 2;
                    freshCnt--;
                }
            }
        }
        
        if(freshCnt == 0) return time;
        else return -1;
    }




// Sid
class Solution {
public:
    struct Node{
        int time;
        int x;
        int y;
    };
    int orangesRotting(vector<vector<int>>& grid) {
        //push all nodes with rotten oranges in the queue with initial timestamp as 0 
        int n = grid.size();
        int m = grid[0].size();
        queue<Node> q;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(grid[i][j] == 2)
                {
                    struct Node x = {0, i, j};
                    q.push(x);
                }
            }
        }
        struct Node x;
        while(q.size() > 0)
        {
            x = q.front(); 
            //rot all the adjacent nodes and push it in the queue 
            q.pop();
            int time = x.time;
            int curi = x.x;
            int curj = x.y;
            // cout << time << " "<< curi <<" "<< curj << endl;
            if(curj > 0)
            {
                if(grid[curi][curj-1] == 1)
                {
                    grid[curi][curj-1] = 2;
                    struct Node y = {time+1, curi, curj-1};
                    q.push(y);
                }
            }
            if(curi > 0)
            {
                if(grid[curi-1][curj] == 1)
                {
                    grid[curi-1][curj] = 2;
                    struct Node y = {time+1, curi-1, curj};
                    q.push(y);
                }
            }
            if(curi < n-1)
            {
                if(grid[curi+1][curj] == 1)
                {
                    grid[curi+1][curj] = 2;
                    struct Node y = {time+1, curi+1, curj};
                    q.push(y);
                }
            }
            if(curj < m-1)
            {
                if(grid[curi][curj+1] == 1)
                {
                    grid[curi][curj+1] = 2;
                    struct Node y = {time+1, curi, curj+1};
                    q.push(y);
                }
            }
        }
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(grid[i][j] == 1)
                    return -1;
            }
        }
        return x.time;
    }
};
