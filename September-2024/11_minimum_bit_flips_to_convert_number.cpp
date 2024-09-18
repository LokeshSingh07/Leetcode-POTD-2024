// 2220. Minimum Bit Flips to Convert Number

class Solution {
public:
    int minBitFlips(int start, int goal) {
        int XOR = start ^ goal;
        int count=0;

        while(XOR){
            XOR = XOR & (XOR-1);
            count++;
        }
        return count;
    }
};



class Solution {
public:
    int minBitFlips(int start, int goal) {
        int XOR = start ^ goal;
        return __builtin_popcount(XOR);
    }
};