class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int Islands = 0;
        int row = grid.size(), col = grid[0].size();
        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j < col; j++)
            {
                if(grid[i][j] == '1')
                {
                    Islands++;
                    dfs(grid, i, j); //So after getting an island, DFS sinks the whole island
                }
            }
        }
        return Islands;
    }

private:
    void dfs(vector<vector<char>>& grid, int r, int c) //Pass the grid, index, row, col
    {
        bool found = false;
        if(r < 0 || c < 0 || //false if row or column lower than zero, out of bounds
           r >= grid.size() || c >= grid[0].size() ||
           grid[r][c] == '0') //If its a zero then no need to do anything to it
        {
            return;
        }
        else if(grid[r][c] == '1') //If it is a one grid, we want to sink it
        {
            grid[r][c] = '0'; //Sink the tile
                //check all four directions
                dfs(grid, r + 1, c); 
                dfs(grid, r - 1, c);
                dfs(grid, r, c + 1);
                dfs(grid, r, c - 1);
        }
    }
};