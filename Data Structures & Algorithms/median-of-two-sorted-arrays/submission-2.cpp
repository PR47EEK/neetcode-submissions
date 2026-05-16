class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        vector<int> merge;
        int i = 0, j = 0;
        while (i < n && j < m)
        {
            if(nums1[i] < nums2[j])
            {
                merge.emplace_back(nums1[i]);
                i++;
            }
            else
            {
                merge.emplace_back(nums2[j]);
                j++;
            }
        }
        while(i < n)
        {
            merge.emplace_back(nums1[i]);
            i++;
        }
        while(j < m)
        {
            merge.emplace_back(nums2[j]);
            j++;
        }
        for(int i = 0; i < (m+n); i++) cout << merge[i] <<" ";
        int l = n+m;
        if((l)%2 == 0)
        {
            return double(merge[l/2] + merge[(l/2) - 1]) / double(2);
        }
        else
        {
            return double(merge[l/2]);
        }
        return 0.0;
    }
};
