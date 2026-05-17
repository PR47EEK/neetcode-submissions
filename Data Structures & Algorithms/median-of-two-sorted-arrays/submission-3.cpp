class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        int len = n+m;
        int i = 0, j = 0;
        int curr = 0, prev = 0, count = 0;
        while(i < n || j < m)
        {
            prev = curr;
            if(j >= m || (i < n && nums1[i] < nums2[j]))
            {
                curr = nums1[i];
                i++;
            }
            else
            {
                curr = nums2[j];
                j++;
            }
            if(count == len/2)
            {
                if(len%2 == 0)
                {
                    return double(prev + curr)/2.0;
                }
                else
                {
                    return (double)curr;
                }
            }
            count++;
        }
        return -1;
    }
};
