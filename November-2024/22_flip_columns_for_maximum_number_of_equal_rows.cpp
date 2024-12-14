// 1072. Flip Columns For Maximum Number of Equal Rows

class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        int maxRows = 0;

        for(auto currRow : matrix){
            vector<int> inverted(n);

            // flip the row
            for(int j=0; j<n; j++){
                inverted[j] = 1 - currRow[j];
            }

            int cnt = 0;
            for(auto row : matrix){
                if(row == inverted || row == currRow){
                    cnt++;
                }
            }

            maxRows = max(maxRows, cnt);
        }

        return maxRows;
    }
};