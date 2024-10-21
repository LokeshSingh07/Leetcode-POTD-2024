// 2406. Divide Intervals Into Minimum Number of Groups

class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        int n = intervals.size();
        priority_queue<int, vector<int>, greater<int>> pq;

        sort(begin(intervals), end(intervals));

        for(int i=0; i<n; i++){
            int arr = intervals[i][0];
            int dep = intervals[i][1];

            // check it on heap
            if(!pq.empty() && arr > pq.top()) pq.pop();

            pq.push(dep);
        }

        return pq.size();
    }
};