#include <iostream>
#include <stack>
#include <string>
#include <cctype>
using namespace std;

class NganXepSoNguyen {
private:
    stack<int> s;
public:
    bool rong() { return s.empty(); }
    void them(int giaTri) { s.push(giaTri); }
    int layRa() {
        if (rong()) throw runtime_error("Ngan xep rong");
        int giaTri = s.top(); s.pop();
        return giaTri;
    }
    int dinh() {
        if (rong()) throw runtime_error("Ngan xep rong");
        return s.top();
    }
    void xoa() { while (!rong()) s.pop(); }
};

int daoSo(int n) {
    NganXepSoNguyen nganXep;
    while (n > 0) {
        nganXep.them(n % 10);
        n /= 10;
    }
    int soDao = 0, heSo = 1;
    while (!nganXep.rong()) {
        soDao += nganXep.layRa() * heSo;
        heSo *= 10;
    }
    return soDao;
}

bool laXauDoiXung(const string &s) {
    NganXepSoNguyen nganXep;
    for (char kyTu : s) nganXep.them(kyTu);
    string xauDao;
    for (char kyTu : s) xauDao += nganXep.layRa();
    return s == xauDao;
}

string doiSangNhiPhan(int n) {
    if (n == 0) return "0";
    NganXepSoNguyen nganXep;
    while (n > 0) {
        nganXep.them(n % 2);
        n /= 2;
    }
    string nhiPhan;
    while (!nganXep.rong()) nhiPhan += to_string(nganXep.layRa());
    return nhiPhan;
}

int doUuTien(char toanTu) {
    if (toanTu == '+' || toanTu == '-') return 1;
    if (toanTu == '*' || toanTu == '/') return 2;
    return 0;
}

string trungToSangHauTo(const string &bieuThuc) {
    NganXepSoNguyen nganXep;
    string hauTo;
    for (char kyTu : bieuThuc) {
        if (isdigit(kyTu)) hauTo += kyTu;
        else if (kyTu == '(') nganXep.them(kyTu);
        else if (kyTu == ')') {
            while (!nganXep.rong() && nganXep.dinh() != '(')
                hauTo += nganXep.layRa();
            nganXep.layRa();
        } else {
            while (!nganXep.rong() && doUuTien(nganXep.dinh()) >= doUuTien(kyTu))
                hauTo += nganXep.layRa();
            nganXep.them(kyTu);
        }
    }
    while (!nganXep.rong()) hauTo += nganXep.layRa();
    return hauTo;
}

int tinhGiaTriHauTo(const string &bieuThuc) {
    NganXepSoNguyen nganXep;
    for (char kyTu : bieuThuc) {
        if (isdigit(kyTu)) nganXep.them(kyTu - '0');
        else {
            int b = nganXep.layRa(), a = nganXep.layRa();
            switch (kyTu) {
                case '+': nganXep.them(a + b); break;
                case '-': nganXep.them(a - b); break;
                case '*': nganXep.them(a * b); break;
                case '/': nganXep.them(a / b); break;
            }
        }
    }
    return nganXep.layRa();
}

int main() {
    cout << "Dao so 1234: " << daoSo(1234) << endl;
    cout << "Kiem tra xau doi xung 'madam': " << laXauDoiXung("madam") << endl;
    cout << "Doi so thap phan sang nhi phan (10): " << doiSangNhiPhan(10) << endl;
    string trungTo = "3+5*2";
    string hauTo = trungToSangHauTo(trungTo);
    cout << "Trung to sang hau to: " << hauTo << endl;
    cout << "Tinh gia tri bieu thuc hau to: " << tinhGiaTriHauTo(hauTo) << endl;
    return 0;
}
