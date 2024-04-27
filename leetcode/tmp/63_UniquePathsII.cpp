#include "utils.h"

int _pathFinder(std::vector<std::vector<int>> &grid, int r, int c) {

  // Why do my recursive solutins fail :( at leetcode

  if (r >= grid.size() || r < 0 || c < 0 || c >= grid[0].size() ||
      grid[r][c] == 1) {
    return 0;
  }
  if (r == grid.size() - 1 && c == grid[0].size() - 1) {
    return 1;
  }
  int pathsRight = _pathFinder(grid, r, c + 1);
  int pathsDown = _pathFinder(grid, r + 1, c);
  return pathsRight + pathsDown;
}

int _PathFinderDynamic(std::vector<std::vector<int>> &obstacleGrid) {
  int m = obstacleGrid.size();
  int n = obstacleGrid[0].size();

  std::vector<std::vector<int>> dp(m, std::vector<int>(n, 0));

  dp[0][0] = (obstacleGrid[0][0] == 0) ? 1 : 0;

  for (int i = 1; i < m; ++i) {
    dp[i][0] = (obstacleGrid[i][0] == 0 && dp[i - 1][0]) ? 1 : 0;
  }

  for (int j = 1; j < n; ++j) {
    dp[0][j] = (obstacleGrid[0][j] == 0 && dp[0][j - 1]) ? 1 : 0;
  }

  for (int i = 1; i < m; ++i) {
    for (int j = 1; j < n; ++j) {
      if (obstacleGrid[i][j] == 0) {
        dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
      }
    }
  }

  return dp[m - 1][n - 1];
}

int uniquePathsWithObstacles(std::vector<std::vector<int>> &obstacleGrid) {
  return _PathFinderDynamic(obstacleGrid);
}

int main() {
  std::vector<std::vector<int>> vv = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};

  LOG(uniquePathsWithObstacles(vv));

  return 0;
}
