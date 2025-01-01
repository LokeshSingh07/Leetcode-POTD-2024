// 2182. Construct String With Repeat Limit

class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        int n = s.size();
        vector<int> vec(26, 0);
        string result;

        // mapping
        for(int i=0; i<n; i++){
            char ch = s[i];
            vec[ch-'a']++;
        }

        int i= 25;
        while(i >= 0){
            if(vec[i] == 0){
                i--;
                continue;
            }

            char ch = i + 'a';
            int freq = min(vec[i], repeatLimit);

            result.append(freq, ch);
            vec[i] -= freq;

            if(vec[i] > 0){
                // find next largest char
                int j = i-1;
                while(j>=0 && vec[j] == 0){
                    j--;
                }

                if(j < 0) break;
                result.push_back('a' + j);
                vec[j]--;
            }
        }

        return result;
    }
};