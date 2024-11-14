// 2064. Minimized Maximum of Products Distributed to Any Store

class Solution {
public:
    bool check(int n, vector<int>& quantities, int tar){
        int store = 0;

        for(auto product: quantities){
            store += (product + tar -1)/tar;
            if(store > n) return false;
        }
        
        return true;
    }

    int minimizedMaximum(int n, vector<int>& quantities) {
        int s=1;
        int e=*max_element(begin(quantities), end(quantities));
        int ans = -1;

        while(s <= e){
            int mid = s+(e-s)/2;

            if(check(n, quantities, mid)){
                ans = mid;
                e = mid-1;
            }
            else{
                s = mid+1;
            }
        }

        return ans;
    }
};