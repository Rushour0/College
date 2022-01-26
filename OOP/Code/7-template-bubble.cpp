#include <typeinfo>
#include <iostream>
using namespace std;

#define line cout << endl;
#define getarr(arr)     \
    for (auto &i : arr) \
        cin >> i;
#define putarr(arr)     \
    for (auto &i : arr) \
        cout << i << " ";
#define swap(x, y)          \
    do                      \
    {                       \
        typeof(x) SWAP = x; \
        x = y;              \
        y = SWAP;           \
    } while (0);

template <typename T>
T bubbleSort()
{
    int n;
    cout << "Input Size of array : ";
    cin >> n;
    T arr[n];
    cout << "Input elements of the array : ";
    getarr(arr);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
    putarr(arr);
    cout << endl;
}

int main()
{
    bubbleSort<int>();
    bubbleSort<float>();
    bubbleSort<string>();
    return 0;
}

/*
10
3 4 2 5 1 6 8 0 7 9
5
2.3 1.5 5.7 9.3 0.1
5
water earth fire air airr
*/