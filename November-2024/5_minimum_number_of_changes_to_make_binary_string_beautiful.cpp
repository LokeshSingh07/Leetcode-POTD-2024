// 2914. Minimum Number of Changes to Make Binary String Beautiful

class Solution {
public:
    int minChanges(string s) {
        int n = s.length();
        int changes = 0;
        int ch = s[0];
        int cnt=0;        


        for(int i=0; i<n; i++){
            if(s[i] == ch){
                cnt++;
            }
            else{
                if((cnt & 1) == 0){       // partition
                    cnt = 1;
                }
                else{
                    changes++;
                    cnt++;
                }
                ch = s[i];
            }
        }

        return changes;
    }
};




class Solution {
public:
    int minChanges(string s) {
        int n = s.length();
        int changes = 0;   

        for(int i=0; i<n; i=i+2){
            if(s[i] != s[i+1]) changes++;
        }

        return changes;
    }
};