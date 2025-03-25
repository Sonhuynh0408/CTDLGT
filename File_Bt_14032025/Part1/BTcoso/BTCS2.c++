#include <iostream>
using namespace std;

int main() {
    int arr1[] = {8, 5, 1, 3, 6, 9, 12, 4, 7, 10};
    int arr2[] = {8, 5, 1, 3, 6, 9, 12, 4, 7, 10};
    int arr3[] = {8, 5, 1, 3, 6, 9, 12, 4, 7, 10};
    int n = sizeof(arr1) / sizeof(arr1[0]);
    cout << "Quick Sort: ";
    quickSort(arr1, 0, n - 1);
    printArray(arr1, n);
    cout << "Merge Sort: ";
    mergeSort(arr2, 0, n - 1);
    printArray(arr2, n);
    cout << "Heap Sort: ";
    heapSort(arr3, n);
    printArray(arr3, n);
    return 0;
}
//  in mảng
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}
//Quick Sort
void quickSort(int arr[], int left, int right) {
    if (left >= right) return;
    int pivot = arr[right], i = left, j = right - 1;
    while (i <= j) {
        while (i <= j && arr[i] < pivot) i++;
        while (i <= j && arr[j] > pivot) j--;
        if (i <= j) swap(arr[i++], arr[j--]);
    }
    swap(arr[i], arr[right]); 
    quickSort(arr, left, i - 1);
    quickSort(arr, i + 1, right);
}
//Merge Sort
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1, n2 = right - mid;
    int L[n1], R[n2];
    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int i = 0; i < n2; i++) R[i] = arr[mid + 1 + i];
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) arr[k++] = (L[i] < R[j]) ? L[i++] : R[j++];
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}
void mergeSort(int arr[], int left, int right) {
    if (left >= right) return;
    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}
//Heap Sort
void heapify(int arr[], int n, int i) {
    int largest = i, left = 2 * i + 1, right = 2 * i + 2;
    if (left < n && arr[left] > arr[largest]) largest = left;
    if (right < n && arr[right] > arr[largest]) largest = right;
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}
void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) heapify(arr, n, i);
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

