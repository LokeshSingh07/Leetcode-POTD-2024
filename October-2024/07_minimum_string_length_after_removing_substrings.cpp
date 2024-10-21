// 2696. Minimum String Length After Removing Substrings

class Solution {
public:
    int minLength(string s) {
        stack<int> st;
        int n = s.length();

        for(int i=0; i<n; i++){
            int ele = s[i];
            if(!st.empty() && ((st.top()=='C' && ele=='D') || (st.top()=='A' && ele=='B'))) st.pop();
            else st.push(s[i]);
        }

        return st.size();
    }
};