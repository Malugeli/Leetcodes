struct Solution{
    bool searchMatrix(std::vector<std::vector<int>>& matrix, int target){
        int left = 0;
        int right = matrix.size() - 1;

        while(left <= right){
            int mid = std::midpoint(left, right);
            if(matrix[mid][0] > target){
                right = mid - 1;
            }
            else if(matrix[mid][matrix[mid].size() - 1] < target){
                left = mid + 1;
            }
            else{
                int inner_left = 0;
                int inner_right = matrix[mid].size() - 1;
                while(inner_left <= inner_right){
                    int inner_mid = std::midpoint(inner_left, inner_right);
                    if(matrix[mid][inner_mid] > target){
                        inner_right = inner_mid -1;
                    }
                    else if(matrix[mid][inner_mid] < target){
                        inner_left = inner_mid +1;
                    }
                    else{
                        return true;
                    }
                }
                return false;
            }
        }
        return false;
    }
}; 