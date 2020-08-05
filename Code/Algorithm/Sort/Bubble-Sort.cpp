/* Code by KingNNT */
#include <bits/stdc++.h>

#define pathio "/mnt/Learning And Working/Code/C-CPP/GNU-Compiler/In-Out/"
#define lfi pathio "input.txt", "r", stdin
#define lfo pathio "output.txt", "w", stdout

using namespace std;

void bubbleSort(float *arr, int n)
{
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
}

void enterArray(float *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
}
void printArray(float *arr, int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    freopen(lfi);
    freopen(lfo);
    // ios_base ::sync_with_stdio(0);
    cin.tie(0);

    cout << "Nhap so phan tu cua mang n = ";
    int n;
    cin >> n;
    float *arr = new float[n];
    enterArray(arr, n);
    cout << endl
         << "Before Sort" << endl;
    printArray(arr, n);

    bubbleSort(arr, n);

    cout << endl
         << "After Sort" << endl;
    printArray(arr, n);

    fclose(stdin);
    fclose(stdout);
    return 0;
}