#include <iostream>
#include <vector>
#include <cmath>=
using namespace std;

int main() {
    int n, k;
    cout << "Nhập số phần tử: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Nhập dãy số: ";
    for (int i = 0; i < n; i++) cin >> arr[i];
    cout << "Nhập k: ";
    cin >> k;
    // Tìm vị trí k lớn nhất
    topK(arr, k);
    // Sắp xếp theo tổng chữ số
    sortBySum(arr);
    cout << "Dãy sau khi sắp xếp: ";
    for (int num : arr) cout << num << " ";
    cout << endl;
    // Xóa số nguyên tố
    removePrime(arr);
    cout << "Dãy sau khi xóa số nguyên tố: ";
    for (int num : arr) cout << num << " ";
    cout << endl;
    return 0;
}

// Hàm tính tổng chữ số
int digitSum(int num) {
    int sum = 0, temp = abs(num);
    while (temp) {
        sum += temp % 10;
        temp /= 10;
    }
    return sum;
}
// Hàm kiểm tra số nguyên tố
bool isPrime(int num) {
    if (num < 2) return false;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return false;
    }
    return true;
}
// Tìm vị trí k số lớn nhất
void topK(const vector<int>& arr, int k) {
    vector<int> indices(arr.size());
    for (int i = 0; i < arr.size(); i++) indices[i] = i;
    for (int i = 0; i < k; i++) {        // Selection Sort tìm k phần tử lớn nhất
        int maxIdx = i;
        for (int j = i + 1; j < arr.size(); j++) {
            if (arr[j] > arr[maxIdx]) maxIdx = j;
        }
        swap(indices[i], indices[maxIdx]);
    }
    cout << "Vị trí " << k << " số lớn nhất: ";
    for (int i = 0; i < k; i++) {
        cout << indices[i] << " ";
    }
    cout << endl;
}
// Sắp xếp theo tổng chữ số
void sortBySum(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (digitSum(arr[j]) < digitSum(arr[minIdx])) {
                minIdx = j;
            }
        }
        swap(arr[i], arr[minIdx]);
    }
}
// Xóa số nguyên tố
void removePrime(vector<int>& arr) {
    vector<int> temp;
    for (int num : arr) {
        if (!isPrime(num)) temp.push_back(num);
    }
    arr = temp;
}

