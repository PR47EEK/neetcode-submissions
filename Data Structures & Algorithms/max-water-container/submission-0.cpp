class Solution {
public:
    int maxArea(vector<int>& heights) {
        int maxi = INT_MIN;
        int n = heights.size();
        int i = 0;
        int j = n-1;
        while(i < j) {
            int area = (j - i) * min(heights[i], heights[j]);
            maxi = max(area, maxi);
            if(heights[i] < heights[j]) {
                i++;
            }
            else {
                j--;
            }
        }
        return maxi;
    }
};
