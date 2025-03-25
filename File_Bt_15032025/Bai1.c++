#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};
// Định nghĩa lớp LinkedList
class LinkedList {
private:
    Node* head;

public:
    //khởi tạo danh sách rỗng
    LinkedList() {
        head = nullptr;
    }

    //thêm phần tử vào cuối danh sách
    void addElement(int value) {
        Node* newNode = new Node{value, nullptr};
        if (!head) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
    // xóa phần tử có giá trị cụ thể
    void deleteElement(int value) {
        if (!head) return;

        // Nếu phần tử cần xóa là phần tử đầu tiên
        if (head->data == value) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }
        // Xóa phần tử ở giữa hoặc cuối danh sách
        Node* temp = head;
        while (temp->next && temp->next->data != value) {
            temp = temp->next;
        }
        if (temp->next) {
            Node* nodeToDelete = temp->next;
            temp->next = temp->next->next;
            delete nodeToDelete;
        }
    }
    //in danh sách
    void printList() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    // gộp danh sách khác vào danh sách hiện tại
    void mergeList(LinkedList& otherList) {
        if (!head) {
            head = otherList.head;
            return;
        }

        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = otherList.head;
    }

    // giải phóng bộ nhớ
    ~LinkedList() {
        Node* temp;
        while (head) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    LinkedList list1, list2;
    int number;
    cout << "Nhập 10 số nguyên cho danh sách 1:\n";
    for (int i = 0; i < 10; i++) {
        cin >> number;
        list1.addElement(number);
    }
    cout << "Danh sách 1: ";
    list1.printList();

    cout << "Nhập số cần xóa: ";
    cin >> number;
    list1.deleteElement(number);

    cout << "Danh sách 1 sau khi xóa: ";
    list1.printList();

    cout << "Nhập 5 số nguyên cho danh sách 2:\n";
    for (int i = 0; i < 5; i++) {
        cin >> number;
        list2.addElement(number);
    }
    list1.mergeList(list2);
    cout << "Danh sách 1 sau khi gộp danh sách 2: ";
    list1.printList();

    return 0;
}
