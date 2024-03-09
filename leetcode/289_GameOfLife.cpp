class Solution {
public:


int accessElement(const std::vector<std::vector<int>>& matrix, std::pair<int,int>& coordinate) {
  int res = 0;
  try {
    res = matrix.at(coordinate.first).at(coordinate.second);
  }
  catch (const std::out_of_range& e) {
    return -1;
  }
  return res;
}


int liveNeighbours(const std::vector<std::vector<int>>& matrix, std::pair<int,int>& coordinate) {
  uint liveCount = 0;
  for(int i = -1; i <=1; i++)
    for(int j = -1; j<=1; j++) {
      if(i == 0 && j == 0) continue;
      int r = coordinate.first + i;
      int c = coordinate.second + j;
      std::pair<int,int> adjCoordinates = std::make_pair(r,c);
      if(accessElement(matrix,adjCoordinates) == 1) {
        liveCount++;
      }
    }
  return liveCount;
}

void gameOfLife(std::vector<std::vector<int>>& board) {
  size_t R = board.size();
  size_t C = board[0].size();

  std::vector<std::vector<int>> changes;
  for(int i = 0; i<R; i++)
    for(int j = 0; j<C; j++) {
      std::pair<int,int> c = std::make_pair(i,j);
      int liveCount = liveNeighbours(board,c);
      int alive = accessElement(board,c);
      if(alive && (liveCount < 2 || liveCount >3)) {
        changes.push_back({i,j,0});
      } else if (!alive && liveCount == 3){
        changes.push_back({i,j,1});
      }
    }

  for(auto& change:changes) {
    board[change[0]][change[1]] = change[2];
  }
  
}


};
