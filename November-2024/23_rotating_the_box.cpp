// 1861. Rotating the Box

class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int m = box.size();
        int n = box[0].size();

        vector<vector<char>> res(n, vector<char>(m));

        // transpose of matrix
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                res[j][i] = box[i][j];
            }
        }

        // rotate by 90 deg
        for(vector<char> &row : res){
            reverse(begin(row), end(row));
        }


        // simulation -> apply gravity
        for(int j=0; j<m; j++){
            for(int i=n-1; i>=0; i--){
                if(res[i][j] == '.'){
                    int stoneRow = -1;
                    int k = i-1;
                    while(k >= 0 && res[k][j] != '*'){
                        if(res[k][j] == '#'){
                            stoneRow = k;
                            break;
                        }
                        k--;
                    }
                
                    if(stoneRow != -1){
                        res[i][j] = '#';
                        res[stoneRow][j] = '.';
                    }
                }
            }
        }

        return res;
    }
};