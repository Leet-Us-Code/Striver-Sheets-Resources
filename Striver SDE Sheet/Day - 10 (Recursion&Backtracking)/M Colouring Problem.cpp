// Sid

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

// Hari

bool helper(int idx, bool graph[101][101], int m, int V, int colors[]){
    // first traverse through colors. Then we check the adjacent vertices for current "index"
    // and see if this chosen color is in them. If yes, backtrack. Else it is valid
    
    //base case
    if(idx == V) return true; // traversed all vertices w/o issues
    //traverse colors
    for(int i = 0; i<m; i++){
        //traverse vertices that are adj to idx
        bool flag = true;
        for(int j = 0; j<V; j++){
            //check if edge exists btw idx and j
            if(graph[idx][j]){
                // if edge is there, compare colors
                // i is the color we want to assign to idx. Compare adj vert colors with it
                if(colors[j] == i){
                    flag = false;
                    break;
                    // dont put "return false" as it will skip other colors
                }
            }
        }
        // backtracking if colors different
        if(flag){
            colors[idx] = i;
            if(helper(idx+1, graph, m, V, colors)) return true;
            colors[idx] = -1; // we recursed to next idx and if that had failed, then replace current idx w -1 as it will not give soln in future
        }
        
    }
    return false;
}



//Function to determine if graph can be coloured with at most M colours such
//that no two adjacent vertices of graph are coloured with same colour.
bool graphColoring(bool graph[101][101], int m, int V)
{
    int colors[V];
    for(int i = 0; i<V; i++) colors[i] = -1; // so init with no colors
    return helper(0, graph, m, V, colors);
}
