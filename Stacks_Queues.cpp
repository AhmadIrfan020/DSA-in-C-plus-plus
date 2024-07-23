#include <iostream>
//  Stack
using namespace std; /*
 class Node
 {
 public:
     int value;
     Node *next;

     Node(int value)
     {
         this->value = value;
         next = nullptr;
     }
 };

 class Stack
 {
 private:
     Node *top;
     int height;

 public:
     Stack(int value)
     {
         Node *newNode = new Node(value);
         top = newNode;
         height = 1;
     }

     ~Stack()
     {
         Node *temp = top;
         while (top)
         {
             top = top->next;
             delete temp;
             temp = top;
         }
     }

     void printStack()
     {
         Node *temp = top;
         while (temp)
         {
             cout << temp->value << endl;
             temp = temp->next;
         }
     }

     void getTop()
     {
         if (top == nullptr)
         {
             cout << "Top: nullptr" << endl;
         }
         else
         {
             cout << "Top: " << top->value << endl;
         }
     }

     void getHeight()
     {
         cout << "Height: " << height << endl;
     }

     void push(int value)
     {
         Node *newNode = new Node(value);
         newNode->next = top;
         top = newNode;
         height++;
     }
     int pop()
     {
         if (height == 0)
             return INT_MIN;
         Node *temp = top;
         int poppedvalue = top->value;
         top = top->next;
         delete temp;
         height--;
         return poppedvalue;
     }
 };*/
                     /* int main()
                     {
                     
                         Stack *myStack = new Stack(4);
                     
                         myStack->getTop();
                         myStack->getHeight();
                     
                         cout << "\nStack:\n";
                         myStack->printStack();
                         cout << "_________________________\n";
                         Stack *myStack1 = new Stack(2);
                     
                         cout << "Stack before push(1):\n";
                         cout << "---------------------\n";
                         myStack1->printStack();
                         cout << endl;
                     
                         myStack1->getTop();
                         myStack1->getHeight();
                     
                         myStack1->push(1);
                     
                         cout << "\n\nStack after push(1):\n";
                         cout << "--------------------\n";
                         myStack1->printStack();
                         cout << endl;
                     
                         myStack1->getTop();
                         myStack1->getHeight();
                     */
/*
    EXPECTED OUTPUT:
    ----------------
    Top: 4
    Height: 1

    Stack:
    4

*/
/*
    EXPECTED OUTPUT:

    Stack before push(1):
    --------------------
    2

    Top: 2
    Height: 1


    LL after prepend(1):
    --------------------
    1
    2

    Top: 1
    Height: 2

*/
/*
    cout << "_________________________\n";
    Stack *myStack2 = new Stack(1);

    cout << "Popped value: " << myStack2->pop();

    cout << "\n\nPopped value: " << myStack2->pop();

    /*
        EXPECTED OUTPUT:
        ----------------
        Popped value: 1

        Popped value: -2147483648

    *//*
cout << "\n_________________________\n";
return 0;
}
*/
// QUEUES
#include <iostream>

using namespace std;


class Node
{
public:
    int value;
    Node *next;

    Node(int value)
    {
        this->value = value;
        next = nullptr;
    }
};


class Queue {
private:
    Node *first;
    Node *last;
    int length;

public:
        Queue(int value)
    {
        Node *newNode = new Node(value);
        first = newNode;
        last = newNode;
        length = 1;
    }

        ~Queue() {
            Node* temp = first;
            while (first) {
                first = first->next;
                delete temp;
                temp = first;
            }
        }

        void printQueue() {
            Node* temp = first;
            while (temp) {
                cout << temp->value << endl;
                temp = temp->next;
            }
        }

        void getFirst() {
            if (first == nullptr) {
                cout << "First: nullptr" << endl;
            } else {
                cout << "First: " << first->value << endl;
            }
        }

        void getLast() {
            if (last == nullptr) {
                cout << "Last: nullptr" << endl;
            } else { 
                cout << "Last: " << last->value << endl;
            }  
        }

        void getLength() {
            cout << "Length: " << length << endl;
        }
        
        bool isEmpty() {
            if (length == 0) return true;
            return false;
        }
        void enqueue(int value){
        Node* newNode=new Node(value);
        if(length==0){
            first=newNode;
            last=newNode;
        }else{
            last->next=newNode;
            last=newNode;
        }
        length++;
       }

         int dequeue()
     {
         if (length == 0)
             return INT_MIN;
         Node *temp = first;
         int dequeuedvalue = first->value;
         if(length==1){
            first=nullptr;
            last=nullptr;
         }else{
            first=first->next;
         }
         delete temp;
         length--;
         return dequeuedvalue;
     }

};



int main() {
        
    Queue* myQueue = new Queue(7);

    myQueue->getFirst();
    myQueue->getLast();
    myQueue->getLength();

    cout << "\nQueue:\n";
    myQueue->printQueue();
    cout << "\n_________________________\n";

    /*  
        EXPECTED OUTPUT:
        ----------------
        First: 7
        Last: 7
        Length: 1

        Queue:
        7

    */    
Queue* myQueue2 = new Queue(1);

    cout << "Queue before enqueue(2):\n";
    cout << "------------------------\n";
    myQueue2->printQueue();
    cout << endl;

    myQueue2->getFirst();
    myQueue2->getLast();
    myQueue2->getLength();

    myQueue2->enqueue(2);

    cout << "\n\nQueue after enqueue(2):\n";
    cout << "-----------------------\n";
    myQueue2->printQueue();
    cout << endl;

    myQueue2->getFirst();
    myQueue2->getLast();
    myQueue2->getLength();
    cout << "\n_________________________\n";

    /*  
        EXPECTED OUTPUT:

        Queue before enqueue(2):
        ------------------------
        1

        First: 1
        Last: 1
        Length: 1


        Queue after enqueue(2):
        -----------------------
        1
        2

        First: 1
        Last: 2
        Length: 2

    */ 
   Queue* myQueue3 = new Queue(2);
    myQueue3->enqueue(1);

    cout << "Dequeued value: " << myQueue3->dequeue();
    
    cout << "\n\nDequeued value: " << myQueue3->dequeue();

    cout << "\n\nDequeued value: " << myQueue3->dequeue();


    /*  
        EXPECTED OUTPUT:
        ----------------
        Dequeued value: 2

        Dequeued value: 1

        Dequeued value: -2147483648

    */ 
    cout << "\n_________________________\n";
    cout << "\n_________________________\n";
}

