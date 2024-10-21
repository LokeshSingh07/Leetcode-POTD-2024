// 670. Maximum Swap

class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        if(num < 10) return num;

        vector<int> ans;
        int maxiIndex;
        for(int i=0; i<s.size()-1; i++){
            maxiIndex = i;
            for(int j=i; j<s.size(); j++){
                if(s[maxiIndex] <= s[j]){
                    maxiIndex = j;
                }
            }
            
            swap(s[maxiIndex], s[i]);
            ans.push_back(stoi(s));
            swap(s[maxiIndex], s[i]);
        }


        return *max_element(begin(ans), end(ans));
    }
};