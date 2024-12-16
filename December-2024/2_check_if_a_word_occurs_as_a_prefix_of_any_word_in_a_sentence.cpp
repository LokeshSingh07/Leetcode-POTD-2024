// 1455. Check If a Word Occurs As a Prefix of Any Word in a Sentence

class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int cnt = 1;
        stringstream ss(sentence);
        string word;

        while(ss >> word){
            if(word.substr(0, searchWord.size()) == searchWord) return cnt;
            cnt++;
        }

        return -1;
    }
};