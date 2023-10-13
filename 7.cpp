/**
 * Note:
 * Added board as suggested by Frode, made visitgroup function which checks that
 * a piece has not been visited, if not it starts a new group, prints the
 * coordinates of the group, the visits the children using recursion of the same
 * function. Afterwards it prints the total number of members of the group, then
 * continues until the entire board has been checked. The board is n+2 in size
 * as this mitigated the need for checking if the position exists as it will
 * always exist.
*/

#include <iostream>                  //  cout
#include <iomanip>                   //  setw

const int SIZE = 10;
const int PIECE = 1;
const int SEEN = 2;

int gBoard[SIZE+2][SIZE+2] = {
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0 },
    { 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0 },
    { 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0 },
    { 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0 },
    { 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } 
};

void visitGroup(int x, int y, int groupNumber, int & members) {
    if (gBoard[x][y] == PIECE) {
        gBoard[x][y] = SEEN;
        members++;
        std::cout << "x: " << x << "\ty: " << y << "\n";
        visitGroup(x+1, y, groupNumber, members);
        visitGroup(x, y+1, groupNumber, members);
        visitGroup(x-1, y, groupNumber, members);
        visitGroup(x, y-1, groupNumber, members);
    }
}

int main() {
    int groupNumber = 0, members;
    
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (gBoard[i+1][j+1] == PIECE) {
                members = 0;
                std::cout << "Visiting group: " << ++groupNumber << " with members "
                << "at the following positions: \n";
                visitGroup(i+1, j+1, groupNumber, members);
                std::cout << "\n Total: " << members << " members.\n";
            }
        }
    }
}