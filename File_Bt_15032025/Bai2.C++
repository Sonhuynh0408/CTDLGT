#include <iostream>
#include <cstring>
using namespace std;

struct SinhVien {
    char ten[50], diaChi[70], lop[10];
    int khoa;

    void nhap() {
        cin.ignore();
        cout << "Nhập tên: "; cin.getline(ten, 50);
        cout << "Nhập địa chỉ: "; cin.getline(diaChi, 70);
        cout << "Nhập lớp: "; cin.getline(lop, 10);
        cout << "Nhập khóa: "; cin >> khoa;
    }
    
    void xuat() {
        cout << ten << " | " << diaChi << " | " << lop << " | " << khoa << endl;
    }
};

// Hàm so sánh
bool soSanhTen(SinhVien a, SinhVien b) { return strcmp(a.ten, b.ten) < 0; }
bool soSanhDiaChi(SinhVien a, SinhVien b) { return strcmp(a.diaChi, b.diaChi) < 0; }

struct Nut {
    SinhVien data;
    Nut* next;
};

class DanhSach {
    Nut* head;

public:
    DanhSach() { head = nullptr; }

    void them(SinhVien sv) {
        Nut* moi = new Nut{sv, nullptr};
        if (!head) head = moi;
        else {
            Nut* temp = head;
            while (temp->next) temp = temp->next;
            temp->next = moi;
        }
    }

    void xuat() {
        for (Nut* temp = head; temp; temp = temp->next) temp->data.xuat();
    }

    void xoa(bool (*dieuKien)(SinhVien)) {
        while (head && dieuKien(head->data)) {
            Nut* temp = head;
            head = head->next;
            delete temp;
        }

        for (Nut* temp = head; temp && temp->next;) {
            if (dieuKien(temp->next->data)) {
                Nut* xoaNut = temp->next;
                temp->next = temp->next->next;
                delete xoaNut;
            } else temp = temp->next;
        }
    }

    void sapXep(bool (*soSanh)(SinhVien, SinhVien)) {
        for (Nut* i = head; i && i->next; i = i->next) {
            Nut* min = i;
            for (Nut* j = i->next; j; j = j->next) {
                if (soSanh(j->data, min->data)) min = j;
            }
            swap(i->data, min->data);
        }
    }

    ~DanhSach() {
        while (head) {
            Nut* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

// Điều kiện xóa
bool xoaTheoTen(SinhVien sv) { return strcmp(sv.ten, "Nguyen Van Teo") == 0; }
bool xoaTheoDiaChi(SinhVien sv) { return strcmp(sv.diaChi, "Nguyen Van Cu") == 0; }

int main() {
    DanhSach ds;
    SinhVien sv;

    cout << "Nhập 10 sinh viên:\n";
    for (int i = 0; i < 10; i++) {
        cout << "Sinh viên " << i + 1 << ":\n";
        sv.nhap();
        ds.them(sv);
    }

    cout << "\nDanh sách ban đầu:\n";
    ds.xuat();

    ds.xoa(xoaTheoTen);
    ds.xoa(xoaTheoDiaChi);

    SinhVien mo = {"Tran Thi Mo", "25 Hong Bang", "TT0901", 2009};
    ds.them(mo);

    cout << "\nDanh sách sau khi cập nhật:\n";
    ds.xuat();
    
    return 0;
}
