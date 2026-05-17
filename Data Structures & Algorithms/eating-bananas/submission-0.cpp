class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, r = 1000000000;
        while(l < r)
        {
            int total = 0;
            int m = (l + r) / 2;
            for(auto p : piles)
            {
                total += (p + m - 1) / m;
            }
            if(total > h)
            {
                l = m + 1;
            }
            else
            {
                r = m;
            }
        }
        return l;
    }
};
