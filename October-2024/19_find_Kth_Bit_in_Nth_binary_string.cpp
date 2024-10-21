// 1545. Find Kth Bit in Nth Binary String

class Solution {
public:
    string ans;
    string flipReverse(string s){
        int i=0;
        int j=s.size()-1;

        while(i <= j){
            swap(s[i], s[j]);
            s[i] = s[i]=='1' ? '0' : '1';
            if(i != j)
                s[j] = s[j] == '0'? '1' : '0';
            i++;
            j--;
        }
        return s;
    }
    void solveRec(int n, int k, int i, string s){
        if(i==n){
            ans = s;
            return;
        }

        // build ans
        string temp = "";
        temp = s + "1" + flipReverse(s);
        solveRec(n, k, i+1, temp);
    }

    char findKthBit(int n, int k) {
        solveRec(n, k, 1, "0");

        return ans[k-1];
    }
};