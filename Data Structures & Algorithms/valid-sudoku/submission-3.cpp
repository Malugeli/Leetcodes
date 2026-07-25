class Solution{
    public:
    bool isValidSudoku(std::vector<std::vector<char>>& board){
        std::array<std::array<char, 9>, 9> row{};
        std::array<std::array<char, 9>, 9> column{};
        std::array<std::array<char, 9>, 9> box{};

        for(size_t r = 0; r < board.size(); ++r){
            for(size_t c = 0; c < board.size(); ++c){
                if(!isdigit(board[r][c])){
                    continue;
                }
                int target = board[r][c] - '1';
                int box_num = (r / 3) * 3 + c / 3;
                if(row[r][target] || column[c][target] || box[box_num][target]){
                    return false;
                }
                row[r][target] = true;
                column[c][target] = true;
                box[box_num][target] = true;
            }
        }
        return true;
    }
};