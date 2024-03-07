#include <iostream>
using namespace std;

int main() {
    int Sol = 1; // This variable will be used later to keep track of the number of solutions we printed out
    int b[8][8] = {0}, r = 0, c = 0; // Initialize the array we are going to use (resembles a chess board)

    b[0][0] = 1; // Places the first queen at the point 0,0 (1 will be used to signify the presence of a queen)

nc: 
    c++; // Callback that moves to the next column
    if (c == 8) goto print; // If we have reached the end of the board, jump to the print section
    r = -1;

nr: 
    r++; // Callback that moves to the next row
    if (r == 8) goto backtrack; // If we have reached the end of the current column, backtrack

    // Row test: Check for any queens in the row, if so, move on to the next row
    for (int i = 0; i < c; i++) {
        if (b[r][i] == 1) goto nr;
    }

    // Up diagonal test: Check for any queens across the board (left)
    for (int i = 1; (r - i) >= 0 && (c - i) >= 0; i++) {
        if (b[r - i][c - i] == 1) goto nr;
    }

    // Down diagonal test: Check for any queens across the board (right)
    for (int i = 1; (r + i) < 8 && (c - i) >= 0; i++) {
        if (b[r + i][c - i] == 1) goto nr;
    }

    // To place the queen
    b[r][c] = 1;
    goto nc;

backtrack:
    c--;
    if (c == -1) return 0; // If we have backtracked past the first column, exit the program
    r = 0;
    while (b[r][c] != 1) {
        r++;
    }
    b[r][c] = 0; // Remove the queen from the current position
    goto nr;

print:
    cout << "Solution # " << Sol++ << ": " << endl; // Since this part will repeat until there is no more solution, the count will increase
    for (int i = 0; i < 8; i++) {
        for (int u = 0; u < 8; u++) {
            cout << b[i][u];
        }
        cout << endl;
    }
    cout << endl;
    goto backtrack;
}
