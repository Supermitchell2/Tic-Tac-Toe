#include <iostream>

class Board
{
    std::string board[3][3];
public:
    /**
    * Determines whether a tile is already occupied 
    * @param row the row of the tile
    * @param col the column of the tile
    * @return boolean representing whether the tile is occupied
    */
    bool isOccupied(int row, int col) {
        if (row < 3 && col < 3 && row > -1 && col > -1) {
            return board[row][col].compare("") != 0;
        }
        std::cout << "not in bounds";
        return true;
    }

    /**
    * Adds a move to a tile if it is not already occupied
    * @param row the row to add to
    * @param col the column to add to
    * @param team the letter of the team which is playing
    * @return boolean representing whether the item was added
    */
    bool add(int row, int col, std::string team) {
        if (!isOccupied(row, col)) {
            board[row][col] = team;
            return true;
        }
        return false;
    }

    /**
    * Prints the current state of the board
    */
    void print() {
        std::cout << " 1 2 3\n";
        for (int row = 0; row < 3; row++) {
            std::cout << row + 1;
            for (int col = 0; col < 3; col++) {
                
                if (board[row][col].compare("") == 0) {
                    std::cout << " ";
                }
                else {
                    std::cout << board[row][col];
                }
                if (col < 2) {
                    std::cout << " ";
                }
            }
            std::cout << "\n";
        }
    }

    /**
    * Identifies if a player has won the game
    * @return a string which either contains the winning team's letter or is empty
    */
    std::string getWinner() {
        // Check for rows
        for (int row = 0; row < 3; row++) {
            if (board[row][0].compare(board[row][1]) == 0 && board[row][1].compare(board[row][2]) == 0) {
                return board[row][0];
            }
        }
        // Check for columns
        for (int col = 0; col < 3; col++) {
            if (board[0][col].compare(board[1][col]) == 0 && board[1][col].compare(board[2][col]) == 0) {
                return board[0][col];
            }
        }
        // Check for diagonals
        if (board[0][0].compare(board[1][1]) == 0 && board[1][1].compare(board[2][2]) == 0) {
            return board[0][0];
        }
        else if (board[2][0].compare(board[1][1]) == 0 && board[1][1].compare(board[0][2]) == 0) {
            return board[2][0];
        }
        return "";
    }

    /**
    * Determines whether all possible tiles have been filled
    * @return boolean representing whether all tiles are occupied
    */
    bool isFull() {
        for (int row = 0; row < 3; row++) {
            for (int col = 0; col < 3; col++) {
                if (!isOccupied(row, col)) {
                    return false;
                }
            }
        }
        return true;
    }
};

class TicTacToe {
public:
    /**
    * Runs the Tic Tac Toe game
    */
    void play() {
        int row;
        int col;
        Board board = Board();
        std::string currentTeam = "X";
        std::string winner = "";
        while (winner.compare("") == 0) {
            std::cout << "\nIt is now player " << currentTeam << "'s turn\n";
            board.print();
            row = getRow();
            col = getCol();
            if (!board.add(row, col, currentTeam)) {
                std::cout << "That square (" << row << ", " << col << ") is taken! Please try again!\n";
                continue;
            }
            winner = board.getWinner();
            if (board.isFull()) {
                break;
            }
            currentTeam = currentTeam.compare("X") == 0 ? "O" : "X";
        }
        board.print();
        if (winner.compare("") == 0) {
            std::cout << "It was a draw! Good game!\n";
        }
        else {
            std::cout << "Congratulations to player " << winner << "! You win!\n";
        }
    }

    /**
    * Takes user input to identify the row
    * @return int the row inputted by the user
    */
    int getRow() {
        int row = -1;
        while (row > 3 || row < 1) {
            std::cout << "Enter a row (1 to 3): ";
            std::cin >> row;
            std::cin.ignore(32767, '\n');
        }
        return --row;
    }

    /**
    * Takes user input to identify the column
    * @return int the column inputted by the user
    */
    int getCol() {
        int col = -1;
        while (col > 3 || col < 1) {
            std::cout << "Enter a column (1 to 3): ";
            std::cin >> col;
            std::cin.ignore(32767, '\n');
        }
        return --col;
    }
};

int main()
{
    TicTacToe game = TicTacToe();
    game.play();
}