// 2501. Longest Square Streak in an Array

class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        sort(begin(nums), end(nums));
        unordered_map<int,int> mp;

        int maxStreak = 0;
        for(auto it: nums){
            int root = (int)sqrt(it);
            if(root*root == it && mp.find(root) != mp.end()){
                mp[it] =  1+mp[root];
            }
            else{
                mp[it] = 1;
            }

            maxStreak = max(maxStreak, mp[it]);
        }

        return maxStreak < 2 ? -1 : maxStreak;
    }
};