#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cout << "Nhập n: ";
    cin >> n;
    vector<int> a(n);
    cout << "Nhập mảng:\n";
    for (int& x : a) cin >> x;
    sortArr(a);
    cout << "Mảng sau sắp xếp:\n";
    for (int x : a) cout << x << " ";
    return 0;
}
void sortArr(vector<int>& a) {
    vector<int> e, o;
    // Lưu số chẵn và số lẻ vào mảng riêng
    for (int x : a) {
        if (x == 0) continue;
        (x % 2 == 0) ? e.push_back(x) : o.push_back(x);
    }
    // Sắp xếp chẵn tăng, lẻ giảm
    sort(e.begin(), e.end());
    sort(o.begin(), o.end(), greater<int>());
    // Gán lại giá trị, giữ nguyên số 0
    int ei = 0, oi = 0;
    for (int& x : a) {
        if (x == 0) continue;
        x = (x % 2 == 0) ? e[ei++] : o[oi++];
    }
}
