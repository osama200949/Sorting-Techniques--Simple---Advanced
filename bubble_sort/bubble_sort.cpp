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
         << arrayName;
    cout << "number of passes = " << numOfPasses << endl
         << "number of comparisons = " << numOfComparison << endl
         << "number of swaps = " << numOfSwap << endl;
    cout << "The sorted array { ";
    for (int i = 0; i < size; i++)
        cout << arr[i] << ", ";
    cout << "}" << endl;
    cout << endl;
}

void bubbleSort(int arr[], int size)
{
    int i, j;
    int numOfPasses, numOfComparison, numOfSwap;
    numOfPasses = numOfComparison = numOfSwap = 0;
    for (i = 0; i < size - 1; i++)
    {
        for (j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                numOfSwap++;
            }
            numOfComparison++;
        }
        numOfPasses++;
    }
    print("Data Array A", arr, size, numOfPasses, numOfComparison, numOfSwap);
}

int main()
{
    cout << "<< Bubble Sort >>" << endl;
    int dA[25] = {100, 50, 88, 30, 60, 45, 25, 12, 10, 5, 98, 15, 65, 55, 45, 70, 20, 90, 66, 22, 120, 48, 35, 85, 2};
    int sizeA = sizeof(dA) / sizeof(dA[0]);
    int dB[25] = {5, 8, 30, 25, 35, 40, 42, 50, 55, 22, 24, 60, 66, 70, 75, 78, 80, 88, 95, 100, 118, 98, 120, 122, 121};
    int sizeB = sizeof(dB) / sizeof(dB[0]);

    bubbleSort(dA, sizeA);
    bubbleSort(dB, sizeB);

    cout << endl
         << endl;
    system("pause");
    return 0;
}