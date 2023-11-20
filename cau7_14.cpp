#include <iostream>
#include <cstdlib> // Chứa hàm srand và rand
#include <ctime>   // Chứa hàm time

using namespace std;

const int ARRAY_SIZE = 5;

// Hàm để tạo mảng ngẫu nhiên từ 0 đến 9
void taoMangNgauNhien(int mang[]) {
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        mang[i] = rand() % 10; // Tạo số ngẫu nhiên từ 0 đến 9
    }
}

// Hàm để kiểm tra và đếm số phần tử giống nhau trong hai mảng
int demSoPhanTuGiongNhau(int mang1[], int mang2[]) {
    int dem = 0;
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        if (mang1[i] == mang2[i]) {
            dem++;
        }
    }
    return dem;
}

int main() {
    int lottery[ARRAY_SIZE];
    int user[ARRAY_SIZE];

    // Thiết lập seed cho hàm rand để tạo số ngẫu nhiên mỗi lần chạy chương trình
    srand(static_cast<unsigned int>(time(0)));

    // Tạo mảng ngẫu nhiên cho lottery
    taoMangNgauNhien(lottery);

    // Nhập số từ người dùng cho user
    cout << "Nhập 5 chữ số của bạn (từ 0 đến 9): ";
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        cin >> user[i];
    }

    // Hiển thị mảng lottery
    cout << "Mảng lottery: ";
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        cout << lottery[i] << " ";
    }
    cout << endl;

    // Hiển thị mảng user
    cout << "Mảng user: ";
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        cout << user[i] << " ";
    }
    cout << endl;

    // Đếm số phần tử giống nhau và hiển thị kết quả
    int soPhanTuGiongNhau = demSoPhanTuGiongNhau(lottery, user);

    cout << "Số chữ số giống nhau: " << soPhanTuGiongNhau << endl;

    // Kiểm tra nếu tất cả đều giống nhau
    if (soPhanTuGiongNhau == ARRAY_SIZE) {
        cout << "Chúc mừng! Bạn là người chiến thắng lớn!" << endl;
    }

    return 0;
}
