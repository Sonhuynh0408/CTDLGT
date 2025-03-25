#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Nhập số phòng: ";
    cin >> n;
    Rm r[n];
    in(r, n);
    sortC(r, n);
    cout << "\nDanh sách theo sức chứa giảm dần:\n";
    out(r, n);
    sortB(r, n);
    cout << "\nDanh sách theo nhà (A → Z), số phòng tăng:\n";
    out(r, n);
    return 0;
}
struct Rm {
    int id;  // Số phòng
    char b;  // Nhà
    int c;   // Sức chứa
};

// Nhập danh sách phòng
void in(Rm r[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "Nhập số phòng, nhà, sức chứa: ";
        cin >> r[i].id >> r[i].b >> r[i].c;
    }
}
// Hiển thị danh sách
void out(Rm r[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "Phòng " << r[i].id << " - Nhà " << r[i].b << " - Sức chứa " << r[i].c << endl;
    }
}
// Sắp xếp giảm dần theo sức chứa
void sortC(Rm r[], int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (r[j].c < r[j + 1].c)
                swap(r[j], r[j + 1]);
}

// Sắp xếp tăng dần theo Nhà, cùng nhà thì theo số phòng
void sortB(Rm r[], int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (r[j].b > r[j + 1].b || 
               (r[j].b == r[j + 1].b && r[j].id > r[j + 1].id))
                swap(r[j], r[j + 1]);
}

