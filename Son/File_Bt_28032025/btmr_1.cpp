#include <iostream>
#include <stack>
using namespace std;

// (a) Tính số Fibonacci
// Đệ quy
int fibonacciDeQuy(int n) {
    if (n <= 1) return n;
    return fibonacciDeQuy(n - 1) + fibonacciDeQuy(n - 2);
}

// Khử đệ quy dùng stack
int fibonacciKhongDeQuy(int n) {
    if (n <= 1) return n;
    stack<int> s;
    s.push(n);
    int a = 0, b = 1, fib = 0;
    for (int i = 2; i <= n; i++) {
        fib = a + b;
        a = b;
        b = fib;
    }
    return fib;
}

// (b) Đảo ngược số
// Đệ quy
int daoNguocDeQuy(int n, int rev = 0) {
    if (n == 0) return rev;
    return daoNguocDeQuy(n / 10, rev * 10 + n % 10);
}

// Khử đệ quy dùng stack
int daoNguocKhongDeQuy(int n) {
    stack<int> s;
    while (n > 0) {
        s.push(n % 10);
        n /= 10;
    }
    int rev = 0, place = 1;
    while (!s.empty()) {
        rev += s.top() * place;
        s.pop();
        place *= 10;
    }
    return rev;
}

// (c) Bài toán Tháp Hà Nội
// Đệ quy
void thapHaNoiDeQuy(int n, char from, char to, char aux) {
    if (n == 1) {
        cout << "Di chuyen dia tu " << from << " den " << to << endl;
        return;
    }
    thapHaNoiDeQuy(n - 1, from, aux, to);
    cout << "Di chuyen dia tu " << from << " den " << to << endl;
    thapHaNoiDeQuy(n - 1, aux, to, from);
}

// Khử đệ quy dùng stack
struct Move {
    int n;
    char from, to, aux;
};

void thapHaNoiKhongDeQuy(int n) {
    stack<Move> s;
    s.push({n, 'A', 'C', 'B'});
    while (!s.empty()) {
        Move m = s.top(); s.pop();
        if (m.n == 1) {
            cout << "Di chuyen dia tu " << m.from << " den " << m.to << endl;
        } else {
            s.push({m.n - 1, m.aux, m.to, m.from});
            s.push({1, m.from, m.to, m.aux});
            s.push({m.n - 1, m.from, m.aux, m.to});
        }
    }
}

int main() {
    int n = 5;
    cout << "Fibonacci(" << n << ") (De quy): " << fibonacciDeQuy(n) << endl;
    cout << "Fibonacci(" << n << ") (Khong de quy): " << fibonacciKhongDeQuy(n) << endl;
    
    int so = 12345;
    cout << "Dao nguoc " << so << " (De quy): " << daoNguocDeQuy(so) << endl;
    cout << "Dao nguoc " << so << " (Khong de quy): " << daoNguocKhongDeQuy(so) << endl;
    
    int dia = 3;
    cout << "\nThap Ha Noi (De quy):\n";
    thapHaNoiDeQuy(dia, 'A', 'C', 'B');
    cout << "\nThap Ha Noi (Khong de quy):\n";
    thapHaNoiKhongDeQuy(dia);
    
    return 0;
}