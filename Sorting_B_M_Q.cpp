//  ---------------------->>>   BASIC SORTS
#include <iostream>
using namespace std; /*
 //  ---------------------->>>   bubbleSort
 void bubbleSort(int array[], int size)
 {
     for (int i = size - 1; i > 0; i--)
     {
         for (int j = 0; j < i; j++)
         {
             if (array[j] > array[j + 1])
             {
                 int temp = array[j];
                 array[j] = array[j + 1];
                 array[j + 1] = temp;
             }
         }
     }
 }
 //  ---------------------->>>   Insertion sort
 void insertionSort(int array[], int size)
 {
     for (int i = 1; i < size; i++)
     {
         int temp = array[i];
         int j = i - 1;
         while (j > -1 && temp < array[j])
         {
             array[j + 1] = array[j];
             array[j] = temp;
             j--;
         }
     }
 }
 //  ---------------------->>>   selection sort
 void selectionSort(int array[],int size){
         for(int i=0;i<size;++i){
             int minIndex=i;
             for(int j=i+1;j<size;++j){
                 if(array[j]<array[minIndex]){
                 minIndex=j;
                 }
             }
             if(i!=minIndex){
             int temp=array[i];
             array[i]=array[minIndex];
             array[minIndex]=temp;}
         }
     }
 int main()
 {
     int myArray[] = {6, 4, 2, 5, 1, 3};
      cout<<"\nOriginal array:\n";
     for (auto value : myArray)
     {
         cout << value << " ";
     }

     int size = sizeof(myArray) / sizeof(myArray[0]);
     bubbleSort(myArray, size);
     cout<<"\nbubbleSort\n";
     for (auto value : myArray)
     {
         cout << value << " ";
     }



     insertionSort(myArray, size);
     cout<<"\nInsertion Sort\n";
     for (auto value : myArray)
     {
         cout << value << " ";
     }


     selectionSort(myArray, size);

     cout<<"\nselection Sort\n";
     for (auto value : myArray) {
         cout << value << " ";
     }
     cout<<endl;
 }*/
//-----------------------------------------------------------
//  ---------------------->>>   MERGE SORTS
//  ---------------------->>>    merge helping function
/*
void merge(int array[], int leftIndex, int midIndex, int rightIndex)
{
    int leftArraySize = midIndex - leftIndex + 1;
    int rightArraySize = rightIndex - midIndex;

    int leftArray[leftArraySize];
    int rightArray[rightArraySize];

    for (int i = 0; i < leftArraySize; i++)
        leftArray[i] = array[leftIndex + i];
    for (int j = 0; j < rightArraySize; j++)
        rightArray[j] = array[midIndex + 1 + j];

    int i = 0;
    int j = 0;
    int index = leftIndex;

    while (i < leftArraySize && j < rightArraySize)
    {
        if (leftArray[i] <= rightArray[j])
        {
            array[index] = leftArray[i];
            index++;
            i++;
        }
        else
        {
            array[index] = rightArray[j];
            index++;
            j++;
        }
    }

    while (i < leftArraySize)
    {
        array[index] = leftArray[i];
        index++;
        i++;
    }

    while (j < rightArraySize)
    {
        array[index] = rightArray[j];
        index++;
        j++;
    }
}

//  ---------------------->>>   merge sort
void mergeSort(int array[], int leftIndex, int rightIndex)
{
    if (leftIndex >= rightIndex)
        return;

    int midIndex = leftIndex + (rightIndex - leftIndex) / 2;
    mergeSort(array, leftIndex, midIndex);
    mergeSort(array, midIndex + 1, rightIndex);

    merge(array, leftIndex, midIndex, rightIndex);
}

int main()
{

    int myArray[] = {1, 3, 7, 8, 2, 4, 5, 6};
    int size = sizeof(myArray) / sizeof(myArray[0]);
    int leftIndex = 0;
    int rightIndex = size - 1;
    cout << "\nOriginal array:\n";
    for (auto value : myArray)
    {
        cout << value << " ";
    }
    cout << endl
         << endl;
    mergeSort(myArray, leftIndex, rightIndex);
    cout<<"Merge Sort\n";
    for (auto value : myArray)
    {
        cout << value << " ";
    }
    cout << endl
         << endl;
    //----------------merge below----------------------

    int midIndex = (size / 2) - 1;

    merge(myArray, leftIndex, midIndex, rightIndex);
    cout<<"Merge helping function\n";
    for (auto value : myArray)
    {
        cout << value << " ";
    }
    cout<<endl<<endl;
    return 0;
}*/
//--------------------------------------------------
//  ---------------------->>>   QUICK SORTS

void swap(int array[], int firstIndex, int secondIndex) {
    int temp = array[firstIndex];
    array[firstIndex] = array[secondIndex];
    array[secondIndex] = temp;
}

//----------------pivot helping function----------
int pivot(int array[], int pivotIndex, int endIndex) {
    int swapIndex = pivotIndex;
    for (int i = pivotIndex + 1; i <= endIndex; i++) {
        if (array[i] < array[pivotIndex]) {
            swapIndex++;
            swap(array, swapIndex, i);
        }
    }
    swap(array, pivotIndex, swapIndex);

    return swapIndex;
}

//----------- quickSort------------
void quickSort(int array[], int leftIndex, int rightIndex) {
    if (leftIndex >= rightIndex) return; 

    int pivotIndex = pivot(array, leftIndex, rightIndex);
    quickSort(array, leftIndex, pivotIndex-1);
    quickSort(array, pivotIndex+1, rightIndex);
}



int main() {
    
    int myArray[] = {4,6,1,7,3,2,5};

    int size = sizeof(myArray) / sizeof(myArray[0]);

    int returnedIndex = pivot(myArray, 0, size-1);

    cout << "Returned Index: " << returnedIndex << "\n\nAfter pivot function\n" ;

    for (auto value : myArray) {
        cout << value << " ";
    }

    /*
        EXPECTED OUTPUT:
        ----------------
        Returned Index: 3

        2 1 3 4 6 7 5  
        
     */

    quickSort(myArray, 0, size-1);

    cout<<"\n\n----------------\nQuick sort\n";
    for (auto value : myArray) {  
        cout << value << " ";
    }
    
    /*
        EXPECTED OUTPUT:
        ----------------
        1 2 3 4 5 6 7 
        
     */

}
// Big o cheet sheet: https://www.bigocheatsheet.com/
