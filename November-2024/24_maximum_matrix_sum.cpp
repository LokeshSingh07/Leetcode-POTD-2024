// 1975. Maximum Matrix Sum

class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        long long sum = 0;
        int negCnt=0, minAbsNeg=INT_MAX;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                sum += abs(matrix[i][j]);
                if(matrix[i][j] < 0) negCnt++;
                if(abs(matrix[i][j]) < minAbsNeg) minAbsNeg = abs(matrix[i][j]);
            }
        }

        if(negCnt % 2 == 0) return sum;
        return sum - 2*minAbsNeg;
    }
};