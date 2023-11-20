#include <iostream>
using namespace std;

const int SIZE = 3; // Size of the square

// Function to check if a square is a Lo Shu Magic Square
bool isLoShuMagicSquare(int square[][SIZE]) {
    // Calculate the expected sum (15)
    int expectedSum = 15;

    // Check rows and columns
    for (int i = 0; i < SIZE; i++) {
        int rowSum = 0;
        int colSum = 0;

        for (int j = 0; j < SIZE; j++) {
            rowSum += square[i][j];
            colSum += square[j][i];
        }

        if (rowSum != expectedSum || colSum != expectedSum) {
            return false;
        }
    }

    // Check main diagonal
    int mainDiagonalSum = 0;
    for (int i = 0; i < SIZE; i++) {
        mainDiagonalSum += square[i][i];
    }

    // Check secondary diagonal
    int secondaryDiagonalSum = 0;
    for (int i = 0; i < SIZE; i++) {
        secondaryDiagonalSum += square[i][SIZE - 1 - i];
    }

    // Check if both diagonals have the expected sum
    return mainDiagonalSum == expectedSum && secondaryDiagonalSum == expectedSum;
}

int main() {
    int square[SIZE][SIZE];

    // Input the elements of the 3x3 square
    cout << "Enter the elements of the 3x3 square:" << endl;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            cin >> square[i][j];
        }
    }

    // Check if it's a Lo Shu Magic Square
    if (isLoShuMagicSquare(square)) {
        cout << "It's a Lo Shu Magic Square!" << endl;
    } else {
        cout << "It's not a Lo Shu Magic Square." << endl;
    }

    return 0;
}
