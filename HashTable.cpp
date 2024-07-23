#include <iostream>
#include <vector>

using namespace std;

class Node {
public:
    string key;
    int value;
    Node* next;

    Node(string key, int value) {
        this->key = key;
        this->value = value;
        next = nullptr;
    }
};

class HashTable {
private:
    static const int SIZE = 7;
    Node* dataMap[SIZE];

    int hash(string key) {
        int hash = 0;
        for (int i = 0; i < key.length(); i++) {
            int asciiValue = int(key[i]);
            hash = (hash + asciiValue * 23) % SIZE;
        }
        return hash;
    }

public:
    // Constructor to initialize dataMap array
    HashTable() {
        for (int i = 0; i < SIZE; i++) {
            dataMap[i] = nullptr;
        }
    }

    // Destructor to free allocated memory
    ~HashTable() {
        for (int i = 0; i < SIZE; i++) {
            Node* head = dataMap[i];
            Node* temp = head;
            while (head) {
                head = head->next;
                delete temp;
                temp = head;
            }
        }
    }

    // Insert key-value pair into the hash table
    void set(string key, int value) {
        int index = hash(key);
        Node* newNode = new Node(key, value);
        if (dataMap[index] == nullptr) {
            dataMap[index] = newNode;
        } else {
            Node* temp = dataMap[index];
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    // Retrieve value associated with key
    int get(string key) {
        int index = hash(key);
        Node* temp = dataMap[index];
        while (temp != nullptr) {
            if (temp->key == key) return temp->value;
            temp = temp->next;
        }
        return 0; // Return 0 if key not found (assuming all values are positive)
    }

    // Print the contents of the hash table
    void printTable() {
        for (int i = 0; i < SIZE; i++) {
            cout << i << ":" << endl;
            if (dataMap[i]) {
                Node* temp = dataMap[i];
                while (temp) {
                    cout << "   {" << temp->key << ", " << temp->value << "}" << endl;
                    temp = temp->next;
                }
            }
        }
    }

    // Return all keys in the hash table as a vector
    vector<string> keys() {
        vector<string> allKeys;
        for (int i = 0; i < SIZE; i++) {
            Node* temp = dataMap[i];
            while (temp != nullptr) {
                allKeys.push_back(temp->key);
                temp = temp->next;
            }
        }
        return allKeys;
    }
};

int main() {
    HashTable* myHashTable = new HashTable();

    // Adding key-value pairs
    myHashTable->set("paint", 20);
    myHashTable->set("bolts", 40);
    myHashTable->set("nails", 100);
    myHashTable->set("tile", 50);
    myHashTable->set("lumber", 80);

    // Printing the hash table
    cout << "Printing Hash Table:" << endl;
    myHashTable->printTable();

    // Getting values for specific keys
    cout << "\nGetting values for keys:" << endl;
    cout << "Lumber: " << myHashTable->get("lumber") << endl;
    cout << "Bolts: " << myHashTable->get("bolts") << endl;
    cout << "Paint: " << myHashTable->get("paint") << endl;
    cout << "Bricks: " << myHashTable->get("bricks") << endl; // Assuming "bricks" is not in the table

    // Printing all keys
    cout << "\nAll keys:" << endl;
    vector<string> keys = myHashTable->keys();
    for (auto key : keys) {
        cout << key << " ";
    }
    cout << endl;

    delete myHashTable; // Free allocated memory

    return 0;
}
/*#include <iostream>
#include <unordered_map>
#include <vector>


using namespace std;

bool itemInCommonV(vector<int> vect1, vector<int> vect2) {
    for (auto i : vect1) {
        for (auto j : vect2) {
            if (i == j) return true;
        }
    }
    return false;
}

bool itemInCommonH(vector<int> vect1, vector<int> vect2) {
    unordered_map<int, bool> myMap;

    for (auto i : vect1) {
        myMap.insert({i, true});
    }

    for (auto j : vect2) {
        if (myMap[j]) return true;
    }
    
    return false;
}


int main() {

    vector<int> vect1  {1, 3, 5};

    vector<int> vect2  {2, 4, 5};

    cout << itemInCommonV(vect1, vect2)<<endl;

    cout << itemInCommonH(vect1, vect2);


}*/