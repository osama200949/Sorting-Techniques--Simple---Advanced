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

    cout << "number of passes = " << numOfPasses << endl
         << "number of comparisons = " << numOfComparison << endl
         << "number of swaps = " << numOfSwap << endl;
    cout << "The sorted array { ";
    for (int i = 0; i < size; i++)
        cout << arr[i] << ", ";
    cout << "}" << endl;
    cout << endl;
}

void enhancedBubbleSort(int arr[], int size)
{
    bool swapped;
    int i, j;
    for (i = 0; i < size - 1; i++)
    {
        swapped = false;
        for (j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swapped = true;
                numOfSwap++;
            }
            numOfComparison++;
        }
        numOfPasses++;
        // if there is no two elements swapped then return the array as sorted and stop the loop
        if (!swapped)
            break;
    }
}

int main()
{
    cout << "<< Improved Bubble Sort >>" << endl; // Title
    int dA[25] = {100, 50, 88, 30, 60, 45, 25, 12, 10, 5, 98, 15, 65, 55, 45, 70, 20, 90, 66, 22, 120, 48, 35, 85, 2};
    int sizeA = sizeof(dA) / sizeof(dA[0]);
    int dB[25] = {5, 8, 30, 25, 35, 40, 42, 50, 55, 22, 24, 60, 66, 70, 75, 78, 80, 88, 95, 100, 118, 98, 120, 122, 121};
    int sizeB = sizeof(dB) / sizeof(dB[0]);

  
    enhancedBubbleSort(dA, sizeA);
    print(dA, sizeA);
    numOfPasses = numOfComparison = numOfSwap = 0;
    enhancedBubbleSort(dB, sizeB);
    print(dB, sizeB);

    cout << "\n\n";
    system("pause");
    return 0;
}