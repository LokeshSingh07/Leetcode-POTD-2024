// 3243. Shortest Distance After Road Addition Queries I

class Solution {
public:
    void BFS(int &n, vector<int> query, unordered_map<int,vector<int>> &adj, vector<int> &ans){
        queue<int> q;
        unordered_map<int, bool> vis;
        int level = 0;
        adj[query[0]].push_back(query[1]);      // catch

        q.push(0);      //catch
        vis[0] = true;

        while(!q.empty()){
            int size = q.size();

            while(size--){
                int frontNode = q.front();
                q.pop();

                if(frontNode == n-1){
                    ans.push_back(level);
                    return;
                }

                for(auto nbr: adj[frontNode]){
                    if(!vis[nbr]){
                        vis[nbr] = true;
                        q.push(nbr);
                    }
                }
            }
            level++;
        }

    }

    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        int x = queries.size();
        int y = queries[0].size();
        vector<int> ans;

        // create adjList
        unordered_map<int, vector<int>> adj;
        for(int i=0; i<n-1; i++){
            adj[i] = {i+1};
        }


        // apply BFS fro every query
        for(auto &query: queries){
            BFS(n, query, adj, ans);
        }

        return ans;
    }
};