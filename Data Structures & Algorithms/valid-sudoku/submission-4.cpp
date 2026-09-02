class Solution {
public:
    bool isValidSudoku(std::vector<std::vector<char>>& board){
        std::array<std::array<bool, 10>, 9> box{};
        std::array<std::array<bool, 10>, 9> vertical{};
        std::array<std::array<bool, 10>, 9> horizontal{};

        for(size_t h = 0; h < board.size(); ++h){
            for(size_t v = 0; v < board.size(); ++v){
                if(board[h][v] == '.') continue;
                size_t num = static_cast<size_t>( board[h][v] - '0' );
                size_t index = ( ( h / 3 ) * 3 ) + ( v / 3 );
                if(vertical[v][num] || horizontal[h][num] || box[index][num]){
                    return false;
                }
                vertical[v][num] = true;
                horizontal[h][num] = true;
                box[index][num] = true;
            }
        }
        return true;
    }
};