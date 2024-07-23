#include <iostream>

using namespace std;

class Node { 
    public:
        int value;
        Node* next;

        Node(int value) {
            this->value = value;
            next = nullptr;
        }
}; 

class LinkedList {
    private:
        Node* head;
        Node* tail;
        int length;

    public:
        LinkedList(int value) {
            Node* newNode = new Node(value);
            head = newNode;
            tail = newNode;
            length = 1;
        }

        ~LinkedList() {
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
            } else {
                cout << "Head: " << head->value << endl;
            }
        }

        void getTail() {
            if (tail == nullptr) {
                cout << "Tail: nullptr" << endl;
            } else { 
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
            } else {
                tail->next = newNode;
                tail = newNode;
            }
            length++;
        }

        void deleteLast() {
            if (length == 0) return;
            Node* temp = head;
            if (length == 1) {
                head = nullptr;
                tail = nullptr;
            } else {
                Node* pre = head;
                while(temp->next) {
                    pre = temp;
                    temp = temp->next;
                }
                tail = pre;
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
            } else {
                newNode->next = head;
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
            } else {
                head = head->next;
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
    LinkedList* myLinkedList = new LinkedList(1);
    myLinkedList->append(2);
    myLinkedList->append(3);
    myLinkedList->append(4);
    myLinkedList->append(5);

    cout << "Initial Linked List:\n";
    myLinkedList->printList();
    myLinkedList->getHead();
    myLinkedList->getTail();
    myLinkedList->getLength();

    cout << "\nAfter Prepending 0:\n";
    myLinkedList->prepend(0);
    myLinkedList->printList();

    cout << "\nAfter Setting index 1 to 10:\n";
    myLinkedList->set(1, 10);
    myLinkedList->printList();

    cout << "\nAfter Inserting 15 at index 3:\n";
    myLinkedList->insert(3, 15);
    myLinkedList->printList();

    cout << "\nAfter Removing index 4:\n";
    myLinkedList->remove(4);
    myLinkedList->printList();

    cout << "\nAfter Reversing the list:\n";
    myLinkedList->reverse();
    myLinkedList->printList();

    delete myLinkedList;

    return 0;
}
/*

### Explanation of New Functions:

1. **`insert(int index, int value)`**:
    - Inserts a new node with the given value at the specified index.
    - Handles cases where the new node should be prepended or appended.

2. **`remove(int index)`**:
    - Removes the node at the specified index.
    - Handles cases where the node to be removed is the first or last node.

3. **`reverse()`**:
    - Reverses the order of nodes in the linked list.

### Usage:
- The main function demonstrates the usage of all member functions.
- It creates a linked list, appends nodes, prepends a node, sets values
 at specific indices, inserts a node at a specified index, removes a node, and reverses the list.
- The linked list is printed after each operation to show the changes.

This code provides a more advanced implementation of a linked list in C++,
 including several useful member functions.*/