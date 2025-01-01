// 2940. Find Building Where Alice and Bob Can Meet

class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        int n = heights.size();
        int m = queries.size();
        vector<vector<vector<int>>> qs(n);
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        vector<int> ans(m, -1);

        for(int q=0; q<m; q++){
            int a = queries[q][0];
            int b = queries[q][1];
            int mini = min(a, b);
            int maxi = max(a, b);
            
            if(mini == maxi || heights[maxi] > heights[mini])
                ans[q] = maxi;
            else
                qs[maxi].push_back({max(heights[maxi], heights[mini]), q});
        }


        for(int i=0; i<n; i++){
            while(!pq.empty() && pq.top()[0] < heights[i]){
                ans[pq.top()[1]] = i;
                pq.pop();
            }

            for(auto ele : qs[i]){
                pq.push(ele);
            }
        }

        return ans;
    }
};