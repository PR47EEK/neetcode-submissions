class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;
        for(int i = 0; i <= n; i++)
        {
            int temp = i, cnt = 0;
            while(temp)
            {
                cnt+=(temp&1)?1:0;
                temp>>=1;
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};
