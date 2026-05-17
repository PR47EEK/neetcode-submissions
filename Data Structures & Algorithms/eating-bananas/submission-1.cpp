class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        //koko need to eat 1 banana atleast an hour
        // while can eat maximum 10^9
        // now we will guess using binary search
        int l = 1, r = 1000000000;
        while(l < r)
        {
            int m = (l + r) / 2; //suppose k = m
            int total = 0;
            for(auto p : piles)
            {
                // now here we will play a trick to control integer floor devision rule
                // let's say if pile has 10 bananas and m = 3 (koko can eat 3 bananas)
                // so total time to finish that pile will be 4 hrs but
                //from interger devision 10/3 => 3 so that why we will add (m - 1)
                // hence formula become (p + m - 1)/m
                // e.g. (10 + 3 - 1)/3 => 12/3 => 4
                //e.ge. p = 9 -> (9 + 3 -1)/3 => 11/3 => 3
                // so
                total += (p + m - 1) / m;
            }
            //now we will use binary search trick
            // if total taken hrs to eat all piles koko took more than h hours
            if(total > h)
            {
                l = m + 1;
            }
            else
            {
                r = m;
            }

        }
        return l; // after loop ends only one value reamins
    }
};