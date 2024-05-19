class NumMatrix {
public:
    vector<vector<int>> prefixRowSumMatrix;
    NumMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        prefixRowSumMatrix = matrix;
        for(int i = 0; i < n; i++){
            for(int j = 1; j < m ; j++){
                prefixRowSumMatrix[i][j] = prefixRowSumMatrix[i][j-1] + prefixRowSumMatrix[i][j];
            }
        }
    }
    
    void update(int row, int col, int val) {
        int indexVal = prefixRowSumMatrix[row][col] - (col == 0? 0 :prefixRowSumMatrix[row][col-1]);
        int diff = val - indexVal;
        for(int i = col; i< prefixRowSumMatrix[row].size();i++){
            prefixRowSumMatrix[row][i] += diff;
        }
        
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int answer = 0;
        for(int i = row1; i <=row2; i++){
            answer += prefixRowSumMatrix[i][col2] - (col1 == 0? 0 :prefixRowSumMatrix[i][col1-1]);
        }
        return answer;
    }
};



/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * obj->update(row,col,val);
 * int param_2 = obj->sumRegion(row1,col1,row2,col2);
 */