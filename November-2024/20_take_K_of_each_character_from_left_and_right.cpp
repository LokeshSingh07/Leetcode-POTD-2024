// 2516. Take K of Each Character From Left and Right

class Solution {
public:
    int takeCharacters(string s, int k) {
        int n = s.size();

        // count the freq of a,b,c
        int cnt_a=0, cnt_b=0, cnt_c=0;
        for(char &ch : s){
            if(ch=='a') cnt_a++;
            else if(ch=='b') cnt_b++;
            else cnt_c++;
        }

        // catch 
        if(cnt_a < k || cnt_b < k || cnt_c < k) return -1;


        int i=0;
        int j=0;
        int maxiWindowSize = 0;

        while(j<n){
            if(s[j] == 'a') cnt_a--;
            else if(s[j]=='b') cnt_b--;
            else  cnt_c--;

            // if cnt >= k add -> same way cnt<k remove (shrink window size)
            while(i<=j && (cnt_a < k || cnt_b < k || cnt_c < k)){
                if(s[i] == 'a') cnt_a++;
                else if(s[i]=='b') cnt_b++;
                else  cnt_c++;
                i++;
            }

            maxiWindowSize = max(maxiWindowSize, j-i+1);
            j++;
        }

        return n-maxiWindowSize;
    }
};