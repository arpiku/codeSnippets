class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        std::vector<std::pair<int,int>> toChange;
        int R = matrix.size();
        int C = matrix[0].size();

        for(int i=0; i<matrix.size(); i++) 
            for(int j=0; j<matrix[0].size(); j++) {
                if(matrix.at(i).at(j) == 0)
                    toChange.push_back({i,j});
            }
        

        
        for(auto& rc:toChange) {
            int r = rc.first;
            int c = rc.second;
            std::cout << R << std::endl;

            for(int i = 0; i<C; i++) {
                matrix[r][i] = 0;
            }
            for(int i = 0; i<R; i++) {
                matrix[i][c] = 0;

            }
        }

        return;
        
    }
};
