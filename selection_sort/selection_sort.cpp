#include <iostream>
using namespace std;

void swap(int &i, int &j)
{
    int temp = i;
    i = j;
    j = temp;
}

void print(string arrayName, int arr[], int size, int numOfPasses, int numOfComparison, int numOfSwap)
{
    cout << endl
         << arrayName << endl;
    cout << "number of passes = " << numOfPasses << endl
         << "number of comparisons = " << numOfComparison << endl
         << "number of swaps = " << numOfSwap << endl;
    cout << "The sorted array { ";
    for (int i = 0; i < size; i++)
        cout << arr[i] << ", ";
    cout << "}" << endl;
    cout << endl;
}

void selectionSort(int arr[], int size)
{
    int i, j;
    int numOfPasses, numOfComparison, numOfSwap;
    numOfPasses = numOfComparison = numOfSwap = 0;
    for (i = 0; i < size - 1; i++)
    {
        numOfPasses++;
        int *smallestNum = &arr[i];
        for (j = i + 1; j < size; j++)
        {
            numOfComparison++;
            if (arr[j] < *smallestNum)
            {
                smallestNum = &arr[j];
            }
        }
        numOfSwap++;
        swap(arr[i], *smallestNum);
    }
    print("Data Array A ", arr, size, numOfPasses, numOfComparison, numOfSwap);
}

int main()
{
    cout << "<< Selection Sort >>" << endl; // Title
    int dA[25] = {100, 50, 88, 30, 60, 45, 25, 12, 10, 5, 98, 15, 65, 55, 45, 70, 20, 90, 66, 22, 120, 48, 35, 85, 2};
    int sizeA = sizeof(dA) / sizeof(dA[0]);
    int dB[25] = {5, 8, 30, 25, 35, 40, 42, 50, 55, 22, 24, 60, 66, 70, 75, 78, 80, 88, 95, 100, 118, 98, 120, 122, 121};
    int sizeB = sizeof(dB) / sizeof(dB[0]);

    selectionSort(dA, sizeA);
    selectionSort(dB, sizeB);

    cout << "\n\n";
    system("pause");
    return 0;
}