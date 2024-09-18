// 179. Largest Number

class Solution {
public:
    static bool comp(string a, string b){
        return a+b > b+a;
    }

    string largestNumber(vector<int>& nums){
        // step1: convert it into string
        int n = nums.size();
        vector<string> vec;
        for(auto i:nums){
            vec.push_back(to_string(i));
        }

        // step2: sort it in lexicographically (dictionary)
        sort(vec.begin(), vec.end(), comp);

        // step3: return maximum possible ans
        if(vec[0] == "0") return "0";               // catch

        string ans = "";
        for(auto it: vec){
            ans += it;
        }
        
        return ans;
    }
};