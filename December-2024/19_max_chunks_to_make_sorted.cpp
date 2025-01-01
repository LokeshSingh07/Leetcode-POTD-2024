// 769. Max Chunks To Make Sorted

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        int chunk = 0;
        vector<int> prefixMax(n);
        vector<int> suffixMin(n);

        // prefix
        prefixMax[0] = arr[0];
        for(int i=1; i<n; i++){
            prefixMax[i] = max(arr[i], prefixMax[i-1]);
        }

        // suffix 
        suffixMin[n-1] = arr[n-1];
        for(int i=n-2; i>=0; i--){
            suffixMin[i] = min(arr[i], suffixMin[i+1]);
        }

        for(int i=0; i<n; i++){
            int maxi = prefixMax[i];
            int mini = (i < n-1) ? suffixMin[i+1] : INT_MAX;

            if(maxi < mini) chunk++;
        }

        return chunk;
    }
};