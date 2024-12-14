// 2924. Find Champion II

class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> indegree(n, 0);
        int m = edges.size();

        for(int i=0; i<m; i++){
            indegree[edges[i][1]]++;
        }   

        int cnt = 0;
        int node;
        for(int i=0; i<n; i++){
            if(indegree[i] == 0){
                node = i;
                cnt++;
            } 
        }

        return cnt>1 ? -1 : node;
    }
};