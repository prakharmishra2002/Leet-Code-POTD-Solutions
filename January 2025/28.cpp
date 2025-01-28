class Solution {
private:
    // Helper function to count the number of fishes in a connected component
    int calculateFishes(vector<vector<int>>& grid,
                        vector<vector<bool>>& visited, int row, int col) {
        // Check boundary conditions, water cells, or already visited cells
        if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size() ||
            grid[row][col] == 0 || visited[row][col]) {
            return 0;
        }

        // Mark the current cell as visited
        visited[row][col] = true;

        // Accumulate the fish count from the current cell and its neighbors
        return grid[row][col] + calculateFishes(grid, visited, row, col + 1) +
               calculateFishes(grid, visited, row, col - 1) +
               calculateFishes(grid, visited, row + 1, col) +
               calculateFishes(grid, visited, row - 1, col);
    }

public:
    int findMaxFish(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        int maxFishCount = 0;

        // A 2D vector to track visited cells
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));

        // Iterate through all cells in the grid
        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                // Start a DFS for unvisited land cells (fish available)
                if (grid[row][col] > 0 && !visited[row][col]) {
                    maxFishCount = max(
                        maxFishCount, calculateFishes(grid, visited, row, col));
                }
            }
        }

        // Return the maximum fish count found
        return maxFishCount;
    }
};
