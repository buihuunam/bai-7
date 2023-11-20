#include <iostream>
using namespace std;

// Function to display numbers in the array greater than n
void displayNumbersGreaterThanN(int arr[], int size, int n) {
    cout << "Numbers greater than " << n << " in the array are: ";
    for (int i = 0; i < size; i++) {
        if (arr[i] > n) {
            cout << arr[i] << " ";
        }
    }
    cout << endl;
}

int main() {
    const int SIZE = 10; // Size of the array
    int numbers[SIZE];   // Declare an array of integers

    // Input values into the array
    cout << "Enter " << SIZE << " integers: ";
    for (int i = 0; i < SIZE; i++) {
        cin >> numbers[i];
    }

    int n; // Number to compare with
    cout << "Enter a number to compare with: ";
    cin >> n;

    // Call the function to display numbers greater than n
    displayNumbersGreaterThanN(numbers, SIZE, n);

    return 0;
}