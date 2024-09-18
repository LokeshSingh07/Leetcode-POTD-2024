// 1684. Count the Number of Consistent Strings

class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words){
        unordered_set<char> st;
        for(auto ch: allowed){
            st.insert(ch);
        }

        int cnt = 0;
        for(auto word: words){
            int flag = true;
            for(int i=0; i<word.size(); i++){
                if(st.find(word[i]) != st.end()) continue;
                else{
                    flag = false;
                    break;
                }
            }
            if(flag) cnt++;
        }

        return cnt;
    }
};