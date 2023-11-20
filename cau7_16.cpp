#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

// Hàm để đọc nội dung từ file và hiển thị danh sách đội bóng
void hienThiDanhSachDoiBong(const string& tenFile) {
    ifstream file(tenFile);

    if (!file.is_open()) {
        cout << "Không thể mở file: " << tenFile << endl;
        return;
    }

    cout << "Danh sách các đội bóng: \n";
    string team;
    while (getline(file, team)) {
        cout << team << endl;
    }

    file.close();
}

// Hàm để đếm số lần một đội bóng đã chiến thắng World Series từ năm 1903 đến 2012
int demSoLanChienThang(const string& tenFile, const string& tenDoiBong) {
    ifstream file(tenFile);
    int soLanChienThang = 0;

    if (!file.is_open()) {
        cout << "Không thể mở file: " << tenFile << endl;
        return -1;
    }

    string winningTeam;
    while (getline(file, winningTeam)) {
        if (winningTeam == tenDoiBong) {
            soLanChienThang++;
        }
    }

    file.close();

    return soLanChienThang;
}

int main() {
    const string tenFileTeams = "Teams.txt";
    const string tenFileWinners = "WorldSeriesWinners.txt";

    // Hiển thị danh sách đội bóng từ file Teams.txt
    hienThiDanhSachDoiBong(tenFileTeams);

    // Nhập tên đội bóng từ người dùng
    cout << "\nNhập tên đội bóng: ";
    string tenDoiBong;
    getline(cin, tenDoiBong);

    // Đếm số lần đội bóng đã chiến thắng World Series
    int soLanChienThang = demSoLanChienThang(tenFileWinners, tenDoiBong);

    // Hiển thị kết quả
    if (soLanChienThang >= 0) {
        cout << "Đội bóng " << tenDoiBong << " đã chiến thắng World Series " << soLanChienThang << " lần." << endl;
    }

    return 0;
}
