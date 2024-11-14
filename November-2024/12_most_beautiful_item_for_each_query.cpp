// 2070. Most Beautiful Item for Each Query

class Solution {
public:
    int BS(vector<vector<int>>& items, int targ){
        int s=0;
        int e=items.size()-1;
        int maxBeauty = 0;

        while(s<=e){
            int mid = s+(e-s)/2;
            if(targ >= items[mid][0]){
                maxBeauty = max(maxBeauty, items[mid][1]);
                s = mid+1;
            }
            else e = mid-1;
        }

        return maxBeauty;
    }

    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        int n = items.size();
        int maxi = INT_MIN;
        vector<int> ans;
        sort(items.begin(), items.end());

        for(int i=0; i<n; i++){
            maxi = max(maxi, items[i][1]);
            items[i][1] = maxi;
        }

        for(int it: queries){
            int ele = BS(items, it);
            ans.push_back(ele);
        }

        return ans;
    }
};