// 1346. Check If N and Its Double Exist

class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        int n = arr.size();
        for(int i=0; i<n-1; i++){
            for(int j=i+1; j<n; j++){
                if(arr[i] == 2*arr[j] || 2*arr[i] == arr[j]) return true;
            }
        }

        return false;
    }
};