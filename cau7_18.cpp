#include <iostream>
using namespace std;

// Hàm để hiển thị nội dung của bảng
void hienThiBang(char bang[][3]) {
    cout << "Bảng hiện tại:\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << bang[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

// Hàm để kiểm tra xem có người chiến thắng hay không
bool kiemTraChienThang(char bang[][3], char kyTu) {
    // Kiểm tra theo hàng và cột
    for (int i = 0; i < 3; i++) {
        if (bang[i][0] == kyTu && bang[i][1] == kyTu && bang[i][2] == kyTu) {
            return true; // Người chiến thắng
        }
        if (bang[0][i] == kyTu && bang[1][i] == kyTu && bang[2][i] == kyTu) {
            return true; // Người chiến thắng
        }
    }

    // Kiểm tra theo đường chéo
    if (bang[0][0] == kyTu && bang[1][1] == kyTu && bang[2][2] == kyTu) {
        return true; // Người chiến thắng
    }
    if (bang[0][2] == kyTu && bang[1][1] == kyTu && bang[2][0] == kyTu) {
        return true; // Người chiến thắng
    }

    return false;
}

// Hàm để kiểm tra xem có hòa hay không
bool kiemTraHoa(char bang[][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (bang[i][j] == '*') {
                return false; // Chưa đầy bảng
            }
        }
    }
    return true; // Bảng đã đầy, hòa
}

int main() {
    char bang[3][3];

    // Khởi tạo bảng với các dấu "*"
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            bang[i][j] = '*';
        }
    }

    char kyTu;
    int hang, cot;

    do {
        // Hiển thị bảng
        hienThiBang(bang);

        // Lượt của người chơi 1 (X)
        kyTu = 'X';
        cout << "Người chơi 1 (X), nhập hàng và cột (1-3): ";
        cin >> hang >> cot;
        bang[hang - 1][cot - 1] = kyTu;

        // Kiểm tra chiến thắng
        if (kiemTraChienThang(bang, kyTu)) {
            hienThiBang(bang);
            cout << "Người chơi 1 (X) chiến thắng!\n";
            break;
        }

        // Kiểm tra hòa
        if (kiemTraHoa(bang)) {
            hienThiBang(bang);
            cout << "Trò chơi hòa!\n";
            break;
        }

        // Hiển thị bảng sau lượt của người chơi 1
        hienThiBang(bang);

        // Lượt của người chơi 2 (O)
        kyTu = 'O';
        cout << "Người chơi 2 (O), nhập hàng và cột (1-3): ";
        cin >> hang >> cot;
        bang[hang - 1][cot - 1] = kyTu;

        // Kiểm tra chiến thắng
        if (kiemTraChienThang(bang, kyTu)) {
            hienThiBang(bang);
            cout << "Người chơi 2 (O) chiến thắng!\n";
            break;
        }

        // Kiểm tra hòa
        if (kiemTraHoa(bang)) {
            hienThiBang(bang);
            cout << "Trò chơi hòa!\n";
            break;
        }

    } while (true);

    return 0;
}
