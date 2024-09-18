// 884. Uncommon Words from Two Sentences

// prerequisite stringstream

class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> mp;

        stringstream str1(s1);
        stringstream str2(s2);
        string word = "";

        while(str1 >> word) mp[word]++;
        while(str2 >> word) mp[word]++;

        vector<string> ans;
        for(auto &it: mp){
            if(it.second == 1) ans.push_back(it.first);
        }

        return ans;
    }
};