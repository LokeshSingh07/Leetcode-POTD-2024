// 1331. Rank Transform of an Array

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        if(!n) return {};
        vector<pair<int,int>> temp(n);     // value, index
        
        for(int i=0; i <n; i++){
            temp[i].first = arr[i];
            temp[i].second = i;
        }

        sort(begin(temp), end(temp));

        // assign rank
        vector<int> rank(n);
        int cnt = 1;
        rank[temp[0].second] = cnt;
        for(int i=1; i<n; i++){
            if(temp[i].first != temp[i-1].first){
                cnt++;
            }
            rank[temp[i].second] = cnt;
        }

        return rank;
    }
};