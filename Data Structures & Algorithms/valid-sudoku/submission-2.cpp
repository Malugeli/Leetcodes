// Was für eine hässliche Lösung

class Solution{
    public:
    bool isValidSudoku(std::vector<std::vector<char>>& board){
        std::array<std::array<bool, 10>, 10> row{};
        std::array<std::array<bool, 10>, 10> col{};
        std::array<std::array<bool, 10>, 10> box{};
        const int ascii = 48;
        for (size_t c = 0; c < board.size(); ++c) {
          for (size_t r = 0; r < board.size(); ++r) {
            if (!isdigit(board[r][c])) {
              continue;
            }
            int target = static_cast<size_t>(board[r][c]) - ascii;
            if (row[r][target] || col[c][target]) {
              return false;
            }
            auto box_num = (c / 3) * 3 + r / 3;
            if (box[box_num][target]) {
              return false;
            }
            box[box_num][target] = true;
            row[r][target] = true;
            col[c][target] = true;
          }
        }
        return true;
    }
};