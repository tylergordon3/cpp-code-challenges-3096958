// C++ Code Challenges, LinkedIn Learning

// Challenge #6: Horseplay
// Write a function that takes in the location of a knight in a chessboard and returns a vector of strings with the possible locations it might move to.
// The locations are expressed as strings in algebraic notation.
// Print the list on the terminal.
// Don't worry about other pieces on the chessboard.

#include <iostream>
#include <vector>
#include <string>

bool check(int col, int row) {
        if (col > 8 || col < 1 || row > 8 || row < 1) {
            return false;
        }
        return true;
}


std::string pos(int col, int row) {
    std::vector<char> letters = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};
    
    char c = letters.at(col-1);
    std::string str = "";

    str+=c;
    str+=std::to_string(row);

    return str;
}

// knight_moves()
// Summary: This function receives a string with the location of a knight in a chessboard and returns a vector of strings with the possible locations it might move to.
// Arguments:
//           knight: The knight's location.
// Returns: An STL vector of strings with the possible locations to move.
std::vector<std::string> knight_moves(std::string knight){
    std::vector<std::string> moves;
    int col = 999;
    int row = std::stoi(&knight.back());

    std::vector<char> letters = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};

    for (int idx = 0; idx < letters.size(); idx++) {
        if (knight[0] == letters.at(idx)) {
            col = idx + 1;
            break;
        }
    }
    
    if (col > 8 || col < 1 || row > 8 || row < 1) {
        moves.push_back("error");
    }

    
    // Top Left
    int col_lu1 =  col - 1;
    int col_lu2 = col - 2;
    int row_lu1 = row + 2;
    int row_lu2 = row + 1; 

    if (check(col_lu1, row_lu1)) {
        moves.push_back(pos(col_lu1, row_lu1));
    }

    if (check(col_lu2, row_lu2)) {
        moves.push_back(pos(col_lu2, row_lu2));
    }

    // Top Right
    int col_ru1 =  col + 1;
    int col_ru2 = col + 2;
    int row_ru1 = row + 2;
    int row_ru2 = row + 1; 

    if (check(col_ru1, row_ru1)) {
        moves.push_back(pos(col_ru1, row_ru1));
    }

    if (check(col_ru2, row_ru2)) {
        moves.push_back(pos(col_ru2, row_ru2));
    }
    
     // Bot Left
    int col_lb1 =  col - 1;
    int col_lb2 = col - 2;
    int row_lb1 = row - 2;
    int row_lb2 = row - 1; 

    if (check(col_lb1, row_lb1)) {
        moves.push_back(pos(col_lb1, row_lb1));
    }

    if (check(col_lb2, row_lb2)) {
        moves.push_back(pos(col_lb2, row_lb2));
    }

     // Bot Right
    int col_rb1 =  col + 1;
    int col_rb2 = col + 2;
    int row_rb1 = row - 2;
    int row_rb2 = row - 1; 

    if (check(col_rb1, row_rb1)) {
        moves.push_back(pos(col_rb1, row_rb1));
    }

    if (check(col_rb2, row_rb2)) {
        moves.push_back(pos(col_rb2, row_rb2));
    }
    
    return moves;
}

// Main function
int main(){
    std::string knight;
    
    std::cout << "Enter the location of the knight: " << std::flush;
    std::cin >> knight;

    std::vector<std::string> the_moves = knight_moves(knight);
    std::cout << std::endl << "Possible moves from " << knight << ": ";

    for (auto element : the_moves)
        std::cout << element << " ";
    std::cout << std::endl << std::endl << std::flush;
    return 0;
}