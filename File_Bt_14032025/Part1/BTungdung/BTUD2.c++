#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Nhập số hạng: ";
    cin >> n;
    Term p[n]; // Mảng lưu các số hạng
    // Nhập dữ liệu
    for (int i = 0; i < n; i++) {
        cout << "Nhập hệ số và bậc của hạng " << i + 1 << ": ";
        cin >> p[i].c >> p[i].d;
    }
    sort(p, n);     // Sắp xếp theo bậc
    // In kết quả
    cout << "Đa thức sau khi sắp xếp:\n";
    for (int i = 0; i < n; i++) {
        cout << p[i].c << "x^" << p[i].d << " ";
    }
    cout << endl;
    return 0;
}

// Định nghĩa cấu trúc Term để lưu hệ số và bậc
struct Term {
    double c; // Hệ số (Coefficient)
    int d;    // Bậc (Degree)
};

// Hàm Selection Sort theo bậc tăng dần
void sort(Term p[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            if (p[j].d < p[min].d) {
                min = j;
            }
        }
        swap(p[i], p[min]);
    }
}

