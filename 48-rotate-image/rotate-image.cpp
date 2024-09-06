class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
   
        int n =matrix.size();
         vector<vector<int>> fl(n, vector<int>(n));
        for(int i=0;i<matrix.size();i++){
            for(int j=0; j<matrix[i].size();j++){
                fl[i][j] = matrix[n-j-1][i];
            }
        }
        
           for(int i=0;i<matrix.size();i++){
            for(int j=0; j<matrix[i].size();j++){
                matrix[i][j] = fl[i][j];
            }
        }
    }
};