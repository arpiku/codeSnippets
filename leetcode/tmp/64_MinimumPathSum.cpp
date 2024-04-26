#include "utils.h"
#include <iterator>
#include <limits>



int traverseDFS(std::vector<std::vector<int>>& grid,  int r, int c, int runningSum) { // This is too slow 
	if(r >= grid.size() || r < 0 || c < 0 || c >= grid[0].size())
		return std::numeric_limits<int>::max();
	int R = grid.size();
	int C = grid[0].size();
	runningSum += grid[r][c];
	if(r == R-1 && c == C-1) {
	return runningSum;
}
	int down = traverseDFS(grid,r+1,c,runningSum);
	int right = traverseDFS(grid,r,c+1,runningSum);
	return std::min(down,right);
}

std::vector<int> extractRow(const std::vector<std::vector<int>>& matrix2D, int n) {
	if(n>= matrix2D.at(0).size() || n < 0) {
		return {};		
	}	return *(matrix2D.begin() + n);
}


std::vector<int> extractColumn(const std::vector<std::vector<int>>& matrix2D, int n) {
	if(n>= matrix2D.size() || n < 0) {
		return {};		
	}
	std::vector<int> res; //Could have used std::copy 
	std::for_each(matrix2D.begin(),matrix2D.end(),[&](const std::vector<int>& row){res.push_back(row[n]);});
	return res;
}

int minPathSum(std::vector<std::vector<int>>& grid) {
    if (grid.empty() || grid[0].empty()) return 0; // Handle edge cases
    int R = grid.size();
    int C = grid[0].size();

    std::vector<std::vector<int>> dp(R, std::vector<int>(C, 0));
    dp[0][0] = grid[0][0];

	
    for (int i = 1; i < R; ++i) {
        dp[i][0] = dp[i - 1][0] + grid[i][0];
    }

    for (int j = 1; j < C; ++j) {
        dp[0][j] = dp[0][j - 1] + grid[0][j];
    }

    for (int i = 1; i < R; ++i) {
        for (int j = 1; j < C; ++j) {
            dp[i][j] = grid[i][j] + std::min(dp[i - 1][j], dp[i][j - 1]);
        }
    }


    return dp[R - 1][C - 1];
}


int _minPathSum(std::vector<std::vector<int>> &grid) {
  if (grid.empty() || grid[0].empty())
    return 0;
  int R = grid.size();
  int C = grid[0].size();

	std::vector<std::vector<int>> dp(R, std::vector<int>(C,0)); 
	auto firstRow = extractRow(grid,0);
	auto firstColumn = extractColumn(grid,0);

	dp[0] = firstRow;

	int i = 0;
	std::for_each(dp.begin(),dp.end(),[&](std::vector<int>& row){row[0] = firstColumn[i++];});

	for(auto& row:dp) {
		printVec(row);
	}

	for(int i = 1; i<R; ++i) {
		for(int j = 1; j<C; ++j) {
			dp[i][j] = grid[i][j] + std::min(dp[i-1][j], dp[i][j-1]);
		}
	}

		for(auto& row:dp) {
		printVec(row);
	}


	return dp[R-1][C-1];
}

int minPathSum2(std::vector<std::vector<int>>& grid) {
minPathSum2(grid);
	return 0;
}




int main() {
	std::vector<std::vector<int>> grid = {{1,3,1},{1,5,1},{4,2,1}};


minPathSum2(grid);

// std::cout << _minPathSum(grid);
	return 0;
}
