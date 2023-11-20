#include <iostream>
#include <iomanip>
#include <string>
#include <limits> // Để sử dụng giá trị tối đa cho double

using namespace std;

const int NUM_STUDENTS = 5;
const int NUM_TESTS = 4;

// Hàm để tính trung bình cộng và xếp hạng từ điểm số
char tinhXepHang(double diemTrungBinh) {
    if (diemTrungBinh >= 90) {
        return 'A';
    } else if (diemTrungBinh >= 80) {
        return 'B';
    } else if (diemTrungBinh >= 70) {
        return 'C';
    } else if (diemTrungBinh >= 60) {
        return 'D';
    } else {
        return 'F';
    }
}

// Hàm để tìm điểm thấp nhất trong mảng
double timDiemThapNhat(double diemHocSinh[NUM_TESTS]) {
    double diemThapNhat = numeric_limits<double>::max(); // Sử dụng giá trị tối đa của double làm giá trị ban đầu

    for (int i = 0; i < NUM_TESTS; ++i) {
        if (diemHocSinh[i] < diemThapNhat) {
            diemThapNhat = diemHocSinh[i];
        }
    }

    return diemThapNhat;
}

int main() {
    string tenHocSinh[NUM_STUDENTS];
    char xepHangHocSinh[NUM_STUDENTS];
    double diemHocSinh[NUM_STUDENTS][NUM_TESTS];

    // Nhập thông tin của từng học sinh
    for (int i = 0; i < NUM_STUDENTS; ++i) {
        cout << "Nhập tên của học sinh " << (i + 1) << ": ";
        getline(cin, tenHocSinh[i]);

        // Nhập điểm cho từng bài kiểm tra và kiểm tra tính hợp lệ
        for (int j = 0; j < NUM_TESTS; ++j) {
            do {
                cout << "Nhập điểm cho bài kiểm tra " << (j + 1) << " của học sinh " << tenHocSinh[i] << ": ";
                cin >> diemHocSinh[i][j];

                // Kiểm tra tính hợp lệ của điểm
                if (diemHocSinh[i][j] < 0 || diemHocSinh[i][j] > 100) {
                    cout << "Điểm không hợp lệ. Vui lòng nhập lại trong khoảng từ 0 đến 100." << endl;
                }

            } while (diemHocSinh[i][j] < 0 || diemHocSinh[i][j] > 100);
        }

        // Loại bỏ điểm thấp nhất và tính điểm trung bình và xếp hạng cho từng học sinh
        double diemTrungBinh = 0;
        double diemThapNhat = timDiemThapNhat(diemHocSinh[i]);
        for (int j = 0; j < NUM_TESTS; ++j) {
            diemTrungBinh += diemHocSinh[i][j];
        }
        diemTrungBinh = (diemTrungBinh - diemThapNhat) / (NUM_TESTS - 1);

        xepHangHocSinh[i] = tinhXepHang(diemTrungBinh);
    }

    // Hiển thị thông tin cho từng học sinh
    cout << "\nThông tin học sinh:" << endl;
    for (int i = 0; i < NUM_STUDENTS; ++i) {
        cout << "Học sinh " << tenHocSinh[i] << " có điểm trung bình: " << fixed << setprecision(2) << diemHocSinh[i][j] << ", và xếp hạng: " << xepHangHocSinh[i] << endl;
    }

    return 0;
}
