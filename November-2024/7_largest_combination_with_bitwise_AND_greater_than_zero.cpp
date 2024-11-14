// 2275. Largest Combination With Bitwise AND Greater Than Zero

class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int maxGrpSize = 0;

        for(int i=0; i<24; i++){
            int count = 0;
            for(int num: candidates){
                if((num & (1 << i)) != 0){
                    count++;
                }
            }

            maxGrpSize = max(maxGrpSize, count);
        }

        return maxGrpSize;
    }
};