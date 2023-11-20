#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

const int SO_HANG = 15;
const int SO_GHE_MOT_HANG = 30;

vector<vector<char>> ghe(SO_HANG, vector<char>(SO_GHE_MOT_HANG, '#'));
vector<double> giaVe(SO_HANG, 0.0);
double doanhThu = 0.0;

// Khai báo hàm
void nhapGiaVe();
void hienThiGhe();
void banVe();
void hienThiDoanhThu();
void hienThiTinhTrangGhe();

int main() {
    nhapGiaVe();

    int luaChon;
    do {
        cout << "\n1. Hiển thị sơ đồ chỗ ngồi\n";
        cout << "2. Bán vé\n";
        cout << "3. Hiển thị tổng doanh thu\n";
        cout << "4. Hiển thị tình trạng ghế\n";
        cout << "0. Thoát\n";
        cout << "Nhập lựa chọn của bạn: ";
        cin >> luaChon;

        switch (luaChon) {
            case 1:
                hienThiGhe();
                break;
            case 2:
                banVe();
                break;
            case 3:
                hienThiDoanhThu();
                break;
            case 4:
                hienThiTinhTrangGhe();
                break;
            case 0:
                cout << "Kết thúc chương trình.\n";
                break;
            default:
                cout << "Lựa chọn không hợp lệ. Vui lòng thử lại.\n";
        }
    } while (luaChon != 0);

    return 0;
}

void nhapGiaVe() {
    cout << "Nhập giá vé cho từng hàng:\n";
    for (int i = 0; i < SO_HANG; ++i) {
        cout << "Hàng " << (i + 1) << ": $";
        cin >> giaVe[i];
    }
}

void hienThiGhe() {
    cout << "\nSơ đồ chỗ ngồi\n";
    for (int i = 0; i < SO_HANG; ++i) {
        cout << "Hàng " << setw(2) << (i + 1) << " ";
        for (int j = 0; j < SO_GHE_MOT_HANG; ++j) {
            cout << ghe[i][j];
        }
        cout << endl;
    }
}

void banVe() {
    int hang, cho;
    double giaVeHang;

    cout << "Nhập số hàng và số chỗ (0 0 để dừng): ";
    cin >> hang >> cho;

    while (hang != 0 && cho != 0) {
        if (hang < 1 || hang > SO_HANG || cho < 1 || cho > SO_GHE_MOT_HANG) {
            cout << "Hàng hoặc chỗ không hợp lệ. Vui lòng thử lại.\n";
        } else if (ghe[hang - 1][cho - 1] == '*') {
            cout << "Chỗ ngồi đã có người. Vui lòng chọn chỗ khác.\n";
        } else {
            ghe[hang - 1][cho - 1] = '*';
            giaVeHang = giaVe[hang - 1];
            doanhThu += giaVeHang;
            cout << "Vé đã được bán với giá $" << giaVeHang << ". Tổng doanh thu: $" << doanhThu << endl;
        }

        cout << "Nhập số hàng và số chỗ (0 0 để dừng): ";
        cin >> hang >> cho;
    }
}

void hienThiDoanhThu() {
    cout << "Tổng doanh thu: $" << doanhThu << endl;
}

void hienThiTinhTrangGhe() {
    int soGheTrong;
    cout << "\nTình trạng ghế\n";
    for (int i = 0; i < SO_HANG; ++i) {
        soGheTrong = count(ghe[i].begin(), ghe[i].end(), '#');
        cout << "Hàng " << (i + 1) << ": " << soGheTrong << " ghế trống\n";
    }

    int tongGheTrong = 0;
    for (int i = 0; i < SO_HANG; ++i) {
        tongGheTrong += count(ghe[i].begin(), ghe[i].end(), '#');
    }

    cout << "Tổng số ghế trống: " << tongGheTrong << endl;
}