// 2872. Maximum Number of K-Divisible Components

class Solution {
public:

    long long dfs(int src, int parent, unordered_map<int,vector<int>> &adjList, vector<int> &values, int &k, int &componentCount){
        long long sum = 0;

        for(int nbr: adjList[src]){
            if(nbr != parent){
                sum += dfs(nbr, src, adjList, values, k, componentCount);
            }
        }

        // backtrack
        sum += values[src];
        if((sum % k) == 0){
            componentCount++;
            sum=0;
        }
        return sum;
    }

    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        // create adjList
        unordered_map<int,vector<int>> adjList;
        for(auto edge : edges){
            int u = edge[0];
            int v = edge[1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        int parent = -1;
        int componentCount=0;
        dfs(0, parent, adjList, values, k, componentCount);
        return componentCount;
    }
};