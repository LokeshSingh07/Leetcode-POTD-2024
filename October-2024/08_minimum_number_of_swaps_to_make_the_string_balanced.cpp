// 1963. Minimum Number of Swaps to Make the String Balanced

class Solution {
public:
    int minSwaps(string s) {
        stack<int> st;
        int n = s.length();

        for(int i=0; i<n; i++){
            char ch = s[i];
            if(!st.empty() && st.top()=='[' && ch == ']') st.pop();
            else st.push(ch);
        }

        return ((st.size()/2)+1)/2;
    }
};