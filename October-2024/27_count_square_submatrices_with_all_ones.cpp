// 1277. Count Square Submatrices with All Ones

class Solution {
public:
    int solveRec(vector<vector<int>> &mat, int i, int j, vector<vector<int>> &dp){
        if(i>=mat.size() || j>=mat[0].size()) return 0;
        if(mat[i][j] == 0) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        int right = solveRec(mat, i+1, j, dp);
        int diagonal = solveRec(mat, i+1, j+1, dp);
        int down = solveRec(mat, i, j+1, dp);

        return dp[i][j] = 1+min(right, min(diagonal, down));
    }

    int countSquares(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int result = 0;
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(mat[i][j]){
                    result += solveRec(mat, i, j, dp);
                }
            }
        }

        return result;
    }
};