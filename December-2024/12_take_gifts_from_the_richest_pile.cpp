// 2558. Take Gifts From the Richest Pile

class Solution {
public:
    #define P long long
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<P> pq;   // maxHeap

        for(auto it: gifts){
            pq.push(it);
        }

        while(k--){
            P sq = sqrt(pq.top());
            pq.pop();
            pq.push(sq);
        }

        P ans = 0;
        while(!pq.empty()){
            P val = pq.top();
            pq.pop();
            ans += val;
        }

        return ans;
    }
};