#include <iostream>

using namespace std;

class Node {
public:
    int value;
    Node* next;
    Node* prev;

    Node(int value) {
        this->value = value;
        next = nullptr;
        prev = nullptr;
    }
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;
    int length;

public:
    DoublyLinkedList(int value) {
        Node* newNode = new Node(value);
        head = newNode;
        tail = newNode;
        length = 1;
    }
    
    ~DoublyLinkedList() {
        Node* temp = head;
        while (head) {
            head = head->next;
            delete temp;
            temp = head;
        }
    }

    void printList() {
        Node* temp = head;

        while (temp != nullptr) {
            cout << temp->value << endl;
            temp = temp->next;
        }
    }

    void getHead() {
        if (head == nullptr) {
            cout << "Head: nullptr" << endl;
        }
        else {
            cout << "Head: " << head->value << endl;
        }
    }

    void getTail() {
        if (tail == nullptr) {
            cout << "Tail: nullptr" << endl;
        }
        else {
            cout << "Tail: " << tail->value << endl;
        }
    }

    void getLength() {
        cout << "Length: " << length << endl;
    }


    void append(int value) {
        Node* newNode = new Node(value);
        if (length == 0) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        length++;
    }


    void deleteLast() {
        if (length == 0) return;
        Node* temp = tail;
        if (length == 1) {
            head = nullptr;
            tail = nullptr;
        }
        else {
            tail = tail->prev;
            tail->next = nullptr;
        }
        delete temp;
        length--;
    }


    void prepend(int value) {
        Node* newNode = new Node(value);
        if (length == 0) {
            head = newNode;
            tail = newNode;
        }
        else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        length++;
    }
    void deleteFirst() {
        if (length == 0) return;
        Node* temp = head;
        if (length == 1) {
            head = nullptr;
            tail = nullptr;
        }
        else {
            head = head->next;
            head->prev = nullptr;
        }
        delete temp;
        length--;
    }


    Node* get(int index) {
        if (index < 0 || index >= length) return nullptr;
        Node* temp = head;
        for (int i = 0; i < index; ++i) {
            temp = temp->next;
        }
        return temp;
    }

    bool set(int index, int value) {
        Node* temp = get(index);
        if (temp) {
            temp->value = value;
            return true;
        }
        return false;
    }

    bool insert(int index, int value) {
        if (index < 0 || index > length) return false;
        if (index == 0) {
            prepend(value);
            return true;
        }
        if (index == length) {
            append(value);
            return true;
        }
        Node* newNode = new Node(value);
        Node* temp = get(index - 1);
        newNode->next = temp->next;
        temp->next = newNode;
        length++;
        return true;
    }

    void remove(int index) {
        if (index < 0 || index >= length) return;
        if (index == 0) {
            deleteFirst();
            return;
        }
        if (index == length - 1) {
            deleteLast();
            return;
        }
        Node* prev = get(index - 1);
        Node* temp = prev->next;
        prev->next = temp->next;
        delete temp;
        length--;
    }

    void reverse() {
        Node* temp = head;
        head = tail;
        tail = temp;
        Node* prev = nullptr;
        Node* next = nullptr;
        for (int i = 0; i < length; i++) {
            next = temp->next;
            temp->next = prev;
            prev = temp;
            temp = next;
        }
    }
};

int main() {
    DoublyLinkedList* myDLL = new DoublyLinkedList(1);
    myDLL->append(2);
    myDLL->append(3);
    myDLL->append(4);
    myDLL->append(5);
    myDLL->append(6);
    myDLL->append(7);
    cout << "DoublyLinkedList" << endl;
    myDLL->printList();

    myDLL->deleteLast();
    cout << "DELETE last (1st time)"<<endl;
    myDLL->printList();

    myDLL->deleteLast();
    cout << "DELETE last (2nd)" << endl;
    myDLL->printList();
    myDLL->deleteLast();
    cout << "DELETE last (3rd)" << endl;
    myDLL->printList();


    cout << "Initial Linked List:\n";
    myDLL->printList();
    myDLL->getHead();
    myDLL->getTail();
    myDLL->getLength();
    
    cout << "\nAfter Prepending 0:\n";
    myDLL->prepend(0);
    myDLL->printList();

    cout << "\nAfter Setting index 1 to 10:\n";
    myDLL->set(1, 10);
    myDLL->printList();

    cout << "\nAfter Inserting 15 at index 3:\n";
    myDLL->insert(3, 15);
    myDLL->printList();

    cout << "\nAfter Removing index 4:\n";
    myDLL->remove(4);
    myDLL->printList();

    cout << "\nAfter Reversing the list:\n";
    myDLL->reverse();
    myDLL->printList();

    delete myDLL;
    return 0;
}