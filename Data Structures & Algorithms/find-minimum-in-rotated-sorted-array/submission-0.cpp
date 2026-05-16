class Solution {
public:
    int findMin(vector<int> &nums) {
        int n = nums.size();
        int si = 0, ei = n - 1;
        while(si <= ei)
        {
            int mid = (si + ei)/2;
            int num = nums[mid];
            if(nums[si] <= nums[ei])
            {
                return nums[si]; //array is already sorted
            }
            //min element will be smallar than it's right and left element
            if(num <= nums[(mid + n - 1) % n] && num <= nums[(mid + 1) % n])
            {
                return num;
            }
            if(nums[si] <= num)
            {
                si = mid + 1;
            }
            else
            {
                ei = mid - 1;
            }
        }
        return -1;
    }
};
