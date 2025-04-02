int dfs(vector<vector<int>>& obstacleGrid, int i, int j,vector<vector<int>>&memo) {
    // Check if out of bounds or an obstacle
    if (i >= obstacleGrid.size() || j >= obstacleGrid[0].size() || obstacleGrid[i][j] == 1) {
        return 0;
    }

    // If the destination (bottom-right corner) is reached, return 1
    if (i == obstacleGrid.size() - 1 && j == obstacleGrid[0].size() - 1) {
        return 1;
    }
 if (obstacleGrid[0][0] == 1 || obstacleGrid[obstacleGrid.size()- 1][obstacleGrid[0].size() - 1] == 1) {
        return 0;
    }

    if (memo[i][j] != -1) {
        return memo[i][j];
    }

    // Recursively calculate the number of paths by moving right or down
    int rightPaths = dfs(obstacleGrid, i, j + 1,memo);
    int downPaths = dfs(obstacleGrid, i + 1, j,memo);

    return memo[i][j] = rightPaths + downPaths;
}

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();

    
    vector<vector<int>>memo(m, vector<int>(n, -1));

    // If the starting or ending point is blocked, return 0


    return dfs(obstacleGrid, 0, 0,memo);
}