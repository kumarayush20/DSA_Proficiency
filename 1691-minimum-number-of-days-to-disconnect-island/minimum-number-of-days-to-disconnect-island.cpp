/*
Intuition
First of all, looking at the problem statement, we can observe that we need to make the grid disconnected by turning some land cells into water. If the grid has more than one island initially, it is already disconnected, and no further steps are required. However, if it is connected, we need to figure out the minimum number of days required to disconnect it. So, I decided to use Depth-First Search (DFS) to count the number of islands. If we remove land cells and recheck the number of islands, we can figure out the minimum days needed to achieve a disconnected grid.

Approach
Step 1: Initial Check for Connectivity:
Before diving into removing any land cells, first, I checked if the grid is already disconnected by counting the number of islands. This was done using a DFS traversal. If the grid is already disconnected (i.e., it has more than one island), then no days are needed, and we can return 0 immediately.
Step 2: Try Removing Each Land Cell:
Since the grid might still be connected, I decided to try removing each land cell one by one. For every land cell (i, j), I temporarily changed it to water (grid[i][j] = 0) and then rechecked the number of islands using DFS. If the grid becomes disconnected after removing a single cell, it means we only needed one day to achieve this, and I can return 1. If removing a single cell doesn't work, I restored the cell back to land (grid[i][j] = 1) and moved on to the next cell.
Step 3: Handling Cases Where One Day Is Not Enough:
If removing a single land cell is not enough to disconnect the grid, I realized that it would require at least 2 days. This is because a fully connected grid of land cells always needs two changes to disconnect.

Example
Let's walk through an example with grid = [[0,1,1,0],[0,1,1,0],[0,0,0,0]]:

Step 1:
First, I checked if the grid is already disconnected. It was not; the grid had one large island.

Step 2:
Then, I began testing each land cell. For instance, by removing the cell at grid[1][1], the grid still remained connected. But when I removed grid[0][2], the grid split into two islands, making it disconnected. So, in this case, I found that it took at least 2 days to disconnect the grid.

Complexity
Time Complexity: O(m * n * (m + n)) where m and n are the dimensions of the grid. The DFS operation, which checks the number of islands, is run for each cell.

Space Complexity: O(m * n) which accounts for the space used by the DFS stack and the grid itself.
*/

class Solution {
public:
    int minDays(vector<vector<int>>& grid) {
        auto count_islands = [&]() -> int {
            vector<vector<int>> seen(grid.size(), vector<int>(grid[0].size(), 0));
            int islands = 0;
            
            function<void(int, int)> dfs = [&](int r, int c) {
                seen[r][c] = 1;
                for (auto [dr, dc] : {pair{-1, 0}, {1, 0}, {0, -1}, {0, 1}}) {
                    int nr = r + dr, nc = c + dc;
                    if (nr >= 0 && nr < grid.size() && nc >= 0 && nc < grid[0].size() && grid[nr][nc] == 1 && !seen[nr][nc]) {
                        dfs(nr, nc);
                    }
                }
            };
            
            for (int i = 0; i < grid.size(); i++) {
                for (int j = 0; j < grid[0].size(); j++) {
                    if (grid[i][j] == 1 && !seen[i][j]) {
                        islands++;
                        dfs(i, j);
                    }
                }
            }
            return islands;
        };
        
        if (count_islands() != 1) return 0;
        
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    grid[i][j] = 0;
                    if (count_islands() != 1) return 1;
                    grid[i][j] = 1;
                }
            }
        }
        
        return 2;
    }
};