// 1894. Find the Student that Will Replace the Chalk

class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long acc = accumulate(chalk.begin(), chalk.end(), 0LL);
        k = k % acc;

        for(int i=0; i<chalk.size(); i++){
            if(chalk[i] > k) return i;
            k -= chalk[i];
        }

        return -1;
    }
};


// TC: O(n)