#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    const int SIZE = 20;  // Kích thước mảng cho câu hỏi và câu trả lời của sinh viên
    char correctAnswers[SIZE] = {'A', 'D', 'B', 'B', 'C', 'B', 'A', 'B', 'C', 'D', 'A', 'C', 'D', 'B', 'D', 'C', 'C', 'A', 'D', 'B'};
    char studentAnswers[SIZE];  // Mảng lưu câu trả lời của sinh viên

    // Nhập câu trả lời của sinh viên
    cout << "Nhập câu trả lời cho từng câu hỏi (A, B, C, hoặc D):" << endl;
    for (int i = 0; i < SIZE; ++i) {
        cout << "Câu " << (i + 1) << ": ";
        cin >> studentAnswers[i];

        // Kiểm tra tính hợp lệ của câu trả lời
        while (studentAnswers[i] != 'A' && studentAnswers[i] != 'B' && studentAnswers[i] != 'C' && studentAnswers[i] != 'D') {
            cout << "Câu trả lời không hợp lệ. Vui lòng nhập lại (A, B, C, hoặc D): ";
            cin >> studentAnswers[i];
        }
    }

    // Đánh giá kết quả
    int correctCount = 0;  // Số câu trả lời đúng
    int incorrectCount = 0;  // Số câu trả lời sai
    int incorrectQuestions[SIZE];  // Mảng lưu số câu hỏi bị trả lời sai

    // Kiểm tra từng câu trả lời
    for (int i = 0; i < SIZE; ++i) {
        if (studentAnswers[i] == correctAnswers[i]) {
            correctCount++;
        } else {
            incorrectQuestions[incorrectCount] = i + 1;  // Lưu số câu hỏi bị trả lời sai
            incorrectCount++;
        }
    }

    // Hiển thị kết quả
    cout << "\nKết quả:" << endl;
    cout << "Số câu trả lời đúng: " << correctCount << endl;
    cout << "Số câu trả lời sai: " << incorrectCount << endl;

    // Kiểm tra nếu sinh viên đã qua hay chưa
    if (correctCount >= 15) {
        cout << "Sinh viên đã qua kỳ thi!" << endl;
    } else {
        cout << "Sinh viên không đạt được số điểm cần thiết để qua kỳ thi." << endl;
        cout << "Câu hỏi bị trả lời sai: ";
        for (int i = 0; i < incorrectCount; ++i) {
            cout << incorrectQuestions[i];
            if (i < incorrectCount - 1) {
                cout << ", ";
            }
        }
        cout << endl;
    }

    return 0;
}
