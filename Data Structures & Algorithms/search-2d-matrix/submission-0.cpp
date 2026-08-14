class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int l = 0, e = (m * n) - 1;
        while(l <= e) {
            int mid = (l + e) / 2;
            int r = mid / n;
            int c = mid % n;

            if(matrix[r][c] == target) return true;
            if(matrix[r][c] < target) {
                l = mid + 1;
            } else {
                e = mid - 1;
            }
        }
        return false;
    }
};