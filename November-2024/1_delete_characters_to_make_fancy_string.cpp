// 1957. Delete Characters to Make Fancy String

class Solution {
public:
    string makeFancyString(string s) {
        int n=s.size();
        string result="";
        result.push_back(s[0]);
        int cnt=1;

        for(int i=1; i<n; i++){
            if(s[i] == result.back()){
                cnt++;
                if(cnt < 3){
                    result.push_back(s[i]);
                }
            }
            else{
                cnt=1;
                result.push_back(s[i]);
            }
        }

        return result;
    }
};