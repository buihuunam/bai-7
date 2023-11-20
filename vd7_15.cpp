// This program uses two parallel arrays: one for hours
2 // worked and one for pay rate.
3 #include <iostream>

7.7 Focus on Software Engineering: Using Parallel Arrays 405

4 #include <iomanip>
5 using namespace std;
6
7 int main()
8 {
9 const int NUM_EMPLOYEES = 5; // Number of employees
10 int hours[NUM_EMPLOYEES]; // Holds hours worked
11 double payRate[NUM_EMPLOYEES]; // Holds pay rates
12
13 // Input the hours worked and the hourly pay rate.
14 cout << "Enter the hours worked by " << NUM_EMPLOYEES
15 << " employees and their\n"
16 << "hourly pay rates.\n";
17 for (int index = 0; index < NUM_EMPLOYEES; index++)
18 {
19 cout << "Hours worked by employee #" << (index+1) << ": ";
20 cin >> hours[index];
21 cout << "Hourly pay rate for employee #" << (index+1) << ": ";
22 cin >> payRate[index];
23 }
24
25 // Display each employee's gross pay.
26 cout << "Here is the gross pay for each employee:\n";
27 cout << fixed << showpoint << setprecision(2);
28 for (int index = 0; index < NUM_EMPLOYEES; index++)
{
double grossPay = hours[index] * payRate[index];
cout << "Employee #" << (index + 1);
cout << ": $" << grossPay << endl;
}
return 0;
}