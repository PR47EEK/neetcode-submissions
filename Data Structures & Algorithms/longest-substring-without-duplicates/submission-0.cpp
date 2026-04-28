class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLen = 0;
        int start = 0;
        unordered_map<char, int> umap;
        int n = s.size();
        for(int i = 0; i < n; i++) {
            if(umap.find(s[i]) != umap.end() && start <= umap[s[i]]) start = max(start, umap[s[i]] + 1);
            umap[s[i]]=i;
            maxLen = max(maxLen, i - start + 1);
        }
        return maxLen;
    }
};
