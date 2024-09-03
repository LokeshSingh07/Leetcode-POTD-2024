// 1945. Sum of Digits of String After Convert

class Solution {
public:
    string getValue(string s){
        int sum = 0;
        for(auto &ch: s){
            sum += (ch-'0');
        }
        return to_string(sum);
    }
    

    int getLucky(string s, int k) {
        int n = s.size();
        string strVal = "";

        for(int i=0; i<n; i++){
            strVal += to_string(s[i]-'a'+1);        //catch
        }


        while(k--){
            strVal = getValue(strVal);
        }


        return stoi(strVal);
    }
};

// TC: O(N+K)