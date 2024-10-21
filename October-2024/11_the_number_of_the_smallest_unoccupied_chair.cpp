// 1942. The Number of the Smallest Unoccupied Chair

class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n = times.size();
        vector<int> chairs(n, -1);
        int targetArrTime = times[targetFriend][0];

        sort(begin(times), end(times));

        for(auto &p: times){
            int arr = p[0];
            int dep = p[1];

            // check
            for(int i=0; i<n; i++){
                if(chairs[i] <= arr){
                    chairs[i] = dep;
                    if(arr == targetArrTime) return i;
                    break;
                }
            }
        }

        return -1;
    }
};