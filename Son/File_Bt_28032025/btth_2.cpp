#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>
using namespace std;

class QueueInt {
private:
    queue<int> q;
public:
    bool rong() { return q.empty(); }
    void them(int giaTri) { q.push(giaTri); }
    int layRa() {
        if (rong()) throw runtime_error("Hàng đợi rỗng");
        int giaTri = q.front(); q.pop();
        return giaTri;
    }
    int dau() {
        if (rong()) throw runtime_error("Hàng đợi rỗng");
        return q.front();
    }
    void xoa() { while (!rong()) q.pop(); }
};


class LinkedQueueInt {
private:
    struct Node {
        int data;
        Node* next;
        Node(int val) : data(val), next(nullptr) {}
    };
    Node *dau, *cuoi;
public:
    LinkedQueueInt() : dau(nullptr), cuoi(nullptr) {}
    bool rong() { return dau == nullptr; }
    void them(int giaTri) {
        Node* moi = new Node(giaTri);
        if (rong()) dau = cuoi = moi;
        else {
            cuoi->next = moi;
            cuoi = moi;
        }
    }
    int layRa() {
        if (rong()) throw runtime_error("Hàng đợi rỗng");
        int giaTri = dau->data;
        Node* tam = dau;
        dau = dau->next;
        if (!dau) cuoi = nullptr;
        delete tam;
        return giaTri;
    }
    int dauHang() {
        if (rong()) throw runtime_error("Hàng đợi rỗng");
        return dau->data;
    }
    void xoa() { while (!rong()) layRa(); }
};

void xepLichMua(queue<string> &nam, queue<string> &nu) {
    while (!nam.empty() && !nu.empty()) {
        cout << "Cặp: " << nam.front() << " - " << nu.front() << endl;
        nam.pop(); nu.pop();
    }
    if (!nam.empty()) cout << "Thiếu nữ!" << endl;
    if (!nu.empty()) cout << "Thiếu nam!" << endl;
}


int layChuSo(int num, int viTri) {
    return (num / viTri) % 10;
}

void radixSort(vector<int> &arr) {
    const int BASE = 10;
    queue<int> buckets[BASE];
    int maxVal = *max_element(arr.begin(), arr.end());
    for (int exp = 1; maxVal / exp > 0; exp *= BASE) {
        for (int num : arr) buckets[layChuSo(num, exp)].push(num);
        int idx = 0;
        for (int i = 0; i < BASE; i++) {
            while (!buckets[i].empty()) {
                arr[idx++] = buckets[i].front();
                buckets[i].pop();
            }
        }
    }
}

int main() {
    // Ứng dụng xếp lịch múa
    queue<string> nam, nu;
    nam.push("Minh"); nam.push("An"); nam.push("Hoàng");
    nu.push("Lan"); nu.push("Mai");
    cout << "Xếp lịch cặp múa:\n";
    xepLichMua(nam, nu);

    // Ứng dụng Radix Sort
    vector<int> arr = {170, 45, 75, 90, 802, 24, 2, 66};
    cout << "\nMảng trước khi sắp xếp: ";
    for (int num : arr) cout << num << " ";
    radixSort(arr);
    cout << "\nMảng sau khi sắp xếp: ";
    for (int num : arr) cout << num << " ";
    cout << endl;
    return 0;
}