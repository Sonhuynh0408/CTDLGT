#include <iostream>
using namespace std;

int main()
{
    LinkedList list;
    list.insertOrder(5);
    list.insertOrder(2);
    list.insertOrder(8);
    list.insertOrder(1);
    list.showList(); // 1 -> 2 -> 5 -> 8 -> NULL

    list.insertFirst(0);
    list.showList(); // 0 -> 1 -> 2 -> 5 -> 8 -> NULL

    list.insertAfter(2, 3);
    list.showList(); // 0 -> 1 -> 2 -> 3 -> 5 -> 8 -> NULL

    list.remove(3);
    list.showList(); // 0 -> 1 -> 2 -> 5 -> 8 -> NULL

    list.deleteFirst();
    list.showList(); // 1 -> 2 -> 5 -> 8 -> NULL

    list.selectionSort();
    list.showList(); // 1 -> 2 -> 5 -> 8 -> NULL (đã sắp xếp)

    cout << "Phần tử tại vị trí 2: " << list.getElement(2) << endl; // 5

    list.clearList();
    list.showList(); // NULL

    return 0;
}

// Định nghĩa Node của danh sách liên kết đơn
struct Node
{
    int data;
    Node *next;

    Node(int value)
    {
        data = value;
        next = nullptr;
    }
};
// Định nghĩa lớp LinkedList
class LinkedList
{
private:
    Node *head;

public:
    // Khởi tạo danh sách rỗng
    LinkedList()
    {
        head = nullptr;
    }

    // Kiểm tra danh sách có rỗng không
    bool isEmpty()
    {
        return head == nullptr;
    }

    // Tìm kiếm một phần tử trong danh sách
    Node *find(int value)
    {
        Node *temp = head;
        while (temp)
        {
            if (temp->data == value)
                return temp;
            temp = temp->next;
        }
        return nullptr;
    }

    // Tìm kiếm phần tử theo vị trí
    Node *findOrder(int order)
    {
        Node *temp = head;
        int count = 0;
        while (temp)
        {
            if (count == order)
                return temp;
            temp = temp->next;
            count++;
        }
        return nullptr;
    }

    // Thêm phần tử vào đầu danh sách
    void insertFirst(int value)
    {
        Node *newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    // Thêm phần tử sau một phần tử có giá trị value
    void insertAfter(int value, int newValue)
    {
        Node *temp = find(value);
        if (!temp)
            return;

        Node *newNode = new Node(newValue);
        newNode->next = temp->next;
        temp->next = newNode;
    }

    // Thêm phần tử vào danh sách theo thứ tự tăng dần
    void insertOrder(int value)
    {
        Node *newNode = new Node(value);
        if (!head || head->data >= value)
        {
            newNode->next = head;
            head = newNode;
            return;
        }

        Node *temp = head;
        while (temp->next && temp->next->data < value)
        {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }

    // Xóa phần tử đầu danh sách
    void deleteFirst()
    {
        if (!head)
            return;
        Node *temp = head;
        head = head->next;
        delete temp;
    }

    // Xóa phần tử sau một phần tử có giá trị value
    void deleteAfter(int value)
    {
        Node *temp = find(value);
        if (!temp || !temp->next)
            return;

        Node *nodeToDelete = temp->next;
        temp->next = temp->next->next;
        delete nodeToDelete;
    }

    // Xóa phần tử có giá trị cụ thể
    void remove(int value)
    {
        if (!head)
            return;

        if (head->data == value)
        {
            deleteFirst();
            return;
        }
        Node *temp = head;
        while (temp->next && temp->next->data != value)
        {
            temp = temp->next;
        }
        if (!temp->next)
            return;

        Node *nodeToDelete = temp->next;
        temp->next = temp->next->next;
        delete nodeToDelete;
    }
    // Xóa phần tử tại vị trí thứ order
    void removeOrder(int order)
    {
        if (!head)
            return;
        if (order == 0)
        {
            deleteFirst();
            return;
        }
        Node *temp = head;
        for (int i = 0; temp && i < order - 1; i++)
        {
            temp = temp->next;
        }
        if (!temp || !temp->next)
            return;
        Node *nodeToDelete = temp->next;
        temp->next = temp->next->next;
        delete nodeToDelete;
    }
    // Duyệt danh sách và in ra
    void showList()
    {
        Node *temp = head;
        while (temp)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
    // Hủy bỏ danh sách
    void clearList()
    {
        Node *temp;
        while (head)
        {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
    // Sắp xếp danh sách tăng dần (Selection Sort)
    void selectionSort()
    {
        if (!head || !head->next)
            return;
        Node *temp = head;
        while (temp)
        {
            Node *minNode = temp;
            Node *nextNode = temp->next;
            while (nextNode)
            {
                if (nextNode->data < minNode->data)
                {
                    minNode = nextNode;
                }
                nextNode = nextNode->next;
            }
            swap(temp->data, minNode->data);
            temp = temp->next;
        }
    }
    // Lấy nội dung của một phần tử theo vị trí
    int getElement(int order)
    {
        Node *temp = findOrder(order);
        return temp ? temp->data : -1;
    }
    // Destructor để giải phóng bộ nhớ
    ~LinkedList()
    {
        clearList();
    }
};
