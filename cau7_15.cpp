#include <iostream>
#include <vector> // Thêm thư viện vector
using namespace std;

// Nguyên mẫu hàm
bool kiemTraPIN(const vector<int>&, const vector<int>&, int);

int main()
{
    const int SO_CHU_SO = 7; // Số chữ số trong một PIN

    // Sử dụng vector thay vì mảng
    vector<int> pin1 = {2, 4, 1, 8, 7, 9, 0};
    vector<int> pin2 = {2, 4, 6, 8, 7, 9, 0};
    vector<int> pin3 = {1, 2, 3, 4, 5, 6, 7};

    if (kiemTraPIN(pin1, pin2, SO_CHU_SO))
        cout << "LỖI: pin1 và pin2 báo cáo giống nhau.\n";
    else
        cout << "THÀNH CÔNG: pin1 và pin2 khác nhau.\n";

    if (kiemTraPIN(pin1, pin3, SO_CHU_SO))
        cout << "LỖI: pin1 và pin3 báo cáo giống nhau.\n";
    else
        cout << "THÀNH CÔNG: pin1 và pin3 khác nhau.\n";

    if (kiemTraPIN(pin1, pin1, SO_CHU_SO))
        cout << "THÀNH CÔNG: pin1 và pin1 báo cáo giống nhau.\n";
    else
        cout << "LỖI: pin1 và pin1 báo cáo khác nhau.\n";

    return 0;
}

// Sửa đổi hàm để chấp nhận vector
bool kiemTraPIN(const vector<int>& custPIN, const vector<int>& databasePIN, int size)
{
    for (int index = 0; index < size; index++)
    {
        if (custPIN[index] != databasePIN[index])
            return false; // Chúng ta đã tìm thấy hai giá trị khác nhau.
    }
    return true; // Nếu chúng ta đến được đến đây, các giá trị giống nhau.
}
