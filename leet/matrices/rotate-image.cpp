class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int l=0, h=n-1;
        while (l<h)
        {
            int tmp;
            for (int i=l; i<h; i++)
            {
                tmp = matrix[l][i];
                matrix[l][i]=matrix[n-1-i][l];
                matrix[n-1-i][l]=matrix[n-1-l][n-1-i];
                matrix[n-1-l][n-1-i]=matrix[i][h];
                matrix[i][h]=tmp;
            }
            l++;
            h--;
        }
    }
};