#include<iostream>
using namespace std;
int main(){
    int a[10];
    //yeu cau nguoi dung nhap 10 so
    for(int i = 0; i < 10; i++){
        cout << "nhap so thu " << i+1 << endl;
        cin >> a[i];
    }

    int largest = a[0];//gan gia tri lon nhat
    int smallest = a[0];//gan gia tri nho nhat
    for(int i = 1; i < 10; i++){
        if(a[i] > largest){
            largest = a[i];
        }
        if(a[i] < smallest){
            smallest = a[i];
        }
    }
    cout << largest << endl;
    cout << smallest << endl;
    return 0;
}