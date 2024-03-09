class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        for(int i=0;i<n;i++){
            reverse(matrix[i].begin(),matrix[i].end());
        }
    }
};


class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size()-1;
        for(int i =0; i<=n; i++)
            for(int j = n-i; j>i; j--) {
                std::swap(matrix[i][j],matrix[n-j][i]);
                std::swap(matrix[n-j][i],matrix[n-i][n-j]);
                std::swap(matrix[n-i][n-j],matrix[j][n-i]);
            }
    }
};
