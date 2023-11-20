#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

const int MAX_QUESTIONS = 20;

// Hàm để đọc đáp án đúng từ file và lưu vào mảng
void docDapAnDung(char correctAnswers[MAX_QUESTIONS], const char* fileName) {
    ifstream inputFile(fileName);

    if (!inputFile) {
        cerr << "Không thể mở file " << fileName << " để đọc." << endl;
        exit(1);
    }

    for (int i = 0; i < MAX_QUESTIONS; ++i) {
        inputFile >> correctAnswers[i];
    }

    inputFile.close();
}

// Hàm để đọc câu trả lời của sinh viên từ file và lưu vào mảng
void docCauTraLoiSinhVien(char studentAnswers[MAX_QUESTIONS], const char* fileName) {
    ifstream inputFile(fileName);

    if (!inputFile) {
        cerr << "Không thể mở file " << fileName << " để đọc." << endl;
        exit(1);
    }

    for (int i = 0; i < MAX_QUESTIONS; ++i) {
        inputFile >> studentAnswers[i];
    }

    inputFile.close();
}

// Hàm để đếm số câu hỏi bị trả lời sai và hiển thị chi tiết
void danhGiaBaiThi(char correctAnswers[MAX_QUESTIONS], char studentAnswers[MAX_QUESTIONS]) {
    int soCauHoiSai = 0;

    // Danh sách các câu hỏi bị trả lời sai
    cout << "Các câu hỏi bị trả lời sai:" << endl;
    for (int i = 0; i < MAX_QUESTIONS; ++i) {
        if (studentAnswers[i] != correctAnswers[i]) {
            soCauHoiSai++;
            cout << "Câu " << (i + 1) << ": Đúng: " << correctAnswers[i] << ", Sai: " << studentAnswers[i] << endl;
        }
    }

    // Hiển thị tổng số câu hỏi bị trả lời sai
    cout << "\nTổng số câu hỏi bị trả lời sai: " << soCauHoiSai << endl;

    // Tính tỷ lệ câu hỏi đúng
    double tyLeDung = (MAX_QUESTIONS - soCauHoiSai) / static_cast<double>(MAX_QUESTIONS) * 100;

    // Hiển thị tỷ lệ câu hỏi đúng
    cout << "Tỷ lệ câu hỏi đúng: " << fixed << setprecision(2) << tyLeDung << "%" << endl;

    // Kiểm tra nếu sinh viên đã qua hay chưa
    if (tyLeDung >= 70) {
        cout << "Sinh viên đã qua kỳ thi!" << endl;
    } else {
        cout << "Sinh viên không đạt được số điểm cần thiết để qua kỳ thi." << endl;
    }
}

int main() {
    char correctAnswers[MAX_QUESTIONS];
    char studentAnswers[MAX_QUESTIONS];

    // Đọc đáp án đúng từ file
    docDapAnDung(correctAnswers, "CorrectAnswers.txt");

    // Đọc câu trả lời của sinh viên từ file
    docCauTraLoiSinhVien(studentAnswers, "StudentAnswers.txt");

    // Đánh giá bài thi
    danhGiaBaiThi(correctAnswers, studentAnswers);

    return 0;
}
