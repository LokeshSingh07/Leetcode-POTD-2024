// 386. Lexicographical Numbers


// // TC: O(n)
// SC: O(1)
class Solution {
public:
    void solve(int currNum, int n, vector<int> &result){
        if(currNum >  n) return;
        result.push_back(currNum);

        // explore possibility
        for(int i=0; i<=9; i++){
            int newNum = (currNum*10) + i;
            if(newNum > n) return;
            solve(newNum, n, result);
        }
    }

    vector<int> lexicalOrder(int n) {
        vector<int> result;

        for(int i=1; i<=9; i++)
            solve(i, n, result);

        return result;
    }
};





// TC: O(nlogn)
// SC: O(n)
#include<bits/stdc++.h>
using namespace std;

static bool comp(int a, int b){
	return to_string(a) < to_string(b);
}

int main(){
    int n = 13;
    vector<int> ans;

    for(int i=1; i<=n; i++){
    	ans.push_back(i);
    }

    sort(ans.begin(), ans.end(), comp);


    for(auto it:ans){
    	cout<<it<<" ";
    }


return 0;
}

