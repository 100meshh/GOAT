class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());
        vector<string> result;
        for(auto x: folder){
            if(result.empty() || x.find(result.back()+"/")!=0) result.push_back(x);
        }
        return result;
    }
};