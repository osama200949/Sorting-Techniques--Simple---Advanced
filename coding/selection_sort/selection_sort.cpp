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

void selectionSort(int arr[], int size)
{
    int i, j;
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
}

int main()
{
    cout << "<< Selection Sort >>" << endl; // Title
    int dA[25] = {100, 50, 88, 30, 60, 45, 25, 12, 10, 5, 98, 15, 65, 55, 45, 70, 20, 90, 66, 22, 120, 48, 35, 85, 2};
    int sizeA = sizeof(dA) / sizeof(dA[0]);
    int dB[25] = {5, 8, 30, 25, 35, 40, 42, 50, 55, 22, 24, 60, 66, 70, 75, 78, 80, 88, 95, 100, 118, 98, 120, 122, 121};
    int sizeB = sizeof(dB) / sizeof(dB[0]);

    selectionSort(dA, sizeA);
    print(dA, sizeA);
    numOfPasses = numOfComparison = numOfSwap = 0;
    selectionSort(dB, sizeB);
    print(dB, sizeB);

    cout << "\n\n";
    system("pause");
    return 0;
}