// 1813. Sentence Similarity III

class Solution {
public:
    bool areSentencesSimilar(string s1, string s2) {
        if(s1.length() < s2.length()) swap(s1, s2);

        vector<string> v1, v2;
        stringstream ss1(s1);
        string token;
        while(ss1 >> token){
            v1.push_back(token);
        }

        stringstream ss2(s2);
        while(ss2 >> token){
            v2.push_back(token);
        }

        // two pointer
        int i=0, j=v1.size()-1;
        int k=0, l=v2.size()-1;
        
        while(k <= l){
            if(v1[i] == v2[k]){
                i++;
                k++;
            }
            else if(v1[j] == v2[l]){
                j--;
                l--;
            }
            else break;
        }

        return l<k;
    }
};