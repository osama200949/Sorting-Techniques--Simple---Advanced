#include <iostream>
using namespace std;

void swap(int &i, int &j)
{
    int temp = i;
    i = j;
    j = temp;
}

void bubbleSort(int arr[], int size)
{

    int i;
    bool sorted = false;

    while (!sorted)
    {

        sorted = true;
        for (i = 0; i < size - 1; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                sorted = false;
                swap(arr[i], arr[i + 1]);
            }
        }
    }
}

void print() {}

int main()
{
    int dA[25] = {100, 50, 88, 30, 60, 45, 25, 12, 10, 5, 98, 15, 65, 55, 45, 70, 20, 90, 66, 22, 120, 48, 35, 85, 2};
    // int dA[4] = {100, 50, 88, 30};
    int dB[25] = {5, 8, 30, 25, 35, 40, 42, 50, 55, 22, 24, 60, 66, 70, 75, 78, 80, 88, 95, 100, 118, 98, 120, 122, 121};

    bubbleSort(dA, sizeof(dA) / sizeof(dA[0]));

    for (int i = 0; i < sizeof(dA) / sizeof(dA[0]); i++)
        cout << dA[i] << " ";
    print();

    cout << endl
         << endl;

    system("pause");
    return 0;
}