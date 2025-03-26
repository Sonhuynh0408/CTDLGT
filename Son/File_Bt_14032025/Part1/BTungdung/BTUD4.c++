#include <iostream>
#include <vector>
#include <algorithm>
using namespace std

int main() {
    int m, n;
    cout << "Nhập số dòng và số cột: ";
    cin >> m >> n;

    vector<vector<int>> mat(m, vector<int>(n));
    cout << "Nhập ma trận:\n";
    for (auto& row : mat)
        for (int& num : row) cin >> num;
    // Sắp xếp các dòng theo tổng số nguyên tố trong dòng (tăng dần)
    sort(mat.begin(), mat.end(), [](const vector<int>& a, const vector<int>& b) {
        return sumPrimeRow(a) < sumPrimeRow(b);
    });
    cout << "Ma trận sau khi sắp xếp:\n";
    for (const auto& row : mat) {
        for (int num : row) cout << num << " ";
        cout << endl;
    }

    return 0;
}
bool isPrime(int num) {
    if (num < 2) return false;
    for (int i = 2; i * i <= num; i++)
        if (num % i == 0) return false;
    return true;
}
// Hàm tính tổng các số nguyên tố trong dòng
int sumPrimeRow(const vector<int>& row) {
    int sum = 0;
    for (int num : row)
        if (isPrime(num)) sum += num;
    return sum;
}
