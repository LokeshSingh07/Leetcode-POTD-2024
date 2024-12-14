// 2097. Valid Arrangement of Pairs

class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        unordered_map<int, vector<int>> adj;
        unordered_map<int, int> indegree, outdegree;

        // create in &out degree
        for(auto edge : pairs){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            outdegree[u]++;
            indegree[v]++;
        }


        // find the starting node
        int startNode = pairs[0][0];        // catch
        for(auto it: adj){
            int node = it.first;
            if(outdegree[node] - indegree[node] == 1){
                startNode = node;
                break;
            }
        }


        // traverse using DFS (Euler)       // isme glti kri thi
        vector<int> EulerPath;
        stack<int> st;
        st.push(startNode);

        while(!st.empty()){
            int curr = st.top();
            if(!adj[curr].empty()){
                st.push(adj[curr].back());
                adj[curr].pop_back();
            }
            else{
                EulerPath.push_back(curr);
                st.pop();
            }
        }


        // 1 - 5 - 4 - 9 - 11
        reverse(begin(EulerPath), end(EulerPath));
        vector<vector<int>> ans;
        for(int i=0; i<EulerPath.size()-1; i++){
            ans.push_back({EulerPath[i], EulerPath[i+1]});
        }


        return ans;
    }
};