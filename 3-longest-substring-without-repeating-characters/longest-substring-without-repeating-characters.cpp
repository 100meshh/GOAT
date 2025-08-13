class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int first=0,second=0,count=0,length=0;
        vector<bool>visited(256,0);
        while(second<s.size()){
            while(visited[s[second]]){
                visited[s[first]]=0;
                first++;
            }
            visited[s[second]]=1;
            length=max(length,(second-first)+1);
            second++;
        }
        return length;
    }
};