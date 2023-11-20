#include <iostream>
#include <iomanip>
using namespace std;

const int NUM_EMPLOYEES = 7;

int main() {
    long empId[NUM_EMPLOYEES] = {5658845, 4520125, 7895122, 8777541, 8451277, 1302850, 7580489};
    int hours[NUM_EMPLOYEES];
    double payRate[NUM_EMPLOYEES];
    double wages[NUM_EMPLOYEES];

    // Input hours worked and pay rate for each employee
    for (int i = 0; i < NUM_EMPLOYEES; i++) {
        cout << "Enter the number of hours worked for employee " << empId[i] << ": ";
        cin >> hours[i];
        
        // Input validation for hours
        while (hours[i] < 0) {
            cout << "Hours worked cannot be negative. Enter a valid value: ";
            cin >> hours[i];
        }

        cout << "Enter the hourly pay rate for employee " << empId[i] << ": ";
        cin >> payRate[i];
        
        // Input validation for pay rate
        while (payRate[i] < 15.00) {
            cout << "Pay rate cannot be less than $15.00. Enter a valid value: ";
            cin >> payRate[i];
        }

        wages[i] = hours[i] * payRate[i];
    }

    // Display employee data and gross wages
    cout << "\nEmployee Data and Gross Wages:" << endl;
    cout << "-----------------------------------" << endl;
    cout << setw(15) << "Employee ID" << setw(15) << "Hours Worked" << setw(15) << "Hourly Rate" << setw(15) << "Gross Wages" << endl;
    cout << "-----------------------------------" << endl;

    for (int i = 0; i < NUM_EMPLOYEES; i++) {
        cout << setw(15) << empId[i] << setw(15) << hours[i] << setw(15) << fixed << setprecision(2) << payRate[i] << setw(15) << wages[i] << endl;
    }

    return 0;
}
