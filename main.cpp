#include <iostream>
#include <vector>

bool validRow(std::vector<std::vector<int>>& sudokuboard, int number, int row, int column) {
    for (int i{0}; i <= 8; i++) {
        if (sudokuboard[row][i] == number) {
            return false;
        }
    }
    return true;
}

bool validColumn(std::vector<std::vector<int>>& sudokuboard, int number, int row, int column) {
    for (int i{0}; i <= 8; i++) {
        if (sudokuboard[i][column] == number) {
            return false;
        }
    }
    return true;
}

bool validBox(std::vector<std::vector<int>>& sudokuboard, int number, int row, int column) {
    int colstartpos{3 * (column / 3)};
    int rowstartpos{3 * (row / 3)};

    for (int i{rowstartpos}; i < rowstartpos + 3; i++) {
        for (int j{colstartpos}; j < colstartpos + 3; j++) {
            if (sudokuboard[i][j] == number) {
                return false;
            }
        }
    }
    return true;
}

bool validPosition(std::vector<std::vector<int>>& sudokuboard, int number, int row, int column) {
    bool validcol = validColumn(sudokuboard, number, row, column);
    bool validrow = validRow(sudokuboard, number, row, column);
    bool validbox = validBox(sudokuboard, number, row, column);
    return(validcol && validrow && validbox);
}

bool solveSudoku(std::vector<std::vector<int>>& sudokuboard) {
    for (int row{0}; row <= 8; row++) {
        for (int col{0}; col <= 8; col++ ) {
            if (sudokuboard[row][col] == 0) {
                for (int num{1}; num <= 9; num++) {
                    if (validPosition(sudokuboard, num, row, col)) {
                        sudokuboard[row][col] = num;
                        if (solveSudoku(sudokuboard)) {
                            return true;
                        }
                        sudokuboard[row][col] = 0;
                    }
                }
                return false;
            }
        }
    }
    return true;
}


int main() {
    std::vector<std::vector<int>> sudokuboard = {
        {1, 0, 0, 0, 0, 7, 0, 9, 0},
        {0, 3, 0, 0, 2, 0, 0, 0, 8},
        {0, 0, 9, 6, 0, 0, 5, 0, 0},
        {0, 0, 5, 3, 0, 0, 9, 0, 0},
        {0, 1, 0, 0, 8, 0, 0, 0, 2},
        {6, 0, 0, 0, 0, 4, 0, 0, 0},
        {3, 0, 0, 0, 0, 0, 0, 1, 0},
        {0, 4, 1, 0, 0, 0, 0, 0, 7},
        {0, 0, 7, 0, 0, 0, 3, 0, 0}
    };



    solveSudoku(sudokuboard);

    for (int row{0}; row <= 8; row++) {
        for (int col{0}; col <= 8; col++ ) {
            std::cout << sudokuboard[row][col] << " ";
            if ((col + 1) % 9 == 0) {
                std::cout << "\n";
            }
        }
    }

    return 0;
}
