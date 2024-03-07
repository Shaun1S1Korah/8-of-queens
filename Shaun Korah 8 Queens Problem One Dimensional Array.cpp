#include<iostream>
#include<cmath> 

using namespace std;

int main() {
    int q[8] = {0}, c = 0, count = 0; // q array which stores queen positions, c for column, count for solution count
    q[0] = 0; // Start with the first queen in the first column

nc: // Label for column increase
    c++;
    if(c == 8) goto print; // If all queens are placed, print the solution
    q[c] = -1; // Start with the first row for the next column

nr: // Label for row increase
    q[c]++; // Move to the next row
    if (q[c] == 8) goto backtrack; // If all rows are tried in this column, go to backtrack fix any errors
    // Check if the current queen position collides with other queens
    for (int i = 0; i < c; i++) {
        if (q[i] == q[c] || (c - i) == abs(q[c] - q[i])) goto nr; // If there's a conflict, try move to the next row
    }
    goto nc; // Move to the next column

backtrack: // Label for backtracking
    c--; // Move back to the previous column
    if (c == -1) return 0; // If all columns are exhausted, end the code

    goto nr; // Move to the next row in the previous column

print: // Label for printing the solution
    count++;// there is a soltuion present
    cout << "Solution #" << count << ": "; // Print solution number

    // Print queen positions for each column with their row value
    for(int i = 0; i < 8; i++) {
        cout << q[i] << " ";
    }
    cout << "\n";

    // Print the chessboard column by column
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
            if (q[j] == i) 
                cout << "1 "; // Queen present
            else
                cout << "0 "; // Empty cell
        }
        cout << endl;
    }
    cout << endl;

    goto backtrack; // Backtrack to find other solutions if not the code will stop since there are no more solutions
}
