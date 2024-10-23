// 1593. Split a String Into the Max Number of Unique Substrings

class Solution {
public:
    int maxCnt = 0;

    void solveRec(string s, int i, unordered_set<string> se, int currCnt){
        if(i>= s.size()){
            maxCnt = max(maxCnt, currCnt);
            return;
        }

        for(int j=i; j<s.size(); j++){
            string temp = s.substr(i, j-i+1);
            if(se.find(temp) == se.end()){              // not present
                se.insert(temp);                        // DO 
                solveRec(s, j+1, se, currCnt+1);        // EXPLORE

                // UNDO
                se.erase(temp);
            }
        }
    }

    int maxUniqueSplit(string s) {
        unordered_set<string> se;
        int i=0, currCnt=0;

        solveRec(s, i, se, currCnt);

        return maxCnt;
    }
};