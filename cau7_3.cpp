#include <iostream>
using namespace std;
//prototype(thủ tục)
int inputValidate(int);
void getNumberSold(const string[], int[], const int);
int getTotal(const int[], const int);
string getHighest(const string[], const int[], const int);
string getLowest(const string[], const int[], const int);

int main()
{
    const int ARRAY_SIZE = 5;

    int number_of_jars_sold[ARRAY_SIZE];
    string salsa_names[] = {"mild","medium","sweet","hot","zesty"};

    getNumberSold(salsa_names, number_of_jars_sold, ARRAY_SIZE);

    cout << endl;
    //tạo vòng lặp để xuất ra tên salsa có trong mảng salsa_names[]
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        cout << "Sales for " << salsa_names[i] << " salsa = " << number_of_jars_sold[i] << " jars." << endl;
    }
    //xuất ra tổng doanh thu
    int total_sales = getTotal(number_of_jars_sold, ARRAY_SIZE);
    cout << "\nTotal sales = " << total_sales << " jars." << endl;

    //xuất ra doanh thu lớn nhất
    string highest_selling = getHighest(salsa_names, number_of_jars_sold, ARRAY_SIZE);
    cout << "Highest selling = " << highest_selling << endl;

    //xuất ra doanh thu thấp nhất
    string lowest_selling = getLowest(salsa_names, number_of_jars_sold, ARRAY_SIZE);
    cout << "Lowest selling = " << lowest_selling << endl << endl;

    return 0;
} // End int main()

int inputValidate(int user_number)
{
    while (!(cin >> user_number) || user_number < 0)
    {
        cout << "Error. Only positve number. Try again: ";
        cin.clear();
        cin >> user_number;
    }
    return user_number;
}
//tạo 1 hàm để nhập
void getNumberSold(const string names_array[], int values_array[], const int SIZE)
{
    for (int i = 0; i < SIZE; i++)
    {
        cout << "Enter number of jars sold for " << names_array[i] << ": ";
        //nếu nhập sai thì hàm sẽ sử dụng hàm inputValidate để nhập lại
        values_array[i] = inputValidate(values_array[i]);
    }
    
}
//tạo 1 hàm để tính tổng
int getTotal(const int array[], const int SIZE)

{
    int total = 0;

    for (int i = 0; i < SIZE; i++)
        total += array[i];

    return total;
}
//hàm để xuất giá trị lớn nhất
string getHighest(const string array1[], const int array2[], int ARRAY_SIZE)
{
    int highest = array2[0];
    string highest_name = array1[0];

    for (int i = 1; i < ARRAY_SIZE; i++)
    {
        if (array2[i] > highest)
        {
            highest = array2[i];
            highest_name = array1[i];
            
        } 
        else if (array2[i] == highest)
        {

            highest = array2[i];
            highest_name += ", ";
            highest_name += array1[i];
            
        }
        
    }
    
    return highest_name;
}
//lap ra ham de tim gia tri nho nhat
string getLowest(const string array1[], const int array2[], int ARRAY_SIZE)
{
    int lowest = array2[0];
    string lowest_name = array1[0];

    for (int i = 1; i < ARRAY_SIZE; i++)
    {
        if (array2[i] < lowest)
        {
            lowest = array2[i];
            lowest_name = array1[i];
            
        } 
        else if (array2[i] == lowest)
        {
            lowest = array2[i];
            lowest_name += ", ";
            lowest_name += array1[i];

        }
        
    }
    
    return lowest_name;
}