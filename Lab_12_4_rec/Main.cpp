#include <iostream>

struct Node {
    int data;
    Node* next;
};

void createCircularList(Node*& head, Node*& tail, int values[], int size, int index = 0) {
    if (index == size) {
        if (head != nullptr) // ���� ������ �� �������
            tail->next = head; // ������� ������� ������� ���������� �� ������ �������
        return;
    }

    Node* newNode = new Node(); // ��������� ������ �����
    newNode->data = values[index]; // ��������� �������� ����� � ������
    newNode->next = nullptr; // ����������� ��������� �� ��������� ����� �� nullptr

    if (head == nullptr) { // ���� ������ �������
        head = newNode; // ������������ ����������� �� �������� �����
        tail = newNode;
    }
    else {
        tail->next = newNode; // ��������� ������ ����� ���� �������� �����
        tail = newNode; // ��������� �������� �����
    }

    createCircularList(head, tail, values, size, index + 1); // ����������� ������ ��� ���������� ��������
}

int countPositiveElements(Node* current, Node* head) {
    if (current->next == head) // ���� ������� ���� ������
        return (current->data > 0) ? 1 : 0; // ˳������� �������� ��������

    int count = (current->data > 0) ? 1 : 0; // ˳������� �������� ��������
    return count + countPositiveElements(current->next, head); // ����������� ������ ��� ���������� ��������
}

void displayCircularList(Node* current, Node* head) {
    if (current->next == head) { // ���� ������� ���� ������
        std::cout << current->data << " ";
        return;
    }

    std::cout << current->data << " ";
    displayCircularList(current->next, head); // ����������� ������ ��� ���������� ��������
}

int main() {
    Node* head = nullptr;
    Node* tail = nullptr;
    int values[] = { 1, -2, 3, -4, 5, };
    int size = sizeof(values) / sizeof(values[0]);

    createCircularList(head, tail, values, size);
    std::cout << "Original List: ";
    displayCircularList(head, head); // �������� ������� ������ � ����� ������� ��� ���������
    std::cout << std::endl;

    int count = countPositiveElements(head, head); // �������� ������� ������ � ����� ������� ��� ���������
    std::cout << "Number of positive elements: " << count << std::endl;

    return 0;
}