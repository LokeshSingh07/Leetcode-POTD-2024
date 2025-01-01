// 1475. Final Prices With a Special Discount in a Shop

class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        int i=0;
        vector<int> ans;

        while(i<n){
            int curr = prices[i];
            // min index
            int j = i+1;
            while(j<n && prices[j] > prices[i]){
                j++;
            }

            // min index mil gaya h
            if(j < n) ans.push_back(prices[i]-prices[j]);
            else ans.push_back(prices[i]);
            i++;
        }

        return ans;
    }
};