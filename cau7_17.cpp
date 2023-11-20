#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm> // Sử dụng để sắp xếp vector

using namespace std;

// Hàm để đọc nội dung từ file và lưu vào vector
void docFileVaLuuvaoVector(const string& tenFile, vector<string>& danhSachTen) {
    ifstream file(tenFile);

    if (!file.is_open()) {
        cout << "Không thể mở file: " << tenFile << endl;
        return;
    }

    string ten;
    while (getline(file, ten)) {
        danhSachTen.push_back(ten);
    }

    file.close();
}

// Hàm để kiểm tra xem tên có thuộc danh sách phổ biến không
bool laTenPhoBien(const vector<string>& danhSachTen, const string& tenCanKiemTra) {
    return find(danhSachTen.begin(), danhSachTen.end(), tenCanKiemTra) != danhSachTen.end();
}

int main() {
    const string tenFileGirlNames = "GirlNames.txt";
    const string tenFileBoyNames = "BoyNames.txt";

    vector<string> danhSachGirlNames;
    vector<string> danhSachBoyNames;

    // Đọc nội dung từ file và lưu vào vector
    docFileVaLuuvaoVector(tenFileGirlNames, danhSachGirlNames);
    docFileVaLuuvaoVector(tenFileBoyNames, danhSachBoyNames);

    // Nhập tên từ người dùng
    cout << "Nhập tên cần kiểm tra (để kiểm tra cả tên trai và tên gái, nhập cả hai): ";
    string tenNhap;
    getline(cin, tenNhap);

    // Kiểm tra xem tên có thuộc danh sách phổ biến không
    bool laTenGaiPhoBien = laTenPhoBien(danhSachGirlNames, tenNhap);
    bool laTenTraiPhoBien = laTenPhoBien(danhSachBoyNames, tenNhap);

    // Hiển thị kết quả
    if (laTenGaiPhoBien && laTenTraiPhoBien) {
        cout << "Tên " << tenNhap << " là một trong những tên phổ biến cho cả trai và gái." << endl;
    } else if (laTenGaiPhoBien) {
        cout << "Tên " << tenNhap << " là một trong những tên phổ biến cho gái." << endl;
    } else if (laTenTraiPhoBien) {
        cout << "Tên " << tenNhap << " là một trong những tên phổ biến cho trai." << endl;
    } else {
        cout << "Tên " << tenNhap << " không nằm trong danh sách tên phổ biến." << endl;
    }

    return 0;
}
