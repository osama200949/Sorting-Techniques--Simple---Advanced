#include <iostream>
using namespace std;
int numOfPasses = 0, numOfComparison = 0, numOfSwap = 0;

void swap(int &i, int &j)
{
    int temp = i;
    i = j;
    j = temp;
}

void print(int arr[], int size)
{
    cout << "\nnumber of passes = " << numOfPasses << endl
         << "number of comparisons = " << numOfComparison << endl
         << "number of swaps = " << numOfSwap << endl;
    cout << "The sorted array { ";
    for (int i = 0; i < size; i++)
        cout << arr[i] << ", ";
    cout << "}" << endl;
    cout << endl;
}

/* This function takes last element as pivot, places 
the pivot element at its correct position in sorted 
array, and places all smaller (smaller than pivot) 
to left of pivot and all greater elements to right 
of pivot */
int partition(int arr[], int low, int high)
{
    int pivot = arr[high]; // pivot
    int i = (low - 1);     // Index of smaller element

    for (int j = low; j <= high - 1; j++)
    {
        numOfPasses++;
        numOfComparison++;
        // If current element is smaller than the pivot
        if (arr[j] < pivot)
        {
            i++; // increment index of smaller element
            swap(arr[i], arr[j]);
            numOfSwap++;
        }
    }
    swap(arr[i + 1], arr[high]);
    numOfSwap++;
    return (i + 1);
}

/* The main function that implements QuickSort 
arr[] --> Array to be sorted, 
low --> Starting index, 
high --> Ending index */
void quickSort(int arr[], int low, int high)
{
    if (low >= high)
        return;

    /* pi is partitioning index, arr[p] is now 
		at right place */
    int pi = partition(arr, low, high);

    // Separately sort elements before
    // partition and after partition
    quickSort(arr, low, pi - 1);
    quickSort(arr, pi + 1, high);
}

int main()
{
    cout << "<< Quick Sort >>" << endl; // Title
    int dA[25] = {100, 50, 88, 30, 60, 45, 25, 12, 10, 5, 98, 15, 65, 55, 45, 70, 20, 90, 66, 22, 120, 48, 35, 85, 2};
    int sizeA = sizeof(dA) / sizeof(dA[0]);
    int dB[25] = {5, 8, 30, 25, 35, 40, 42, 50, 55, 22, 24, 60, 66, 70, 75, 78, 80, 88, 95, 100, 118, 98, 120, 122, 121};
    int sizeB = sizeof(dB) / sizeof(dB[0]);

    quickSort(dA, 0, sizeA - 1);
    print(dA, sizeA);
    numOfPasses = numOfComparison = numOfSwap = 0;
    quickSort(dB, 0, sizeB - 1);
    print(dB, sizeB);

    cout << "\n\n";
    system("pause");
    return 0;
}
