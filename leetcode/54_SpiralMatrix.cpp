class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
    if (matrix.empty()) return {};

    std::vector<int> res;

    int top = 0;
    int bottom = matrix.size() - 1;
    int left = 0;
    int right = matrix[0].size() - 1;

    while (top <= bottom && left <= right) {
        for (int j = left; j <= right; ++j) {
            res.push_back(matrix[top][j]);
        }
        top++;
        for (int i = top; i <= bottom; ++i) {
            res.push_back(matrix[i][right]);
        }
        right--;

        // Make sure we are now going to traverse a valid row.
        if (top <= bottom) {
            // Traverse from right to left.
            for (int j = right; j >= left; --j) {
                res.push_back(matrix[bottom][j]);
            }
            bottom--;
        }

        // Make sure we are now going to traverse a valid column.
        if (left <= right) {
            // Traverse upwards.
            for (int i = bottom; i >= top; --i) {
                res.push_back(matrix[i][left]);
            }
            left++;
        }
    }

    return res;
    }
};
