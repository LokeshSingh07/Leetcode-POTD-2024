// 2109. Adding Spaces to a String

class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        int n = s.size();
        string t = "";
        int i = 0;
        int j=0;


        while(i<n){
            if(j<spaces.size() && i == spaces[j]){
                t += " ";
                j++;
            }
            t += s[i];
            i++;
        }

        return t;
    }
};