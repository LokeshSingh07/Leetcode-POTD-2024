// 2981. Find Longest Special Substring That Occurs Thrice I

class Solution {
public:
    int maximumLength(string s) {
        int n = s.size();
        unordered_map<string,int> mp;

        for(int i=0; i<n; i++){
            string temp = "";
            for(int j=i; j<n; j++){
                if(temp == "" || s[j] == s[j-1]){
                    temp += s[j];
                    mp[temp]++; 
                }
                else break;
            }
        }

        int res = 0;
        for(auto it:mp){
            string str = it.first;
            int cnt = it.second;

            if(cnt>2){
                int len = str.length();
                res = max(res, len);
            }
        }

        return res == 0 ? -1 : res;
    }
};