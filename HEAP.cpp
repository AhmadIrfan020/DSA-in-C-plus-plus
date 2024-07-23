#include <iostream>
#include <vector>
#include <climits>
using namespace std;
// Max heap code
class heap
{
private:
    vector<int> heap;

    int leftchild(int index)
    {
        return 2 * index + 1;
    }

    int rightchild(int index)
    {
        return 2 * index + 2;
    }

    int parent(int index)
    {
        return (index - 1) / 2;
    }

    void swap(int index1, int index2)
    {
        int temp = heap[index1];
        heap[index1] = heap[index2];
        heap[index2] = temp;
    }

public:
    void printheap()
    {
        cout << "\n[";
        for (size_t i = 0; i < heap.size(); i++)
        {
            cout << heap[i];
            if (i < heap.size() - 1)
            {
                cout << ", ";
            }
        }
        cout << "]" << endl;
    }
    const vector<int>& getHeap() const {
            return heap;
        }

    void sinkDown(int index)
    {
        int maxIndex = index;
        while (true)
        {
            int leftIndex = leftchild(index);
            int rightIndex = rightchild(index);

            if (leftIndex < heap.size() && heap[leftIndex] > heap[maxIndex])
            {
                maxIndex = leftIndex;
            }
            if (rightIndex < heap.size() && heap[rightIndex] > heap[maxIndex])
            {
                maxIndex = rightIndex;
            }
            if (maxIndex != index)
            {
                swap(index, maxIndex);
                index = maxIndex;
            }
            else
                return;
        }
    }

    void insert(int value)
    {
        heap.push_back(value);
        int current = heap.size() - 1;

        while (current > 0 && heap[current] > heap[parent(current)])
        {
            swap(current, parent(current));
            current = parent(current);
        }
    }

    int remove()
    {
        if (heap.empty())
        {
            return INT_MIN;
        }
        int maxvalue = heap.front();
        if (heap.size() == 1)
        {
            heap.pop_back();
        }
        else
        {
            heap[0] = heap.back();
            heap.pop_back();
            sinkDown(0);
        }
        return maxvalue;
    }
};

int main()
{
    heap *myheap = new heap();
    
    cout<<"Inserting values in heap: \n";
    myheap->insert(99);
    myheap->insert(72);
    myheap->insert(61);
    myheap->insert(58);
    myheap->printheap();

    myheap->insert(100);
    myheap->printheap();
    myheap->insert(75);
    myheap->printheap();
    cout << "\ndeleting values in heap1: \n";
    heap *myheap1 = new heap();
    myheap1->insert(95);
    myheap1->insert(75);
    myheap1->insert(80);
    myheap1->insert(55);
    myheap1->insert(60);
    myheap1->insert(50);
    myheap1->insert(65);
    myheap1->printheap();

    myheap1->remove();
    myheap1->printheap();

    myheap1->remove();
    myheap1->printheap();
    cout << "\n \n";
}
/*
// Min heap code
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class MinHeap {
    private:
        vector<int> heap;
    
        int leftChild(int index) {
            return 2 * index + 1;
        }
    
        int rightChild(int index) {
            return 2 * index + 2;
        }
    
        int parent(int index) {
            return (index - 1) / 2;
        }
    
        void swap(int index1, int index2) {
            int temp = heap[index1];
            heap[index1] = heap[index2];
            heap[index2] = temp;
        }
    
    public:
        void printHeap() {
            cout << "\n[";
            for (size_t i = 0; i < heap.size(); i++) {
                cout << heap[i];
                if (i < heap.size() - 1) { 
                    cout << ", ";
                }
            }
            cout << "]" << endl;
        }
        
        const vector<int>& getHeap() const {
            return heap;
        }
    
       void insert(int value)
    {
        heap.push_back(value);
        int current = heap.size() - 1;

        while (current > 0 && heap[current] <= heap[parent(current)])
        {
            swap(current, parent(current));
            current = parent(current);
        }
    }

        void sinkDown(int index) {
            int minIndex = index;
            while (true) {
                int leftIndex = leftChild(index);
                int rightIndex = rightChild(index);
    
                if (leftIndex < heap.size() && heap[leftIndex] < heap[minIndex]) {
                    minIndex = leftIndex;
                }
    
                if (rightIndex < heap.size() && heap[rightIndex] < heap[minIndex]) {
                    minIndex = rightIndex;
                }
    
                if (minIndex != index) {
                    swap(index, minIndex);
                    index = minIndex;
                } else {
                    return;
                }
            }
        }
    int remove(){
        if(heap.empty()){
            return INT_MIN;
        }
        int minvalue = heap.front();
        if (heap.size() == 1)
        {
            heap.pop_back();
        }
        else
        {
            heap[0] = heap.back();
            heap.pop_back();
            sinkDown(0);
        }
        return minvalue;
    }
    

};
int main(){
    MinHeap* myheap=new MinHeap;
    myheap->insert(99);
    myheap->insert(72);
    myheap->insert(61);
    myheap->insert(58);
    myheap->printHeap();

    myheap->insert(100);
    myheap->printHeap();
    myheap->insert(75);
    myheap->printHeap();
    
    cout << "\ndeleting values in heap1: \n";
    MinHeap *myheap1 = new MinHeap();
    myheap1->insert(95);
    myheap1->insert(75);
    myheap1->insert(80);
    myheap1->insert(55);
    myheap1->insert(60);
    myheap1->insert(50);
    myheap1->insert(65);
    myheap1->printHeap();

    myheap1->remove();
    myheap1->printHeap();

    myheap1->remove();
    myheap1->printHeap();
    return 0;
}
*/