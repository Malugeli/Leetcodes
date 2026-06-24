struct Solution{
    bool searchMatrix(std::vector<std::vector<int>>& matrix, int target){
        int row = matrix[0].size();
        int column = matrix.size();
        int left = 0;
        int right = (row * column) - 1;

        while(left <= right){
            int mid = std::midpoint(left, right);
            int real_mid = matrix[mid / row][mid % row];
            if(real_mid > target){
                right = mid - 1;
            }     
            else if(real_mid < target){
                left = mid + 1;
            }
            else{
                return true;
            }
        }
        return false;
    }
}; 