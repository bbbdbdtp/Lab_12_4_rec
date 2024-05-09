#include <iostream>

struct Node {
    int data;
    Node* next;
};

void createCircularList(Node*& head, Node*& tail, int values[], int size, int index = 0) {
    if (index == size) {
        if (head != nullptr) // якщо список не порожн≥й
            tail->next = head; // «робити останн≥й елемент посиланн€м на перший елемент
        return;
    }

    Node* newNode = new Node(); // —творенн€ нового вузла
    newNode->data = values[index]; // ѕрисвоЇнн€ значенн€ вузлу з масиву
    newNode->next = nullptr; // ≤н≥ц≥ал≥зац≥€ вказ≥вника на наступний вузол €к nullptr

    if (head == nullptr) { // якщо список порожн≥й
        head = newNode; // ¬становленн€ початкового та к≥нцевого вузла
        tail = newNode;
    }
    else {
        tail->next = newNode; // ƒодаванн€ нового вузла п≥сл€ к≥нцевого вузла
        tail = newNode; // ќновленн€ к≥нцевого вузла
    }

    createCircularList(head, tail, values, size, index + 1); // –екурсивний виклик дл€ наступного елемента
}

int countPositiveElements(Node* current, Node* head) {
    if (current->next == head) // якщо дос€гли к≥нц€ списку
        return (current->data > 0) ? 1 : 0; // Ћ≥чильник додатних елемент≥в

    int count = (current->data > 0) ? 1 : 0; // Ћ≥чильник додатних елемент≥в
    return count + countPositiveElements(current->next, head); // –екурсивний виклик дл€ наступного елемента
}

void displayCircularList(Node* current, Node* head) {
    if (current->next == head) { // якщо дос€гли к≥нц€ списку
        std::cout << current->data << " ";
        return;
    }

    std::cout << current->data << " ";
    displayCircularList(current->next, head); // –екурсивний виклик дл€ наступного елемента
}

int main() {
    Node* head = nullptr;
    Node* tail = nullptr;
    int values[] = { 1, -2, 3, -4, 5, };
    int size = sizeof(values) / sizeof(values[0]);

    createCircularList(head, tail, values, size);
    std::cout << "Original List: ";
    displayCircularList(head, head); // ѕередача початку списку в €кост≥ початку дл€ виведенн€
    std::cout << std::endl;

    int count = countPositiveElements(head, head); // ѕередача початку списку в €кост≥ початку дл€ п≥драхунку
    std::cout << "Number of positive elements: " << count << std::endl;

    return 0;
}