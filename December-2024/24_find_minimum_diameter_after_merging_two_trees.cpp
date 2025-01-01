// 3203. Find Minimum Diameter After Merging Two Trees

class Solution {
public:
    pair<int,int> BFS(unordered_map<int,vector<int>> &adj, int src){
        queue<int> q;
        unordered_map<int,bool> visited;
    
        // initial state
        visited[src] = true;
        q.push(src);

        // logic
        int farthestNode = src;
        int length = 0;
        while(!q.empty()){
            int n = q.size();
            while(n--){
                int frontNode = q.front();
                farthestNode = frontNode;
                q.pop();

                for(auto nbr: adj[frontNode]){
                    if(!visited[nbr]){
                        q.push(nbr);
                        visited[nbr] = true;
                    }
                }


            }
            if(!q.empty()){ 
                length++;
            }
        }

        return {farthestNode, length};
    }

    int diameter(unordered_map<int,vector<int>> &adj){
        int randomNode = 0;
        auto [endNode, distance] = BFS(adj, randomNode);

        auto [anotherEndNode, diameter] = BFS(adj, endNode);
        return diameter;
    }


    unordered_map<int,vector<int>> buildAdjList(vector<vector<int>>& edges){
        unordered_map<int,vector<int>> adj;

        for(auto &edge: edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        return adj;
    }

    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        unordered_map<int,vector<int>> adj1 = buildAdjList(edges1);
        unordered_map<int,vector<int>> adj2 = buildAdjList(edges2);

        int d1 = diameter(adj1);
        int d2 = diameter(adj2);

        int combined = (d1+1)/2 + (d2+1)/2 + 1;

        return max(combined, max(d1,d2));
    }
};