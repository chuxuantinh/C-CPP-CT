/* Code by KingNNT */
#include <bits/stdc++.h>

#define pathio "/mnt/Learning And Working/Code/C-Extend/GNU-Compiler/In-Out/"
#define lfi pathio "input.txt", "r", stdin
#define lfo pathio "output.txt", "w", stdout

using namespace std;

void heapify(int *arr, int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] > arr[largest])
        largest = l;

    if (r < n && arr[r] > arr[largest])
        largest = r;

    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int *arr, int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i > 0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

void enterArray(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
}
void printArray(int *arr, int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    freopen(lfi);
    freopen(lfo);
    ios_base ::sync_with_stdio(0);
    cin.tie(0);

    cout << "Nhap so phan tu cua mang n = ";
    int n;
    cin >> n;
    int *arr = new int[n];
    enterArray(arr, n);
    cout << endl
         << "Before Sort" << endl;
    printArray(arr, n);

    heapSort(arr, n);
    
    cout << endl
         << "After Sort" << endl;
    printArray(arr, n);

    fclose(stdin);
    fclose(stdout);
    return 0;
}