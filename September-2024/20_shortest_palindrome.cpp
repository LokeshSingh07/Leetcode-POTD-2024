// 214. Shortest Palindrome


// Memory Limit Exceeded    -- TC: O(n^2)
class Solution {
public:
    string shortestPalindrome(string s){
        int n = s.size();
        string rev = s;
        reverse(rev.begin(), rev.end());

        for(int i=0; i<n; i++){
            if(s.substr(0, n-i) == rev.substr(i)){      // prefix of s == suffix of rev
                string ans = "";
                ans += rev.substr(0, i) + s;
                return ans;
            }
        }

        return rev + s;     // catch
    }
};


// TC: O(n^2)
class Solution {
public:
    string shortestPalindrome(string s){
        int n = s.size();
        string rev = s;
        reverse(rev.begin(), rev.end());

        for(int i=0; i<n; i++){
            if(memcmp(s.c_str(), rev.c_str()+i, n-i) == 0){      // prefix of s == suffix of rev
                string ans = "";
                ans = rev.substr(0, i) + s;
                return ans;
            }
        }

        return rev + s;     // catch
    }
};