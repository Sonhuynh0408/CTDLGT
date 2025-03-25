#include <iostream>
#include <cstdlib>  // Thư viện C cho rand()
#include <ctime>    // Để sử dụng time(0)
#include <chrono>   // Đo thời gian
using namespace std;
using namespace chrono;

int main() {
    int sizes[] = {10, 100, 200, 500, 1000, 5000, 10000};
    int tests = 5;
    cout << "Quick Sort:\n";
    for (int n : sizes)
        for (int i = 0; i < tests; i++)
            testSorting(n, [](int arr[], int n) { quickSort(arr, 0, n - 1); });
    cout << "\nMerge Sort:\n";
    for (int n : sizes)
        for (int i = 0; i < tests; i++)
            testSorting(n, [](int arr[], int n) { mergeSort(arr, 0, n - 1); });
    cout << "\nHeap Sort:\n";
    for (int n : sizes)
        for (int i = 0; i < tests; i++)
            testSorting(n, [](int arr[], int n) { heapSort(arr, n); });
    return 0;
}

const int MAX_N = 10000;
int cmp, swapCount;
// Hàm tạo mảng
void generateArray(int arr[], int n) {
    srand(time(0)); // Đảm bảo số ngẫu nhiên thay đổi mỗi lần chạy
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 10000; // Sinh số từ 0 đến 9999
    }
}

// **QUICK SORT**
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        cmp++;
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
            swapCount++;
        }
    }
    swap(arr[i + 1], arr[high]);
    swapCount++;
    return i + 1;
}
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
// MERGE SORT
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int L[n1], R[n2];

    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        cmp++;
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
        swapCount++;
    }

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}
// HEAP SORT
void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1, right = 2 * i + 2;
    if (left < n) {
        cmp++;
        if (arr[left] > arr[largest]) largest = left;
    }
    if (right < n) {
        cmp++;
        if (arr[right] > arr[largest]) largest = right;
    }
    if (largest != i) {
        swap(arr[i], arr[largest]);
        swapCount++;
        heapify(arr, n, largest);
    }
}
void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) heapify(arr, n, i);
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        swapCount++;
        heapify(arr, i, 0);
    }
}
// THỰC NGHIỆM
void testSorting(int n, void (*sortFunction)(int[], int)) {
    int arr[MAX_N];
    generateArray(arr, n);
    cmp = 0, swapCount = 0;
    auto start = high_resolution_clock::now();
    sortFunction(arr, n);
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);
    cout << "Kich thuoc: " << n 
         << " | So sanh: " << cmp 
         << " | Doi cho: " << swapCount 
         << " | Thoi gian: " << duration.count() << "ms\n";
}
