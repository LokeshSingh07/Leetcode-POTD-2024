// 773. Sliding Puzzle

class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        // step1: convert it into string
        string start = "";
        string target = "123450";
        for(int i=0; i<2; i++){
            for(int j=0; j<3; j++){
                start += to_string(board[i][j]);
            }
        }


        // step2: create a mapping that store moves of every index
        unordered_map<int, vector<int>> mp;
        mp[0] = {1,3};
        mp[1] = {0,2,4};
        mp[2] = {1,5};
        mp[3] = {0,4};
        mp[4] = {1,3,5};
        mp[5] = {2,4};

        // step3: apply BFS
        queue<string> q;
        unordered_set<string> vis;
        q.push(start);
        vis.insert(start);

        int level = 0;

        while(!q.empty()){
            int n = q.size();
            while(n--){
                string curr = q.front();
                q.pop();

                if(curr == target) return level;

                // swap the zeroKaIdx with its nbr nnode
                int zeroIndex = curr.find('0');
                for(auto idx : mp[zeroIndex]){
                    string newState = curr;
                    swap(newState[zeroIndex], newState[idx]);
                    if(!vis.count(newState)){
                        q.push(newState);
                        vis.insert(newState);
                    }
                }
            }

            level++;
        }

        return -1;
    }
};