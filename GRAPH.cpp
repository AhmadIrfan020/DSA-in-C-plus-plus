#include <iostream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Graph {
    private:
        unordered_map<string, unordered_set<string>> adjList;
    
    public:
        void printGraph() {
            for (const auto& kvPair : adjList) {
                cout << kvPair.first << ": [ ";
                for (const auto& edge : kvPair.second) {
                    cout << edge << " ";
                }
                cout << "]" << endl;
            }
        }

        bool addVertex(string vertex) {
            if (adjList.count(vertex) == 0) {
                adjList[vertex];
                return true;
            }
            return false;
        }

        bool addEdge(string vertex1, string vertex2) {
            if (adjList.count(vertex1) != 0 && adjList.count(vertex2) != 0) {
                adjList[vertex1].insert(vertex2);
                adjList[vertex2].insert(vertex1);
                return true;
            }         
            return false;          
        }

        bool removeEdge(string vertex1, string vertex2) {
            if (adjList.count(vertex1) != 0 && adjList.count(vertex2) != 0) {
                adjList[vertex1].erase(vertex2);
                adjList[vertex2].erase(vertex1);
                return true;
            }
            return false;
        }

        bool removeVertex(string vertex) { 
            if (adjList.count(vertex) == 0) return false;  
            for (const auto& otherVertex : adjList[vertex]) {
                adjList[otherVertex].erase(vertex);   
            }
            adjList.erase(vertex);
            return true;
        }
};

int main() {
    Graph* myGraph = new Graph();

    myGraph->addVertex("A");
    myGraph->addVertex("B");
    myGraph->addVertex("C");
    myGraph->addVertex("D");

    myGraph->addEdge("A", "B");
    myGraph->addEdge("A", "C");
    myGraph->addEdge("A", "D");
    myGraph->addEdge("B", "D");
    myGraph->addEdge("C", "D");

    cout << "Graph after addVertex and addEdge and before removeVertex(): \n";
    myGraph->printGraph();

    myGraph->removeVertex("D");

    cout << "\n\nGraph after removeVertex(): \n";
    myGraph->printGraph();

    myGraph->addEdge("A", "B");
    myGraph->addEdge("A", "C");
    myGraph->addEdge("B", "C");

    cout << "\n\nGraph before removeEdge(): \n";
    myGraph->printGraph();

    myGraph->removeEdge("A", "B");

    cout << "\n\nGraph after removeEdge(): \n";
    myGraph->printGraph();

    cout << "\n\nGraph before addEdge(): \n";
    myGraph->printGraph();

    myGraph->addEdge("A", "B");

    cout << "\n\nGraph after addEdge(): \n";
    myGraph->printGraph();

    myGraph->addVertex("E");
    myGraph->addVertex("F");

    cout << "\n\nGraph:\n";
    myGraph->printGraph();

    delete myGraph;

    /*
        EXPECTED OUTPUT:
        ----------------
Graph after addVertex and addEdge and before removeVertex(): 
        A: [ B C D ]
        B: [ A D ]
        C: [ A D ]
        D: [ A B C ]

        Graph after removeVertex(): 
        A: [ B C ]
        B: [ A ]
        C: [ A ]

        Graph before removeEdge(): 
        A: [ B C ]
        B: [ A C ]
        C: [ A B ]

        Graph after removeEdge(): 
        A: [ C ]
        B: [ C ]
        C: [ A B ]

        Graph before addEdge(): 
        A: [ C ]
        B: [ C ]
        C: [ A B ]

        Graph after addEdge(): 
        A: [ B C ]
        B: [ A C ]
        C: [ A B ]

        Graph:
        A: [ B C ]
        B: [ A C ]
        C: [ A B ]
        E: [ ]
        F: [ ]
    */ 
}
/*                        SETS
#include <iostream>
#include <unordered_set>
 
using namespace std;
 
int main() {
    // Create a set
    unordered_set<int> mySet = {1, 2, 3, 4, 5};
 
    // Add elements to the set
    mySet.insert(6);
    mySet.insert(7);
 
    // Remove an element from the set
    mySet.erase(2);
 
    // Checking if an element is in a set
    if (mySet.find(10) != mySet.end()) {
        cout << "Found 10 in mySet" << endl;
    }
 
    // Check size of the set
    cout << "Size of mySet: " << mySet.size() << endl;
 
    // Check if a set is empty
    if (mySet.empty()) {
        cout << "Set is empty!" << endl;
    } else {
        cout << "Set is not empty!" << endl;
    }
 
    // Clearing all elements from a set
    mySet.clear();
    cout << "After clearing, size: " << mySet.size() << endl;
}*/