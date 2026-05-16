class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();
        for(int i = 0; i < n; i++)
        {
            if(target >= matrix[i][0] && target <= matrix[i][m-1])
            {
                int si = 0, ei = m - 1;
                
                while(si <= ei)
                {
                    int mid = (si + ei) / 2;
                    if(matrix[i][mid] == target)
                    return true;
                    if(matrix[i][mid] > target)
                    {
                        ei = mid - 1;
                    }
                    else
                    {
                        si = mid + 1;
                    }
                }
            }
        }
        return false;
    }
};
