class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int si = 0, ei = n - 1;
        while(si <= ei)
        {
            int mid = (si + ei) / 2;
            int num = nums[mid];
            if(num == target)
            {
                return mid;
            }
            //left sorted half
            if(nums[si] <= num)
            {
                if(num > target && target >= nums[si])
                {
                    ei = mid - 1;
                }
                else
                {
                    si = mid + 1;
                }
            }
            else
            {
                if(num < target && target <= nums[ei])
                {
                    si = mid + 1;
                }
                else
                {
                    ei = mid - 1;
                }
            }
        }
        return -1;
    }
};
