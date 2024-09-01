// 2022. Convert 1D Array Into 2D Array

class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        int size = original.size();
        if(size != m*n) return {};

        vector<vector<int>> vec(m, vector<int>(n));

        int idx = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                vec[i][j] = original[idx++];
            }
        }

        return vec;
    }
};


// TC: O(m*n)