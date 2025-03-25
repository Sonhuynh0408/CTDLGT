#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> Mang;
    int N, GiaTri;
    cout << "Nhập số phần tử: ";
    cin >> N;
    cout << "Nhập các phần tử: ";
    for (int i = 0; i < N; i++) {
        cin >> GiaTri;
        Mang.push_back(GiaTri);
    }

    vector<int> SaoChep = Mang;
    insertionSort(SaoChep); cout << "Insertion Sort: "; printArray(SaoChep);
    SaoChep = Mang; 
    selectionSort(SaoChep); cout << "Selection Sort: "; printArray(SaoChep);
    SaoChep = Mang; 
    bubbleSort(SaoChep); cout << "Bubble Sort: "; printArray(SaoChep);
    SaoChep = Mang;
    quickSort(SaoChep, 0, SaoChep.size() - 1); cout << "Quick Sort: "; printArray(SaoChep);
    SaoChep = Mang; 
    heapSort(SaoChep); cout << "Heap Sort: "; printArray(SaoChep);
    SaoChep = Mang; 
    interchangeSort(SaoChep); cout << "Interchange Sort: "; printArray(SaoChep);
    
    return 0;
}
void swap(int &A, int &B) {
    int Temp = A;
    A = B;
    B = Temp;
}

void insertionSort(vector<int> &Mang) {
    for (size_t i = 1; i < Mang.size(); i++) {
        int Khoa = Mang[i], j = i - 1;
        while (j >= 0 && Mang[j] < Khoa) {
            Mang[j + 1] = Mang[j];
            j--;
        }
        Mang[j + 1] = Khoa;
    }
}

void selectionSort(vector<int> &Mang) {
    for (size_t i = 0; i < Mang.size() - 1; i++) {
        size_t ChiSoMax = i;
        for (size_t j = i + 1; j < Mang.size(); j++) {
            if (Mang[j] > Mang[ChiSoMax]) ChiSoMax = j;
        }
        swap(Mang[i], Mang[ChiSoMax]);
    }
}

void bubbleSort(vector<int> &Mang) {
    for (size_t i = 0; i < Mang.size() - 1; i++) {
        for (size_t j = 0; j < Mang.size() - i - 1; j++) {
            if (Mang[j] < Mang[j + 1]) swap(Mang[j], Mang[j + 1]);
        }
    }
}

void quickSort(vector<int> &Mang, int Thap, int Cao) {
    if (Thap < Cao) {
        int Chot = Mang[Cao], i = Thap - 1;
        for (int j = Thap; j < Cao; j++) {
            if (Mang[j] > Chot) swap(Mang[++i], Mang[j]);
        }
        swap(Mang[i + 1], Mang[Cao]);
        quickSort(Mang, Thap, i);
        quickSort(Mang, i + 2, Cao);
    }
}

void heapify(vector<int> &Mang, int N, int i) {
    int LonNhat = i, Trai = 2 * i + 1, Phai = 2 * i + 2;
    if (Trai < N && Mang[Trai] > Mang[LonNhat]) LonNhat = Trai;
    if (Phai < N && Mang[Phai] > Mang[LonNhat]) LonNhat = Phai;
    if (LonNhat != i) {
        swap(Mang[i], Mang[LonNhat]);
        heapify(Mang, N, LonNhat);
    }
}

void heapSort(vector<int> &Mang) {
    for (int i = Mang.size() / 2 - 1; i >= 0; i--) heapify(Mang, Mang.size(), i);
    for (int i = Mang.size() - 1; i > 0; i--) {
        swap(Mang[0], Mang[i]);
        heapify(Mang, i, 0);
    }
}

void interchangeSort(vector<int> &Mang) {
    for (size_t i = 0; i < Mang.size() - 1; i++) {
        for (size_t j = i + 1; j < Mang.size(); j++) {
            if (Mang[i] < Mang[j]) swap(Mang[i], Mang[j]);
        }
    }
}

void printArray(const vector<int> &Mang) {
    for (int So : Mang) cout << So << " ";
    cout << endl;
}


