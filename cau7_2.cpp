#include <iostream>
using namespace std;
int main(){
    const int MONTH = 12;
    double rainfall[MONTH];
    double S = 0;
    int i;
    //nhap luong mua trong thang neu nhap sai se ket thuc chuong trinh
    for(int i =0; i < MONTH; i++){
            cout << "nhap luong mua thang " << i+1 << endl;
            cin >> rainfall[i];
            cin.clear();
            while(rainfall[i] < 0){
                //neu so nhap be hon 0 thi se ket thuc chuong trinh
                cout << "ban da nhap sai!" << endl;
                cin >> rainfall[i];
            }
            S += rainfall[i];
    }
    cout << "tong luong mua trong nam la " << S << endl;
    return 0;
}