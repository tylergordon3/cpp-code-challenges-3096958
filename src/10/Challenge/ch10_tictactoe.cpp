// C++ Code Challenges, LinkedIn Learning

// Challenge #10: Playing Tic-Tac-Toe
// Write an application that plays Tic-Tac-Toe against the user.

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <random>

using namespace std;

// ask_for_move()
// Summary: This function asks the user to make a move.
// Arguments:
//           game[3][3]: The state of the game.
//           mark: The user's mark: 'X' or 'O'.
// Returns: Nothing.
void ask_for_move(char game[][3], char mark){
    std::string str;
    int row, col;
    do{
        std::cout << "Place your mark (" << mark << ") in row: " << std::flush;
        std::cin >> str;
        row = stoi(str);
        std::cout << "Place your mark (" << mark << ") in column: " << std::flush;
        std::cin >> str;
        col = stoi(str);
    }while(game[row-1][col-1]!=' ');
    game[row-1][col-1] = mark;
    return;
}

// make_move()
// Summary: This AI function makes a move on behalf of the computer in an ongoing tic-tac-toe game.
// Arguments:
//           game[3][3]: The state of the game.
//           mark: The AI's mark: 'X' or 'O'.
// Returns: Nothing.

//#define TWO_PLAYERS
void make_move(char game[][3], char mark) { 
    #ifdef TWO_PLAYERS
    ask_for_move(game,mark);
    #else
    
    // Write your code here and comment out the definition of TWO_PLAYERS above
    // Randomly choose an open space
    std::vector<int> arr;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (game[i][j] == ' ') {
                arr.push_back(i);
                arr.push_back(j);
            }
        }
    }

    if (arr.size() == 2) {
        game[arr[0]][arr[1]] = mark;
        return;
    }

    for (int z = 0; z < arr.size(); z++) {
        cout << arr[z] << " ";
    }
    int min = 0;
    std::cout << std::endl << "min: " << min << std::endl;
    int max = arr.size()/2;
    std::cout << "max: " << max << std::endl;
    std::cout << "size: " << arr.size() << std::endl;

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(min, max);
    int randomValue = distrib(gen);

    int x = randomValue * 2;
    int y = (randomValue * 2) + 1;
    std::cout<< "row index: " << x << std::endl;
    std::cout<< "col index: " << y << std::endl;
    game[arr[x]][arr[y]] = mark;    
    std::cout<< "row: " << arr[x] << std::endl;
    std::cout<< "col : " << arr[y] << std::endl;
    #endif
    return;
}

// game_state()
// Summary: This function returns the state of a game.
// Arguments:
//           game[3][3]: The state of the game.
// Returns: A character encoded as:
//                                  'a': An active game.
//                                  'X': X won.
//                                  'O': O won.
//                                  't': A tie.
char game_state(char game[][3]){
    int row_c0, row_c1, row_c2;
    int r0_col, r1_col, r2_col;
    // Write your code here
    // Horizontal/Vertical Win
    // [*] [*] [*]          [] [*] []       [] []  [*]
    // [*] []   []     ->  [*] [*] [*]  ->  [] []  [*]
    // [*] [] []            [] [*] []      [*] [*] [*]
    for (int idx = 0; idx < 3; idx++) {
        row_c0 = game[idx][0];
        row_c1 = game[idx][1];
        row_c2 = game[idx][2];
        r0_col = game[0][idx];
        r1_col = game[1][idx];
        r2_col = game[2][idx];

        // Horizontal Win
        if (row_c0 != ' ' && row_c0 == row_c1 && row_c1 == row_c2)
            return row_c0;
        // Vertical Win 
        if (r0_col != ' ' && r0_col == r1_col && r1_col == r2_col)
            return r0_col;
    }

    // [*] []  []       []  []  [*]    
    // []  [*] []   ->  []  [*] [] 
    // []  []  [*]      [*] []  []
    // Diagonal Win
    if (game[0][0] != ' ' && game[0][0] == game[1][1] && game[1][1] == game[2][2])
        return game[0][0];
    if (game[2][0] != ' ' && game[2][0] == game[1][1] && game[1][1] == game[0][2])
        return game[2][0];

    // Active Game
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) { 
            if (game[i][j] == ' ') 
                return 'a';
        }
    }
    
    // No victories, and no spaces empty
    return 't';
}

// print_game()
// Summary: This function prints an ongoing tic-tac-toe game.
// Arguments:
//           game[3][3]: The state of the game.
// Returns: Nothing.
void print_game(char game[][3]){
    std::cout << std::endl << std::endl;
    std::cout << "    1   2   3\n\n";
    std::cout << "1   " << game[0][0] << " | "<< game[0][1] << " | " << game[0][2] << "\n";
    std::cout << "   " << "---+---+---\n";
    std::cout << "2   " << game[1][0] << " | "<< game[1][1] << " | " << game[1][2] << "\n";
    std::cout << "   " << "---+---+---\n";
    std::cout << "3   " << game[2][0] << " | "<< game[2][1] << " | " << game[2][2] << "\n";

    std::cout << std::endl << std::endl;
    return;
}

// Main function
int main(){
    char game[3][3] = {{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}};
    char user_mark = 'X', ai_mark = 'O', turn = 'X';
    std::string str;

    std::cout << "Pick your mark (X goes first): " << std::flush;
    std::cin >> str;
    if(str[0]== 'O' || str[0]== 'o'){
        user_mark = 'O';
        ai_mark = 'X';
    }
    std::cout << "      User: " << user_mark << "     AI: " << ai_mark << "\n";    

    print_game(game);

    while(game_state(game)=='a'){
        std::cout << turn << "'s turn...\n";    
        if(turn==user_mark)
            ask_for_move(game,user_mark);
        else
            make_move(game,ai_mark);
        print_game(game);
        turn = turn == 'X' ? 'O' : 'X';
    }
    if(game_state(game)=='t')
        std::cout << "It's a tie.\n\n";
    else    
        std::cout << game_state(game) << " is the winner.\n\n";
    std::cout << std::flush;
    return 0;
}
