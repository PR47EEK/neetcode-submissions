class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> uset(nums.begin(), nums.end());\
        int res = 0;
        for(int x : nums) {
            if(uset.find(x-1) == uset.end()) {
                int length = 0;
                while(uset.find(x) != uset.end()){
                    length++;
                    x++;
                }
                res = max(length, res);
            }
        }
        return res;
    }
};
