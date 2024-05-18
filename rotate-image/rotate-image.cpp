class Solution {
public:
    void rotateUtil(vector<vector<int>> &matrix, int start, int end, int i){
        int temp = matrix[start][start+i];
        matrix[start][start+i] = matrix[end-i][start];
        matrix[end-i][start] = matrix[end][end-i];
        matrix[end][end-i] = matrix[start+i][end];
        matrix[start+i][end] = temp;
    }
    void rotate(vector<vector<int>>& matrix) {
        int start = 0;
        int end = matrix.size()-1;
        while(start < end){
            for(int i = 0; start + i < end; i++){
                rotateUtil(matrix, start, end, i);
            }
            start++;
            end--;
        }
    }
};