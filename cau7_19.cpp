#include <iostream>
#include <iomanip> // Sử dụng để định dạng xuất

using namespace std;

const int ROWS = 3;
const int COLS = 4;

// Hàm để hiển thị mảng
void hienThiMang(int mang[][COLS], int dong, int cot) {
    for (int i = 0; i < dong; i++) {
        for (int j = 0; j < cot; j++) {
            cout << setw(5) << mang[i][j] << " ";
        }
        cout << endl;
    }
}

// Hàm để tính tổng của tất cả các giá trị trong mảng
int getTotal(int mang[][COLS], int dong, int cot) {
    int tong = 0;
    for (int i = 0; i < dong; i++) {
        for (int j = 0; j < cot; j++) {
            tong += mang[i][j];
        }
    }
    return tong;
}

// Hàm để tính trung bình của tất cả các giá trị trong mảng
double getAverage(int mang[][COLS], int dong, int cot) {
    int tong = getTotal(mang, dong, cot);
    return static_cast<double>(tong) / (dong * cot);
}

// Hàm để tính tổng của giá trị trong một dòng cụ thể
int getRowTotal(int mang[][COLS], int dong, int cot, int dongCanTinh) {
    int tong = 0;
    for (int j = 0; j < cot; j++) {
        tong += mang[dongCanTinh][j];
    }
    return tong;
}

// Hàm để tính tổng của giá trị trong một cột cụ thể
int getColumnTotal(int mang[][COLS], int dong, int cot, int cotCanTinh) {
    int tong = 0;
    for (int i = 0; i < dong; i++) {
        tong += mang[i][cotCanTinh];
    }
    return tong;
}

// Hàm để tìm giá trị lớn nhất trong một dòng cụ thể
int getHighestInRow(int mang[][COLS], int dong, int cot, int dongCanTinh) {
    int maxVal = mang[dongCanTinh][0];
    for (int j = 1; j < cot; j++) {
        if (mang[dongCanTinh][j] > maxVal) {
            maxVal = mang[dongCanTinh][j];
        }
    }
    return maxVal;
}

// Hàm để tìm giá trị nhỏ nhất trong một dòng cụ thể
int getLowestInRow(int mang[][COLS], int dong, int cot, int dongCanTinh) {
    int minVal = mang[dongCanTinh][0];
    for (int j = 1; j < cot; j++) {
        if (mang[dongCanTinh][j] < minVal) {
            minVal = mang[dongCanTinh][j];
        }
    }
    return minVal;
}

int main() {
    int mang[ROWS][COLS] = {{1, 2, 3, 4},
                            {5, 6, 7, 8},
                            {9, 10, 11, 12}};

    // Hiển thị mảng
    cout << "Mảng ban đầu:\n";
    hienThiMang(mang, ROWS, COLS);

    // Gọi các hàm và hiển thị kết quả
    cout << "\nTổng các giá trị trong mảng: " << getTotal(mang, ROWS, COLS) << endl;
    cout << "Trung bình các giá trị trong mảng: " << fixed << setprecision(2) << getAverage(mang, ROWS, COLS) << endl;
    cout << "Tổng các giá trị trong dòng 2: " << getRowTotal(mang, ROWS, COLS, 1) << endl;
    cout << "Tổng các giá trị trong cột 3: " << getColumnTotal(mang, ROWS, COLS, 2) << endl;
    cout << "Giá trị lớn nhất trong dòng 3: " << getHighestInRow(mang, ROWS, COLS, 2) << endl;
    cout << "Giá trị nhỏ nhất trong dòng 3: " << getLowestInRow(mang, ROWS, COLS, 2) << endl;

    return 0;
}
