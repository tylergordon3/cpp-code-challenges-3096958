// C++ Code Challenges, LinkedIn Learning

// Challenge #13: Conway's Game of Life
// Write an application that runs Conway's Game of Life, the best-known cellular automaton.
// Do this for a 10x10 grid.
// The grid wraps around in all directions, like the Pac-Man world.

// Rules:
// Any live cell with fewer than two live neighbors dies, as if by underpopulation.
// Any live cell with two or three live neighbors lives on to the next generation.
// Any live cell with more than three live neighbors dies, as if by overpopulation.
// Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.

#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>

#define N 10
#define M 10

//       ..
// .. [] [] [] ..
// .. [] ** [] ..
// .. [] [] [] ..
//       ..
int getNeighbros(char game[][M],int r, int c) {
    int num = 0;
    // Add 10 to indexes for modulo
    int nr = r + N;
    int nc = c + M;
    // Up = nr - 1 : Down = nr + 1
    // Right = nc + 1 : Left = nc - 1

    // Down
    if (game[(nr+1)%N][nc%M] == 'X') {
        num++;
    }
    // Down Right
    if (game[(nr+1)%N][(nc+1)%M] == 'X') {
        num++;
    }
    // Right
    if (game[nr%N][(nc+1)%M] == 'X') {
        num++;
    }
    // Up Right
    if (game[(nr-1)%N][(nc+1)%M] == 'X') {
        num++;
    }
     // Up 
    if (game[(nr-1)%N][nc%M] == 'X') {
        num++;
    }
    // Up Left
    if (game[(nr-1)%N][(nc-1)%M] == 'X') {
        num++;
    }
    // Down Left
    if (game[(nr+1)%N][(nc-1)%M] == 'X') {
        num++;
    }
    // Left
    if (game[nr%N][(nc-1)%M] == 'X') {
        num++;
    }
    return num;
}


// Conway's Game of Life, main()
// Summary: This application is a simulation of Conway's game of life.
int main(){    
    // The game, initialized with a glider and a blinker.
    char game[N][M];  
    std::memset(game,'-',N*M); // Initialize game with dashes.

    // A glider     // - - - - - - - - - -
    game[1][1]='X'; // - X - - - - - - - -
    game[2][2]='X'; // - - X - - - - - - -
    game[3][0]='X'; // X X X - - - - - - -
    game[3][1]='X';
    game[3][2]='X';

    // A blinker    // - - - - - - - - - -
    game[3][6]='X'; // - - - - - - - - - -
    game[3][7]='X'; // - - - - - - - - - -
    game[3][8]='X'; // - - - - - - X X X -
    
    char next_gen[N][M];
    int generation = 0;
    std::string go_on;
    do{
        std::cout << "Generation #" << generation++ << "\n";
        for (auto &str : game){
            for (auto &ch : str)
                std::cout << " " << ch;
            std::cout << "\n";
        }
        std::cout << "\n";
        // Write your code here
        std::memcpy(next_gen,game,N*M);

        for (int row = 0; row < N; row++) {
            for (int col = 0; col < M; col++) {
                int numNeighbors = getNeighbros(game, row, col);
                // Any live cell with fewer than two live neighbors dies, as if by underpopulation.
                if (game[row][col] == 'X' && numNeighbors < 2) {
                    next_gen[row][col] = '-';
                }
                // Any live cell with two or three live neighbors lives on to the next generation.
                // Good as is

                // Any live cell with more than three live neighbors dies, as if by overpopulation.
                if (game[row][col] == 'X' && numNeighbors > 3) {
                    next_gen[row][col] = '-';
                }
                // Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
                if (game[row][col] == '-' && numNeighbors == 3) {
                    next_gen[row][col] = 'X';
                }
            }
        }
        // Make the next generation the current game state
        std::memcpy(game, next_gen,N*M);
       
        std::cout << "Press Enter for the next generation, or type \"Exit\": " << std::flush;
        std::getline(std::cin,go_on);
        std::transform(go_on.begin(), go_on.end(), go_on.begin(), toupper);
        std::cout << "\n" << std::flush;
    }while(go_on.compare("EXIT")!=0);
    
    return 0;
}
