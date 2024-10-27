// 1233. Remove Sub-Folders from the Filesystem

class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        unordered_set<string> st(begin(folder), end(folder));
        vector<string> result;

        for(auto currFolder: folder){
            string tempFolder = currFolder;
            bool isPresent = false;
            // trim and check
            while(currFolder != ""){
                size_t pos = currFolder.find_last_of('/');
                currFolder = currFolder.substr(0, pos);

                // if it is present in set
                if(st.find(currFolder) != st.end()){
                    isPresent = true;
                    break;
                }
            }

            if(!isPresent) result.push_back(tempFolder);
        }

        return result;
    }
};