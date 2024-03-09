class Solution {
public:
    bool searchMatrix(const vector<vector<int>>& matrix,const int& target) {
        const int R = matrix.size();
        const int C = matrix[0].size();
        int r = 0; int c = C-1;
        while(r<R && c >=0) {
            if(matrix[r][c] == target)
                return 1;
            if(matrix[r][c] < target) {
                r++;
            }
            else {
                c--;
            }
        }return 0;
    } 
};
