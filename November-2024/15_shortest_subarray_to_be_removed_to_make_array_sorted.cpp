// 1574. Shortest Subarray to be Removed to Make Array Sorted

class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size();
        int i=0;int j=n-1;

        // find the correct jth pointer
        while(j>0 && arr[j-1] <= arr[j]){
            j--;
        }

        // if(j==0) return 0;
        int removeCnt = j;      // catch

        // find the correct ith pointer
        while(i<j && (i==0 || arr[i-1] <= arr[i])){
            while(j<n && arr[i] > arr[j]){
                j++;
            }

            removeCnt = min(removeCnt, j-i-1);
            i++;
        }

        return removeCnt;
    }
};