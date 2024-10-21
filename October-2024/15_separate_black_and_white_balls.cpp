// 2938. Separate Black and White Balls

class Solution {
public:
    long long minimumSteps(string s) {
        long long int swap = 0;
        long long int cnt = 0;

        for(int i=0; i<s.size(); i++){
            if(s[i] == '0'){
                swap += cnt;
            }
            else{
                cnt++;
            }
        }


        return swap;
    }
};