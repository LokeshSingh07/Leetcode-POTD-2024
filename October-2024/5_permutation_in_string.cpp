// 567. Permutation in String

class Solution {
public:
    void sortString(string &s1){
        sort(s1.begin(), s1.end());
    }

    bool checkInclusion(string s1, string s2) {
        int len1 = s1.size();
        int len2 = s2.size();

        sortString(s1);

        // process first window
        string tempStr = s2.substr(0, len1);
        sortString(tempStr);
        if(tempStr == s1) return true;

        // process remaining window
        int i=1;
        int j=len1;
        while(j < len2){
            tempStr = s2.substr(i, len1);
            sortString(tempStr);
            if(tempStr == s1) return true;
            i++;
            j++;
        }

        return false;
    }
};