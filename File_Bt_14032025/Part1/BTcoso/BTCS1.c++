#include <iostream>
using namespace std;


int main() {
    int arr[] = {39, 8, 5, 1, 3, 6, 9, 12, 4, 7, 10};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Original Array: ";
    printArray(arr, size);

    cout << "Interchange Sort: ";
    interchangeSort(arr, size);
    printArray(arr, size);

    // Chạy lại mảng để chạy thuật toán khác
    int arr2[] = {39, 8, 5, 1, 3, 6, 9, 12, 4, 7, 10};
    cout << "Selection Sort: ";
    selectionSort(arr2, size);
    printArray(arr2, size);

    int arr3[] = {39, 8, 5, 1, 3, 6, 9, 12, 4, 7, 10};
    cout << "Insertion Sort: ";
    insertionSort(arr3, size);
    printArray(arr3, size);

    int arr4[] = {39, 8, 5, 1, 3, 6, 9, 12, 4, 7, 10};
    cout << "Bubble Sort: ";
    bubbleSort(arr4, size);
    printArray(arr4, size);

    return 0;
}
//in mảng
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) cout << arr[i] << " ";
    cout << endl;
}
// Sắp xếp đổi chỗ trực tiếp (Interchange Sort)
void interchangeSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] > arr[j]) {
                swap(arr[i], arr[j]);
            }
        }
    }
}
// Sắp xếp chọn trực tiếp (Selection Sort)
void selectionSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}
// Sắp xếp chèn trực tiếp (Insertion Sort)
void insertionSort(int arr[], int size) {
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
// Sắp xếp nổi bọt (Bubble Sort)
void bubbleSort(int arr[], int size) {
    bool swapped;
    for (int i = 0; i < size - 1; i++) {
        swapped = false;
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}
