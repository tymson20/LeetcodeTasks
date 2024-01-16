// 36. Valid Sudoku

#include <iostream>
#include <vector>
#include <unordered_set>

class Solution {
public:
    bool isValidSudoku(std::vector<std::vector<char>>& board) {
        std::size_t size = 0;
        std::unordered_set<char> u_set;

        // checking rows
        for (const auto& row : board) {
            for (char value : row) {
                if (value != '.') {
                    u_set.insert(value);
                    if (++size != u_set.size()) return false;
                }
            }
            u_set.clear();
            size = 0;
        }
        // checking columns
        for (std::size_t i = 0; i < 9; i++) {
            for (std::size_t j = 0; j < 9; j++) {
                if (board[j][i] != '.') {
                    u_set.insert(board[j][i]);
                    if (++size != u_set.size()) return false;
                }
            }
            u_set.clear();
            size = 0;
        }
        // checking sub-boxes
        for (std::size_t i = 0; i < 3; i++) {
            for (std::size_t j = 0; j < 3; j++) {
                for (std::size_t ii = 0; ii < 3; ii++) {
                    for (std::size_t jj = 0; jj < 3; jj++) {
                        if (board[3*i + ii][3*j + jj] != '.') {
                            u_set.insert(board[3 * i + ii][3 * j + jj]);
                            if (++size != u_set.size()) return false;
                        }
                    }
                }
                u_set.clear();
                size = 0;
            }
        }
        return true;
    }
};

int main() {
    Solution solution = Solution();
    std::vector<std::vector<char>> board1 = {{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
                                             {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
                                             {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
                                             {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
                                             {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
                                             {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
                                             {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
                                             {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
                                             {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
    bool result = solution.isValidSudoku(board1);
    std::cout<<result<<std::endl;
    return 0;
}

/*
board =
[["5","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]]
*/