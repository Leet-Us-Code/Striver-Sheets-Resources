bool helper(bool graph[101][101], int m, int V, int col[], int i)
{
    if(i == V) // base case
    {
        return true;
    }
    for(int j = 0; j < m; j++)
    {
        //right now the colur we have is j 
        //check if any adjacent vertex has the colour j 
        bool flag = true;
        for(int x = 0; x < V; x++)
        {
            if(graph[i][x] == true)
            {
                if(col[x] == j)
                {
                    flag = false;
                    break;
                }
            }
        }
        if(flag == true)
        {
            //assign the colour
            col[i] = j;
            //call for the next vertex
            if(helper(graph, m, V, col, i+1))
            return true;
            //backtrack
            col[i] = -1;
        }
    }
    return false;
}
bool graphColoring(bool graph[101][101], int m, int V) {
    // your code here
    int col[V] ; // -1 means no coloured
    for(int i = 0; i < V; i++)
    col[i] = -1;
    return helper(graph, m, V, col, 0);
}
