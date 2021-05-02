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
