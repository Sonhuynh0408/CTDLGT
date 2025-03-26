#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int m, n;
    cout << "Nhập số dòng và số cột: ";
    cin >> m >> n;

    vector<vector<int>> mat(m, vector<int>(n));

    cout << "Nhập ma trận:\n";
    for (auto& row : mat)
        for (int& num : row) cin >> num;
    // Tìm dòng có tổng lớn nhất
    int maxIndex = 0, maxSum = sumRow(mat[0]);
    for (int i = 1; i < m; i++) {
        int sum = sumRow(mat[i]);
        if (sum > maxSum) {
            maxSum = sum;
            maxIndex = i;
        }
    }
    cout << "Dòng có tổng lớn nhất: " << maxIndex + 1 << " (Tổng = " << maxSum << ")\n";
    // Sắp xếp dòng theo tổng giảm dần
    sort(mat.begin(), mat.end(), [](const vector<int>& a, const vector<int>& b) {
        return sumRow(a) > sumRow(b); // Sắp xếp giảm dần
    });
    cout << "Ma trận sau khi sắp xếp:\n";
    for (const auto& row : mat) {
        for (int num : row) cout << num << " ";
        cout << endl;
    }
    return 0;
}

// Hàm tính tổng các phần tử trong một dòng
int sumRow(const vector<int>& row) {
    int sum = 0;
    for (int num : row) sum += num;
    return sum;
}

